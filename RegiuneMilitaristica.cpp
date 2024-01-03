#include "RegiuneMilitaristica.h"
#include <string>
RegiuneMilitaristica::RegiuneMilitaristica() : Regiune() {
	populatie[0] = 0;
	populatie[1] = 0;
	populatie[2] = 0;
	populatie[3] = 0;
	populatie[4] = 0;
	populatie[5] = 0;
	populatie[6] = 0;
	populatie[7] = 0;
	populatie[8] = 0;
	populatie[9] = 0;
	nrVotTotale = 0;
}
RegiuneMilitaristica::RegiuneMilitaristica(const int* populatie, const float& nrVotTotale, const int& nrLoc) : Regiune(nrLoc) {
	if (populatie != nullptr) {
		this->populatie[0] = populatie[0];
		this->populatie[1] = populatie[1];
		this->populatie[2] = populatie[2];
		this->populatie[3] = populatie[3];
		this->populatie[4] = populatie[4];
		this->populatie[5] = populatie[5];
		this->populatie[6] = populatie[6];
		this->populatie[7] = populatie[7];
		this->populatie[8] = populatie[8];
		this->populatie[9] = populatie[9];
		
	}
	this->nrVotTotale = nrVotTotale;
}

void RegiuneMilitaristica::calculareRezultat(std::ifstream& Input, std::ofstream& Output) {
	RegiuneMilitaristica votanti_poz;
	RegiuneMilitaristica votanti_neg;
	char buffer[256];
	Input >> buffer;
	if (strcmp(buffer, "Da") == 0) {
		votanti_poz.citireVotanti(Input);
		Input >> buffer; // sa scap de nu
		votanti_neg.citireVotanti(Input);
	}
	else {
		votanti_neg.citireVotanti(Input);
		Input >> buffer;
		votanti_poz.citireVotanti(Input);
	}

	float voturiPozitive = 0;
	float voturiNegative = 0;
	for (int i = 0; i < 6; i++) {
		voturiPozitive = voturiPozitive + votanti_poz.populatie[i] * (10 - i);
		voturiNegative = voturiNegative + votanti_neg.populatie[i] * (10 - i);
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
	float prezenta;
	prezenta = (votanti_poz.nrVotTotale + votanti_neg.nrVotTotale) / (this->nrVotTotale - 1);
	Output << "Prezenta vot: " << prezenta * 100 << "%" << '\n';
}
void RegiuneMilitaristica::citire(std::ifstream& Input) {
	char buffer[256];
	Input >> buffer;
	this->nrLoc = std::stoi(buffer);
	for (int i = 0; i < 10; i++) {
		Input >> buffer;
		this->populatie[i] = std::stoi(buffer);
	}
	this->calculNrVotTotale();
}

void RegiuneMilitaristica::citireVotanti(std::ifstream& Input) {
	char buffer[256];
	for (int i = 0; i < 5; i++) { // 5 doar
		Input >> buffer;
		this->populatie[i] = std::stoi(buffer);
	}
	this->calculNrVotTotale();
}

void RegiuneMilitaristica::calculNrVotTotale() {
	for (int i = 0; i < 5; i++) {
		this->nrVotTotale = this->nrVotTotale + this->populatie[i] * (10 - i);
	}
}
void RegiuneMilitaristica::afisare(std::ofstream& Output) {
	std::cout << "Zona 2" << '\n';
	std::cout << this->nrVotTotale<<'\n';
	for (int i = 0; i < 10; i++) {
		std::cout << this->populatie[i] << " ";
	}
	std::cout << '\n';

}
