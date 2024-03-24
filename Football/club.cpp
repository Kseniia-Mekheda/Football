#include "club.h"
#include <fstream>
#include <string>
using namespace std;

const int DEFAULT_ARR_SIZE = 11;

Club::Club()
	:clubName(" "),
	clubCoef(1),
	capacity(DEFAULT_ARR_SIZE),
	filled(0),
	arr(new Footballer[capacity])
{}

Club::Club(std::string name, double coef, int cap)
	:clubName(name),
	clubCoef(coef),
	capacity(cap),
	filled(0),
	arr(new Footballer[capacity])
{}

Club::Club(const Club& C)
	:clubName(C.clubName),
	clubCoef(C.clubCoef),
	capacity(C.capacity),
	arr(new Footballer[C.capacity])
{
	for (int i = 0; i < capacity; ++i) {
		arr[i] = C.arr[i];
	}
}

Club::~Club() {}

void Club::adjustMemory() {
	if (filled < capacity) {
		return;
	}
	else {
		capacity += DEFAULT_ARR_SIZE;
		Footballer* temporary = new Footballer[capacity];
		for (int i = 0; i < filled; ++i) {
			temporary[i] = arr[i];
		}

		delete[] arr;
		arr = temporary;
		temporary = nullptr;
	}
}

void Club::addToClub(Footballer& F) {
	adjustMemory();
	F.setCoef(clubCoef);
	arr[filled] = F;
	++filled;
}
void Club::printClub() const {
	if (filled == 0) {
		cout << "Club is empty; " << endl;
	}

	cout << "Club: " << clubName << ". Payment: " << clubCoef << " per goal. Members quantity: " << filled << endl;

	cout << "Members: " << endl;
	for (int i = 0; i < filled; ++i) {
		arr[i].print();
	}
}

void Club::sortByGoals() {
	for (int i = 0; i < filled; ++i) {
		int max = i;
		for(int j = i + 1; j < filled; ++j) {
			if (arr[j].getGoals() > arr[max].getGoals()) {
				max = j;
			}
		}
		if (max != i) {
			Footballer victim = arr[i];
			arr[i] = arr[max];
			arr[max] = victim;
		}
	}
}

double Club::calcGoals(){
	int allGoals = 0;
	for (int i = 0; i < filled; ++i) {
		allGoals += arr[i].getGoals();
	}

	return allGoals;
}
double Club::calcSalary(){
	double allSalary = 0;
	for (int i = 0; i < filled; ++i) {
		allSalary += arr[i].getSalary();
	}

	return allSalary;
}

void divideInClubs(Club* arr, const std::string fileName) {
	ifstream fin(fileName);
	int size;
	fin >> size;
	Footballer F;

	for (int i = 0; i < size; ++i) {
		string fClub;
		fin >> fClub;
		fin >> F;
		if (fClub == "RealMadrid") {
			arr[0].addToClub(F);
		}
		if (fClub == "ManchesterUnited") {
			arr[1].addToClub(F);
		}
		if (fClub == "Liverpool") {
			arr[2].addToClub(F);
		}
	}
}

Club& Club::operator=(const Club& C)
{
	if (this != &C)
	{
		delete[] arr;
		clubName = C.clubName;
		clubCoef = C.clubCoef;
		capacity = C.capacity;
		filled = C.filled;
		arr = new Footballer[capacity];
		for (int i = 0; i < filled; ++i)
		{
			arr[i] = C.arr[i];
		}
	}
	return *this;
}

void findTheBestIn(Club* arr, int size, double(Club::*method)()) {
	Club best = arr[0];
	for (int i = 1; i < size; ++i) {
		if ((best.*method)() < (arr[i].*method)()) {
			best = arr[i];
		}
	}

	best.printClub();
}