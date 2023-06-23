#include <iostream>
#pragma once
#include "CIndividual.h"
#include <vector>
#include <random>

using namespace std;

CIndividual::CIndividual(vector<int> sequence) {
	genotyp = sequence;
	fitness = 0;
}
CIndividual::~CIndividual() {
	//genotyp.clear();
}

vector<int> CIndividual::getGenotyp() {
	return this->genotyp;
}

int CIndividual::countFitness(CKnapsackProblem* kp) {

	int fitness= (*kp).iCompute(this->genotyp);
	this->fitness = fitness;
	return fitness;

}

int CIndividual::getFitness() {
	return fitness;
}

void CIndividual::mutate(double mut_prob,CKnapsackProblem* kp) {

	double lower_bound = 0;
	double upper_bound = 1;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;


	for (int i = 0; i < genotyp.size();i++) {

		
		double a_random_double = unif(re);
		if (a_random_double < mut_prob) {

			if (genotyp.at(i) == 1) {

				genotyp.at(i) = 0;
			}
			else {
			    genotyp.at(i) = 1;
			}
			this->countFitness(kp);
			this->fitness = this->getFitness();
		}
	}
	
	
}
std::pair<CIndividual, CIndividual> CIndividual::cross(CIndividual* parent,double cross_prob) {
	double lower_bound = 0;
	double upper_bound = 1;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;
	double a_random_double = unif(re);
	vector<int> newGenotyp1=this->genotyp;
	vector<int>newGenotyp2 = parent->genotyp;

	if (a_random_double < cross_prob) {


		int a_random_int = rand() % genotyp.size();


		newGenotyp1.clear();
		newGenotyp1.insert(newGenotyp1.end(), genotyp.begin(), genotyp.begin() + a_random_int);
		newGenotyp1.insert(newGenotyp1.end(), (*parent).genotyp.begin() + a_random_int, (*parent).genotyp.end());

		newGenotyp2.clear();
		newGenotyp2.insert(newGenotyp2.end(), (*parent).genotyp.begin(), (*parent).genotyp.begin() + a_random_int);
		newGenotyp2.insert(newGenotyp2.end(), genotyp.begin() + a_random_int, genotyp.end());

	}
	CIndividual child1(newGenotyp1);
	CIndividual child2(newGenotyp2);
	

	return std::make_pair(child1, child2);
}
void CIndividual::printIndividual() {

	for(int i = 0; i < genotyp.size(); i++) {
		cout << genotyp.at(i);
	}
	cout << "\nFitness: " << fitness;
	cout << endl;
}

