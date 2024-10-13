#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	/*string data;
	// open a file in write mode
	ofstream outfile;
	outfile.open("student.txt", ios::app);
	cout << "Enter student name: ";
	cin >> data;
	//write input data in the file
	outfile << data << endl;
	cout << "\nEnter student age: ";
	cin >> data;
	//write input data in the file
	outfile << data << endl;
	cout << "\nEnter student program: ";
	cin >> data;
	outfile << data << endl;
	//close the open file
	outfile.close();
	system("pause");*/
	int myarray = 50;
	string mystring = "connor";
	string data;
	const char* buffer = new char;
	//opens a file in write mode
	ofstream outfile;
	outfile.open("HighScores.dat", ios::out | ios::binary);

	outfile.write((char*)&mystring, sizeof(string));

	outfile.close();

	//read file
	ifstream infile;
	infile.open("HighScores.dat", ios::in | ios::binary);

	while (!infile.eof() && infile.peek() != EOF) {
		infile.read((char*)&data, sizeof(string));
		cout << data << endl;
	}
	infile.close();
	system("pause");

	/*
	int myVecArray[9] = { 0, 1, 2 , 1, 2, 3 , 4, 5, 6 };
	int arraySize = sizeof(myVecArray) / sizeof(int);
	//opening binary file data.dat
	ofstream fout("data.dat", ios::out | ios::binary);
	//fill in the array here
	if (fout.good()) {
		for (int i = 0; i < arraySize; i++) {
			fout.write((char*)&myVecArray[i], sizeof(int));
		}
		fout.close();
	}
	//read
	int myarray;
	ifstream fin("data.dat", ios::in | ios::binary);
	if (fin.good()) {
		// read until we get to the end of file
		while (!fin.eof() && fin.peek() != EOF) {
			fin.read((char*)&myarray, sizeof(int));
			cout << myarray << endl;
		}
		fin.close();
	}
	system("pause");*/
}

		

