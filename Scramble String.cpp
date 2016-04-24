    #include<iostream>
    #include<string>
    using namespace std;
    bool isScramble(string s1,string s2){	
		int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2) return false;
        if(s1==s2) return true;
        int count[256]={0};
        for(int i=0;i<n1;i++){
        	count[s1[i]]++;
        	count[s2[i]]--;
		}
		for(int i=0;i<256;i++){
			if(count[i]!=0) return false;
		}
        for(int i=1;i<=n1-1;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(n1-i))&&isScramble( s1.substr(i),s2.substr(0,n1-i) ))
                return true;
        }
        return false;
    }
    int main(){
    	string s1="ccbbcaccbccbbbcca";
    	string s2="ccbbcbbaabcccbccc";
  
    	cout<<isScramble(s1,s2);
		
		return 0;
	}
