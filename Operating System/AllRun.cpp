#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main() {
	string objName[18];
	string filepath;
    	objName[0] = "calculator";
	objName[1] = "calender";
	objName[2] = "clock";
    	objName[3] = "copyFile";
	objName[4] = "createFile";
	objName[5] = "deletefile";
	objName[6] = "Fileproperties";
	objName[7] = "moveFile";
	objName[8] = "notepad";
	objName[9] = "rename";
	objName[10] = "song";
	objName[11] = "tictactoe";
	objName[12] = "video";
	objName[13] = "Hangman";
	objName[14] = "RockPaperScissors";
	objName[15] = "numberGuess";
	objName[16] = "intro";
    	objName[17] = "main";
    
	for (int i=0;i<17;i++)
    	{
		filepath = "/home/f219183/Desktop/project/"+ objName[i] + ".cpp";
		string command ="g++ -o "+ objName[i] + " "+ filepath;
		int result = system(command.c_str());
		cout << objName[i]<<" is compiling..." << endl;
		if (result == 0) {
		    cout << "Command for "<<objName[i]<<" executed successfully." << endl;
		} 
		else 
		{
		    cerr << "Error executing command for "<<objName[i]<< endl;
		}
    	}
    //For Main use thread
    filepath = "/home/f219183/Desktop/project/"+ objName[17] + ".cpp";
        string command ="g++ -pthread -o "+ objName[17] + " "+ filepath;
        int result = system(command.c_str());
	cout << objName[17]<<" is compiling..." << endl;
        if (result == 0) {
            cout << "Command for "<<objName[17]<<" executed successfully." << endl;
        } 
        else 
        {
            cerr << "Error executing command for "<<objName[14]<< endl;
        }
	
    return 0;
}




