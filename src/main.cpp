// Práctica: Ticket de compra
// main() solo coordina: pide los datos, llama a los módulos y muestra el ticket.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
// Ejecutar:
//   macOS:   ./ticket
//   Windows: .\ticket.exe

// ¿Recuerdas qué hace iostream?
#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"


int main() {
    // Paso 1: variables
    int cantidad = 0;
    double precio = 0.0;
    double subtotal = 0.0;
    double porcentaje = 0.0;
    double descuento = 0.0;
    double impuesto = 0.0;
    double total = 0.0;
    std::string producto = "";
    const double IVA = 0.16;

    // Paso 2: mensaje de bienvenida
    std::cout << "Bienvenido a la tienda\n";

    // Paso 3: pedir y validar los datos
    std::cout << "Ingresar Producto\n";
    producto = leerCadena("Escribe el producto: ");

    do {
        std::cout << "Ingresar Cantidad de Productos adquiridos\n";
        cantidad = leerEntero("Escribe cantidad adquirida: ");

        if (cantidad <= 0) {
            std::cout << "La cantidad debe ser mayor que cero. Intenta de nuevo.\n";
        }
    } while (cantidad <= 0);

    do {
        std::cout << "Ingresar Precio Unitario\n";
        precio = leerDecimal("Escribe el precio: ");

        if (precio <= 0.0) {
            std::cout << "El precio debe ser mayor que cero. Intenta de nuevo.\n";
        }
    } while (precio <= 0.0);

    do {
    std::cout << "Ingresar descuento aplicado\n";
    porcentaje = leerDecimal("Escribe el descuento: ");

    if (porcentaje < 0.00 || porcentaje > 100.00) {
        std::cout << "El descuento debe estar entre 0 y 100. Intenta de nuevo.\n";
    }

} while (porcentaje < 0 || porcentaje > 100);

    // Paso 4: calcular los importes
 
// Paso 4: calcular los importes
subtotal = calcularSubtotal(precio, cantidad);

// Calcular descuento
descuento = calcularDescuento(subtotal, porcentaje);

// Calcular IVA después del descuento
impuesto = (subtotal - descuento) * IVA;

// Calcular total
total = (subtotal - descuento) + impuesto;

    // Paso 5: imprimir el ticket
    std::cout << "\n--- Ticket de compra ---\n";

    std::cout << "Producto: " << producto << "\n";
    std::cout << std::string(20, '=') << "\n";

    std::cout << "Cantidad: " << cantidad << "\n";
    std::cout << std::string(20, '=') << "\n";

    std::cout << "Precio unitario: " << precio << "\n";
    std::cout << std::string(20, '=') << "\n";

    std::cout << "Subtotal: " << subtotal << "\n";
    std::cout << std::string(20, '=') << "\n";

    std::cout << "Descuento: " << descuento << "\n";
    std::cout << std::string(20, '=') << "\n";

    std::cout << "IVA: " << impuesto << "\n";
    std::cout << std::string(20, '=') << "\n";

    std::cout << "Total: " << total << "\n";

    // Finalizar programa
    return 0;
}


