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

    /** Initialize your data structure here. */
    int sum = 0;
    Queue<Integer> q;
    int max_size = 0;
    
    public MovingAverage(int size) {
        max_size = size;
        q = new LinkedList<Integer>();
        sum = 0;
    }
    
    public double next(int val) {
        sum = sum + val;
        q.offer(val);
        if(q.size() > max_size) {
            sum -= q.poll();
        }
        return sum * 1.0 / q.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
