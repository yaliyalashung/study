#include <cstdio>

int main(){
    // FILE* infile = fopen("text.txt", "w");
    // int value[5] = {1, 2, 3, 4, 5};
    // fwrite(&value, sizeof(int), 5, infile);
    // //fprintf(infile, "Hello, World!\n");
    // fclose(infile);

    FILE* infile = fopen("text.txt", "r");
    int value[5];
    fread(&value, sizeof(int), 5, infile);
    fclose(infile);

    for(int i=0; i<5; i++)
    {
        printf("%d ", value[i]);
    }
    return 0;
}