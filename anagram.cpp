/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Given an array of strings, return all groups of strings that are anagrams.
 Example     : 'spar', formed from 'rasp'
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
  vector<vector<int> > anagrams(const vector<string> &A);
}obj;

vector<vector<int> > Solution::anagrams(const vector<string> &A)
{
        vector<vector<int> > result;
        map<string, vector<int> > pairs;

        for (int i = 0; i < A.size(); i++)
        {
            string B = A[i];
            sort(B.begin(), B.end());
            pairs[B].push_back(i + 1);
        }

        for(map<string, vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
}

int main()
{
  vector<vector<int> > B;
  string A1[9] = {"cat", "dog", "god", "tca"};
  vector<string> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  B =obj.anagrams(A);
  cout<<"Anagram pairs are: "<<endl;
  for (int i = 1; i < B.size(); i++)
  {
       for (int j = 0; j < B[i].size(); j++)
       cout<<B[i][j]<<" ";
       cout<<endl;
  }

  return 0;
}
