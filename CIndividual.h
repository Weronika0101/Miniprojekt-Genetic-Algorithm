#pragma once
#include <iostream>
#include <vector>
#include "CKnapsackProblem.h"

using namespace std;

class CKnapsackProblem;
class CIndividual {
public:
	CIndividual(vector<int> seq);
	~CIndividual();
	int countFitness(CKnapsackProblem* kp);
	int getFitness();
	void mutate(double mut_prob,CKnapsackProblem* kp);
	std::pair<CIndividual, CIndividual> cross(CIndividual* parent, double cross_prob);
	void printIndividual();
	vector<int> getGenotyp();

private:
	vector<int> genotyp;
	int fitness;

};
