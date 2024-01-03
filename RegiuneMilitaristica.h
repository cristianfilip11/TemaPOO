#pragma once
#include "Regiune.h"
class RegiuneMilitaristica : public Regiune
{
	int populatie[10];
	float nrVotTotale;
public:
	RegiuneMilitaristica();
	RegiuneMilitaristica(const int* populatie,const float& nrVotTotale, const int& nrLoc);
	void calculNrVotTotale();
	void calculareRezultat(std::ifstream& Input, std::ofstream& Output);
	void citire(std::ifstream& Input);
	void citireVotanti(std::ifstream& Input);
	void afisare(std::ofstream& Output);
};

