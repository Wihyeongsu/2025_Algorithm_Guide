#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* rlink;
    Node* llink;

    Node(int value): data(value), rlink(nullptr), llink(nullptr) {}
};

class Dequeue{
private:
    Node* frontNode;
    Node* rearNode;
    int queue_size;
public:
    Dequeue(): frontNode(nullptr), rearNode(nullptr), queue_size(0) {}

    ~Dequeue() {
        while(!empty())  pop_front();
    }
    
    void push_front(int x){
        Node* newNode = new Node(x);

        if(empty()){
            frontNode = newNode;
            rearNode = newNode;
        }
        else{
            frontNode->llink = newNode;
            newNode->rlink = frontNode;
            frontNode = newNode;
        }

        queue_size++;
    }

    void push_back(int x){
        Node* newNode = new Node(x);

        if(empty()){
            frontNode = newNode;
            rearNode = newNode;
        }
        else{
            rearNode->rlink = newNode;
            newNode->llink = rearNode;
            rearNode = newNode;
        }
        
        queue_size++;
    }

    int pop_front(){
        if(empty())  return -1;

        Node* old = frontNode;
        int returnData = old->data;
        frontNode = frontNode->rlink;
        if(frontNode == nullptr)  rearNode = nullptr;
        else  frontNode->llink = nullptr;

        delete old;
        queue_size--;

        return returnData;
    }

    int pop_back(){
        if(empty())  return -1;

        Node* old = rearNode;
        int returnData = old->data;
        rearNode = rearNode->llink;
        if(rearNode == nullptr)  frontNode = nullptr;
        else  rearNode->rlink = nullptr;

        delete old;
        queue_size--;

        return returnData;
    }

    int size(){
        return queue_size;
    }

    int empty(){
        return (frontNode == nullptr && rearNode == nullptr) ? 1 : 0;
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

int scanInt(void){
    int x; 
    cin >> x;
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Dequeue q;

    for(int i = 0; i < n; i++){
        string command;
        cin >> command;

        if(command == "push_front"){
            q.push_front(scanInt());
        }
        else if(command == "push_back"){
            q.push_back(scanInt());
        }
        else if(command == "pop_front")
            cout << q.pop_front() << "\n";
        else if(command == "pop_back")
            cout << q.pop_back() << "\n";
        else if(command == "size")  
            cout << q.size() << "\n";
        else if(command == "empty")  
            cout << q.empty() << "\n";
        else if (command == "front")  
            cout << q.front() << "\n";
        else if(command == "back")
            cout << q.back() << "\n";
        else  cout << "잘못된 명령입니다." << "\n";
    }

    return 0;
}


