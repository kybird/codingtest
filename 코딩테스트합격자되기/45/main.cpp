// 건설 회사의 설계사인 죠르디는 고객사로부터 자동차 경주로 건설에 필요한 견적을 의뢰받았습니
// 다. 제공된 경주로 설계 도면에 따르면 경주로 부지의 크기는 N × N이며 각 격자의 크기는 1 × 1
// 입니다. 설계 도면상 격자의 칸은 0 또는 1로 채워져 있으며, 0은 칸이 비어 있음을 1은 해당 칸이 
// 벽으로 채워져 있음을 나타냅니다. 경주로의 출발점은 (0, 0)이며, 도착점은 (N - 1, N - 1)입니다. 
// 죠르디는 출발점인 (0, 0)에서 출발한 자동차가 도착점인 (N - 1, N - 1)까지 무사히 도달할 수 있
// 게 중간에 끊기지 않는 경주로를 건설해야 합니다. 
// 경주로는 상, 하, 좌, 우로 인접한 두 빈칸을 연결해 건설할 수 있으며 벽이 있는 칸에는 경주로를 
// 건설할 수 없습니다. 이때 인접한 두 빈칸을 상하 또는 좌우로 연결한 경주로를 직선 도로라고 합
// 니다. 또한 두 직선 도로가 서로 직각으로 만나는 지점을 코너라고 부릅니다. 건설 비용을 계산해
// 보니 직선 도로 하나를 만들 때는 100원이 필요하고, 코너 하나를 만들 때는 500원이 추가로 듭
// 니다. 

// 죠르디는 견적서 작성을 위해 경주로를 건설하는 데 필요한 최소 비
// 용을 계산해야 합니다. 다음은 직선 도로 6개와 코너 4개로 구성된 
// 임의의 경주로를 그림으로 표현한 것입니다. 건설 비용은 6 × 100
// + 4 × 500 = 2600원입니다. 

// 다른 예도 봅시다. 다음은 직선 도로 4개와 코너 1개로 구성된 경주
// 로를 그림으로 표현한 것입니다. 건설 비용은 4 × 100 + 1 × 500 = 900원입니다.
// 2차원 배열 도면 board가 주어질 때 경주로를 건설하는 데 필요한 
// 최소 비용을 반환하는 solution( ) 함수를 완성하세요.

// 제약 조건
// • board는 2차원 정사각 배열로 크기는 3 이상 25 이하입니다.
// • board 배열의 각 원소의 값은 0 또는 1입니다.
// - 도면의 가장 왼쪽 상단 좌표는 (0, 0)이며, 가장 우측 하단 좌표는 (N - 1, N - 1)입니다.
// - 원소의 값 0은 칸이 비어 있어 도로 연결이 가능함을, 1은 칸이 벽으로 채워져 있어 도로 연결이 불가능함을 나타냅니다.
// • board는 항상 출발점에서 도착점까지 경주로를 건설할 수 있는 형태로 주어집니다.
// • 출발점과 도착점 칸의 원소의 값은 항상 0으로 주어집니다.
// 입출력의 예
// board result
// [[0, 0, 0], [0, 0, 0], [0, 0, 0]] 900	
// [[0, 0, 0, 0, 0, 0, 0, 1], 
// [0, 0, 0, 0, 0, 0, 0, 0], 
// [0, 0, 0, 0, 0, 1, 0, 0], 
// [0, 0, 0, 0, 1, 0, 0, 0], 
// [0, 0, 0, 1, 0, 0, 0, 1], 
// [0, 0, 1, 0, 0, 0, 1, 0], 
// [0, 1, 0, 0, 0, 1, 0, 0], 
// [1, 0, 0, 0, 0, 0, 0, 0]] 3800
// [[0, 0, 1, 0], 
// [0, 0, 0, 0], 
// [0, 1, 0, 1], 
// [1, 0, 0, 0]] 2100
	
// [[0, 0, 0, 0, 0, 0], 
// [0, 1, 1, 1, 1, 0], 
// [0, 0, 1, 0, 0, 0], 
// [1, 0, 0, 1, 0, 1], 
// [0, 1, 0, 0, 0, 1], 
// [0, 0, 0, 0, 0, 0]]
// 3200
// 문제의 이해를 조금 더 잘하기 위해 두 번째 입출력 예도 그림으로 보겠습니다. 다음과 같이 경주
// 로를 건설하면 직선 도로 18개, 코너 4개로 총 3800원이 듭니다.

// 네 번째 입출력 예도 봅시다. 네 번째 입출력 예는 경로 1과 경로 2의 최소 비용 중 경로 2의 최소 
// 비용이 더 많습니다. 경로 1은 직선 도로 12개, 코너 4개로 총 3,200원, 
// 경로 2는 직선 도로 10개, 코너 5개로 총 3,500원입니다. 

// int solution(vector<vector<int>> board)

// ㅋㅋ 흠 뭔말인지는 알겟지만 이문제를 이렇게 풀생각을 할수있을거 같지는 않음

#include <vector>
#include <iostream>
#include <queue>
#include <limits>

using namespace std;

const int dx[] = { 0, 0,-1, 1};
const int dy[] = {-1, 1, 0, 0};
const int STRAIGHT_COST = 100;
const int CORNER_COST = 600;
const int MAX_SIZE = 26;
const int INF = numeric_limits<int>::max();

struct Path
{
    int y;
    int x;
    int direction;
};

bool isValid(int y, int x, int size)
{
    return y >= 0 && y < size && x >= 0 && x < size;
}

int solution(vector<vector<int>> board)
{
    int boardSize = static_cast<int>(board.size());
    int dist[MAX_SIZE][MAX_SIZE][4];
    
    memset(dist, -1, sizeof(dist));
    queue<Path> q;

    q.push({0,0,1});
    q.push({0,0,3});

    dist[0][0][1] = 0;
    dist[0][0][3] = 0;

    while(!q.empty())
    {
        auto [y, x, dir] = q.front();
        q.pop();

        int lastCost = dist[y][x][dir];
        for (int i = 0 ; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!isValid(ny, nx, boardSize) || board[ny][nx])
            {
                continue;
            }

            int newCost = lastCost + (i == dir ? STRAIGHT_COST : CORNER_COST);

            if (dist[ny][nx][i] == -1 || dist[ny][nx][i] > newCost)
            {
                dist[ny][nx][i] = newCost;
                q.push({ny, nx, i});
            }
        }
    }

    int answer = INF;

    for (int i = 0; i <4; i++)
    {
        if (dist[boardSize - 1][boardSize - 1][i] != -1)
        {
            answer = min(answer, dist[boardSize - 1][boardSize -1][i]);
        }
    }

    return answer == INF ? -1: answer;

}

void main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0, 0}, 
        {0, 1, 1, 1, 1, 0}, 
        {0, 0, 1, 0, 0, 0}, 
        {1, 0, 0, 1, 0, 1}, 
        {0, 1, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0}
    };

    int answer = solution(board);

    cout << "answer:" << answer;
}