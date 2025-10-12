#include <cstdio>
#include <string>

template <typename T>
class MyArray{
    private :
        T* arrayItem; //배열 포인터
        int count = 0;
        int capacity = 8;

    public :
        MyArray(){
            arrayItem = new T[8];
        }

        virtual ~MyArray(){
            delete[] arrayItem;
        }

        void putValue(const T& value){
            if(capacity<=count){
                printf("배열의 capcity가 두 배로 늘어났습니다.\n");
                T* newarray = new T[capacity*2];
                capacity = capacity*2;
                for(int i = 0; i <count; i++){
                    newarray[i] = arrayItem[i];
                }
                delete[] arrayItem;
                arrayItem = newarray;
            }
            arrayItem[count] = value;
            count++;
        }

    int getCount(){
        return count;
    }

    T getValue(int index){
        return arrayItem[index];
    }
};

int main(){
    MyArray<std::string> m = MyArray<std::string>();

    for(int i = 1; i<10; i++){
        m.putValue("apple");
    }

    for(int i =0; i<m.getCount(); i++){
        printf("%s ", m.getValue(i).c_str());
    }

    return 0;
}