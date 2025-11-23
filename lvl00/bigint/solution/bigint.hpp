#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

class bigint{
    private:
        std::string _digits;

    public:
        bigint();
        bigint(unsigned long long n);
        bigint(std::string str);
        bigint(const bigint& src);

        bigint& operator= (const bigint& src);

        ~bigint();

        std::string getDigits() const;

        bool operator <(const bigint& other) const;
        bool operator >(const bigint& other) const;
        bool operator <=(const bigint& other) const;
        bool operator >=(const bigint& other) const;
        bool operator ==(const bigint& other) const;
        bool operator !=(const bigint& other) const;

        //addition + +=
        bigint operator+ (const bigint& other) const;
        bigint& operator+= (const bigint& other);
        
        //increment ++x x++
        bigint& operator ++();
        bigint operator ++(int);

        //digit shifts
        bigint operator <<(unsigned int n) const;
        bigint operator >>(unsigned int n) const;
        bigint& operator <<=(unsigned int n);
        bigint& operator >>=(unsigned int n);

        //bigint shifts
        bigint operator <<(const bigint& other) const;
        bigint operator >>(const bigint& other) const;
        bigint& operator <<=(const bigint& other);
        bigint& operator >>=(const bigint& other);
};

std::ostream& operator <<(std::ostream& output, const bigint& obj);
int toInt(const bigint& obj);