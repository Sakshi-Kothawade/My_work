// b. Implement binary search tree and perform following operations:
// a. Insert b. Delete c. Display d. Search e. BFS (Level wise print)
#include <iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;

    node(int new_data){
        this->data=new_data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* bst_insert(node*root,int data){
    if (root == NULL) {
        return new node(data);
    }
    else if (data < root->data) {
        root->left = bst_insert(root->left, data);
    } 
    else if (data > root->data){
        root->right = bst_insert(root->right, data);
    }
    else{
        cout<<"Do not enter duplicate data"<<endl;
    }
    return root;
}
    
void leve_lorder_traversal(node*root){
    queue<node*> q;
    
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            //purana level traverse ho chuka he
            cout<<endl;
            if (!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }

        else{
            cout<<temp -> data <<" ";
            if(temp->left){
                q.push(temp->left);

            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
void inorder(node*root){
    //left-root-right
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node*root){
    //root-left-right
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    //left-right-root
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int search(node*root,int num_search,int level=0){
    if(root==NULL)
        return -1;

    if(root->data==num_search)
        return level;

    if(root->data > num_search)
        return search(root->left,num_search,level+1);

    return search(root->right,num_search,level+1);
}

node* findMin(node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

node* deleteNode(node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data){
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data){
        root->right = deleteNode(root->right, key);
    }

    else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void exit_program(){
    cout<<"Exiting the program"<<endl;
    exit(0);
}

int main(){
    node* root = NULL;
    int data;
    int tar;
    int search_node;
    int level;

    while(1) {
        int sw_case;
        cout << "1. Creating Binary search Tree" << endl;
        cout << "2. Displaying Binary search Tree" << endl;
        cout << "3. Deleting node of Binary search Tree"  << endl;
        cout << "4. Searching node" << endl;
        cout << "5. Level wise print" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Input: ";
        cin >> sw_case;

        switch (sw_case) {
        case 1:
            cout<<"Creating the binary search tree:"<<endl;
            while (true) {
                cout << "Enter data to insert into BST (-1 to stop):" << endl;
                cin >> data;
                if (data == -1) {
                    break;
                }
                root = bst_insert(root, data);
            }
            break;

        case 2:
            cout << "Display Binary Search Tree" << endl;

            cout << "Inorder Representation: ";
            inorder(root);
            cout << endl;

            cout << "Preorder Representation: ";
            preorder(root);
            cout << endl;

            cout << "Postorder Representation: ";
            postorder(root);
            cout << endl;

            break;

        case 3:
            cout<<"Enter node to delete:"<<endl;
            cin>>tar;
            deleteNode(root,tar);

            cout<<"Tree after deletion of "<<tar<<endl;
            inorder(root);
            cout << endl;
            break;
            
        case 4:
            cout << "Enter the node to search" << endl;
            cin>>search_node;
            level=search(root,search_node);

            if (level!= -1) {
                    cout << "Key " << search_node << " found at level " << search << endl;
                } else {
                    cout << "Key " << search_node << " not found." << endl;
                }
            break;

        case 5:
            cout << "Level wise representation of BST:" << endl;
            leve_lorder_traversal(root);
            break;
        
        case 6:
            exit_program();
            break;

        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
    return 0;
}
    