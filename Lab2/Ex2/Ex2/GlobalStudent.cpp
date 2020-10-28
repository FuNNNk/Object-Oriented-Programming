#include "Student.h"
#include <string.h>

int compareName(Student student1, Student student2)
{
	return strcmp(student1.nameStudent, student2.nameStudent);
}

int compareGradeMaths(Student student1, Student student2)
{
	if (student1.gradeMaths > student2.gradeMaths)
		return 1;
	else if (student1.gradeMaths < student2.gradeMaths)
		return -1;
	else return 0;
}

int compareGradeEngl(Student student1, Student student2)
{
	if (student1.gradeEngl > student2.gradeEngl)
		return 1;
	else if (student1.gradeEngl < student2.gradeEngl)
		return -1;
	else return 0;
}

int compareGradeHist(Student student1, Student student2)
{
	if (student1.gradeHist > student2.gradeHist)
		return 1;
	else if (student1.gradeHist < student2.gradeHist)
		return -1;
	else return 0;
}

int compareAvgGrade(Student student1, Student student2)
{
	if (student1.GetAvgGrade() > student2.GetAvgGrade())
		return 1;
	else if (student1.GetAvgGrade() < student2.GetAvgGrade())
		return -1;
	else return 0;
}
