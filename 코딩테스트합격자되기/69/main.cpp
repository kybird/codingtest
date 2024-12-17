// 머쓱이는 RPG 게임을 하고 있습니다. 게임에는 [up], [down], [left], [right] 방향키가 있으며 각 
// 키를 누르면 위, 아래, 왼쪽, 오른쪽으로 1칸씩 이동합니다. 예를 들어 [0, 0]에서 [up]을 누르면 캐
// 릭터는 [0, 1]로, [down]을 누르면 [0, -1]로, [left]를 누르면 [-1, 0]로, [right]를 누르면 [1, 0]로 
// 이동합니다. 머쓱이가 입력한 방향키의 배열 keyinput과 맵의 크기 board가 주어지고, 캐릭터는 
// 항상 [0, 0]에서 시작합니다. 키 입력이 모두 끝난 뒤에 캐릭터의 좌표 [x, y]를 반환하는 solution( ) 

// 함수를 완성해주세요. [0, 0]은 board의 정중앙에 위치합니다. 예를 들어 board의 가로 크기가 
// 9면 캐릭터는 왼쪽으로 최대 [-4, 0], 오른쪽으로 최대 [4, 0]까지 이동할 수 있습니다.
// 제약 조건
// • board는 [가로 크기, 세로 크기] 형태로 주어집니다.
// • board의 가로 크기와 세로 크기는 홀수입니다.
// • board의 크기를 벗어난 방향키 입력은 무시합니다.
// • 0 ≤ keyinput의 길이 ≤ 50
// • 1 ≤ board[0] ≤ 99
// • 1 ≤ board[1] ≤ 99
// • keyinput은 항상 up, down, left, right만 주어집니다.
// 입출력의 예
// keyinput board result
// [“left”, “right”, “up”, “right”, “right”] [11, 11] [2, 1]
// [“down”, “down”, “down”, “down”, “down”] [7, 9] [0, -4]

// vector<int> solution(vector<string> keyinput, vector<int> board)


#include <vector>
#include <string>
#include <iostream>

using namespace std;
vector<int> solution(vector<string> keyinput, vector<int> board)
{
    //현재위치를 나타내는 크기가 2이고 값이 모두 0인 벡터
    vector<int> v(2, 0);

    // 키입력순서대로 캐릭터 이동
    for( string s : keyinput)
    {
        if (s == "up" && v[1] < +board[1] /2) v[1]++;
        else if (s == "down" && v[1] > -board[1] / 2) v[1]--;
        else if (s == "left" && v[0] > -board[0] / 2) v[0]--;
        else if (s == "right" && v[0] < +board[0] / 2) v[0]++;
    }
    return v;
}


void main()
{
    vector<string> keyinput = {
         "left", "right", "up", "right", "right"
    }; 

    // 첫번째 가로크기, 두번째 세로크기
    vector<int> board = {
        11, 11
    };
    //[11, 11] [2, 1]
    // expected
    // [2, 1]

    vector<int> result = solution(keyinput, board);
    cout << "result:" << endl;

    for (auto item : result)
    {
        cout << item << " ";
    } 
    cout << endl; 
}

