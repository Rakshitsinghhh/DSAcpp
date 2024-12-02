#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int process[n], bt[n], tat[n], rem_bt[n], wt[n] = {0};

    // Initialize process IDs
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }

    // Input burst times
    cout << "Enter burst times of processes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> bt[i];
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Input time quantum
    cout << "Enter time quantum: ";
    int tc;
    cin >> tc;

    // Round Robin Scheduling
    int time = 0;
    queue<int> q;

    // Add all processes to the queue
    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (rem_bt[i] <= tc) {
            time += rem_bt[i];
            tat[i] = time; // Turnaround time = completion time
            rem_bt[i] = 0; // Process completed
        } else {
            time += tc;
            rem_bt[i] -= tc;
            q.push(i); // Re-add process to the queue
        }
    }

    // Calculate waiting times
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i]; // Waiting time = turnaround time - burst time
    }

    // Display results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << process[i] << "\t" << bt[i] << "\t\t" 
             << wt[i] << "\t\t" << tat[i] << endl;
    }

    return 0;
}
