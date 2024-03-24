#pragma once
#include "footballer.h"

class Club {
private:
	std::string clubName;
	double clubCoef;
	int capacity;
	int filled;
	Footballer* arr;
	void adjustMemory();

public:

	Club();
	Club(std::string name, double coef, int cap = 11);
	Club(const Club& C);
	~Club();

	void addToClub(Footballer& F);
	void printClub() const;

	void sortByGoals(); 

	double calcGoals();
	double calcSalary();

	Club& operator=(const Club& C);
};

void divideInClubs(Club* arr, const std::string fileName);
void findTheBestIn(Club* arr, int size, double(Club::* method)());