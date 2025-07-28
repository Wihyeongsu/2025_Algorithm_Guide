#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* link;

    Node(int val) : data(val), link(nullptr) {}
};

class Stack{
private:
    Node* top;
    int stack_size;
public:
    Stack(): top(nullptr), stack_size(0) {}
    ~Stack(){
        while(!empty())  pop();
    }

    void push(int x){
        Node* newNode = new Node(x);
        newNode->link = top;
        top = newNode;

        stack_size++;
    }

    char pop(){
        if(empty())  return -1;

        Node* old = top;
        char data = old->data;
        top = top->link;
        delete old;
        stack_size--;

        return data;
    }

    bool empty(){
        return (top == nullptr) ? true : false;
    }
};

bool isVPS(string s){
    Stack stack;

    for(int i = 0; i < s.size(); i++){
        char symbol = s[i];
        
        if(symbol == '(')  stack.push(symbol);
        else if(symbol == ')'){
            if(stack.pop() != '(')  return false;
        }
    }

    if(stack.empty())  return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_number;
    cin >> test_number;

    for(int i = 0; i < test_number; i++){
        string s;
        cin >> s;

        if(isVPS(s))  cout << "YES" << "\n";
        else  cout << "NO" << "\n";
    }

    return 0;
}
