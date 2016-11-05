class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        l=[]
        for i in xrange(1,n+1):
            if i%3 ==0 and i % 5 ==0:
                l.append("FizzBuzz")
            elif i%3 == 0 :
                l.append("Fizz")
            elif i % 5 == 0:
                l.append("Buzz")
            else: l.append(str(i));
        return l
