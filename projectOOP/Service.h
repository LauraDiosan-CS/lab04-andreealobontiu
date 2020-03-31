#pragma once
#include "Repository.h"
#include "Project.h"
#include <iostream>

class Service
{
private:
	Repository repo;
	int len;
public:
	Service();
	Service(Repository r);
	~Service();
	Repository getRepo();
	int addProject(const char*g, int b, int c);
	int updateProject(int index, Project newP);
	
	int delProjectPath(const char* path);
	void delProject(int index);
	int delProjectBranches(int nrBranches);

	int filterByPath(const char* path);
	int filterByCommits(int nrCommits);
	int filterGreaterBranches(int greaterThan);
	int filterCommitsInterval(int a, int b);

	int maxBranches();
	int minCommits();

	int sumCommits();
	int sumBranches();

	void readProjects();
	
	
	Project* getAll();

	int getLen();
};

