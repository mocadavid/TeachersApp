#pragma once
#include <string>

class Teacher
{
private:
	std::string name;
public:
	Teacher(std::string name);
	std::string getName();
	~Teacher();
};

