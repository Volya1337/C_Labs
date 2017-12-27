#include <stdio.h>
#include <math.h>

int main() {

    double a, x, G, F, Y;
    int c;
    
/**
     * Выбор формулы для дальнейшего расчета
     */
    printf("Для выхода из программы, введите 0\n");
        printf("Формула 1: Рассчет G, введите 1\n");
        printf("Формула 2: Рассчет F, введите 2\n");
        printf("Формула 3: Рассчет Y, введите 3\n");
    printf("Выберите формулу 1,2,3:");
    scanf("%d", &c);
    printf("Введите а: ");
    scanf("%lf", &a);
    printf("Введите x: ");
    scanf("%lf", &x);

    /**
    * Выполнение вычислений исходя из выбранной формулы
    */
    switch (c) {
        case 1:
            if ((a != 0) && (x != 0)) {
                G = (-2 * (-5 * pow(a, 2) + 3 * a * x + 2 * pow(x, 2))) / (5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2));
                printf("%lf\n\n", G);
            }
            else
                printf("Ввведите корректное значение");
            break;
        case 2:
            F = sin(M_PI * (10.0 * pow(a, 2.0) + 37.0*a*x + 7.0*pow(x, 2.0))) / (M_PI * (10.0*pow(a, 2.0) + 37.0*a*x + 7.0*pow(x, 2.0)));
            printf("%3.25lf\n\n", F);
            break;
        case 3:
            if ((a > 0) && (x > 0)) /* Область определения log(x) */
                printf("Введите отрицательное число a или х ");
            printf("а:\n\n ");
            scanf("%lf", &a);
            Y = (log(-5*pow(a,2) - 16*a*x + 16*pow(x,2)+1)) / log(2);
            printf("%lf\n\n", Y);
            break;
        default:
            printf("Ошибка, Вы ввели не ту цифру");
    }
    return 0;
}

