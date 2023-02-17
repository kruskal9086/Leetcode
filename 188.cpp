class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k==0) return 0;
        int buy[k];
        int prof[k];
        for(int i=0;i<k;i++){
            buy[i]=INT_MAX;
            prof[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(j==0){
                    buy[j]=min(buy[j],prices[i]);
                    prof[j]=max(prof[j],prices[i]-buy[j]);
                }else{
                   buy[j]=min(buy[j],prices[i]-prof[j-1]);
                    prof[j]=max(prof[j],prices[i]-buy[j]); 
                }
            }
        }
        return prof[k-1];
    }
};