// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
// Example:
//
//
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3
//
//
//  
//


class MovingAverage {
public:
    /** Initialize your data structure here. */
    double sum = 0;
    int max_size;
    queue<int> q;
    
    MovingAverage(int size) {
        max_size = size;
        while(!q.empty()) q.pop();
        sum = 0;
    }
    
    double next(int val) {
        if(q.size()  < max_size){
            sum = sum + val;
            q.push(val);
            return sum * 1.0 / q.size();
        }else{
            sum -= q.front();
            q.pop();
            sum += val;
            q.push(val);
            return sum * 1.0 / q.size();
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
