#include <stdio.h>
#include <math.h>

typedef struct
{
    float raio, arg;
} CoordPolar;

typedef struct
{
    float x, y;
} CoordCart;

CoordCart Transformar(CoordPolar u)
{
    CoordCart v;
    v.x = u.raio * cos(u.arg);
    v.y = u.raio * sin(u.arg);

    return v;
}

int main()
{
    
    return 0;
}