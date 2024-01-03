#pragma warning (disable: 4996)
#include <iostream>
#include <fstream>
#include <string>
#include "RegiuneReligioasa.h"
#include "RegiuneMilitaristica.h"
#include "RegiuneDemocratica.h"

using namespace std;
int main() {

	std::ifstream Input("input.txt");
	std::ofstream Output("out.txt");

	RegiuneReligioasa regiuneaReligioasa;
	RegiuneMilitaristica regiuneaMilitaristica;
	RegiuneDemocratica regiuneaDemoratica;

	char buffer[256];	

	for (int i = 0; i < 3; i++) {

		Input >> buffer;

		if (strcmp(buffer, "1") == 0) {
			regiuneaReligioasa.citire(Input);
			//regiuneaReligioasa.afisare(Output);
		}
		if (strcmp(buffer, "2") == 0) {
			regiuneaMilitaristica.citire(Input);
			//regiuneaMilitaristica.afisare(Output);
		}
		if (strcmp(buffer, "3") == 0) {
			regiuneaDemoratica.citire(Input);
			//regiuneaDemoratica.afisare(Output);
		}

	}
	
	int nrIntrebari, zona, varsta;
	std::string intrebare;
	for (int i = 0; i < 3; i++) { //pana la 3 ca sunt 3 zone
		Input >> buffer;
		nrIntrebari = std::stoi(buffer);
		Input >> buffer;
		zona = std::stoi(buffer);
		if (zona == 1) {
			Output << "Zona 1" << '\n';
		}
		if (zona == 2) {
			Output << "Zona 2" << '\n';
		}
		if (zona == 3) {
			Output << "Zona 3" << '\n';
		}
		//Input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int j = 0; j < nrIntrebari; j++) {
			//std::getline(Input, intrebare, '\n');
			if (zona == 3) { //iau si varsta mai intai
				Input >> buffer;
				varsta = std::stoi(buffer);
			}
			Input.get(); // scap de spatiu gol
			Input.getline(buffer, sizeof(buffer), '\n'); // ia intrebarea
			Output << buffer<< '\n'; // afiseaza intrebarea
			if (zona == 1) {
				regiuneaReligioasa.calculareRezultat(Input, Output);
			}
			if (zona == 2) {
				regiuneaMilitaristica.calculareRezultat(Input, Output);
			}
			if (zona == 3) {
				regiuneaDemoratica.calculareRezultat(Input, Output, varsta);
			}	
		}	
	}
	
	Input.close();
	Output.close();

	return 0;
}