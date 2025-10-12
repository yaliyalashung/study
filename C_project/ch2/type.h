float input_1;
float input_2;
char input_3;
float result;

bool valid = true;

float getfloat(){
    float a;
    fseek(stdin, 0, SEEK_END);
    scanf("%f", &a);
    return a;
}

char getChar(){
    char a;
    fseek(stdin, 0, SEEK_END);
    scanf(" %c", &a);
    return a;
}

float choiceoper(int num, float input_1, float input_2){

    switch (num)
    {
        case 0:
            result = input_1+input_2;
            break;
        case 1:
            result = input_1-input_2;
            break;
        case 2:
            result = input_1*input_2;
            break;
        case 3:
            if(input_2==0){
                printf("0으로 나눌 수 없습니다.\n");
            }
            else{
                result = input_1/input_2;
            }
            break;
        case 4:
            result = (int)input_1%(int)input_2;
            break;
        
        default:
            printf("잘못된 연산식을 입력하셨습니다.\n");
            valid = false;
            break;
    }

    return result;

}