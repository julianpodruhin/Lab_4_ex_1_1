#include <iostream>
#include <cstdlib>

enum
{
	HAS_ROOTS = 1,
	ROOTS_EQUAL = 0,
	NO_ROOTS = -1
};

int equation_root(double, double, double, double&, double&);

int main()
{
	double x1, x2;
	int root_result = equation_root(1, -2, 1, x1, x2);
	switch (root_result)
	{
		case HAS_ROOTS: 
			std::cout << "Roots x1 = " << x1 << " x2 = " << x2 << std::endl;
			break;
		case ROOTS_EQUAL: 
			std::cout << "Only one root x1 = x2 = " << x1 << std::endl;
			break;
		case NO_ROOTS: 
			std::cout << "No roots" << std::endl;
			break;
	}
	return 0;
}

int equation_root(double a, double b, double c, double& x1, double& x2)
{
	if (a == 0)
	{
		return -1;
	}
	double discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
	{
		return -1;
	}
	x1 = ( - b + sqrt(discriminant)) / (2 * a);
	x2 = ( - b - sqrt(discriminant)) / (2 * a);
	return x1 == x2 ? 0 : 1;
}