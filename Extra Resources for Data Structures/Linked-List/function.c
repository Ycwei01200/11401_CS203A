#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

//insert()
void insert(struct node* node,int info){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val  = info;
    newnode->next = node->next;
    node->next    = newnode;
    free(newnode);
    
}
//push_back()
void push_back(struct node* node,int info){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* current = node;
    newnode->val  = info;
    newnode->next = NULL;
    while(current->next!=NULL){
        current = current -> next;
    }
    current->next = newnode;
    
}
//pop_back()
void pop_back(struct node* node,int info){
    struct node* current = node;
    while(current->next!=NULL){
        current = current -> next;
    }
    current = NULL;
    
    
}
//erase()
struct node* erase(struct node* first,struct node* target){

    struct node* current =first;
    if(first==target){
        first = first->next;
        free(target);
        return first;
    }
    else{
        while(current->next!=target){
            current = current->next;
        }
        current->next = target->next;
        free(target);
        return first;
    }
        
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));

    head->next = (struct node*)malloc(sizeof(struct node));

    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->next = (struct node*)malloc(sizeof(struct node));
    head->val = 10;
    //head->next->val=30;//創造node
    struct node* node = (struct node*)malloc(sizeof(struct node));
    head->next->val=20;
    head->next->next->val = 30;
    head->next->next->next = NULL;
    
    while(node){
        printf("  %d",node->val);
        node = node->next;
    }
    free(node);free(head);
    return 0;
}
