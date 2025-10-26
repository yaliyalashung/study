#include <stdio.h>
#include <stdlib.h>     //malloc


struct  Node
{
    int data;           
    struct  Node *next;
};

//새로운 노드를 가장 뒤에 삽입
void append(struct Node** head_ref, int new_data){

    // 0.head
    struct Node *last = *head_ref;
    
    // 1. new node 생성
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    //2. linked list가 비었으면 새 노드를 head로 만듦.
    if(*head_ref == NULL)
    {
        *head_ref=new_node;
        return;
    }

    //3.1 마지막 노드일때까지 순회
    while(last->next != NULL)
    {
        last = last->next;
    }

    //3.2 마지막 노드를 새로운 노드로 변경
    last->next = new_node;
    return;

}

//새로운 노드를 가장 앞에 삽입
void push(struct Node** head_ref, int new_data)
{
    //1. new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    //순서가 중요!
    //2. next 
    new_node->next = (*head_ref); //head가 가지고 있는 값에 next를 연결

    //3.move the head to point to the new node
    (*head_ref) = new_node;

    /*
    struct Node *temp = *head_ref;
    *head_ref = new_node;
    new_node->next = temp;
    */
};

//현재 가리키고 있는 노드의 뒷부분에 삽입
void insertAfter(struct Node* prev_node, int new_data){

    if(prev_node == NULL){
        printf("the given previous node cannot be NULL");
        return;
    }
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;


}

void printList(struct Node *node){
    while(node != NULL){
        printf(" %d ", node->data);
        node = node->next;
    }

}

void deleteNode(struct Node **head_ref, int key)
{
    struct Node* temp = *head_ref, *prev;

    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp !=NULL && temp->data !=key){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL) return;

    if(prev!=NULL) prev->next = temp->next;

    free(temp);

}


int main()
{
    struct Node* head = NULL;
    
    //linked list의 제일 뒤에 추가
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    printf("\n Created Linked list is : ");
    printList(head);

    deleteNode(&head, 7);
    puts("\nLinked List after deletion of 1 : ");
    printList(head);

    return 0;
}
