#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "discriminant.h"

const double EPS = 1e-10;
const short ERROR = -1;
const short NO_ROOTS = 0;
const short ONE_ROOT = 1;
const short TWO_ROOTS = 2;



int check(double d, double f, double eps)
{
	return fabs(d - f) < eps;
}

short computering_roots(double a, double b, double c, double *x1, double *x2)
{
	double D = discriminant(a, b, c);
	if (D < 0)
		return NO_ROOTS;
	if (check(D, 0, EPS))
	{
		*x1 =  -b / (2 / a);
		return ONE_ROOT;
	}
	if (D > 0)
	{
		*x1 = (-b - sqrt(D)) / (2 * a);
		*x2 = (-b + sqrt(D)) / (2 * a);
		return TWO_ROOTS;
	}
	return ERROR;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, x1, x2;
	short fl = 5;
	printf("Введите аргументы: a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a == 0)
		printf("Нет решения!\n");
	else
		fl = computering_roots(a, b, c, &x1, &x2);
	if (fl == 0)
		printf("Нет реальных корней!\n");
	if (fl == 1)
		printf("Только один корень: x = %4.2f\n", x1);
	if (fl == 2)
		printf("Два корня: x1 = %4.2f; x2 = %4.2f\n", x1, x2);
	return 0;
}
