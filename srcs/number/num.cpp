#include <typelib/num.hpp>

num::num(unsigned long long n): hasDot(false) {
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


num::num(long long n): hasDot(false) {
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

num::num(std::string n): hasDot(false) {
	size_t pos = 0;

	if (n[pos] == '+' || n[pos] == '-')
		this->internal += n[pos++];
	for (; pos < n.length(); pos++) {
		if ((!std::isdigit(n[pos]) && n[pos] != '.') || (n[pos] == '.' && this->hasDot))
			break;
		this->internal += n[pos];
		if (n[pos] == '.')
			this->hasDot = true;
	}
	if (this->internal == "+" || this->internal == "-")
		this->internal = "0";
}

num::num(const num &obj): hasDot(false) {
	if (this == &obj)
		return ;
	this->internal = obj.internal;
}

num	&num::operator=(const num &obj) {
	if (this != &obj) {
		this->internal = obj.internal;
		this->hasDot = obj.hasDot;
	}
	return (*this);
}


num::~num(void) {
	
}

void	num::show(void) {
		std::cout << this->internal << std::endl;
}