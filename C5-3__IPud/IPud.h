#ifndef _IPUD_H_
#define _IPUD_H_

#include <string>
#include <stdexcept>
#include "HashMap.h"
#include "List.h"
using namespace std;

typedef struct {
	int durTotal = 0;
	List<string> lista;
}lista_rep;

class IPud {
public:
	void addSong(const string& s, const string& a, const int& d) {
		if(canciones.contains(s)) {throw std::domain_error("addSong");}		
		canciones.insert(s, InfoCancion(a, d));
	}

	void addToPlaylist(string s) {
		if (!canciones.contains(s)) { throw std::domain_error("addtoPlaylist"); }
		
		l.lista.push_front(s);
		canciones.find(s).value().it = l.lista.begin();
		l.durTotal += canciones.find(s).value().dur;
		

	}
	string current() {
		if (l.lista.empty()) { throw std::domain_error("current"); }
		return l.lista.back();
	}
	void play() {
		if (!l.lista.empty()) { 
			if (!canciones.contains(l.lista.back())) {//si hemos eliminado la cancion anteriormente ya no puede sonar
				l.durTotal -= canciones.find(l.lista.back()).value().dur;
				l.lista.pop_back();
			}
			if (!l.lista.empty()) {
				recents.push_front(l.lista.back());
				l.durTotal -= canciones.find(l.lista.back()).value().dur;
				l.lista.pop_back();
			}
		}

	}
	int totalTime() {
		return l.durTotal;
	}
	List<string> recent(int n) {
		List<string> aux;
		
		int i = 0;
		while (i < n && i < recents.size()) {
			aux.push_back(recents.at(i));
			i++;
		}
		return aux;
	}
	void deleteSong(string s) {
		if (canciones.contains(s)) {
			//if(canciones.find(s).value().it != l.lista.end()) l.lista.erase(canciones.find(s).value().it);
			canciones.erase(s);
		}
	}

	

private:

	class InfoCancion {
	public:
		InfoCancion(const string& artista, const unsigned int& duracion) : 
			art(artista), dur(duracion) {}

		List<string>::Iterator it;
		string art;
		int dur;
	};

	lista_rep l;
	List<string> recents;
	HashMap<string, InfoCancion> canciones;
};

#endif
