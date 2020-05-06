#include <stdio.h>
#define PI 3.1415927

int main()
{
    double R;
    while(scanf("%lf",&R)!=EOF)
    {
        printf("%.3lf\n", 4.0 / 3.0 * PI * R * R * R);
    }
    return 0;
}