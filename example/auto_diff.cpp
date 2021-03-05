#include <shijimi/math/auto_diff.hpp>

using namespace shijimi::math;

int main() 
{
	var<2> x1(3.1415926/3,1), x2(7.,2), y;
	
	y = x1*x2 + sin(x1)*x2;
	printf("%f, %f, %f\n", y.val, y.dval(0), y.dval(1));
}