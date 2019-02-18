#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <iostream>
using std::cout, std::endl;
using std::pair;
using std::vector;
//idea:
//1 use multimap to sort x value of points
//2 use multiset to maintain heights, when going through x values, if start of build is met ,add height to multiset ,if end ,delete
//3 if height is diff then previous , update

class Solution
{
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> ans;
        int curhei = 0;
        //<x, h> at startpoints or <x -h> at endpoints
        std::multimap<int, int> points;
        std::set<int> pointxs;
        for (auto b : buildings)
        {
            pointxs.insert(b[0]);
            pointxs.insert(b[1]);
            points.insert(pair(b[0], b[2]));
            points.insert(pair(b[1], -b[2]));
        }

        // set instead of multiset was used in first submission which cant deal with the following case:
        //[[0,3,3],[1,5,3],[2,4,3],[3,7,3]]
        //in which houses with the same height align along x axis

        std::multiset<int> egdesH;
        for (auto x : pointxs)
        {
            auto ps = points.equal_range(x);
            for (auto p = ps.first; p != ps.second; p++)
            {
                if (p->second > 0)
                {
                    egdesH.insert(p->second);
                }
                else
                    egdesH.erase(egdesH.find(-p->second));
            }
            if (egdesH.empty())
            {
                curhei = 0;
                ans.push_back(pair(x, 0));
            }
            else if (*egdesH.rbegin() != curhei)
            {
                curhei = *egdesH.rbegin();
                ans.push_back(pair(x, curhei));
            }
        }

        return ans;
    }
};

int main()
{

    vector<vector<int>> input{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};

    //fail case of 1st submission:
    vector<vector<int>> input2{{0, 3, 3}, {1, 5, 3}, {2, 4, 3}, {3, 7, 3}};

    Solution s;
    auto ans = s.getSkyline(input);
    auto ans2 = s.getSkyline(input2);

    for (auto s : ans2)
    {
        cout << s.first << " " << s.second << endl;
    }
    return 0;
}

/*------------------------------------------------------------*/
// faster solution
// using priority queue

// class Solution {
// public:
//     vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
//         vector<pair<int,int>> result;
//         if(buildings.size()==0)
//         {
//             return result;
//         }
//         priority_queue<pair<int,int>> live_bldg;
//         int len=buildings.size();
//         int curr=0,curr_X,curr_H=-1;
//         while(curr<len || !live_bldg.empty() )
//         {
//             curr_X=live_bldg.empty()?buildings[curr][0]:live_bldg.top().second;
//             if(curr>=len || buildings[curr][0]>curr_X)
//             {//first check if the current tallest building will end before the next timing point
//                   // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
//                 while(!live_bldg.empty() && (live_bldg.top().second<=curr_X))
//                 {
//                     live_bldg.pop();
//                 }
//             }
//             else
//             { // if the next new building starts before the top one ends, process the new building in the vector
//                 curr_X=buildings[curr][0];
//                 while(curr<len&&buildings[curr][0]==curr_X) // go through all the new buildings that starts at the same point
//                 {  // just push them in the queue
//                     live_bldg.push(make_pair(buildings[curr][2],buildings[curr][1]));
//                     curr++;
//                 }
//             }
//             curr_H=live_bldg.empty()?0:live_bldg.top().first;
//             if(result.empty() || (result.back().second!=curr_H))
//             {
//                 result.push_back(make_pair(curr_X,curr_H));
//             }
//         }
//         return result;
//     }
// };