#include "procesadorInstrucciones.h"
#include "identificadorOperaciones.h"
#include "operacionHola.h"
#include "operacionSuma.h"

#include <iostream>
#include <string>
#include <fstream>

#include "proveedorFormato.h"
#include "proveedorFormatoDesdeStream.h"

using namespace std;

int main() {

    try {
        // Inicialización
        // Configuración de la inyección de dependencias
        map<string, Operacion *> operaciones {};

        std::ifstream ifs("formato.ini", std::ifstream::in);

        if (!ifs.is_open())
        {
            std::cerr << "Error leyendo archivo formato.ini" << std::endl;
            return -1;
        }

        ProveedorFormato *proveedorFormato = new ProveedorFormatoDesdeStream(&ifs);

        OperacionHola *operacionHola = new OperacionHola(proveedorFormato);
        operaciones.insert(std::pair<string, Operacion *>("hola", operacionHola));

        OperacionSuma *operacionSuma = new OperacionSuma(proveedorFormato);
        operaciones.insert(std::pair<string, Operacion *>("suma", operacionSuma));

        IdentificadorOperacionesBase *identificadorOperaciones = new IdentificadorOperaciones(operaciones);
        // Fin de inicialización 
        
        ProcesadorInstrucciones *procesador = new ProcesadorInstrucciones(identificadorOperaciones);
        string resultado = procesador->Procese("hola", "todos");
        
        cout << "Resultado: " << resultado << endl;

        resultado = procesador->Procese("suma", "913 + 420");
        cout << "Resultado: " << resultado << endl;
        // Cerrar archivo de entrada
        ifs.close();

    } catch (char const* exception)
    {
        cerr << "Error: " << exception << endl;
    }

    return 0;
}

