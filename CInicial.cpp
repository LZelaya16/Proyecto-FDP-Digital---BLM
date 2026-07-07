#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_JUEGOS = 10;

string juegos[MAX_JUEGOS] = {
    "GTA 6",
    "Minecraft",
    "Batman Arkham Origins",
    "Human Fall Flat",
    "Ready or Not",
    "Forza Horizon 6",
    "Peak",
    "Mortal Kombat XL",
    "Dragon Ball X",
    "Doom"
};

double precios[MAX_JUEGOS] = {69.99, 29.99, 19.99, 14.99, 39.99, 59.99, 24.99, 34.99, 44.99, 49.99};
int stock[MAX_JUEGOS] = {10, 20, 8, 15, 12, 9, 18, 11, 7, 14};
int carrito[MAX_JUEGOS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

double subtotal = 0;
double total = 0;

void mostrarMenu() {
    cout << "\n===== TIENDA DE VIDEOJUEGOS DIGITAL BLM =====\n";
    cout << "1. Ver catalogo\n";
    cout << "2. Agregar al carrito\n";
    cout << "3. Calcular total\n";
    cout << "4. Modificar carrito\n";
    cout << "5. Vaciar carrito\n";
    cout << "6. Confirmar compra\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}

void verCatalogo() {
    cout << "\n===== CATALOGO DE VIDEOJUEGOS =====\n";
    cout << left << setw(5) << "ID" << setw(30) << "Juego"
         << setw(12) << "Precio" << setw(10) << "Stock" << endl;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        cout << left << setw(5) << (i + 1) << setw(30) << juegos[i]
             << "$" << setw(11) << fixed << setprecision(2) << precios[i]
             << setw(10) << stock[i] << endl;
    }
}