// 전력망을 둘로 나누기

// n 개의 송전탑이 전선을 통해 하나의 트리형태로 연결되어 있습니다.
// 당신은 이전선중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다.
// 이때 두전력망이 갖는 송전탑의 개수를 최대한 비슷하게 맞추려합니다.
// 송전탑개수를 n, 전선정보 wires 가 매개변수로 주어집니다. 
// 이때 송전탑개수가 비슷하도록 전선중 하나를 끊어서 두전력망으로 나누고 두전력망이 가지고 있는 송전탑 개수차이를 반환하는 solution 함수를 완성하세요

// 제약조건
// * n 은 2이상 100이하 자연수이다
// * wires 는 길이가 n-1인 정수형 2차원 배열입니다
//     - wires 의 각원소는 [v1,v2] 2개의 자연수로 이루어져 있으며, 이는 전력망의 v1번 송전탑과 v2번 송전탑이 전선으로 연결되어 있다는것을 의미합니다
//     - 1 <= v1 <= v2 <= n 입니다

//     - 전력망 네트워크가 하나의 트리형태가 아닌 경우는 입력으로 주어지지 않습니다.

// 입출력의 예
// n wires result
// 9 [[1, 3], [2, 3], [3, 4], [4, 5], [4, 6], [4, 7], [7, 8], [7, 9]] 3
// 4 [[1, 2], [2, 3], [3, 4]] 0
// 7 [[1, 2], [2, 7], [3, 7], [3, 4], [4, 5], [6, 7]] 1

// 프로토타입
// int solution(int n, vector<vector<int>> wires)

// 아시팔 몇개를 풀었는데도 답안보고는 못푸네 ㅋㅋㅋ 대가리 어쩔

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



// 깊이우선 탐색
int dfs(int node, int parent, const vector<vector<int>> & graph)
{
    // parent 를 스킵하기위해서 파라메터로 받음. graph 는 굳이 안받아도 될뻔?
    int cnt = 1;

    // 인접노드에 깊이우선탐색
    for (int child : graph[node])
    {
        if (child != parent) {
            cnt += dfs(child, node, graph);
        }
    }
    return cnt;
}



int solution(int n, vector<vector<int>> wires)
{
    vector<vector<int>> graph(n+1);
    
    // build graph
    // 그래프를 만듬
    for(auto wire : wires)
    {
        int a = wire[0];
        int b = wire[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int min_diff = INT_MAX;
    for (auto &wire : wires)
    {
        int a = wire[0];
        int b = wire[1];

        graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

        int cnt_a = dfs(a, b, graph);
        int cnt_b = n - cnt_a;

        min_diff = min(min_diff, abs(cnt_a - cnt_b));

        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    return min_diff;
}

void main()
{

    int n = 9;
    vector<vector<int>> wires = {
        {1, 3}, 
        {2, 3}, 
        {3, 4}, 
        {4, 5}, 
        {4, 6}, 
        {4, 7}, 
        {7, 8}, 
        {7, 9}
    };
    // expected 
    // 3
    int answer = solution(n, wires);
    cout << "answer:" << answer << endl;

}
