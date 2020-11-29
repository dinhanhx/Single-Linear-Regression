#include <stdio.h>
#include <math.h>
double errorFunc(double* x, double* y, int length,
				double *theta)
{
	double sum = 0.0;
	for (int i = 0; i < length; i++)
	{
		sum += ((*(theta + 0)) + (*(theta + 1)) * (*(x + i)) - (*(y + i))) * ((*(theta + 0)) + (*(theta + 1)) * (*(x + i)) - (*(y + i)));
	}
	return sum /(2* (double)length);
}

double derivativeOfErrorFunc(double *x, double *y, int length,
							double *theta, bool isThetaZero)
{
	double sum = 0.0;
	if (isThetaZero)
	{
		for (int i = 0; i < length; i++)
		{
			sum += (*(theta + 0)) + (*(theta + 1)) * (*(x+i)) - (*(y+i));
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			sum += ((*(theta + 0)) + (*(theta + 1)) * (*(x + i)) - (*(y + i))) * (*(x + i));
		}
	}
	return sum / (double)length;
}

double *simpleLinearRegression(double *x, double *y, int length,
						double alpha = 0.001,
						int max_interation = 1000,
						bool showLog = true)
{
	// This only works for y = theta0 + theta1 * x
	static double theta[2] = {0.0, 0.0};
	for (int iter = 0; iter < max_interation; iter++)
	{
		theta[0] = theta[0] - alpha * derivativeOfErrorFunc(x, y, length, theta, true);
		theta[1] = theta[1] - alpha * derivativeOfErrorFunc(x, y, length, theta, false);
		if (showLog)
		{
			printf("Error value: %f\n", errorFunc(x, y, length, theta));
			printf("Updated theta: %f %f\n", theta[0], theta[1]);
			printf("===\n");
		}
	}
	return theta;
}

void arrayPrint(double* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%f ", *(arr + i));
	}
	printf("\n");
}

int main()
{
	printf("Linear regression for y = t1*x + t0\nNote that t is short form of theta\n");
	double x[6] = { 20.0, 25.0 , 30.0, 40.0, 43.0, 51.0 };
	double y[6] = {1.6, 1.8, 2.5, 3.2, 3.4, 4.5};

	//printf("x values\n");
	//arrayPrint(x, 6);
	//printf("y values\n");
	//arrayPrint(y, 6);

	double* theta = simpleLinearRegression(x, y, 6, 0.001, 5);
	return 0;
}