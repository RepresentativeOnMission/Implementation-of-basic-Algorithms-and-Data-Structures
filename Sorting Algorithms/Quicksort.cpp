#include<iostream>
void swap(int *arr, int a, int b);
int partition(int *arr, int p, int q);
void quicksort(int *arr, int p, int q);
void printArr(int *arr, int size);

int main(){
    int arr[10] = {5,4,7,9,7,5,12,4,87,5};
    quicksort(arr, 0, 9);
    printArr(arr, 10);
    return 0;
}

void quicksort(int *arr, int p, int q){
    if(p < q){
        int r = partition(arr, p, q);
        quicksort(arr, p, r-1);
        quicksort(arr, r+1, q);
    }
    return ;
}

int partition(int *arr, int p, int q){
    int x = arr[q];
    int i=p-1;
    for(int j=p; j<=q; j++){
        if(arr[j] <= x){
            i++;
            swap(arr, i, j);
        }
    }
    return i;
}

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArr(int *arr, int size){
    for(int i=0; i<size; i++){
        std::cout << arr[i] << std::endl;
    }
    return ;
}