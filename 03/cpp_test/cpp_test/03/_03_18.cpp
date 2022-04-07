//
//  _03_18.cpp
//  cpp_test
//
//  Created by delims on 2022/3/18.
//

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;


class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        // write code here
        int n = nums.size();
        int size = n / 8 + 1;
        unsigned char* m = (unsigned char*)malloc(size);
        memset(m, 0xff, size);

        for (int x : nums) {
            if (x > n + 1 || x < 1) continue;
            x -= 1;
            int i = x / 8;
            int j = x % 8;
            if (m[i] & (1 << j)) m[i] &= ~(1 << j);
        }
        int k = -1;
        while (++k < n+1) {
            int i = k / 8;
            int j = k % 8;
            if (m[i] & (1<<j)) return k + 1;
        }
        free(m);
        return 0;
 
    }
};

vector<vector<int> > threeSum(vector<int>& num) {
    vector<vector<int> > res;
    if (num.size() < 3) return res;

    vector<int> item;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        if (num[i] > 0) break;
        if (i > 0 && num[i] == num[i-1]) continue;
        int l = i + 1;
        int r = num.size() - 1;
        while (l < r) {
            int sum = num[i] + num[l] + num[r];
            if (sum == 0) {
                item.push_back(num[i]);
                item.push_back(num[l]);
                item.push_back(num[r]);
                res.push_back(item);
                item.clear();
                while (l < r && num[l] == num[l + 1]) l++;
                while (l < r && num[r] == num[r - 1]) r--;
                l++;
                r--;
            } else if (sum > 0) r--;
            else l++;
        }
    }
    return res;
}

//void _03_18() {
    
//    std::queue<int*> q;
//
//    q.push(nullptr);
//    q.push(nullptr);
//    q.push(nullptr);

//    vector<int> array = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//    threeSum(array);
    
//    printf("%d\n",q.size());
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

int minNumberDisappeared(vector<int>& nums) {
    // write code here
    int n = nums.size();
    int size = n / 8 + 1;
    unsigned char* m = (unsigned char*)malloc(size);
    memset(m, 0xff, size);

    for (int x : nums) {
        if (x > n + 1 || x < 1) continue;
        x -= 1;
        int i = x / 8;
        int j = x % 8;
        if (m[i] & (1 << j)) m[i] &= ~(1 << j);
    }
    int k = -1;
    while (++k < n+1) {
        int i = k / 8;
        int j = k % 8;
        if (m[i] & (1<<j)) {
            
            return k + 1;
        }
    }
    free(m);
    return 0;
}

class A {
private:
    int a;
    int b;
protected:
    int c;
public:
    int d;
};


class B : public A {
public:
    
    void func() {
        c = 120;
        printf("=%d \n",c);
    }
};
