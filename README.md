
# Real-Time Scheduling for IoT Devices

This repository contains a C program that implements real-time scheduling algorithms for IoT devices. The program supports three different scheduling algorithms for task management:

1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF) - Non-Preemptive**
3. **Shortest Job First (SJF) - Preemptive**

These algorithms simulate the scheduling of tasks on IoT devices, considering task arrival time, burst time, and various other time metrics like completion time, waiting time, response time, and turnaround time.

## Algorithms Implemented

### 1. First-Come, First-Served (FCFS)
- The simplest scheduling algorithm where tasks are executed in the order they arrive.

### 2. Shortest Job First (SJF) - Non-Preemptive
- This scheduling algorithm selects the task with the shortest burst time (execution time) that is ready to execute, without preemption.

### 3. Shortest Job First (SJF) - Preemptive
- Similar to the non-preemptive SJF, but this version allows preemption, meaning a task with a shorter remaining time can interrupt a task currently being executed.

## Code Overview

The code defines a `Task` structure to hold task-related data, including:
- `id`: Task identifier
- `arrival_time`: The time at which the task arrives
- `burst_time`: The execution time required by the task
- `deadline`: The deadline by which the task must finish (not used in the current code)
- `priority`: The priority of the task (not used in the current code)
- `remaining_time`: The remaining time for the task to complete
- `completion_time`: The time at which the task finishes
- `turnaround_time`: The total time from arrival to completion
- `waiting_time`: The time the task spends waiting in the queue
- `response_time`: The time from arrival until the task first starts executing
- `first_execution`: The first time the task starts executing (used in preemptive SJF)

## Features
- **Task Sorting**: The tasks are sorted based on their arrival time before execution begins.
- **Task Execution**: The tasks are executed according to the selected scheduling algorithm.
- **Metrics Calculation**: The program computes several important metrics for each task:
    - Completion Time (CT)
    - Turnaround Time (TAT)
    - Waiting Time (WT)
    - Response Time (RT)

## Input Format

1. The program asks for the number of tasks `n`.
2. For each task, you need to provide the following:
    - Arrival time
    - Burst time (execution time)

## Output Format

The program outputs the scheduling results for each task, including:
- Task ID
- Arrival Time (AT)
- Burst Time (BT)
- Completion Time (CT)
- Turnaround Time (TAT)
- Waiting Time (WT)
- Response Time (RT)

### Example Output:

```
Enter number of tasks: 3
Enter arrival time for T1: 0
Enter burst time for T1: 5
Enter arrival time for T2: 1
Enter burst time for T2: 3
Enter arrival time for T3: 2
Enter burst time for T3: 2

Task    AT      BT      CT      TAT     WT      RT
T1      0       5       5       5       0       0
T2      1       3       8       7       4       4
T3      2       2       10      8       6       6

Task    AT      BT      CT      TAT     WT      RT
T1      0       5       5       5       0       0
T3      2       2       7       5       3       3
T2      1       3       10      9       6       6

Task    AT      BT      CT      TAT     WT      RT
T1      0       5       5       5       0       0
T3      2       2       7       5       3       3
T2      1       3       10      9       6       6
```

## Compilation & Usage

To compile and run the program, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/avanish2006/realtime-scheduling-for-IoT-device.git
    cd realtime-scheduling-for-IoT-device
    ```

2. **Compile the code**:
    ```bash
    gcc -o main main.c
    ```

3. **Run the program**:
    ```bash
    ./main
    ```

4. **Provide input** for the number of tasks and their respective arrival and burst times as prompted.

## Dependencies

- This program is written in **C** and uses the standard C library, so no external dependencies are required.




---

