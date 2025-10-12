#include <stdio.h>

struct list{
    int data;
    struct list* next;
};

int main(){

    list* a = new list{1, nullptr};
    list* b = new list{2, nullptr};

    FILE* fp = fopen("test.txt", "w");
    if(fp != NULL){
        fprintf(fp, "%d\n",a->data);
    }
    fclose(fp);

    int value = 0;
    fp = fopen("test.txt", "r");
    if(fp != NULL){
        fscanf(fp, "%d", &value);
    }
    fclose(fp);

    printf("%d", value);

    return 0;
}