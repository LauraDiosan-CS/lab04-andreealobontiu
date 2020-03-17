#include "Project.h"
#include <string.h>
#include <stdlib.h>

Project::Project()
{
	this->gitPath = NULL;
	this->nrBranches = 0;
	this->nrCommits = 0;
}

Project::Project(const char * gitPath, int nrBranches, int nrCommits)
{
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
	this->nrBranches = nrBranches;
	this->nrCommits = nrCommits;
}

Project::Project(const Project & p)
{
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->nrBranches = p.nrBranches;
	this->nrCommits = p.nrCommits;
}

/*Project::~Project()
{
	if (this->gitPath != NULL) {
		delete[] this->gitPath;
		this->gitPath = NULL;
	}
}*/

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

void Project::setPath(const char * p)
{
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

bool Project::compare(Project & p)
{
	return ((strcmp(this->gitPath, p.gitPath) == 0) && (this->nrBranches == p.nrBranches) && (this->nrCommits=p.nrCommits));
}

Project & Project::operator=(const Project & p)
{
	//suprascriere
	if (this != &p)
	{
		this->setPath(p.gitPath);
		this->setNrBranches(p.nrBranches);
		this->setNrCommits(p.nrCommits);
	}
	return *this;
}

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
