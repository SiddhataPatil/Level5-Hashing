/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Minimum window string 
 Example     : S = "ADOBECODEBANC" T = "ABC" Minimum window is "BANC"
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
  string minWindow(string S, string T) ;
}obj;

string Solution::minWindow(string S, string T)
{
    vector<int> A(128,0);

    for(auto check : T)
    {
        A[check]++;
    }
    int length=T.size();
    int start=0;
    int end=0;
    int maximum=INT_MAX;
    int current=0;

    while(end < S.size())
    {
        if(A[S[end++]]-- > 0)
        length--;
        while(length==0){
         if(end-start < maximum)
         maximum=end-(current=start);
         if(A[S[start++]]++==0)
            length++;
        }

    }
    if(maximum==INT_MAX)
    return "";
    else
    return S.substr(current,maximum);
}

int main()
{
  string S ="ADOBECODEBANC";
  string T ="ABC";
  string result;
  result =obj.minWindow( S, T);
  cout<<"Given input"<<endl;
  cout<<" string S = ADOBECODEBANC "<<endl;
  cout<<" string T = ABC "<<endl;
  cout<<"Minimum window is "<<result<<endl;
  return 0;
}
