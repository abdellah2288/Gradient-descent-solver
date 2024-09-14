#include "point.h"
#include <math.h>

point_t psubt(point_t point_1,point_t point_2)
{
        point_t result = {point_1.x - point_2.x, point_1.y - point_2.y, point_1.z - point_2.z};
        return result;
}
point_t spmult(point_t point, float scalar)
{
        point_t result = {point.x * scalar, point.y * scalar, point.z * scalar};
        return result;
}
float pmod(point_t point)
{
        return sqrt(pow(point.x,2)+pow(point.y,2)+pow(point.z,2));
}
