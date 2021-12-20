// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"Gestor_Futbolistas.h"

using namespace std;


// función que resuelve el problema
void ultimos_fichajes(Gestor g, string team, int n) {
	List<string> aux = g.ultimos_fichajes(team, n);
	cout << "Ultimos fichajes de " << team << ":";
	for (int i = 0; i < aux.size(); i++) {
		cout << " " << aux.at(i);
	}
	cout << "\n";
}
void cuantos_equipos(Gestor g, string j) {
	int n = g.cuantos_equipos(j);
	cout << "Equipos que han fichado a " << j << ": " << n << "\n";
}
void equipo_actual(Gestor g, string j) {
	string team = g.equipo_actual(j);
	cout << "El equipo de " << j << " es " << team << "\n";
}
void fichados(Gestor g, string team) {
	int n = g.fichados(team);
	cout << "Jugadores fichados por " << team << ": " << n << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string caso,j,team;
	Gestor gestor;
	int n;
	cin >> caso;
	if (!std::cin)
		return false;
	
	while (caso != "FIN") {
		try {
			if (caso == "fichar") {
				cin >> j >> team;
				gestor.fichar(j, team);
			}
			else if (caso == "ultimos_fichajes") {
				cin >> team >> n;
				ultimos_fichajes(gestor, team, n);
			}
			else if (caso == "cuantos_equipos") {
				cin >> j;
				cuantos_equipos(gestor, j);
			}
			else if (caso == "equipo_actual") {
				cin >> j;
				equipo_actual(gestor, j);
			}
			else if (caso == "fichados") {
				cin >> team;
				fichados(gestor, team);
			}
		}
		catch (exception e) {
			cout << "ERROR: " << e.what() << "\n";
		}
		cin >> caso;
	}

	// escribir sol

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