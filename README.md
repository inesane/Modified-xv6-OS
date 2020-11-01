Enhancing xv6 OS

System Calls
waitx - The waitx system call waits for a process to terminate and gives the wait time and run time of that process

ps - The ps system call is gives information about the currently running processes, such as its pid, priority value, state, run time, wait time, number of times it was picked up by the scheduler (n_run), etc...

set_priority - The set_priority system call is used to change the priority of a process. This is required only in Priority Based Scheduling (PBS). It takes 2 inputs, the pid of the process that we would like to change the priority of and the new priority that we would like to give to said process

User Programs
time - "time <command>" will run the inputted command and display the number of clock ticks that the relevant process waited for and the number of clock ticks that it ran for. It uses the waitx system call to implement this

ps - the ps user program displays information related to the current processes such as its pid, priority value, state, run time, wait time, etc... It uses the ps system call to implement this

setPriority - the setPriority user program changes the priority of a given process. It takes the the pid of the process, whose priority is required to be changed and the new priority of said process as inputs and it implements this change. It uses the set_priority system call to implement this

The Following Scheduling Algorithms have been implemented (RR is the original scheduling algorithm used, the other 3 have been added):
Round-Robin (RR) - preemptive scheduling algorithm that executes each process for a given time period. After the completion of that time period, it is preempted and other processes are allowed to execute for the same time period
First Come Fist Serve (FCFS) - selects the process with the lowest creation time and runs it to completion
Priority Based Scheduling (PBS) - selects the process with the highest priority. Implements Round-Robin in case multiple processes have the same priority
Multi-Level Feedback Queue (MLFQ) - allows processes to move between various priority queues (in this case 5), based on how much CPU time they take to execute and CPU bursts

Performance Comparisons Between Scheduling Algorithms
