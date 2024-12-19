// 땅따먹기 게임을 하려고 합니다. 땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고 모든 
// 칸에는 점수가 쓰여 있습니다. 1행부터 땅을 밟으며 한 행씩 내려올 때 각 행의 4칸 중 한 칸만 밟
// 으면서 내려와야 합니다. 단, 땅따먹기 게임에는 한 행씩 내려올 때 같은 열을 연속해서 밟을 수 없
// 는 특수 규칙이 있습니다. 예를 들어 다음과 같은 경우
// 1 2 3 5
// 5 6 7 X
// 4 3 2 1


// 1행에서 4번째 칸 5를 밟았으면 2행의 4번째 칸 8은 밟을 수 없습니다. 마지막 행까지 내려왔을 
// 때 얻을 수 있는 점수의 최댓값을 반환하는 solution( ) 함수를 완성하세요.
// 제약 조건
// • 행의 개수 N : 100,000 이하의 자연수
// • 열의 개수는 4개이고, 땅(land)은 2차원 배열로 주어집니다.
// • 점수 : 100 이하의 자연수
// 입출력의 예
// land result
// [[1, 2, 3, 5], [5, 6, 7, 8], [4, 3, 2, 1]] 16

// 프로토타입
// C++
// int solution(vector<vector<int>> land)

#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); ++i) // 행 (row)
    {
        for (int j = 0; j < 4; ++j) // 열 (column)
        {
            int maxVal = 0;
            for (int k = 0; k < 4; ++k) // 얘도 열이냐. 
            {
                if (k != j)
                {
                    maxVal = max(maxVal, land[i-1][k]);
                }
            }
            land[i][j] += maxVal;
        }
    }
    return *max_element(land.back().begin(), land.back().end());

}

void main()
{
    vector<vector<int>> land = {
        {1, 2, 3, 5}, 
        {5, 6, 7, 8}, 
        {4, 3, 2, 1}
    };

    int answer = solution(land);
    cout << "answer:" << answer << endl;
}
