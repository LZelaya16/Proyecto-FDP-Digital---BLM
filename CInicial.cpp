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
    cout << "\n--- TIENDA DE VIDEOJUEGOS DIGITAL BLM ---\n";
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
    cout << "\n--- CATALOGO DE VIDEOJUEGOS ---\n";
    cout << left << setw(5) << "ID" << setw(30) << "Juego"
         << setw(12) << "Precio" << setw(10) << "Stock" << endl;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        cout << left << setw(5) << (i + 1) << setw(30) << juegos[i]
             << "$" << setw(11) << fixed << setprecision(2) << precios[i]
             << setw(10) << stock[i] << endl;
    }
}

void agregarAlCarrito() {
    char otro;

    do {
        int id, cantidad;

        verCatalogo();
        cout << "\nIngrese el ID del juego: ";
        cin >> id;
        cout << "Ingrese la cantidad de copias: ";
        cin >> cantidad;

        if (id < 1 || id > MAX_JUEGOS) {
            cout << "\nError: Opcion no valida.\n";
        } else {
            int indice = id - 1;

            if (cantidad <= 0 || cantidad > stock[indice]) {
                cout << "\nError: juego sin stock.\n";
            } else {
                carrito[indice] = carrito[indice] + cantidad;
                stock[indice] = stock[indice] - cantidad;
                cout << "\nSe agrego " << cantidad << " unidad(es) de "
                     << juegos[indice] << " al carrito.\n";
            }
        }

        cout << "\nDesea agregar otro juego? (s/n): ";
        cin >> otro;

    } while (otro == 's' || otro == 'S');
}

void calcularTotal() {
    total = 0;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        subtotal = carrito[i] * precios[i];
        total = total + subtotal;
    }

    cout << "\nTotal de la compra: $" << fixed << setprecision(2) << total << endl;
}

void modificarCarrito() {
    int id, nuevaCantidad;

    cout << "\n--- CARRITO ACTUAL ---\n";
    for (int i = 0; i < MAX_JUEGOS; i++) {
        if (carrito[i] > 0) {
            cout << (i + 1) << ". " << juegos[i] << " - Cantidad: " << carrito[i] << endl;
        }
    }

    cout << "\nIngrese el ID del juego que desea modificar: ";
    cin >> id;

    if (id < 1 || id > MAX_JUEGOS) {
        cout << "\nError: Opcion no valida.\n";
        return;
    }

    int indice = id - 1;
    int disponible = stock[indice] + carrito[indice];

    cout << "Ingrese la nueva cantidad de copias: ";
    cin >> nuevaCantidad;

    if (nuevaCantidad < 0 || nuevaCantidad > disponible) {
        cout << "\nError: juego sin stock.\n";
    } else {
        stock[indice] = disponible - nuevaCantidad;
        carrito[indice] = nuevaCantidad;
        cout << "\nCarrito y stock actualizados correctamente.\n";
    }
}

void vaciarCarrito() {
    char confirmacion;

    cout << "\nConfirma cancelar la compra? (s/n): ";
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        for (int i = 0; i < MAX_JUEGOS; i++) {
            stock[i] = stock[i] + carrito[i];
            carrito[i] = 0;
        }
        cout << "\nEl carrito ha sido vaciado.\n";
    } else {
        cout << "\nOperacion cancelada. El carrito sigue igual.\n";
    }
}

return 0;
