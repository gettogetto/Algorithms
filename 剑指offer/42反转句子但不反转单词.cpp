//¡°student a am I¡±->¡°I am a student¡±¡£
class Solution {
public:
    string ReverseSentence(string str) {
    	int i=0;
        reverse(str.begin(),str.end());
        int start=0,end=1;
        while(i<str.size()){
            if(str[i]!=' '&&i!=str.size()-1) i++;
            else{
                end=(i==str.size()-1?str.size():i);
                reverse(str.begin()+start,str.begin()+end);
                start=end+1;
                i++;
            }
        }
        return str;
    }
    
};
