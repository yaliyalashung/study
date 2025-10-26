#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next; 
};

struct Node* make_node(int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

//새로운 노드를 가장 뒤에 삽입
void append(int new_data, struct Node** head){
    
    struct Node* last = *head;

    struct Node* new_node = make_node(new_data);

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next !=NULL){
        last = last->next;
    }

    last->next = new_node;
    return;

}


//새로운 노드를 가장 앞에 삽입
void push(int new_data, struct Node** head){

    struct Node* new_node = make_node(new_data);
    
    struct Node* temp = *head;
    *head = new_node;
    new_node->next = temp;

}

//현재 가리키고 있는 노드의 뒷부분에 삽입
void insert(int new_data, struct Node* prev){
    
    if(prev==NULL) return;

    struct Node* new_node = make_node(new_data);

    new_node->next = prev->next;

    prev->next = new_node;
    
}

//Node 삭제하기
void Delete(struct Node** head, int key){

    struct Node* temp = *head;
    struct Node* prev;

    if(temp !=NULL){
        if(temp->data == key){
            *head = temp->next;
            free(temp);
            return;
        }else{
            prev = temp;
            temp = temp->next;
        }
    }else {
        return;
    }

    if(prev!=NULL) prev->next = temp->next;

    free(temp);
}

//Node 출력하기
void printNode(struct Node* node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    };
}


int main(){

    struct Node* head = NULL;

    for(int i = 0; i<10; i++){
        append((i+1),&head);
    }

    const char* filename = "D:\\CPP\\Linked_list.txt";

    struct Node* current_node = head;
    //node를 입력할 파일 열기
    FILE* fp = fopen(filename, "w");
    if(fp!=NULL){
        while(current_node != NULL){
            fprintf(fp, " %d ", current_node->data);
            current_node = current_node->next;
        }
        fclose(fp);
    }else{
        printf("File open failed\n");
    }

    struct Node* read_node = NULL;

    //입력된 노드 파일 읽기
    fp = fopen(filename, "r");
    if(fp != NULL){        
        int read_data;
        while(fscanf(fp, "%d", &read_data)==1){
            append(read_data, &read_node);
        }
        fclose(fp);
    }

    printNode(read_node);

    return 0;
}