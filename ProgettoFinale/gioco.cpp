#include "gioco.h"

#define IDNEUTRALE 2

gioco::gioco(string nome, int pianetiNeutrali)
{
	dimensione = 10;
	//Inizializzazione dell'oggetto giocatore
	giocatoreReale = new giocatore(nome, 0);
	giocatoreVirtuale = new giocatore("Avversario", 1);
	giocatoreNeutrale = new giocatore("Neutrale", IDNEUTRALE);
	//=================================================
	numPianetiNeutrali = pianetiNeutrali;
	numPianetiTot = pianetiNeutrali + 2;

	campo = new pianeti**[dimensione];
	for (int i = 0; i < dimensione; i++)
	{
		campo[i] = new pianeti*[dimensione];
		for (int j = 0; j < dimensione; j++)
		{
			campo[i][j] = NULL;
		}
	}

	arrayPianeti = new pianeti*[numPianetiTot];
	//Inizializzazione dell'oggetto pianeta
	for (int i = 0; i < numPianetiTot; i++)
	{
		bool trovato = false;
		int coordinataX;
		int coordinataY;
		
		while (trovato == false)
		{
			coordinataX = rand() % dimensione;
			coordinataY = rand() % dimensione;
			string nome = "";
			nome += (char)('A' + i);
			int possessore = i < 2 ? i : IDNEUTRALE;
			if (campo[coordinataX][coordinataY] == NULL)
			{
				arrayPianeti[i] = new pianeti(nome, possessore, coordinataX, coordinataY);
				trovato = true;
			}			
		}
		campo[coordinataX][coordinataY] = arrayPianeti[i];
	}
	//=================================================

}



giocatore* gioco::getGiocatoreReale()
{
	return giocatoreReale;
}

giocatore* gioco::getGiocatoreVirtuale()
{
	return giocatoreVirtuale;
}

giocatore** gioco::getArrayGiocatori()
{
	giocatore** ptr = new giocatore*[3];
	ptr[0] = giocatoreReale;
	ptr[1] = giocatoreVirtuale;
	ptr[2] = giocatoreNeutrale;
	return ptr;
}

pianeti** gioco::getArrayPianeti()
{
	return arrayPianeti;
}

pianeti*** gioco::getCampo()
{
	return campo;
}

int gioco::getNumPianetiNeutrali()
{
	return numPianetiNeutrali;
}

int gioco::getNumPianetiTot()
{
	return numPianetiTot;
}

int gioco::getDimensione()
{
	return dimensione;
}

gioco::~gioco()
{
}
