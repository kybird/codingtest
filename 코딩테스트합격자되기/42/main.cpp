// 네트워크란 컴퓨터 상호 간에 정보를 교환하도록 연결된 어떤 형태를 의미합니다. 
// 예를 들어 컴퓨터 A, B가 직접 연결되어 있고 컴퓨터 B, C가 직접 연결되어 있을 때 컴퓨터 A, C는 간접 연결되
// 어 있어 정보를 교환할 수 있습니다. 그러면 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 
// 수 있습니다. 컴퓨터 개수가 n, 연결 정보가 담긴 2차원 배열 computers가 주어질 때 네트워크 
// 개수를 반환하는 solution( ) 함수를 작성하세요.

// 제약 조건
// • 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
// • 각 컴퓨터는 0부터 n - 1인 정수로 표현합니다.
// • i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
// • computers[i][i]는 항상 1입니다.
// 입출력의 예
// n computers result
// 3 [[1, 1, 0], [1, 1, 0], [0, 0, 1]] 2
// 3 [[1, 1, 0], [1, 1, 1], [0, 1, 1]] 1


// 첫 번째 입출력 예를 그림으로 표현하면 오른쪽 그림과 같습니다. 
// 프로토타입
// C++
// int solution(int n, vector<vector<int>> computers)
// 이문제를 보고 깊이 우선 탐색을 하면 된다는것을 나는 떠올릴수 있는가
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 그래프는 dfs 던 bfs 던 거의 무조건 이게 필요한거같구만
vector<bool> visited;

// 깊이우선 탐색 함수
void dfs(const vector<vector<int>>& network, int node)
{
    visited[node] = true;

    for (int i = 0; i < network[node].size(); i++)
    {
        if (network[node][i] && !visited[i]) // 연결되있고. 방문하지않았으면
        {
            dfs(network, i); // 재귀호출
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    visited = vector<bool>(computers.size(), false);

    int networkCount = 0;
    for (int i = 0 ; i < computers.size(); i++)
    {
        if (!visited[i])
        {
            dfs(computers, i);
            networkCount++;
        }
    }
    return networkCount;
}

void main()
{
    int n = 3;
    vector<vector<int>> computers = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    // expected 2

    // int n = 3;
    // vector<vector<int>> computers = {
    //     {1,1,0},
    //     {1,1,1},
    //     {0,1,1}
    // };
    int answer = solution(n, computers);

    cout << "answer:" << answer;

}
