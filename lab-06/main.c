#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    struct mas_struct {
        double G;
        double F;
        double Y;
    } functions;

    struct mas_struct item[100];

    double a, x, d, xmin, xmax, s = 0, steps;
    int i = 0;
    char value[100];

    printf("Введите минимальное значение х: ");/* Ввод минимального значения x */
    scanf("%s", &value);
    xmin = atof(value);

    printf("Введите максимальное значение x: "); /*Ввод максимального значения x */
    scanf("%s", &value);
    xmax = atof(value);
    
    printf("Введите а: ");
    scanf("%s", &value);
    a = atof(value);

    printf("Введите количество шагов:\n");
    scanf("%s", &value);
    steps = atoi(value);
    s = (xmax - xmin) / (steps - 1);

    i = 0;

    x = xmin;

    while ((x <= xmax) && (i <= steps)) {
        d = 5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2);
        if (fabs(d) < (10e-6)) {
            printf("Введенные значения не входят в область определния ф-ции \n");
        } else {
            item[i].G = (-2 * (-5 * pow(a, 2) + 3 * a * x + 2 * pow(x, 2))) / d;
            printf("G=%lf\n", item[i].G);
        }
        i++;
        if (i > 100) {
            printf("Массив переполнен.");
            break;
        }
        x += s;
    }
    printf("--------------------------------------------------------------------------\n");

    i = 0;

    x = xmin;

    while ((x <= xmax) && (i <= steps)) {
        d = (M_PI * (10.0 * pow(a, 2.0) + 37.0 * a * x + 7.0 * pow(x, 2.0)));
        if (fabs(d) < (10e-6)) {
            printf("Введенные значения не входят в область определния ф-ции\n");
        } else {
            item[i].F = sin(M_PI * (10.0 * pow(a, 2.0) + 37.0 * a * x + 7.0 * pow(x, 2.0))) / d;
            printf("F= %0.18lf\n", item[i].F);
        }
        i++;
        if (i > 100) {
            printf("Массив переполнен.");
            break;
        }
        x += s;
    }
    printf("--------------------------------------------------------------------------\n");

    i = 0;

    x = xmin;

    while ((x <= xmax) && (i <= s)) {
        d = log(2);
        if (fabs(d) < (10e-6)) {
            printf("Введенные значения не входят в область определния ф-ции\n");
        } else {
            item[i].Y = (log(-5 * pow(a, 2) - 16 * a * x + 16 * pow(x, 2) + 1)) / d;
            printf("Y= %lf\n", item[i].Y);
        }
        i++;
        if (i > 100) {
            printf("Массив переполнен.");
            break;
        }
        x += s;
    }
    return 0;
}
