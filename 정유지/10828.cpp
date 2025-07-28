#include <iostream>
#include <string>
using namespace std;

void push(int x);
int pop(void);
int size(void);
int empty(void);
int top(void);

int stack[10000];
int stack_top = -1;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(command == "pop")
            cout << pop() << endl;
        else if(command == "size")  
            cout << size() << endl;
        else if(command == "empty")  
            cout << empty() << endl;
        else if (command == "top")  
            cout << top() << endl;
        else  cout << "잘못된 명령입니다." << endl;
    }

    return 0;
}


void push(int x){
    stack[++stack_top] = x;
}
int pop(void){
    if(empty())  return -1;
    return stack[stack_top--];  
}
int size(void){
    return stack_top + 1;
}
int empty(void){
    if(stack_top == -1)  return 1;
    else  return 0;
}
int top(void){
    if(empty())  return -1;
    return stack[stack_top];
}
