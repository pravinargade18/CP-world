class StockSpanner {
public:
    stack<pair<int,int>>s;
    
   StockSpanner() {
       
   }
   
   int next(int price) {
       
       int count = 1;
       while(s.size()>0 && price >= s.top().first){
           count += s.top().second;
           s.pop();
       }
       s.push({price,count});
       return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
