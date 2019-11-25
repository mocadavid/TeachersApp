#pragma once
#include <vector>
#include "Teacher.h"
#include "Student.h"

class Repository
{
private:
	std::vector<Teacher> teachers;
	std::vector<Student> students;
public:
	Repository();
	std::vector<Teacher> getTeachers();
	std::vector<Student> getStudents();
	void addCoordinatorForStudent(int index, std::string coordinator);
	void loadStudents();
	void loadTeachers();
	~Repository();
};

