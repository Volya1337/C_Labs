#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ARRAY_SIZE 200

struct Point    /* Тут хранятся все точки*/
{
    double x[ARRAY_SIZE];
    double y[ARRAY_SIZE];
};

struct Facilities_verification /*Относительно этих точек проверяется принадлежность*/
{
    double x2;
    double y2;
};

typedef struct Facilities_verification point;

typedef struct Point Points;

Points Array_getRandom_Points(void) /*Функция генерации случайных чисел в заданном диапазоне*/
{
    Points Array;
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < 200; i++) {
        Array.x[i] = (double) rand() / RAND_MAX * (10.0 + 10.0);
        Array.y[i] = (double) rand() / RAND_MAX * (10.0 + 10.0);
    }
    return Array;
}

int accessory_to_region(point Array, point mass,double radius){ /*Функция проверки принадлежности области*/
    double d;
    d = sqrt((pow(2,mass.x2-Array.x2))+pow(2,mass.y2-Array.y2));
    if (d <= radius)
        return 1;
}
int amount_of_points_points_in_vicinity(double rad) /*функция получения колличества точек в окресности*/
{
    point xx, included_in_vicinity;
    Points massif;
    int i = 0, change = 0, receipt = 0;;
    srand(time(NULL));

    change = rand() % 100;

    massif = Array_getRandom_Points();
    massif.x[change] = xx.x2;
    massif.y[change] = xx.y2;

    for (i = 0; i < 200; i++)
    {
        included_in_vicinity.x2 = massif.x[i];
        included_in_vicinity.y2 = massif.y[i];
        if (accessory_to_region(xx,included_in_vicinity,rad) == 1)
        {
            receipt++;
        }
    }
    if (receipt != 0) {

    }
    return receipt;
}

int main()
{
     FILE* output;
    double radius,start,stop;
    srand(time(NULL));

    start = omp_get_wtime();
    radius = (double) rand() / RAND_MAX * (30.0);
    printf("Радиус окрестности: %lf\n", radius);
    printf("Количество точек в окрестности: %d\n", amount_of_points_points_in_vicinity(radius));
    stop = omp_get_wtime();
    printf("Время работы программы: %lf\n\n", stop - start);
    output = fopen("/home/valery/lab-08/time.txt","a");
    fprintf(output,"%lf\n",stop - start);
    fclose(output);
    return 0;
}