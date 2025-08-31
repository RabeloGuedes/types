#include <typelib/num.hpp>

Number::Number(int n) {
	if (n < 0)
		this->internal += "-";
	std::string inverse;

	do
	{
		inverse += ((n % 10) * (n < 0 ? -1 : 1)) + 48;
		n /= 10;
	} while (n);

	this->internal += std::string(inverse.rbegin(), inverse.rend());
}

void	Number::show(void) {
	std::cout << this->internal << std::endl;
}


Number::~Number(void) {

}