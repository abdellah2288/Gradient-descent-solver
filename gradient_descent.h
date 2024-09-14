#ifndef __GRADIENT_DESCENT
#define __GRADIENT_DESCENT
#define GRADIENT_STEP 0.01
#define LEARNING_RATE 0.01
#define ADJUSTMENT_COEFF 0.5
#define ACCURACY_THRESHOLD 0.01
#define SAMPLE_COUNT 120
#include "point.h"
/**
 *@brief calculate the gradient of a function at a point using centered finite difference method
 *@param gradient_step the derivative spacing.
 *@return a 3D vector representing the gradient.
 */
point_t calculate_gradient(float (*function)(point_t),point_t point, float gradient_step);
/**
 *@brief uses the gradient descent algorithm to find the minima of a positive function.
 *@param learning_rate the initial learning rate, don't use a very big value or the algorithm diverges.
 *@param threshold will stop the algorithm when the found minima is below the threshold.
 *@param max_iter the algorithm will stop after max_iter iterations.
 *@return a point (3D vector) representing the optimum. 
 */
point_t gradient_descent_solver(float (*function)(point_t), float learning_rate, float threshold, int max_iter);

#endif
