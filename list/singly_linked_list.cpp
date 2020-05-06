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
        cout << temp->v << ",";
        temp = temp->next;
    }
    cout << endl;
    return;
}

// 递归反转
node* recursiveReverseList(node*head){
    // 如果 为空或者
    if(!head || head->next)
        return head;

    node* end = recursiveReverseList(head->next);
    head->next->next = head;
    head->next = nullptr; 
    return end;
}


void reverseList(node** head){
    if(!(*head) || !(*head)->next) 
        return;
    node* pre = *head;
    node* cur = (*head)->next;
    node* temp = nullptr;
    (*head)->next = nullptr;

    // 如果当前节点存在
    while(cur){
        // 那么先记录当前节点后一个节点的位置，因为之后要将他进行翻转。 
        temp = cur->next;
        cur->next = pre;
        
        // 将当前节点后移。
        pre = cur;
        cur = temp;
    }
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
            break;
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
node* combine(node* h1, node* h2){
    if(!h1 && !h2){
        return nullptr;
    }
    node* ret = new node();
    node* temp = ret;

    while(h1 && h2){
        // 比较 h1和 h2的内容的大小，将较小的那个拼在链表尾部
        if(h1->v >= h2->v){
           temp->next = h2;
           temp = h2; 
           h2 = h2->next;
        }else{
            temp->next = h1;
            temp = h1;
            h1 = h1->next;
        }
    }

    h1? temp->next=h1: temp->next=h2;

    temp =  ret->next;
    delete(ret);
    return temp;
}

// 删除倒数第N个数 
node* deleteN(node* head, int n){
// 想法:快慢指针 慢指针先走一段路
// 要注意 如果是删除第一个元素的话，不能取到prev.
    node* slow= head, *fast =head;
    while(n--){
        fast = fast->next;
    }

    if(!fast){
        head = head->next;
        return head;
    }

    node* prev=nullptr;
    while(fast){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = slow->next;
    return head;
}

// 查找中点
node* findCenter(node* head){
    if(!head)
        return nullptr;

    // 快慢指针， 快只针到底的时候 慢指针刚好到一半。
    // 分两种情况一个是偶数 一个不是偶数。
    node* fast = head;
    node* slow = head;
    while(fast){
        // 证明后面还可以遍历一次
        if(fast->next->next && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        if(!fast->next){
            // 说明链表长度刚好是奇数，则慢指针刚好在中间
            return slow;
        }
        
        if(!fast->next->next){
            // 说明链表长度是偶数，则满指针在中间的偏左
            return slow;
        }
    }
}

int main(int argc, char** argv){
    node *head;
    makeList(1, &head);
    for(auto i=1;i<10;i++){
        appendToList(head, i);
    }
    // printList(head);
    // reverseList(&head);
    // printList(head);

    node * h1, * h2;
    makeList(1, &h1);
    for(auto i=1; i<20;i+=2){
        appendToList(h1, i);
    }
    printList(h1);

    makeList(1, &h2);
    for(auto i=1; i<20;i+=3){
        appendToList(h2, i);
    }
    printList(h2);
    node* h3 = combine(h1,h2);
    printList(h3);

    cout << findCenter(h2)->v << endl;
    return 0;
}