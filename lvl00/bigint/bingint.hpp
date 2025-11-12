#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <string>

class bigint
{
private:
	std::string digits;  // digits are stored reversed (e.g., "123" → digits = "321")

	void trim();         // remove unnecessary leading zeros

public:
	// Constructors
	bigint();                      // default constructor (sets to 0)
	bigint(unsigned long long n);  // construct from integer
	bigint(const bigint &copy);    // copy constructor

	// Assignment
	bigint &operator=(const bigint &copy);

	// Arithmetic
	bigint operator+(const bigint &copy) const;
	bigint &operator+=(const bigint &copy);

	// Increment operators
	bigint &operator++();     // prefix (++x)
	bigint operator++(int);   // postfix (x++)

	// Digit shifting (like bit shifting, but in base 10)
	bigint operator<<(unsigned int n) const;
	bigint &operator<<=(unsigned int n);
	bigint operator>>(unsigned int n) const;
	bigint &operator>>=(unsigned int n);

	// Comparison operators
	bool operator==(const bigint &copy) const;
	bool operator!=(const bigint &copy) const;
	bool operator<(const bigint &copy) const;
	bool operator>(const bigint &copy) const;
	bool operator<=(const bigint &copy) const;
	bool operator>=(const bigint &copy) const;
};

// Output stream operator (defined outside the class)
std::ostream &operator<<(std::ostream &os, const bigint &n);

#endif