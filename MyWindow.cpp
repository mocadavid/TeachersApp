#include "MyWindow.h"
#include <QMessageBox>

MyWindow::MyWindow(Controller& controller, std::string teacherName,QWidget *parent)
	: controller{ controller }, teacherName{teacherName}, QWidget(parent)
{
	ui.setupUi(this);
	this->update();
	this->connectAll();
}

void MyWindow::update() {
	this->ui.listWidgetAllStudents->clear();
	std::vector<Student> sortedStudents = this->controller.showStudents(this->teacherName);
	
	for (auto student : sortedStudents) {
		new QListWidgetItem(student.toString().c_str(), this->ui.listWidgetAllStudents);
	}
}

MyWindow::~MyWindow()
{
}

void MyWindow::connectAll() {
	QObject::connect(this->ui.lineEditSearchId, &QLineEdit::textChanged, this, &MyWindow::searchStudent);
	QObject::connect(this->ui.lineEditSearchName, &QLineEdit::textChanged, this, &MyWindow::searchStudent);
	QObject::connect(this->ui.listWidgetSearchedStudents, &QListWidget::pressed, this, &MyWindow::setCurrentItem);
	QObject::connect(this->ui.pushButtonAddCoordinate, &QPushButton::clicked, this, &MyWindow::setCoordinate);
	QObject::connect(this->ui.pushButtonApprove, &QPushButton::clicked, this, &MyWindow::approveThesis);
}

void MyWindow::searchStudent() {
	this->ui.listWidgetSearchedStudents->clear();
	if (this->ui.lineEditSearchId->text().isEmpty()) {
		std::vector<Student> studentsFound = this->controller.searchForStudent(this->ui.lineEditSearchName->text().toStdString(), "", false);//name id bool
		for (auto student : studentsFound) {
			new QListWidgetItem(student.toString().c_str(), this->ui.listWidgetSearchedStudents);
		}
	}
	else {
		std::vector<Student> studentsFound = this->controller.searchForStudent("", this->ui.lineEditSearchId->text().toStdString(), true);
		for (auto student : studentsFound) {
			new QListWidgetItem(student.toString().c_str(), this->ui.listWidgetSearchedStudents);
		}
	}
}

void MyWindow::setCurrentItem() {
	this->currentItem = this->ui.listWidgetSearchedStudents->currentItem();
}

void MyWindow::setCoordinate() {
	if (this->currentItem != NULL) {
		char buffer[51];
		char* argument;
		strcpy(buffer, this->currentItem->text().toStdString().c_str());
		argument = strtok(buffer, ",");
		std::string id{ argument };
		Student student{ id,"","",0,"","" };
		this->controller.addCoordinatoForStudent(student, this->teacherName);
	}
	this->controller.notify();
}

void MyWindow::approveThesis() {
	this->controller.approveThesis(this->teacherName);
}