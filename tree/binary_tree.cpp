#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct node{
    node* left;
    int val;
    node* right;
};

// 前序遍历 root->left->right
void search_before(node* root){
    if(root != nullptr){
        cout << root->val << endl;
        search_before(root->left);
        search_before(root->right);
    }
    return;
}

// 中序遍历 left->root->right
void search_mid(node* root){
    if(root != nullptr){
        search_mid(root->left);
        cout << root->val << endl;
        search_before(root->right);
    }
    return;
}

// 后序遍历 left->right->root
void search_after(node* root){
    if(root != nullptr){
        search_after(root->left);
        search_after(root->right);
        cout << root->val << endl;
    }
    return;
}

node* search(node* root, int n){
    while(root){
        if(root->val<n){
            root= root->right;
        }else if(root->val>n){
            root = root->left;
        }else{
            return root;
        }
    }
    return nullptr;
}


int main (int argc, char** argv){ 

    return 0; 
}

