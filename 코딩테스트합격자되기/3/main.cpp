// 정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 2개의 수를 뽑아 더
// 해 만들 수 있는 모든 수를 배열에 오름차순으로 담아 반환하는 solution( ) 함수를 완성하세요.
// 제약 조건
// • numbers의 길이는 2 이상 100 이하입니다.
// • numbers의 모든 수는 0 이상 100 이하입니다.
// 입출력의 예
// numbers result
// [2, 1, 3, 4, 1] [2, 3, 4, 5, 6, 7]
// [5, 0, 2, 7] [2, 5, 7, 9, 12]
// 프로토타입
// vector<int> solution(vector<int> numbers)
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers)
{
    // set 는 원래 소팅될건데.. 오름차순 옵션은 못주나?
    // less 반댓말을 뭘까?
    // 큰수로 만들려면 어떻게해?
    set<int, less<int>> sum_set;
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            sum_set.insert(numbers[i] + numbers[j]);
        }
    }

    
    
    vector<int> ret(sum_set.begin(), sum_set.end());

    for (auto num : ret)
    {
        printf("%d ", num);
    }
    return ret;
}

void main()
{
    //vector<int> input = {2,1,3,4,1};
    vector<int> input = {5,0,2,7};

    solution(input);

    // vector<int> result
}