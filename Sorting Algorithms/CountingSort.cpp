#include<iostream>

void countingSort(int* arr, int* result, int k, int size);
void readArray(int* arr, int size);

int main(){
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int result[10] = {};
    countingSort(arr, result, 90, 10);
    readArray(result, 10);
    return 0;
}

void countingSort(int* arr, int* result, int k, int size){
    int temp[k+1] = {};
    int v;
    for(int i=0; i<k+1; i++){
        temp[i] = 0;
    }
    for(int i=0; i<size; i++){
        temp[arr[i]] += 1;
    }
    for(int i=1; i<k+1; i++){
        temp[i] = temp[i-1] + temp[i];
    }
    for(int i=size-1; i>=0; i--){
        v = temp[arr[i]];
        temp[arr[i]] -= 1;
        result[v] = arr[i];
    }
}

void readArray(int* arr, int size){
    std::cout << std::endl;
    for(int i=0;i<size; i++){
        std::cout << arr[i] << " , ";
    }
    std::cout << std::endl;
}