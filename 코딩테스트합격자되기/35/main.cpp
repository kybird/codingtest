// n개의 섬 사이에 다리를 건설하는 비용 costs가 주어질 때 최소 비용으로 모든 섬이 서로 통행하
// 는 solution( ) 함수를 완성하세요. 다리를 여러 번 건너더라도 목표 지점에 도달할 수만 있으면 
// 통행할 수 있다고 봅니다. 예를 들어 A, B 섬 사이에 다리가 있고, B, C 섬 사이에 다리가 있으면 A, C 섬은 서로 통행할 수 있습니다.
// 제약 조건
// • 섬 개수 n은 1 이상 100 이하입니다.
// • costs의 길이는 ((n - 1) * n)/2 이하입니다.
// • 임의의 i에 대해, costs[i][0]과 costs[i][1]에는 다리가 연결되는 두 섬의 번호가 들어 있고, costs[i][2]에는 이 두 섬을 연결하는 다리를 건설할 때 드는 비용입니다.
// • 같은 연결은 두 번 주어지지 않습니다. 또한 순서가 바뀌더라도 같은 연결로 봅니다. 즉 0과 1사이를 연결하는 비용이 주어졌을 때, 1과 0의 비용이 주어지지 않습니다.
// • 모든 섬 사이의 다리 건설 비용이 주어지지 않습니다. 이 경우, 두 섬 사이의 건설이 불가능한 것으로 봅니다.
// • 연결할 수 없는 섬은 주어지지 않습니다.

// 입출력의 예
// n costs result
// 4 [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]] 4

// 입출력 예의 costs를 그림으로 표현하면 다음과 같습니다. 별도의 색
// 으로 표현한 선이 가장 적은 비용으로 모두를 통행하도록 만드는 방법
// 입니다.

// int solution(int n, vector<vector<int>> costs)
// 책진짜 대충썻구나. 문제가 뭔데?
// 최소비용으로 모든 섬이 서로 통행할수 있는 solution 함수를 완성하세요.
// 그래놓고 답은 4랜다.
// 항의하기도 귀찮다 모르는거나 배워가자
// 어떻게 푸는지 전혀모르겠다. ㅋㅋ 모두 방문해야함. 1,2,3,4 
// 갈수 있는곳만 갈수있다. cost 가 있는곳만 갈수 있음.
// 트리로만들어?
// 일단 돌려~?

// 0   3 
// | * |
// 1 - 2
   
// 0 -> 1 은 1
// 0 -> 2 는 2
// 1 -> 2 는 5

//  0  -1-  1
// -2- -5- -1-
//  2  -8-  3   
// pair 를 키로해야하나? 
// 앞뒤가 바껴도 동일해야하는 키인데. +로 할까? 안되는데
// 시팔 모르겠다. 왜이렇게 푸는지 자체를 모르겠다.
// 이해안감
// 이렇게 푸는게 상호배타적 집합이다.
// 웹사이트 찾아본결과
// find 를 한번이라도 실행하면 해당노드에서 루트까지 경로의 모든노드가 경로압축이 됨. 다음검색시 빨라짐
// 할수있는건 뭐냐
// 특정집합과 특정집합을 합치고 각원소들이 어느집합에 속해있는지 알수있음
// 그런데 문제만보고 이알고리즘 떠올리기는 쉽지않을듯.
// 연결성확인? 루트가 동일하면 연결되있다.
// 가장큰집합추적. size 배열을 추가해서 합쳐질떄마다 갱신? 흠 루트가 새로생길떄마다 추가하는게 짜증날듯
// 최소거리구하기라고 하면 정말 당황스럽군.
// 이건 뭐 거의 코드를 외워야하나




#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int size) : parent(size, -1), rank(size, 0) {}
    int find(int node)
    {
        if (parent[node] == -1)
            return node;
        return parent[node] = find(parent[node]);
    }

    void merge(int node1, int node2)
    {
        cout << "merge process " << node1 << "," << node2 << endl;
        int root1 = find(node1);
        int root2 = find(node2);

        cout << node1 << "'s root:" << root1 << endl;
        cout << node2 << "'s root2:" << root2 << endl;

        if (root1 != root2)
        {
            if (rank[root1] > rank[root2]) 
            {
                parent[root2] = root1;
            } 
            else if (rank[root1] < rank[root2])
            {
                parent[root1] = root2;
            }
            else 
            {
                parent[root2] = root1;
                rank[root1]++;
            }
            cout << "modifiy" << endl;
            cout << "parent[" << root1 << "]:" << parent[root1] << endl;
            cout << "parent[" << root2 << "]:" << parent[root2] << endl;
            cout << "rank[" << root1 << "]:" << rank[root1] << endl;
        }
    }
    bool isCycle(int node1, int node2) 
    {
        if (find(node1) == find(node2))
        {
            cout << node1 << "and " << node2 << "is cycle so passing" << endl;
            return true;
        }
        return false;
    }
};
 
int solution(int n, vector<vector<int>> costs)
{
    sort(costs.begin(), costs.end(),
        [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
    cout << "소트후 경로 내용" << endl;
    for (auto item : costs)
    {
        for (auto val : item)
        {
            cout << val << ' ';
        }
        cout << endl;
    }
    


    DisjointSet disjointSet(n);
    int totalCost = 0;

    for (const auto &edge: costs) {
        int cost = edge[2];
        int node1 = edge[0];
        int node2 = edge[1];
        

        if (!disjointSet.isCycle(node1, node2))
        {
            cout << node1 << " 과 " << node2 << " 연결 비용" << cost << endl;
            disjointSet.merge(node1, node2);
            totalCost += cost;
        }
        // 0-> -1    1-> 0  3->
        // rank 1

        
    }
    return totalCost;
}

void main()
{
    int n = 4;
    vector<vector<int>> costs = { 
        {0, 1, 1},
        {0, 2, 2},
        {1, 2, 5},
        {1, 3, 9},
        {2, 3, 10}
    };

    // expected result = 4

    // 모든 경로를 갔는지 확인은 어디서하냐?
    int answer = solution(n, costs);
    cout << "answer:" << answer;
}


