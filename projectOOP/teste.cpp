#pragma once
#include "teste.h"
#include "Project.h"
#include "Repository.h"
#include "assert.h"
#include <iostream>
using namespace std;

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

void testRepository()
{
	Repository repo;
	Project p2 = Project("abcd/a", 5, 3);
	Project p1 = Project("local", 10, 6);
	repo.addProject(p1);
	repo.addProject(p2);
	assert(repo.getLen() == 2);
	
	cout << "Repository tests passed" << endl;
}
