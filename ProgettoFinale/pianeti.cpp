#include "pianeti.h"


pianeti::pianeti(string _nome, int _possessore, int x, int y)
{
	nome = _nome;
	possessore = _possessore;
	coordinataX = x;
	coordinataY = y;
}

int pianeti::getcooX()
{
	return coordinataX;
}

int pianeti::getcooY()
{
	return coordinataY;
}

pianeti::~pianeti()
{
}

string pianeti::getNome()
{
	return nome;
}

int pianeti::getPossessore()
{
	return possessore;
}

ostream& pianeti::put(ostream& os)
{
	os << "Pianeta: " << nome << "  Possessore: " << possessore;
	return os;
}
