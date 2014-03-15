#pragma once
#include <string>
#include <iostream>

using namespace std;

class giocatore
{
protected:
	static int totaleGiocatore;
private:
	string nome;
	int tipo;
	int numeroPianeti;
	int indiceGiocatore;
public:
	giocatore(string, int);
	string getNome();
	int getTipo();
	int getNumeroPianeti();
	static int getTotaleGiocatori();
	~giocatore();
};

