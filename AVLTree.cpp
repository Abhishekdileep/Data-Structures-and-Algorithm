#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct NODE {
    int value , balance_factor; 
    struct NODE* left;
    struct NODE* right;
    NODE();
    NODE(int val);
    NODE(int val , NODE* left , NODE* right);
    int Height();
    int Height(struct NODE* root , int h);
};
typedef struct NODE* Node;

NODE::NODE(int val){
     this->value = val;
     this->left = nullptr;
     this->right = nullptr; 
}
NODE::NODE(int val , Node l , Node r ){
     this->value = val;
     this->left = l;
     this->right = r; 
}

int NODE::Height(){
    balance_factor = Height( left , 0 ) - Height( right , 0 );
}

int NODE::Height(Node Root , int h){
    if( Root == nullptr )
        return 0;
     
}



// class AVLTree {
//     public :  
//         AVLTree();
//         Node root;

// };

// AVLTree::AVLTree(){
//     root = nullptr;
// };

// void AVLTree(){

// };

int main(){
    int a = 10 ;
    Node L1 = new NODE(a);
    a++;
    Node L2 = new NODE(a , L1 , nullptr );
    a++;
    Node root = new NODE(a ,L2 , nullptr);

    


    return 0;
}