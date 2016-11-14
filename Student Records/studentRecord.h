#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include "students.h"



using namespace std;

// Prints Title
void printTitle();

// Prints Menu
void printMenu();

// Executes Choice
void exeChoice();

// Sort function
bool compareElements(Student& comp1, Student& comp2);

// Prints Unsorted Records
void printStudentRecord();

// Prints Deviated Sorted Records
void printDeviatedRecord();

double getNum();

int getInt();

int getInRange(int, int);

#endif