class MedianFinder {
public:
    priority_queue<int> smaller_half;
    priority_queue<int,vector<int>,greater<int>> larger_half;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smaller_half.push(num);

        larger_half.push(smaller_half.top());
        smaller_half.pop();

        if(larger_half.size()>smaller_half.size()){
            smaller_half.push(larger_half.top());
            larger_half.pop();
        }
        
    }
    
    double findMedian() {
        if(smaller_half.size()>larger_half.size()){
            return smaller_half.top();
        }

        return (smaller_half.top()+larger_half.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */