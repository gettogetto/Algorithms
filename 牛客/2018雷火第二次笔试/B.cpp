#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
double x1,yy1,z1,x2,y2,z2,x3,y3,z3;
double x,y;
struct node{
    double x,y;
    double w;
}p[5];
double dis(node A,node B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double area(node A,node B,node C){
    double len1 = dis(A,B),len2 = dis(B,C),len3 = dis(A,C);
    double p = (len1+len2+len3)/2;
    return sqrt(p*(p-len1)*(p-len2)*(p-len3));
}
bool equ(double A,double B){
    if(fabs(A-B)<eps)return true;
    return false;
}
int main(){
    while(cin>>p[0].x>>p[0].y>>p[0].w){
        for(int i=1;i<3;i++)
            cin>>p[i].x>>p[i].y>>p[i].w;
        cin>>p[3].x>>p[3].y;
        for(int i=3;i>=0;i--){
            p[i].x-=p[0].x;
            p[i].y-=p[0].y;
        }
        if(equ(area(p[0],p[1],p[2]),area(p[0],p[1],p[3])+area(p[0],p[2],p[3])+area(p[1],p[2],p[3]))==false){
            cout<<"-1"<<endl;
            continue;
        }
        double B = (p[1].x*p[3].y-p[3].x*p[1].y)/(p[1].x*p[2].y-p[2].x*p[1].y);
        double A;
        if(equ(p[1].x,0)==false)A = (p[3].x-B*p[2].x)/p[1].x;
        else A = (p[3].y-B*p[2].y)/p[1].y;
        printf("%.2f\n",A*p[1].w+B*p[2].w+(1.0-A-B)*p[0].w);
    }
}
