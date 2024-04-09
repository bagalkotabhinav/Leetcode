class MedianFinder {
public:
    priority_queue<int> smaller;
    priority_queue<int,vector<int>,greater<int>> greater;

    MedianFinder() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    
    void addNum(int num) {

        if(smaller.empty() || num<=smaller.top())
            smaller.push(num);
        else
            greater.push(num);

        if(smaller.size()>greater.size()+1){
            greater.push(smaller.top());
            smaller.pop();
        }
        else if(greater.size()>smaller.size()){
            smaller.push(greater.top());
            greater.pop();
        }
    }
    
    double findMedian() {
        if(smaller.size()==greater.size())
            return(smaller.top()+greater.top())/2.0;
        else
            return smaller.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 //maxheap to store all elements less than or equal to median
 //minheap to store all elements greater than median
 //maxheap can have one more element than minheap. top of maxheap assumed to be median
// if single element or element equal to top of maxheap, push into maxheap
//else push to minheap

//if maxheap and minheap size diff more than 1, top of maxheap to minheap, and pop maxheap
//if minheap more than maxheap, top of minheap to maxheap and pop minheap