// 인수로 아직 완성되지 않은 9 X 9 스도쿠 배열 board를 받습니다. 답을 채우지 않은 부분에는 0
// 이 들어 있습니다. 스도쿠 규칙에 맞게 채운 배열을 반환하는 solution( ) 함수를 작성하세요. 해
// 는 유일하지 않을 수 있습니다. 스도쿠의 조건에 맞다면 맞는 해라고 생각하시면 됩니다. 스도쿠의 
// 규칙은 아래와 같습니다.
// 1 가로줄, 세로줄에는 1부터 9까지의 숫자가 한 번씩 나타나야 합니다.
// 2 9 × 9 보드를 채울 9개의 작은 박스(3 × 3 크기)에도 1부터 9까지의 숫자가 한 번씩 나타나
// 야 합니다.
// 제약 조건
// • 문제에 주어지는 board 중 스도쿠를 완성하지 못하는 board는 없다고 가정합니다. 예를 들
// 어 특정 행이나 열에 같은 숫자가 있는 경우는 없습니다. 
// 입출력의 예
// board result
// [
//  [5, 3, 0, 0, 7, 0, 0, 0, 0],
//  [6, 0, 0, 1, 9, 5, 0, 0, 0], 
//  [0, 9, 8, 0, 0, 0, 0, 6, 0],
//  [8, 0, 0, 0, 6, 0, 0, 0, 3],
//  [4, 0, 0, 8, 0, 3, 0, 0, 1],
//  [7, 0, 0, 0, 2, 0, 0, 0, 6],
//  [0, 6, 0, 0, 0, 0, 2, 8, 0],
//  [0, 0, 0, 4, 1, 9, 0, 0, 5],
//  [0, 0, 0, 0, 8, 0, 0, 7, 9],
// ]
// [
//  [5, 3, 4, 6, 7, 8, 9, 1, 2],
//  [6, 7, 2, 1, 9, 5, 3, 4, 8],
//  [1, 9, 8, 3, 4, 2, 5, 6, 7],
//  [8, 5, 9, 7, 6, 1, 4, 2, 3],
//  [4, 2, 6, 8, 5, 3, 7, 9, 1],
//  [7, 1, 3, 9, 2, 4, 8, 5, 6],
//  [9, 6, 1, 5, 3, 7, 2, 8, 4],
//  [2, 8, 7, 4, 1, 9, 6, 3, 5],
//  [3, 4, 5, 2, 8, 6, 1, 7, 9],
// ]
// [
//  [0, 0, 0, 0, 0, 0, 0, 0, 0],
//  [0, 0, 0, 0, 0, 0, 0, 0, 0], 
//  [0, 0, 0, 0, 0, 0, 0, 0, 0], 
//  [0, 0, 0, 0, 0, 0, 0, 0, 0], 
//  [0, 0, 0, 0, 0, 0, 0, 0, 0], 
//  [0, 0, 0, 0, 0, 0, 0, 0, 0], 
//  [0, 0, 0, 0, 0, 0, 0, 0, 0], 
//  [0, 0, 0, 0, 0, 0, 0, 0, 0], 
//  [0, 0, 0, 0, 0, 0, 0, 0, 0]
// ]
// [
//  [1 2 3 4 5 6 7 8 9], 
//  [4 5 6 7 8 9 1 2 3],
//  [7 8 9 1 2 3 4 5 6], 
//  [2 1 4 3 6 5 8 9 7], 
//  [3 6 5 8 9 7 2 1 4], 
//  [8 9 7 2 1 4 3 6 5], 
//  [5 3 1 6 4 2 9 7 8], 
//  [6 4 2 9 7 8 5 3 1], 
//  [9 7 8 5 3 1 6 4 2]
// ]

// vector<vector<int>> solution(vector<vector<int>> input_board)
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> board;

bool isValid(int num, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num || board[i][col] == num)
        {
            return false;
        }
    }
    
    int startRow = row - row %3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

pair<int, int> find_empty_position() {
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {   
            if (board[row][col] == 0)
            {
                return {row, col};
            }
        }
    }
    return {-1, -1};
}
void solve_sudoku()
{
    pair<int, int> pos = find_empty_position();

    if (pos.first == -1)
    {
        return;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(num, pos.first, pos.second))
        {
            board[pos.first][pos.second] = num;
            solve_sudoku();

            // 완성되면 더이상 탐색하지 않음
            if (find_empty_position().first == -1)
            {
                return;
            }
            // 얘는 왜해?
            board[pos.first][pos.second] = 0;
        }
    }
}
vector<vector<int>> solution(vector<vector<int>> input_board)
{
    board = input_board;

    solve_sudoku();
    return board;
}

void main()
{
    vector<vector<int>> input_board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    board = solution(input_board);

    for (auto rows : board)
    {
        for (auto row : rows)
        {
            cout << row << "  ";
        }
        cout << endl;
    }
}
