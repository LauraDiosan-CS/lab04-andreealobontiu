#pragma once
#include "teste.h"
#include <iostream>
#include <string.h>
#include "assert.h"
#include "Project.h"
#include "Service.h"
#include "Repository.h"

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
	repo.addProject("abcd/a", 5, 3);
	repo.addProject("local", 10, 6);
	assert(repo.getLen() == 2);
	assert(p2.compare(repo.getAll()[0]) == true);
	assert(p1.compare(repo.getAll()[1]) == true);
	
	cout << "Repository tests passed" << endl;
}

//tests for the Service class
void testService()
{
	Repository repo;
	Service serv;
	Project p2 = Project("abcd/a", 5, 3);
	Project p1 = Project("master", 10, 6);
	serv.addProject("abcd/a", 5, 3);
	serv.addProject("andreea/scoala", 10, 6);
	serv.addProject("abcd/a", 15, 20);
	serv.addProject("local", 10, 8);
	assert(serv.addProject("abcd/a", 5, 3) == 1);
	assert(serv.addProject("andreea/scoala", 10, 6) == 1);
	assert(serv.updateProject(0, p1) == 1);
	assert(serv.getLen() == 4);
	assert(p2.compare(serv.getAll()[0]) == false);
	assert(p1.compare(serv.getAll()[1]) == false);
	serv.delProjectPath("andreea/scoala");
	assert(serv.getLen() == 3);

	serv.delProject(1);
	assert(serv.getLen() == 2);
	serv.addProject("master", 7, 0);
	serv.addProject("andreea/scoala", 5, 26);

	assert(serv.filterByPath("master") == 2);
	assert(serv.filterByCommits(8) == 1);
	assert(serv.filterGreaterBranches(8) == 2);
	assert(serv.filterCommitsInterval(0, 5) == 1);
	assert(serv.maxBranches() == 10);
	assert(serv.minCommits() == 0);
	assert(serv.sumBranches() == 32);
	assert(serv.sumCommits() == 40);

	

	cout << "Service tests passed" << endl;
}
