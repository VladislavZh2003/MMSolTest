#include <stdio.h>

int cylinder(double r, double h, double* V, double* S);

int main()
{
    double r;
    double h;
    double V,S;

    while (1)
    {
        scanf("%lf %lf", &r, &h);

        if (cylinder(r,h,&V,&S) == -1)
        {
            printf("Invalid data\n");
            continue;
        }
            
        printf("V = %lf, S = %lf", V, S);
        break;
        
    }
    

    return 0;
}

int cylinder(double r, double h, double* V, double* S)
{
    #define PI 3.14159

    if(r <= 0 || h <= 0)
        return -1;

    double v = PI * r * r * h;
    double s = 2 * PI * r * h;
    
    *V = v;
    *S = s;

    return 0;
}