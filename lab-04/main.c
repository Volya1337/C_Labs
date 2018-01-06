#include <stdio.h>
#include <math.h>

int main() {
    double mas[100];
    double a, x, d, h, xmin, xmax, maxv, minv;
    int c, s, i;
    
    do{
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

            printf("Введите минимальное значение х: ");/* Ввод минимального значения x */
        scanf("%lf", &xmin);
        printf("Введите максимальное значение x: "); /*Ввод максимального значения x */
        scanf("%lf", &xmax);
       
    if (s > 100){
        printf("Ошибка с массивом");
        return 0;
    }
            h = (xmax - xmin) / (s - 1);

        /*
         * Выполнение вычислений исходя из выбранной формулы
         */
        switch (c) {
            case 1: {
                printf("Введите а: ");
                scanf("%lf", &a);
                for (x = xmin, i = 0; x <= xmax & i <= s; x+=h, i++) {/*Цикл вычисления функции с учетом введенных данных*/
                    d = 5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2);
                    if (d == (10e-6)) {
                        printf("Введенные значения не входят в область определния ф-ции \n");
                        break;
                    }
                    mas[i] = (-2 * (-5 * pow(a, 2) + 3 * a * x + 2 * pow(x, 2))) /
                        (5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2));
                    printf("x = %lf\t", x );
                    printf("G=%lf\n", mas[i]);

                }
                break;
                case 2: {
                    printf("Введите а: ");
                    scanf("%lf", &a);
                    for (x = xmin, i = 0; x < xmax; x+=h, i++) {
                        d = 5 * pow(a, 2) + 9 * a * x - 2 * pow(x, 2);
                        if (d == (10e-6)) {
                            printf("Введенные значения не входят в область определния ф-ции\n");
                            break;
                        }
                        mas[i] = sin(M_PI * (10.0 * pow(a, 2.0) + 37.0 * a * x + 7.0 * pow(x, 2.0))) /
                            (M_PI * (10.0 * pow(a, 2.0) + 37.0 * a * x + 7.0 * pow(x, 2.0)));
                        printf("x = %0.18lf\t", x );
                        printf("F= %0.18lf\n", mas[i]);
                    }
                    break;
                    case 3: {
                        printf("Введите а: ");
                        scanf("%lf", &a);
                        while (a > 0) { /* Цикл проверки ввода а если оно положительно, то цикл повторяется */
                            printf("a должно быть отрицательным числом, введите его еще раз: ");
                            scanf("%lf", &a);
                        }
                        for (x = xmin, i = 0; x < xmax; x+=h, i++) {
                            if (x < 0 || a < 0) {
                            }
                            mas[i] = (log(-5 * pow(a, 2) - 16 * a * x + 16 * pow(x, 2) + 1)) / log(2);
                            printf("x = %lf\t", x );
                            printf("%lf\n", mas[i]);
                        }
                        break;

                    }
                }
            }
        }
for (i = 0, minv = mas[0], maxv = mas[0]; i <= s; i++){
    if(mas[i] > maxv)
        maxv = mas[i];
    if (mas[i] < minv)
        minv = mas[i];
}
    printf("Макс. значение: %0.18lf\n", maxv);
    printf("Мин. значение: %0.18lf\n", minv);
    } while (c != 0);
    return 0;
}

