#include "students.h"

double StudentData::calculateSum(int num){
	double total = 0 ;
	for (int i = 0; i < scoreNum; i++)
		total += studentRecord[num].score[i];
	return total;
}

int StudentData::calcMedian(vector<Student> record, int num){
	int scoreNumArr[scoreNum];
	for (int i = 0; i < scoreNum; i++){
		scoreNumArr[i] = studentRecord[num].score[i];
	}
	sort(scoreNumArr, scoreNumArr + scoreNum);

	return (scoreNumArr[4] + scoreNumArr[5]) / 2;
}

int StudentData::calcMode(vector<Student> record, int num){
	int scoreArr[scoreNum];
	int count = 0, highScore = 0, mode = 0;
	
	for (int i = 0; i < scoreNum; i++) {
		scoreArr[i] = studentRecord[num].score[i];
	}
	sort(scoreArr, scoreArr + scoreNum);

	int modeArr = scoreArr[0];
	for (int i = 0; i < scoreNum-1; i++) {
		if (scoreArr[i] == scoreArr[i + 1]) {
			count++;
			if (count > highScore) {
				highScore = count;
				modeArr = scoreArr[i];
			}
		}
		else
			count = 0;
	}
	if (modeArr != scoreArr[0])
		return modeArr;
	else
		return mode = studentRecord[num].mean;
}

int StudentData::calcDev(vector<Student> record, int num, double mean){

	int deviationTotal = 0;
	int devArr[scoreNum];
	for (int i = 0; i < scoreNum; i++) {
		devArr[i] = studentRecord[num].score[i];
	}

	for (int i = 0; i < scoreNum; i++) {
		deviationTotal += (devArr[i] - mean)*(devArr[i] - mean);
	}

	return sqrt(deviationTotal / scoreNum);
}

int StudentData::randomInt(int i) {
	return i = rand() % 99;
	
}

vector<Student> StudentData::createRecord(){
	constantStuData csd;

	studentRecord.resize(20);
	studentRecord[0].name = "Maria Sanderson";
	studentRecord[0].clas = csd.fresh;
	studentRecord[0].major = csd.lib;

	studentRecord[1].name = "Adrian Stewart";
	studentRecord[1].clas = csd.soph;
	studentRecord[1].major = csd.lib;

	studentRecord[2].name = "Stephen Churchill";
	studentRecord[2].clas = csd.junior;
	studentRecord[2].major = csd.gs;

	studentRecord[3].name = "Sonia Mackenzie";
	studentRecord[3].clas = csd.senior;
	studentRecord[3].major = csd.lib;

	studentRecord[4].name = "Nicholas McDonald";
	studentRecord[4].clas = csd.fresh;
	studentRecord[4].major = csd.gs;

	studentRecord[5].name = "William Lambert";
	studentRecord[5].clas = csd.junior;
	studentRecord[5].major = csd.gs;

	studentRecord[6].name = "Connor Langdon";
	studentRecord[6].clas = csd.soph;
	studentRecord[6].major = csd.lib;

	studentRecord[7].name = "Wanda Russell";
	studentRecord[7].clas = csd.fresh;
	studentRecord[7].major = csd.gs;

	studentRecord[8].name = "Alexandra Welch";
	studentRecord[8].clas = csd.junior;
	studentRecord[8].major = csd.lib;

	studentRecord[9].name = "Brandon Russell";
	studentRecord[9].clas = csd.soph;
	studentRecord[9].major = csd.lib;

	studentRecord[10].name = "Victoria Nash";
	studentRecord[10].clas = csd.junior;
	studentRecord[10].major = csd.gs;

	studentRecord[11].name = "Sonia Scott";
	studentRecord[11].clas = csd.fresh;
	studentRecord[11].major = csd.gs;

	studentRecord[12].name = "Bella Hunter";
	studentRecord[12].clas = csd.senior;
	studentRecord[12].major = csd.lib;

	studentRecord[13].name = "Jack Peake";
	studentRecord[13].clas = csd.fresh;
	studentRecord[13].major = csd.gs;

	studentRecord[14].name = "James Simpson";
	studentRecord[14].clas = csd.soph;
	studentRecord[14].major = csd.lib;

	studentRecord[15].name = "Olivia Lawrence";
	studentRecord[15].clas = csd.junior;
	studentRecord[15].major = csd.lib;

	studentRecord[16].name = "Stewart Randall";
	studentRecord[16].clas = csd.senior;
	studentRecord[16].major = csd.gs;

	studentRecord[17].name = "Sonia Lyman";
	studentRecord[17].clas = csd.soph;
	studentRecord[17].major = csd.lib;

	studentRecord[18].name = "Alexander Fisher";
	studentRecord[18].clas = csd.senior;
	studentRecord[18].major = csd.gs;

	studentRecord[19].name = "Lily Hughes";
	studentRecord[19].clas = csd.soph;
	studentRecord[19].major = csd.gs;

	for (int i = 0; i < studentRecord.size(); i++) {
		for (int k = 0; k < scoreNum; k++)
			studentRecord[i].score[k] = randomInt(i);
	}

	for (int i = 0; i < studentRecord.size(); i++) {
		studentRecord[i].mean = calculateSum(i)/scoreNum;
	}

	for (int i = 0; i < studentRecord.size(); i++) {
		studentRecord[i].median = calcMedian(studentRecord, i);
	}

	for (int i = 0; i < studentRecord.size(); i++) {
		studentRecord[i].mode = calcMode(studentRecord, i);
	}

	for (int i = 0; i < studentRecord.size(); i++)	{

		studentRecord[i].standardDeviation = calcDev(studentRecord, i, studentRecord[i].mean);
	}
	return studentRecord;
}

void StudentData::printRecord(vector<Student> record, ostream &outFile){
	outFile << left << setw(18) << "Student Name" << left << setw(12) << "Class" << left << setw(15) << "Major" << right << setw(10) << "Scores" << right << setw(31) << "Mean" << "\t" << "Median" << "\t" << "Deviation" << endl;
	outFile << "-------------------------------------------------------------------------------------------------------";
	for (int i = 0; i < record.size(); i++) {
		outFile << endl << left << setw(18) << studentRecord[i].name << left << setw(12) << studentRecord[i].clas << left << setw(15) << studentRecord[i].major << right << setw(6);
		for (int k = 0; k < scoreNum; k++) 
			outFile << studentRecord[i].score[k] << " ";
		outFile << "\t  " << studentRecord[i].mean << "\t  " << studentRecord[i].median << "\t  " << studentRecord[i].standardDeviation;	
	}
	outFile << "\n";
}