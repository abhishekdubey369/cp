#include<iostream>
#include <iterator>
#include <string>

using namespace std;

class node{
    public:
        char data;
        node* next;
        node(char x);
};

node::node(char x){
    data = x;
}

class stack{
    private:
        node* stk;
        node* top;
    public:
        stack(){
            stk=nullptr;
        };
        int priority(char a);
        void push(char x);
        char pop();
        string reverse(char* str);
        string in2pos(char* a);
        void in2pre(char* a);
        void balance(char* a);
        ~stack(){
            delete stk;
            delete top;
        }

};

int stack::priority(char a){
    if(a=='+' || a=='-'){
        return 1;
    }else if(a=='/' || a=='*'){
        return 2;
    }else{
        return 3;
    }
}

void stack::push(char x){
    if(stk == nullptr){
        stk= new node(x);
        top = stk;
        stk->next=nullptr;
    }else{
        top= new node(x);
        top->next=stk;
        stk = top;
    }
}

string stack::reverse(char* str){
    int i=0,j=0;
    string restr;
    stack se;
    while(str[i]!='\0'){
        se.push(str[i]);
        i++;
    }while(i!=-1){
        cout<<se.pop();
    }
    return restr;
}

char stack::pop(){
    // cout<<top<<endl;
    char dt;
    if(stk == nullptr){
        return NULL;
    }else{
        dt = stk->data;
        top=top->next;
        stk=top;
        return dt;}
}

string stack::in2pos(char* a){
    /*
    infix to postfix
    l2R scan
    if operand print.if operator push if stk is null
    else check already present element priority if high pop again check if low store
    at the end pop all element;
    */
   int i=0;
   string i2po;
   while(a[i]!='\0'){
    if((a[i]>='A' && a[i]<='Z')|| (a[i]>='a' && a[i]<='z')){
        i2po+=a[i];
    }else{
        if(stk==nullptr){
        push(a[i]);}
        else{
            if(priority(stk->data)>= priority(a[i])){
                i2po+=pop();
                push(a[i]);
            }else{
                push(a[i]);
            }
        }
    }
    i++;
   }
   while(stk!=nullptr){
        i2po+=pop();
    }
    return i2po;

}

void stack::in2pre(char* a){
    /*
    method 1 reverse the infix string after that generate postfix 
    than reverse the postfix experession to get the prefix just remeber to 
    swap parantheses*/
    // char* temp[];
    string b;
    int i=0;
    while(a[i]!='\0'){
        b+=a[i++];
    }
    int n=b.length();
    char temp[n];
    for(int i = 0; i < n; i++)
        temp[i]=b[n-i-1];
    b = in2pos(temp);
    for (int i = 0; i < n / 2; i++)
        swap(b[i], b[n - i - 1]);
    cout<<b<<endl;
}

void stack::balance(char* a){
    int i=0;
    while(a[i]!='\0'){
        if(a[i]=='(' || a[i]=='{' || a[i]=='['){
            push(a[i]);
            i++;
        }else{
            char x=pop();
            if((x=='(' && a[i]==')') || (x=='{' && a[i]=='}') || (x=='[' && a[i]==']')){
                i++;
            }else{
                cout<<"not balance"<<endl;
                return;
            }
        }
    }

}

int main(void){
    stack b;
    b.push('A');
    b.push('B');
    cout<<b.pop()<<endl;
    cout<<b.pop()<<endl;
    char* a = "A+B/C+D*E";
    char* c = "({[([])])";
    char* d = "Tutedude";
    // b.balance(c);
    // b.in2pos(a);
    
    cout<<b.reverse(d)<<endl;
    // b.in2pre(a);
}