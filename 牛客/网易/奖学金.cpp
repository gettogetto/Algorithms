#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n,r,avg;
    while(cin>>n>>r>>avg){
        map<int,vector<long> >m;
        long sumneed=avg*n;
        for(int i=0;i<n;i++){
            long scorehaved,onescoretime;
            cin>>scorehaved>>onescoretime;
            sumneed-=scorehaved;
            m[onescoretime].push_back(scorehaved);
        }
 
        long time=0;
        bool flag=1;
        //while(1){
             
            for(auto it=m.begin();it!=m.end()&&flag;it++){
                if(sumneed<=0) break;
                vector<long> tmp=it->second;
                for(int i=0;i<tmp.size();i++){
               
                    if(r-tmp[i]>=sumneed){
                       // tmp[i]+=sumneed;
                        time+=it->first*sumneed;
                        flag=0;
                        sumneed=0;
                        break;
                    }else{
                         
                        time+=it->first*(r-tmp[i]);
                        sumneed-=(r-tmp[i]);
                        //tmp[i]=r;
                    }
                    /*while(tmp[i]<r){
                        if(sumneed<=0){flag=0;break;}
                        time+=it->first;
                        tmp[i]++;
                        sumneed--;
                    } */
                }
            }
        //}
        cout<<time<<endl;
    }
    return 0;
     
}


