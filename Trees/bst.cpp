#include<iostream>
#include<string>
#include "bst.h"

using namespace std;

NodeBST* createNode(int key, string val){
    NodeBST *nd = new NodeBST();
    nd->key = key;
    nd->value = val;
    nd->left = nullptr;
    nd->right = nullptr;
    return nd;
}

NodeBST* insert(NodeBST *root, int key, string val){

    if(root == nullptr){
        return createNode(key, val);
    }else if(key < root->key){
        root->left = insert(root->left, key, val);
    }else if(key > root->key){
        root->right = insert(root->right, key, val);
    }
    return root;
}

string search(NodeBST *root, int key){
    if(root != nullptr){
        if(key < root->key){
            return search(root->left, key);
        }else if(key > root->key){
            return search(root->right, key);
        }else{
            return root->value;
        }
    }else{
        return "not found";
    }
}

string nodeToString(NodeBST *x){
    string str = "NULL ";
    if(x){
        str = to_string(x->key) + ":" + x->value + " ";
    }
    return str;
}

void PreOrder(NodeBST *root){
    std::cout << nodeToString(root);
    if(root != nullptr){
        PreOrder(root->left);
        PreOrder(root->right);
    }
    return ;
}

/*void getArrString(string* arr, int size){
    string str;
    getline (cin,str);
    std::string delimiter = " ";
    
    size_t pos = 0;
    string token;
    int i = 0;
    while ((pos = str.find(delimiter)) != string::npos) {
        arr[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
    arr[i] = str;
}*/
/*
int main(){
    NodeBST *root = nullptr;
    string arr[3] = {};
    while(arr[0]!="exit"){
        getArrString(arr, 3);
        if(arr[0]=="insert"){
            root = insert(root, stoi(arr[1]), arr[2]);
        }else if(arr[0] == "show"){
            PreOrder(root);
        }else if(arr[0] == "find"){
            cout << endl << search(root, stoi(arr[1]));
        }
    }
    return 0;
}*/