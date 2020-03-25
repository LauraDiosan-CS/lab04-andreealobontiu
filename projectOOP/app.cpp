#include "teste.h"
#include "Project.h"
#include  "Repository.h"
#include "Service.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	Repository repo;
	Service serv{ &repo };
	testProject();
	testRepository();
	testService();
	
	Project p1 = Project("abcd/a", 5, 3);
	p1.setPath("bbbb");
	Project p2 = Project("ancd/b", 10, 8);
	Project p3 = Project("andreea/scoala", 2, 0);
	
	serv.addProject(p1);
	serv.addProject(p2);
	serv.addProject(p3);
	serv.updateProject(1, p1);
	
	serv.delProject("andreea/scoala");
	
	cout << serv.getLen() << endl;
	serv.readProjects();
	cout << endl;
	system("pause");
	return 0;
}
