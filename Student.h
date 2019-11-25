#pragma once
#include <string>

class Student
{
private:
	std::string id;
	std::string name;
	std::string email;
	int year;
	std::string title;
	std::string coordinator;
public:
	Student(std::string id, std::string name, std::string email, int year, std::string title, std::string coordinator);
	std::string toString();
	std::string getCoordinator();
	int getYear();
	std::string getId();
	std::string getName();
	std::string getTitle();
	void setCoordinator(std::string coordinator);
	~Student();
};

