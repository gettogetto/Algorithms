/*
牛牛和 15 个朋友来玩打土豪分田地的游戏，牛牛决定让你来分田地，地主的田地可以看成是一个矩形，每个位置有一个价值。分割田地的方法是横竖各切三刀，分成 16 份，作为领导干部，牛牛总是会选择其中总价值最小的一份田地， 作为牛牛最好的朋友，你希望牛牛取得的田地的价值和尽可能大，你知道这个值最大可以是多少吗？ 
输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 75），表示田地的大小，接下来的 n 行，每行包含 m 个 0-9 之间的数字，表示每块位置的价值。


输出描述:
输出一行表示牛牛所能取得的最大的价值。

输入例子:
4 4
3332
3233
3332
2323

输出例子:
2
*/
#include<bits/stdc++.h>
 
using namespace std;
 
int subValue(vector<vector<int>>& vecValue, size_t x1, size_t y1, size_t x2, size_t y2) {
    return vecValue[x2][y2] - vecValue[x2][y1] - vecValue[x1][y2] + vecValue[x1][y1];
}
 
bool isMinimal(vector<vector<int>>& vecValue, int valToComp) {
    size_t row = vecValue.size();
    size_t col = vecValue[0].size();
    for (size_t c1 = 1; c1 < col - 3; ++c1) {
        for (size_t c2 = c1 + 1; c2 < col - 2; ++c2) {
            for (size_t c3 = c2 + 1; c3 < col - 1; ++c3) {
                int cutTimes = 0;
                size_t lastRow = 0;
                for (size_t r = 1; r < row; ++r) {
                    int s1 = subValue(vecValue, lastRow, 0, r, c1);
                    int s2 = subValue(vecValue, lastRow, c1, r, c2);
                    int s3 = subValue(vecValue, lastRow, c2, r, c3);
                    int s4 = subValue(vecValue, lastRow, c3, r, col - 1);
                    if (valToComp <= min(min(s1, s2), min(s3, s4))) {
                        ++cutTimes;
                        lastRow = r;
                    }
                }
                if (cutTimes >= 4) {
                    return true;
                }
            }
        }
    }
    return false;
}
 
int main() {
    size_t row, col;
    cin >> row >> col;
    vector<vector<int>> vecValue(row + 1, vector<int>(col + 1, 0));
    for (size_t i = 1; i <= row; ++i) {
        string str;
        cin >> str;
        for (size_t j = 1; j <= col; ++j) {
            vecValue[i][j] = str[j - 1] - '0';
            vecValue[i][j] += vecValue[i - 1][j] + vecValue[i][j - 1] - vecValue[i - 1][j - 1];
        }
    }
 
    int left = 0, right = vecValue[row][col];
    int ret = 0;
    while (left <= right) {
        int valToComp = left + right >> 1;
        if (isMinimal(vecValue, valToComp)) {
            ret = valToComp;
            left = valToComp + 1;
        }
        else {
            right = valToComp - 1;
        }
    }
    cout << ret << endl;
    return 0;
}
