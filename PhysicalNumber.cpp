//
// Created by moshe on 02/04/2019.
//

#include "PhysicalNumber.h"
#include "iostream"

using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, Unit unit) {
    this -> unit = unit;
    this -> value = num;
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