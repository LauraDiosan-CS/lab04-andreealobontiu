#pragma once
#include "teste.h"
#include "Project.h"
#include "Repository.h"
#include "assert.h"
#include <iostream>
using namespace std;

//tests for the Project class
void testProject()
{
	Project p1 = Project();

	assert(p1.getPath() == NULL);
	assert(p1.getNrBranches() == 0);
	assert(p1.getNrCommits() == 0);

	Project p2 = Project("abcd/a", 5,3);
	assert(strcmp(p2.getPath(), "abcd/a") == 0);
	assert(p2.getNrBranches() == 5);
	assert(p2.getNrCommits() == 3);

	Project p3 =Project(p2);
	assert(strcmp(p3.getPath(), "abcd/a") == 0);
	assert(p3.getNrBranches() == 5);
	assert(p3.getNrCommits() == 3);

	cout << "Project tests passed" << endl;
}

//tests for the Repository class
void testRepository()
{
	Repository repo;
	Project p2 = Project("abcd/a", 5, 3);
	Project p1 = Project("local", 10, 6);
	repo.addProject(p1);
	repo.addProject(p2);
	assert(repo.getLen() == 2);
	assert(p2.compare(repo.getAll()[1]) == true);
	assert(p1.compare(repo.getAll()[0]) == true);
	cout << "Repository tests passed" << endl;
}

//tests for the Service class
void testService()
{
	Repository repo;
	Service serv{ &repo };
	Project p2 = Project("abcd/a", 5, 3);
	Project p1 = Project("andreea/scoala", 10, 6);
	serv.addProject(p2);
	serv.addProject(p1);
	assert(serv.addProject(p1) == 1);
	assert(serv.addProject(p2) == 1);
	assert(serv.updateProject(0, p2) == 1);
	assert(serv.getLen() == 2);
	assert(p2.compare(serv.getAll()[0]) == true);
	assert(p1.compare(serv.getAll()[1]) == true);
	serv.delProject("andreea/scoala");
	assert(serv.getLen() == 1);

	cout << "Service tests passed" << endl;
}
