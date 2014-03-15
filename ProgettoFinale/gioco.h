#pragma once
#include <string>
#include "pianeti.h"
#include "giocatore.h"
using namespace std;

class gioco
{
private:
	giocatore* giocatoreReale;
	giocatore* giocatoreVirtuale;
	giocatore* giocatoreNeutrale;
	pianeti* *arrayPianeti;
	int numPianetiNeutrali;
	int numPianetiTot;
	int dimensione;
	pianeti* **campo;
public:
	gioco(string, int);
	giocatore* getGiocatoreReale();
	giocatore* getGiocatoreVirtuale();
	giocatore* *getArrayGiocatori();
	pianeti* *getArrayPianeti();
	pianeti*** getCampo();
	int getDimensione();
	int getNumPianetiTot();
	int getNumPianetiNeutrali();
	~gioco();
};

