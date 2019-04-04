//
// Created by moshe on 02/04/2019.
//

#include "PhysicalNumber.h"
#include "iostream"

using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, Unit unit) {
    this -> unit = unit;
    this->value = num;
   /* double tmp;
    switch (unit){
        case Unit::KM : tmp = num*1000*100; break;
        case Unit::M : tmp = num*100; break;
        case Unit::CM : tmp = num; break;

        case Unit::TON : tmp = num*1000*1000; break;
        case Unit::KG : tmp = num*1000; break;
        case Unit::G : tmp = num; break;

        case Unit::HOUR : tmp = num*60*60; break;
        case Unit::MIN : tmp = num*60; break;
        case Unit::SEC : tmp = num; break;

        default: throw ("Invalid input");
    }
    this -> value = tmp;*/
}

std::ostream &ariel::operator<<(std::ostream &os, const PhysicalNumber &c) {

    std::string output;
    switch (c.unit){
        case Unit::KM : output = "KM"; break;
        case Unit::M : output = "M"; break;
        case Unit::CM : output = "CM"; break;
        case Unit::TON : output = "TON"; break;
        case Unit::KG : output = "KG"; break;
        case Unit::G : output = "G"; break;
        case Unit::HOUR : output = "HOUR"; break;
        case Unit::MIN : output = "MIN"; break;
        case Unit::SEC : output = "SEC"; break;
        default: throw ("Invalid input");
    }
    return os << c.value << output;
}

const ariel::PhysicalNumber ariel::operator+(const ariel::PhysicalNumber &c1, const ariel::PhysicalNumber &c2) {
    PhysicalNumber tmp1 = PhysicalNumber::convert(c1);
    PhysicalNumber tmp2 = PhysicalNumber::convert(c2);

    if((int)tmp1.unit%3 == (int)tmp2.unit%3) {
        double tmp = tmp1.value + tmp2.value;
        if((int)tmp1.unit%3 == 0) {
           switch (c1.unit){
               case Unit::KM : tmp = tmp/(1000*100); break;
               case Unit::M : tmp = tmp/100; break;
               case Unit::CM : tmp = tmp; break;
           }
        }
        else if((int)tmp1.unit%3 == 2) {
            switch (c1.unit){
                case Unit::TON : tmp = tmp/(1000*1000); break;
                case Unit::KG : tmp = tmp/1000; break;
                case Unit::G : tmp = tmp; break;
            }
        }
        else {
            switch (c1.unit){
                case Unit::HOUR : tmp = tmp/(60*60); break;
                case Unit::MIN : tmp = tmp/60; break;
                case Unit::SEC : tmp = tmp; break;
            }
        }
    }
    else
        throw "Invalid operation";
    return  PhysicalNumber(tmp,  c1.unit);
}

PhysicalNumber PhysicalNumber::convert(PhysicalNumber pn) {
    double tmp;
    switch (pn.unit){
        case Unit::KM : tmp = pn.value*1000*100; pn.unit= Unit::CM; break;
        case Unit::M : tmp = pn.value*100; pn.unit= Unit::CM; break;
        case Unit::CM : tmp = pn.value; break;

        case Unit::TON : tmp = pn.value*1000*1000; pn.unit= Unit::G; break;
        case Unit::KG : tmp = pn.value*1000; pn.unit= Unit::G; break;
        case Unit::G : tmp = pn.value; break;

        case Unit::HOUR : tmp = pn.value*60*60; pn.unit= Unit::SEC; break;
        case Unit::MIN : tmp = pn.value*60; pn.unit= Unit::SEC; break;
        case Unit::SEC : tmp = pn.value; break;

        default: throw ("Invalid input");
    }
    pn.value = tmp;
    return pn;
}

const PhysicalNumber ariel::operator-(const PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    PhysicalNumber tmp = pn2;
    tmp.value = -tmp.value;
    return pn1 + tmp;
}

const PhysicalNumber ariel::operator-(const PhysicalNumber &pn1) {
    PhysicalNumber tmp = pn1;
    tmp.value = -tmp.value;
    return tmp;
}

const PhysicalNumber ariel::operator+(const PhysicalNumber &pn1) {
    return pn1;
}

const PhysicalNumber &ariel::operator+=(PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    PhysicalNumber temp=pn1+pn2;
    pn1=temp;
    return pn1;
}

const PhysicalNumber &ariel::operator-=(PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    PhysicalNumber temp=pn1-pn2;
    pn1=temp;
    return pn1;
}

const PhysicalNumber ariel::operator++(PhysicalNumber &pn1) {
    pn1.value=pn1.value+1;
    return pn1;
}

const PhysicalNumber ariel::operator++(PhysicalNumber &pn1, int) {
    return ++pn1;
}

const PhysicalNumber ariel::operator--(PhysicalNumber &pn1) {
    pn1.value=pn1.value-1;
    return pn1;
}

const PhysicalNumber ariel::operator--(PhysicalNumber &pn1, int) {
    return --pn1;
}

const bool ariel::operator!=(const PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    return 0;
}

const bool ariel::operator==(const PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    return 0;
}

const bool ariel::operator>=(const PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    return 0;
}

const bool ariel::operator>(const PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    return 0;
}

const bool ariel::operator<=(const PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    return 0;
}

const bool ariel::operator<(const PhysicalNumber &pn1, const PhysicalNumber &pn2) {
    return 0;
}

using namespace std;

