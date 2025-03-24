#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Task structure
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int deadline;
    int priority;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int first_execution;
} Task;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to display results
void displayResults(Task *tasks, int n) {
    printf("\nTask\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("T%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               tasks[i].id, tasks[i].arrival_time, tasks[i].burst_time,
               tasks[i].completion_time, tasks[i].turnaround_time,
               tasks[i].waiting_time, tasks[i].response_time);
    }
}

// Function to implement FCFS scheduling
void fcfs(Task *tasks, int n) {
    int current_time = 0;

    // Sort tasks by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].arrival_time > tasks[j].arrival_time) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (current_time < tasks[i].arrival_time) {
            current_time = tasks[i].arrival_time;
        }
        tasks[i].completion_time = current_time + tasks[i].burst_time;
        current_time = tasks[i].completion_time;
        tasks[i].turnaround_time = tasks[i].completion_time - tasks[i].arrival_time;
        tasks[i].waiting_time = tasks[i].turnaround_time - tasks[i].burst_time;
        tasks[i].response_time = tasks[i].waiting_time; // FCFS
    }
    displayResults(tasks, n);
}

// Function to implement SJF (Non-Preemptive) scheduling
void sjfNonPreemptive(Task *tasks, int n) {
    int current_time = 0;
    int completed = 0;
    int is_completed[n];
    for(int i = 0; i < n; i++) is_completed[i] = 0;

    // Sort tasks by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].arrival_time > tasks[j].arrival_time) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    while (completed < n) {
        int idx = -1;
        int min_burst_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!is_completed[i] && tasks[i].arrival_time <= current_time && tasks[i].burst_time < min_burst_time) {
                min_burst_time = tasks[i].burst_time;
                idx = i;
            }
        }

        if (idx == -1) {
            current_time++;
        } else {
            tasks[idx].completion_time = current_time + tasks[idx].burst_time;
            current_time = tasks[idx].completion_time;
            tasks[idx].turnaround_time = tasks[idx].completion_time - tasks[idx].arrival_time;
            tasks[idx].waiting_time = tasks[idx].turnaround_time - tasks[idx].burst_time;
            tasks[idx].response_time = tasks[idx].waiting_time; // SJF Non Preemptive
            is_completed[idx] = 1;
            completed++;
        }
    }
    displayResults(tasks, n);
}

// Function to implement SJF (Preemptive) scheduling
void sjfPreemptive(Task *tasks, int n) {
    int current_time = 0;
    int completed = 0;
    int is_completed[n];
    for (int i = 0; i < n; i++) is_completed[i] = 0;

    // Sort tasks by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].arrival_time > tasks[j].arrival_time) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    while (completed < n) {
        int idx = -1;
        int min_remaining_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!is_completed[i] && tasks[i].arrival_time <= current_time && tasks[i].remaining_time < min_remaining_time && tasks[i].remaining_time > 0) {
                min_remaining_time = tasks[i].remaining_time;
                idx = i;
            }
        }

        if (idx == -1) {
            current_time++;
        } else {
            if (tasks[idx].first_execution == -1) tasks[idx].first_execution = current_time;
            tasks[idx].remaining_time--;
            current_time++;

            if (tasks[idx].remaining_time == 0) {
                tasks[idx].completion_time = current_time;
                tasks[idx].turnaround_time = tasks[idx].completion_time - tasks[idx].arrival_time;
                tasks[idx].waiting_time = tasks[idx].turnaround_time - tasks[idx].burst_time;
                tasks[idx].response_time = tasks[idx].first_execution - tasks[idx].arrival_time;
                is_completed[idx] = 1;
                completed++;
            }
        }
    }
    displayResults(tasks, n);
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("Enter arrival time for T%d: ", i + 1);
        scanf("%d", &tasks[i].arrival_time);
        printf("Enter burst time for T%d: ", i + 1);
        scanf("%d", &tasks[i].burst_time);
        tasks[i].remaining_time = tasks[i].burst_time;
        tasks[i].first_execution = -1;
    }

    fcfs(tasks,n);
    printf("\n");
    sjfNonPreemptive(tasks,n);
    printf("\n");
    for (int i = 0; i < n; i++) tasks[i].remaining_time = tasks[i].burst_time;
    sjfPreemptive(tasks, n);

    return 0;
}
