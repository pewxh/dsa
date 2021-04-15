#include<iostream>
using namespace std;

class TreeNode{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode();
        TreeNode(int);
};
TreeNode::TreeNode(){
    value = 0;
    left = right = NULL;
}
TreeNode::TreeNode(int v){
    value = v;
    left = right = NULL;
}

class BST{
    public:
        TreeNode* root;
        bool isEmpty();
};
bool BST::isEmpty(){
    return (root == NULL);
}

int main(){
    int choice;
    do{
        cout << "Select Choice \n";
        cout << "0 \t EXIT \n";
        cout << "1 \t Insert \n";
        cout << "2 \t Search \n";
        cout << "3 \t Delete \n";
        cout << "4 \t Print \n";
        cout << "5 \t Clear Screen \n";
        cin >> choice;
        switch(choice){
            case 0: 
                break;
            case 1:
                cout << "\n Enter Node To Insert \t ";
                break;
            case 2:
                cout << "\n Enter Node To Search \t";
                break;
            case 3:
                cout << "\n Enter Node To Delete \t";
                break;
            case 4:
                break;
            case 5:
                system("cls");
                break;
            default:
                cout << "Oops! Enter Valid Choice \n";
        }
    }while(choice);
    return 0;
}