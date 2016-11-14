#include "studentRecord.h"

StudentData studentdat;
ofstream outFile;

void printTitle() {
	cout
		<< "Student Records Program"
		<< "\n    by Nate Sobol\n\n";
}

void printMenu() {
	cout
		<< "\n1. Print Unsorted Records"
		<< "\n2. Print Sorted Records"
		<< "\n3. Exit Program"
		<< "\nEnter Choice: ";
}

void exeChoice() {
	while (true) {
		printMenu();
		int choice = getInRange(1, 3);
		if (choice == 1)
			printStudentRecord();
		else if (choice == 2) {
			printDeviatedRecord();
			sort(studentdat.studentRecord.begin(), studentdat.studentRecord.end(), compareElements);
		}
		else
			exit(0);
	}
}

void printStudentRecord() {
	studentdat.studentRecord = studentdat.createRecord();
	studentdat.printRecord(studentdat.studentRecord);
}

void printDeviatedRecord(){
	sort(studentdat.studentRecord.begin(), studentdat.studentRecord.end(), compareElements);
	cout << "\nSorting By Standard Deviation: \n\n";
	studentdat.printRecord(studentdat.studentRecord);
}

void printToFile() {
	outFile.open(string("StudentDat.txt"));
	studentdat.printRecord(studentdat.studentRecord, outFile);
}

bool compareElements(Student& comp1, Student& comp2) {
	return comp1.standardDeviation < comp2.standardDeviation;
}

double getNum() {
	double num;
	while (!(cin >> num)) {
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Please no letter: ";
	}
	cin.ignore(80, '\n');
	return num;
}

int getInt() {
	double num = getNum();
	while (num != int(num)) {
		cout << num << " isn't a integer. Try Again: ";
		num = getNum();
	}
	return int(num);
}

int getInRange(int startNum, int endNum) {
	// Input
	int num = getInt();

	// Validation
	while (num < startNum || num > endNum) {
		cout << "Number isn't in range. Try again: ";
		num = getNum();
	}

	// Return
	return num;
}