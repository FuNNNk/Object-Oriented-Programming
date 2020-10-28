#pragma once
class Student {
	char* nameStudent;
	float gradeMaths, gradeEngl, gradeHist;
public:
	void SetName(char* name);
	void SetGradeMaths(float grade);
	void SetGradeEngl(float grade);
	void SetGradeHist(float grade);

	char* GetName();
	float GetGradeMaths();
	float GetGradeEngl();
	float GetGradeHist();
	float GetAvgGrade();

	friend int compareName(Student student1, Student student2);
	friend int compareGradeMaths(Student student1, Student student2);
	friend int compareGradeEngl(Student student1, Student student2);
	friend int compareGradeHist(Student student1, Student student2);
	friend int compareAvgGrade(Student student1, Student student2);
};