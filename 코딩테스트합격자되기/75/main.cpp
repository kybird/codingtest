// 위와 같은 정수 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중 거쳐간 숫자의 합이 가장 큰 경
// 우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로
// 만 이동합니다. 예를 들어 3에서는 8 또는 1로만 이동할 수 있습니다. 삼각형의 정보가 담긴 배열 
// triangle이 주어질 때 거쳐간 숫자의 최댓값을 반환하는 solution( ) 함수를 완성하세요.
// 제약 
	
// 조건
// • 삼각형의 높이는 1 이상 500 이하입니다.
// • 삼각형을 이루고 있는 숫자는 0 이상 9999 이하의 정수입니다.
// 입출력의 예
// triangle result
// [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]] 30
// 프로토타입
// C++
// int solution(vector<vector<int>> triangle)
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int n = triangle.size(); // 열인가
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }

    return dp[0][0];

}

void main()
{
    vector<vector<int>> triangle = {
        {7}, 
        {3, 8}, 
        {8, 1, 0}, 
        {2, 7, 4, 4}, 
        {4, 5, 2, 6, 5}
    };

    int answer = solution(triangle);

    cout << "answer:" << answer << endl;
}

