#pragma once
#include <iostream>
#include <vector>
#include "CGeneticAlgorithm.h"
#include "CKnapsackProblem.h"
#include<random>

using namespace std;

CGeneticAlgorithm::CGeneticAlgorithm(CKnapsackProblem* problem, int pop_size, double mut_prob, double cross_prob)
    : problem(problem), pop_size(pop_size), cross_prob(cross_prob), mut_prob(mut_prob) {
    validateProblem(problem);
    validateData(pop_size, cross_prob, mut_prob);
}


void CGeneticAlgorithm::createPopulation(CKnapsackProblem* kp) {

    for (int i = 0; i < pop_size; i++) {
        population.push_back((*kp).generateIndividuall());
    }
    for (int i = 0; i < pop_size; i++) {
        population.at(i).countFitness(kp);
    }
}
void CGeneticAlgorithm::printPopulation() {
    for (int i = 0; i < population.size(); i++) {
        population.at(i).printIndividual();
    }

}
void CGeneticAlgorithm::validateData(int populationSize, double crossoverProbability, double mutationProbability) {
    if (populationSize <= 0) {
        throw std::runtime_error("Population size cant be lower than 0");
    }
    if (crossoverProbability < 0 || crossoverProbability > 1) {
        throw std::runtime_error("Crossover probability must be grater or equal to 0 and less or equal to 1");
    }
    if (mutationProbability < 0 || mutationProbability > 1) {
        throw std::runtime_error("Mutation probability must be grater or equal to 0 and less or equal to 1");
    }
}
void CGeneticAlgorithm::validateProblem(CKnapsackProblem* problem) {
    if (problem->getPojemnosc() <= 0) {
        throw std::runtime_error("Capacity can not be lower than 0");
    }
    if (problem->getNumItems()<=0){
        throw std::runtime_error("Number of items can not be lower than 0");
}
}

std::pair<std::vector<int>, int> CGeneticAlgorithm::getAnswer() {
    int bestIndex = 0;
    int bestFitness = 0;
    for (int i = 0; i < pop_size; i++) {
        int fitness = calculateFitness(population[i]);
        if (fitness > bestFitness) {
            bestIndex = i;
            bestFitness = fitness;
        }
    }
    return std::make_pair(population[bestIndex].getGenotyp(), bestFitness);
}


int CGeneticAlgorithm::calculateFitness(CIndividual individual) {
 
    return individual.getFitness();
}
CIndividual CGeneticAlgorithm::findBestOfTwo(const CIndividual& ob1, const CIndividual& ob2) {
    if (calculateFitness(ob1) > calculateFitness(ob2)) {
        return ob1;
    }
    return ob2;
}
void CGeneticAlgorithm::RunGA(CKnapsackProblem* kp) {
    vector<CIndividual> potomstwo;
    
    while (potomstwo.size() < pop_size) {
        
        CIndividual* parent1 = this->getParent();
        CIndividual* parent2 = this->getParent();
        
        while (parent1 == parent2) {
              parent2 = this->getParent();
        }
        //vector<CIndividual> dzieci;
        std::pair<CIndividual, CIndividual> dzieci=(*parent1).cross(parent2, cross_prob);
        dzieci.first.countFitness(kp);
        dzieci.second.countFitness(kp);
        potomstwo.push_back(findBestOfTwo(dzieci.first, dzieci.second));
      
    }
  //  printPopulation();

 
   // cout << "After mutation" << endl;
    population = potomstwo;
    for (int i = 0; i < pop_size; i++) {
        population.at(i).mutate(mut_prob,kp);
    }
  //  printPopulation();
    
}


CIndividual* CGeneticAlgorithm::getParent() {
  

    int a_random_int1 = rand() % population.size();
    int a_random_int2 = rand() % population.size();
    
    if (population.at(a_random_int1).getFitness() >= population.at(a_random_int2).getFitness()) {
        return &(population.at(a_random_int1));
    } else  return &(population.at(a_random_int2));
}

