#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    std::vector<int> myvec = {40, 70, 1};

    myvec.push_back(10);
    myvec.push_back(5);
    myvec.push_back(30);

    std::sort(myvec.begin(), myvec.end());
    
    /*
    for (int i = 0; i<myvec.size(); i++){
        printf("%d ", myvec.at(i));
    }
    */

    for(std::vector<int>::const_iterator it = myvec.begin(); it != myvec.end(); it++){
        printf("%d ", *it);
    }
    return 0;
}