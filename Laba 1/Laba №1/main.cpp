#include "FStream.h"
#include "FPointer.h"

int mode(int argc, char** argv) {
	if (argc != 3) {
		return -1;
	}

	string flag{ argv[1] }, mode{ argv[2] };
	if (flag != "-mode") {
		return -1; 
	}

	if (mode == "FilePointer") {
		return 1;
	}
	else if (mode == "FileStream") {
		return 2;
	}
	else {
		return -1;
	}
}


int main(int argc, char** argv) {
	int choice;
	string filename;
	int selectedMode = mode(argc, argv);

	if (selectedMode == -1) {
		cout << "Invalid command line arguments." << endl;
		return 0;
	}

	while (true) {
		choice = menuP();
		switch (choice) {
		case 1:
			if (selectedMode == 1) {
				WriteToFileP(GetFilenameP());
			}
			else if (selectedMode == 2) {
				WriteToFileS(GetFilenameS());
			}
			break;
		case 2:
			if (selectedMode == 1) {
				ReadFileP(GetFilenameP());
			}
			else if (selectedMode == 2) {
				ReadFileS(GetFilenameS());
			}
			break;
		case 3:
			if (selectedMode == 1) {
				AddToFileP(GetFilenameP());
			}
			else if (selectedMode == 2) {
				AddToFileS(GetFilenameS());
			}
			break;
		case 4:
			cout << "Enter name of new file (format: text2.txt): ";
			cin >> filename;
			if (selectedMode == 1) {
				SortFileP(GetFilenameP());
			}
			else if (selectedMode == 2) {
				SortFileS(GetFilenameS());
			}
			break;
		}
	}

	return 0;
}
