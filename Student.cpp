#include "Student.h"



Student::Student(std::string id, std::string name, std::string email, int year, std::string title, std::string coordinator)
	:id{ id }, name{ name }, email{ email }, year{ year }, title{ title }, coordinator{coordinator}
{
}

std::string Student::toString() {
	std::string finalString;
	finalString += this->id;
	finalString += ",";
	finalString += this->name;
	finalString += ",";
	finalString += this->email;
	finalString += ",";
	finalString += std::to_string(this->year);
	finalString += ",";
	finalString += this->title;
	finalString += ",";
	finalString += this->coordinator;
	return finalString;
}

std::string Student::getCoordinator() {
	return this->coordinator;
}


std::string Student::getId() {
	return this->id;
}

std::string Student::getName() {
	return this->name;
}


int Student::getYear() {
	return this->year;
}

void Student::setCoordinator(std::string coordinator) {
	this->coordinator = coordinator;
}

Student::~Student()
{
}

std::string Student::getTitle() {
	return this->title;
}