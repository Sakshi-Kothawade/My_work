// A. Consider a friend’s network on facebook social web site. Model it as a graph to
// represent each node as a user and a link to represent the friend relationship between
// them. Store data such as date of birth, number of comments for each user.
// 1. Find who is having maximum friends
// 2. Find who has post maximum and minimum comments
// 3. Find users having birthday in this month
// Hint: (Use adjacency list representation and perform DFS and BFS traversals)

#include <iostream>
#include <string>
using namespace std;

// Max number of users in the network
const int MAX_USERS = 100;

int graph[MAX_USERS][MAX_USERS]; // Adjacency matrix
string birthdays[MAX_USERS];      // Store date of birth as "YYYY-MM-DD"
int comments[MAX_USERS];          // Store the number of comments for each user
int numUsers;                     // Total number of users  

// Function to add friendship (bidirectional relationship)
void addFriendship(int user1, int user2) {
    graph[user1][user2] = 1;
    graph[user2][user1] = 1;
}

// Find user with maximum friends
int findMaxFriends() {
    int maxFriends = 0;
    int userWithMaxFriends = -1;
    
    for (int i = 0; i < numUsers; i++) {
        int friendCount = 0;
        for (int j = 0; j < numUsers; j++) {
            if (graph[i][j] == 1) {
                friendCount++;
            }
        }
        if (friendCount > maxFriends) {
            maxFriends = friendCount;
            userWithMaxFriends = i;
        }
    }
    return userWithMaxFriends;
}

// Find user with maximum and minimum comments
void findMaxMinComments(int &maxUser, int &minUser) {
    int maxComments = -1;
    int minComments = 1e9;

    for (int i = 0; i < numUsers; i++) {
        if (comments[i] > maxComments) {
            maxComments = comments[i];
            maxUser = i;
        }
        if (comments[i] < minComments) {
            minComments = comments[i];
            minUser = i;
        }
    }
}

// Find users with birthdays this month
void findBirthdaysThisMonth(int month) {
    bool found = false;
    for (int i = 0; i < numUsers; i++) {
        int birthMonth = stoi(birthdays[i].substr(3, 2)); // Extract month from "YYYY-MM-DD"
        if (birthMonth == month) {
            found = true;
            cout << "User " << i + 1 << " has a birthday this month.\n";
        }
    }
    if (!found) {
        cout << "No users have a birthday this month.\n";
    }
}

int main() {
    // Input number of users
    cout << "Enter the number of users: ";
    cin >> numUsers;

    // Input user details
    for (int i = 0; i < numUsers; i++) {
        cout << "Enter birthday (DD-MM-YYYY) for user " << i + 1 << ": ";
        cin >> birthdays[i];
        cout << "Enter number of comments for user " << i + 1 << ": ";
        cin >> comments[i];
    }

    // Input friendships
    int numFriendships;
    cout << "Enter number of friendships: ";
    cin >> numFriendships;

    for (int i = 0; i < numFriendships; i++) {
        int user1, user2;
        cout << "Enter friendship pair (user1 user2): ";
        cin >> user1 >> user2;
        addFriendship(user1 - 1, user2 - 1); // Adjust for 0-based index
    }

    // 1. Find user with maximum friends
    int maxFriendsUser = findMaxFriends();
    cout << "User with maximum friends: User " << maxFriendsUser + 1 << "\n";

    // 2. Find user with maximum and minimum comments
    int maxCommentsUser, minCommentsUser;
    findMaxMinComments(maxCommentsUser, minCommentsUser);
    cout << "User with maximum comments: User " << maxCommentsUser + 1 << "\n";
    cout << "User with minimum comments: User " << minCommentsUser + 1 << "\n";

    // 3. Find users with birthdays this month
    int currentMonth;
    cout << "Enter the current month (1-12): ";
    cin >> currentMonth;
    findBirthdaysThisMonth(currentMonth);

    return 0;
}

