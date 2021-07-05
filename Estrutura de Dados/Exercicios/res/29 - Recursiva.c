#include <stdio.h>

int casas(int n)
{
    int i = 0;
    while(n != 0)
    {
        n /= 10;
        ++i;
    }
    return i;
}

int elevado(int a, int b)
{
    if(b == 1) return a;
    else if(b == 0) return 1;
    return a * elevado(a, b - 1);
}

int inverte(int n)
{
    if(n == 0) return 0;
    return (int)(n - 10 * (int)(n / 10)) * elevado(10, casas(n) - 1) + inverte(n / 10);
}

int main()
{
    printf("%d\n", inverte(12378));
    return 0;
}