#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
				//Saves a list of player names, scores, times and dates to a binary file 
	int sizeOfName = 0;
	string* nameArray = new string[sizeOfName];
	string data;
	string answer;
	cout << "write 'view' to view current Hichscores, 'append' to add a new record, 'retrieve' to search a highcore by name, 'clear' to clear the file:\n";
	cin >> answer; cout << endl;
	if (answer == "view")
	{
		cout << "Current Highscores:\n";
		//opens the file in read and binary mode
		ifstream infile;
		infile.open("HighScores.dat", ios::in | ios::binary);
		//writes to terminal until end of file and 
		while (!infile.eof() && infile.peek() != EOF) {
			infile.read((char*)&data, sizeof(string));
			cout << data << endl;
		}
		infile.close();

		cout << "Anything else?\n";
		main();
	}
	else if (answer == "append")
	{
		string test;
		cout << "wrtie name of new Highscore:\n";
		//opens the file in write, append and binary mode
		ofstream outfile;
		outfile.open("HighScores.dat", ios::binary | ios::out | ios::app);

		//error handling if file dosent open
		if (!outfile)
		{
			cerr << "Error OPening file" << endl;
		}
		//gets user input
		cin >> test;
		//updates dynamic array
		string* newString = new string[sizeOfName + 1];
		for (int i = 0; i < sizeOfName; i++)
		{
			newString[i] = nameArray[i];
		}
		newString[sizeOfName] = test;
		delete[] nameArray;
		sizeOfName += 1;
		nameArray = newString;
		//writes the new array to the binary file
		for (int i = 0; i < sizeOfName; i++)
		{
			outfile.write((char*)&nameArray[i], sizeof(string));
		}
		outfile.close();
		delete[] nameArray;
		cout << "Anything else?\n";
		main();
	}
	else if (answer == "retrieve")
	{

	}
	else if (answer == "clear")
	{

	}
	else
	{

	}

	return 69;
}

		

