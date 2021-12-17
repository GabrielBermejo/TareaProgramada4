#ifndef OPERACIONSUMA_H
#define OPERACIONSUMA_H

#include <iostream>
#include "operacion.h"
#include "proveedorFormato.h"
#include <string>

using namespace std;
class OperacionSuma: public Operacion {

    public:
    OperacionSuma();

    virtual string Ejecute(string valor);

};

#endif