
# Gradient Descent 3D Solver

This project implements a simple gradient descent algorithm to find the minima of positive functions defined in 3D space. It uses finite difference methods to approximate the gradient of the function at a given point.

## Features

- Subtraction of 3D points.
- Scalar multiplication of 3D points.
- Computation of the magnitude (modulus) of a 3D point.
- Gradient computation using the centered finite difference method.
- Gradient descent solver to find the local minima of a function in 3D space.

## Project Structure

- `point.h`: Header file defining operations on 3D points (`point_t`), such as subtraction, scalar multiplication, and modulus computation.
- `gradient_descent.h`: Header file defining the gradient descent solver and the gradient computation functions.
- `main.c`: Example usage of the gradient descent algorithm on multiple functions.
- `point.c`: Implementation of the functions defined in `point.h`.
- `gradient_descent.c`: Implementation of the gradient descent algorithm and the finite difference method for gradient approximation.

## Usage

### 1. Gradient Descent Algorithm

The gradient descent algorithm is implemented in `gradient_descent_solver` and finds the local minima of a user-defined function. It takes the following parameters:

```c
point_t gradient_descent_solver(float (*function)(point_t), float learning_rate, float threshold, int max_iter);
```

- `function`: A pointer to the function whose minima we want to find. This function should take a `point_t` as input and return a `float`.
- `learning_rate`: The learning rate for the descent. Small values help avoid overshooting but may slow convergence.
- `threshold`: The stopping criterion based on how close the function's value is to 0.
- `max_iter`: The maximum number of iterations allowed.

### 2. Gradient Calculation

The gradient at a point is computed using the centered finite difference method. The function `calculate_gradient` performs this task:

```c
point_t calculate_gradient(float (*function)(point_t), point_t point, float gradient_step);
```

- `function`: The function whose gradient is to be calculated.
- `point`: The point at which the gradient is evaluated.
- `gradient_step`: The step size used for finite difference approximation.

### 3. Point Operations

The following operations on 3D points (`point_t`) are supported:

- **Subtraction of Points**:
  ```c
  point_t psubt(point_t point_1, point_t point_2);
  ```
  
- **Scalar Multiplication**:
  ```c
  point_t spmult(point_t point, float scalar);
  ```

- **Modulus of a Point**:
  ```c
  float pmod(point_t point);
  ```

## Example

The `main.c` file contains an example of finding the local minima of several test functions representing sphere intersections.

```c
#include <stdio.h>
#include "gradient_descent.h"

int main() {
    point_t optimum = gradient_descent_solver(sphere_intersection, LEARNING_RATE, ACCURACY_THRESHOLD, SAMPLE_COUNT);
    printf("[EQ 0]> [%f,%f,%f] 
", optimum.x, optimum.y, optimum.z);
    
    // Additional test functions
}
```

Example functions:

```c
float sphere_intersection_1(point_t point);
float sphere_intersection_2(point_t point);
float sphere_intersection_3(point_t point);
```

The output will be the coordinates of the minima for each of the test functions.

### Example Output

```
[EQ 0]> [2.563, 6.234, 3.123]
[EQ 1]> [1.452, 4.634, 5.234]
[EQ 2]> [7.213, 6.423, 3.897]
[EQ 3]> [4.324, 5.421, 2.345]
```

## Compilation and Running

To compile the program, use `gcc` or any other C compiler:

```bash
gcc -o gradient_solver main.c point.c gradient_descent.c -lm
```

Then, run the executable:

```bash
./gradient_solver
```

## Requirements

- C compiler (e.g., GCC)
- Math library (`-lm` for linking math functions like `sqrt`)

## License

This project is open-source and freely available under the  GNU GENERAL PUBLIC LICENSE Version 2.
