#include<bits/stdc++.h>

using namespace std;

struct NODE{
    struct NODE* lchild;
    struct NODE* rchild;
    int val;
    NODE(int v , struct NODE* l , struct NODE* r);
    NODE(int v);
    NODE();
};

typedef struct NODE* Node;

NODE::NODE(int v, Node l , Node r){
    this->lchild = l;
    this->rchild = r;
    this->val = v;
};

NODE::NODE(int v){
    this->lchild =nullptr;
    this->rchild =nullptr;
    this->val = v;
};

class tree{
    private :
    public : 
        Node root;
        tree();
        Node BST(int start , int end , vector<int> &Arr , Node main);   
        void BST(int start  , int end  , vector<int> &arr );
        void Binary_tree( vector<int> );
        Node Binary_tree( vector<int> , int  , int );
        void preorder(Node main);
        void postorder(Node main);
        void inorder(Node main);
        void levelOrder();
        void levelOrder( queue<Node>& temp);
        int TreeDepth(Node);
        int size(Node main);
        bool identicalTree(Node  , Node ); 
        Node TreeToList ( Node main );
        void printAllPath(Node , vector<int> & );
        Node FindNode(Node , int , int );
        int MaxDepth(Node main , int depth);
};

tree::tree(){
    root = nullptr ;
}

Node tree::BST(int start , int end , vector<int> &arr , Node main ){
    
        if(start == end){
            main = new NODE(arr[start]);
            return main;
        }
        if(start > end){
            return nullptr;
        }
        else{
            int midVal = (start + end)/2;
            main = new NODE(arr[midVal]);
            Node left = BST(start , midVal-1 , arr  , main->lchild); 
            Node right = BST(midVal+1 , end , arr , main->rchild) ;
            main->lchild = left;
            main->rchild = right;
            return main;
        }
}

void tree::BST(int start  , int end  , vector<int> &arr ){
    this->root =  BST(0 , arr.size()-1 , arr , this->root);
}

void tree::preorder(Node main){
    if(main != nullptr){
        cout << main->val<<" ";
        preorder(main->lchild);
        preorder(main->rchild);
    }
    return ;
}

void tree::postorder(Node main){
    if(main != nullptr){
        postorder(main->lchild);
        postorder(main->rchild);
        cout << main->val<<" ";
    }
    return ;
}

void tree::inorder(Node main){
     if(main != nullptr){
        inorder(main->lchild);
        cout << main->val<<" ";
        inorder(main->rchild);
    }
    return ;   
}

void tree::Binary_tree(vector<int> arr){
    this->root = Binary_tree(arr , 0 , arr.size() );
}

void tree::levelOrder(){
    queue<Node> value;
    value.push(root);
    levelOrder( value);
}

void tree::levelOrder(queue<Node>& values){
   while(!values.empty()) {
    Node temp = values.front();
    values.pop();
    if(temp != nullptr){
    cout<<temp->val<<" ";
    values.push(temp->lchild);
    values.push(temp->rchild);
    }
    }
}

Node tree::Binary_tree(vector<int> arr , int start , int size ){
    int left = 2*start + 1;
    int right = 2*start + 2;
    Node curr = new NODE(arr[start]);

    if(left < size) {
        curr->lchild = Binary_tree( arr , left , size);
    }

    if(right < size) {
        curr->rchild = Binary_tree( arr , right , size);
    }

    return curr;
}

int tree::TreeDepth(Node root)
{
    if (root == nullptr)
        return 0;
    int lDepth = TreeDepth(root->lchild);
    int rDepth = TreeDepth(root->rchild);
    if (lDepth > rDepth)
        return lDepth + 1;
    else
        return rDepth + 1;
}

int tree::size(Node main){
    if(main == nullptr)
        return 0;
    else 
        return size(main->lchild) + size(main->rchild) + 1;
}

bool tree::identicalTree(Node root1 , Node root2 ){
    if( root1 == nullptr && root2 == nullptr )
        return true;
    else if ( root1 == nullptr || root2 == nullptr )
        return false;
    else 
        return identicalTree( root1->lchild , root2->lchild ) && identicalTree( root1->rchild , root2->rchild ) &&( root1->val == root2->val ) ;
}

Node tree::TreeToList( Node main ){
    Node head = nullptr , tail = nullptr ; 
    if( main == nullptr ){
        return nullptr;
    }

    if( main->lchild == nullptr && main->rchild == nullptr ){
        main->lchild = main;
        main->rchild = main;
        return main;
    }

    if( main->lchild != nullptr ){
        head = TreeToList(main->lchild);
        tail = head->lchild;
        main->lchild = tail ;
        tail->rchild = main;
    }
    else{
        head = main;
    }

    if( main->rchild != nullptr ){
        tail = TreeToList(main->rchild);
        tail = tail->rchild;
        main->rchild = tail ;
        tail->lchild = main;
    }
    else{
        tail = main;
    }

    head->lchild =tail;
    tail->rchild = head;
    return head;
}

void tree::printAllPath(Node main , vector<int> &stk){
    if(main == nullptr)
        return;
    stk.push_back(main->val);
    if( main->lchild == nullptr && main->rchild ==nullptr){
        for ( auto i : stk){
            cout<<" "<<i;
        }
        stk.pop_back();
        cout<<endl;
        return ;
    }
    printAllPath(main->lchild , stk);
    printAllPath(main->rchild , stk);
    stk.pop_back();
}

Node tree::FindNode(Node main , int key1 , int key2 ){
   
   Node left , right ;

    if( main == nullptr )
        return nullptr;
    
    if( main->val == key1 || main->val == key2 )
        return main; 

    left = FindNode( main->lchild , key1 , key2 );
    right = FindNode( main->rchild , key1 , key2 );

    if( left != nullptr && right != nullptr )
        return main;
    if( left != nullptr  )
        return left;
    else if (right != nullptr)
        return right;
    else
        return nullptr;
}

int tree::MaxDepth(Node main ,int depth){
    if(main == nullptr )
        return depth;
    
    int left = MaxDepth( main->lchild , depth + 1 );
    int right = MaxDepth( main->rchild , depth + 1 );

    if( left > right )
        return left;
    else 
        return right;
}

int main(){
    tree t,t1;
    vector<int> temp = {1 , 2, 3, 4, 5 ,6, 7, 8, 9, 10 };
    t.BST( 0  ,  temp.size()  ,temp );
    cout<<"Preorder : "; t.preorder(t.root);
    cout<<"\n";
    cout<<"Postorder : "; t.postorder(t.root);
    cout<<"\n";
    cout<<"Inorder : "; t.inorder(t.root);
    cout<<"\n";
    cout<<"Level    order : "; t.levelOrder();
    cout<<"\n";
    cout<<"Tree Depth is  : "<<t.TreeDepth(t.root);
    cout<<"\n";
    cout<<"Tree size is  : "<<t.size(t.root);   
    cout<<"\n";
    cout<<"Tree 1 and Tree 2 are identical : (T/F) " << t.identicalTree(t.root , t1.root); 
    cout<<"Path to All Leaf nodes \n"; t.printAllPath(t.root , temp);
    cout<<"\n";
    cout<<"Finding Node with key 9 , 10 ";
    Node res = t.FindNode(t.root , 9 , 10);
    cout<<" "<<res->val;
    cout<<"\n";
    cout<<"Max Depth of a Tree is "<<t.MaxDepth(t.root , 0);
    return 0;
}
