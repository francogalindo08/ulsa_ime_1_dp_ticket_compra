#pragma once

// =====================================================
// NO MODIFICAR ESTE ARCHIVO
// Contiene funciones de apoyo para la practica.
// =====================================================

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <stdexcept>

// Muestra el mensaje y lee una linea completa.
// Repite la pregunta hasta que el usuario escriba un entero valido.
// Rechaza texto, decimales ("3.5") y entradas mixtas ("12abc").
//
// Recibe: el mensaje que se muestra al usuario.
// Devuelve: el numero entero que escribio el usuario.
inline int leerEntero(const std::string& mensaje) {
    std::string linea;
    while (true) {
        std::cout << mensaje;
        if (!std::getline(std::cin, linea)) {
            std::cout << "\nNo hay mas entrada. Fin del programa.\n";
            std::exit(1);
        }
        try {
            std::size_t pos = 0;
            int valor = std::stoi(linea, &pos);
            while (pos < linea.size() &&
                   std::isspace(static_cast<unsigned char>(linea[pos]))) {
                pos++;
            }
            if (pos == linea.size()) {
                return valor;
            }
        } catch (const std::exception&) {
            // Texto no numerico o numero fuera de rango: se vuelve a pedir
        }
        std::cout << "Entrada no valida. Escribe un numero entero.\n";
    }
}

// Muestra el mensaje y lee una linea completa.
// Repite la pregunta hasta que el usuario escriba un numero valido.
// Acepta enteros ("5") y decimales ("2.5").
// Rechaza texto, entradas mixtas ("12abc"), "nan" e "inf".
// OJO: solo revisa que sea un numero, NO que tenga sentido
// para tu problema (por ejemplo, que sea mayor que 0).
//
// Recibe: el mensaje que se muestra al usuario.
// Devuelve: el numero que escribio el usuario, como double.
inline void imprimirLinea(int largo, char simbolo) {
    for (int i = 0; i < largo; i++) {
        std::cout << simbolo;
    }
    std::cout << std::endl;
}
inline double leerDecimal(const std::string& mensaje) {
    std::string linea;
    while (true) {
        std::cout << mensaje;
        if (!std::getline(std::cin, linea)) {
            std::cout << "\nNo hay mas entrada. Fin del programa.\n";
            std::exit(1);
        }
        try {
            std::size_t pos = 0;
            double valor = std::stod(linea, &pos);
            while (pos < linea.size() &&
                   std::isspace(static_cast<unsigned char>(linea[pos]))) {
                pos++;
            }
            if (pos == linea.size() && std::isfinite(valor)) {
                return valor;
            }
        } catch (const std::exception&) {
            // Texto no numerico o numero fuera de rango: se vuelve a pedir
        }
        std::cout << "Entrada no valida. Escribe un numero (ej. 5 o 2.5).\n";
    }
}

// Muestra el mensaje y lee una linea completa de texto.
// Repite la pregunta hasta que el usuario escriba al menos un caracter
// que no sea espacio. Acepta espacios en medio ("Ana Maria").
// Quita los espacios del inicio y del final.
// OJO: solo revisa que el texto no este vacio, NO que tenga sentido
// para tu problema.
//
// Recibe: el mensaje que se muestra al usuario.
// Devuelve: el texto que escribio el usuario.
inline std::string leerCadena(const std::string& mensaje) {
    std::string linea;
    while (true) {
        std::cout << mensaje;
        if (!std::getline(std::cin, linea)) {
            std::cout << "\nNo hay mas entrada. Fin del programa.\n";
            std::exit(1);
        }
        std::size_t inicio = 0;
        while (inicio < linea.size() &&
               std::isspace(static_cast<unsigned char>(linea[inicio]))) {
            inicio++;
        }
        std::size_t fin = linea.size();
        while (fin > inicio &&
               std::isspace(static_cast<unsigned char>(linea[fin - 1]))) {
            fin--;
        }
        if (fin > inicio) {
            return linea.substr(inicio, fin - inicio);
        }
        std::cout << "Entrada no valida. Escribe al menos un caracter.\n";
    }
    
}
