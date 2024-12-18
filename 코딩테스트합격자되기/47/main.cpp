// 정수 N을 입력받아 1부터 N까지의 숫자 중에서 합이 10이 되는 조합을 배열로 반환하는 
// solution( ) 함수를 작성하세요.
// 제약 조건
// • 백트래킹을 활용해야 합니다.
// • 숫자 조합은 오름차순으로 정렬되어야 합니다.
// • 같은 숫자는 한 번만 선택할 수 있습니다.
// • N은 1 이상 10 이하인 정수입니다.
// 입출력의 예
// N result
// 5 [[1, 2, 3, 4], [1, 4, 5], [2, 3, 5]]
// 2 [ ]
// 7 [[1, 2, 3, 4], [1, 2, 7], [1, 3, 6], [1, 4, 5], [2, 3, 5], [3, 7], [4, 6]]

// vector<vector<int>> solution(int N)
// 아이구 내손으로 풀고싶었지만 못품 ㅋ
// 재귀함수는 내머리로 응용이 불가능한건가


#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

int indent = -1;

void indenter()
{
    for (int i = 0 ; i < indent; i++)
    {
        cout << "\t";
    }
}
void backtrack(int N, int sum, int start)
{
    indent++;
    indenter();
    cout << "sum:" << sum << " start:" << start << " end:" << N << endl;
    if (sum == 10) 
    {
        indenter();
        cout << "exit" << endl;
        results.push_back(selected_nums);
        indent--;
        return;
    }

    for (int i = start; i <= N; ++i)
    {
        indenter();
        cout << "i: " << i << endl;
        if (sum + i <= 10)
        {
            selected_nums.push_back(i);
            backtrack(N, sum + i, i + 1);
            selected_nums.pop_back();
        
        }
    }
    indenter();
    cout << "function end" << endl;
    indent--;
}


vector<vector<int>> solution(int N)
{
    backtrack(N, 0, 1);
    return results;
}

void main()
{
    int N = 5;
    
    vector<vector<int>> result = solution(N);

    cout << "answer" << endl;
    for(auto& col : result)
    {
        for(auto& row : col)
        {
            cout << row << " ";
        }
        cout << endl;
    }

}