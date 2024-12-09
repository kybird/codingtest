// 벨만-포드 알고리즘을 구현한 solution( ) 함수를 구현하세요. 그래프의 각 데이터는 그래프의 정
// 보입니다. 첫 번째 데이터는 0번 노드 기준으로 연결된 노드 정보, 두 번째 데이터는 1번 노드 기준
// 으로 연결된 노드 정보입니다. 노드 정보의 구성은 (노드, 가중치)와 같습니다. source는 시작 노
// 드입니다. 최단 거리를 담은 distance 배열을 반환하면 됩니다. 만약 음의 가중치 순회가 있다면 
// [-1]을 반환하세요. 음의 가중치 순회란 순환하면 할수록 가중치의 합이 적어지는 순회를 말합니
// 다.
// 제약 조건
// • 노드의 최대 개수는 100개입니다. 
// • 각 간선의 가중치는 -100 이상 100 이하입니다.
// 입출력의 예
// num_vertices
// edges
// source
// result
// 5
// [[0, 1, 4], [0, 2, 3], [0, 4, -6], [1, 3, 5], [2, 1, 2], [3, 0, 7], [3, 2, 4],[4, 2, 2]]
// 0 
// [0, 2, -4, 3, -6]
// 4
// [[0, 1, 5], [0, 2, -1], [1, 2, 2], [2, 3,-2], [3, 0, 2], [3, 1, 6]]
// 0 
// [-1]

// 예를 들어 입력에 있는 그래프는 다음과 같습니다.
// 두 번째 그래프의 경우 음의 가중치 순회가 존재하므로, [-1]이 반환된 것을 알 수 있습니다.
// 프로토타입
// C++
// vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source)

// 이제 나도 좀 안다
// 노드의 갯수는 100개이므로 배열로 표현할시 100 * 100 의 공간이 필요
// 모든 공간을 inf 로 처리하고 -> inf = 먼리밋의 멀쓰던데 모르겠음. 나같으면 -1 에 unsigned 캐스팅할듯
// 그리고 각 간선간정보를 넣어주고.
// 하나씩 돌려? 그건아니였어.. 또 까먹엇어. => 아직이해를 못한거지 ㅋ
// 노트가져왓으니 그려봐라 알고리즘 그대로 그려보자

// 시작노드에서 각노드까지 가능한 모든 경로로 접근해보기
// 접근할때마다 비용이 적게드는걸 찾으면 갱신한다
// 라는거 같음.
// 여기서 납득되지않는건
// 시작노드에서 각노드까지 가능한 모든경로로 접근하는 방법이 생소함

#include <vector>
#include <tuple>
#include <iostream>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source)
{
    vector<vector<pair<int, int>>> graph(num_vertices);

    for (auto &edge : edges)
    {
        int from, to, weight;
        tie(from, to, weight) = edge;
        graph[from].emplace_back(to, weight);
    }
    // 인접리스트 생성

    vector<int> distance(num_vertices, INF);
    distance[source] = 0;
    // 모든비용을 최대값으로. 시작점만 0으로.. 왜!!?

    // 벨만 포드 알고리즘
    // 정점의 개수 -1 만큼 최소비용을 갱신 왜?? 난 모르겠어
    for (int i = 0; i < num_vertices - 1; ++i)
    {
        for (int u = 0; u < num_vertices; ++u) // 여기부터가 모든 간선을 한번 돌아보는것임. i는 아무역활도 안함 그냥 횟수만. 
        {
            for (const auto &[v, weight] : graph[u])
            {
                cout << "i:" << i << " u:" << u << " v:" << v << " weight:" << weight << endl;
                
                if (distance[u] + weight < distance[v])
                {
                    cout << "distance[" << u << "] + " << weight << " : " << distance[u] + weight << " is smaller than distance[" << v << "]" << endl;
                    distance[v] = distance[u] + weight;
                    
                }
            }
        }
    }

    // 최단경로 갱신 동작 한번더수행
    // 갱신되는것이있다면 음의 순환이 있는것!

    for (int u = 0; u < num_vertices; u++)
    {
        for (const auto &[v, weight] : graph[u])
        {
            if (distance[u] + weight < distance[v])
            {
                return vector<int>(1,-1);
            }
        }
    }

    return distance;
}

void main()
{
    int num_vertices = 5;
    vector<tuple<int, int, int>> edges= {
        {0, 1, 4},
        {0, 2, 3},
        {0, 4, -6},
        {1, 3, 5},
        {2, 1, 2},
        {3, 0, 7},
        {3, 2, 4},
        {4, 2, 2}
    };
    int source = 0;
    // expected
    // 0, 2, 4, -4 , 3, -6

    // int num_vertices = 4;
    // vector<tuple<int, int, int>> edge = {
    //     {0, 1, 5},
    //     {0, 2, -1},
    //     {1, 2, 2},
    //     {2, 3, -2},
    //     {3, 0, 2},
    //     {3, 1, 6}
    // };
    // int source = 0;
    // expected
    // -1
    vector<int> result = solution(num_vertices, edges, source);
    for (auto item : result)
    {
        cout << item << " ";
    }
    cout << endl;

}
