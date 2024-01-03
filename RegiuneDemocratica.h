#pragma once
#include "Regiune.h"
class RegiuneDemocratica : Regiune
{
	int populatie[4];
public:

	RegiuneDemocratica();
	RegiuneDemocratica(const int* populatie, const int& nrLoc);
	//void calculNrVotTotale();
	void calculareRezultat(std::ifstream& Input, std::ofstream& Output, int& varsta);
	void citire(std::ifstream& Input);
	void citireVotanti(std::ifstream& Input);
	void afisare(std::ofstream& Output);
};

