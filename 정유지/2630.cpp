#include <iostream>
using namespace std;

const int MAX = 128;
int papers[MAX][MAX];
int white_paper = 0, blue_paper = 0;

// 모두 같은 수로 되어 있는지 확인
bool isSame(int row, int col, int size){
    if(size == 1)  return true;

    int first = papers[row][col];
    for(int i = row; i < row + size; i++)
        for(int j = col; j < col + size; j++)
            if(papers[i][j] != first)  return false;

    return true;
}

// 종이의 개수 구하기
void number_of_papers(int row, int col, int size){
    if(isSame(row, col, size)){
        int value = papers[row][col];

        if(value == 0)  white_paper++;
        else  blue_paper++;
        return;
    }

    // 4분할
    int divided_size = size / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            number_of_papers(row + i*divided_size, col + j*divided_size, divided_size);    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> papers[i][j];

    number_of_papers(0, 0, n);

    cout << white_paper << "\n" << blue_paper << "\n";

    return 0;
}
