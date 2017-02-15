/*
ţţ�� 15 �������������������ص���Ϸ��ţţ��������������أ���������ؿ��Կ�����һ�����Σ�ÿ��λ����һ����ֵ���ָ���صķ����Ǻ��������������ֳ� 16 �ݣ���Ϊ�쵼�ɲ���ţţ���ǻ�ѡ�������ܼ�ֵ��С��һ����أ� ��Ϊţţ��õ����ѣ���ϣ��ţţȡ�õ���صļ�ֵ�;����ܴ���֪�����ֵ�������Ƕ����� 
��������:
ÿ��������� 1 ������������ÿ�����������ĵ�һ�а����������� n �� m��1 <= n, m <= 75������ʾ��صĴ�С���������� n �У�ÿ�а��� m �� 0-9 ֮������֣���ʾÿ��λ�õļ�ֵ��


�������:
���һ�б�ʾţţ����ȡ�õ����ļ�ֵ��

��������:
4 4
3332
3233
3332
2323

�������:
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
