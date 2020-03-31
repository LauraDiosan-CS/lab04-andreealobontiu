#include "UI.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//function that prints the menu on the console
void printMenu()
{
	cout << "0. Exit" << endl;
	cout << "1. Add a project" << endl;
	cout << "2. Update a project" << endl;
	cout << "3. Show the project list" << endl;
	cout << "4. Delete projects by path" << endl;
	cout << "5. Delete project by index" << endl;
	cout << "6. Delete projects by the number of branches" << endl;
	cout << "7. Filter projects by path" << endl;
	cout << "8. Filter projects by the number of commits" << endl;
	cout << "9. Display the projects that have more braches than a given value" << endl;
	cout << "10. Display the projects that have the number of commits in a given interval [a,b]" << endl;
	cout << "11. Display the projects with the greatest number of branches" << endl;
	cout << "12. Display the projects with the least number of commits" << endl;
	cout << "13. Display the total number of commits" << endl;
	cout << "14. Display the total number of branches" << endl;
}

//function that runs the program
void UI::interFace()
{

	int option;
	bool stop = true;
	Repository repo;
	
	this->serv.addProject("abcd/a", 50, 3);
	this->serv.addProject("andreea/scoala", 50, 18);
	this->serv.addProject("abcd/b", 5, 8);
	this->serv.addProject("andreea/scoala", 6, 0);

	while (stop)
	{
		printMenu();
		cout << "Choose an option: ";
		cin >> option;
		if (option==0) //option 0
		{
			stop = false;
			system("pause");
			cout << "EXITED" << endl;
			
		}
		else if (option==1) //option 1
		{
			char* path = new char[50];
			int branches, commits;
			cout << "Give a path: ";
			cin >> path;
			cout << "Give the number of branches: ";
			cin >> branches;
			cout << "Give the number of commits: ";
			cin >> commits;

			
			if (serv.addProject(path, branches, commits) == 1)
			{
				cout << "The project has been added" << endl << endl;
			}
			else
				cout << "The project already exists" << endl << endl;

		}
		else if (option==2) //option 2
		{
			int index, newBranches, newCommits;
			char* newPath = new char[50];

			serv.readProjects();
			cout << "Enter the index of the project you want to update: ";
			cin >> index;
			if (index < serv.getLen())
			{
				cout << "Enter the new path: ";
				cin >> newPath;
				cout << "Enter the new number of branches: ";
				cin >> newBranches;
				cout << "Enter he new number of commits: ";
				cin >> newCommits;

				Project newP = Project(newPath, newBranches, newCommits);
				serv.updateProject(index, newP);
			}
			else
				cout << "Index out of range";
		}
		else if (option==3)  //option 3
		{
			serv.readProjects();
		}
		else if (option==4) //option 4
		{
			char* delPath = new char[50];
			cout << "Enter a path: ";
			cin >> delPath;
			serv.delProjectPath(delPath);
			if (serv.delProjectPath(delPath) == 0)
			{
				cout << "The path that you gave does not exist" << endl;
			}
		}
		else if (option==5)     //option 5
		{
			serv.readProjects();
			int index;
			cout << "Enter the index of the project you want to delete: ";
			cin >> index;
			if (index < serv.getLen())
			{
				serv.delProject(index);
			}
			else
				cout << "Index out of range";
		}
		else if (option==6)     //option 6
		{
			int delBranches;
			cout << "Enter the number of branches: ";
			cin >> delBranches;
			serv.delProjectBranches(delBranches);
			if (serv.delProjectBranches(delBranches) == 0)
			{
				cout << "The number of branches that you gave does not exist" << endl;
			}
		}
		else if (option==7)    //option 7
		{
			char* countPath = new char[50];
			cout << "Enter a path: ";
			cin >> countPath;
			int count1 = serv.filterByPath(countPath);
			if (count1 == 0)
				cout << "There are no projects with that path" << endl;
		}
		else if (option==8)    //option 8
		{
			int countCommits;
			cout << "Enter the number of commits: ";
			cin >> countCommits;
			int count2 = serv.filterByCommits(countCommits);
			if (count2 == 0)
				cout << "There are no projects with that number of commits" << endl;
		}
		else if (option==9)     //option 9
		{
			int value;
			cout << "Enter a value for the number of branches: ";
			cin >> value;
			int count3 = serv.filterGreaterBranches(value);
			if (count3 == 0)
				cout << "There are no projects with that number of branches greater than that value" << endl;
		}
		else if (option==10)      //option 10
		{
			int end1, end2, count4;
			cout << "Enter the low end: ";
			cin >> end1;
			cout << "Enter the high end: ";
			cin >> end2;
			count4 = serv.filterCommitsInterval(end1, end2);
			if (count4 == 0)
				cout << "There are no projects with that number of commits between those values" << endl;
		}
		else if (option==11)      //option 11
		{
			int max = serv.maxBranches();

			for (int i = 0; i < serv.getLen(); i++)
			{
				if (serv.getAll()[i].getNrBranches() == max)
				{
					cout << serv.getAll()[i].toString() << endl;
				}
		}
		}
		else if (option==12)  //option 12
		{
			int min = serv.minCommits();

			for (int i = 0; i < serv.getLen(); i++)
			{
				if (serv.getAll()[i].getNrCommits() == min)
				{
					cout << serv.getAll()[i].toString() << endl;
				}
			}
		}
		else if (option==13)    //option 13
		{
			cout << serv.sumBranches() << endl;
		}
		else if (option==14)   //option 14
		{
		cout << serv.minCommits() << endl;
		}
		

		
	}
}
