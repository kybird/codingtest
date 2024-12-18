// 든든앤파이터라는 게임에는 피로도 시스템이 있습니다. 피로도는 정수로 표시하며 일정 피로도를 
// 사용해서 던전을 탐험할 수 있는데, 각 던전마다 탐험을 시작하기 위해 필요한 최소 필요 피로도와 
// 던전 탐험을 마쳤을 때 소모되는 소모 피로도가 있습니다. 예를 들어 최소 필요 피로도가 80, 소모 
// 피로도가 20인 던전을 탐험하기 위해서는 유저의 현재 남은 피로도는 80 이상이어야 하고, 던전
// 을 탐험한 후에는 피로도 20이 소모됩니다. 이 게임에는 하루에 한 번만 탐험할 수 있는 던전이 여
// 러 개 있습니다. 한 유저가 오늘 던전을 최대한 많이 탐험하려 합니다. 유저의 현재 피로도 k와 각 
// 던전별 최소 필요 피로도, 소모 피로도가 담긴 2차원 배열 dungeons가 매개변수로 주어질 때 유
// 저가 탐험할 수 있는 최대 던전 수를 반환하는 solution( ) 함수를 완성하세요.
// 제약 조건
// • k는 1 이상 5, 000 이하인 자연수입니다.
// • dungeons의 세로 길이, 즉, 던전 개수는 1 이상 8 이하입니다.
// - dungeons의 가로 길이는 2입니다.
// - dungeons의 각 행은 각 던전의 [최소 필요 피로도, 소모 피로도]입니다.
// - 최소 필요 피로도는 항상 소모 피로도보다 크거나 같습니다.
// - 최소 필요 피로도와 소모 피로도는 1 이상 1, 000 이하인 자연수입니다.
// - 서로 다른 던전의 [최소 필요 피로도, 소모 피로도]가 같을 수 있습니다.


// 입출력의 예
// k dungeons result
// 80 [[80, 20], [50, 40], [30, 10]] 3
// 첫 번째 입출력을 봅시다. 현재 피로도는 80입니다. 만약 첫 번째 → 두 번째 → 세 번째 순서로 던
// 전을 탐험하면 다음과 같이 피로도의 총량을 계산할 수 있습니다.
// • 현재 피로도는 80
// - 첫 번째 던전을 돌기 위한 최소 필요 피로도 80 → 첫 번째 던전을 탐험할 수 있음 
// - 첫 번째 던전의 소모 피로도는 20 → 던전을 탐험한 후 남은 피로도는 60
// • 현재 피로도는 60
// - 두 번째 던전을 돌기 위한 최소 필요 피로도 50 → 두 번째 던전을 탐험할 수 있음 
// - 두 번째 던전의 소모 피로도는 40 → 던전을 탐험한 후 남은 피로도는 20
// • 현재 피로도는 20
// - 세 번째 던전을 돌기 위한 최소 필요 피로도는 30 → 세 번째 던전은 탐험할 수 없음
// 던전 순서를 바꿔서 탐험하면 어떨까요? 만약 첫 번째 → 세 번째 → 두 번째 던전 순서로 탐험한다
// 면 다음과 같이 피로도의 총량을 계산할 수 있습니다.
// • 현재 피로도는 80
// - 첫 번째 던전을 돌기 위한 최소 필요 피로도 80 → 첫 번째 던전을 탐험할 수 있음
// - 첫 번째 던전의 소모 피로도는 20 → 던전을 탐험한 후 남은 피로도는 60
// • 현재 피로도는 60
// - 세 번째 던전을 돌기 위한 최소 필요 피로도 30 → 세 번째 던전을 탐험할 수 있음
// - 세 번재 던전의 소모 피로도는 10 → 던전을 탐험한 후 남은 피로도는 50
// • 현재 피로도는 50
// - 두 번째 던전을 돌기 위한 최소 필요 피로도는 50 → 두 번째 던전을 탐험할 수 있음 
// - 두 번째 던전의 소모 피로도는 40 → 던전을 탐험한 후 남은 피로도는 10

// 이렇게 하니 세 던전을 모두 탐험할 수 있게 되었습니다. 즉, 유저가 탐험할 수 있는 최대 던전 수
// 는 3입니다.

// int solution(int initialPower, vector<vector<int>> dungeons)




// 모든 경로중 최대갯수?
// 다도는건 어짜피 dfs 나 bfs 나 동일함
// 그런데

 // vector<vector<int>> dungeons = {
    //     {80, 20}, 
    //     {50, 40}, 
    //     {30, 10}
    // };
// 순서가없다.

   
// 이런그래프인가.
// 그래프를 만드나.

// 다연결되있는데 만들필요가있나?
// a a b b c c 
// b c a c a b
// c b c a b a

//    a     b     c
//   b c   a c   a b
//  c   b c   a b   a
// 먼가...배웟던 그래프같기는한데
// 루트가없는게 이상하네.
// for 두번돌려도 될거같은데
// 루트가 a,b,c 인 트리 세개를 돌려야하나  

// void dfs(int index);
#include <vector>
#include <iostream>

using namespace std;

// 내머리로 생각나는 답 ㅋㅋ
// int solution(int initialPower, vector<vector<int>> dungeons)
// {
//     // 0 1 2 로 만들수 있는 모든 조합

//     // 0 1 2
//     // 0 2 1
//     // 1 0 2
//     // 1 2 0
//     // 2 0 1
//     // 2 1 0
//     int answer = 0;
//     for (int i = 0; i < dungeons.size(); i++)
//     {
//         for (int j = 0; j < dungeons.size(); j++)
//         {
//             if (i != j)
//             {
//                 for (int k = 0; k < dungeons.size(); k++)
//                 {
//                     if (i!= k && k!= j && i !=k )
//                     {
//                         cout << "possible combination " << i << " " << j << " " << k << endl;

//                         auto first = dungeons[i];
//                         auto second  = dungeons[j];
//                         auto third = dungeons[k];



//                         int currentPower = initialPower;
//                         int passDungeon = 0;
//                         cout << "first[0]:" << first[0] << " second[0]:" << second[0] << " third[0]:" << third[0] << " currentPower:" << currentPower << endl;
//                         if (first[0] <= currentPower)
//                         {
//                             passDungeon++;
//                             currentPower -= first[1];
//                         }
//                         cout << "current power:" << currentPower << endl;
//                         if (second[0] <= currentPower)
//                         {
//                             passDungeon++;
//                             currentPower -= second[1];
//                         }
//                         cout << "current power:" << currentPower << endl;
//                         if (third[0] <= currentPower)
//                         {
//                             passDungeon++;
//                             currentPower -= second[1];
//                         }
//                         cout << "current power:" << currentPower << endl;
//                         answer = max(answer, passDungeon);
//                         cout << "pass dungeon:" << passDungeon << endl;
//                         //cout << "answer:" << answer << endl;
//                     }
//                 }
//             }
//         }
//     }
//     return answer;
// }

// 머리가 굳었어 ㅋㅋ 아니면 내머린 이걸 응용못하는걸까
vector<bool> visited = {
    false,
};
int maxDepth = 0;

void backtracking(int depth, int power, vector<vector<int>> dungeons)
{
    if (maxDepth < depth)
    {
        maxDepth = depth;
    }

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visited[i] == true || dungeons[i][0] > power)
        {
            continue;
        }
        visited[i] = true;
        backtracking(depth +1, power - dungeons[i][1],  dungeons);
        visited[i] = false; // 백트래킹 무효한애는 방문안한걸로 재초기화
    }
}

int solution(int initialPower, vector<vector<int>> dungeons)
{
    backtracking(0, initialPower, dungeons);
    return maxDepth;
}


void main()
{
    int initialPower = 80;
    vector<vector<int>> dungeons = {
        {80, 20}, 
        {50, 40}, 
        {30, 10}
    };
    // unexpected 3
    
    int answer = solution(initialPower, dungeons);
    cout << "answer:" << answer << endl;
}