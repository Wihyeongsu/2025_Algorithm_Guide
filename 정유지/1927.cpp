#include <iostream>
#include <vector>
using namespace std;


vector<int> maxHeap = {0};

// pop 및 힙 재정렬 함수
int pop(void){
    if(maxHeap.size() <= 1)  return 0;

    int root = maxHeap[1];
    maxHeap[1] = maxHeap.back();  // 가장 마지막 요소를 루트로 올림
    maxHeap.pop_back();  // 배열에서 마지막 요소 제거

    int parent = 1;
    int size = maxHeap.size();
    while(true){
        int left = parent * 2;  // 왼쪽 자식 인덱스
        int right = parent * 2 + 1;  // 오른쪽 자식 인덱스
        int smallest = parent;

        if(left < size && maxHeap[left] < maxHeap[smallest])
            smallest = left;
        if(right < size && maxHeap[right] < maxHeap[smallest])
            smallest = right;
        if(smallest == parent)  break;

        swap(maxHeap[parent], maxHeap[smallest]);
        parent = smallest;
    }

    return root;
}

// 힙 정렬 함수
void insert(int x){
    maxHeap.push_back(x);
    int index = maxHeap.size() - 1;
    
    while(index > 1 && maxHeap[index] < maxHeap[index/2]){
        swap(maxHeap[index], maxHeap[index/2]);
        index /= 2;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 0)  cout << pop() << "\n";
        else  insert(x);
    }

    return 0;
}
