// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    
    priority_queue<int> maxHeap; // contains largest ele from left upto n/2
    priority_queue<int, vector<int>, greater<int>> minHeap; // contains largest ele from right n/2
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxHeap.empty() or maxHeap.top()>=num) maxHeap.push(num);

        else minHeap.push(num);

        if(maxHeap.size()>minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if(maxHeap.size()<minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        
        if(maxHeap.size()==minHeap.size()) return (maxHeap.top()+minHeap.top())/2.0;

        else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
