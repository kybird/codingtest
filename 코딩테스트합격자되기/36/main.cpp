// 깊이 우선 탐색으로 모든 그래프의 노드를 순회하는 함수 solution( )을 작성하세요. 시작 노드는 문
// 자형 start로 주어집니다. graph 배열은 [출발 노드, 도착 노드] 쌍들이 들어 있는 배열입니다. 반환값
// 은 그래프의 시작 노드부터 모든 노드를 깊이 우선 탐색으로 탐색한 경로가 순서대로 저장된 배열입
// 니다.
// 제약 조건
// • 노드의 최대 개수는 100개를 넘지 않습니다.
// • 시작 노드부터 시작해서 모든 노드를 방문할 수 있는 경로가 항상 있습니다.
// • 그래프의 각 노드는 대문자 알파벳 문자입니다.
// ※ 해당 문제는 탐색 순서에 따라 정답이 여러 개일 수 있습니다. 
// 입출력의 예
// graph start result
// [[‘A’, ‘B’], [‘B’, ‘C’], [‘C’, ‘D’], [‘D’, ‘E’]] ‘A’ [‘A’, ‘B’, ‘C’, ‘D’, ‘E’]
// [[‘A’, ‘B’], [‘A’, ‘C’], [‘B’, ‘D’], [‘B’, ‘E’], [‘C’, ‘F’], [‘E’, ‘F’]] ‘A’ [‘A’, ‘B’, ‘D’, ‘E’, ‘F’, ‘C’]

// 프로토타입
// C++
// vector<char> solution(vector<pair<char, char>> graph, char start)

// 깊이우선탐색
// 깊이우선탐색을 구현할려면 그래프를 인접리스트로 변환해야한다?
// !! 그래프는 인접리스트로 구현할수 있다 !! 인가

#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_map<char, vector<char>> adjList; // 인접리스트의 형태. 
vector<char> result;
unordered_set<char> visited;

void dfs(char node)
{
    // 현재노드를 방문한 목록과 방문한 경로에 추가
    visited.insert(node); // 자신을 방문한것으로 처리하고
    result.push_back(node); // 방문처리

    // 현재 노드와 인접한노드중, 방문하지 않은 노드에 깊이우선 탐색을 진행
    // 나와 연결된 노드들을 순환.
    for (char neighbor : adjList[node])
    {
        // 연결된 노드들을 방문하지 않았다면. 계속해서 깊이우선탐색
        if (visited.find(neighbor) == visited.end()) 
        {
            dfs(neighbor);
        }
    }
}



vector<char> solution(vector<pair<char, char>> graph, char start)
{
    // 인접리스트 생성
    for (auto &edge : graph) 
    {
        char u = edge.first;
        char v = edge.second;
        adjList[u].push_back(v);
    }

    // 깊이우선 탐색
    dfs(start);
    return result;

}

void main()
{
    vector<pair<char, char>> graph = {
        {'A', 'B'}, 
        {'A', 'C'},
        {'B', 'D'}, 
        {'B', 'E'},
        {'C', 'F'},
        {'E', 'F'},
    };
    //     D
    //     |   
    // A - B - E 
         
    //         |
    //   - C - F
    char start = 'A';
    // 깊이우선탐색 정의
    // A B E F D C
    // 틀렸네
    // dfs(A)
    // dfs(B)
    // dfs(D)
    // dfs(E)
    // dfs(F)
    // dfs(C)
    // 순서대로 접근한다고 생각해야할듯
    // A B D E F C

    // 두번쨰 파라메터
    // vector<pair<char, char>> graph = {
    //     {'A', 'B'}, 
    //     {'B', 'C'},
    //     {'C', 'D'}, 
    //     {'D', 'E'}
    // };
    // char start = 'A';


    vector<char> result = solution(graph, start);

    for(auto chr : result)
    {
        cout << chr << " ";
    }
    cout << endl;
}

