
class Solution {  
public:  
    int romanToInt(string& s) {  
        unordered_map<char,int>m;  
        m['I']=1;  
        m['V']=5;  
        m['X']=10;  
        m['L']=50;  
        m['C']=100;  
        m['D']=500;  
        m['M']=1000;  
        int res=0;  
        int n=s.size();  
        if(n==0) return 0;  
        for(int i=0;i<n;i++){  
            if(i==n-1||m[s[i]]>=m[s[i+1]]) res+=m[s[i]];  
            else res-=m[s[i]];  
        }  
        return res;  
    }  
    
    string intToRoman(int n) {  
        vector<string>v1={"","I","II","III","IV","V","VI","VII","VIII","IX"};  
        vector<string>v2={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};  
        vector<string>v3={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};  
        vector<string>v4={"","M","MM","MMM"};  
        string res;  
        for(int i=1;i<=4;i++){  
            int bit=n%10;  
            switch(i){  
            case 1:  
                res=v1[bit]+res;  
                n=n/10;  
                break;  
            case 2:  
                res=v2[bit]+res;  
                n=n/10;  
                break;  
            case 3:  
                res=v3[bit]+res;  
                n=n/10;  
                break;  
            case 4:  
                res=v4[bit]+res;  
                n=n/10;  
                break;  
            }  
        }  
        return res;  
          
    }  
};  
