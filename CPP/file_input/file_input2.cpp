#include <cstdio>


bool file_exists(const char* filename){
    FILE* fp = fopen(filename, "r");
    if (fp != nullptr) fclose(fp);
    return fp != nullptr;

}
int main(){

    FILE* infile = fopen("in.txt", "r");

    while (true)
    {
        char line[256];
        if(fscanf(infile, "%255[^\n]", line) != 1) {
            break;
        }
        fgetc(infile);          //fstream의 line에서 개행문자 다음 글자의 위치를 반환해줌
        printf("%s\n", line);

        if (feof(infile)==1) break;
    }
    
    fclose(infile);
    return 0;
}