#include <iostream>
using namespace std;

class treenode{
public:
    treenode(int data,treenode* r=nullptr,treenode* l=nullptr):data(data),rchild(r),lchild(l){}

    int data;
    treenode* rchild;
    treenode* lchild;
};

void addnode(int v,treenode* father){
    if(v==father->data) return;
    if(father->data>v){
        if(!father->lchild) father->lchild=new treenode(v);
        else addnode(v,father->lchild);
    }
    if(father->data<v){
        if(!father->rchild) father->rchild=new treenode(v);
        else addnode(v,father->rchild);
    }
    return ;
}

treenode* findl(treenode* node){//寻找一个节点的最左子节点
    if(!node->lchild) return node;
    return findl(node->lchild);
}

treenode* findr(treenode* node){//寻找一个节点的最右子节点
    if(!node->rchild) return node;
    return findr(node->rchild);
}

void delnode(int val,treenode* node){
    if(val==node->data){
        findl(node)->lchild=node->lchild;
        return ;
    }
    if(val<node->data){
        delnode(val,node->lchild);
    }
    if(val>node->data){
        delnode(val,node->rchild);
    }
}

void noderelese(treenode* node){//二叉树释放
    if(node->lchild)noderelese(node->lchild);
    if(node->rchild)noderelese(node->rchild);
    delete node;
}

void traversal(treenode* node){//中序遍历
    if(node->lchild)traversal(node->lchild);
    cout<<node->data<<endl;
    if(node->rchild)traversal(node->rchild);
}

int main()
{
    treenode* head=new treenode(10);
    addnode(5,head);
    addnode(6,head);
    addnode(7,head);
    addnode(11,head);
    addnode(13,head);
    cout<<"yza1"<<endl;
    traversal(head);
    cout<<"yza2"<<endl;
    noderelese(head);
    return 0;
}