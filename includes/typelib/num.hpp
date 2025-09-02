#ifndef NUM_H
# define NUM_H

# include <string>
# include <iostream>

class num {
	public:
		num(void);
		num(long long n);
		num(unsigned long long n);
		num(double n);
		num(std::string);
		num(const num &obj);
		num &operator=(const num &obj);
		~num();
		num	operator+(const num &obj);

		// utilities
		void	show(void);
	
	private:
		std::string	internal;
		bool		hasDot;
};

#endif