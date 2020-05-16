#include <iostream>
#include <limits>

using namespace std;

void print(int* arr, int len){
    for(auto i=0;i<len;i++){
        cout << "index: "<<i << ",value: "<< arr[i] << endl;
    }
}

// 时间复杂度 O(n), 空间复杂度 O(1)
void bubbleSort(int* & arr, int len){
    if(len<=1)
        return;
    auto limit = len-1;
    while(limit>1){
        bool flag = false;
        for(auto i=0; i<limit; i++){
            // 如果低位的比高位的大 则交换两者
            if(arr[i]>arr[i+1]){
                auto temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = true;
            }
        }
        // 如果某一次 没有交换 说明已经排序完成了。
        if(!flag)
            break;
        limit--;
    }

}

// 插入排序
void insertionSort(int *&arr, int len){
    if(len<=1) return;

    for(auto i=1;i<len;i++){
        auto val = arr[i];
        auto index = i-1;

        while(index >=0){
            // move data
            if(arr[index] > val){
                arr[index+1] = arr[index];
                index --;
            }else{
                break;
            }
        }
        arr[index+1] = val;
    }
}

void selectionSort(int* &arr, int len){

    for(auto i=0; i<len;i++){
        auto temp = arr[i];
        auto min = std::numeric_limits<int>::max();
        auto index = -1;
        // 获取最小值
        for(auto j=i;j<len; j++){
           if(arr[j]<= min) {
               min = arr[j];
               index = j;
           }
        }

        // 交换最小值的位置
        arr[i] = min;
        arr[index] = temp;
    }
}

int main(int argc, char** argv){
    int* ori = new int[5]{3,2,5,1,4};
    print(ori, 5);
    cout << "------------" << endl;
    // bubbleSort(ori, 5);
    // insertionSort(ori, 5);
    selectionSort(ori, 5);
    print(ori, 5);
    return 0;
}