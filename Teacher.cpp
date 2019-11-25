#include "Teacher.h"



Teacher::Teacher(std::string name) :name{name}
{
}

std::string Teacher::getName() {
	return this->name;
}

Teacher::~Teacher()
{
}
