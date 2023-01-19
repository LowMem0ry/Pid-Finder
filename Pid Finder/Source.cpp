#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

using namespace std;

int GetPid(const char* ProcessName) {
	int pid = 0;

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (!hSnapshot) {
		cout << "failed to take a snapshot to all the processes in the system\n";
		return GetLastError();
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	BOOL result = Process32First(hSnapshot, &pe32);
	if (!result) {
		cout << "failed to retrieve about the first process in the system snapshot" << endl;
		return GetLastError();
	}

	while (result) {
		if (strcmp(ProcessName, pe32.szExeFile) == 0) {
			pid = pe32.th32ProcessID;
			break;
		}
		result = Process32Next(hSnapshot, &pe32);
	}
	CloseHandle(hSnapshot);

	return pid;
}
int main(void) {
	int pid = 0;
	char* ProcessName;
	cout << "[+] Process Name : ";
	cin >> ProcessName;
	
	pid = GetPid(ProcessName);
	cout << pid << endl;

	return 0;
}
