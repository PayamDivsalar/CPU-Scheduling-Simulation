#include "scheduler.h"
#include <stdbool.h>

// ---------------- Scheduling Algorithms ----------------

// FCFS Scheduling
Metrics fcfs_metrics(Process proc[], int n) {

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i] = proc[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j].arrivalTime < p[min_idx].arrivalTime) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Process tmp = p[i];
            p[i] = p[min_idx];
            p[min_idx] = tmp;
        }
    }
    int currentTime = 0;
    float totalTurnaround = 0;
    float totalWaiting = 0;
    float totalResponse = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }
        p[i].startTime = currentTime;
        p[i].completionTime = p[i].startTime + p[i].burstTime;
        currentTime = p[i].completionTime;

        int turnaround = p[i].completionTime - p[i].arrivalTime;
        int waiting    = turnaround - p[i].burstTime;
        int response   = p[i].startTime    - p[i].arrivalTime;

        totalTurnaround += turnaround;
        totalWaiting    += waiting;
        totalResponse   += response;
    }

    Metrics m;
    m.avgTurnaround = totalTurnaround / n;
    m.avgWaiting    = totalWaiting    / n;
    m.avgResponse   = totalResponse   / n;
    return m;
}

// SJF Scheduling (Non-preemptive)
Metrics sjf_metrics(Process proc[], int n) {

    Process p[n];
    bool done[n];
    for (int i = 0; i < n; i++) {
        p[i]    = proc[i];
        done[i] = false;
    }
    int completed   = 0;
    int currentTime = 0;
    float totalTurnaround = 0;
    float totalWaiting    = 0;
    float totalResponse   = 0;

    while (completed < n) {

        int idx = -1;
        int minBurst = 0;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrivalTime <= currentTime) {
                if (idx == -1 || p[i].burstTime < minBurst) {
                    idx = i;
                    minBurst = p[i].burstTime;
                }
            }
        }
        if (idx == -1) {

            int nextArrival = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i]) {
                    if (nextArrival == -1 || p[i].arrivalTime < p[nextArrival].arrivalTime) {
                        nextArrival = i;
                    }
                }
            }
            currentTime = p[nextArrival].arrivalTime;
            continue;
        }

        p[idx].startTime      = currentTime;
        p[idx].completionTime = p[idx].startTime + p[idx].burstTime;
        currentTime           = p[idx].completionTime;

        int turnaround = p[idx].completionTime - p[idx].arrivalTime;
        int waiting    = turnaround - p[idx].burstTime;
        int response   = p[idx].startTime - p[idx].arrivalTime;

        totalTurnaround += turnaround;
        totalWaiting    += waiting;
        totalResponse   += response;

        done[idx] = true;
        completed++;
    }

    Metrics m;
    m.avgTurnaround = totalTurnaround / n;
    m.avgWaiting    = totalWaiting    / n;
    m.avgResponse   = totalResponse   / n;
    return m;
}

// Round Robin Scheduling (Revised)
Metrics rr_metrics(Process proc[], int n, int timeQuantum) {

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i] = proc[i];
        p[i].remainingTime = p[i].burstTime;
        p[i].startTime = -1;
    }

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j].arrivalTime < p[min_idx].arrivalTime) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Process tmp = p[i];
            p[i] = p[min_idx];
            p[min_idx] = tmp;
        }
    }

    int currentTime = 0;
    int completed   = 0;
    float totalTurnaround = 0;
    float totalWaiting    = 0;
    float totalResponse   = 0;

    int queue[100];
    int front = 0, rear = 0;
    bool inQueue[n];
    for (int i = 0; i < n; i++) {
        inQueue[i] = false;
    }
    int nextArrival = 0;


    while (nextArrival < n && p[nextArrival].arrivalTime <= currentTime) {
        queue[rear++] = nextArrival;
        inQueue[nextArrival] = true;
        nextArrival++;
    }

    while (completed < n) {
        if (front == rear) {

            if (nextArrival < n) {
                currentTime = p[nextArrival].arrivalTime;
                queue[rear++] = nextArrival;
                inQueue[nextArrival] = true;
                nextArrival++;
            }
            continue;
        }

        int idx = queue[front++];
        if (p[idx].startTime == -1) {
            p[idx].startTime = currentTime;
        }

        int execTime = (p[idx].remainingTime < timeQuantum) ? p[idx].remainingTime : timeQuantum;
        p[idx].remainingTime -= execTime;
        currentTime += execTime;


        while (nextArrival < n && p[nextArrival].arrivalTime <= currentTime) {
            if (!inQueue[nextArrival]) {
                queue[rear++] = nextArrival;
                inQueue[nextArrival] = true;
            }
            nextArrival++;
        }

        if (p[idx].remainingTime > 0) {
            queue[rear++] = idx;
        } 

        else {
            p[idx].completionTime = currentTime;
            int turnaround = p[idx].completionTime - p[idx].arrivalTime;
            int waiting    = turnaround - p[idx].burstTime;
            int response   = p[idx].startTime - p[idx].arrivalTime;

            totalTurnaround += turnaround;
            totalWaiting    += waiting;
            totalResponse   += response;
            completed++;
        }
    }

    Metrics m;
    m.avgTurnaround = totalTurnaround / n;
    m.avgWaiting    = totalWaiting    / n;
    m.avgResponse   = totalResponse   / n;
    return m;
}
