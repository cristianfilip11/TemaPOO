#include "RegiuneDemocratica.h"
RegiuneDemocratica::RegiuneDemocratica() : Regiune(){
	populatie[0] = 0;
	populatie[1] = 0;
	populatie[2] = 0;
	populatie[3] = 0;
}
RegiuneDemocratica::RegiuneDemocratica(const int* populatie, const int& nrLoc) : Regiune(nrLoc) {
	this->populatie[0] = populatie[0];
	this->populatie[1] = populatie[1];
	this->populatie[2] = populatie[2];
	this->populatie[3] = populatie[3];
}
void RegiuneDemocratica::citire(std::ifstream& Input) {
	char buffer[256];
	Input >> buffer;
	this->nrLoc = std::stoi(buffer);
	for (int i = 0; i < 4; i++) {
		Input >> buffer;
		this->populatie[i] = std::stoi(buffer);
	}
	//this->calculNrVotTotale();
	//std::cout << this->nrVotTotale << '\n';
}
void RegiuneDemocratica::citireVotanti(std::ifstream& Input) {
	char buffer[256];
	for (int i = 0; i < 4; i++) {
		Input >> buffer;
		this->populatie[i] = std::stoi(buffer);
	}
}
void RegiuneDemocratica::afisare(std::ofstream& Output) {
	std::cout << "Zona 3" << '\n';
	std::cout << this->nrLoc<<'\n';
	for (int i = 0; i < 4; i++) {
		std::cout << this->populatie[i] << " ";
	}
	std::cout << '\n';
}
//void calculNrVotTotale();
void RegiuneDemocratica::calculareRezultat(std::ifstream& Input, std::ofstream& Output, int& varsta) {
	char buffer[256];
	//RegiuneDemocratica votanti_poz; nu mai am nevoie de obiecte 
	//RegiuneDemocratica votanti_neg; separate, pot sa iau direct 2 var
	int voturiPozitive;
	int voturiNegative;
	Input >> buffer;

	if (strcmp(buffer, "Da") == 0) {

		// votanti_poz.citireVotanti(Input);
		Input >> buffer;
		voturiPozitive = std::stoi(buffer);
		Input >> buffer; // sa scap de nu
		Input >> buffer; // sa iau nr 
		voturiNegative = std::stoi(buffer);
	}
	else {
		Input >> buffer;
		voturiNegative = std::stoi(buffer);
		Input >> buffer; // sa scap de da
		Input >> buffer; // sa iau nr 
		voturiPozitive = std::stoi(buffer);
	}


	if (voturiPozitive > voturiNegative) {
		Output << "Acceptat " << voturiPozitive << "-" << voturiNegative << '\n';
	}
	else if (voturiPozitive == voturiNegative) {
		Output << "Egalitate " << voturiPozitive << "-" << voturiNegative << '\n';
	}
	else {
		Output << "Respins " << voturiPozitive << "-" << voturiNegative << '\n';
	}
	float nrVotantiEligibili;
	if (varsta == 0) {
		nrVotantiEligibili = this->nrLoc - 1;
	}
	else if (varsta == 14) {
		nrVotantiEligibili = this->nrLoc - 1 - populatie[0];
	}
	else if (varsta == 20) {
		nrVotantiEligibili = this->nrLoc - 1 - populatie[0] - populatie[1];
	}
	else if (varsta >= 40) {
		nrVotantiEligibili = this->populatie[3] - 1;
	}
	float prezenta;
	prezenta = (voturiNegative + voturiPozitive) / nrVotantiEligibili * 100;
	Output << "Prezenta vot: " << prezenta << "%" << '\n';
}
