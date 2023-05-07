#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Palabra {
    string palabra;
    string traduccion;
    string funcionalidad;
};

void agregarPalabra(vector<Palabra>& palabras) {
    Palabra p;
    cout << "-> Ingrese Palabra: ";
    getline(cin, p.palabra);
    cout << "-> Ingrese Traduccion: ";
    getline(cin, p.traduccion);
    cout << "-> Ingrese Funcionalidad: ";
    getline(cin, p.funcionalidad);
    palabras.push_back(p);
}

void mostrarPalabras(const vector<Palabra>& palabras) {
    for (const auto& p : palabras) {
        cout << "-> Palabra: " << p.palabra << '\n';
        cout << "-> Traduccion: " << p.traduccion << '\n';
        cout << "-> Funcionalidad: " << p.funcionalidad << "\n\n";
    }
}

void actualizarPalabra(vector<Palabra>& palabras) {
    string palabra;
    cout << "-> Ingrese la palabra que desea actualizar: ";
    getline(cin, palabra);
    for (auto& p : palabras) {
        if (p.palabra == palabra) {
            cout << "-> Ingrese nueva traduccion: ";
            getline(cin, p.traduccion);
            cout << "-> ngrese nueva funcionalidad: ";
            getline(cin, p.funcionalidad);
            return;
        }
    }
}

void borrarPalabra(vector<Palabra>& palabras) {
    string palabra;
    cout << "-> Ingrese la palabra que desea borrar: ";
    getline(cin, palabra);
    for (auto it = palabras.begin(); it != palabras.end(); ++it) {
        if (it->palabra == palabra) {
            palabras.erase(it);
            return;
        }
    }
}

void guardarPalabras(const vector<Palabra>& palabras) {
    ofstream archivo("traducciones.dat");
    for (const auto& p : palabras) {
        archivo << p.palabra << '\n';
        archivo << p.traduccion << '\n';
        archivo << p.funcionalidad << '\n';
    }
}

void cargarPalabras(vector<Palabra>& palabras) {
    Palabra p;
    ifstream archivo("traducciones.dat");
    while (getline(archivo, p.palabra)) {
        getline(archivo, p.traduccion);
        getline(archivo, p.funcionalidad);
        palabras.push_back(p);
    }
}

int main() {
    vector<Palabra> palabras;
    cargarPalabras(palabras);
    
    int opcion = 0;
    while (opcion != 6) {
        cout << "1. Agregar palabra\n";
        cout << "2. Mostrar palabras\n";
        cout << "3. Actualizar palabra\n";
        cout << "4. Borrar palabra\n";
        cout << "5. Guardar cambios\n";
        cout << "6. Salir\n";
        cout << "-> Ingrese opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                agregarPalabra(palabras);
                break;
            case 2:
                mostrarPalabras(palabras);
                break;
            case 3:
                actualizarPalabra(palabras);
                break;
            case 4:
                borrarPalabra(palabras);
                break;
            case 5:
                guardarPalabras(palabras);
                break;
            case 6:
                break;
            default:
                cerr << "Opcion invalida! Ingrese otro numero.\n";
                break;
        }
    }
}
