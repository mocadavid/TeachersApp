#include "Repository.h"
#include <fstream>
#include <iostream>
using namespace std;

Repository::Repository()
{
	this->loadStudents();
	this->loadTeachers();
}

std::vector<Teacher> Repository::getTeachers() {
	return this->teachers;
}

std::vector<Student> Repository::getStudents() {
	return this->students;
}

void Repository::loadStudents() {

	ifstream fileDescriptor("StudentsFile.txt");

	char buffer[101];
	char* argument;

	while (fileDescriptor.getline(buffer, 100)) {
		argument = strtok(buffer, ",\n");
		std::string id{ argument };
		argument = strtok(NULL, ",\n");
		std::string name{ argument };
		argument = strtok(NULL, ",\n");
		std::string email{ argument };
		argument = strtok(NULL, ",\n");
		int year = atoi(argument);
		argument = strtok(NULL, ",\n");
		std::string title{ argument };
		argument = strtok(NULL, ",\n");
		std::string coordinator;
		if (argument == NULL) {
			coordinator = "";
		}
		else {
			std::string pickedCoordinator{ argument };
			coordinator = pickedCoordinator;
		}
		Student student{ id,name,email,year,title,coordinator };
		this->students.push_back(student);
	}

	fileDescriptor.close();
}

void Repository::loadTeachers() {
	ifstream fileDescriptor("TeachersFile.txt");

	char buffer[101];
	char* argument;

	while (fileDescriptor.getline(buffer, 100)) {
		argument = strtok(buffer, "\n");
		std::string name{ argument };
		Teacher teacher{ name };
		this->teachers.push_back(teacher);
	}

	fileDescriptor.close();
}

void Repository::addCoordinatorForStudent(int index, std::string coordinator) {
	this->students[index].setCoordinator(coordinator);
}


Repository::~Repository()
{
}
