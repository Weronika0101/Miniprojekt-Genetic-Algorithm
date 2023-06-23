
#pragma once
#include <iostream>
#include "CKnapsackProblem.h"
#include <vector>
#include<random>
#include <fstream>
#include "CIndividual.h"


using namespace std;

/*CKnapsackProblem::CKnapsackProblem(int poj_plecaka, int l_przedmiotow, vector<int> t_rozmiarow, vector<int> t_wartosci) {
	pojemnosc_plecaka = poj_plecaka;
	liczba_przedmiotow = l_przedmiotow;
	tabela_rozmiarow = t_rozmiarow;
	tabela_wartosci = t_wartosci;
}*/

CKnapsackProblem::CKnapsackProblem(int poj_plecaka, int l_przedmiotow, vector<int> t_rozmiarow, vector<int> t_wartosci)
	: pojemnosc_plecaka(poj_plecaka), liczba_przedmiotow(l_przedmiotow), tabela_rozmiarow(t_rozmiarow),tabela_wartosci(t_wartosci) {
	 validateData(poj_plecaka,l_przedmiotow);
}
void CKnapsackProblem::validateData(int poj_plecaka, int l_przedmiotow) {
	if (poj_plecaka <= 0) {
		throw std::runtime_error("Pojemnosc plecaka nie moze byc mniejsza od 0");
	}
	if (l_przedmiotow<=0) {
		throw std::runtime_error("Liczba przedmiotow musi byc wieksza od 0");
	}
}

CKnapsackProblem::CKnapsackProblem() {
	liczba_przedmiotow = 0;
	pojemnosc_plecaka = 0;
	tabela_wartosci.clear();
	tabela_rozmiarow.clear();
}

vector<int> CKnapsackProblem::getTabelaRozmiarow() {
	return tabela_rozmiarow;
}

vector<int> CKnapsackProblem::getTabelaWartosci() {
	return tabela_wartosci;
}
int CKnapsackProblem::getValue(int index) const {
	return tabela_wartosci[index];
}

int CKnapsackProblem::getWeight(int index) const {
	return tabela_rozmiarow[index];
}
int CKnapsackProblem::getNumItems() const {
	return liczba_przedmiotow;
}

int CKnapsackProblem::getPojemnosc() {
	return pojemnosc_plecaka;
}
int CKnapsackProblem::iCompute(vector<int> genotyp) {
	int fitness = 0;
	int size = 0;

	for (int i = 0; i < genotyp.size(); i++) {

		if (genotyp.at(i) == 1) {
			size += tabela_rozmiarow.at(i);
			if (size > pojemnosc_plecaka) {
				fitness = 0;
				break;
			}
			fitness += tabela_wartosci.at(i);
		}
	}
	return fitness;
}

CIndividual CKnapsackProblem::generateIndividuall() {
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> distrib(0,1);
	vector<int> genotyp;
	for (int n = 0; n < liczba_przedmiotow; ++n) {
		
		genotyp.push_back(distrib(gen));
	}
	CIndividual nowy(genotyp);
	return  nowy;
}

void CKnapsackProblem::loadFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Nie uda³o siê otworzyæ pliku " << filename << std::endl;
		return;
	}
	file >> liczba_przedmiotow;
	if (liczba_przedmiotow < 0) {
		throw std::runtime_error("Liczba przedmiotow mniejsza od 0!");
	}
	tabela_rozmiarow.clear();
	tabela_wartosci.clear();
	for (int i = 0; i < liczba_przedmiotow; i++) {
		int size, value;
		file >> value >> size;
		tabela_rozmiarow.push_back(size);
		tabela_wartosci.push_back(value);
	}
	file >> pojemnosc_plecaka;
	if (pojemnosc_plecaka < 0) {
		throw std::runtime_error("Pojemnosc mniejsza od 0!");
	}
	file.close();
}

