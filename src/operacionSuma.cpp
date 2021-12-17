#include "operacionSuma.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

OperacionSuma::OperacionSuma() {
    
}

string OperacionSuma::Ejecute(string valor) {

    stringstream ss;  
    int num;       //int where the first number is stored
    char plussign; //char that stores the + sign
    int num2;      //int where the second number's stored
    
    ss << valor;   //input string is copied into stringstream
    
    ss >> num;     //values are stored into their respective variables one by one
    ss>>plussign;  
    ss >> num2;

    
    int result=num+num2; //int containing the result

    valor= std::to_string(result); //result converted to string and copied to string valor
    return valor;
}