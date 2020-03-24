#pragma once
#include "Repository.h"
#include "Project.h"
#include <iostream>

class Service
{
private:
	Repository* repo;
public:
	Service() { }
	Service(Repository* r): repo(r){}
	Repository getRepo() const { return *repo; }
	int addProject(Project p);
	int updateProject(int index, Project newP);
	int delProject(const char* path);
	void readProjects();
	
	Project* getAll();

	int getLen();
};

