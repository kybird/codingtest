// 1 x 1 크기의 직사각형들로 이루어진 격자 형태의 미로에서 탈출하려고 합니다. 각 칸은 통로 또
// 는 벽으로 구성되어 있으며 벽으로 된 칸은 지나갈 수 없고 통로로 된 칸으로만 이동할 수 있습니
// 다. 통로 중 한 칸에는 미로를 빠져나가는 문이 있는데 이 문은 레버를 당겨서만 열 수 있습니다. 
// 레버 또한 통로 중 한 칸에 있습니다. 따라서 출발 지점에서 먼저 레버가 있는 칸으로 이동해 레버
// 를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 됩니다. 이때 아직 레버를 당기지 않았
// 더라도 출구가 있는 칸을 지나갈 수 있습니다. 미로에서 한 칸을 이동하는 데 1초가 걸린다고 할 
// 때 최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 합니다. 미로를 나타낸 문자열 배열 
// maps가 매개변수로 주어질 때 미로를 탈출하는 데 필요한 최소 시간을 반환하는 solution( ) 함
// 수를 완성하세요. 만약 탈출할 수 없다면 -1을 반환하세요.
// 제약 조건
// • 5 ≤ maps의 길이 ≤ 100
//     - 5 ≤ maps[i]의 길이 ≤ 100
//     - maps[i]는 다음 5개의 문자로 구성
// ■ S : 시작 지점 
// ■ E : 출구
// ■ L : 레버
// ■ O : 통로
// ■ X : 벽

// - 시작 지점과 출구, 레버는 항상 다른 곳에 있으며 1개씩만 있음
// - 출구는 레버가 당겨지지 않아도 지나갈 수 있음 

// - 모든 통로, 출구, 레버, 시작점은 여러 번 지나갈 수 있음
// 입출력의 예
// maps result
// [“SOOOL”, “XXXXO”, “OOOOO”, “OXXXX”, “OOOOE”] 16
// [“LOOXS”, “OOOOX”, “OOOOO”, “OOOOO”, “EOOOO”] -1
// 첫 번째 입출력 예에 주어진 문자열을 그림으로 그리면 다음과 같습니다. 이 미로는 다음과 같이 4
// 번 이동해 레버를 당기고 출구까지 이동하면 총 16초의 시간이 걸리며, 이 시간이 가장 빠른 시간
// 입니다.

// 0  1  2  3  4
// x  x  x  x  5
// 10 9  8  7  6
// 11 x  x  x  x
// 12 13 14 15 16

// 두 번째 입출력 예에 주어진 문자열을 그림으로 그리면 다
// 음과 같습니다. 시작 지점에서 이동할 수 있는 공간이 없어
// 서 탈출할 수 없으므로 -1을 반환합니다.


// int solution(vector<string> maps)

#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Point {
    int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;

bool isWithinRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m;}

// 시작좌표확인
Point findStartPoint(char start, vector<string> &maps)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == start)
            {
                return {i, j, 0};
            }
        }
    }
    return {-1, -1, -1};
}

int bfs(char start, char end, vector<string> &maps)
{
    bool visited[101][101] = {false};
    queue<Point> q;

    q.push(findStartPoint(start, maps)); // 시작노드부터 너비우선탐색 하기
    // 너비우선탐색은 큐로 시작하는가

    while (!q.empty())
    {
        Point current = q.front();
        q.pop();

        // 목적지에 도달했으면 해당 목저지까지의 이동횟수 반환
        if (maps[current.y][current.x] == end) 
        {
            return current.cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = current.y + dy[i];
            int nx = current.x + dx[i];
            if (isWithinRange(ny,nx) && !visited[ny][nx] && maps[ny][nx] != 'X')
            {
                //후보좌표가 미로범위내에있고 방문하지 않았으면 대상에 추가
                q.push({ny,nx, current.cnt + 1});
                visited[ny][nx] = true;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) 
{
    n = maps.size();
    m = maps[0].size();

    int distanceToL = bfs('S', 'L', maps);
    if (distanceToL == -1)
    {
        return -1;
    }

    int distanceToE = bfs('L', 'E', maps);
    return distanceToE == -1 ? -1: distanceToL + distanceToE;
}

void main()
{
    vector<string> maps = {"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"};
    int result = solution(maps);

    cout << result << endl;

}