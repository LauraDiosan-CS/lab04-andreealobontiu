#include "Service.h"

using namespace std;

//function that adds an instance of Project to Service
//in: an instance of Project
//out:- 
int Service::addProject(Project p)
{
	this->repo->addProject(p);
	return 1;
}

//function that updates the info about an instance of Project
//in: the index of the Project that will be updated and the new info
//out: the instance of Project with updated info
int Service::updateProject(int index, Project newP)
{
	this->repo->updateProject(index, newP);
	return 1;
}

//function that removes an instance of Project from Service
//in: the path of the instance of Project to be removed
//out:-
int Service::delProject(const char * path)
{
	Project *projects = this->repo->getAll();
	int len = this->repo->getLen();
	for (int i = 0; i < len; i++)
		if (strcmp(projects[i].getPath(), path)==0)
		{
			this->repo->delProject(projects[i]);
		}
		return 1;
}

//function that prints on the console the whole list of instances of Project
//in: -
//out: a list on the console with all the projects added
void Service::readProjects()
{
	for (int i=0; i<this->repo->getLen(); i++)
	{
		cout<<this->repo->getAll()[i].toString()<<endl;
	}
}

//getter that returns the array of Projects
Project * Service::getAll()
{
	return this->repo->getAll();
}

//function that returns the length of the Project array
int Service::getLen()
{
	return this->repo->getLen();
}
