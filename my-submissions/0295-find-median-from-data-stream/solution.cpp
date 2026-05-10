class MedianFinder {
public:

    // max heap
    priority_queue<int> leftHeap;

    // min heap
    priority_queue<int, vector<int>, greater<int>> rightHeap;

    MedianFinder() {
        
    }

    void addNum(int num) {

        // Step 1: push into max heap
        leftHeap.push(num);

        // Step 2: balance order property
        rightHeap.push(leftHeap.top());
        leftHeap.pop();

        // Step 3: maintain size property
        if (rightHeap.size() > leftHeap.size()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }

    double findMedian() {

        if (leftHeap.size() > rightHeap.size()) {
            return leftHeap.top();
        }

        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
