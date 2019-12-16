#include <iostream>
#include <math.h>

double k, c; //ęô ďđ˙ěîé
double a, b, r; // ęô îęđóćíîńňč

double Diskrim() 
{
	float D2 = pow(2*k*(c-b)-2*a,2)-4*(k*k+1)*(a*a+pow(c-b,2)-r*r);
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
	b = 2.0;
	r = 2;

	double D=Diskrim();
		if (D >= 0.0)
		{
			double X1 = (-(2.0 * k*(c - b) - 2.0 * a) + sqrt(D)) / (2.0 * (1.0 + pow(k, 2)));
			double Y1 = line(k, X1, b);
			printf("Ďĺđâŕ˙ ňî÷ęŕ ďĺđĺńĺ÷ĺíč˙: %f %f", X1, Y1);
				if ((D < 0.0 + pow(10,-5)) & (D > 0.0 - pow(10, -5)))
					printf("1 ęîđĺíü\n");
				else
				{
					double X2 = (-(2.0 * k*(c - b) - 2.0 * a) - sqrt(D)) / (2.0 * (1.0 + pow(k, 2)));
					double Y2 = line(k, X2, b);
					printf("\nÂňîđŕ˙ ňî÷ęŕ ďĺđĺńĺ÷ĺíč˙: %f %f", X2, Y2);
					printf("\nÄâŕ ęîđí˙\n");
				}
		}
		else
			printf("íĺň ęîđíĺé\n");
		
		system("pause");
		return 0;
}




