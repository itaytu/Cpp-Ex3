#include "PhysicalNumber.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <exception>

using namespace std;
using namespace ariel;

using namespace std;

const char* units[]={"[km]","[hour]","[ton]","[m]","[min]","[kg]","[cm]","[sec]","[g]"};

//---------------------CONSTRUCTOR-----------------------
PhysicalNumber::PhysicalNumber(const PhysicalNumber &pn) {
    this->value = pn.value;
    this->unit = pn.unit;
}

//---------------------COPY CONSTRUCTOR-------------------
PhysicalNumber::PhysicalNumber(double num, Unit unit) {
    this -> unit = unit;
    this->value = num;
}


//-----------------------OUTPUT OPERATOR------------------------------
ostream &ariel::operator<<(ostream &os, const PhysicalNumber &c) {
    string output;
    switch (c.unit){
        case Unit::KM : output = "[km]"; break;
        case Unit::M : output = "[m]"; break;
        case Unit::CM : output = "[cm]"; break;
        case Unit::TON : output = "[ton]"; break;
        case Unit::KG : output = "[kg]"; break;
        case Unit::G : output = "[g]"; break;
        case Unit::HOUR : output = "[hour]"; break;
        case Unit::MIN : output = "[min]"; break;
        case Unit::SEC : output = "[sec]"; break;
        default: {
            string error = "Invalid Input";
            throw invalid_argument(error);
        }
    }
    return os << c.value << output;
}

//-----------------------INPUT OPERATOR------------------------------
istream &ariel::operator>>(istream &in, PhysicalNumber &c) {
    string tmp;
    double value;
    in >> value >> tmp;
    transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

    if(tmp == "[km]" ) c.setUnit(Unit::KM);
    else if(tmp == "[m]" ) c.setUnit(Unit::M);
    else if(tmp == "[cm]" ) c.setUnit(Unit::CM);

    else if(tmp == "[ton]" ) c.setUnit(Unit::TON);
    else if(tmp == "[kg]" ) c.setUnit(Unit::KG);
    else if(tmp == "[g]" ) c.setUnit(Unit::G);

    else if(tmp == "[hour]" ) c.setUnit(Unit::HOUR);
    else if(tmp == "[min]" ) c.setUnit(Unit::MIN);
    else if(tmp == "[sec]") c.setUnit(Unit::SEC);

    else {
        return in;
    }

    c.setValue(value);
    return in;
}

//-----------------------PLUS OPERATOR------------------------------
ariel::PhysicalNumber PhysicalNumber::operator+(const ariel::PhysicalNumber &c1){
    PhysicalNumber tmp1 = PhysicalNumber::convert(*this);
    PhysicalNumber tmp2 = PhysicalNumber::convert(c1);
    double tmp;
    if((int)tmp1.unit%3 == (int)tmp2.unit%3) {
        tmp = tmp1.value + tmp2.value;
        if((int)tmp1.unit%3 == 0) {
            switch (this->unit){
                case Unit::KM : tmp = tmp/(1000*100); break;
                case Unit::M : tmp = tmp/100; break;
                case Unit::CM : break;
                default: break;
            }
        }
        else if((int)tmp1.unit%3 == 2) {
            switch (this->unit){
                case Unit::TON : tmp = tmp/(1000*1000); break;
                case Unit::KG : tmp = tmp/1000; break;
                case Unit::G : break;
                default: break;
            }
        }
        else {
            switch (this->unit){
                case Unit::HOUR : tmp = tmp/(60*60); break;
                case Unit::MIN : tmp = tmp/60; break;
                case Unit::SEC : break;
                default: break;
            }
        }
    }
    else {
        string s = "Units do not match - " ;
        s.append(units[(int) unit]);
        string s2 = " cannot be converted to ";
        s2.append(units[(int) c1.unit]);
        throw invalid_argument(s.append(s2));
    }
    PhysicalNumber a(tmp,this->unit);
    return (a);

}

//-----------------------UNARY AND BINARY OPERATORS------------------------------
PhysicalNumber PhysicalNumber::operator+() {
    return *this;
}

PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber &pn1) {
    *this=*this+pn1;
    return *this;
}

PhysicalNumber& PhysicalNumber::operator++() {
    value++;
    return *this;
}

const PhysicalNumber PhysicalNumber::operator++(int) {
    PhysicalNumber const copy (*this);
    value++;
    return copy;
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &pn1) {
    PhysicalNumber tmp = pn1;
    tmp.setValue(-tmp.value);
    return *this+tmp;
}

PhysicalNumber PhysicalNumber::operator-() {
    return PhysicalNumber(-(this->value),this->unit);
}

PhysicalNumber PhysicalNumber::operator-=(const PhysicalNumber &pn1) {
    *this=*this-pn1;
    return *this;
}

PhysicalNumber& PhysicalNumber::operator--() {
    value--;
    return *this;
}

const PhysicalNumber PhysicalNumber::operator--(int) {
    PhysicalNumber const copy(*this);
    value--;
    return copy;
}

//-----------------------COMPARISON OPERATORS------------------------------
bool PhysicalNumber::operator!=(const PhysicalNumber &pn2) {
    return (!(*this==pn2));
}

bool PhysicalNumber::operator==(const PhysicalNumber &pn2) {

    PhysicalNumber tmp1 = PhysicalNumber::convert(*this);
    PhysicalNumber tmp2 = PhysicalNumber::convert(pn2);

    if((int)tmp1.unit%3 == (int)tmp2.unit%3){
        if (tmp1.value==tmp2.value) return true;
    } else {
        string s = "Units do not match - " ;
        s.append(units[(int) this->unit]);
        string s2 = " cannot be converted to ";
        s2.append(units[(int) pn2.unit]);
        throw invalid_argument(s.append(s2));
    }
    return false;
}

bool PhysicalNumber::operator>=(const PhysicalNumber &pn2) {
    return (*this>pn2||*this==pn2);
}

bool PhysicalNumber::operator>(const PhysicalNumber &pn2) {
    PhysicalNumber tmp1 = PhysicalNumber::convert(*this);
    PhysicalNumber tmp2 = PhysicalNumber::convert(pn2);

    if((int)tmp1.unit%3 == (int)tmp2.unit%3){
        if (tmp1.value>tmp2.value) return true;
    } else {
        string s = "Units do not match - " ;
        s.append(units[(int) this->unit]);
        string s2 = " cannot be converted to ";
        s2.append(units[(int) pn2.unit]);
        throw invalid_argument(s.append(s2));
    }
    return false;
}

bool PhysicalNumber::operator<=(const PhysicalNumber &pn2) {
    return ((*this<pn2)||(*this==pn2));
}

bool PhysicalNumber::operator<(const PhysicalNumber &pn2) {
    PhysicalNumber tmp1 = PhysicalNumber::convert(*this);
    PhysicalNumber tmp2 = PhysicalNumber::convert(pn2);

    if((int)tmp1.unit%3 == (int)tmp2.unit%3){
        if (tmp1.value<tmp2.value) return true;
    } else {
        string s = "Units do not match - " ;
        s.append(units[(int) this->unit]);
        string s2 = " cannot be converted to ";
        s2.append(units[(int) pn2.unit]);
        throw invalid_argument(s.append(s2));
    }
    return false;
}




//-----------------------FUNCTION TO CONVERT UNITS------------------------------
PhysicalNumber PhysicalNumber::convert(PhysicalNumber pn) {
    double tmp;
    switch (pn.unit){
        case Unit::KM : tmp = pn.value*1000*100; pn.setUnit(Unit::CM); break;
        case Unit::M : tmp = pn.value*100; pn.setUnit(Unit::CM); break;
        case Unit::CM : tmp = pn.value; break;

        case Unit::TON : tmp = pn.value*1000*1000; pn.setUnit(Unit::G); break;
        case Unit::KG : tmp = pn.value*1000; pn.setUnit(Unit::G); break;
        case Unit::G : tmp = pn.value; break;

        case Unit::HOUR : tmp = pn.value*60*60; pn.setUnit(Unit::SEC); break;
        case Unit::MIN : tmp = pn.value*60; pn.setUnit(Unit::SEC); break;
        case Unit::SEC : tmp = pn.value; break;

        default: {
            string error = "Invalid Input";
            throw invalid_argument(error);
        }
    }
    pn.setValue(tmp);
    return pn;
}

void PhysicalNumber::setUnit(Unit unit) {
    this->unit = unit;
}

Unit PhysicalNumber::getUnit() {
    return this->unit;
}

void PhysicalNumber::setValue(double value) {
    this->value = value;
}

double PhysicalNumber::getValue() {
    return this->value;
}








