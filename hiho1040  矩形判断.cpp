/*
描述
给出平面上4条线段，判断这4条线段是否恰好围成一个面积大于0的矩形。

输入
输入第一行是一个整数T(1<=T<=100)，代表测试数据的数量。

每组数据包含4行，每行包含4个整数x1, y1, x2, y2 (0 <= x1, y1, x2, y2 <= 100000)；其中(x1, y1), (x2,y2)代表一条线段的两个端点。

输出
每组数据输出一行YES或者NO，表示输入的4条线段是否恰好围成矩形。

样例输入
3
0 0 0 1
1 0 1 1
0 1 1 1
1 0 0 0
0 1 2 3
1 0 3 2
3 2 2 3
1 0 0 1
0 1 1 0
1 0 2 0
2 0 1 1
1 1 0 1
样例输出
YES
YES
NO
*/
#include<iostream>
#include<vector>
#include<utility>
#include<set>
using namespace std;
typedef pair<int,int> Point;
class Line
{
    public:
    Point p1,p2;

    Point getVec() const{
        return make_pair<int,int>(p2.first-p1.first,p2.second-p1.second);
    }
    int getVecx()const{
        return p2.first-p1.first;
    }
    int getVecy()const{
        return p2.second-p1.second;
    }
};

bool JudgePoint(const vector<Point>& p)
{
    int n=p.size();
    set<Point> s;
    for(int i=0;i<n;i++){
        s.insert(p[i]);
    }
    return s.size()==4;
}
bool JudgeLine(const vector<Line>& line){
    int n=line.size();
    for(int i=1;i<n;i++){
        if(line[0].getVecx()*line[i].getVecx()+
        line[0].getVecy()*line[i].getVecy()==0){
            continue;
        }
        if(line[0].getVecx()*line[i].getVecy()==
        line[0].getVecy()*line[i].getVecx()){
            continue;
        }
        /*if(line[0].getVecx()*line[i].getVecy()==-
        line[0].getVecy()*line[i].getVecx()){
            continue;
        }*/
        return false;
        
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        vector<Point> point;
        vector<Line> line(4);
        for(int i=0;i<4;i++){
            cin>>line[i].p1.first
            >>line[i].p1.second
            >>line[i].p2.first
            >>line[i].p2.second;
            point.push_back(line[i].p1);
            point.push_back(line[i].p2);
        }
        if(!JudgePoint(point)) {
            cout<<"NO"<<endl;
            continue;
        }
        if(!JudgeLine(line)) {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
}
