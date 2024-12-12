// N개의 마을로 이루어진 나라가 있습니다. 이 나라의 각 마을에는 1부터 N까지의 번호를 하나씩 
// 부여했습니다. 마을은 양방향으로 통행할 수 있는 도로로 연결했는데, 서로 다른 마을로 이동할 때는 이 도로를 지
// 나야 합니다. 도로를 지날 때 걸리는 시간은 도로마다 다릅니다. 1번 마을에 있는 음식점에서 각 마을로 음식 배달
// 을 하려고 합니다. 이때 음식 주문을 받을 수 있는 N개의마을 중 배달 시간이 K 이하인 곳으로만 음식 배달을 제한
// 하려고 합니다. 
// 다음은 N = 5, K = 3인 경우입니다.
// 1번 마을에 있는 음식점은 1, 2, 4, 5 마을까지는(1번 마을에도 음식을 팝니다) 배달 시간이 3 이하이므로 배달할 수 있습니다.
// 하지만 3번 마을은 어디로 가도 배달 시간이 3시간을 넘습니다.
// 따라서 1번 마을에서 배달할 수 있는 마을은 1, 2, 4, 5로 총 4개의 마을입니다. 
// 마을 개수가 N, 각 마을을 연결하는 도로의 정보가 road, 음식 배달이 가능한 시간 K가 매개변수로 주어질 때 음식 
// 주문을 받을 수 있는 마을의 개수를 반환하는 solution( ) 함수를 완성하세요.
// 제약 조건
// • 마을의 개수 N은 1 이상 50 이하의 자연수입니다.
// • road의 길이는 1 이상 2,000 이하입니다.
// • road의 각 원소는 마을을 연결하는 각 도로의 정보를 나타냅니다.
// • road는 길이가 3인 배열이며 순서대로 (a, b, c)를 나타냅니다.
// - a, b(1 ≤ a, b ≤ N, a != b)는 도로가 연결하는 두 마을의 번호이며 c(1 ≤ c ≤ 10,000, c는 자연수)는 도로를 지나는 데 걸리는 시간입니다.
// - 두 마을 a, b를 연결하는 도로는 여러 개가 있을 수 있습니다.
// - 한 도로의 정보가 여러 번 중복해서 주어지지 않습니다.

// • K는 음식 배달이 가능한 시간을 나타내며 1 이상 500,000 이하입니다.
// • 임의의 두 마을 간에 항상 이동 가능한 경로가 있습니다.
// • 1번 마을에 있는 음식점이 K 이하의 시간에 배달할 수 있는 마을 개수를 반환하면 됩니다.
// 입출력의 예
// N road K result
// 5 [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]] 3 4
// 6 [[1, 2, 1], [1, 3, 2], [2, 3, 2], [3, 4, 3], [3, 5, 2], [3, 5, 3], [5, 6, 1]] 4 4
// 첫 번째 입출력 예는 문제에서 설명한 것과 같으므로 넘어가고 두 번째 입출력 예를 설명하겠습니
// 다. 마을과 도로의 모양은 다음 그림과 같으며 1번 마을에서 배달에 4시간 이하가 걸리는 마을은 
// 1, 2, 3, 5로 4개이므로 4를 반환합니다.

// int solution(int N, vector<vector<int>> road, int K)

#include <limits>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> tree;



int solution(int N, vector<vector<int>> road, int K)
{
    vector<vector<pair<int, int>>> graph;
    graph.resize(N + 1);
    vector<int> distances(N + 1, numeric_limits<int>::max());
    vector<bool> visited(N + 1, false);
    distances[1] = 0;

    // 방향이 없으므로 양방향 동일한 가중치
    for (const auto &r : road)
    {
        int a = r[0], b = r[1], cost = r[2];
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    // 출발점을 heap에 추가
    //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    queue<pair<int, int>> heap;
    heap.push({0, 1}); // 1은 거리가 없다로 넣은거구만

    while (!heap.empty())
    {
        // int dist = heap.top().first;
        // int node = heap.top().second;
        
        int dist = heap.front().first;
        int node = heap.front().second;
        heap.pop();
        
        // 이미 방문한 노드는 무시
        if (visited[node])
        {
            cout << "duplication continue";
            continue;
        }
        cout << "current node:" << node << endl;
        visited[node] = true;

        for(const auto &next : graph[node])
        {
            // cout << "neighbor:" << next.first << endl;
            int next_node = next.first;
            int next_dist = next.second;
            int cost = dist + next_dist;
            // cout << "cost:" << cost << endl;
            // 거쳐가는 노드로 가는 경로의 비용이 더 짧으면 최소 비용 갱신
            if (cost < distances[next_node])
            {
                //cout << "found cheaper to node:" << next_node << "cost:" << cost << " original:" << distances[next_node] <<  endl;
                distances[next_node] = cost;
                heap.push({cost, next_node});
                cout << "push next_node:" << next_node << " cost:" << cost <<endl;
            }
        }

    }

    int count = 0;

    // 거리가 k 이하인 장소를 카운트
    for (int i = 1; i <= N; i++)
    {
        if (distances[i] <= K)
        {
            count++;
        }

    }

    return count;
}

void main()
{
    int N = 5;
    vector<vector<int>> road = {
        {1, 2, 1}, 
        {2, 3, 3}, 
        {5, 2, 2}, 
        {1, 4, 2}, 
        {5, 3, 1}, 
        {5, 4, 2}
    };
    int K = 2;
    //expected 4
    int answer = solution(N, road, K);
    cout << "answer:" << answer;

}