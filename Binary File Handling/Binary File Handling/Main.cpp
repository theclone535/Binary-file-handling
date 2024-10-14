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
				//Saves a list of player names, scores, times and dates to a binary file 
	int sizeOfName = 5;
	string *nameArray = new string[sizeOfName];
	string data;
	
	//int *array = new int[size];
	//string nameArray[sizeOfName];
	//cout << "write a name\n";
	/*for (int i = 0; i < sizeOfName; i++)
	{
		cin >> nameArray[i];
	}
	
	for (int i = 0; i < sizeOfName; i++)
	{
		cout << nameArray[i] << endl;
		//cout << sizeOfName << endl;
		
	}*/
	
	/*string data;
	const char* buffer = new char;
	//opens a file in write mode
	ofstream outfile;
	outfile.open("HighScores.dat", ios::out | ios::binary);

	
	for (int i = 0; i < sizeOfName; i++)
	{
		cin >> nameArray[i];
		outfile.write((char*)&nameArray[i], sizeof(string));
	}

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

	string answer;
	cout << "write 'view' to view current Hichscores, 'append' to add a new record, 'retrieve' to search a highcore by name:\n";
	cin >> answer; cout << endl;
	if (answer == "view")
	{
		cout << "Current Highscores:\n";
		//displays highscores in ascending order
		ifstream infile;
		infile.open("HighScores.dat", ios::in | ios::binary);

		while (!infile.eof() && infile.peek() != EOF) {
			infile.read((char*)&data, sizeof(string));
			cout << data << endl;
		}
		infile.close();
		
		cout << "Anything else?\n";
		cin >> answer; cout << endl;
	}
	else if (answer == "append")
	{
		cout << "wrtie name of new Highscore:\n";
		string test;
		ofstream outfile;
		outfile.open("HighScores.dat", ios::out | ios::binary | ios::app);
		
		sizeOfName += 1;
		cin >> test;
		nameArray[sizeOfName] = test;
		outfile.write((char*)&nameArray[sizeOfName], sizeof(string));

		cout << sizeOfName; // for debugging 
		
		outfile.close();
		
		cout << "Anything else?\n";
		cin >> answer; cout << endl;
	}
	else if (answer == "retrieve")
	{

	}
	else
	{

	}

	return 69;
}

		

