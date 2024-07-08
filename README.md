# Enhancing xv6 OS

## How to Run

1. Clean the build environment:
    ```bash
    make clean
    ```
2. Build and run xv6 with a specified scheduler:
    ```bash
    make qemu SCHEDULER=<SCHEDULER>
    ```
    The input `SCHEDULER` is the scheduling algorithm to be used to run the processes. The options are listed below.

## System Calls

### `waitx`
The `waitx` system call waits for a process to terminate and provides the wait time and run time of that process.

### `ps`
The `ps` system call gives information about the currently running processes, such as its PID, priority value, state, run time, wait time, number of times it was picked up by the scheduler (`n_run`), etc.

### `set_priority`
The `set_priority` system call changes the priority of a process. This is required only in Priority Based Scheduling (PBS). It takes 2 inputs: the PID of the process whose priority is to be changed, and the new priority value.

## User Programs

### `time`
`time <command>` runs the inputted command and displays the number of clock ticks the relevant process waited for and the number of clock ticks it ran for. It uses the `waitx` system call to implement this.

### `ps`
The `ps` user program displays information related to the current processes, such as its PID, priority value, state, run time, wait time, etc. It uses the `ps` system call to implement this.

### `setPriority`
The `setPriority` user program changes the priority of a given process. It takes the PID of the process whose priority is to be changed and the new priority value as inputs. It uses the `set_priority` system call to implement this change.

## Scheduling Algorithms

The following scheduling algorithms have been implemented (Round-Robin is the original scheduling algorithm used, the other three have been added):

### Round-Robin (RR)
A preemptive scheduling algorithm that executes each process for a given time period. After the completion of that time period, the process is preempted and other processes are allowed to execute for the same time period.

### First Come First Serve (FCFS)
A non-preemptive scheduling algorithm that selects the process with the lowest creation time and runs it to completion.

### Priority Based Scheduling (PBS)
Selects the process with the highest priority. Implements Round-Robin in case multiple processes have the same priority. By default, the priority of each process is set to 60.

### Multi-Level Feedback Queue (MLFQ)
Allows processes to move between various priority queues (in this case, 5 queues), based on how much CPU time they take to execute and CPU bursts.

## Reason for Scheduling Getting Exploited

If a process calls a large number of CPU cycles and then makes a few I/O calls before exceeding its time slice, it will stay in a high-priority queue and still be able to continue to call a large number of CPU cycles.

## Performance Comparisons Between Scheduling Algorithms

On running the `benchmark`, we get the total number of ticks taken to run each scheduling algorithm for two separate runs:

- **RR**: 8941, 10326
- **FCFS**: 12755, 11175
- **PBS**: 5763, 4724
- **MLFQ**: 7481, 8304

## Bonus

The bonus has been implemented as well. Here are two different graphs, both with 4 processes:

1. In the first graph, 2 of the processes are CPU-bound and 2 are I/O-bound. The CPU-bound processes quickly climb to the 5th queue and are executed there, while the I/O-bound processes stay in the first queue as they are sleeping for a large portion of time.

2. The second graph shows that all 4 processes are CPU-bound, and we can see that all the processes quickly climb to the 5th queue and are executed there. Hence, the 2 processes that climbed in the first graph are the CPU-bound processes, while the other 2 that stayed in the first queue are I/O-bound.
