#include"CGeneticAlgorithm.h"
#include "CIndividual.h"
#include "CKnapsackProblem.h"
#include <algorithm>
#include <iostream>

int main()
{
	try {
		CKnapsackProblem kp;
		//kp.loadFromFile("test1.txt");
		//kp.loadFromFile("test2.txt");
		kp.loadFromFile("test3.txt");
		//	kp.loadFromFile("test4.txt");
		
		//CKnapsackProblem kp(7,4,vector<int>{4,1,3,2},vector<int>{5,1,4,3}); //pojemnosc,l_przedmiotow, rozmiary,wartosci

		CGeneticAlgorithm ga(&kp,60, 0.1, 0.6); //instancja problemu, pop_size, mut_prob, cross_prob
		ga.createPopulation(&kp);
		//ga.printPopulation();
		cout << endl;
		vector<int> bestFitnesses;
		for (int i = 0; i < 100; i++) {
			cout << endl;
			cout << "Generacja " << i ;
			ga.RunGA(&kp);
			cout << endl;
			std::pair<std::vector<int>, int> solution = ga.getAnswer();
			bestFitnesses.push_back(solution.second);
			for (int i : solution.first) {
				std::cout << i << " ";
			}
			std::cout << "\nFITNESS: " << solution.second << std::endl;
		}
		
		std::cout << "\nROZWIĄZANIE: " << *max_element(bestFitnesses.begin(), bestFitnesses.end()) << std::endl;
	}
	

      catch (std::exception& e) {
	   cout << e.what();
	   throw e;
}

}
	

