#include "Parcelas.h"

bool operator<(const tParcela & parcela1, const tParcela& parcela2) {
	return parcela1.numPlat < parcela2.numPlat;
}