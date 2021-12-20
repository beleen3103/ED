// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "IPud.h"
using namespace std;


// función que resuelve el problema
void play(IPud& ipud) {
	if (ipud.totalTime() == 0) cout << "No hay canciones en la lista\n";
	else {
		cout << "Sonando " << ipud.current() << "\n";
		ipud.play();
	}
}
void totalTime(IPud ipud) {
	cout << "Tiempo total " << ipud.totalTime() << "\n";
}
void recent(IPud ipud, int n) {
	cout << "Las " << n << " mas recientes\n";
	List<string> aux = ipud.recent(n);
	if (aux.empty()) cout << "No hay canciones recientes\n";
	else {
		for (int i = 0; i < n; i++) {
			cout << "    " << aux.at(i) << "\n";
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	string caso, artista, cancion;
	cin >> caso;
	if (!std::cin)
		return false;
	IPud ipud;
	int dur;	
	try {
		while (caso != "FIN") {
			if (caso == "addSong") {
				cin >> cancion >> artista >> dur;
				ipud.addSong(cancion, artista, dur);
			}
			else if (caso == "addToPlaylist") {
				cin >> cancion;
				ipud.addToPlaylist(cancion);
			}
			else if (caso == "play") {
				play(ipud);
			}
			else if (caso == "totalTime") {
				totalTime(ipud);
			}
			else if (caso == "deleteSong") {
				cin >> cancion;
				ipud.deleteSong(cancion);
			}
			else if(caso == "recent") {
				int n;
				cin >> n;
				recent(ipud, n);
			}
			else if (caso == "current") {
				ipud.current();
			}
			cin >> caso;
		}
	cout << "---\n";
	}
	catch (exception e) {
		cout << "ERROR: " << e.what() << "\n";
	}
	

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