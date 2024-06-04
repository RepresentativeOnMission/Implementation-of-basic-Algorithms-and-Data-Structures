#include<iostream>
#include<string>
#include <sstream>
#include <vector>
#include "avl.h"

using namespace std;



NodeAVL* createNodeAVL(int key, string val){
    NodeAVL *nd = new NodeAVL();
    nd->key = key;
    nd->value = val;
    nd->height = 0;
    nd->BF = 0;
    nd->left = nullptr;
    nd->right = nullptr;
    return nd;
}

int rightHeight(NodeAVL *x){
    if(x->right == nullptr){
        return -1;
    }
    return x->right->height;
}

int leftHeight(NodeAVL *x){
    if(x->left == nullptr){
        return -1;
    }
    return x->left->height;
}

void updateNode(NodeAVL *x){
    int x_rh = rightHeight(x);
    int x_lh = leftHeight(x);

    x->height = 1 + max(x_lh, x_rh);
    x->BF = x_rh - x_lh;
    return ;
}

NodeAVL* leftRotate(NodeAVL *x){
    NodeAVL *y = x->right;
    x->right = y->left;
    y->left = x;
    updateNode(x);
    updateNode(y);

    return y;
}

NodeAVL* rightRotate(NodeAVL *x){
    NodeAVL *y = x->left;
    x->left = y->right;
    y->right = x;

    updateNode(x);
    updateNode(y);

    return y;
}

NodeAVL* leftLeftCase(NodeAVL* x){
    return rightRotate(x);
}

NodeAVL* leftRightCase(NodeAVL* x){
    x->left = leftRotate(x->left);
    return leftLeftCase(x);
}

NodeAVL* rightRightCase(NodeAVL *x){
    return leftRotate(x);
}

NodeAVL* rightLeftCase(NodeAVL* x){
    x->right = rightRotate(x->right);
    return rightRightCase(x);
}

NodeAVL* balanceTree(NodeAVL *root){
    if(root->BF == -2){
        if(root->left->BF <= 0){
            return leftLeftCase(root);
        }else{
            return leftRightCase(root);
        }
    }else if(root->BF == 2){
        if(root->right->BF >= 0){
            return rightRightCase(root);
        }else{
            return rightLeftCase(root);
        }
    }
    return root;
}


NodeAVL* insertAVL(NodeAVL *root, int key, string val){
    //create new Node
    if(root == nullptr){
        NodeAVL *n = createNodeAVL(key, val);
        return n;
    }else{
        if(key < root->key){
            root->left = insertAVL(root->left, key, val);
        }else{
            root->right = insertAVL(root->right, key, val);
        }
        updateNode(root);
    }
    return balanceTree(root);
}

string findAVL(NodeAVL *root, int key){
    string val = "not found";
    if(root){
        if(key < root->key){
            val = findAVL(root->left, key);
        }else if(key > root->key){
            val = findAVL(root->right, key);
        }else{
            val = root->value;
        }
    }
    return val;
}

string nodeToString(NodeAVL *x){
    string str = "NULL ";
    if(x){
        str = to_string(x->key) + ":" + x->value + ":" + to_string(x->height+1) + " ";
    }
    return str;
}

void PreOrder(NodeAVL *root){
    if(root != nullptr){
        std::cout << nodeToString(root);
        PreOrder(root->left);
        PreOrder(root->right);
    }else{
        std::cout << nodeToString(root);
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
    NodeAVL *root = nullptr;
    string arr[3] = {};
    while(arr[0]!="exit"){
        getArrString(arr, 3);
        if(arr[0]=="insert"){
            root = insertAVL(root, stoi(arr[1]), arr[2]);
        }else if(arr[0] == "show"){
            PreOrder(root);
        }else if(arr[0] == "find"){
            cout << endl << findAVL(root, stoi(arr[1]));
        }
    }
    return 0;
}*/