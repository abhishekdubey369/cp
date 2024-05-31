// #include <corecrt_malloc.h>
#include<iostream>

using namespace std;

//method1

struct node{
    int data;
    struct node *next;
} *first = NULL;//start/head/first/root start is global variable

typedef struct node node;

node* nnode(){

    node* newnode;
    newnode =new node[sizeof(node)];
    cout<<"enter int data"<<" ";
    cin>>newnode->data;
    newnode->next=NULL;
    return newnode;

}

void createlist(int n){
    node* newnode;
    node* temp;
    for(int i=0;i<n;i++){
        newnode= nnode();
        if(first==NULL){
            first=newnode;
        }else{
            temp=first;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void Display(node *p){

    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

}

int Counter(node *p){
    int i=0;
    while (p!=NULL)
    {
        i++;
        p=p->next;
        /* code */
    }
    return i;
    

}

void insert(){
    int d,p,c;
    cout<<"enter data to be inserted"<<" ";
    cin>>d;
    cout<<"enter at what position"<<" ";
    cin>>p;
    c=Counter(first);
    if(p==1){
        node* temp;
        temp = new node[sizeof(node)];
        temp->data=d;
        temp->next=first;
        first=temp;
    }else if(p==c){
        node* temp;
        node* trav;
        temp = new node[sizeof(node)];
        temp->data=d;
        temp->next=NULL;
        trav=first;
        while(trav->next!=NULL){
            trav=trav->next;
        }
        trav->next=temp;
    }else if(p>1 && p<c){
        node* temp;
        node* prev;
        node* newnode;
        newnode = new node[sizeof(node)];
        newnode->data=d;
        temp=first;
        for(int i=0;i<p;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=newnode;
        newnode->next=temp;
    }else{
        cout<<"insertion is not possible "<<"\n try less than \t"<<Counter(first)<<endl;
        insert();
    }
}

void deletion(){
    char a;
    cout<<"element-e or postion-p"<<endl;
    cin>>a;
    if(a=='e'){
        int d;
        cout<<"enter element"<<" ";
        cin>>d;
        node* temp;
        node* prev;
        int c=1;
        temp=first;
        while(temp->data!=d){
            c++;
            prev=temp;
            temp=temp->next;
        }if(c==1){
            temp=first;
            first=temp->next;
            delete temp;
        }else if(c==Counter(first)){
            delete temp;
        }else if(c>1 && c<Counter(first)){
            prev->next=temp->next;
            delete temp;
        }else{
            cout<<"deletion is not possible"<<"\n it should be less than \t"<<Counter(first)<<endl;
            deletion();
        }
    }else{
        int p;
        cout<<"enter position"<<" ";
        cin>>p;
        node* temp;
        node* prev;
        temp=first;
        int c=p;
        while(c!=1){
            c--;
            prev=temp;
            temp=temp->next;
        }if(p==1){
            temp=first;
            first=temp->next;
            delete temp;
        }else if(p==Counter(first)){
            delete temp;
        }else if(p>1 && p<Counter(first)){
            prev->next=temp->next;
            delete temp;
        }else{
            cout<<"deletion is not possible"<<"\n it should be less than \t"<<Counter(first)<<endl;
            deletion();
        }
    }
}



//method2

class Node {
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }
  
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist{
    Node* head;
  
public:

    Linkedlist() { head = NULL; }
  
    void insertNode(int);
  

    void printList();

    void deleteNode(int);
};
  

void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
  
    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }
  
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }
  
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
             << endl;
        return;
    }
  
    temp1 = head;
  
    if (nodeOffset == 1) {
  
        head = head->next;
        delete temp1;
        return;
    }
  
    while (nodeOffset-- > 1) {

        temp2 = temp1;
  
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
  
    delete temp1;
}
  
void Linkedlist::insertNode(int data)
{

    Node* newNode = new Node(data);
  
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    Node* temp = head;
    while (temp->next != NULL) {

        temp = temp->next;
    }

    temp->next = newNode;
}
  
void Linkedlist::printList()
{
    Node* temp = head;
  
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


//method 3

class LL
{
    private:
        struct node 
        {
            int value;
            node* next;
            node(int v_) :value(v_), next(nullptr) {};
        };
        node* head;

    public:
        LL() 
        {
            head = nullptr;
        }
        void print() 
        {
            node* temp = head;
            while (temp) 
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }
        void insert_sorted_order(int v_) 
        {
            if (!head)
                head = new node(v_);
            else
            {
                node* insert = new node(v_);
                node** temp = &head;
                while ((*temp) && insert->value > (*temp)->value)
                    temp = &(*temp)->next;
                insert->next = (*temp);
                (*temp) = insert;
            }
        }

        void remove(int v_)
        {
            node** temp = &head;
            while ((*temp)->value != v_)
                temp = &(*temp)->next;
            node* d = (*temp);
            (*temp) = (*temp)->next;
            delete d;
        }

        void insertRear(int v_)//single pointer
        {
            if (!head)
                head = new node(v_);
            else
            {
                node* temp = new node(v_);
                temp->next = head;
                head = temp;
            }
        }
};


int main(void){
    int n;
    cout<<"number of node"<<" ";
    cin>>n;
    createlist(n);
    Display(first);
    // deletion();
    insert();
    Display(first);
    return 0;
}