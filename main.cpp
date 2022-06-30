#include <bits/stdc++.h>
using namespace std;
template<class T>
class BSTNode{
private:
    T key;
    BSTNode* left;
    BSTNode*right;
public:
    BSTNode () {left = right = 0;}
    BSTNode (T& el, BSTNode* l = 0, BSTNode* r = 0){
        key   = el;
        left  = l;
        right = r;
    }
    void setLeft(BSTNode *left) {
        BSTNode::left = left;
    }

public:
    void setRight(BSTNode *right) {
        BSTNode::right = right;
    }
    void setKey(T key) {
        BSTNode::key = key;
    }
    BSTNode* getLeft(){return left;}
    BSTNode* getRight(){return right;}
    T getKey(){return key;}

};
template <class T>
class BST {
public:
    BSTNode<T>* root;
public:
    BST ()         {root = 0;}
    void clear()   {root = 0;}
    bool isEmpty() {return root == 0;}
    T* search (T& el) {
        BSTNode<T> * current =root;
        while(current!=0){
            if(el== current->getKey()){
                return &current->getKey();
            }else if(el<current->getKey()){
                current=current->getLeft();
            }else{
                current=current->getRight();
            }
        }
    }
    void breadthFirst(){
        BSTNode<T> * current =root;
        queue<BSTNode<T>*> q;
        if(current!=0){
            q.push(current);
            while(!q.empty()){
                current=q.front();
                q.pop();
                cout<<current->getKey()<<" ";
                if(current->getLeft()!=0){
                    q.push(current->getLeft());
                }
                if(current->getRight()!=0){
                    q.push(current->getRight());
                }
            }
        }
    }
    // DEPTH
    void inorder(BSTNode<T> * p){
        if(p!=0){
            inorder(p->getLeft());
            cout<<p->getKey()<<" ";
            inorder(p->getRight());
        }
    }
    void preorder(BSTNode<T> * p){
        if(p!=0){
            cout<<p->getKey()<<" ";
            preorder(p->getLeft());
            preorder(p->getRight());
        }
    }
    void postorder(BSTNode<T> * p){
        if(p!=0){
            postorder(p->getLeft());
            postorder(p->getRight());
            cout<<p->getKey()<<" ";
        }
    }
    void insertion(T&el){
        BSTNode<T> * p =root , *prev=0;
        while(p!=0){
            prev=p;
            if(el> p->getKey()){
                p=p->getRight();
            }else{
                p=p->getLeft();
            }
        }
        if(root==0){
            root= new BSTNode<int>(el);
        }else if(prev->getKey()<el){
            prev->setRight(new BSTNode<int>(el));
        }else{
            prev->setLeft(new BSTNode<int>(el));
        }
    }
};

int main()
{
    BST<int> tree;
    int val=10;
    tree.insertion(val);
    val=13;
    tree.insertion(val);
    val=2;
    tree.insertion(val);
    val=12;
    tree.insertion(val);
    val=25;
    tree.insertion(val);
    val=20;
    tree.insertion(val);
    val=31;
    tree.insertion(val);
    val=29;
    tree.insertion(val);

    tree.inorder(tree.root);cout<<endl;
    tree.preorder(tree.root);cout<<endl;
    tree.postorder(tree.root);cout<<endl;
    tree.breadthFirst();

}



