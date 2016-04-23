    #include<iostream>
    #include<string>
    using namespace std;
    bool isVowel(char ch);
	string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(left<right&&!isVowel(s[left])) left++;
            
            while(left<right&&!isVowel(s[right])) right--;
            
            swap(s[left++],s[right--]);
        }
        return s;
    }
    bool isVowel(char ch){
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            return true;
        else return false;
    }
    int main(){
    	
    	string str;
    	while(cin>>str){
    		cout<<reverseVowels(str)<<endl;
		}
		return 0;
	}
