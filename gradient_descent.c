#include <math.h>
#include "point.h"
#include "gradient_descent.h"
point_t gradient_descent_solver(float (*function)(point_t), float learning_rate, float threshold, int max_iter)
{
	point_t guess = {0.,0.,0.}; 
	point_t prev_guess = guess;
	float solution = function(guess);
	int iterations = 0.0;
	float __learning_rate = learning_rate;
	
	while(fabs(solution) > threshold && iterations <= max_iter)
	{
		solution = function(guess);

		point_t gradient =  calculate_gradient(function, prev_guess, GRADIENT_STEP) ;
		guess = psubt(prev_guess,spmult(gradient,__learning_rate));
		if(function(guess) > function(prev_guess) - __learning_rate * 0.8 * pow(pmod(gradient),2))
		{
					__learning_rate = __learning_rate * ADJUSTMENT_COEFF > 0.000001 ? __learning_rate * ADJUSTMENT_COEFF : 0.000001;
		}
	        iterations ++;	
		prev_guess = guess;
	}
	return guess;
}
point_t calculate_gradient(float (*function)(point_t),point_t point, float gradient_step)
{
	point_t point_x_p = {point.x + gradient_step,0.,0.};
	point_t point_x_m = {point.x - gradient_step,0.,0.};
	
	point_t point_y_p = {0.,point.y + gradient_step,0.};
	point_t point_y_m = {0.,point.y - gradient_step,0.};
	
	point_t point_z_p = {0.,0.,point.z + gradient_step};
	point_t point_z_m = {0.,0.,point.z - gradient_step};

	float x_partial = (function(point_x_p) - function(point_x_m)) / (2.0 * gradient_step);
	float y_partial = (function(point_y_p) - function(point_y_m)) / (2.0 * gradient_step);
	float z_partial = (function(point_z_p) - function(point_z_m)) / (2.0 * gradient_step);
	
	point_t gradient = {x_partial,y_partial,z_partial};	
	return gradient;
}

