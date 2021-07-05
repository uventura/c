#include <stdio.h>

int Multiplica(int a, int b)
{
    if(b == 1)
        return a;
    return a + Multiplica(a, b - 1);
}

int main()
{
    printf("%d\n", Multiplica(2, 3));
    return 0;
}