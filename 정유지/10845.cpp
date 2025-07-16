#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* link;

    Node(int value): data(value), link(nullptr) {}
};

class Queue{
private:
    Node* frontNode;
    Node* rearNode;
    int queue_size;
public:
    Queue(): frontNode(nullptr), rearNode(nullptr), queue_size(0) {}

    ~Queue() {
        while(!empty())  pop();
    }

    void push(int x){
        Node* newNode = new Node(x);

        if(rearNode == nullptr){
            frontNode = newNode;
            rearNode = newNode;
        }
        else{
            rearNode->link = newNode;
            rearNode = newNode;
        }
        
        queue_size++;
    }

    int pop(){
        if(empty())  return -1;

        Node* old = frontNode;
        int returnData = old->data;
        frontNode = frontNode->link;
        if(frontNode == nullptr)  rearNode = nullptr;
        delete old;
        queue_size--;

        return returnData;
    }

    int size(){
        return queue_size;
    }

    int empty(){
        return (frontNode == nullptr) ? 1 : 0;
    }

    int front(){
        if(empty())  return -1;
        return frontNode->data;
    }

    int back(){
        if(empty())  return -1;
        return rearNode->data;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Queue q;

    for(int i = 0; i < n; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(command == "pop")
            cout << q.pop() << endl;
        else if(command == "size")  
            cout << q.size() << endl;
        else if(command == "empty")  
            cout << q.empty() << endl;
        else if (command == "front")  
            cout << q.front() << endl;
        else if(command == "back")
            cout << q.back() << endl;
        else  cout << "잘못된 명령입니다." << endl;
    }

    return 0;
}


