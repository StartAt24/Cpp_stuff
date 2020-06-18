#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct node{
    node(int v):val(v){};
    node* left;
    int val;
    node* right;
};

class binarySearchTree{
public: 
    binarySearchTree():_root(nullptr){

    }

    ~binarySearchTree(){

    }

    int insert(int val){
        if(!_root){
            _root = new node(val);
            return 0;
        }

        node* p = _root;
        while(p){
            if(val>p->val){
                if(p->right == nullptr){
                    p->right = new node(val);
                    return 0;
                }
                p = p->right;
            }else if(val<p->val){
                if(p->left == nullptr){
                    p->left = new node(val);
                    return 0;
                }
                p = p->left;
            }else{
                cout << "already exist..." << endl;
                return -1;
            }
        }
        return 0;
    }

    node* search(int val){
        node* p = _root;
        while(p){
            if(val > p->val)
                p = p->right;
            else if(val < p->val)
                p = p->left;
            else 
                return p;
        }
        return nullptr;
    }

    int del(int val){
        node *p = _root, *pp = nullptr;
        while(p != nullptr && p->val != val){
            pp = p;
            if(p->val > val){
                p = p->left;
            }else 
                p = p->right;
        }

        // not found
        if(p==nullptr)
            return -1;
        
        // p have two child
        // 查找右子树的最小的数 
        if(p->left && p->right)
        {
            node* childP = p->right;
            node* childPP = p;            

            while(childP->left != nullptr) {
                childPP = childP; 
                childP = childP->left;
            }
            // 如果 此时是叶子节点。则直接替换
            p->val = childP->val;

            // 将问题归一为删除某个节点。
            p = childP;
            pp = childPP;
        }

        // p是一个叶子节点 或者仅有一个子节点。
        node* only_child=nullptr;
        if(p->left != nullptr) only_child=p->left;
        else if(p->right != nullptr) only_child = p->right;

        // 删除的是根节点, 这个条件进来的情况是 当树仅有一个节点 或者 root只有一个左节点或者右节点。
        if(pp == nullptr) {
            cout << " delete root" << endl;
            _root=only_child;
        } 
        else if(pp->left == p) pp->left = only_child;
        else pp->right = only_child;
        
        return 0;
    }

    void print(){
       print(_root);
    }

    void print_root(){
        if(!_root)
            return;
        cout << "root is:" << _root->val << endl;
    }

    void print_height(){
        cout << "height is:" << height(_root) << endl;
    }

private:
    void print(node* p){
        if(!p)
            return;
        print(p->left);
        cout << p->val << endl;
        print(p->right);
        return;
    }

    int height(node* p){
        if(!p)
            return 0;
        else
        {
            if(height(p->left) > height(p->right))
                return 1+height(p->left);
            else
                return 1+height(p->right);
        }
    }

private:
    node* _root;
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
    binarySearchTree t;
    t.insert(6);
    t.insert(3);
    t.insert(1);
    t.print_height();

    cout << "---------" << endl;
    t.del(6);
    t.print_height();
    return 0; 
}

