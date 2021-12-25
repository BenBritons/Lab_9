//
// Created by Ivan on 25.12.21.
//

#ifndef LAB_9_RATIONALNUMBER_H
#define LAB_9_RATIONALNUMBER_H
#include <iostream>

template<class T>
class RationalNumber {
private:
    T integer_part;
    T numerator;
    T denominator;
    unsigned int gcd( int num,  int den){
        return (den != 0) ? gcd(den, num%den) : num;
    }

public:
    RationalNumber():numerator(0), denominator(1){}
    RationalNumber(T num, T den, T i_p):numerator(num), denominator(den), integer_part(i_p){}

    friend const RationalNumber& operator-(const RationalNumber& i);
    RationalNumber& operator=(const RationalNumber& right);
    friend RationalNumber& operator+=( RationalNumber& left, const RationalNumber& right);
    friend RationalNumber& operator-=( RationalNumber& left, const RationalNumber& right);
    friend RationalNumber& operator*=( RationalNumber& left, const RationalNumber& right);
    friend RationalNumber& operator/=( RationalNumber& left, const RationalNumber& right);
    template <typename U>
    friend bool operator== (const RationalNumber<U>  &c1, const RationalNumber<U>  &c2);
    template <typename U>
    friend bool operator!= (const RationalNumber<U>  &c1, const RationalNumber<U>  &c2);
    template <typename U>
    friend bool operator< ( RationalNumber<U>  left,  RationalNumber<U>  right);
    template <typename U>
    friend bool operator<= ( RationalNumber<U>  left,  RationalNumber<U>  right);
    template <typename U>
    friend bool operator>=( RationalNumber<U>  left,  RationalNumber<U>  right);
    template <typename U>
    friend bool operator> ( RationalNumber<U> left,  RationalNumber<U> right);
    friend RationalNumber operator++ ( RationalNumber left);
    friend RationalNumber operator-- ( RationalNumber left);

    void operator+();
    RationalNumber<T> operator+( RationalNumber<T> right);
    RationalNumber<T> operator-( RationalNumber<T> right);
    RationalNumber<T> operator*( RationalNumber<T> right);
    RationalNumber<T> operator/( RationalNumber<T> right);
    template <typename U>
    friend std::ostream& operator<< (std::ostream &out, const RationalNumber<U> &r);

};

template<class T>
void RationalNumber<T>::operator+() {

    int g_c_d;
    if(numerator < 0){
        g_c_d = gcd(-numerator, denominator);
    } else{
        g_c_d = gcd(numerator,denominator);
    }
    numerator = numerator / g_c_d;
    denominator = denominator / g_c_d;
}
template<class T>
const RationalNumber<T>& operator-(const RationalNumber<T>& i) {
    i.numerator = i.numerator * (-1);
    return i;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator+( RationalNumber<T> right) {
    RationalNumber a(0,1,0);
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    a.numerator = right.numerator * denominator + numerator * right.denominator;
    a.denominator = right.denominator * denominator;
    if(a.numerator > a.denominator){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }
    +a;
    return a;
}
template<class T>
RationalNumber<T> RationalNumber<T>::operator-( RationalNumber<T> right) {
    RationalNumber a(0,1,0);
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    a.numerator = numerator * right.denominator - right.numerator * denominator ;
    a.denominator = right.denominator * denominator;
    if(a.numerator > a.denominator){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }
    +a;
    return a;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator*( RationalNumber<T> right) {
    RationalNumber a(0,1,0);
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }

    a.numerator = right.numerator * numerator;
    a.denominator = right.denominator * denominator;
    if(a.numerator > a.denominator){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }
    +a;
    return a;
}


template<class T>
RationalNumber<T> RationalNumber<T>::operator/( RationalNumber<T> right) {
    RationalNumber a(0,1,0);
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }
    int tmp_int;
    tmp_int = right.denominator;
    right.denominator = right.numerator;
    right.numerator = tmp_int;

    a.numerator = right.numerator * numerator;
    a.denominator = right.denominator * denominator;
    if(a.denominator < 0){
        a.numerator = -a.numerator;
        a.denominator = -a.denominator;
    }
    if(abs(a.numerator) >= abs(a.denominator)){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }

    +a;
    return a;
}





template<class T>
RationalNumber<T>& RationalNumber<T>::operator=(const RationalNumber<T>& right){
    integer_part = right.integer_part;
    denominator = right.denominator;
    numerator = right.numerator;
}


template<class T>
RationalNumber<T>& operator+=( RationalNumber<T>& left,  const RationalNumber<T>& right){
    left = right + left;
    return left;
}

template<class T>
RationalNumber<T>& operator-=( RationalNumber<T>& left,  const RationalNumber<T>& right){
    left = right - left;
    return left;
}

template<class T>
RationalNumber<T>& operator*=( RationalNumber<T>& left,  const RationalNumber<T>& right){
    left = right * left;
    return left;
}
template<class T>
RationalNumber<T>& operator/=( RationalNumber<T>& left,  const RationalNumber<T>& right){
    left = right / left;
    return left;
}

template<class T>
bool operator==(const RationalNumber<T> &c1, const RationalNumber<T> &c2) {
    if(c1.numerator == c2.numerator && c1.denominator == c2.denominator && c1.integer_part == c2.integer_part){
        return true;
    }
    return false;
}

template<class T>
bool operator!=(const RationalNumber<T> &c1, const RationalNumber<T> &c2) {
    if(c1.numerator != c2.numerator || c1.denominator != c2.denominator || c1.integer_part || c2.integer_part){
        return true;
    }
    return false;
}

template<class T>
bool operator<(RationalNumber<T> left,RationalNumber<T> right) {
    if(left.integer_part != 0){
        left.numerator = left.denominator * left.integer_part + left.numerator;
        left.integer_part = 0;
    }
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    left.numerator = left.numerator * right.denominator;
    right.numerator = right.numerator * left.denominator;
    if(left.numerator < right.numerator)
        return true;

    return false;
}


template<class T>
bool operator<=(RationalNumber<T> left,RationalNumber<T> right) {
    if(left.integer_part != 0){
        left.numerator = left.denominator * left.integer_part + left.numerator;
        left.integer_part = 0;
    }
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    left.numerator = left.numerator * right.denominator;
    right.numerator = right.numerator * left.denominator;
    if(left.numerator <= right.numerator)
        return true;

    return false;
}



template<class T>
bool operator>(RationalNumber<T> left,RationalNumber<T> right) {
    if(left.integer_part != 0){
        left.numerator = left.denominator * left.integer_part + left.numerator;
        left.integer_part = 0;
    }
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    left.numerator = left.numerator * right.denominator;
    right.numerator = right.numerator * left.denominator;
    if(left.numerator > right.numerator)
        return true;

    return false;
}

template<class T>
bool operator>=(RationalNumber<T> left,RationalNumber<T> right) {
    if(left.integer_part != 0){
        left.numerator = left.denominator * left.integer_part + left.numerator;
        left.integer_part = 0;
    }
    if(right.integer_part != 0){
        right.numerator = right.denominator * right.integer_part + right.numerator;
        right.integer_part = 0;
    }
    left.numerator = left.numerator * right.denominator;
    right.numerator = right.numerator * left.denominator;
    if(left.numerator >= right.numerator)
        return true;

    return false;
}

template<class T>
RationalNumber<T> operator++(RationalNumber<T> left) {
    left.integer_part++;
    return left;
}


template<class T>
RationalNumber<T> operator--(RationalNumber<T> left) {
    left.integer_part--;
    return left;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, const RationalNumber<T> &r) {
    out <<  r.numerator << '/' << r.denominator;
    return out;
}


#endif //LAB_9_RATIONALNUMBER_H
