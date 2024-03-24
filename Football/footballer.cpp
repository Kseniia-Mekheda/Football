#include "footballer.h"
using namespace std;

Footballer::Footballer()
	:footballerName(" "),
	footballerSurname(" "), 
	footballerGoalls(0),
	footballerCoef(1)
{}

Footballer::Footballer(string name, string surname, int goals)
	:footballerName(name),
	footballerSurname(surname),
	footballerGoalls(goals),
	footballerCoef(1)
{}

Footballer::Footballer(const Footballer& C)
	:footballerName(C.footballerName),
	footballerSurname(C.footballerSurname),
	footballerGoalls(C.footballerGoalls),
	footballerCoef(C.footballerCoef)
{}

Footballer::~Footballer() {}


int Footballer::getGoals() const {
	return footballerGoalls;
}
double Footballer::getSalary() const {
	return footballerGoalls * footballerCoef;
}

void Footballer::setCoef(double coef) {
	footballerCoef = coef;
}

void Footballer::print() const {
	cout << "Footballer: " << footballerName << ' ' << footballerSurname << ". Goals quantity: " << footballerGoalls
		<< ". Salary: " << getSalary() << " usd." << endl;
}
void Footballer::readFrom(istream& in) {
	in >> footballerName >> footballerSurname >> footballerGoalls;
}

istream& operator>>(istream& in, Footballer& F) {
	F.readFrom(in);
	return in;
}

