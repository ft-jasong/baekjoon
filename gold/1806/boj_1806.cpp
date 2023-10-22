#include <iostream>

using namespace std;

int nums[100000];

int main(void) {
    int sumGoal;
    int size;
    int minLen;
    int curSum;
    int start;
    int end;

    cin >> size >> sumGoal;
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    minLen = size + 1;
    start = 0;
    end = -1;
    curSum = 0;
    while (end < size) {
        while (true) {
            if (end >= size)
                break ;
            end++;
            curSum += nums[end];
            if (curSum >= sumGoal)
                break ;
        }
        if (curSum < sumGoal)
            break ;
        while (curSum - nums[start] >= sumGoal) {
            curSum -= nums[start];
            start++;
        }
        if (minLen > end - start + 1)
            minLen = end - start + 1;
        curSum -= nums[start];
        start++;
    }
    if (minLen == size + 1)
        cout << "0\n";
    else
        cout << minLen << '\n';
    return (0);
}
