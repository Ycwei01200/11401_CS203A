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
void Selection_sort_by_value(node* head){
    if(head == NULL || head->next == NULL) return;
    for(node* i = head; i != NULL ; i = i->next){
        node* min_node = i;
        for(node* j = i->next; j!= NULL; j = j->next){
            if(j->value < min_node->value){
                min_node = j;
            }
        }
        if(min_node != i){
            int temp = i->value;
            i->value = min_node->value;
            min_node->value = temp;
        }
    }
}
// 太抽象了
void Selection_sort_by_pointer(node*& head){
    // 1. 基本檢查：如果是空串列或只有一個節點，不用排
    if(head == NULL || head->next == NULL) return;

    // i 是「目前要處理的位置」
    for(node* i = head; i->next != NULL; i = i->next){
        
        // --- 步驟 A: 找出最小值 ---
        node* min_node = i;       // 先假設 i 自己是最小的
        node* prev_min = NULL;    // 紀錄 min_node 的前一個節點 (為了拔出來用)
        
        node* prev_j = i;         // 這是 j 的前一個節點
        for(node* j = i->next; j != NULL; j = j->next){
            if(j->value < min_node->value){
                min_node = j;
                prev_min = prev_j; // 記住最小值的前一個是誰
            }
            prev_j = j; // 往下走
        }

        // --- 步驟 B: 如果真的找到比 i 更小的節點，就進行搬移 ---
        if(min_node != i){
            
            // 1. 【拔出來】把 min_node 從原本位置移除
            // prev_min->next 接到 min_node->next，這樣 min_node 就斷開了
            prev_min->next = min_node->next;

            // 2. 【插進去】把 min_node 插到 i 的前面
            min_node->next = i;

            // 3. 【接起來】處理 i 的前一個節點指向 min_node
            if(i == head){
                head = min_node; // 如果 i 是頭，頭就要換人做
            } else {
                // 如果 i 不是頭，我們要找到 i 的前一個節點 (prev_i)
                node* prev_i = head;
                while(prev_i->next != i){
                    prev_i = prev_i->next;
                }
                prev_i->next = min_node; // 讓前一個節點指向新的 min_node
            }

            // 4. 【更新 i】
            // 因為我們把 min_node 插到了 i 的位置，
            // 現在 i 指標應該要指著這個新位置 (min_node)，
            // 這樣迴圈的 i = i->next 才會正確走到下一個位置 (原本的 i)。
            i = min_node;
        }
    }
}
// ...existing code...







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