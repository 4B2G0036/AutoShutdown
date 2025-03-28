#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	FILE* fp;
	errno_t err = fopen_s(&fp, "F:/Item/shutdown.bat", "w");
	if (err != 0) {
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
		fprintf(fp, "shutdown -a");
		fclose(fp);
		if (system("F:/Item/shutdown.bat") == 1116) {
			cout << "No shutdown in progress" << endl;
		}
		else {
			cout << "Shutdown canceled" << endl;
		}
	}
	if (time != 0) {
		fprintf(fp, "shutdown -s -t %d", (int)time);
		fclose(fp);
		system("F:/Item/shutdown.bat");
		cout << "Shutdown in " << input << " hour" << endl;
	}
	system("pause");
	return 0;
}