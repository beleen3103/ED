#ifndef Parcelas_h
#define Parcelas_h

#include "Plantacion.h"

const int MAX = 1000;

typedef struct {
	string idParcela;
	int fila, col, numPlat;

}tParcela;

typedef struct {
	int cont;
	tParcela *parcelas[MAX];
}tListaParcelas;

istream& operator<<(istream& in, tParcela& parcela);
bool operator<(const tParcela & parcela1, const tParcela& parcela2);


#endif
