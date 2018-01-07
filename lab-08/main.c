#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 5000

struct points
{
    double x[N];
    double y[N];
};

struct main_point
{
    double main_x;
    double main_y;
};

struct points generator_array(void)
{
    struct points array;
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < N; i++) {
        array.x[i] = (double) rand() / RAND_MAX * (5.0 + 5.0) - 5.0;
        array.y[i] = (double) rand() / RAND_MAX * (5.0 + 5.0) - 5.0;
    }
    return array;
}

int belongOrNot(struct main_point one_p, struct main_point all_p,double rad)
{
    double distance;
    distance = sqrt((pow(2,one_p.main_x-all_p.main_x))+pow(2,one_p.main_y-all_p.main_y));
    if (distance <= rad)
        return 1;
    else
        return 0;
}
int amountOfPoints(double rad)
{
    struct main_point thePoint, allPoints;
    struct points mass;
    int counter = 0;
    int i = 0, choice = 0;
    srand(time(NULL));

    choice = rand() % N;

    mass = generator_array();
    thePoint.main_x = mass.x[choice];
    thePoint.main_y = mass.y[choice];

    for (i = 0; i < N; i++)
    {
        allPoints.main_x = mass.x[i];
        allPoints.main_y = mass.y[i];
        if (belongOrNot(thePoint,allPoints,rad) == 1)
        {
            counter++;
        }
    }
    if (counter != 0)
    {
        counter = counter - 1;
    }
    return counter;
}

int main()
{
    FILE* output;
    double radius,start,end;

    printf("Введите радиус окрестности: ");
    scanf("%lf", &radius);
    start = omp_get_wtime();
    printf("Количество точек в заданной окрестности: %d\n", amountOfPoints(radius));
    end = omp_get_wtime();
    printf("Время выполнения программы: %lf\n", end - start);
    output = fopen("/home/valery/lab-08_c/time.txt","a");
    fprintf(output,"%lf\n",end - start);
    fclose(output);
    return 0;
}