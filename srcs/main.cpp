#include <typelib/num.hpp>

int	main(void) {
	num	n("172");
	num	t("-15");

	n.show();
	t.show();
	num p = n + t;
	p.show();
	return (0);
}