#include<iostream>

void heapify(int* vec, int heapSize, int index);
int father(int index);
int left(int index);
int right(int index);
bool isLeaf(int heapSize, int i);
void buildHeap(int* vec, int size, int& heapSize);//O(n)
void addNode(int* vec, int& heapSize,int size, int value);
int extractMax(int* vec, int& heapSize);
void swap(int& a, int& b);
void print(int* vec, int heapSize);
void heapSort(int* vec, int size);//O(n*log(n))
void maxHeapModify(int* vec, int heapSize, int i, int value);
void bringUp(int* vec, int index);

int main(){
	int size = 10;
    int vec[size] = {5,7,1,2,9,8,12,13,3,50};
	int heapSize = size;
	heapSort(vec, size);
	std::cout << std::endl;
	print(vec, heapSize);
    return 0;
}

//precondizione: vec[left(i)] e vec[right(i)], sono radici di Max Heap
//postcondizione: vec[i] è radice di Max Heap
void heapify(int* vec, int heapSize, int i){
	int g = i;
	if(!isLeaf(heapSize, i)){
		if(vec[i] < vec[left(i)]){
			g = left(i);
		}
		if(vec[g] < vec[right(i)]){
			g = right(i);
		}
	}
	if(g != i){
		swap(vec[i], vec[g]);
		heapify(vec, heapSize, g);
	}
	return;
}

int father(int index){
	return index/2;
}

int left(int index){
	return 2*index;
}

int right(int index){
	return 2*index + 1;
}



bool isLeaf(int heapSize, int i){
	if (i >= heapSize/2){
		return true;
	}
	return false;
}

void buildHeap(int* vec, int size, int& heapSize){
	heapSize = size;
	for(int i=size/2; i >= 0; i--){
		heapify(vec, heapSize, i);
	}
}

void addNode(int* vec, int& heapSize, int size, int value){
int pos = heapSize+1;
	if(heapSize < size){
		heapSize++;
		vec[heapSize] = value;
		bringUp(vec, pos);
	}
	return;
}

int extractMax(int* vec, int& heapSize){
	swap(vec[0], vec[heapSize]);
	heapSize--;
	heapify(vec, heapSize, 0);
	return vec[heapSize+1];
}

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
	return;
}

void print(int* vec, int heapSize){
	for(int i=0;i<heapSize;i++){
		std::cout << vec[i] << std::endl;
	}
	return;
}

void heapSort(int* vec, int size){
	int heapSize;
	buildHeap(vec, size, heapSize);
	for(int i=size-1; i>1; i--){
		heapSize = i;
		swap(vec[0], vec[heapSize]);
		heapSize--;
		heapify(vec, heapSize, 0);
	}
	return;
}

//given an index i and a value, vec[i] = vec[i] + value, then you rearrange the array, to get a Max Heap
void maxHeapModify(int* vec, int heapSize, int i, int value){
	vec[i] = vec[i] + value;
	if(value < 0){
		heapify(vec, heapSize, i);
	}else{
		bringUp(vec, i);
	}
}

//recursively brings a value up to the tree
void bringUp(int* vec, int index){
	if(father(index) != index){
		if(vec[father(index)] < vec[index]){
			swap(vec[father(index)], vec[index]);
			bringUp(vec, father(index));
		}
	}
	return;
}