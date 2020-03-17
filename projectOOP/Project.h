#pragma once
#include <string.h>
class Project
{
private:
	char* gitPath=new char[100];
	int nrBranches;
	int nrCommits;

public:
	Project();
	Project(const char* gitPath, int nrBranches, int nrCommits);
	Project(const Project &p);
	~Project();

	char* getPath();
	int getNrBranches();
	int getNrCommits();
	void setPath(const char* p);
	void setNrBranches(int b);
	void setNrCommits(int c);

	bool compare(Project &p);
	Project& operator=(const Project& p);
	char* toString();
	
};

