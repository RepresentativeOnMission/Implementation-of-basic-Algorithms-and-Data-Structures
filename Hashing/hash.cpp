#include<iostream>
#include<string>

void insertHashWord(std::string word, std::string *arr, int size);
void deleteWord(std::string word, std::string *arr, int size);
int searchWord(std::string word, std::string *arr, int size);
int hash(std::string *word);
void print(std::string *arr, int size);

int main(){
    std::string arr[25] = {""};
    int size = 25;
    std::string word = "anacapri";
    insertHashWord(word, arr, size);
    word = "wacca";
    insertHashWord(word, arr, size);
    word = "wecca";
    insertHashWord(word, arr, size);
    word = "wicca";
    insertHashWord(word, arr, size);
    word = "wmcmna";
    insertHashWord(word, arr, size);
    word = "gecco";
    insertHashWord(word, arr, size);
    word = "becco";
    insertHashWord(word, arr, size);
    deleteWord(word, arr, size);
    print(arr, size);
    word = "wacca";
    std::cout << searchWord(word, arr, size) << std::endl;
    return 0;
}

void insertHashWord(std::string word, std::string *arr, int size){
    int hashW = hash(&word);
    int counter = 0;
    while(arr[hashW] != "" && counter < size){
        counter++;
        hashW++;
        if(hashW == size)
            hashW = 0;
    }
    if(counter < size)
        arr[hashW] = word;
}

void deleteWord(std::string word, std::string *arr, int size){
    int hashW = hash(&word);
    int counter = 0;
    while(arr[hashW] != word && counter < size){
        counter++;
        hashW++;
        if(hashW == size)
            hashW = 0;
    }
    if(counter < size)
        arr[hashW] = "DEL";
}

int searchWord(std::string word, std::string *arr, int size){
    int hashW = hash(&word);
    int counter = 0;
    while(arr[hashW] != word && counter < size){
        counter++;
        hashW++;
        if(hashW == size)
            hashW = 0;
    }
    if(counter < size)
        return hashW;
    return -1;
}

int hash(std::string *word){
    return word->at(0) - 97;
}

void print(std::string *arr, int size){
    for(int i=0;i<size;i++){
        std::cout << arr[i] << std::endl;
    }
    return ;
}