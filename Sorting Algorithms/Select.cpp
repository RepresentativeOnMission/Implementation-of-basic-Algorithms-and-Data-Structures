#include<iostream>

void insertionSort(int* vec, int size);//O(n^2)
void printVec(int* vec, int size);
void swap(int& a, int& b);
int Select(int* vec, int p, int q, int i);
int Partition(int* vec, int p, int q, int r);
void getB(int* vec, int* B, int p, int q);
int getBLength(int p, int q);

int main(){
	int vec[10] = {4,7,12,1,3,6,8,3,90,10};
	std::cout << Select(vec, 0, 9, 3);
	return 0;
}

void insertionSort(int* vec, int p, int q){
	int j = 0;
	for(int i=0;i<q-p+1;i++){
		j = i;
		while(j >= 0 && vec[j] < vec[j-1]){
			swap(vec[j], vec[j-1]);
			j--;
		}
	}
	return;
}

void printVec(int* vec, int size){
	for(int i=0;i<size;i++){
		std::cout << vec[i] << std::endl;
	}
	return;
}

void swap(int& a, int& b){
	int temp = a;
	a=b;
	b=temp;
	return;
}

int Select(int* vec, int p, int q, int i){
	int r,m, bLen = getBLength(p, q);
	int B[bLen];
	if(p==q){
		return vec[p];
	}else{
		getB(vec, B, p, q);
		m = Select(B, 0, bLen, bLen / 2);
		r = Partition(vec, p, q, m);
		if(i == r){
			return vec[r];
		}
		if(i < r){
			return Select(vec, p, r-1, i);
		}else{
			return Select(vec, r+1, q, i);
		}
	}
}

int Partition(int* vec, int p, int q, int r){
	int key = vec[r];
	int j = p-1;
	for(int i=p; i<=q; i++){
		if(vec[i] <= key){
			j++;
			swap(vec[i], vec[j]);
		}
	}
	return j;
	
}

void getB(int* vec,int* B, int p, int q){
	int* temp = vec;
	int sizeVec = q-p+1;
	int remainder = sizeVec % 5;
	int j=0;
	int i;
	for(i=0; i < sizeVec-remainder; i+=5){
		insertionSort(temp, i, i+4);
		B[j] = temp[i+2];
		j++;
	}
	i++;
	insertionSort(temp, i, sizeVec+remainder);
	B[j] = temp[i+2];
	return ;
}

int getBLength(int p, int q){
	int sizeVec = q-p+1;
	int sizeB = 0;
	if(sizeVec % 5 != 0){
		sizeB = (sizeVec / 5) + 1;
	}else{
		sizeB = (sizeVec / 5);
	}
	return sizeB;
}