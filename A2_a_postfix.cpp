#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

TreeNode* constructExpressionTree(const string& exp) {
    stack<TreeNode*> st;
    
    for (int i=0;i<exp.size();i++) {
        if (isOperator(exp[i])) { 
            TreeNode* rightNode = st.top(); st.pop();
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* node = new TreeNode(exp[i]);
            node->left = leftNode;
            node->right = rightNode;
            st.push(node);
        } else {
            st.push(new TreeNode(exp[i]));
        }
    }

    return st.top();
}

void nonRecursiveInOrderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->value << " ";

        curr = curr->right;
    }
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    TreeNode* root = constructExpressionTree(postfix);

    cout << "Non-recursive In-Order Traversal: ";
    nonRecursiveInOrderTraversal(root);
    cout << endl;

    return 0;
}
