// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>
#include "TreeMap.h"
#include "List.h"
using namespace std;

typedef TreeMap<string, List<int>*> Diccionario;
void leerDiccionario(Diccionario& diccionario, const int lineas) {
	string linea;
	int j = 0;
	while (j < lineas) {
		getline(cin, linea);
		stringstream lin(linea); //procesar la línea
		string clave;
		while (lin >> clave) {
			if (clave.length() > 2) {
				for (int i = 0; clave[i]; i++) { //palabra a minuscula
					clave[i] = tolower(clave[i]);
				}
				
				if (!diccionario.contains(clave)) {
					List<int> *lista = new List<int>; //creamos un puntero a una lista nueva
					lista->push_back(j + 1); //le añadimos el valor
					diccionario.insert(clave, lista); //insertamos el par en el diccionario
				}
				else {
					if(diccionario.at(clave)->back() != j+1)diccionario.at(clave)->push_back(j + 1); //si la clave ya existia, modificamos su lista
				}
			}
		}
		j++;
	}
}

// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0)
		return false;
	Diccionario dic;
	string s;
	getline(cin, s); //basura
	leerDiccionario(dic, n);
	
	// escribir sol
	TreeMap<string, List<int>*>::Iterator it = dic.begin();
	while (it != dic.end()) {
		cout << it.key() << " ";
		for (int i = 0; i < it.value()->size(); i++ ) {
			cout << it.value()->at(i) << " ";
		}
		cout << "\n";
		it.next();
	}
	cout << "---\n";
	
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
