#pragma once
#include "Repository.h"
#include "Subject.h"

class Controller:public Subject
{
private:
	Repository& repository;
public:
	Controller(Repository& repository);
	std::vector<Teacher> getTeachers();
	std::vector<Student> getStudents();
	std::vector<Student> showStudents(std::string teacherName);
	void addCoordinatoForStudent(Student student,std::string coordinator);
	std::vector<Student> searchForStudent(std::string name,std::string id,bool byId);
	void approveThesis(std::string teacherName);
	void generateFile(Student student, std::string teacherName);
	~Controller();
};

