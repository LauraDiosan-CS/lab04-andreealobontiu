#include "Project.h"
#include <string.h>
#include <stdlib.h>

//default constructor; all atributes are intialized with 0/null
Project::Project()
{
	this->gitPath = NULL;
	this->nrBranches = 0;
	this->nrCommits = 0;
}

//parameter constructor
//in: a path, number of branches, number of commits
//out: an instance of Project class which has those attributes
Project::Project(const char * gitPath, int nrBranches, int nrCommits)
{
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
	this->nrBranches = nrBranches;
	this->nrCommits = nrCommits;
}

//copy constructor
//in: an instance of Project
//out: a new instance of Project, with the same attribute values as the first one
Project::Project(const Project & p)
{
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->nrBranches = p.nrBranches;
	this->nrCommits = p.nrCommits;
}


//destructor. it deallocates the memory used for gitPath
Project::~Project()
{
	if (this->gitPath != NULL) {
		delete[] this->gitPath;
		this->gitPath = NULL;
	}
}


//getters and setters for each attribute from the class
char * Project::getPath()
{
	return this->gitPath;
}

int Project::getNrBranches()
{
	return this->nrBranches;
}

int Project::getNrCommits()
{
	return this->nrCommits;
}

void Project::setPath(const char* p)
{
	if (this->gitPath) 
	{
		delete[] this->gitPath;
	}
	this->gitPath = new char[strlen(p) + 1];
	strcpy_s(this->gitPath, strlen(p) + 1, p);
}

void Project::setNrBranches(int b)
{
	this->nrBranches = b;
}

void Project::setNrCommits(int c)
{
	this->nrCommits = c;
}

//compares 2 instances of Project
//in: an instance of object that will be compared with the current one
//out: 1 if they are equal, 0 otherwise
bool Project::compare(Project & p)
{
	return ((strcmp(this->gitPath, p.gitPath) == 0) && (this->nrBranches == p.nrBranches) && (this->nrCommits=p.nrCommits));
}

//override
Project & Project::operator=(const Project & p)
{
	if (this != &p)
	{
		this->setPath(p.gitPath);
		this->setNrBranches(p.nrBranches);
		this->setNrCommits(p.nrCommits);
	}
	return *this;
}

//function that returns a char array with info about the instance of Project
//in:-
//out: a char array with info about the instance of Project
char * Project::toString()
{
	if (this->gitPath != NULL) {
		int noChars = strlen(this->gitPath) + 1 + 5 + 5 + 2;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[5];
		strcpy_s(s, noChars, this->gitPath);
		strcat_s(s, noChars, " ; ");
		
		_itoa_s(this->nrBranches, aux, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, " ; ");
		_itoa_s(this->nrCommits, aux, 5, 10);
		strcat_s(s, noChars, aux);

		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		
		return s;
	}
	else
		return NULL;
}
