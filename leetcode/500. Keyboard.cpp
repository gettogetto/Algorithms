class Solution {
public:
    bool isok(string str,string r1,string r2,string r3){
        if(str.empty()) return true;
        string s;
        str[0]=toupper(str[0]);
        if(r1.find_first_of(str[0])!=string::npos) s=r1;
        if(r2.find_first_of(str[0])!=string::npos) s=r2;
        if(r3.find_first_of(str[0])!=string::npos) s=r3;
        for(auto c:str){
            c=toupper(c);
            if(s.find_first_of(c)==string::npos) return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        string r1="QWERTYUIOP";
        string r2="ASDFGHJKL";
        string r3="ZXCVBNM";
        vector<string> res;
        for(auto str:words){
            if(isok(str,r1,r2,r3)) res.push_back(str);
        }
        return res;
        
    }
};
