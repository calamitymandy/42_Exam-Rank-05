bigint::bigint() : _digits("0") {}

bigint::bigint(long long n) : _digits(std::to_string(n)) {}

bigint::bigint(std::string str) : _digits(str) {}

bigint::bigint(const bigint& src){
    *this = src;
}

bigint& bigint::operator= (const bigint& src){
    if (this != &src)
        this->_digits = src._digits;
    return *this;
}

bigint::~bigint(){}

std::string bigint::getDigits() const{
    return this->_digits;
}

bigint bigint::operator+ (const bigint& other) const{
    std::string result;
    int carry = 0;

    int i = this->_digits.size() - 1;
    int j = other.getDigits().size() - 1;

    while (i >= 0 || j >= 0 || carry != 0){
        int sum = carry;
        if (i >= 0)
             sum += this->_digits[i--] - '0';
        if (j >= 0)
            sum += other._digits[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return bigint(result);
}

bigint& bigint::operator+= (const bigint& other){
    *this = *this + other;
    return *this;
}

bigint bigint::operator++ (int){
    bigint tmp = *this;
    *this = *this + bigint(1);
    return tmp;
}

bigint& bigint::operator++ (){
    *this = *this + bigint(1);
    return *this;
}

bigint bigint::operator<< (int n){
    if (*this == bigint(0))
        return *this;
    std::string result = this->_digits;
    result.append(n, '0');
    return bigint(result);
}

bigint bigint::operator>> (int n){
    if (this->_digits.size() <= n)
        return bigint(0);
    return bigint(this->_digits.substr(0, (this->_digits.size() - n)));
}

bigint& bigint::operator<<= (int n){
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>= (int n){
    *this = *this >> n;
    return *this;
}

bigint bigint::operator << (const bigint& other) const{
    bigint tmp = *this;
    tmp << toInt(other);
    return tmp;
}

bigint bigint::operator >> (const bigint& other) const{
    bigint tmp = *this;
    tmp >> toInt(other);
    return tmp;
}

bigint& bigint::operator <<= (const bigint& other){
    *this = *this << toInt(other);
    return *this;
}

bigint& bigint::operator >>= (const bigint& other){
    *this = *this >> toInt(other);
    return *this;
}

bool bigint::operator== (const bigint& other) const{
    if (this->_digits == other.getDigits())
        return true;
    return false;
}

bool bigint::operator!= (const bigint& other) const{
    if (this->_digits != other.getDigits())
        return true;
    return false;
}

bool bigint::operator> (const bigint& other) const{
    if (this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() > other.getDigits().size());
    return this->_digits > other.getDigits();
}

bool bigint::operator< (const bigint& other) const{
    if (this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() < other.getDigits().size());
    return this->_digits > other.getDigits();
}

bool bigint::operator>= (const bigint& other) const{
    if (this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() <= other.getDigits().size());
    return this->_digits > other.getDigits();
}

bool bigint::operator<= (const bigint& other) const{
    if (this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() <= other.getDigits().size());
    return this->_digits > other.getDigits();
}

std::ostream& operator<< (std::ostream& output, const bigint& obj){
    output << obj.getDigits();
    return output;
}

int toInt(const bigint& obj){
    if (obj.getDigits().size() > 9)
        return INT_MAX;
    int res = std::stoi(obj.getDigits());
    return res;
}