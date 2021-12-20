#ifndef _GESTOR_FUTBOLISTAS_H_
#define _GESTOR_FUTBOLISTAS_H_

#include <stdexcept>
#include <string>
#include "HashMap.h"
#include "List.h"

using namespace std;

class Gestor {
public:
	void fichar(const string& j,const string& team) {
		auto it = jugadores.find(j);
		if (!equipos.contains(team)) {
			List<string> nueva;
			equipos.insert(team, InfoEquipo(nueva));
		}
		if (it == jugadores.end()) {
			equipos.find(team).value().js.push_front(j);
			equipos.find(team).value().ultimosFichajes.push_front(j);
			
			jugadores.insert(j, InfoJugador(1, team, equipos.find(team).value().js.begin()));
		}
		if (jugadores.find(j).value().equipo != team) {
			string anterior = jugadores.find(j).value().equipo;
			equipos.find(anterior).value().js.erase(jugadores.find(j).value().it); //elimina al jugador del anterior equipo
			equipos.find(team).value().js.push_front(j); //lo añadimos al nuevo equipo
			it.value().it = equipos.find(team).value().js.begin(); //cambiamos su puntero
			equipos.find(team).value().ultimosFichajes.push_front(j); //ultimos fichajes

			//le asignamos otro equipo
			jugadores.find(j).value().numEquipos++;
			jugadores.find(j).value().equipo = team;
			
		}

	}
	string equipo_actual(const string& j) {
		auto it = jugadores.find(j);
		if (it == jugadores.end()) { throw std::domain_error("Jugador inexistente"); }
		return it.value().equipo;
	}
	int fichados(const string& team) {
		if (!equipos.contains(team)) { throw std::domain_error("Equipo inexistente"); }
		return equipos.find(team).value().js.size();
	}
	List<string> ultimos_fichajes(const string& team, int n) {
		if(!equipos.contains(team)){ throw std::domain_error("Equipo inexistente"); }
		int i = 0;
		List<string> res;
		while (n > 0 && i < equipos.find(team).value().ultimosFichajes.size()) {
			if (equipo_actual(equipos.find(team).value().ultimosFichajes.at(i)) == team) { //el jugador sigue en el equipo
				res.push_back(equipos.find(team).value().ultimosFichajes.at(i));
				n--;
			}
			i++;
		}
		return res;
	}
	int cuantos_equipos(const string& j) {
		auto it = jugadores.find(j);
		if (it == jugadores.end()) return 0;
		else return it.value().numEquipos;
	}

private:

	class InfoEquipo {
	public:
		InfoEquipo(const List<string>& _js) : js(_js) {}
		List<string> js;
		List<string> ultimosFichajes;
	};
	HashMap<string, InfoEquipo> equipos;

	class InfoJugador {
	public:
		InfoJugador(const int& _numEquipos, const string& _equipo, const List<string>::Iterator& _it) : numEquipos(_numEquipos), equipo(_equipo), it(_it) {}

		int numEquipos;
		string equipo;
		List<string>::Iterator it;
	};

	HashMap<string, InfoJugador> jugadores;
};


#endif
