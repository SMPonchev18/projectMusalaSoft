#pragma once
#include <iostream>
#include <string>
#include <iomanip> 


struct STUDENTS {

	std::string StuFirstName;
	std::string StuSurname;
	std::string StuClass;
	std::string StuRole;
	std::string StuEmail;
	int studentID;

};

struct TEACHERS {

	std::string teacherName;
	std::string teacherSubname;
	std::string teacherEmail;
	int teacherID;
	int teachedTeamsNum = 0;
};
struct TEAMS
{
	std::string teamName;
	std::string teamDescription;
	struct STUDENTS Backend;
	struct STUDENTS Frontend;
	struct STUDENTS QA;
	struct STUDENTS Master;
	struct TEACHERS teamTeacher;
	int teamID;
};

struct SCHOOLS {

	std::string schoolName;
	std::string city;
	std::string address;
	int schoolID;
	struct STUDENTS studentsInSchool[10];
	struct TEACHERS teachersInSchool[10];
	struct TEAMS teamsInSchool[10];
};

int getIndexById(STUDENTS* students, int SCounter, int ID);

void createStudent(STUDENTS* students, int& SCount, int& maxStudentID, STUDENTS test);

void updateStudent(STUDENTS* students, int SCount, int studentID, STUDENTS test);

void deleteStudent(STUDENTS* students, int& SCount, int studentID);

STUDENTS getStudent(STUDENTS* students, int& SCount, int studentID);

void createStudentMenu(STUDENTS* students, int& SCount, int& maxStudentID);

void showStudents(STUDENTS* students, int& SCount, int& maxStudentID);

void showStudentsPerRole(STUDENTS* students, int& SCount, int& maxStudentID, std::string searchedRole);

void deleteStudentMenu(STUDENTS* students, int& SCount, int& maxStudentID);

void editStudentMenu(STUDENTS* students, int& SCount);

bool showStudentMenu(STUDENTS* students, int& SCount, int& maxStudentID);

int getTeacherIndexByID(TEACHERS* teachers, int& TCounter, int teacherID);

void createTeacher(TEACHERS* teachers, int& TCounter, int& maxTeacherID, TEACHERS test);

void updateTeacher(TEACHERS* teachers, int TCounter, int teacherID, TEACHERS test);

void deleteTeacher(TEACHERS* teachers, int& TCounter, int teacherID);

TEACHERS getTeacher(TEACHERS* teachers, int& TCounter, int teacherID);

void createTeacherMenu(TEACHERS* teachers, int& TCounter, int& maxTeacherID, TEAMS* teams, int& teamCount, int& maxTeamID);

void showTeachers(TEACHERS* teachers, int& TCounter, int& maxTeacherID);

void deleteTeacherMenu(TEACHERS* teachers, int& TCounter, int& maxTeacherID);

void editTeacherMenu(TEACHERS* teachers, int& TCounter);

bool showTeacherMenu(TEACHERS* teachers, int& TCounter, int& maxTeacherID, TEAMS* teams, int& teamCount, int& maxTeamID);

int getTeamIndexByID(TEAMS* teams, int& teamsCount, int teamID);

void createTeam(TEAMS* teams, int& teamsCount, int& maxTeamID, TEAMS test);

void updateTeam(TEAMS* teams, int teamsCount, int teamID, TEAMS test);

void deleteTeam(TEAMS* teams, int& teamsCount, int teamID);

TEAMS getTeam(TEAMS* teams, int& teamsCount, int teamID);

void createTeamMenu(TEAMS* teams, int& teamsCount, int& maxTeamID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID);

void showTeams(TEAMS* teams, int& teamsCount, int& maxTeamID);

void deleteTeamMenu(TEAMS* teams, int& teamsCount, int& maxTeamID);

void editTeamMenu(TEAMS* teams, int& teamsCount);

bool showTeamMenu(TEAMS* teams, int& teamCount, int& maxTeamID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID);

int getSchoolIndexByID(SCHOOLS* schools, int& schoolCount, int schoolID);

void createSchool(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, SCHOOLS test);

void updateSchool(SCHOOLS* schools, int schoolCount, int schoolID, SCHOOLS test);

void deleteSchool(SCHOOLS* schools, int& schoolCount, int schoolID);

SCHOOLS getSchool(SCHOOLS* schools, int& schoolCount, int schoolID);

void createSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum);

void showSchools(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum);

void deleteSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID);

void editSchoolMenu(SCHOOLS* schools, int& schoolCount);

bool showSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum);

bool mainMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& TCounter, int& maxTeacherID, STUDENTS* students, int& SCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID, int& studentsInSchoolNum, int& teachersInSchoolNum, int& teamsInSchoolNum);