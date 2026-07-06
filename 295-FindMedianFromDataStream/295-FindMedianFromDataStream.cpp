// Last updated: 7/7/2026, 2:40:19 AM


class MedianFinder {
public:
priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    MedianFinder() {
         
    }

    void addNum(int num) {

       
       leftMaxHeap.push(num);
       rightMinHeap.push(leftMaxHeap.top());
       leftMaxHeap.pop();

        if (leftMaxHeap.size() < rightMinHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    double findMedian() {
        if (leftMaxHeap.size() == rightMinHeap.size())
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        else
            return leftMaxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */