#include <iostream>
#include <cstdio>

using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char x) : data(x), next(nullptr) {}
};

class PIPC {
private:
    char* data;
    Node* operand;
    Node* operators;
    Node* complex;

public:
    PIPC(char* str) : data(str), operand(nullptr), operators(nullptr), complex(nullptr) {}
    void prefixToinfix();
    void push(char chr, Node*& node);
    void push(char* chr, Node*& node);
    char pop(Node*& node);
    void postfixToinfix();
    void prefixTopostfix();
    void postfixToprefix();
    void infixToprefix();
    void infixTopostfix();
    ~PIPC();
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void PIPC::postfixToprefix() {
    int i = 0;
    int t=1;
    while (data[i] != '\0') {
        if (isOperand(data[i])) {
            push(data[i], operand);
            // cout<<pop(operand);
        } else {
            // cout<<pop(operand);
            if(t==1){
                char operand1 = pop(operand);
                char operand2 = pop(operand);
            }else if (t==2)
            {
                char* operand1 = nullptr;
                while(complex->data != '('){
                    strcat(operand1,pop(data));
                }
            }
            // if (operand1 == '\0' || operand2 == '\0') {
            //     cerr << "Error: Insufficient operands for operator\n";
            //     return;
            // }

            // char brack[3] = {data[i], operand2, operand1};
            // push(brack, complex);
        }
        i++;
    }
    while (complex != nullptr) {
        char result = pop(complex);
        if (result != '\0') {
            cout << result;
        }
    }
}

void PIPC::prefixToinfix() {
    int i = 0;
    while (data[i] != '\0') {
        if (isOperator(data[i])) {
            push(data[i], operators);
        } else {
            cout << data[i];
            if (operators != nullptr) {
                cout << pop(operators);
            }
        }

        i++;
    }

    // Pop any remaining operators from the stack and print them
    while (operators != nullptr) {
        cout << pop(operators);
    }
}

void PIPC::push(char chr, Node*& node) {
    Node* newNode = new (nothrow) Node(chr);
    if (newNode == nullptr) {
        cerr << "Memory allocation failed." << endl;
        return;
    }
    newNode->next = node;
    node = newNode;
}

void PIPC::push(char* chr, Node*& node) {
    int i = 0;
    Node* newNode1 = new (nothrow) Node('(');
    newNode1->next = node;
    node = newNode1;
    while (chr[i] != '\0') {
        Node* newNode = new (nothrow) Node(chr[i]);
        if (newNode == nullptr) {
            cerr << "Memory allocation failed." << endl;
            return;
        }
        newNode->next = node;
        node = newNode;
        i++;
    }
    Node* newNode2 = new (nothrow) Node(')');
    newNode2->next = node;
    node = newNode2;
}

char PIPC::pop(Node*& node) {
    if (node == nullptr) {
        cerr<<"Underflow\n";
        return '\0';
    }
    Node* temp = node;
    node = node->next;
    char ret = temp->data;
    delete temp;
    return ret;
}

PIPC::~PIPC() {
    while (operand != nullptr) {
        Node* temp = operand;
        operand = operand->next;
        delete temp;
    }
}

int main() {
    char expression[] = "ABC/-AK/L-*";  // Change this to your desired postfix expression

    PIPC pipc(expression);

    // cout << "Infix Expression: ";
    pipc.postfixToprefix();

    return 0;
}
