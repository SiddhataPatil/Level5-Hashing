/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Determine if a Sudoku is valid
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  int isValidSudoku(const vector<string> &A);
}obj;

int Solution::isValidSudoku(const vector<string> &A) {
     bool row[9][9];
     bool column[9][9];
     bool box[3][3][9];

    memset(row, false, sizeof(row));
    memset(column, false, sizeof(column));
    memset(box, false, sizeof(box));

        int number;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (A[i][j] > '0' && A[i][j] <='9')
                {
                    number = A[i][j] - '1';

                    if (row[i][number])
                    {
                      return false;
                    }

                    row[i][number] = true;

                    if (column[j][number])
                    {
                      return false;
                    }

                    column[j][number] = true;

                    if (box[i / 3][j / 3][number])
                    {
                      return false;
                    }

                    box[i / 3][j / 3][number] = true;
                }
            }
        }
        return true;
    }

int main()
{
  int result;
  string A1[9] = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
  vector<string> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  result =obj.isValidSudoku(A);
  cout<<"Return 0 / 1 ( 0 for false, 1 for true ) for the given problem: "<<result<<endl;
  return 0;
}
