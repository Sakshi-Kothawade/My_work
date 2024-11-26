#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* constructExpressionTree(const string& postfix) {
    stack<Node*> st;

    for (char c : postfix) {
        if (isspace(c)) continue;

        if (isdigit(c) || isalpha(c)) {
            st.push(new Node(string(1, c)));
        } else if (isOperator(c)) {
            Node* rightNode = st.top(); st.pop();
            Node* leftNode = st.top(); st.pop();
            Node* operatorNode = new Node(string(1, c));
            operatorNode->left = leftNode;
            operatorNode->right = rightNode;
            st.push(operatorNode);
        }
    }
    return st.top();
}

void inOrder(Node* root) {
    stack<Node*> st;
    Node* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top(); st.pop();
        cout << current->data << " ";

        current = current->right;
    }
}

void preOrder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* current = st.top(); st.pop();
        cout << current->data << " ";

        if (current->right) st.push(current->right);
        if (current->left) st.push(current->left);
    }
}

void postOrder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* current = st1.top(); st1.pop();
        st2.push(current);

        if (current->left) st1.push(current->left);
        if (current->right) st1.push(current->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
    string postfix;

    cout << "Enter a postfix expression (e.g., ab+c*): ";
    getline(cin, postfix);

    Node* root = constructExpressionTree(postfix);

    cout << "\nIn-order traversal: ";
    inOrder(root);

    cout << "\nPre-order traversal: ";
    preOrder(root);

    cout << "\nPost-order traversal: ";
    postOrder(root);

    cout << endl;
    return 0;
}
