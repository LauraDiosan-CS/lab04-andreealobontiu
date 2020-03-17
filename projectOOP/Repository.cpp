#include "Repository.h"
#include <string>

//function that adds an instance of Project to Repository
//in: an instance of Project
//out:- 
int Repository::addProject(Project & p)
{
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
int Repository::delProject(Project & p)
{
	int poz = verifDuplicate(p);
	if (poz != -1)
	{
		for (int i = poz; i <= this->length - 1; i++)
		{
			this->projects[i] = this->projects[i + 1];
		}
		this->length = this->length - 1;
		return 1;
	}
	else
		return 0;
}

//function that checks if an instance of Project is duplicate
//in: the instance of Project that will be checked
//out: the position of the duplicate or -1 otherwise
int Repository::verifDuplicate(Project & p)
{
	for (int i = 0; i < this->length; i++)
		if ((p.getNrBranches() == this->projects[i].getNrBranches()) && (strcmp(p.getPath(), this->projects[i].getPath()) == 0) && (p.getNrCommits() == projects[i].getNrCommits()))
			return i;
	return -1;
}

//getter that returns the array of Projects
Project * Repository::getAll()
{
	return this->projects;
}

//function that returns the length of Repository
int Repository::getLen()
{
	return this->length;
}
