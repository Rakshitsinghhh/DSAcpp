#include <iostream>
#include <vector>
using namespace std;

class BankersAlgorithm {
private:
    int n, m; 
    vector<vector<int>> allocation, maximum, need;
    vector<int> available;

public:
    BankersAlgorithm(int processes, int resources) {
        n = processes;
        m = resources;

        allocation.resize(n, vector<int>(m));
        maximum.resize(n, vector<int>(m));
        need.resize(n, vector<int>(m));
        available.resize(m);
    }

    void inputData() {
        cout << "Enter Available Resources: ";
        for (int i = 0; i < m; i++) {
            cin >> available[i];
        }

        cout << "Enter Allocation Matrix: \n";
        for (int i = 0; i < n; i++) {
            cout << "Process " << i+1 << ": ";
            for (int j = 0; j < m; j++) {
                cin >> allocation[i][j];
            }
        }

        cout << "Enter Maximum Matrix: \n";
        for (int i = 0; i < n; i++) {
            cout << "Process " << i+1 << ": ";
            for (int j = 0; j < m; j++) {
                cin >> maximum[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                need[i][j] = maximum[i][j] - allocation[i][j];
            }
        }
    }

    bool isSafeState() {
        vector<int> work = available;
        vector<bool> finish(n, false);
        int count = 0;

        while (count < n) {
            bool progressMade = false;
            for (int i = 0; i < n; i++) {
                if (!finish[i]) {
                    bool canFinish = true;
                    for (int j = 0; j < m; j++) {
                        if (need[i][j] > work[j]) {
                            canFinish = false;
                            break;
                        }
                    }

                    if (canFinish) {
                        for (int j = 0; j < m; j++) {
                            work[j] += allocation[i][j];
                        }
                        finish[i] = true;
                        progressMade = true;
                        count++;
                        break;
                    }
                }
            }

            if (!progressMade) {
                return false;
            }
        }

        return true;
    }

    bool requestResources(int processID, vector<int>& request) {
        for (int i = 0; i < m; i++) {
            if (request[i] > need[processID][i]) {
                cout << "Error: Process has exceeded maximum claim.\n";
                return false;
            }
        }

        for (int i = 0; i < m; i++) {
            if (request[i] > available[i]) {
                cout << "Error: Resources not available.\n";
                return false;
            }
        }

        for (int i = 0; i < m; i++) {
            available[i] -= request[i];
            allocation[processID][i] += request[i];
            need[processID][i] -= request[i];
        }

        if (isSafeState()) {
            cout << "Request granted.\n";
            return true;
        } else {
            for (int i = 0; i < m; i++) {
                available[i] += request[i];
                allocation[processID][i] -= request[i];
                need[processID][i] += request[i];
            }
            cout << "Request denied (unsafe state).\n";
            return false;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    BankersAlgorithm bank(n, m);
    bank.inputData();

    int processID;
    vector<int> request(m);

    cout << "Enter process ID for requesting resources (1 to " << n << "): ";
    cin >> processID;
    processID--;

    cout << "Enter resource request for process " << processID + 1 << ": ";
    for (int i = 0; i < m; i++) {
        cin >> request[i];
    }

    bank.requestResources(processID, request);

    return 0;
}
