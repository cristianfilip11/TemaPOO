#pragma once
#include "Regiune.h"
class RegiuneReligioasa : public Regiune
{ 
	int populatie[5];
public:
	RegiuneReligioasa();
	RegiuneReligioasa(const int* populatie, const float& nrLoc);
	void calculNrLocuitori();
	void calculareRezultat(std::ifstream& Input, std::ofstream& Output);
	void citireVotanti(std::ifstream& Input);
	void citire(std::ifstream& Input);
	void afisare(std::ofstream& Output);
};

