#ifndef PROJECT3_PHYSICALNUMBER_H
#define PROJECT3_PHYSICALNUMBER_H

#include "Unit.h"
namespace ariel {
    class PhysicalNumber {
    private:
        double value;
        Unit unit;
        static PhysicalNumber convert(PhysicalNumber pn);
    public:
        PhysicalNumber(double num, Unit unit);
        PhysicalNumber(const PhysicalNumber& pn);

        //Output operator
        friend std::ostream& operator<<(std::ostream& os, const PhysicalNumber& c);
        //Input operator
        friend std::istream& operator>>(std::istream &in, PhysicalNumber &c);


        //Plus operators Binary and Unary
        PhysicalNumber operator+ (const PhysicalNumber& pn1) ;
        PhysicalNumber operator+ () ;
        PhysicalNumber& operator++();
        const PhysicalNumber operator++(int) ;
        PhysicalNumber operator+= (const PhysicalNumber& pn1) ;


        //Minus operators Binary and Unary
        PhysicalNumber operator- (const PhysicalNumber& pn1) ;
        PhysicalNumber operator- () ;
        PhysicalNumber& operator--() ;
        const PhysicalNumber operator--(int) ;
        PhysicalNumber operator-= (const PhysicalNumber& pn1) ;


        //Comparison operators
        bool operator< (const PhysicalNumber& pn2);
        bool operator<= (const PhysicalNumber& pn2);
        bool operator> (const PhysicalNumber& pn2);
        bool operator>= (const PhysicalNumber& pn2);
        bool operator== (const PhysicalNumber& pn2);
        bool operator!= (const PhysicalNumber& pn2);

        void setUnit(Unit unit);
        Unit getUnit();

        void setValue(double value);
        double getValue();
    };
}

#endif //PROJECT3_PHYSICALNUMBER_H
