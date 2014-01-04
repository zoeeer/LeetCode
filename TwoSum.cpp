#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void merge_index(vector<int> &A, vector<int> &Val, int p, int q, int r)
    // A[] contains indice of elements in Val[]
    {
        vector<int> L(A.begin() + p, A.begin() + q + 1);
        vector<int> R(A.begin() + q + 1, A.begin() + r + 1);
        vector<int>::iterator iA = A.begin() + p,
                              iL = L.begin(), iR = R.begin();
        while (iL != L.end() && iR != R.end())
            *iA++ = (Val[*iL] <= Val[*iR]) ? *iL++ : *iR++;
        while (iL != L.end())
            *iA++ = *iL++;
        while (iR != R.end())
            *iA++ = *iR++;
    }

    void mergesort(vector<int> &A, vector<int> &Val, int p, int r)
    {
        if (p < r) {
            int q = (p + r) >> 1;
            mergesort(A, Val, p, q);
            mergesort(A, Val, q+1, r);
            merge_index(A, Val, p, q, r);
        }
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> idx(numbers.size(), 0);
        for (int i = 1; i < numbers.size(); i++)
            idx[i] = i;
        mergesort(idx, numbers, 0, numbers.size() - 1);
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int key = target - numbers[idx[i]];
            while (j > i && numbers[idx[j]] > key)
                j--;
            if (numbers[idx[j]] < key)
                i++;
            else {
                vector<int> ans;
                if (idx[i] < idx[j]) {
                    ans.push_back(idx[i] + 1);
                    ans.push_back(idx[j] + 1);
                }
                else {
                    ans.push_back(idx[j] + 1);
                    ans.push_back(idx[i] + 1);
                }
                return ans;
            }
        }
        return vector<int>();
    }
};
