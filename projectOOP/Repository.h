#pragma once
#include "Project.h"
class Repository
{
private:
	int length;
	Project* projects;
public:
	Repository();
	~Repository();
	int addProject(const char* p, int b, int c);
	int delProject(Project p);
	int verifDuplicate(Project p);
	Project* getAll();
	void setAll(Project* p, int l);
	int getLen();
	int updateProject(int index, Project newP);
};

