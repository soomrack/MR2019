#include <iostream>
#include <math.h>

double k, c; //кф прямой
double a, b, r; // кф окружности

double Diskrim() 
{
	float D = pow(2*k*(c-b)-2*a,2)-4*(k*k+1)*(a*a+pow(c-b,2)-r*r);
	return D;
}

double line(double k, double x, double b)
{
	return (k*x + b);
}


int main() 
{
	setlocale(LC_ALL, "Russian");
	k = 1;
	c = 0;
	a = 2;
	b = 0;
	r = 2;

	double D=Diskrim();
		if (D >= 0.0)
		{
			double X1 = (-(2.0 * k*(c - b) - 2.0 * a) + sqrt(D)) / (2.0 * (1.0 + pow(k, 2)));
			double Y1 = line(k, X1, b);
			printf("Первая точка пересечения: %f %f", X1, Y1);
				if ((D < 0.0 + pow(10,-5)) & (D > 0.0 - pow(10, -5)))
					printf("1 корень\n");
				else
				{
					double X2 = (-(2.0 * k*(c - b) - 2.0 * a) - sqrt(D)) / (2.0 * (1.0 + pow(k, 2)));
					double Y2 = line(k, X2, b);
					printf("\nВторая точка пересечения: %f %f", X2, Y2);
					printf("\nДва корня\n");
				}
		}
		else
			printf("нет корней\n");
		
		system("pause");
		return 0;
}




