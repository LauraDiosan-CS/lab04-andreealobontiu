#include "Repository.h"
#include <string>

//default constructor for Repository
Repository::Repository()
{
	this->projects = new Project[100];
	this->length = 0;
}

//destructor for Repository
Repository::~Repository()
{
	if (this->projects!=NULL)
	{
		this->projects = NULL;
		this->length = 0;
	}
}

//function that adds an instance of Project to Repository
//in: an instance of Project
//out:- 
int Repository::addProject(const char* g, int b, int c)
{
	Project p = Project(g, b, c);
	int poz = verifDuplicate(p);
	if (poz == -1)
	{
		this->projects[this->length] = p;
		this->length = this->length + 1;
		return 1;
	}
	return 0;
}

//function that removes an instance of Project from Repository
//in: an instance of Project
//out:- 
int Repository::delProject(Project p)
{
	int poz = verifDuplicate(p);
	if (poz != -1)
	{
		for (int i = poz; i <= this->length - 2; i++)
		{
			this->projects[i] = this->projects[i + 1];
		}
		this->length = this->length - 1;
	}
	
	return 1;
}

//function that checks if an instance of Project is duplicate
//in: the instance of Project that will be checked
//out: the position of the duplicate or -1 otherwise
int Repository::verifDuplicate(Project p)
{
	int len = this->length;
	for (int i = 0; i < len; i++)
		if ((p.getNrBranches() == this->projects[i].getNrBranches()) && (strcmp(p.getPath(), this->projects[i].getPath()) == 0) && (p.getNrCommits() == projects[i].getNrCommits()))
			return i;
	return -1;
}

//getter that returns the array of Projects
Project * Repository::getAll()
{
	return this->projects;
}

//setter for Repository
void Repository::setAll(Project * p, int l)
{
	this->length = l;
	for (int i = 0; i < this->length; i++) {

		this->projects[i] = p[i];

	}
}

//function that returns the length of Repository
int Repository::getLen()
{
	return this->length;
}

//function that updates the info about an instance of Project
//in: the index of the Project that will be updated and the new info
//out: the instance of Project with updated info
int Repository::updateProject(int index, Project newP)
{
	this->getAll()[index].setPath(newP.getPath());
	this->getAll()[index].setNrBranches(newP.getNrBranches());
	this->getAll()[index].setNrCommits(newP.getNrCommits());
	return 1;

}
