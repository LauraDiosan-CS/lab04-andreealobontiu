#include "teste.h"
#include "Project.h"
#include  "Repository.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	Repository repo;
	testProject();
	testRepository();
	
	Project p1 = Project("abcd/a", 5, 3);
	p1.setPath("bbbb");
	
	repo.addProject(p1);
	
	cout << repo.getLen() << endl;
	cout << p1.toString()<<endl;
	system("pause");
	return 0;
}