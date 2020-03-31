#include "teste.h"
#include "Project.h"
#include  "Repository.h"
#include "Service.h"
#include "UI.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	testService();
	testProject();
	testRepository();

	
	UI u;
	u.interFace();
	
	system("pause");
	return 0;
}