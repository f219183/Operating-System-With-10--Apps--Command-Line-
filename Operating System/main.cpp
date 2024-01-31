#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

using namespace std;

double ram = 0, cores = 0, storage = 0;
mutex mtx;

struct Process {
    int pid;
    double arrival_time;
    double priority;
    double burst_time;
};

bool compare_arrival_time(const Process& a, const Process& b) {
    return a.arrival_time < b.arrival_time;
}

bool compare_priority(const Process& a, const Process& b) {
    return a.priority < b.priority;
}

void* calculator(void* p) {
    system("gnome-terminal --disable-factory -- ./calculator"); // Replace "calc" with the name of your calculator program executable
    return NULL;
}

void* calendar(void* p) {
    system("gnome-terminal --disable-factory -- ./calender"); // Replace "calendar" with the name of your calendar program executable
    return NULL;
}

void* clock(void* p) {
    system("gnome-terminal --disable-factory -- ./clock"); // Replace "clock" with the name of your clock program executable
    return NULL;
}

void* copyFile(void* p) {
    system("gnome-terminal --disable-factory -- ./copyFile"); // Replace "copyFile" with the name of your copyFile program executable
    return NULL;
}

void* createFile(void* p) {
    system("gnome-terminal --disable-factory -- ./createFile"); // Replace "createFile" with the name of your createFile program executable
    return NULL;
}

void* deletefile(void* p) {
    system("gnome-terminal --disable-factory -- ./deletefile"); // Replace "Deletefile" with the name of your Deletefile program executable
    return NULL;
}

void* Fileproperties(void* p) {
    system("gnome-terminal --disable-factory -- ./Fileproperties"); // Replace "Fileproperties" with the name of your Fileproperties program executable
    return NULL;
}

void* moveFile(void* p) {
    system("gnome-terminal --disable-factory -- ./moveFile"); // Replace "moveFile" with the name of your moveFile program executable
    return NULL;
}

void* notepad(void* p) {
    system("gnome-terminal --disable-factory -- ./notepad"); // Replace "notepad" with the name of your notepad program executable
    return NULL;
}

void* rename(void* p) {
    system("gnome-terminal --disable-factory -- ./rename"); // Replace "rename" with the name of your rename program executable
    return NULL;
}

void* song(void* p) {
    system("gnome-terminal --disable-factory -- ./song"); // Replace "song" with the name of your song program executable
    return NULL;
}

void* tictactoe(void* p) {
    system("gnome-terminal --disable-factory -- ./tictactoe"); // Replace "tictactoe" with the name of your tictactoe program executable
    return NULL;
}

void* Hangman(void* p) {
    system("gnome-terminal --disable-factory -- ./Hangman"); // Replace "Hangman" with the name of your Hangman program executable
    return NULL;
}

void* RockPaperScissors(void* p) {
    system("gnome-terminal --disable-factory -- ./RockPaperScissors"); // Replace "RockPaperScissors" with the name of your Hangman program executable
    return NULL;
}

void* numberGuess(void* p) {
    system("gnome-terminal --disable-factory -- ./numberGuess"); // Replace "numberGuess	" with the name of your Hangman program executable
    return NULL;
}


void* video(void* p) {
    system("gnome-terminal --disable-factory -- ./video"); // Replace "video" with the name of your video program executable
    return NULL;
}



void dis() {
    DIR* dir = opendir("/proc");
    if (!dir) {
        cerr << "Failed to open directory /proc.\n";
        return;
    }

    struct dirent* ent;
    vector<pid_t> pids;
    while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_type != DT_DIR) continue;
        const string pid_str = ent->d_name;
        if (pid_str.find_first_not_of("0123456789") != string::npos) continue;
        const pid_t pid = stoi(pid_str);
        char cmdline_path[64];
        sprintf(cmdline_path, "/proc/%d/cmdline", pid);
        FILE* cmdline_file = fopen(cmdline_path, "r");
        if (!cmdline_file) continue;
        char cmdline[1024];
        const size_t len = fread(cmdline, 1, sizeof(cmdline), cmdline_file);
        fclose(cmdline_file);
        if (len == 0) continue;
        cmdline[len] = '\0';
        if (strstr(cmdline, "./") == cmdline) {
            pids.push_back(pid);
            cout << pid << " " << cmdline << endl;
        }
    }
    closedir(dir);

    if (pids.empty()) {
        cout << "No processes found.\n";
        return;
    }

    int pid;
    cout << "Enter the PID of the process you want to terminate: ";
    cin >> pid;

    int ret = kill(pid, SIGKILL);
    if (ret == -1) {
        perror("Failed to send signal to process");
        return;
    }

    cout << "Signal sent to process.\n";
}

void display_res() {
	int arr2[9];
	for(int i=0;i<9;i++)
	{
	arr2[i]=0;
	}
	int p=0;
	DIR* dir = opendir("/proc");
	    if (!dir) {
		cerr << "Failed to open directory /proc.\n";
		return;
	    }

	    struct dirent* ent;
	    vector<pid_t> pids;
	    while ((ent = readdir(dir)) != nullptr) {
		if (ent->d_type != DT_DIR) continue;
		const string pid_str = ent->d_name;
		if (pid_str.find_first_not_of("0123456789") != string::npos) continue;
		const pid_t pid = stoi(pid_str);
		char cmdline_path[64];
		sprintf(cmdline_path, "/proc/%d/cmdline", pid);
		FILE* cmdline_file = fopen(cmdline_path, "r");
		if (!cmdline_file) continue;
		char cmdline[1024];
		const size_t len = fread(cmdline, 1, sizeof(cmdline), cmdline_file);
		fclose(cmdline_file);
		if (len == 0) continue;
		cmdline[len] = '\0';
		if (strstr(cmdline, "./") == cmdline) {
		    pids.push_back(pid);
	arr2[p]=pid;
	p++;
		}
	    }

	    closedir(dir);
	if((ram - 0.5*p) <= 0)
	{
		cout<<"\nNo More Memmory\nFirst Process was deleted to free some ram\n\n";
		kill(arr2[2], SIGKILL);
	}
	    cout << "Free Available RAM : " << ram - 0.5*p << endl;
	    cout << "Free Cores : " << 9-p << endl;
	    cout << "Free Storage : " << storage - 0.10*p << endl;
	            
}

int main() {
    int choice;
    int hightime = 5;
    pthread_t calc_thread, calendar_thread,clock_thread,copyFile_thread,createFile_thread,deletefile_thread,Fileproperties_thread,moveFile_thread,notepad_thread,rename_thread,song_thread,video_thread,tictactoe_thread,Hangman_thread,RockPaperScissors_thread,numberGuess_thread;
    cout << "Enter RAM: ";
    cin >> ram;
    cout << "Enter storage: ";
    cin >> storage;

    // Initialize the queues
    int high[3];
	int med[3];
	int low[3];
    for (int i = 0; i < 3; i++)
    {
        high[i] = 0;

    }
for (int i = 0; i < 3; i++)
    {
        med[i] = 0;

    }
for (int i = 0; i < 3; i++)
    {
        low[i] = 0;

    }
    while (choice != -1) {
	sleep(1);
	system("clear");
	display_res();
        cout << "Choose an option:\n";
        cout << "01. Calculator\n";
        cout << "02. Calendar\n";
        cout << "03. Clock\n";
        cout << "04. Copy File\n";
        cout << "05. Create File\n";
        cout << "06. Delete File\n";
        cout << "07. File Properties\n";
        cout << "08. Move File\n";
        cout << "09. Notepad\n";
        cout << "10. Rename File\n";
        cout << "11. Play Song\n";
        cout << "12. Play Video\n";
        cout << "13. Run Tic Tac Toe Game\n";
        cout << "14. Run Hangman Game\n";
        cout << "15. Run Rock Paper Scissors Game\n";
        cout << "16. Run Number Guessing Game\n";
        cout << "17. Kernel Mode For terminating Specific Process\n";
        cout << "18. Dispay Resources\n";
        cout << "19. Terminate Functions\n";

        cout << "-1. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:

        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&calc_thread, NULL, calculator, NULL);
                //pthread_join(calc_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 2:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&calendar_thread, NULL, calendar, NULL);
                // pthread_join(calendar_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 3:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&clock_thread, NULL, clock, NULL);
                // pthread_join(clock_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 4:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&copyFile_thread, NULL, copyFile, NULL);
                // pthread_join(copyFile_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 5:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&createFile_thread, NULL, createFile, NULL);
                // pthread_join(createFile_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 6:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&deletefile_thread, NULL, deletefile, NULL);
                // pthread_join(deletefile_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 7:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&Fileproperties_thread, NULL, Fileproperties, NULL);
                // pthread_join(Fileproperties_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 8:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&moveFile_thread, NULL, moveFile, NULL);
                // pthread_join(moveFile_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 9:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&notepad_thread, NULL, notepad, NULL);
                // pthread_join(notepad_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 10:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&rename_thread, NULL, rename, NULL);
                // pthread_join(rename_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 11:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&song_thread, NULL, song, NULL);
                // pthread_join(song_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 12:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&video_thread, NULL, video, NULL);
                // pthread_join(video_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 13:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&tictactoe_thread, NULL, tictactoe, NULL);
                // pthread_join(tictactoe_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 14:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&Hangman_thread, NULL, Hangman, NULL);
                // pthread_join(Hangman_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 15:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&RockPaperScissors_thread, NULL, RockPaperScissors, NULL);
                // pthread_join(RockPaperScissors_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 16:
        {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                pthread_create(&numberGuess_thread, NULL, numberGuess, NULL);
                // pthread_join(numberGuess_thread, NULL);
                exit(0);
            }
            else if (pid > 0) {
                // Parent process
                wait(NULL);
                break;
            }
            else {
                cerr << "Error creating process.\n";
            }
            break;
        }
        case 17:
            system("clear");
            dis();
            break;
        case 18:
            system("clear");
            getchar(); // wait for user input
            display_res();
		puts("Press enter to continue...");
            getchar(); // wait for user input
            break;
        case -1:
            choice = -1;
            break;
        case 19:
        {
                //
                DIR* dir = opendir("/proc");
                if (!dir) {
                    cerr << "Failed to open 	directory /proc.\n";
                    break;
                }

                int arr2[9], p = 0;
                for (int i = 0; i < 9; i++)
                {
                    arr2[i] = 0;
                }
                struct dirent* ent;
                vector<pid_t> pids;
                while ((ent = readdir(dir)) != nullptr) {
                    if (ent->d_type != DT_DIR) continue;
                    const string pid_str = ent->d_name;
                    if (pid_str.find_first_not_of("0123456789") != string::npos) continue;
                    const pid_t pid = stoi(pid_str);
                    char cmdline_path[64];
                    sprintf(cmdline_path, "/proc/%d/cmdline", pid);
                    FILE* cmdline_file = fopen(cmdline_path, "r");
                    if (!cmdline_file) continue;
                    char cmdline[1024];
                    const size_t len = fread(cmdline, 1, sizeof(cmdline), cmdline_file);
                    fclose(cmdline_file);
                    if (len == 0) continue;
                    cmdline[len] = '\0';
                    if (strstr(cmdline, "./") == cmdline) {
                        pids.push_back(pid);
                        arr2[p] = pid;
                        p++;
                        cout << pid << " " << cmdline << endl;
                    }

                }
                cout << "a-------------" << endl;
                for (int i = 0; i < p; i++)
                {
                    cout << arr2[i] << endl;
                }
                cout << "a-------------" << endl;

                for (int i = 0; i < 3; i++)
                {
                    high[i] = arr2[i];
                }

                for (int i = 0, j = 3; i < 3; i++)
                {
                    med[i] = arr2[j];
                }
                for (int i = 0, j = 6; i < 3; i++)
                {
                    low[i] = arr2[j];
                }

                //
                // Schedule the processes in the queues using different scheduling techniques on each level

                // dis();
                            // Execute the processes in the order of the queues
                int counth = 2;
                while (counth < 3) {

                    cout << "high level queue" << endl;
                    int pid = high[counth];
                    cout << pid << endl;
                    string cmd = "xdotool search --pid " + to_string(pid) + " --all windowactivate";
                    system(cmd.c_str());
                    sleep(5);
                    int ret = kill(pid, SIGKILL);

                    if (ret == -1) {
                        perror("Failed to send signal to process");
                    }
                    else {

                        cout << "Terminated process " << high[counth] << " with high priority.\n";
                    }
                    counth++;
                }

                while (counth < 6) {

                    cout << "medium queue" << endl;
                    int pid = med[counth];
                    cout << pid << endl;
                    string cmd = "xdotool search --pid " + to_string(pid) + " --all windowactivate";
                    system(cmd.c_str());
                    sleep(4);
                    int ret = kill(pid, SIGKILL);

                    if (ret == -1) {
                        perror("Failed to send signal to process");
                    }
                    else {

                        cout << "Terminated process " << high[counth] << " with high priority.\n";
                    }
                    counth++;
                }

                while (counth < 9) {

                    cout << "low queue" << endl;
                    int pid = low[counth];
                    cout << pid << endl;
                    string cmd = "xdotool search --pid " + to_string(pid) + " --all windowactivate";
                    system(cmd.c_str());
                    sleep(4);
                    int ret = kill(pid, SIGKILL);

                    if (ret == -1) {
                        perror("Failed to send signal to process");
                    }
                    else {

                        cout << "Terminated process " << high[counth] << " with high priority.\n";
                    }
                    counth++;
                }
            }
        
		default:
		{
		    cout << "This value is not acceptable.\nTry again.\n";
		}
	}

    }
    return 0;
}

