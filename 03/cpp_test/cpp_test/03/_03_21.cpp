//
//  _03_21.cpp
//  cpp_test
//
//  Created by delims on 2022/3/21.
//

#include "_03_21.hpp"
#include <vector>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    for (int x : input) {
        if (res.empty()) res.push_back(x);
        else {
            res.push_back(x);
            
            int i = (int)res.size() - 1;
            if (res[i-1] > x) {
                while (--i >= 0) {
                    if (res[i] > x) res[i + 1] = res[i];
                    else break;
                }
                res[i+1] = x;
            }
        }
        if (res.size() > k) res.pop_back();
    }
    return res;
}

void _03_21() {
    
    vector<int> input({4,5,1,6,2,7,3,8});
    
    
    for (int x : GetLeastNumbers_Solution(input, 4)) printf("%d ",x);
    
    
//    GetLeastNumbers_Solution(input, 4);
    
    
}
