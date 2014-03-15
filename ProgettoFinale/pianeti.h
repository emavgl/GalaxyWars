#pragma once
#include <string>
#include <iostream>

using namespace std;

class pianeti
{
private:
	string nome;
	int possessore;
	int coordinataX;
	int coordinataY;
public:
	pianeti(string, int, int, int);
	string getNome();
	int getcooX();
	int getcooY();
	int getPossessore();
	void setNome();
	virtual ostream& put(ostream&);
	~pianeti();
};

