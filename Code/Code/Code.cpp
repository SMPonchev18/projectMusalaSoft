#include <iostream>
#include <string>
#include <iomanip> 
#include "Funcs.h"
using namespace std;



int main()
{
	int* SCount = new int(0);
	int* maxStudentID = new int(1);
	STUDENTS  students[10];
	int* TCounter = new int(0);
	int* maxTeacherID = new int(1);
	TEACHERS  teachers[10];
	int* schoolCount = new int(0);
	int* maxSchoolID = new int(1);
	SCHOOLS  schools[10];
	int* TeamCount = new int(0);
	int* maxTeamID = new int(1);
	TEAMS teams[10];
	int* studentsInSchoolNum = new int(0);
	int* teachersInSchoolNum = new int(0);
	int* teamsInSchoolNum = new int(0);
	bool doShowMenu;

	do {
		doShowMenu = mainMenu(schools, *schoolCount, *maxSchoolID, teachers, *TCounter, *maxTeacherID, students, *SCount, *maxStudentID, teams, *TeamCount, *maxTeamID, *studentsInSchoolNum, *teachersInSchoolNum, *teamsInSchoolNum);
	} while (doShowMenu);

}
