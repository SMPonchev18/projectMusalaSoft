#include <iostream>
#include <string>
#include <iomanip> 
#include "Funcs.h"

using namespace std;



int getIndexById(STUDENTS* students, int SCounter, int ID)
{

	for (int i = 0; i < SCounter; i++)
	{
		if (students[i].studentID == ID)
		{
			return i;
		}
	}
	return -1;
}

void createStudent(STUDENTS* students, int& SCount, int& maxStudentID, STUDENTS test)

{
	test.studentID = maxStudentID++;
	students[SCount] = test;
	SCount++;
}
void updateStudent(STUDENTS* students, int SCount, int studentID, STUDENTS test)
{
	int index0 = getIndexById(students, SCount, studentID);
	students[index0] = test;
}
void deleteStudent(STUDENTS* students, int& SCount, int studentID)
{
	int index1 = getIndexById(students, SCount, studentID);

	for (int i = index1; i < SCount - 1; i++)
	{
		students[i] = students[i + 1];
	}
	SCount--;
}
STUDENTS getStudent(STUDENTS* students, int& SCount, int studentID)
{
	int index2 = getIndexById(students, SCount, studentID);
	return students[index2];
}
void createStudentMenu(STUDENTS* students, int& SCount, int& maxStudentID)
{
	STUDENTS addStudent;
	cout << "What is the student's first name?" << endl;
	cin >> addStudent.StuFirstName;
	cout << "What is the student's Last name?" << endl;
	cin >> addStudent.StuSurname;
	cout << "What is the student's class?" << endl;
	cin >> addStudent.StuClass;
	cout << " What is the student's role? Pick one out of the four:" << endl;
	cout << " -Master" << endl;
	cout << " -Frontend" << endl;
	cout << " -QA" << endl;
	cout << " -Backend" << endl;
	cin >> addStudent.StuRole;
	cout << "What is the student's email?" << endl;
	cin >> addStudent.StuEmail;
	createStudent(students, SCount, maxStudentID, addStudent);
}
void showStudents(STUDENTS* students, int& SCount, int& maxStudentID)
{
	if (SCount > 0)
	{
		cout << "All the students added to the list so far : " << endl;
	}
	else
	{
		cout << "No students have been added to the list yet. " << endl << endl;
	}
	for (int i = 0; i < SCount; i++)
	{
		cout << "ID : ";
		cout << students[i].studentID << " | Student Name : " << students[i].StuFirstName << " | Student Surname : " << students[i].StuSurname << " | Student Class: " << students[i].StuClass << " | Student Role: " << students[i].StuRole << " | Student E-mail: " << students[i].StuEmail << endl;
	}
	cout << endl;
}
void showStudentsPerRole(STUDENTS* students, int& SCount, int& maxStudentID, string searchedRole)
{
	int studentsWithRole = 0;
	if (SCount > 0)
	{
		cout << "All the students added to the list so far : " << endl;
	}
	else
	{
		cout << "No students have been added to the list yet. " << endl << endl;
	}
	for (int i = 0; i < SCount; i++)
	{
		if (students[i].StuRole == searchedRole)
		{
			studentsWithRole++;
			cout << "ID : ";
			cout << students[i].studentID << " | Student Name : " << students[i].StuFirstName << " | Student Surname : " << students[i].StuSurname << " | Student Class: " << students[i].StuClass << " | Student E-mail: " << students[i].StuEmail << endl;
		}
	}
	cout << endl;
	if (studentsWithRole == 0)
	{
		cout << "No " << searchedRole << " students have been added to the list yet";
	}
}
void deleteStudentMenu(STUDENTS* students, int& SCount, int& maxStudentID)
{
	if (SCount > 0)
	{
		int delID;
		cout << "Enter the ID of the student you want to delete : ";
		cin >> delID;
		deleteStudent(students, SCount, delID);
	}
	else
	{
		cout << "No students have been added to the list yet. " << endl;
	}
}
void editStudentMenu(STUDENTS* students, int& SCount)
{
	if (SCount > 0)
	{
		int editID;
		cout << "Enter the ID of the student you want to change : ";
		cin >> editID;
		STUDENTS editStudent = getStudent(students, SCount, editID);
		cout << "1. Student Name " << endl;
		cout << "2. Student Surname  " << endl;
		cout << "3. Student Class    " << endl;
		cout << "4. Student Role     " << endl;
		cout << "5. Student E-mail    " << endl;
		int editChoice;
		cin >> editChoice;
		switch (editChoice)
		{
		case 1:
			cout << " Choose a new student first name " << endl;
			cin >> editStudent.StuFirstName;
			updateStudent(students, SCount, editID, editStudent);
			break;

		case 2:
			cout << " Choose a new student surname " << endl;
			cin >> editStudent.StuSurname;
			updateStudent(students, SCount, editID, editStudent);
			break;

		case 3:
			cout << " Choose a new student class " << endl;
			cin >> editStudent.StuClass;
			updateStudent(students, SCount, editID, editStudent);
			break;

		case 4:
			cout << " Choose a new student role " << endl;
			cout << " -Master" << endl;
			cout << " -Frontend" << endl;
			cout << " -QA" << endl;
			cout << " -Backend" << endl;
			cin >> editStudent.StuRole;
			updateStudent(students, SCount, editID, editStudent);
			break;
		case 5:
			cout << " Choose a new student email " << endl;
			cin >> editStudent.StuEmail;
			updateStudent(students, SCount, editID, editStudent);
			break;
		default:
			cout << "The number you chose was not valid!" << endl;
			break;
		}
	}
	else
	{
		cout << "No students have been added to the list yet. " << endl << endl;
	}
}
bool showStudentMenu(STUDENTS* students, int& SCount, int& maxStudentID)
{
	int choice;
	cout << "**************************" << endl;;
	cout << "** 1. Show all students **" << endl;
	cout << "** 2. Add a student     **" << endl;
	cout << "** 3. Edit a student    **" << endl;
	cout << "** 4. Delete a student  **" << endl;
	cout << "** 6. Exit menu         **" << endl;
	cout << "**************************" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		showStudents(students, SCount, maxStudentID);
		break;

	case 2:
		createStudentMenu(students, SCount, maxStudentID);
		break;

	case 3:
		editStudentMenu(students, SCount);
		break;

	case 4:
		deleteStudentMenu(students, SCount, maxStudentID);
		break;
	case 6:
		return false;

	default:
		cout << "The number you chose was not valid!" << endl;
		return 0;
	}
	return true;
}
int getTeacherIndexByID(TEACHERS* teachers, int& TCounter, int teacherID)
{
	for (int j = 0; j < TCounter; j++)
	{
		if (teachers[j].teacherID == teacherID)
		{
			return j;
		}
	}
	return -1;
}
void createTeacher(TEACHERS* teachers, int& TCounter, int& maxTeacherID, TEACHERS test)
{
	test.teacherID = maxTeacherID++;
	teachers[TCounter] = test;
	TCounter++;
}
void updateTeacher(TEACHERS* teachers, int TCounter, int teacherID, TEACHERS test)
{
	int index3 = getTeacherIndexByID(teachers, TCounter, teacherID);
	teachers[index3] = test;
}
void deleteTeacher(TEACHERS* teachers, int& TCounter, int teacherID)
{
	int index4 = getTeacherIndexByID(teachers, TCounter, teacherID);
	for (int i = index4; i < TCounter - 1; i++)
	{
		teachers[i] = teachers[i + 1];
	}
	TCounter--;
}
TEACHERS getTeacher(TEACHERS* teachers, int& TCounter, int teacherID)
{
	int index5 = getTeacherIndexByID(teachers, TCounter, teacherID);
	return teachers[index5];
}
void createTeacherMenu(TEACHERS* teachers, int& TCounter, int& maxTeacherID, TEAMS* teams, int& teamCount, int& maxTeamID)
{
	TEACHERS addTeacher;
	cout << " Whats the teacher's first name?  " << endl;
	cin >> addTeacher.teacherName;
	cout << " Whats the teacher's second name?  " << endl;
	cin >> addTeacher.teacherSubname;
	cout << " Whats the teacher's email? " << endl;
	cin >> addTeacher.teacherEmail;
	createTeacher(teachers, TCounter, maxTeacherID, addTeacher);
}
void showTeachers(TEACHERS* teachers, int& TCounter, int& maxTeacherID)
{
	if (TCounter > 0)
	{
		cout << "All the teachers added to the list so far : " << endl;
	}
	else
	{
		cout << "No teachers have been added to the list yet. " << endl << endl;
	}
	for (int i = 0; i < TCounter; i++)
	{
		cout << "ID : " << teachers[i].teacherID << " | Teacher Name : " << teachers[i].teacherName << " | Teacher surname : " << teachers[i].teacherSubname << " | Teacher E-mail: " << teachers[i].teacherEmail << endl;
	}
	cout << endl;
}
void deleteTeacherMenu(TEACHERS* teachers, int& TCounter, int& maxTeacherID)
{
	if (TCounter > 0)
	{
		int delID;
		cout << "Enter the ID of the teacher you want to delete : ";
		cin >> delID;
		deleteTeacher(teachers, TCounter, delID);
	}
	else
		cout << "No teachers have been added to the list yet. " << endl << endl;
}
void editTeacherMenu(TEACHERS* teachers, int& TCounter)
{
	if (TCounter > 0)
	{
		int editID;
		cout << "Enter the ID of the teacher you want to change : ";
		cin >> editID;
		TEACHERS editTeacher = getTeacher(teachers, TCounter, editID);
		cout << "1. Teacher Name: " << endl;
		cout << "2. Teacher Surname: " << endl;
		cout << "3. Teacher E-mail: " << endl;
		cout << "Choose what information about the teacher you want to change : ";
		int editChoice;
		cin >> editChoice;
		switch (editChoice)
		{
		case 1:
			cout << " Choose a new teacher name : ";
			cin >> editTeacher.teacherName;
			updateTeacher(teachers, TCounter, editID, editTeacher);
			break;
		case 2:
			cout << "Choose a new teacher surname: ";
			cin >> editTeacher.teacherSubname;
			updateTeacher(teachers, TCounter, editID, editTeacher);
			break;
		case 3:
			cout << "Choose  a new teacher email : ";
			cin >> editTeacher.teacherEmail;
			updateTeacher(teachers, TCounter, editID, editTeacher);
			break;
		default:
			cout << "The number you chose was not valid!" << endl;
			break;
		}
	}
	else
	{
		cout << "No teachers have been added to the list yet. " << endl << endl;
	}
}
bool showTeacherMenu(TEACHERS* teachers, int& TCounter, int& maxTeacherID, TEAMS* teams, int& teamCount, int& maxTeamID)
{
	int menuChoice;
	cout << "******************************"<<endl;
	cout << "** --- TEACHER MENU ---     **" << endl;
	cout << "** 1. Show all teachers     **" << endl;
	cout << "** 2. Add a teacher         **" << endl;
	cout << "** 3. Edit a teacher        **" << endl;
	cout << "** 4. Delete a teacher      **" << endl;
	cout << "** 5. Exit Menu             **" << endl;
	cout << "******************************"<<endl;
	cout << "Enter your choice: ";
	cin >> menuChoice;
	switch (menuChoice)
	{
	case 1:
		showTeachers(teachers, TCounter, maxTeacherID);
		break;

	case 2:
		createTeacherMenu(teachers, TCounter, maxTeacherID, teams, TCounter, maxTeamID);
		break;

	case 3:
		editTeacherMenu(teachers, TCounter);
		break;

	case 4:
		deleteTeacherMenu(teachers, TCounter, maxTeacherID);
		break;
	case 5:
		return false;
	default:
		cout << "The number you choose was not valid!" << endl;
		return 0;
	}
	return true;
}
int getTeamIndexByID(TEAMS* teams, int& teamsCount, int teamID)
{
	for (int i = 0; i < teamsCount; i++)
	{
		if (teams[i].teamID == teamID)
		{
			return i;
		}
	}
	return -1;
}
void createTeam(TEAMS* teams, int& teamsCount, int& maxTeamID, TEAMS test)
{
	test.teamID = maxTeamID++;
	teams[teamsCount] = test;
	teamsCount++;
}

void updateTeam(TEAMS* teams, int teamsCount, int teamID, TEAMS test)
{
	int index6 = getTeamIndexByID(teams, teamsCount, teamID);
	teams[index6] = test;
}
void deleteTeam(TEAMS* teams, int& teamsCount, int teamID)
{

	int index7 = getTeamIndexByID(teams, teamsCount, teamID);

	for (int i = index7; i < teamsCount - 1; i++)
	{
		teams[i] = teams[i + 1];
	}
	teamsCount--;
}
TEAMS getTeam(TEAMS* teams, int& teamsCount, int teamID)
{
	int index8 = getTeamIndexByID(teams, teamsCount, teamID);
	return teams[index8];
}
void createTeamMenu(TEAMS* teams, int& teamsCount, int& maxTeamID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID)
{
	TEAMS addTeam;
	cout << " Team Name  ";
	cin >> addTeam.teamName;

	cout << "Team descritpion ";
	cin >> addTeam.teamDescription;

	cout << "Which back-end developer is in the team?";
	showStudentsPerRole(students, SCount, maxStudentID, "Backend");

	cout << "Which ID?";
	int backEndDevID;
	cin >> backEndDevID;

	STUDENTS Backend = getStudent(students, SCount, backEndDevID);
	addTeam.Backend = Backend;

	cout << "Which front-end developer is in the team?";
	showStudentsPerRole(students, SCount, maxStudentID, "Frontend");

	cout << "Which ID?";
	int frontEndDevID;
	cin >> frontEndDevID;

	STUDENTS Frontend = getStudent(students, SCount, frontEndDevID);
	addTeam.Frontend = Frontend;

	cout << "Which quality engineer is in the team?";
	showStudentsPerRole(students, SCount, maxStudentID, "QA");
	cout << "Which ID?";

	int QADevID;
	cin >> QADevID;

	STUDENTS qa = getStudent(students, SCount, QADevID);
	addTeam.QA = qa;

	cout << "Which scrum Master is in the team?";
	showStudentsPerRole(students, SCount, maxStudentID, "Master");
	cout << "Which ID?";
	int masterID;
	cin >> masterID;

	STUDENTS Master = getStudent(students, SCount, masterID);
	addTeam.Master = Master;
	cout << "Which teacher is in the team?";

	showTeachers(teachers, TCounter, maxTeacherID);
	cout << "Which ID?";

	int editID;
	cin >> editID;

	TEACHERS tt = getTeacher(teachers, TCounter, editID);
	addTeam.teamTeacher = tt;

	createTeam(teams, teamsCount, maxTeamID, addTeam);
}
void showTeams(TEAMS* teams, int& teamsCount, int& maxTeamID)
{
	if (teamsCount > 0)
	{
		cout << "All the teams added to the list so far : " << endl;
	}
	else
	{
		cout << "No teams have been added to the list yet. " << endl << endl;
	}

	for (int j = 0; j < teamsCount; j++)
	{
		cout << "ID : ";
		cout << teams[j].teamID << " | Team Name : " << teams[j].teamName << " | Team Description : " << teams[j].teamDescription << " | Team Teacher: " << teams[j].teamTeacher.teacherName << endl;
	}
	cout << endl;
}
void deleteTeamMenu(TEAMS* teams, int& teamsCount, int& maxTeamID)
{
	if (teamsCount > 0)
	{
		int delID;
		cout << "Enter the ID of the team you want to delete : ";
		cin >> delID;
		deleteTeam(teams, teamsCount, delID);
	}
	else
	{
		cout << "No teams have been added to the list yet. " << endl << endl;
	}

}
void editTeamMenu(TEAMS* teams, int& teamsCount)
{
	if (teamsCount > 0)
	{
		int editID;
		cout << "Enter the ID of the team you want to change : ";
		cin >> editID;
		TEAMS editName = getTeam(teams, teamsCount, editID);
		cout << "1. Team Name" << endl;
		cout << "2. Description" << endl;
		cout << "Type the field you want to change : ";
		int editChoice;
		cin >> editChoice;
		switch (editChoice)
		{
		case 1:
			cout << " Choose a new team name : ";
			cin >> editName.teamName;
			updateTeam(teams, teamsCount, editID, editName);
			break;
		case 2:
			cout << "Choose a new team description: ";
			cin >> editName.teamDescription;
			updateTeam(teams, teamsCount, editID, editName);
			break;
		default:
			cout << "The number you choose was not valid!" << endl;
			break;
		}
	}
	else
	{
		cout << "No teams have been added to the list yet. " << endl << endl;
	}
}
bool showTeamMenu(TEAMS* teams, int& teamCount, int& maxTeamID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID)
{
	int choice;
	cout << "**********************" << endl;
	cout << "** 1.Show all teams **" << endl;
	cout << "** 2.Add a team     **" << endl;
	cout << "** 3.Edit a team    **" << endl;
	cout << "** 4.Delete a team  **" << endl;
	cout << "** 5.Exit Menu      **" << endl;
	cout << "**********************" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		showTeams(teams, teamCount, maxTeamID);
		break;
	case 2:
		createTeamMenu(teams, teamCount, maxTeamID, teachers, TCounter, maxTeacherID, students, SCount, maxStudentID);
		break;
	case 3:
		editTeamMenu(teams, teamCount);
		break;
	case 4:
		deleteTeamMenu(teams, teamCount, maxTeamID);
		break;
	case 5:
		return false;

	default: break;
		cout << "The number you choose was not valid!" << endl;
	}
	return true;
}
int getSchoolIndexByID(SCHOOLS* schools, int& schoolCount, int schoolID)
{

	for (int i = 0; i < schoolCount; i++)
	{
		if (schools[i].schoolID == schoolID)
		{
			return i;
		}
	}
	return -1;
}

void createSchool(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, SCHOOLS test)
{
	test.schoolID = maxSchoolID++;
	schools[schoolCount] = test;
	schoolCount++;
}

void updateSchool(SCHOOLS* schools, int schoolCount, int schoolID, SCHOOLS test)
{

	int index9 = getSchoolIndexByID(schools, schoolCount, schoolID);

	schools[index9] = test;

}

void deleteSchool(SCHOOLS* schools, int& schoolCount, int schoolID)
{
	int index10 = getSchoolIndexByID(schools, schoolCount, schoolID);
	for (int i = index10; i < schoolCount - 1; i++)
	{
		schools[i] = schools[i + 1];
	}
	schoolCount--;
}
SCHOOLS getSchool(SCHOOLS* schools, int& schoolCount, int schoolID)
{
	int index11 = getSchoolIndexByID(schools, schoolCount, schoolID);
	return schools[index11];
}
void createSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum)
{
	SCHOOLS addSchool;
	cout << " School Name:  ";
	cin >> addSchool.schoolName;
	cout << "City: ";
	cin >> addSchool.city;
	cout << "Address: ";
	cin >> addSchool.address;
	cout << " How many students study in this school? ";
	cin >> studentsInSchoolNum;
	showStudents(students, SCount, maxStudentID);
	for (int i = 0; i < studentsInSchoolNum; i++)
	{
		cout << " Which ID? ";
		int editedId;
		cin >> editedId;
		STUDENTS tt = getStudent(students, SCount, editedId);
		addSchool.studentsInSchool[i] = tt;
	}
	cout << "How many teachers teach in this school? ";
	cin >> teachersInSchoolNum;
	showTeachers(teachers, TCounter, maxTeacherID);
	for (int i = 0; i < teachersInSchoolNum; i++)
	{
		cout << "Which ID?";
		int editID;
		cin >> editID;
		TEACHERS tt = getTeacher(teachers, TCounter, editID);
		addSchool.teachersInSchool[i] = tt;
	}
	cout << "How many teams are there in this school?";
	cin >> teamsInSchoolNum;
	showTeams(teams, teamCount, maxTeamID);
	for (int i = 0; i < teamsInSchoolNum; i++)
	{
		cout << "Which ID?";
		int editID;
		cin >> editID;
		TEAMS tt = getTeam(teams, teamCount, editID);
		addSchool.teamsInSchool[i] = tt;
	}
	createSchool(schools, schoolCount, maxSchoolID, addSchool);
}
void showSchools(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum)
{
	if (schoolCount > 0)
	{
		cout << "All the schools added to the list so far : " << endl;
	}
	else
	{
		cout << "No schools have been added to the list yet. " << endl;
	}
	for (int j = 0; j < schoolCount; j++)
	{
		cout << "ID : ";
		cout << schools[j].schoolID << " | School Name : "
			<< schools[j].schoolName << " | School City : "
			<< schools[j].city << " | School Address : "
			<< schools[j].address << " | Teachers :";
		cout << endl;
		for (int i = 0; i < studentsInSchoolNum; i++)
		{
			cout << "ID : " << schools[j].studentsInSchool[i].studentID << " | Student Name : " << schools[j].studentsInSchool[i].StuFirstName << " | Student Surname : " << schools[j].studentsInSchool[i].StuSurname << " | Student Class : " << schools[j].studentsInSchool[i].StuClass << " | Student Role : " << schools[j].studentsInSchool[i].StuRole << " | Student E-mail: " << schools[j].studentsInSchool[i].StuEmail << endl;
		}
		for (int i = 0; i < teachersInSchoolNum; i++)
		{
			cout << "ID : ";
			cout << schools[j].teachersInSchool[i].teacherID << " | Teacher Name : " << schools[j].teachersInSchool[i].teacherName << " | Teacher Surname : " << schools[j].teachersInSchool[i].teacherSubname << " | Teacher E-mail : " << schools[j].teachersInSchool[i].teacherEmail << endl;
		}
		for (int i = 0; i < teamsInSchoolNum; i++)
		{
			cout << "ID : ";
			cout << schools[j].teamsInSchool[i].teamID << " | School Name : " << schools[j].teamsInSchool[i].teamName << " | School Description : " << schools[j].teamsInSchool[i].teamDescription << " | School Teacher : " << schools[j].teamsInSchool[i].teamTeacher.teacherName << endl;
		}
	}
}
void deleteSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID)
{
	if (schoolCount > 0)
	{
		int delID;
		cout << "Enter the ID of the school you want to delete : ";
		cin >> delID;
		deleteSchool(schools, schoolCount, delID);
	}
	else
	{
		cout << "No schools have been added to the list yet. " << endl;
	}
}
void editSchoolMenu(SCHOOLS* schools, int& schoolCount)
{
	if (schoolCount > 0)
	{
		int editID;
		cout << "Enter the ID of the school you want to change : ";
		cin >> editID;
		SCHOOLS editSchool = getSchool(schools, schoolCount, editID);
		cout << "1. School Name" << endl;
		cout << "2. City" << endl;
		cout << "3. Address" << endl;
		cout << "Type the field you want to change : ";
		int menuChoice;
		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
			cout << " Choose a new school name : ";
			cin >> editSchool.schoolName;
			updateSchool(schools, schoolCount, editID, editSchool);
			break;
		case 2:
			cout << "Choose a new school city: ";
			cin >> editSchool.city;
			updateSchool(schools, schoolCount, editID, editSchool);
			break;
		case 3:
			cout << "Choose a new school address : ";
			cin >> editSchool.address;
			updateSchool(schools, schoolCount, editID, editSchool);
			break;
		default:
			cout << "The number you choose was not valid!" << endl;
			break;
		}
	}
	else
	{
		cout << "No schools have been added to the list yet. " << endl;
	}
}
bool showSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum)
{
	int menuChoice;
	cout << "*******************************" << endl;
	cout << "** ---SCHOOL MENU---         **" << endl;
	cout << "** 1. Show all schools       **" << endl;
	cout << "** 2. Add a school           **" << endl;
	cout << "** 3. Edit a school          **" << endl;
	cout << "** 4. Delete a school        **" << endl;
	cout << "** 5. Exit Menu              **" << endl;
	cout << "*******************************" << endl;
	cout << "Enter your choice: ";
	cin >> menuChoice;
	switch (menuChoice)
	{
	case 1:
		showSchools(schools, schoolCount, maxSchoolID, studentsInSchoolNum, teachersInSchoolNum, teamsInSchoolNum);
		break;
	case 2:
		createSchoolMenu(schools, schoolCount, maxSchoolID, teachers, TCounter, maxTeacherID, students, SCount, maxStudentID, teams, teamCount, maxTeamID, studentsInSchoolNum, teachersInSchoolNum, teamsInSchoolNum);
		break;
	case 3:
		editSchoolMenu(schools, schoolCount);
		break;
	case 4:
		deleteSchoolMenu(schools, schoolCount, maxSchoolID);
		break;
	case 5:
		return false;
	default: break;
		cout << "The number you choose was not valid!" << endl;
	}
	return true;
}
bool mainMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum)
{
	int menuChoice;
	cout << " ***********************"<<endl;
	cout << " ** ---MAIN MENU---   **" << endl;
	cout << " ** 1. Students       **" << endl;
	cout << " ** 2. Teachers       **" << endl;
	cout << " ** 3. Teams          **" << endl;
	cout << " ** 4. Schools        **" << endl;
	cout << " ** 5. Exit           **" << endl;
	cout << " ***********************" << endl;
	cout << "Enter your choice: ";
	cin >> menuChoice;
	bool doShowMenu;
	switch (menuChoice)
	{
	case 1:

		do {
			doShowMenu = showStudentMenu(students, SCount, maxStudentID);
		} while (doShowMenu);
		break;

	case 2:

		do {
			doShowMenu = showTeacherMenu(teachers, TCounter, maxTeacherID, teams, teamCount, maxTeamID);
		} while (doShowMenu);
		break;

	case 3:
		do {
			doShowMenu = showTeamMenu(teams, teamCount, maxTeamID, teachers, TCounter, maxTeacherID, students, SCount, maxStudentID);
		} while (doShowMenu);
		break;

	case 4:
		do {
			doShowMenu = showSchoolMenu(schools, schoolCount, maxSchoolID, teachers, TCounter, maxTeacherID, students, SCount, maxStudentID, teams, teamCount, maxTeamID, studentsInSchoolNum, teachersInSchoolNum, teamsInSchoolNum);
		} while (doShowMenu);
		break;
	case 5:
		return false;

	default:
		cout << "The number is not valid!";
		return 0;
		break;
	}
	return true;
}
