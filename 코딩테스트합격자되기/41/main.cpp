// ROR 게임은 두 팀으로 나누어서 진행하며 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 그
// 러므로 각 팀은 상대 팀 진영에 최대한 빨리 도착해야 게임을 유리하게 이끌 수 있습니다. 지금부
// 터 당신은 어느 한 팀의 팀원이 되어 게임을 진행하려고 합니다. 다음은 5 × 5 크기의 맵에 당신의 
// 캐릭터가 (1, 1) 위치에 있고 상대 팀의 진영은 (5, 5) 위치에 있는 예를 보여줍니다.


// 위 그림에서 검은색은 벽이고, 흰색은 길입니다. 캐릭터가 움직일 때는 동, 서, 남, 북 방향으로 한 
// 칸씩 이동하며 맵을 벗어날 수 없습니다. 다음은 현재 상황에서 캐릭터가 상대 팀 진영으로 가는 
// 2가지 방법을 보여줍니다. 그림에서 보듯 첫 번째 방법이 빠르게 상대 팀 진영에 도착하는 방법입
// 니다.
// • 11개의 칸을 지나 상대 팀 진영에 도착(왼쪽)
// • 15개의 칸을 지나 상대 팀 진영에 도착(오른쪽)

// 11칸 이동 
// 15칸 이동
// 만약 이렇게 벽이 세워져 있다면 캐릭터는 상대 팀 진영에 도착할 수 없을 겁니다.


// 게임 맵이 maps로 주어질 때 우리 팀 캐릭터가 상대 팀 진영에 도착하기 위해 지나가야 하는 길의 
// 최소 개수를 반환하는 solution( ) 함수를 완성하세요. 만약 상대 팀 진영에 도착할 수 없다면 -1
// 을 반환하세요.
// 제약 조건
// •  maps는 n × m 크기의 게임 맵의 상태가 들어 있는 2차원 배열입니다. 
// - n과 m은 각각 1 이상 100 이하의 자연수입니다.
// - n과 m은 서로 같거나 다를 수 있습니다.
// - n과 m이 모두 1이면 입력으로 주어지지 않습니다.
// • maps는 0과 1로 이루어져 있습니다.
// - 0은 벽이 있는 자리입니다.
// - 1은 벽이 없는 자리입니다.
// • 처음에 캐릭터는 (1, 1) 위치에 있고, 상대 팀 진영은 (n, m) 위치에 있습니다.
// 입출력의 예
// maps answer
// [[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]] 11
// [[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 0], [0, 0, 0, 0, 1]] -1
// int solution(vector<vector<int>> maps)

// 어렵다. 최소값을 찾는거니 너비우선 탐색을 해야한다고 한다... A 에서 B 까지 가는 최소로 가는 길을 찾아라가아니라
// 그길의 최소값을 찾아라이다.
// 너비우선은 큐를 사용한다
// 구현은 생각안남 ㅋ
// 일단 베껴보자
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int check[MAX_SIZE][MAX_SIZE];

struct Point 
{
    int y,x;

    Point(int y, int x) : y(y), x(x) 
    {
    }
    bool isValid(int width, int height) const 
    {
        return y >= 0 && y < height && x >= 0 && x < width;
    }

    Point move(int i) const 
    {
        return Point(y + dy[i], x + dx[i]);
    }
    bool canMoveTo(const vector<vector<int>> &maps) const
    {
        return maps[y][x] == 1 && check[y][x] == 0;
    }
};

queue<Point> q; // BFS 를 위한 큐

int solution(vector<vector<int>> maps)
{
    int width = maps[0].size(), height = maps.size();

    q.push({0,0});
    check[0][0] = 1;

    // 너비우선탐색
    while(!q.empty())
    {
        Point current = q.front();
        q.pop();

        // 현재 좌표 기준으로 상하좌우를 확인
        for (int i = 0; i < 4; i++)
        {
            Point next = current.move(i);
            if (next.isValid(width, height) && next.canMoveTo(maps))
            {
                check[next.y][next.x] = check[current.y][current.x] + 1;
                q.push({next.y, next.x});
            }
        }
    }

    int destinationX = width - 1, destinationY = height - 1;
    if (check[destinationY][destinationX] == 0) 
    {
        return -1;
    }

    return check[destinationY][destinationX];
}

void main()
{
    vector<vector<int>> maps = {
        {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}
    };

    int answer = solution(maps);

    cout << "answer:" << answer << endl;
}



