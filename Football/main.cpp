#include <iostream>
#include <fstream>
#include "club.h"
using namespace std;

int main() {
	int generalArrSize = 3;
	Club* generalArr = new Club[generalArrSize];
	generalArr[0] = Club("RealMadrid", 4000);
	generalArr[1] = Club("ManchesterUnited", 5300);
	generalArr[2] = Club("Liverpool", 3200);

	divideInClubs(generalArr, "footballers.txt");

	for (int i = 0; i < generalArrSize; ++i) {
		generalArr[i].sortByGoals();
		generalArr[i].printClub();
		cout << endl;
		cout << "All goals quantity: " << generalArr[i].calcGoals() << endl;
		cout << "All salarys sum: " << generalArr[i].calcSalary() << " usd." << endl;
		cout << endl;
	}

	cout << "The biggest quantity of goals has: " << endl;
	findTheBestIn(generalArr, generalArrSize, &Club::calcGoals);

	cout << endl;

	cout << "Best salary has: " << endl;
	findTheBestIn(generalArr, generalArrSize, &Club::calcSalary);
	
	return 0;
}