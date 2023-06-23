#pragma once
#include <iostream>
#include <vector>
#include "CIndividual.h"


using namespace std;
class CIndividual;

class CKnapsackProblem {

public:
	CKnapsackProblem();
	CKnapsackProblem(int pojemnosc_plecaka, int l_przedmiotow, vector<int> t_rozmiarow, vector<int> t_wartosci);
	vector<int> getTabelaRozmiarow();
	vector<int> getTabelaWartosci();
	[[nodiscard]] int getNumItems() const;
	[[nodiscard]] int getValue(int index) const;
	[[nodiscard]] int getWeight(int index) const;
	int getPojemnosc();
	void validateData(int poj_plecaka, int l_przedmiotow);
	int iCompute(vector<int>genotyp);
	CIndividual generateIndividuall();
	void loadFromFile(const std::string& filename);

private:
	int liczba_przedmiotow;
	int pojemnosc_plecaka;
	vector<int>tabela_rozmiarow;
	vector<int>tabela_wartosci;
	

};
