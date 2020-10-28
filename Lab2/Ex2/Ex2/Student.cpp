#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>

void Student::SetName(char* name)
{
	nameStudent = name;
}

void Student::SetGradeMaths(float grade)
{
	if(grade>=1 && grade<=10)
		gradeMaths = grade;
}

void Student::SetGradeEngl(float grade)
{
	if (grade >= 1 && grade <= 10)
		gradeEngl = grade;
}

void Student::SetGradeHist(float grade)
{
	if (grade >= 1 && grade <= 10)
		gradeHist = grade;
}

char* Student::GetName()
{
	return nameStudent;
}

float Student::GetGradeMaths()
{
	return gradeMaths;
}

float Student::GetGradeEngl()
{
	return gradeEngl;
}

float Student::GetGradeHist()
{
	return gradeHist;
}

float Student::GetAvgGrade()
{
	return (gradeEngl+gradeHist+gradeMaths)/3;
}
