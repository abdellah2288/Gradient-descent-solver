#include <stdio.h>
#include <math.h>
#include "gradient_descent.h"

float sphere_intersection(point_t point);
float sphere_intersection_1(point_t point);
float sphere_intersection_2(point_t point);
float sphere_intersection_3(point_t point);

int main()
{
    point_t optimum = gradient_descent_solver(sphere_intersection,LEARNING_RATE,ACCURACY_THRESHOLD,SAMPLE_COUNT);
    point_t optimum_1 = gradient_descent_solver(sphere_intersection_1,LEARNING_RATE,ACCURACY_THRESHOLD,SAMPLE_COUNT);
    point_t optimum_2 = gradient_descent_solver(sphere_intersection_2,LEARNING_RATE,ACCURACY_THRESHOLD,SAMPLE_COUNT);
    point_t optimum_3 = gradient_descent_solver(sphere_intersection_3,LEARNING_RATE,ACCURACY_THRESHOLD,SAMPLE_COUNT);
        printf("[EQ 0]> [%f,%f,%f] \n",optimum.x,optimum.y,optimum.z);
        printf("[EQ 1]> [%f,%f,%f] \n",optimum_1.x,optimum_1.y,optimum_1.z);
        printf("[EQ 2]> [%f,%f,%f] \n",optimum_2.x,optimum_2.y,optimum_2.z);
        printf("[EQ 3]> [%f,%f,%f] \n",optimum_3.x,optimum_3.y,optimum_3.z);
}
float sphere_intersection_1(point_t point)
{
    return pow(point.x, 2) + pow(point.y - 4, 2) + pow(point.z - 3, 2) - 2 +
           pow(point.x - 1, 2) + pow(point.y - 1, 2) + pow(point.z - 2, 2) - 5 +
           pow(point.x - 7, 2) + pow(point.y - 7, 2) + pow(point.z - 4, 2) - 3;
}

// Test sphere intersection 2
float sphere_intersection_2(point_t point)
{
    return pow(point.x, 2) + pow(point.y - 6, 2) + pow(point.z - 5, 2) - 3 +
           pow(point.x - 2, 2) + pow(point.y - 2, 2) + pow(point.z - 6, 2) - 6 +
           pow(point.x - 8, 2) + pow(point.y - 8, 2) + pow(point.z - 7, 2) - 4;
}

// Test sphere intersection 3
float sphere_intersection_3(point_t point)
{
    return pow(point.x, 2) + pow(point.y - 8, 2) + pow(point.z - 7, 2) - 4 +
           pow(point.x - 4, 2) + pow(point.y - 4, 2) + pow(point.z - 8, 2) - 7 +
           pow(point.x - 9, 2) + pow(point.y - 9, 2) + pow(point.z - 9, 2) - 2;
}
float sphere_intersection(point_t point)
{
        return pow(point.x,2) + pow(point.y - 10,2) - 1 + pow(point.x - 3,2) + pow(point.y - 3,2) - 4 + pow(point.x - 5,2) + pow(point.y - 5,2) - 9 ;
}
