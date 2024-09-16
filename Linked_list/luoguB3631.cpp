#include  <iostream>

bool t[2000000]={0};
class Node{
public:
    int num;
    Node* next;
    Node(int a=0,Node* b=nullptr){
        num=a;
        next=b;
    }
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){head=nullptr;}
    ~LinkedList(){
        Node*p=head;
        while(p!=nullptr){
            Node*c=p;
            p=p->next;
            delete c;
        }
    }
    void Nodeadd(int a=0,int target=0){
        t[a]=1;
        Node* Nnode = new Node(a);
        if(head==nullptr){
            head=Nnode;
            return;
        }
        Node*p=head;
        while(p!=nullptr&&p->num!=target) p=p->next;
        if(p==nullptr) return;//插入失败
        Nnode->next=p->next;
        p->next=Nnode;
    }
    void Nodedelete(int target=0){
        t[target]=0;
        Node*p=head,*pre=nullptr;
        while(p!=nullptr&&p->num!=target) p=p->next;
        if(p==nullptr || p->next==nullptr) return;
        Node*c=p->next;
        p->next=c->next;
        delete c->next;
    }
    int Nodeselect(int target=0){
        Node*p=head;
        while(p!=nullptr&&p->num!=target) p=p->next;
        if(p==nullptr || p->next==nullptr) return 0;
        return p->next->num;
    }
};


int main()
{   
    LinkedList yza;
    yza.Nodeadd(1);
    int n;
    std::cin>>n;
    for(int i=0;i<n;++i){
        int a=0,b=0,c=0;
        std::cin>>a;
        if(a!=1) {
            std::cin>>b;
            if(a==2) {
                std::cout<<yza.Nodeselect(b)<<std::endl;
            }
            if(a==3){
                yza.Nodedelete(b);
            }
        }
        else {
            std::cin>>b>>c;
            if(t[c]==1) continue;
            yza.Nodeadd(c,b);
        }
    }
    return 0;
}

//在洛谷上有解决不了的re和tle 感觉作为oj题不好用这种死板的格式做题