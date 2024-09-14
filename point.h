#ifndef __POINT_H
#define __POINT_H
typedef struct
{
	float x;
	float y;
	float z;
} point_t;

/**
 * @brief subrtract point_2 from point_1
 */
point_t psubt(point_t point_1,point_t point_2);
/**
 *@brief multipily point by a scalar
 */
point_t spmult(point_t point, float scalar);
/**
 *@brief gets the module of a point
 */
float pmod(point_t point);
#endif
