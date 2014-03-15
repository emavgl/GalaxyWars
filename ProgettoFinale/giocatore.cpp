#include "giocatore.h"

int giocatore::totaleGiocatore = 0;

giocatore::giocatore(string _nome, int _tipo)
{
	nome = _nome;
	tipo = _tipo;
	totaleGiocatore++;
	numeroPianeti = 1;
	indiceGiocatore = totaleGiocatore;
}

string giocatore::getNome()
{
	return nome;
}

int giocatore::getTipo()
{
	return tipo;
}

int giocatore::getTotaleGiocatori()
{
	return totaleGiocatore;
}

int giocatore::getNumeroPianeti()
{
	return numeroPianeti;
}

giocatore::~giocatore()
{
}
