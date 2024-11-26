#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapNames(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &credits, vector<string> &names, int low, int high) {
    int pivot = credits[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (credits[j] >= pivot) {
            i++;
            swap(credits[i], credits[j]);
            swapNames(names[i], names[j]);
        }
    }
    swap(credits[i + 1], credits[high]);
    swapNames(names[i + 1], names[high]);
    return (i + 1);
}

void quickSort(vector<int> &credits, vector<string> &names, int low, int high) {
    if (low < high) {
        int pi = partition(credits, names, low, high);
        quickSort(credits, names, low, pi - 1);
        quickSort(credits, names, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<string> names(n);
    vector<int> credits(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the credits received by " << names[i] << ": ";
        cin >> credits[i];
    }

    quickSort(credits, names, 0, n - 1);

    cout << "\nTop 3 Students with the highest credits:\n";
    for (int i = 0; i < 3 && i < n; i++) {
        cout << i + 1 << ". " << names[i] << " - " << credits[i] << " credits\n";
    }

    return 0;
}
