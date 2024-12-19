// 주어진 두 개의 문자열 str1과 str2에 대해 최장 공통 부분 수열의 길이를 반환하는 solution( ) 함
// 수를 구현하세요.
// 제약 
	
// 조건
// • 각 문자열 str1과 str2의 길이는 1 이상 1,000 이하입니다.
// • 문자열은 알파벳 대문자로 구성되어 있습니다.
// 입출력의 예
// str1 str2 result
// “ABCBDAB” “BDCAB” 4
// “AGGTAB” “GXTXAYB” 4

// int solution(string str1, string str2)

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 최장 공통 부분 수열
int solution(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];

}

void main()
{
    string str1 = "ABCBDAB";
    string str2 = "BDCAB";

    int answer = solution(str1, str2);

    cout << "answer:" << answer;
}