#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* link;

    Node(int val) : data(val), link(nullptr) {}
};

class Queue{
private:
    Node* frontNode;
    Node* rearNode;
    int queueSize;
public:
    Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}
    ~Queue(){
        while(!empty())  pop();
    }

    void push(int x){
        Node* newNode = new Node(x);
        if(empty()){
            frontNode = newNode;
            rearNode = newNode;
        }
        else{
            rearNode->link = newNode;
            rearNode = newNode;
        }
        queueSize++;
    }

    int pop(){
        if(empty())  return -1;
        Node* old = frontNode;
        int tmp = old->data;
        
        frontNode = frontNode->link;
        if(frontNode == nullptr)  rearNode = nullptr;
        delete old;
        queueSize--;

        return tmp;
    }

    bool empty(){
        return (frontNode == nullptr && rearNode == nullptr) ? true : false;
    }

    int getQueueSize(){
        return queueSize;
    }
};

int cards(int n){
    Queue que;

    for(int i = 1; i <= n; i++)
        que.push(i);

    int que_size = que.getQueueSize();
    while(que_size != 1){
        int delete_data = que.pop();
        que.push(que.pop());
        que_size--;
    }

    return que.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << cards(n) << "\n";

    return 0;
}
