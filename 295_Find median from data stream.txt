class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (n % 2 == 0) {
            if (num < mid1) {
                left.push(num);
                right.push(mid2);
            }
            else if (num > mid2) {
                right.push(num);
                left.push(mid1);
                mid1 = mid2;
            }
            else {
                left.push(mid1);
                right.push(mid2);
                mid1 = num;
            }
        }
        else {
            if (num <= mid1) {
                left.push(num);
                mid2 = mid1;
                mid1 = left.top();
                left.pop();
            }
            else {
                right.push(num);
                mid2 = right.top();
                right.pop();
            }
        }
        ++n;
    }
    
    double findMedian() {
        if (n % 2 == 0)
            return (mid1 + mid2) / 2.0;
        else
            return mid1;
    }
    
private:
    int n = 0;
    int mid1 = INT_MIN;
    int mid2 = INT_MAX;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
};








struct Node {
    int val;
    Node* prev; 
    Node* next;
    Node(int val): val(val), prev(NULL), next(NULL) {}
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        median = NULL;
        size = 0;
    }
    
    void addNum(int num) {
        Node* curr = new Node(num);
        if (!median) 
            median = curr;
        else {
            if (median->val <= num) {
                Node* temp = median;
                while (temp->next && temp->next->val < num)
                    temp = temp->next;
                curr->next = temp->next;
                curr->prev = temp;
                temp->next = curr;
                if (curr->next)
                    curr->next->prev = curr;
                if (size % 2 == 0)
                    median = median->next;
            }
            else {
                Node* temp = median;
                while (temp->prev && temp->prev->val > num)
                    temp = temp->prev;
                curr->next = temp;
                curr->prev = temp->prev;
                temp->prev = curr;
                if (curr->prev)
                    curr->prev->next = curr;
                if (size % 2 == 1)
                    median = median->prev;
            }
        }
        size++;
    }
    
    double findMedian() {
        if (size % 2 == 1)
            return median->val;
        else
            return (median->val + median->next->val) / 2.;
    }
    
private:
    Node* median;
    int size;
};








class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = left.size() + right.size();
        if (n == 0)
            left.push(num);
        else if (n % 2 == 1) {
            if (num >= left.top())
                right.push(num);
            else {
                int temp = left.top();
                left.pop();
                left.push(num);
                right.push(temp);
            }
        }
        else {
            if (num <= right.top())
                left.push(num);
            else {
                int temp = right.top();
                right.pop();
                right.push(num);
                left.push(temp);
            }
        }
    }
    
    double findMedian() {
        int n = left.size() + right.size();
        if (n % 2 == 1)
            return left.top();
        else
            return (left.top() + right.top()) / 2.;
    }
    
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
};