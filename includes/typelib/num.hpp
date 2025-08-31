#ifndef NUM_H
# define NUM_H

# include <string>
# include <iostream>

class Number {
	public:
		Number(int n);
		Number(long long n);
		Number(unsigned long n);
		Number(unsigned long long n);
		Number(float n);
		Number(double n);
		Number(char *n);
		Number(std::string);
		Number(const Number &obj);
		Number &operator=(const Number &obj);
		~Number();

		// utilities
		void	show(void);
	
	private:
		std::string internal;
};

#endif