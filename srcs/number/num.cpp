#include <typelib/num.hpp>

num::num(void): internal("0") {}

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

num	num::operator+(const num &obj) {
	char			carry = 0;
	char			placeResult = 0;
	size_t			pos = 0;
	std::string		res;
	std::string 	l(this->internal.rbegin(), this->internal.rend());
	std::string 	r(obj.internal.rbegin(), obj.internal.rend());

	for (; pos < l.length() && pos < r.length(); pos++) {
		placeResult = (l[pos] - 48) + (r[pos] - 48) + carry;
		if (placeResult > 9) {
			carry = placeResult / 10;
			placeResult %= 10;
		} else
			carry = 0;
		res += placeResult + 48;
	}

	for (; pos < l.length(); pos++) {
		placeResult = l[pos] - 48 + carry;
		if (placeResult > 9) {
			carry = placeResult / 10;
			placeResult %= 10;
		} else
			carry = 0;
		res += placeResult + 48;
	}

	for (; pos < r.length(); pos++) {
		placeResult = r[pos] - 48 + carry;
		if (placeResult > 9) {
			carry = placeResult / 10;
			placeResult %= 10;
		} else
			carry = 0;
		res += placeResult + 48;
	}

	if (carry)
		res += carry + 48;
	num n = num(std::string(res.rbegin(), res.rend()));
	return (n);
}

num::~num(void) {
	
}

void	num::show(void) {
		std::cout << this->internal << std::endl;
}