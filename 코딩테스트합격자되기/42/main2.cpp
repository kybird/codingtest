// 상호베타집합으로 해결

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int parent[20];

int findParent(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionNodes(int node1, int node2)
{
    int root1 = findParent(node1);
    int root2 = findParent(node2);
    if (root1 != root2)
    {
        parent[root2] = root1;
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    // 자신을 부모로 초기화

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (computers[i][j])
            {
                unionNodes(i,j); // 연결된 컴퓨터를 그룹화
            }
        }
    }

    unordered_map<int, bool> networkFound;
    for (int i = 0 ; i < n; i++)
    {
        int root = findParent(i); // 각노드의 루트 찾기
        if (!networkFound[root])  // 새로운 네트워크 발견
        {
            answer++;
            networkFound[root] = true;
        }
    }

    return answer;
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
