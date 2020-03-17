#pragma once
#include "Project.h"
class Repository
{
private:
	int length = 0;
	Project projects[100];
public:
	Repository(){}
	int addProject(Project& p);
	int delProject(Project& p);
	int verifDuplicate(Project& p);
	Project* getAll();
	int getLen();
};

