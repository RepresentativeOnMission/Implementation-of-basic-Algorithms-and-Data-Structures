#include <iostream>
#include <string>
#include "brt.h"

using namespace std;

void RedBlackTree::initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = 0;
	node->value = "";
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
  }

string RedBlackTree::colorToString(int color){
      if(color == 0){
          return "black";
      }
      return "red";
  }
string RedBlackTree::nodeToString(NodePtr x){
    string str = "NULL ";
    if(x != TNULL){
        str = to_string(x->data) + ":" + x->value + ":" + colorToString(x->color) + " ";
    }
        return str;
    }
void RedBlackTree::preOrderHelper(NodePtr node) {
    cout << nodeToString(node);
    if (node != TNULL) {
      preOrderHelper(node->left);
      preOrderHelper(node->right);
    }
  }
string RedBlackTree::findHelper(NodePtr node, int key){
      if(node != TNULL){
          if(key < node->data){
              return findHelper(node->left, key);
          }else if(key > node->data){
              return findHelper(node->right, key);
          }else{
              return node->value;
          }
      }else{
          return "not found";
      }
  }
void RedBlackTree::insertFix(NodePtr x) {
    NodePtr uncle;
    while (x->parent->color == 1) {
      if (x->parent == x->parent->parent->right) {
        uncle = x->parent->parent->left;
        if (uncle->color == 1) {
          uncle->color = 0;
          x->parent->color = 0;
          x->parent->parent->color = 1;
          x = x->parent->parent;
        } else {
          if (x == x->parent->left) {
            x = x->parent;
            rightRotate(x);
          }
          x->parent->color = 0;
          x->parent->parent->color = 1;
          leftRotate(x->parent->parent);
        }
      } else {
        uncle = x->parent->parent->right;

        if (uncle->color == 1) {
          uncle->color = 0;
          x->parent->color = 0;
          x->parent->parent->color = 1;
          x = x->parent->parent;
        } else {
          if (x == x->parent->right) {
            x = x->parent;
            leftRotate(x);
          }
          x->parent->color = 0;
          x->parent->parent->color = 1;
          rightRotate(x->parent->parent);
        }
      }
      if (x == root) {
        break;
      }
    }
    root->color = 0;
  }
RedBlackTree::RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }
void RedBlackTree::preorder() {
    preOrderHelper(this->root);
  }
void RedBlackTree::leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }
void RedBlackTree::rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

void RedBlackTree::insert(int key, string value) {
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
	node->value = value;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insertFix(node);
  }
string RedBlackTree::find(int key){
      return findHelper(this->root, key);
  }

void getArrString(string* arr, int size){
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
}
/*
int main() {
    RedBlackTree bst;
    string arr[3] = {};
    while(arr[0]!="exit"){
        getArrString(arr, 3);
        if(arr[0]=="insert"){
            bst.insert(stoi(arr[1]), arr[2]);
        }else if(arr[0] == "show"){
            bst.preorder();
        }else if(arr[0] == "find"){
            cout << endl << bst.find(stoi(arr[1]));
        }
    }
    cout << endl;
    return 0;
}*/