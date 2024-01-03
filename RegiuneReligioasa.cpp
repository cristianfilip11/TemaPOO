#include "RegiuneReligioasa.h"
#include <iostream>
#include <string>
RegiuneReligioasa::RegiuneReligioasa() : Regiune(){
	populatie[0] = 0;
	populatie[1] = 0;
	populatie[2] = 0;
	populatie[3] = 0;
	populatie[4] = 0;
}

RegiuneReligioasa::RegiuneReligioasa(const int* populatie, const float& nrLoc) : Regiune(nrLoc) {

	if (populatie != nullptr) {
		this->populatie[0] = populatie[0];
		this->populatie[1] = populatie[1];
		this->populatie[2] = populatie[2];
		this->populatie[3] = populatie[3];
		this->populatie[4] = populatie[4];
	}
}

void RegiuneReligioasa::calculNrLocuitori() {
	for (int i = 0; i < 5; i++) {
		this->nrLoc = this->nrLoc + this->populatie[i];
	}
}

void RegiuneReligioasa::citire(std::ifstream& Input) {
	char buffer[256];
	Input >> buffer;
	this->nrLoc = std::stoi(buffer);
	for (int i = 0; i < 5; i++) {
		Input >> buffer;
		this->populatie[i] = std::stoi(buffer);
	}
	//this->calculNrLocuitori();
}

void RegiuneReligioasa::citireVotanti(std::ifstream& Input) {
	char buffer[256];

	for (int i = 0; i < 5; i++) {
		Input >> buffer;
		this->populatie[i] = std::stoi(buffer);
	}
	this->calculNrLocuitori();
}

void RegiuneReligioasa::calculareRezultat(std::ifstream& Input, std::ofstream& Output) {

	char buffer[256];
	RegiuneReligioasa votanti_poz;
	RegiuneReligioasa votanti_neg;

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
	for (int i = 0; i < 5; i++) {
		voturiPozitive = voturiPozitive + votanti_poz.populatie[i] * (1 - 0.2 * i);
		voturiNegative = voturiNegative + votanti_neg.populatie[i] * (1 - 0.2 * i);
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
	prezenta = (votanti_poz.nrLoc + votanti_neg.nrLoc) / (this->nrLoc - 1);
	Output << "Prezenta vot: " << prezenta * 100 << "%" << '\n';
}

void RegiuneReligioasa::afisare(std::ofstream& Output) {
	Output << "Zona 1" << '\n';
	std::cout << this->nrLoc<<'\n';
	for (int i = 0; i < 5; i++) {
		std::cout << this->populatie[i] << " ";
	}
	std::cout << '\n';
}