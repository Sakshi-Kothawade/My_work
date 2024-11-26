#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);
    bool slot[n] = {0};
    char result[n];

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Selected Jobs in sequence: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n = 5;
    Job jobs[] = { {'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, 
                   {'D', 1, 25}, {'E', 3, 15} };
    jobSequencing(jobs, n);
    return 0;
}
