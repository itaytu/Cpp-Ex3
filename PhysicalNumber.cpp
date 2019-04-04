//
// Created by moshe on 02/04/2019.
//

#include "PhysicalNumber.h"
#include "iostream"

using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, Unit unit) {
    this -> unit = unit;
    double tmp;
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
    this -> value = tmp;
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
    double tmp;
    Unit unit;
    if((int)c1.unit%3 == (int)c2.unit%3) {
        if((int)c1.unit%3 == 0) {
            c1.value + c2.value
        }
        else if((int)c1.unit%3 == 1) {

        }
        else {

        }
    }
    else
        throw "Invalid operation";
}

//const ariel::PhysicalNumber ariel::operator+(const ariel::PhysicalNumber &p1, const ariel::PhysicalNumber &p2) {
//    switch ()
//}

using namespace std;

int main() {
    ariel::Unit unit= ariel::Unit::KM;
    ariel::PhysicalNumber physicalNumber(2, unit);
    cout << physicalNumber;


    return 0;
}