// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Carnet_puntos.h"
using namespace std;


void consultar(Carnet c, const string& dni) {
	cout << "Puntos de " << dni << ": " << c.consultar(dni) << "\n";
}
void cuantos_con_puntos(Carnet c, const unsigned int& puntos) {
	cout << "Con " << puntos << " puntos hay " << c.cuantos_con_puntos(puntos) << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string caso, dni;
	Carnet c;
	int puntos;
	cin >> caso;
	if (!std::cin)
		return false;
	try {
		while (caso != "FIN") {
			if (caso == "nuevo") {
				cin >> dni;
				c.nuevo(dni);
			}
			else if (caso == "cuantos_con_puntos") {
				cin >> puntos;
				cuantos_con_puntos(c, puntos);
			}
			else if (caso == "quitar") {
				cin >> dni >> puntos;
				c.quitar(dni, puntos);
			}
			else if (caso == "consultar") {
				cin >> dni;
				consultar(c, dni);
			}
			cin >> caso;
		}
	}
	catch (exception e) {
		cout <<"ERROR: " <<  e.what() << "\n";
	}
	if (caso == "FIN") cout << "---\n";
	// escribir sol

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
