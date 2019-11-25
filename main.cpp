//#include "GeneratedAuto.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "MyWindow.h"
#include <assert.h>
#include <QMessageBox>

void testFunction() {
	Repository repository{};
	Controller controller{ repository };
	std::string newCoordinator{ "Sergiu" };
	Student studentWeWantToSetCoordinator{ "AAA","","",0,"","" };
	controller.addCoordinatoForStudent(studentWeWantToSetCoordinator, newCoordinator);
	Student studentWhichHasCoordinator{ "CCC","","",0,"","" };
	controller.addCoordinatoForStudent(studentWhichHasCoordinator, newCoordinator);
	std::vector<Student> students = repository.getStudents();
	for (auto student : students) {
		if (student.getId() == "AAA") {
			assert(student.getCoordinator() == "Sergiu");
		}
		if (student.getId() == "CCC") {
			assert(student.getCoordinator() != "Sergiu");
		}
	}
	std::vector<Student> studentsFoundByName = controller.searchForStudent("Dav", "", false);
	std::vector<Student> studentsFoundById = controller.searchForStudent("", "AAA", true);
	assert(studentsFoundByName.size() == 1);
	assert(studentsFoundById.size() == 1);
}

int main(int argc, char *argv[])
{
	

	QApplication a(argc, argv);

	testFunction();

	Repository repository{};
	Controller controller{ repository };

	std::vector<MyWindow*> windows;
	std::vector<Teacher> teachers = repository.getTeachers();

	for (auto teacher : teachers) {
		MyWindow* window = new MyWindow{ controller,teacher.getName() };
		window->setWindowTitle(teacher.getName().c_str());
		controller.registerObserver(window);
		windows.push_back(window);
	}

	for (auto window : windows) {
		window->show();
	}

	return a.exec();
}

