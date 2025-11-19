#include<iostream>
using namespace std;
struct node{
    int value;
    node* next;
};
void insert_in_tail(node*& head,int val){
    node* current = head;
    if(current == NULL){
        head = new node();
        head->value = val;
        head->next = NULL;
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    node* insert_node = new node();
    insert_node->next = NULL;
    insert_node->value = val;
    current->next = insert_node;
}
void delete_in_head(node*& head){
    if(head == NULL) return;
    node* temp = head;//暫存舊的指標
    head = head->next;//確保鏈結成功
    delete temp;//刪除指標
}
void delete_in_middle(node*& head, int val){
    if(head == NULL) return;
    node* current = head;
    while(current->next != NULL && current->next->value != val){
        current = current -> next;
    }
    node* temp = current->next;//暫存舊的指標
    current->next = current->next->next;
    delete temp;//刪除指標
}
void delete_in_tail(node*& head){
    if(head == NULL) return;

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node* current = head;

    while(current->next->next != NULL){
        current = current->next;
    }
    node* temp = current->next; // 鎖定最後一個節點
    current->next = NULL;       // 斷開連結
    delete temp;
}
void delete_in_list(node*& head,int val){
    if(head == NULL)return;
    node* current = head;
    if(current->value == val){
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while(current->next != NULL && current->next->value != val){
        current = current -> next;
    }
    if(current->next == NULL) return; //沒找到
    
    node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    

}
void move_to(node* head,int form_val,int to_val){
    if(head == NULL) return;
    node* prev_form = head;
    node* current1  = head;
    node* prev_to   = head;
    node* current2  = head;
    while(prev_form->next != NULL && prev_form->next->value != form_val){
        prev_form = prev_form->next;
    }
    current1  = prev_form->next;
    while(prev_to->next != NULL && prev_to->next->value != to_val){
        prev_to = prev_to->next;
    }
    current2  = prev_to->next;
    
    prev_form->next = prev_form->next->next;
    current1->next  = NULL;

    prev_to->next   = prev_to->next->next;
    current2->next  = NULL;

    
    current1->next = prev_to->next;
    prev_to->next  = current1;

    current2->next = prev_form->next;
    prev_form->next= current2;
    

}



void print_list(node* head){
    node* current = head;
    while(current != NULL){
        cout<<current->value<<" ";
        current = current->next;
    }
    cout<<endl;
}
int main(){
    node* head = new node();
    if( head == NULL ) return -1; //要設定擋板，記憶體配置要特別注意
    head->next = NULL;head->value = 1;
    insert_in_tail(head,2);
    insert_in_tail(head,3);
    delete_in_middle(head,3);
    print_list(head);
    return 0;
}