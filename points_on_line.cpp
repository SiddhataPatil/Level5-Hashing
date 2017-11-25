/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 Example     : Sample Input :(1, 1) and (2, 2) Sample Output :2
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
  int maxPoints(vector<int> &A, vector<int> &B)  ;
}obj;
struct Line {
    int x0, y0, x1, y1;
};

bool isLie(const Line& line, int px, int py) {
    int64_t lx = line.x1 - line.x0;
    int64_t ly = line.y1 - line.y0;
    if(lx == 0) return line.x0 == px;
    if(ly == 0) return line.y0 == py;
    int64_t dx = (px - line.x0) * ly;
    int64_t dy = (py - line.y0) * lx;
    return dx == dy;
}

int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    int length = A.size();
    if(length <= 1) return length;
    int result = 0;
    int count = 0;

    for(int i = 0; i < length; ++i)
    {
        for(int j = i+1; j < length; ++j)
        {
           Line line = { A[i], B[i], A[j], B[j] };

            for(int k = 0; k < length; ++k)
            {
                if(isLie(line, A[k], B[k]))
                {
                    ++count;
                }
            }
            result = max(result, count);
        }
    }
    return result;
}

int main()
{
int A1[2]={1,1};
int B1[2]={2,2};
vector<int> A (A1, A1+sizeof(A1)/sizeof(A1[0]));
vector<int> B (B1, B1+sizeof(B1)/sizeof(B1[0]));
int result;
result = obj.maxPoints(A, B) ;
cout<<"Given input:"<<endl;
cout<<"A = {1,1} "<<endl;
cout<<"B = {2,2} "<<endl;
cout<<"Maximum number of points lying on the same straight line = "<<result<<endl;
return 0;
}
