// 정수 배열 lst가 주어집니다. 배열의 중복값을 제거하고 배열 데이터를 내림차순으로 정렬해서 반
// 환하는 solution( ) 함수를 구현하세요.
// 제약 조건
// • lst의 길이는 2 이상 1,000 이하입니다.
// • lst의 원소 값은 -100,000 이상 100,000 이하입니다.
// 입출력의 예
// lst result
// [4, 2, 2, 1, 3, 4] [4, 3, 2, 1]
// [2, 1, 1, 3, 2, 5, 4] [5, 4, 3, 2, 1]
// 프로토타입
// vector<int> solution(vector<int> lst)
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lst)
{
    // sort
    sort(lst.begin(), lst.end(), [](int a, int b)
    {
        return a > b;
    });

    // 중복제거
    auto lastItr = unique(lst.begin(), lst.end());

    lst.erase(lastItr, lst.end());

    return lst;
}

void main()
{

    // vector<int> input = {4,2,2,1,3,4};
    vector<int> input = {2,1,1,3,2,5,4};
    vector<int> answer = solution(input);

    ostringstream oss;
    string sparator = "";
    for( auto item : answer)
    {
        oss << sparator << item;
        sparator = ", ";
    }

    cout << oss.str();
}
