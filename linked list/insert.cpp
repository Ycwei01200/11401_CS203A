#include <iostream>
using namespace std;

struct Node {
    int val;  // 可選的任意資料
    Node* next;  // 下一個節點
};


int main() {
    Node* head = new Node();
    head->next = new Node();
    head->next->next = new Node();
    head->next->next->next = new Node();
    head->val = 10;
    //head->next->val=30;//創造node
    Node* node = new Node();
    head->next->val=20;
    head->next->next->val = 30;
    head->next->next->next = nullptr;
    
    while(node){
        cout<<node->val<<" ";
        node = node->next;
    }
    delete node;delete head;
    return 0;
}
