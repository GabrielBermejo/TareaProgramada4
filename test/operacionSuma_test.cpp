#include <gtest/gtest.h>
#include <string>
#include "./../src/operacionSuma.h"
#include "proveedorFormatoPrueba.h"

using namespace std;

namespace {
    TEST(OperacionSuma_Test, Test_String_Resultado) {

        ProveedorFormatoPrueba *proveedorFormato = new ProveedorFormatoPrueba();
        OperacionSuma *operacionSuma = new OperacionSuma(proveedorFormato);

        string actual = operacionSuma->Ejecute("913 + 420");
        string esperado = "1333";

        EXPECT_EQ(esperado, actual);
    }
}