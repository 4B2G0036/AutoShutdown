#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	system("mkdir Progress");
	
	FILE* fp1;
	errno_t err1 = fopen_s(&fp1, "E:/Gamesfolder/Vs/AutoShutdown/Project1/Progress/AutoShutdown.bat", "w");
	if (err1 != 0) {
		cerr << "Failed to open file" << endl;
		return 1;
	}
	double input;
	double time;
	int sec = 3600;
	cout << "Enter the time in hours: ";
	cin >> input;
	time = input * sec;
	if (time == 0) {
		fprintf(fp1, "shutdown -a");
		fclose(fp1);
		if (system("E:/Gamesfolder/Vs/AutoShutdown/Project1/Progress/AutoShutdown.bat") == 1116) {
			cout << "No shutdown in progress" << endl;
		}
		else {
			cout << "Shutdown canceled" << endl;
		}
	}
	if (time != 0) {
		fprintf(fp1, "shutdown -s -t %d", (int)time);
		fclose(fp1);
		system("E:/Gamesfolder/Vs/AutoShutdown/Project1/Progress/AutoShutdown.bat");
		cout << "Shutdown in " << input << " hour" << endl;
	}
	cout << "Turn off the screen or not? (y/n): ";
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		FILE* fp2;
		errno_t err2 = fopen_s(&fp2, "E:/Gamesfolder/Vs/AutoShutdown/Project1/Progress/Screenoff.bat", "w");
		if (err2 != 0) {
			cerr << "Failed to open file" << endl;
			return 1;
		}
		fprintf(fp2, "@echo off\npowershell (Add-Type '[DllImport(\\\"user32.dll\\\")]^public static extern int PostMessage(int hWnd, int hMsg, int wParam, int lParam);' -Name a -Pas)::PostMessage(-1,0x0112,0xF170,2)");
		fclose(fp2);
		system("E:/Gamesfolder/Vs/AutoShutdown/Project1/Progress/Screenoff.bat");
	}
	else {
		cout << "Good Luck" << endl;
	}
	system("rmdir /s /q \"E:/Gamesfolder/Vs/AutoShutdown/Project1/Progress\"");
	system("pause");
	return 0;
}