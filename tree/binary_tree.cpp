#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct node{
    node* left;
    int val;
    node* right;
};

void search_before(node* root){
    if(root != nullptr){
        cout << root->val << endl;
        search_before(root->left);
        search_before(root->right);
    }
    return;
}

void search_mid(node* root){
    if(root != nullptr){
        search_mid(root->left);
        cout << root->val << endl;
        search_before(root->right);
    }
    return;
}

void search_after(node* root){
    if(root != nullptr){
        search_after(root->left);
        search_after(root->right);
        cout << root->val << endl;
    }
    return;
}

int main (int argc, char** argv){ 
    return 0; 
}

