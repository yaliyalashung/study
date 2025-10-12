#include <cstdio>
#include <string>
#include <cstring>

template<typename T>

class find_value{
    private:
        T* arrayItem;
        int count = 0;
        int capacity = 10;

    public:
        find_value(){
            arrayItem = new T[10];
        }

        virtual ~find_value(){
            delete[] arrayItem;
        }

        void putValue(const T& value){
            if(capacity<=count){
                T* newarray = new T[capacity*2];
                capacity = capacity*2;
                for(int i = 0; i<count; i++){
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

        bool contains(T value){
            for(int i=0; i<count; i++){
                if(value == arrayItem[i]){
                    return true;
                }
            }
            return false;
        }

        void replace(int index, T value){
            if(index<count){              
                arrayItem[index] = value;   
            }
        }

        void erase(int index){
            for(int i = index; i<count-1; i++){
                arrayItem[i] = arrayItem[i+1];
            }
            count--;
        }


};
int main(){
    find_value<int> m = find_value<int>();

    for(int i = 0; i<10; i++){
        m.putValue(i+1);
        printf("%d ", m.getValue(i));
    }

    m.erase(7);
    if(m.contains(11)){        
        m.replace(1, 11);
    }
    else{
        m.replace(1, 1234);
    }

    printf("\n");

    for(int i = 0; i<m.getCount(); i++){
        printf("%d ", m.getValue(i));
    }

    return 0;
}