# CPU Scheduling Algorithms

This project implements three fundamental CPU scheduling algorithms in C as part of an Operating Systems course project.

## Algorithms Implemented

1. **FCFS (First Come First Serve)**
2. **SJF (Shortest Job First - Non-Preemptive)**
3. **Round Robin (RR)**

Each algorithm computes the following performance metrics:
- Average Turnaround Time
- Average Waiting Time
- Average Response Time

## File Structure

```
.
├── scheduler.h         # Declarations for structs and scheduling functions
├── scheduler.c         # Implementation of the scheduling algorithms
├── scheduler_test.c    # Test cases and assertions for validating correctness
├── Makefile            # Build automation script
└── README.md           # Project documentation (this file)
```

## How to Compile

To build the project, simply use:

```bash
make
```

This compiles the source files and produces an executable named `scheduler_test`.

## How to Run

To run the compiled test program:

```bash
make run
```

This will execute the scheduler tests and print the calculated vs. expected metrics for:
- FCFS
- SJF
- Round Robin (with specified quantum)

If all assertions pass, you will see:

```
>>> Test Case X PASSED.
...
ALL TESTS PASSED.
```

## How to Clean

To remove the compiled binary:

```bash
make clean
```

## Example Output (Truncated)

```
==== Test Case 1 ====
FCFS: Calculated: Turnaround: 15.00, Waiting: 7.33, Response: 7.33
      Expected:   Turnaround: 15.00, Waiting: 7.33, Response: 7.33
SJF:  Calculated: Turnaround: 15.00, Waiting: 7.33, Response: 7.33
      Expected:   Turnaround: 15.00, Waiting: 7.33, Response: 7.33
RR (Quantum = 4): Calculated: Turnaround: 19.33, Waiting: 11.67, Response: 3.00
         Expected:   Turnaround: 19.33, Waiting: 11.67, Response: 3.00
>>> Test Case 1 PASSED.

==== Test Case 2 ====
FCFS: Calculated: Turnaround: 5.67, Waiting: 1.67, Response: 1.67
      Expected:   Turnaround: 5.67, Waiting: 1.67, Response: 1.67
SJF:  Calculated: Turnaround: 5.67, Waiting: 1.67, Response: 1.67
      Expected:   Turnaround: 5.67, Waiting: 1.67, Response: 1.67
RR (Quantum = 2): Calculated: Turnaround: 5.67, Waiting: 1.67, Response: 1.00
         Expected:   Turnaround: 5.67, Waiting: 1.67, Response: 1.00
>>> Test Case 2 PASSED.

==== Test Case 3 ====
FCFS: Calculated: Turnaround: 5.75, Waiting: 3.25, Response: 3.25
      Expected:   Turnaround: 5.75, Waiting: 3.25, Response: 3.25
SJF:  Calculated: Turnaround: 5.00, Waiting: 2.50, Response: 2.50
      Expected:   Turnaround: 5.00, Waiting: 2.50, Response: 2.50
RR (Quantum = 2): Calculated: Turnaround: 6.25, Waiting: 3.75, Response: 1.75
         Expected:   Turnaround: 6.25, Waiting: 3.75, Response: 1.75
>>> Test Case 3 PASSED.

==== Test Case 4 ====
FCFS: Calculated: Turnaround: 8.60, Waiting: 4.60, Response: 4.60
      Expected:   Turnaround: 8.60, Waiting: 4.60, Response: 4.60
SJF:  Calculated: Turnaround: 7.60, Waiting: 3.60, Response: 3.60
      Expected:   Turnaround: 7.60, Waiting: 3.60, Response: 3.60
RR (Quantum = 3): Calculated: Turnaround: 10.60, Waiting: 6.60, Response: 2.60
         Expected:   Turnaround: 10.60, Waiting: 6.60, Response: 2.60
>>> Test Case 4 PASSED.

==== Test Case 5 (Single Process) ====
FCFS: Calculated: Turnaround: 5.00, Waiting: 0.00, Response: 0.00
      Expected:   Turnaround: 5.00, Waiting: 0.00, Response: 0.00
SJF:  Calculated: Turnaround: 5.00, Waiting: 0.00, Response: 0.00
      Expected:   Turnaround: 5.00, Waiting: 0.00, Response: 0.00
RR (Quantum = 2): Calculated: Turnaround: 5.00, Waiting: 0.00, Response: 0.00
         Expected:   Turnaround: 5.00, Waiting: 0.00, Response: 0.00
>>> Test Case 5 (Single Process) PASSED.

==== Test Case 6 (Two Processes, Same Arrival) ====
FCFS: Calculated: Turnaround: 7.00, Waiting: 2.00, Response: 2.00
      Expected:   Turnaround: 7.00, Waiting: 2.00, Response: 2.00
SJF:  Calculated: Turnaround: 7.00, Waiting: 2.00, Response: 2.00
      Expected:   Turnaround: 7.00, Waiting: 2.00, Response: 2.00
RR (Quantum = 3): Calculated: Turnaround: 8.50, Waiting: 3.50, Response: 1.50
         Expected:   Turnaround: 8.50, Waiting: 3.50, Response: 1.50
>>> Test Case 6 (Two Processes, Same Arrival) PASSED.

==== Test Case 7 (Varying Arrivals) ====
FCFS: Calculated: Turnaround: 15.25, Waiting: 8.75, Response: 8.75
      Expected:   Turnaround: 15.25, Waiting: 8.75, Response: 8.75
SJF:  Calculated: Turnaround: 14.25, Waiting: 7.75, Response: 7.75
      Expected:   Turnaround: 14.25, Waiting: 7.75, Response: 7.75
RR (Quantum = 3): Calculated: Turnaround: 20.00, Waiting: 13.50, Response: 3.00
         Expected:   Turnaround: 20.00, Waiting: 13.50, Response: 3.00
>>> Test Case 7 (Varying Arrivals) PASSED.

==== Test Case 8 (Six Processes) ====
FCFS: Calculated: Turnaround: 17.00, Waiting: 11.17, Response: 11.17
      Expected:   Turnaround: 17.00, Waiting: 11.17, Response: 11.17
SJF:  Calculated: Turnaround: 15.17, Waiting: 9.33, Response: 9.33
      Expected:   Turnaround: 15.17, Waiting: 9.33, Response: 9.33
RR (Quantum = 4): Calculated: Turnaround: 20.67, Waiting: 14.83, Response: 6.33
         Expected:   Turnaround: 20.67, Waiting: 14.83, Response: 6.33
>>> Test Case 8 (Six Processes) PASSED.

ALL TESTS PASSED.

```

## Notes

- The `Process` struct contains fields for tracking all timing metrics.
- All algorithms are non-preemptive except RR which uses time slicing.
- The project is written in standard C and should work on any Unix-like system (Linux, macOS, WSL).
