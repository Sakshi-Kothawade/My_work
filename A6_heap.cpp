#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> readMarks(int n) {
    vector<int> marks(n);
    cout << "Enter the marks obtained by each student:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }
    return marks;
}

int findMinMarks(const vector<int>& marks) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int mark : marks) {
        minHeap.push(mark);
    }
    return minHeap.top();
}

int findMaxMarks(const vector<int>& marks) {
    priority_queue<int> maxHeap;
    for (int mark : marks) {
        maxHeap.push(mark);
    }
    return maxHeap.top();
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks = readMarks(n);

    int minMarks = findMinMarks(marks);
    int maxMarks = findMaxMarks(marks);

    cout << "Minimum marks: " << minMarks << endl;
    cout << "Maximum marks: " << maxMarks << endl;

    return 0;
}
