#include <stdio.h>
#include <math.h>

int main() {
    double a, x, d, G, F, Y, xmin, xmax;
    int c, s;
    
    do {

/*
 * Выбор формулы для дальнейшего расчета
 */
        printf("Для выхода из программы, введите 0\n");
        printf("Формула 1: Рассчет G, введите 1\n");
        printf("Формула 2: Рассчет F, введите 2\n");
        printf("Формула 3: Рассчет Y, введите 3\n");
        scanf("%d", &c);

    if (c == 0) {
        printf("До свидания!");
        return 0;
    }
        /*
         *  Проверка правильности выбора формулы
         */

        if ((c < 0) || (c > 3)) {
            printf("Неверно введено значение, введите его заного!\n");
            scanf("%d", &c);
        } else

            printf("Введите минимальное значение х: ");// Ввод минимального значения x
        scanf("%lf", &xmin);
        printf("Введите максимальное значение x: ");// Ввод максимального значения x
        scanf("%lf", &xmax);
       
        /*
         * Выполнение вычислений исходя из выбранной формулы
         */
        switch (c) {
            case 1: {
                printf("Введите а: ");
                scanf("%lf", &a);
                for (x = xmin; x <= xmax; x += (xmax - xmin) /
                                               (s - 1)) {//Цикл вычисления функции с учетом введенных данных
                    d = 5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2);
                    if (d == 0) {
                        printf("Введенные значения не входят в область определния ф-ции");
                        continue;
                    }
                    G = (-2 * (-5 * pow(a, 2) + 3 * a * x + 2 * pow(x, 2))) /
                        (5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2));
                    printf("G=%lf\n", G);

                }
                break;
            case 2: {
                printf("Введите а: ");
                scanf("%lf", &a);
                for (x = xmin; x <= xmax; x += (xmax - xmin) / (s - 1)) {
                    d = 5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2);
                    if (d == 0) {
                        printf("Введенные значения не входят в область определния ф-ции");
                        continue;
                    }
                    F = sin(M_PI * (10.0 * pow(a, 2.0) + 37.0 * a * x + 7.0 * pow(x, 2.0))) /
                        (M_PI * (10.0 * pow(a, 2.0) + 37.0 * a * x + 7.0 * pow(x, 2.0)));
                    printf("F=%lf\n", F);
                }
                    break;
                case 3: {
                    printf("Введите а: ");
                    scanf("%lf", &a);
                    while (a > 0) { // Цикл проверки ввода а если оно положительно, то цикл повторяется
                        printf("a должно быть отрицательным числом, введите его еще раз: ");
                        scanf("%lf", &a);
                    }
                    for (x = xmin; x <= xmax; x += (xmax - xmin) / (s - 1)) {
                        if (x < 0 || a < 0) {
                        }
                        Y = (log(-5 * pow(a, 2) - 16 * a * x + 16 * pow(x, 2) + 1)) / log(2);
                        printf("%lf\n", Y);
                    }
                        break;
                    }
                }
            }
        }
    } while (c != 0)
    return 0;
    }

