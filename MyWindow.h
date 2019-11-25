#pragma once

#include <QWidget>
#include "ui_MyWindow.h"
#include "Observer.h"
#include "Controller.h"

class MyWindow : public QWidget,public Observer
{
	Q_OBJECT

public:
	MyWindow(Controller& controller,std::string teacherName,QWidget *parent = Q_NULLPTR);
	void update() override;
	~MyWindow();
	void connectAll();
	void searchStudent();
	void setCurrentItem();
	void setCoordinate();
	void approveThesis();
private:
	Controller& controller;
	std::string teacherName;
	QListWidgetItem* currentItem=NULL;
private:
	Ui::MyWindow ui;
};
