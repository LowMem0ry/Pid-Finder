# What this a process id
* Each process running in Windows is assigned a unique decimal number called the process ID (PID). This number is used in a number of ways, for example to specify the process when attaching a debugger to it.
# TECHNICAL DETAILS
* Snapshot of all processes in the system using using The [PROCESSENTRY32 structure](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/ns-tlhelp32-processentry32)
* Initializing size (you need that for the [Process32First()](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-process32first) and [Process32Next](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-process32next)) 
* Retrieve informations about the first process and compare it to the Process Name using [Process32First()](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-process32first) and [Process32Next](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-process32next)
# DEMO
![Alt Text Here](https://github.com/Zextus/Pid-Finder/blob/main/demo.gif)
