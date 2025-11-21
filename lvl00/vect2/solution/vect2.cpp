#include "vect2.hpp"

// Default: initialize to (0, 0)
vect2::vect2() : x(0), y(0) {}

// Constructor with explicit x, y values
vect2::vect2(int x, int y) : x(x), y(y) {}

// Copy constructor
vect2::vect2(const vect2& copy) : x(copy.x), y(copy.y) {}

// Nothing special in destructor
vect2::~vect2() {}

// Copy assignment operator
vect2& vect2::operator=(const vect2& copy) {
    // Avoid self-assignment (v = v)
    if (this != &copy) {
        this->x = copy.x;
        this->y = copy.y;
    }
    return *this;
}

// v1 + v2
vect2 vect2::operator+(const vect2& right) const {
    vect2 result(*this);     // Start with a copy of left operand
    return result += right;   // Reuse operator+=
}

// v1 += v2
vect2& vect2::operator+=(const vect2& right) {
    this->x += right.x;
    this->y += right.y;
    return *this;
}

// v1 - v2
vect2 vect2::operator-(const vect2& right) const {
    vect2 result(*this);
    return result -= right;
}

// -v (negates the vector)
vect2 vect2::operator-() const {
    return vect2(-(this->x), -(this->y));
}

// v1 -= v2
vect2& vect2::operator-=(const vect2& right) {
    this->x -= right.x;
    this->y -= right.y;
    return *this;
}

// v * n
vect2 vect2::operator*(int num) const {
    vect2 result(*this);
    return result *= num;
}

// v *= n
vect2& vect2::operator*=(int num) {
    this->x *= num;
    this->y *= num;
    return *this;
}

// Prefix ++v
vect2& vect2::operator++() {
    this->x++;
    this->y++;
    return *this;
}

// Postfix v++
vect2 vect2::operator++(int) {
    vect2 result(*this);   // Save original
    ++(*this);             // Use prefix to increment
    return result;         // Return old value
}

// Prefix --v
vect2& vect2::operator--() {
    this->x--;
    this->y--;
    return *this;
}

// Postfix v--
vect2 vect2::operator--(int) {
    vect2 result(*this);
    --(*this);
    return result;
}

// Compare equality
bool vect2::operator==(const vect2& right) const {
    return this->x == right.x && this->y == right.y;
}

// Compare inequality
bool vect2::operator!=(const vect2& right) const {
    return !(*this == right);
}

// Index operator (read-only)
int vect2::operator[](int index) const {
    return index == 0 ? x : y;
}

// Index operator (writeable)
// index 0 → x, anything else → y
int& vect2::operator[](int index) {
    return index == 0 ? x : y;
}

// n * vector (scalar on the left)
vect2 operator*(int num, const vect2& right) {
    vect2 result(right);   // Copy vector
    return result * num;     // Use member operator*
}

// Output format: {x, y}
std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}