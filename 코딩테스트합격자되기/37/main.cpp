// 너비 우선 탐색으로 모든 노드를 순회하는 함수 solution( )을 작성하세요. 시작 노드는 정수형 
// start로 주어집니다. graph 배열은 [출발 노드, 도착 노드] 쌍이 들어 있는 배열입니다. 반환값은 
// 그래프의 시작 노드부터 모든 노드를 너비 우선 탐색한 경로가 순서대로 저장된 배열입니다.
// 제약 조건
// • 노드의 최대 개수는 100개를 넘지 않습니다.
// • 시작 노드부터 시작해서 모든 노드를 방문할 수 있는 경로가 항상 있습니다.
// • 그래프의 각 노드는 숫자입니다.
// ※ 해당 문제는 탐색 순서에 따라 정답이 여러 개일 수 있습니다. 

// 입출력의 예
// graph start result
// [(1, 2), (1, 3), (2, 4), (2, 5), (3, 6), (3, 7), (4, 8), (5, 8), (6, 9), (7, 9)] 1 [1, 2, 3, 4, 5, 6, 7, 8, 9]
// [(0, 1), (1, 2), (2, 3), (3, 4), (4, 5), (5, 0)] 1 [1, 2, 3, 4, 5, 0]

// vector<int> solution(vector<pair<int, int>> graph, int start)

// 너비우선은 시작점과 연결된놈먼저 검색하는것으로 알고있는데
// 어떻게 구현하는지는 모르겠다
// 이거 외워야되는거냐...
// 거의 외워야겠는데..
// 까먹으면 생각안날텐데.환장


#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

// 그래프는 다이렇게 표현할수 있는걸까?
unordered_map<int, vector<int>> adjList; 
vector<int> result;

// bfs 는 뭐의 준말이냐.
// breadth first search. 모르는 단어구만

void bfs(int start) {
    unordered_set<int> visited;
    queue<int> q;

    // 시작노드 큐에 삽입
    q.push(start);

    visited.insert(start); // 방문기록
    result.push_back(start); // 결과기록

    while(!q.empty()) // 큐가 비어있지 않으면
    {
        int node = q.front(); // 맨앞에거부터 값취득
        q.pop();            // 해당 값 엔트리삭제

        // 인접노드 순환
        for (int neighbor : adjList[node]) // 연결된 모든 노드 순환
        {
            // 아직 방문하지 않았다면
            if (visited.find(neighbor) == visited.end())
            {
                q.push(neighbor);      // 큐에 넣음
                visited.insert(neighbor); // 방문기록
                result.push_back(neighbor); // 결과기록
            }
            // node 와 연관된 모든 노드 순환완료.
            // 모든 노드는 순환하면서 큐에 다 넣음
            // 골떄리는군. 결국 모든 노드를 순환하긴 하겠네.
        }
    }
}

vector<int> solution(vector<pair<int, int>> graph, int start)
{
    // 인접리스트 생성
    for(auto &edge : graph)
    {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
    }

    bfs(start);

    return result;
}

void main()
{
    // 인풋
    // vector<pair<int, int>> graph = {
    //     {1, 2}, 
    //     {1, 3}, 
    //     {2, 4},
    //     {2, 5},
    //     {3, 6},
    //     {3, 7},
    //     {4, 8},
    //     {5, 8},
    //     {6, 9},
    //     {7, 9}
    // };
    // int start =  1;
    // expected
    // [1, 2, 3, 4, 5, 6, 7, 8, 9]
    vector<pair<int, int>> graph = {
        {0, 1},
        {1, 2},
        {2, 3}, 
        {3, 4}, 
        {4, 5}, 
        {5, 0}
    };
    int start = 1; 
    // expected
    // [1, 2, 3, 4, 5, 0]

    solution(graph, start);
    for(auto item : result)
    {
        cout << item << " ";
    }

    cout << endl;

}



