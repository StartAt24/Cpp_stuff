#include <iostream>
#include <list>
using namespace std;

struct node{
    node* next=nullptr;
    int v=0;
};

int makeList(int len, node** head){
    if(len<=0){
        *head = nullptr;
        return -1;
    }       
    *head = new node();
    node* current = *head;
    for(int i=0; i<len-1; i++){
        current->next = new node();
        current = current->next;
    }
    return 0;
}

int clearList(node**head){
    if(!head)
        return -1;
    
    node* current = *head;
    while(current){
        node* old = current;
        current = current->next;     
        delete old;
        old = nullptr;
    }

    *head = nullptr;
    return 0;
}

int appendToList(node* head,int val){
    if(!head)
        return -1;
    node* current = head;
    while(current->next){
        current = current->next;
    }
    node* n = new node();
    n->v = val;
    current->next = n;
    return 0;
}

void printList(node* head){
    if(!head)
        return;
    node* temp = head;
    while(temp){
        cout << temp->v << endl;
        temp = temp->next;
    }
    return;
}

void reverseList(node** head){
    if(!(*head) || !(*head)->next) 
        return;

    node* n1 = *head;
    node* n2 = n1->next;
    node* n3 = n1->next->next;

    n1->next =nullptr;
    n2->next =n1; 

    while(n3){
        n1 = n2;
        n2 = n3;
        n3 = n3->next;

        n2->next = n1;
    }

    *head = n2; 
    return;
}

// 链表环检测, 并且返回环的起点
// answer1: 找一个map将所有的走过的节点放进去，以后如果遇到的话 说明有环，如果一直到null都没有遇到就说明没有环
// answer2: 快慢指针

bool checkCircle(node* head, node** entry){
    if(!head)
        return false;

    node* slow_ptr = head;
    node* fast_ptr = head;
    *entry = nullptr;

    bool isCircle = false;
    while(fast_ptr && fast_ptr->next){
        slow_ptr=slow_ptr->next;
        // faster_ptr step is 2
        fast_ptr =fast_ptr->next->next;

        if(slow_ptr == fast_ptr){
            isCircle = true;
        }
    }

    if(isCircle){
        // （x+y）*2 = mc + x +y
        // 此时将快指针放到起始位置，再以慢指针的速度走，再次相遇的节点即为入口。
        fast_ptr = head;
        while(true){
            if(fast_ptr == slow_ptr){
                break;
            }
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        *entry = fast_ptr;
    }

    return isCircle;  
}

// 两个有序链表合并
void combine(node* h1, node* h2, node* h3){


}

// 
void deleteN(node* head){

}


node* findCenter(node* head){

    return nullptr;
}

int main(int argc, char** argv){
    node *head;
    makeList(1, &head);
    for(auto i=1;i<10;i++){
        appendToList(head, i);
    }
    printList(head);
    reverseList(&head);
    printList(head);

    return 0;
}