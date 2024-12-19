// 2 이상의 n이 입력되었을 때 n번째 피보나치 수를 1234567로 나눈 나머지를 반환하는 solution( ) 
// 함수를 완성하세요.
// 제약 조건
// •  n은 2 이상 100,000 이하인 자연수입니다.
// 입출력의 예
// n result
// 3 2
// 5 5
// 피보나치 수는 0번째부터 0, 1, 1, 2, 3, 5, ... 와 같이 이어집니다.

// 프로토타입
// C++
// int solution(int n)

// (a + b) % m = ((a % m) + (b % m)) % m
// 위식이 이해가 가지 않는다.
// 증명은 이해가 가기는 하지만...

// a = k*m + r; (r = a%m)
// b = q*m + s; (s = b%m)





#include <vector>
#include <iostream>

using namespace std;
vector<int> fib = {0, 1};
int solution(int n)
{
    
    for (int i = 2; i <= n; i++)
    {
        fib.push_back((fib[i - 1] + fib[i - 2]) % 1234567);
    }
    return fib[n];

}

void main()
{
    int n = 12345678;
    int answer = solution(n);

    cout << "answer:" << answer << endl;

    // for (int i = 0; i < fib.size(); i++)
    // {
    //     cout << fib[i] << " ";
    // }
    // cout << endl;
}

