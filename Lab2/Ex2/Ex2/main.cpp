#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
	Student student, studentNou;
	student.SetGradeMaths(5.2f);
	student.SetGradeEngl(8.0f);
	student.SetGradeHist(10.0f);
	student.SetName((char*)"Alex");

	cout << "Notele: " <<student.GetGradeMaths() << " " << student.GetGradeEngl() << " " << student.GetGradeHist() << endl;
	cout << "Nota medie: "<<student.GetAvgGrade() << endl;
	cout << "Numele studentului: "<<student.GetName() << endl;

	studentNou.SetGradeMaths(6.2f);
	studentNou.SetGradeEngl(8.0f);
	studentNou.SetGradeHist(8.0f);
	studentNou.SetName((char*)"Teodor");
	
	cout << "Note comparate mate "<<compareGradeMaths(student, studentNou) << endl;
	cout << "Note comparate engleza " << compareGradeEngl(student, studentNou) << endl;
	cout << "Note comparate istorie " << compareGradeHist(student, studentNou) << endl;
	cout << "Note comparate avg " << compareAvgGrade(student, studentNou) << endl;
	cout << "Nume comparate " << compareName(student, studentNou) << endl;
	return 0;
}