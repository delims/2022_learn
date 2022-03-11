//
//  _03_09.cpp
//  cpp_test
//
//  Created by delims on 2022/3/9.
//

#include "_03_09.hpp"
#include <list>
#include <deque>
#include <vector>

using namespace std;


void moveAtoB(int &a, int &b) {
//    printf("a = %d \n",a);
    if (b == 0) {
        b = a & 0xff;
        a >>= 16;
    } else {
        b += (a & 0xff) << 16;
        a >>= 16;
    }
//    printf("b = %d \n",b);

}

//[[23,147,139,66,116,39,75,217,5,50,137,65,256,158,218,226,71,144,95,19,4,9,41,86,52,74,57,92,196,41,14,177],[19,54,41,89,69,197,139,218,256,216,151,35,128,58,128,197,76,96,66,142,91,9,150,4,67,145,96,184,231,52,198,221],

vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
    for (int i = 0; i < n; i ++) { //row
        for (int j = 0;j < n; j ++) { // column
            moveAtoB(mat[i][j], mat[j][n-1-i]);
        }
    }
    return mat;
}

void print_transform(vector<vector<int>> &mat) {
    for (int i =0; i < mat.size(); i ++) {
        for (int j = 0; j <mat.size(); j ++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

extern void _03_09(const char *) {
    
//    std::list<int> a;
    
//    std::deque<int> dak;
//    dak.push_back(1);
    
//    printf("%d \n",dak.size());
    
//    vector<vector<int>> mat;
//    vector<int> item;
    
//    item.push_back(1);
//    item.push_back(2);
//    item.push_back(3);
//    mat.push_back(item);
//    item.clear();
//
//    item.push_back(4);
//    item.push_back(5);
//    item.push_back(6);
//    mat.push_back(item);
//    item.clear();
//
//    item.push_back(7);
//    item.push_back(8);
//    item.push_back(9);
//    mat.push_back(item);
//    item.clear();

//    print_transform(mat);
    
//    transformImage(mat, mat.size());
    
//    print_transform(transformImage(mat, 3));
    

    printf("\n");
    
}
