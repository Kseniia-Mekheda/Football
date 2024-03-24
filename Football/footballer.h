#pragma once
#include <iostream>

class Footballer {
private:
	std::string footballerName;
	std::string footballerSurname;
	int footballerGoalls;
	double footballerCoef;

public:
	Footballer();
	Footballer(std::string name, std::string surname, int goals);
	Footballer(const Footballer& C);
	~Footballer();

	int getGoals() const;
	double getSalary() const;

	void setCoef(double coef);
	
	void print() const;
	void readFrom(std::istream& in);
	Footballer& operator=(const Footballer& F);
};

std::istream& operator>>(std::istream& in, Footballer& F);