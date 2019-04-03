//
// Created by moshe on 02/04/2019.
//

#ifndef PROJECT3_PHYSICALNUMBER_H
#define PROJECT3_PHYSICALNUMBER_H

#include "Unit.h"
namespace ariel {
    class PhysicalNumber {
    public:
        double value;
        Unit unit;

        PhysicalNumber(double num, Unit unit);

//        const Complex operator+(const Complex& c1, const Complex& c2) {
//            return Complex(c1._re + c2._re, c1._im + c2._im);
//        }

        friend std::ostream& operator<<(std::ostream& os, const PhysicalNumber& c);
        friend const PhysicalNumber operator+ (const PhysicalNumber& c1, const PhysicalNumber& c2);

    };
};

#endif //PROJECT3_PHYSICALNUMBER_H
