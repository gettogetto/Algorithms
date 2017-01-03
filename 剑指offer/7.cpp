/*Implement the following operations of a queue using stacks.*/
class Queue {
	stack<int> s1,s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!s2.empty()){
            s2.pop();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty()&&s2.empty();
    }
    
};

/*Implement Stack using Queues*/
class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
