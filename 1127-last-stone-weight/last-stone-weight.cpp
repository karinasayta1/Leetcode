class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //solving using max heap / priority queue
        priority_queue<int> pq;

        //insert array elements into priority queue
        for(int x : stones){
            pq.push(x);
        }

        //smash until we get 1 or 0 at the end
        while(pq.size() > 1){
            int x  = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            // if x and y are equal nothing is pushed.
            if(x != y){
                pq.push(x-y);
            }

        }

        return pq.empty() ? 0 : pq.top();
    }
};