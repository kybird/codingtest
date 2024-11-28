#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    map<string, int> collisionMap;
    // iterating robot
    for(auto route :  routes)
    {
        int time = 0;
        // printf("new robot\n");
        for(int i = 0; i < route.size()-1; i++)
        {
            int startidx = route[i];
            int endidx = route[i+1];
        
            int startx = points[startidx-1][0];
            int starty = points[startidx-1][1];
            int endx = points[endidx-1][0];
            int endy = points[endidx-1][1];
            
            int current_x = startx;
            int current_y = starty;
            // 충돌조건
            // 같은 횟수에 같은 위치일경우
            // 이전에 x,y 를 저장할방법이 없다.
            // 키는 횟수와 x,y 여야한다
            //printf("start(%d %d, %d) end(%d %d %d)\n", startidx, startx, starty, endidx, endx, endy);
            
            
            string key ="";
            if (i == 0)
            {
                key = std::to_string(time) + "s_" + std::to_string(current_x) + "_" + std::to_string(current_y);
                collisionMap[key]++;
            }
            // printf("key:%s\n", key.c_str());
            

            // 이동 x축부터 
            while (current_x != endx) 
            {
                if (current_x < endx) {
                    current_x++;
                } else {
                    current_x--;
                }
                time++;
                key = std::to_string(time) + "s_" + std::to_string(current_x) + "_" + std::to_string(current_y);
                collisionMap[key]++;
                // printf("key:%s\n", key.c_str());
            } 
            while (current_y != endy)
            {
                if (current_y < endy) {
                    current_y++;
                } else {
                    current_y--;
                }
                
                time++;
                key = std::to_string(time) + "s_" + std::to_string(current_x) + "_" + std::to_string(current_y);
                collisionMap[key]++;
                // printf("key:%s\n", key.c_str());
            }
        }
        
    }
    for(const auto &pair : collisionMap)
    {
        if (pair.second > 1) {
            answer++;
        }
        //printf("first:%s second:%d\n", pair.first.c_str(), pair.second);
    }
    
    
    
    return answer;
}

int main()
{

    // [[1, 1], [1, 2], [1, 3]], [[2, 1], [2, 3]]
    // [[1, 1], [2, 2], [3, 3]], [[1, 2, 1], [3, 2, 1]]

    // vector<vector<int>> points  = { {1,1},{2,2},{3,3}};
    // vector<vector<int>> routes  = { {1,2,1},{3,2,1}};


    // vector<vector<int>> points  = { {3,2},{6,4},{4,7},{1,4}};
    // vector<vector<int>> routes  = { {4,2},{1,3},{2,4}};

    vector<vector<int>> points  = { {2,2},{2,3},{2,7},{6,6},{5,2}};
    vector<vector<int>> routes  = { {2,3,4,5},{1,3,4,5}}; 
    // expect 0

    int answer = solution(points, routes);

    printf("answer:%d", answer);
}

