#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

int hashFunction(string name) {
    int hashValue = 0;
    for (char ch : name) {
        hashValue += ch;
    }
    return hashValue % TABLE_SIZE;
}

class HashTableSeparateChaining {
    vector<list<pair<string, string>>> table;

public:
    HashTableSeparateChaining() {
        table.resize(TABLE_SIZE);
    }

    void insert(string name, string phone) {
        int index = hashFunction(name);
        table[index].push_back({name, phone});
    }

    string find(string name, int &comparisons) {
        int index = hashFunction(name);
        comparisons = 0;
        for (const auto &entry : table[index]) {
            comparisons++;
            if (entry.first == name) {
                return entry.second;
            }
        }
        return "Not found";
    }
};

class HashTableLinearProbing {
    vector<pair<string, string>> table;
    vector<bool> isOccupied;

public:
    HashTableLinearProbing() {
        table.resize(TABLE_SIZE, {"", ""});
        isOccupied.resize(TABLE_SIZE, false);
    }

    void insert(string name, string phone) {
        int index = hashFunction(name);
        int originalIndex = index;
        while (isOccupied[index]) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) break;
        }
        table[index] = {name, phone};
        isOccupied[index] = true;
    }

    string find(string name, int &comparisons) {
        int index = hashFunction(name);
        int originalIndex = index;
        comparisons = 0;
        while (isOccupied[index]) {
            comparisons++;
            if (table[index].first == name) {
                return table[index].second;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) break;
        }
        return "Not found";
    }
};

int main() {
    HashTableSeparateChaining hashTableChaining;
    HashTableLinearProbing hashTableProbing;

    int n;
    cout << "Enter the number of clients: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, phone;
        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter client phone number: ";
        cin >> phone;

        hashTableChaining.insert(name, phone);
        hashTableProbing.insert(name, phone);
    }

    string searchName;
    cout << "\nEnter the name of the client to search for: ";
    cin >> searchName;

    int comparisonsChaining = 0;
    int comparisonsProbing = 0;

    string phoneChaining = hashTableChaining.find(searchName, comparisonsChaining);
    string phoneProbing = hashTableProbing.find(searchName, comparisonsProbing);

    cout << "\n--- Results ---" << endl;
    cout << "Separate Chaining - Phone: " << phoneChaining << ", Comparisons: " << comparisonsChaining << endl;
    cout << "Linear Probing - Phone: " << phoneProbing << ", Comparisons: " << comparisonsProbing << endl;

    return 0;
}
