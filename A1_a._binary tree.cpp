// A. Create Binary tree and perform following operations:
// a. Insert
// b. Display
// c. Find Depth of a tree
// d. Display leaf-nodes
// e. Create a copy of a tree.

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

node* buildTree(node*root){
    int data;
    cout<<"enter the data:"<<endl;
    cin>>data;
    root=new node(data);

    if (data==-1){ //base case
        return NULL;
    }

    // cout<<"Enter data for inserting in left:"<<endl;
    cout << "Enter data to left of " << data << ": "<<endl;
    root->left=buildTree(root->left);//recursive condition 
    // cout<<"Enter data for inserting in right:"<<endl;
    cout << "Enter data to right of " << data << ": "<<endl;
    root->right=buildTree(root->right);//recursive condition
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

int depth_tree(node*root){
    if(root==NULL){
        return 0;
    }
    int left_depth=depth_tree(root->left);
    int right_depth=depth_tree(root->right);

    return max(left_depth,right_depth)+1;
}

void inorder_leafcount(node*root){
    //function for leaf count
    if(root==NULL){
        return;
    }

    inorder_leafcount(root->left);
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" "<<endl;
    }
    inorder_leafcount(root->right);
}

node*copy_tree(node*root){
    if(root==NULL){
        return NULL;
    }

    node*new_root=new node(root->data);
    new_root->left=copy_tree(root->left);
    new_root->right=copy_tree(root->right);
    return new_root;
}

void exit_program(){
    cout<<"Exiting the program"<<endl;
    exit(0);
}

int main() {
    node* root = NULL;
    int depth=0;
    node* copied_tree=NULL;
    // node* copyRoot = copyInOrder(root);

    while(1) {
        int sw_case;
        cout << "1. Creating Binary Tree" << endl;
        cout << "2. Displaying Binary Tree" << endl;
        cout << "3. Finding Depth Of Tree" << endl;
        cout << "4. Display Leaf Nodes" << endl;
        cout << "5. Creating Copy of Tree" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Input: ";
        cin >> sw_case;

        switch (sw_case) {
        case 1:
            cout<<"Creating the binary tree:"<<endl;
            root=buildTree(root);//building a tree
            break;

        case 2:
            cout << "Display Binary Tree" << endl;
            cout<< "Level traversal representation:"<<endl;
            leve_lorder_traversal(root);
            cout<<endl;

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
            cout << "Finding Depth of Tree" << endl;
            depth=depth_tree(root);
            cout<<"Depth of tree is:"<<depth<<endl;
            break;

        case 4:
            cout << "Display Leaf Nodes" << endl;
            cout << "Leaf Nodes: "<<endl;
            inorder_leafcount(root);
            break;

        case 5:
            cout << "Creating Copy of Binary Tree" << endl;
            copied_tree=copy_tree(root);
            cout<<"copy of tree is:"<<endl;
            leve_lorder_traversal(copied_tree);
            cout<<endl;
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