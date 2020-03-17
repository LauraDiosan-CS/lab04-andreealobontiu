#include "Repository.h"
#include <string>

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

int Repository::verifDuplicate(Project & p)
{
	for (int i = 0; i < this->length; i++)
		if ((p.getNrBranches() == this->projects[i].getNrBranches()) && (strcmp(p.getPath(), this->projects[i].getPath()) == 0) && (p.getNrCommits() == projects[i].getNrCommits()))
			return i;
	return -1;
}

Project * Repository::getAll()
{
	return this->projects;
}

int Repository::getLen()
{
	return this->length;
}
