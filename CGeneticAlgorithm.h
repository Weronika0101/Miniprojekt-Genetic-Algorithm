#pragma once
#include <vector>
#include <iostream>
#include "CIndividual.h"

using namespace std;

class CGeneticAlgorithm {
public:
	CGeneticAlgorithm(CKnapsackProblem* problem,int popsize, double mutprob, double crossprob);
	CIndividual bestSolution();
	void createPopulation(CKnapsackProblem* kp);
	void printPopulation();
	void validateData(int populationSize, double crossoverProbability, double mutationProbability);
	void validateProblem(CKnapsackProblem* problem);
	void RunGA(CKnapsackProblem* kp);
	CIndividual* getParent();
	int calculateFitness(CIndividual individual);
	CIndividual findBestOfTwo(const CIndividual& ob1, const CIndividual& ob2);
	std::pair<std::vector<int>, int> getAnswer();
private:
	CKnapsackProblem* problem;
	int pop_size;
	double mut_prob;
	double cross_prob;
	vector<CIndividual>population;
};
