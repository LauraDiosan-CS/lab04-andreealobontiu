#include "Service.h"
#include <iostream>


using namespace std;

//default constructor for Service
Service::Service()
{
	Project* p = new Project[100];
	repo.setAll(p, 0);
	this->len = 0;
}

//parameter constructor for Service
//in: an instance of Repository with a Project list and length
//out:Service with the data sets
Service::Service(Repository r)
{
	Project* p = new Project[r.getLen()];
	repo.setAll(r.getAll(), r.getLen());
}

//destructor for Service, deallocates memory
Service::~Service()
{
	if (this->repo.getAll() != NULL) 
	{

		this->repo.setAll(NULL, 0);

	}
}

//getter that returns repo
Repository Service::getRepo()
{
	return this->repo;
}

//function that adds an instance of Project to Service
//in: an instance of Project
//out:- 
int Service::addProject(const char* g, int b, int c)
{
	
	this->repo.addProject(g, b, c);
	return 1;
}

//function that updates the info about an instance of Project
//in: the index of the Project that will be updated and the new info
//out: the instance of Project with updated info
int Service::updateProject(int index, Project newP)
{
	this->repo.updateProject(index, newP);
	return 1;
}

//function that removes an instance of Project from Service by path
//in: the path of the instance/s of Project to be removed
//out:-
int Service::delProjectPath(const char * path)
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int ok = 0;
	for (int i = 0; i < len; i++)
	{
		if (strcmp(projects[i].getPath(), path) == 0)
		{
			this->repo.delProject(projects[i]);
			ok = 1;
		}
	}
	return ok;
}

//function that removes an instance of Project from Service by index
//in: the index of the instance of Project to be removed
//out:-
void Service::delProject(int index)
{
	Project p = Project(this->repo.getAll()[index].getPath(), this->repo.getAll()[index].getNrBranches(), this->repo.getAll()[index].getNrCommits());
	this->repo.delProject(p);
}

//function that removes an instance of Project from Service by the number of branches
//in: the number of branches of the instance/s of Project to be removed
//out:-
int Service::delProjectBranches(int nrBranches)
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int ok = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNrBranches()==nrBranches)
		{
			this->repo.delProject(projects[i]);
			ok = 1;
		}
	}
	return ok;
}

//function that prints all the instances of Project that have a given path
//in:a path
//out: a list with all the instances with that path
int Service::filterByPath(const char * path)
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int filterCount = 0;

	for (int i=0; i<len; i++)
	{
		if (strcmp(projects[i].getPath(), path)==0)
		{
			filterCount++;
			cout << this->repo.getAll()[i].toString() << endl;
		}
	}

	return filterCount;
	
}

//function that prints all the instances of Project with a given number of commits
//in:a value for the number of commits
//out:a list with all the instances with that value of commits
int Service::filterByCommits(int nrCommits)
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int filterCount = 0;

	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNrCommits()==nrCommits)
		{
			filterCount++;
			cout << this->repo.getAll()[i].toString() << endl;
		}
	}

	return filterCount;
}

//function that prints all the instances of Project that have the number of branches greater than a given value
//in:a value for the number of branches
//out:a list with all the instances with the number of branches greater than the given value
int Service::filterGreaterBranches(int greaterThan)
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int filterCount = 0;

	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNrBranches() > greaterThan)
		{
			filterCount++;
			cout << this->repo.getAll()[i].toString() << endl;
		}
	}

	return filterCount;
}

//function that prints all the instances of Project that have the number of commits in a given interval
//in:the low and the high end of the interval
//out:a list with all the instances with the number of commits between those given ends
int Service::filterCommitsInterval(int a, int b)
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int filterCount = 0;

	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNrCommits()>=a && projects[i].getNrCommits()<=b)
		{
			filterCount++;
			cout << this->repo.getAll()[i].toString() << endl;
		}
	}

	return filterCount;
}

//function that returns the maximum value of branches from all Project instances
//in:-
//out: the maximum value
int Service::maxBranches()
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int max = 0;
	

	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNrBranches()>max )
		{
			
			max = projects[i].getNrBranches();
		}
	}
	return max;
}

//function that returns the minimum value of commits from all Project instances
//in:-
//out: the minimum value
int Service::minCommits()
{
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();
	int min = 1000000;
	

	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNrCommits() < min)
		{
			
			min = projects[i].getNrCommits();
		}
	}
	return min;
}

//function that sums all the numbers of commits
//in:-
//out: the sum of all commits
int Service::sumCommits()
{
	int sumC = 0;
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();

	for (int i = 0; i < len; i++)
	{
		sumC = sumC + projects[i].getNrCommits();
	}
	return sumC;
}

//function that sums all the numbers of branches
//in:-
//out: the sum of all branches
int Service::sumBranches()
{
	int sumB = 0;
	Project *projects = this->repo.getAll();
	int len = this->repo.getLen();

	for (int i = 0; i < len; i++)
	{
		sumB = sumB + projects[i].getNrBranches();
	}
	return sumB;
}

//function that prints on the console the whole list of instances of Project
//in: -
//out: a list on the console with all the projects added
void Service::readProjects()
{
	for (int i=0; i<this->repo.getLen(); i++)
	{
		cout<<this->repo.getAll()[i].toString()<<endl;
	}
}

//getter that returns the array of Projects
Project * Service::getAll()
{
	return this->repo.getAll();
}

//function that returns the length of the Project array
int Service::getLen()
{
	return this->repo.getLen();
}
