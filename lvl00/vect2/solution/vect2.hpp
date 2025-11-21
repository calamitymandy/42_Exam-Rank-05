#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>   // Needed for operator<<

class vect2 {
private:
    int x;
    int y;
public:
    // ------------------- Constructors -------------------
    vect2();                            // Default constructor: initializes x and y to 0
    vect2(int x, int y);                // Constructor with two ints (x, y)
    vect2(const vect2 &copy);           // Copy constructor
    vect2 &operator=(const vect2 &copy);// Copy assignment operator
    ~vect2();                           // Destructor (empty because nothing dynamic)

    // ------------------- Arithmetic -------------------
    vect2 operator+(const vect2 &right) const;  // Vector addition
    vect2 &operator+=(const vect2 &right);      // In-place vector addition

    vect2 operator-(const vect2 &right) const;  // Vector subtraction
    vect2 operator-() const;                    // Unary minus (negates both values)
    vect2 &operator-=(const vect2 &right);      // In-place vector subtraction

    vect2 operator*(int num) const;             // Multiply vector by scalar
    vect2 &operator*=(int num);                 // In-place multiply by scalar

    // ------------------- Increment / Decrement -------------------
    vect2 &operator++();      // Prefix ++ : increments x and y then returns *this
    vect2 operator++(int);    // Postfix ++ : returns old value, then increments

    vect2 &operator--();      // Prefix --
    vect2 operator--(int);    // Postfix --

    // ------------------- Comparison -------------------
    bool operator==(const vect2 &right) const;   // Compare x and y
    bool operator!=(const vect2 &right) const;   // Logical negation of ==

    // ------------------- Index access -------------------
    int operator[](int index) const;     // Const access: read-only
    int &operator[](int index);          // Non-const access: allows modifying x or y
};

// Multiply scalar * vect2 (friend-like free function)
vect2 operator*(int num, const vect2 &right);

// Output stream operator: allows cout << vect2
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif
