#include <stdio.h>
#include <math.h>

int main() {
    double a, x, G, F, Y;

    printf("Введите а: ");
    scanf("%lf", &a);
    printf("Введите x: ");
    scanf("%lf", &x);
    G = (-2 * (-5*pow(a, 2)+ 3*a*x + 2*pow(x, 2))) / (5*pow(a, 2) + 9*a*x - 2*pow(x, 2));
    printf("Результат: ");
    printf("%lf", G);

    printf("\n\nВведите а: ");
    scanf("%lf", &a);
    printf("Введите x: ");
    scanf("%lf", &x);
    F = sin(M_PI * (10.0 * pow(a, 2.0) + 37.0*a*x + 7.0*pow(x, 2.0))) / (M_PI * (10.0*pow(a, 2.0) + 37.0*a*x + 7.0*pow(x, 2.0)));
    printf("Результат: ");
    printf("%3.25lf", F);

    printf("\n\nВведите а: ");
    scanf("%lf", &a);
    printf("Введите x: ");
    scanf("%lf", &x);
    Y = (log(-5*pow(a,2) - 16*a*x + 16*pow(x,2)+1)) / log(2);
    printf("Результат: ");
    printf("%lf", Y);

    return 0;
}
