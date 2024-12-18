// 레스토랑을 운영하는 스카피는 레스토랑 내부가 너무 낡아 친구들과 함께 직접 레스토랑을 리모델
// 링하기로 했습니다. 레스토랑은 스노우타운이라는 매우 추운 지역에 있어서 리모델링을 하는 중에 
// 외벽 상태를 점검할 필요가 있습니다. 
// 레스토랑의 구조는 완전히 동그란 모양이고 외벽의 총 둘레는 n미터이며 외벽의 몇몇 지점은 추위
// 가 심하면 손상될 수도 있는 취약한 지점들이 있습니다. 스카피는 외벽의 취약 지점들이 손상되지 
// 않았는지 친구들을 보내서 점검하기로 했습니다. 다만 빠른 공사 진행을 위해 점검 시간을 1시간
// 만 하기로 했습니다. 친구들이 1시간 동안 이동할 수 있는 거리는 제각각이므로 최소한의 친구들
// 을 시켜 취약 지점을 점검하고 나머지 친구들은 리모델링을 하려고 합니다. 
// 편의상 레스토랑의 정북 방향 지점을 0으로 하여 취약 지점의 위치는 정북 방향 지점으로부터 시
// 계 방향으로 떨어진 거리로 나타냅니다. 친구들은 출발 지점부터 시계 혹은 반시계 방향으로 외벽
// 을 따라서만 이동합니다. 외벽의 길이 n, 취약 지점의 위치가 담긴 배열 weak, 각 친구가 1시간 
// 동안 이동할 수 있는 거리가 담긴 배열 dist가 주어질 때 취약 지점을 점검하기 위해 보낼 친구 수
// 의 최솟값을 반환하는 solution( ) 함수를 작성하세요.


// 제약 조건
// • n은 1 이상 200 이하인 자연수입니다.
// • weak의 길이는 1 이상 15 이하입니다.
// - 서로 다른 두 취약점의 위치가 같은 경우는 주어지지 않습니다.
// - 취약 지점의 위치는 오름차순으로 정렬되어 있습니다.
// - weak의 원소는 0 이상 n - 1 이하인 정수입니다.
// • dist의 길이는 1 이상 8 이하입니다.
// - dist의 원소는 1 이상 100 이하인 자연수입니다.
// • 친구들을 모두 투입해도 취약 지점을 전부 점검할 수 없는 때는 -1을 반환하세요.
// 입출력의 예
// n weak dist result
// 12 [1, 5, 6, 10] [1, 2, 3, 4] 2
// 12 [1, 3, 4, 9, 10] [3, 5, 7] 1
// 첫 번째 입출력 예를 봅시다. 그림으로 레스토랑을 나타내면 외벽과 취약 지점은 이렇게 생각해볼 
// 수 있습니다. 

// 친구들을 투입하는 여러 예 중 가장 효율적인 방법을 생각해본 것입니다.
// • 4m를 이동할 수 있는 친구를 10m 지점에서 출발하도록 
// 합니다. 친구는 시계 방향으로 돌아 1m 위치에 있는 지점
// 에서 외벽 점검을 마칩니다.
// • 2m를 이동할 수 있는 친구를 4m 지점에서 출발하도록 합
// 니다. 친구는 시계 방향으로 돌아 6m 위치에 있는 지점에서 
// 외벽 점검을 마칩니다.
// 이 방법 외에도 여러 방법이 있지만 2명보다 적은 친구를 투입하는 방법은 없습니다. 따라서 친구
// 를 최소 2명 투입해야 합니다. 
// 두 번째 입출력 예도 살펴봅시다. 이 경우 7m를 이동할 수 있는 
// 친구가 4m 지점에서 출발해 반시계 방향으로 점검하면 모든 취
// 약 지점을 점검할 수 있습니다. 따라서 친구를 1명 투입하면 됩
// 니다. 

// 프로토타입
// C++
// int solution(int n, vector<int> weak, vector<int> dist)
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

// param 외벽의 길이 n, 취약 지점의 위치가 담긴 배열 weak, 각 친구가 1시간 동안 이동할 수 있는 거리가 담긴 배열 dist
// result 보내야하는 총 친구수
// 모두보내도 해결불가할경우 -1

// int solution(int n, vector<int> weak, vector<int> dist) {
//     int weakSize = weak.size();
//     int answer = INT_MAX;

//     // 원형 외벽을 선형으로 변환 (취약점 복사)
//     for (int i = 0; i < weakSize; ++i) {
//         weak.push_back(weak[i] + n);
//     }

//     // 친구들이 이동할 수 있는 거리 내림차순 정렬
//     // sort(dist.begin(), dist.end(), greater<int>());

//     // 시작점 설정 (원형 외벽이므로 모든 취약점에서 시작 가능)
//     for (int start = 0; start < weakSize; ++start) { // 가능한 시작점을 모두 진행. 많이 비직관적이다.

//         // 친구들을 배치하는 모든 순열 탐색
//         do {
//             int friendsUsed = 1;  // 투입한 친구 수
//             int coveredDistance = weak[start] + dist[0];  // 첫 번째 친구가 점검 가능한 최대 거리
//             // 취약점 점검
//             for (int i = start; i < start + weakSize; ++i) {
//                 if (weak[i] > coveredDistance) {
//                     // 새로운 친구 투입
//                     ++friendsUsed;
//                     if (friendsUsed > dist.size()) {
//                         break;  // 친구가 부족한 경우
//                     }
//                     coveredDistance = weak[i] + dist[friendsUsed - 1];
//                 }
//             }

//             // 최소 친구 수 갱신 (모든 취약점이 커버된 경우만)
//             answer = min(answer, friendsUsed);
//         } while (next_permutation(dist.begin(), dist.end())); // next_permutation 이 핵심이네 요넘이 핵심..가능한 모든수열을 만듬
//         // 가능한 친구 배치순서를 모두 진행해봄.
//     }

//     // 모든 취약점을 점검할 수 없는 경우
//     return (answer == INT_MAX) ? -1 : answer;
// }

// permutation 이란것을 알았으니 나라면 어떻게 할까.
// 직접풀어밨는데... 수긍은 잘안간다 ㅋㅋ

int solution(int n, vector<int> weak, vector<int> dist) 
{
    // 완전 탐색.
    int weakSize = weak.size();
    int answer = INT_MAX;
    // 일단 원형이니 두배로 선형으로 만드는것은 필수
    for (int i = 0; i < weakSize; i++)
    {
        weak.push_back(weak[i] + n);
    }

    // 취약점 순환
    // 시작점은 최초의 크기로.
    for (int start = 0; start < weakSize; start++) 
    {
        do
        {
            int friendUsed = 1;
            int coverDistance = weak[start] + dist[0]; // 시작점에서 부터  첫번쨰 친구의 기여도
            cout << "coverDistance:" << coverDistance << endl;
            // 이러면 모든 가능한 친구의 배치가 dist 에 입력될것임
            // 시작점...검사. 이전 커버리지가 다음커버리지를 덮을떄는 스킵 
            // 못덮을떄는 다음사람 추가인건가.
            for (int i = start; i < start + weakSize; i++)
            {   
                cout << "weak[" << i << "]:" << weak[i] << endl;
                if (weak[i] > coverDistance) 
                {
                    friendUsed++;
                    if (friendUsed > dist.size()) break;
                    coverDistance = weak[i] + dist[friendUsed - 1];
                    cout << "friend:" << friendUsed << " coverDistance:" << coverDistance << endl;
                }
            }

            answer = min(answer, friendUsed);
        } while (next_permutation(dist.begin(), dist.end()));
        // next_permutation 은 어떻게 상태를 유지할까 궁금하다.
    }

    return answer > dist.size() ? -1 : answer;
}

void main()
{
    // cout << solution(12, {1, 5, 6, 10}, {1, 2, 3, 4}) << endl;  // 기대 출력: 2
    // cout << solution(12, {1, 3, 4, 9, 10}, {3, 5, 7}) << endl;  // 기대 출력: 1
    cout << solution(12, {1, 4, 8}, {2, 2, 2}) << endl;         // 기대 출력: -1\n\n    return 0;\n}
}
