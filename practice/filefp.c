#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list* next;
} list;


int main(){

    list* a = (struct list*)malloc(sizeof(list));
    list* b = (struct list*)malloc(sizeof(list));

    a->data = 1;
    a->next = b;

    b->data = 2;
    b->next = NULL;

    FILE* fp = fopen("test.txt", "w");
    if(fp != NULL){
        struct list* List = a;
        while(List != NULL){
            fprintf(fp, "%d\n",List->data);
            List = List->next; 
        }
        fclose(fp);
    }

    fp = fopen("test.txt", "r");

    if(fp != NULL){
        int value;
        while(fscanf(fp, "%d", &value)==1){;
            printf("%d\n", value);
        }        
        fclose(fp);
    }

    free(a);
    free(b);


    return 0;
}
