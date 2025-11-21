#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>

class vect2 {
    private:
        int x;
        int y;
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2 &copy);
        vect2 &operator=(const vect2 &copy);
        ~vect2();

        vect2 operator+(const vect2 &right) const;
        vect2 &operator+=(const vect2 &right);

        vect2 operator-(const vect2 &right) const;
        vect2 &operator-=(const vect2 &right);

        vect2 operator*(int num) const;
        vect2 &operator*=(int num);

        vect2 &operator++();
        vect2 operator++(int);

        vect2 &operator--();
        vect2 operator--(int);

        bool operator==(const vect2 &right) const;
        bool operator!=(const vect2 &right) const;

        int operator[](int index) const;
        int &operator[](int index);
};

vect2 operator*(int num, const vect2 &right);

std::ostream &operator<<(std::ostream &os, const vect2 &v);





#endif