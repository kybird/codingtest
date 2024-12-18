// 가로, 세로 길이가 n인 정사각형 체스판이 있습니다. 체스판 위의 n개의 퀸이 서로를 공격할 수 없
// 도록 배치하고 싶습니다. 체스판의 길이 n이 주어질 때 조건을 만족하는 퀸 배치 수를 반환하는 
// solution( ) 함수를 완성하세요.
// 입출력의 예
// n result
// 4 2

// long long solution(int n)

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isSameRow(int placeRow, int currentRow) 
{
    return placeRow == currentRow;
}

bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow)
{
    return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

bool isSafePosition(const vector<int> &queen, int col, int row)
{
    for (int i = 0; i < col; ++i)
    {
        if (isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row))
        {
            return false;
        }
    }
    return true;
}
int tab = -1;
void indent()
{
    for(int i = 0; i < tab; i++)
    {
        cout << "\t";
    }
    
}

long long placeQueens(vector<int> &queen, int col)
{
    tab++;
    
    int n = queen.size();
    if (col == n) {
        indent();
        cout << "return 1 col:" << col << " n:" << n << endl;
        tab--;
        return 1;
    }

    long long count = 0;
    for (int row = 0; row < n; ++row)
    {
        indent();
        cout << "col:" << col << " row:" << row << endl;    
        if (isSafePosition(queen, col, row)) 
        {
            
            queen[col] = row;
            indent();
            cout << "queen[" << col << "] = " << row << endl;    
            count += placeQueens(queen, col + 1);
            indent();
            cout << "count:" << count << " reset col:" << col << " row:"<< row << endl;
            queen[col] = -1;
        }
    }
    tab--;
    return count;
}

long long solution(int n)
{
    vector<int> queen(n, -1);

    return placeQueens(queen, 0);
}

void main()
{
    int n = 4;
    int result = solution(n); 
    cout << "answer:" << result << endl;
}