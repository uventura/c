#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>

static struct termios old, current;

enum Boolean {false, true};
typedef enum Boolean bool;

typedef struct
{
	int i, j;
} element;

typedef struct
{
	int size;
	int *elements;
	element empty;
} puzzle;

bool FindElement(int el, int *list, int count)
{
	bool result = false;

	int i;
	for(i = 0; i < count; i++)
	{
		if(list[i] == el)
		{
			result = true;
			return result;
		}
	}

	return result;
}

int *GenElements(int n)
{
	// Generate a random list from integer, that contains n elements.

	int *elements;
	elements = malloc(n * sizeof(int));

	int i = 0, element;

	while(i < (n - 1))
	{
		element = rand()%n;
		
		if(element != 0)
		{
			if(element == 0)
			{
				elements[i] = element;
				++i;
			}
			else if(!FindElement(element, elements, i + 1))
			{
				elements[i] = element;
				++i;
			}
		}
	}

	elements[n - 1] = -1;

	return elements;
}

void ShowElements(int *list, int size)
{
	int cols = sqrt(size);
	int counter = 0;
	int i, j, k;

	printf("  ");
	for(i = 0; i < cols; ++i)
		printf("----");

	printf("--\n  ");

	for(i = 0; i < size; ++i)
	{
		if(counter == 0)
			printf("|");
		counter++;

		if(list[i] != -1)
			printf(" %02d ", list[i]);
		else
			printf("    ");	

		if(counter == cols && i + 1 != size)
		{
			printf("|\n  |");
			for(k = 0; k <  counter; ++k)
				printf("    ");
			printf("|\n  ");

			counter = 0;
		}
	}

	printf("|\n  --");
	for(i = 0; i < cols; ++i)
		printf("----");

	printf("\n");
}

void Update()
{
	system("clear");
}

void Exchange(int *list, int size, element a, element b)
{
	int aux = list[(int)(a.i * sqrt(size) + a.j)];

	list[(int)(a.i * sqrt(size) + a.j)] = list[(int)(b.i * sqrt(size) + b.j)];
	list[(int)(b.i * sqrt(size) + b.j)] = aux;
}

void Move(char key, puzzle *p)
{	
	element b = p->empty;

	if(key == 's' && b.i - 1 >= 0)
	{
		--b.i;
		Exchange(p->elements, p->size , p->empty, b);
	}
	else if(key == 'w' && b.i + 1 < (int)sqrt(p->size))
	{
		++b.i;
		Exchange(p->elements, p->size , p->empty, b);
	}
	else if(key == 'd' && b.j - 1 >= 0)
	{
		--b.j;
		Exchange(p->elements, p->size , p->empty, b);
	}
	else if(key == 'a' && b.j + 1 < (int)sqrt(p->size))
	{
		++b.j;
		Exchange(p->elements, p->size , p->empty, b);
	}

	p->empty = b;
}

bool Won(int *list, int size)
{
	bool result = false;

	int emptyPosition = size - 1;
	
	if(list[emptyPosition] == -1)
	{
		--size;

		int i, j;
		for(i = 0; i < size; ++i)
		{
			for(j = i + 1; j < size; ++j)
			{
				if(list[i] > list[j])
				{
					result = false;
					return result;
				}
			}
		}

		result = true;
	}

	return result;
}

// Input

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

int main()
{
	puzzle square;
	
	square.size = 9;
	square.empty.i = 2;
	square.empty.j = 2;
	square.elements = GenElements(9);

	char key;
	do
	{
		Update();
		ShowElements(square.elements, square.size);

		key = getch();
		Move(key, &square);
	}while(!Won(square.elements, square.size));

	int i;
	for(i = 0; i < 4; ++i)
	{
		printf(" %d ", square.elements[i]);
	}
	printf("\n");

	ShowElements(square.elements, square.size);

	printf("Voce ganhou!\n");

	return 0;
}