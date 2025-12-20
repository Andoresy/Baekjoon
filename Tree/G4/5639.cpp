#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct node{
    struct node* left = nullptr;
    struct node* right = nullptr;
    int value;
}Node;
void insert(Node* x, int value){
    if(x->value > value){
        if(x->left == nullptr){
            Node* nNode = new Node();
            nNode->value = value;
            x->left = nNode;
        }else{
            insert(x->left, value);
        }
    }else{
        if(x->right == nullptr){
            Node* nNode = new Node();
            nNode->value = value;
            x->right = nNode;
        }else{
            insert(x->right, value);
        }
    }
}
void postorder(Node* x){
    if(x->left != nullptr) postorder(x->left);
    if(x->right != nullptr) postorder(x->right);
    cout << x->value << "\n";
}
int main(){
    int x;
    Node root;
    cin >> x;
    root.value = x;
    while(cin >> x){
        insert(&root, x);
    }
    postorder(&root);
}