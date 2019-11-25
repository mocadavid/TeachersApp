#include "Controller.h"
#include <algorithm>
#include <fstream>
#include <iostream>

Controller::Controller(Repository& repository) :repository{repository}
{
}

std::vector<Teacher> Controller::getTeachers() {
	return this->repository.getTeachers();
}


std::vector<Student> Controller::getStudents() {
	return this->repository.getStudents();
}

std::vector<Student> Controller::showStudents(std::string teacherName) {
	std::vector<Student> allStudents = this->repository.getStudents();
	std::vector<Student> sortedStudents;
	std::vector<Student> studentsNotCoordinated;
	std::vector<Student> notCurrentYearThesis;
	for (auto student : allStudents) {
		if (student.getCoordinator() == teacherName) {
			if (student.getYear() == 2021) {
				sortedStudents.push_back(student);
			}
			else {
				notCurrentYearThesis.push_back(student);
			}
		}
		else {
			//studentsNotCoordinated.push_back(student);
		}
	}
	sort(notCurrentYearThesis.begin(), notCurrentYearThesis.end(), [](Student student1, Student student2) {return student1.getYear() > student2.getYear(); });
	for (auto student : notCurrentYearThesis) {
		sortedStudents.push_back(student);
	}
	sort(studentsNotCoordinated.begin(), studentsNotCoordinated.end(), [](Student student1, Student student2) {return student1.getYear() > student2.getYear(); });
	for (auto student : studentsNotCoordinated) {
		sortedStudents.push_back(student);
	}
	return sortedStudents;
}

void Controller::addCoordinatoForStudent(Student student, std::string coordinator) {
	/*
	Searches for a GIVEN student in the vector of students from repository and sets the index to the position 
	of the student in the vector of students if it does not have a coordinator otherwise it does nothing
	then calls the function from repository to set the coordinator for the given student
	preConditions: student - student registered in repository, coordinator - teacher registered in repository
	student - Student object, coordinator - string
	*/
	int index = 0;
	bool found = false;
	std::vector <Student> students = this->repository.getStudents();
	for (auto studentFromRepository : students) {
		if (studentFromRepository.getId() == student.getId()) {
			if (studentFromRepository.getCoordinator() == "") {
				found = true;
				break;
			}
			
		}
		index++;
	}
	if (found == true) {
		this->repository.addCoordinatorForStudent(index, coordinator);
	}
}

std::vector<Student> Controller::searchForStudent(std::string name, std::string id, bool byId) {
	/*
	If byId is true searches for students by id through repository and adds them into the studentsFound vector;
	Otherwise searches for students by name through repository and adds them into the studentsFound vector
	The search is partial matching between name or id and the student name or id
	name-string,id-string,byId-bool;
	return a vector with students or an empty vector of students if no students found
	*/
	std::vector<Student> studentsFound;
	std::vector<Student> allStudents = this->getStudents();
	std::size_t found;
	if (byId) {
		for (auto student : allStudents) {
			found = student.getId().find(id);
			if (found != std::string::npos) {
				studentsFound.push_back(student);
			}
		}
	}
	else {
		for (auto student : allStudents) {
			found = student.getName().find(name);
			if (found != std::string::npos) {
				studentsFound.push_back(student);
			}
		}
	}
	return studentsFound;
}

void Controller::approveThesis(std::string teacherName) {
	std::vector<Student> students = this->getStudents();
	for (auto student : students) {
		if (student.getTitle() != "No title") {
			this->generateFile(student,teacherName);
		}
	}
}

void Controller::generateFile(Student student,std::string teacherName) {
	std::string nameFile;
	nameFile += student.getName();
	nameFile += ".txt";
	std::ofstream fileDescriptor(nameFile.c_str());
	if (!fileDescriptor.is_open()) {

	}

	fileDescriptor << teacherName << " aproves the thesis " << student.getTitle() << " authored by " << student.getName();

	fileDescriptor.close();
}

Controller::~Controller()
{
}
