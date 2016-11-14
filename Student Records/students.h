#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
#include <conio.h>
#include <algorithm> 
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int scoreNum = 10;

struct constantStuData{
	const string 
		fresh = "Freshman", soph = "Sophomore", 
		junior = "Junior", senior = "Senior", 
		lib = "Liberal Arts", gs = "General Science";
};

struct Student {
	string name, clas, major;
	int median, mode, standardDeviation;
	double mean;
	int score[scoreNum];
};

class StudentData {
private:
	int numOfItem;
public:
	vector<Student> studentRecord;
	StudentData(){}
	vector<Student> createRecord();
	void printRecord(vector<Student> record, ostream &of = cout);
	int randomInt(int);
	double calculateSum(int i);
	int calcMedian(vector<Student> studentRecord, int i);
	int calcMode(vector<Student> studentRecord, int i);
	int calcDev(vector<Student> studentRecord, int i, double mean);
};

#endif