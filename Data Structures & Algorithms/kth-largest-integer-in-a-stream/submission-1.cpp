class KthLargest {
public:
    int K;
    vector<int> x;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        x=nums;
    }
    
    int add(int val) {
        x.push_back(val);
        sort(x.begin(),x.end());
        return (x[x.size()-K]);
    }
};
