/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
*/
class Solution {
public:
    string convertToBase7(int num) {
      int x = abs(num); string res;
      do{
          res = to_string(x%7)+res; 
        }while(x/=7);
      return num>=0? res : "-"+res;
    }
};
