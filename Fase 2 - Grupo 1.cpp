#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Palabra {
    string palabra;
    string traduccion;
    string funcionalidad;
};

unordered_map<string, string> cargarTraducciones() {
    unordered_map<string, string> traducciones;
    Palabra p;
    ifstream archivo("traducciones.dat");
    while (getline(archivo, p.palabra)) {
        getline(archivo, p.traduccion);
        getline(archivo, p.funcionalidad);
        traducciones[p.palabra] = p.traduccion;
    }
    return traducciones;
}

string traducir(const string& texto, const unordered_map<string, string>& traducciones) {
    istringstream iss(texto);
    ostringstream oss;
    string palabra;
    bool enControl = false;
    while (iss >> palabra) {
        if (palabra == "if") {
            oss << "si";
            enControl = true;
        } else if (palabra == "else") {
            oss << "entonces";
            enControl = true;
        } else if (palabra == "{") {
            if (enControl) {
                oss << " inicio";
                enControl = false;
            }
            oss << " {";
        } else if (palabra == "}") {
            oss << " fin";
        } else if (traducciones.count(palabra)) {
            oss << " " << traducciones.at(palabra);
        } else {
            oss << " " << palabra;
        }
    }
    return oss.str();
}

int main() {
    auto traducciones = cargarTraducciones();
    
    cout << "Ingrese el texto a traducir:\n";
    
    string linea;
    string texto;
    while (getline(cin, linea)) {
        if (linea.empty()) break;
        texto += linea + "\n";
    }
    
    cout << "\nTexto traducido:\n\n";
    
    cout << traducir(texto, traducciones) << "\n";
    
    return 0;
}
