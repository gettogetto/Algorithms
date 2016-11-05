/*
method:
Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
subarray after step 1: [[7,0], [7,1]]
subarray after step 2: [[7,0], [6,1], [7,1]]
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),[](pair<int,int> p1,pair<int,int> p2){return p1.first>p2.first||(p1.first==p2.first)&&p1.second<p2.second;});
        vector<pair<int,int>> res;
        for(auto person:people){
            res.insert(res.begin()+person.second,person);
        }
        return res;
    }
};

//python
class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        L = sorted(people, key=lambda x: (-x[0], x[1]))
        for p in L:
            res.insert(p[1],p)
        return res
