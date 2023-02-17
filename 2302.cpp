class Solution {
public:
    
    long long countSubarrays(vector<int>& nu, long long k) {
        int start = 0 ;
        long long ans = 0 ,count = 0;
        for(int end = 0 ; end < nu.size() ;end++){
            ans += nu[end];
            while(ans*(end - start +1 ) >=k){
                ans -= nu[start];
                start++;      
            }
            count+= (end - start +1);
        }
        return count;
    }
    
};