#include <iostream>
#include <string>
#include "giocatore.h"
#include "pianeti.h"
#include <time.h>
#include "gioco.h"

using namespace std;

string inserisciGiocatore();
int inserisciPianetiNeutrali();
typedef pianeti*** mappa;
void stampaMappa(mappa, int);
void stampaRiepilogo(pianeti**, int, giocatore**);

ostream &  operator << (ostream & sx, pianeti & dx){
	return dx.put(sx);
}

int main()
{
	srand(time(NULL));
	cout << "Benvenuto nel Gioco." << endl;
	string input = "";
	gioco* nuovogioco = NULL;
	do {
		if (nuovogioco != NULL) delete nuovogioco;
		string nomeGiocatore = "ema";//inserisciGiocatore();
		int numneutrali = 3; // inserisciPianetiNeutrali();
		nuovogioco = new gioco(nomeGiocatore, numneutrali);
		mappa xmappa = nuovogioco->getCampo();
		stampaMappa(xmappa, nuovogioco->getDimensione());
		cout << "Va bene questa dispozione? 's' = si" << endl;
		cin >> input;
	} while (input[0] != 's');
	system("cls");
	stampaRiepilogo(nuovogioco->getArrayPianeti(), nuovogioco->getNumPianetiTot(), nuovogioco->getArrayGiocatori());
	system("pause");
	return 0;
}

//Funzione che chiede all'utente di inserire i giocatori
string inserisciGiocatore()
{
	cout << "Inserisci il nome del giocatore reale" << endl;
	string nome = "";
	cin >> nome;
	cout << endl;
	cout << endl;

	cout << "Il giocatore 1: " << nome << " e' stato aggiunto correttamente." << endl << endl << endl;
	cout << "=======================================================================" << endl;
	cout << endl;
	cout << "Viene generato in automatico un avversario virtuale di nome 'Avversario'" << endl;
	cout << endl;
	cout << "=======================================================================" << endl;
	cout << "=======================================================================" << endl;
	cout << "Tutti i giocatori sono stati creati!" << endl;
	cout << "=======================================================================" << endl;

	//restituisce ptr, ovvero l'array di puntatore a oggetti giocatore.
	//Non ho bisogno di passarmi la dimensione perché ho la variabile static che conta
	return nome;
}

//Funzione che chiede all'utente il numero di pianeti e li iniziliazza
int inserisciPianetiNeutrali()
{
	cout << "Prima di tutto, devo chiederti di inserire il numero di pianeti neutrali" << endl;
	int neutrali;
	do {
		cout << "Il massimo di pianeti neutrali che puoi inserire e': 4" << endl;
		cin >> neutrali;
		cout << endl;
		
	} while (neutrali > 4);
	return neutrali;
}

void stampaMappa(mappa campo, int dimensione)
{

	for (int i = 0; i < dimensione; i++)
	{
		for (int j = 0; j < dimensione; j++)
		{
			pianeti* ptr = campo[i][j];
			if (ptr != NULL)
			{
				string notazione = "";
				notazione += ptr->getNome() + to_string(ptr->getPossessore());
				cout << "[" << notazione << "] ";
			}
			else
				cout << "[  ] ";
		}
		cout << endl;;
	}
}

void stampaRiepilogo(pianeti** ptr, int tot, giocatore** arrayGiocatori)
{
	cout << "===============================" << endl;
	cout << "Riepilogo del gioco" << endl;
	cout << "===============================" << endl;
	for (int i = 0; i < tot; i++)
	{
		pianeti* p = ptr[i];
		cout << *p << " :: " << (arrayGiocatori[p->getPossessore()])->getNome() << endl;
	}
}  