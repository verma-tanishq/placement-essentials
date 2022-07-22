class Solution
{
  public:
  vector<int> singleNumber(vector<int> nums){
    vector<int>ans;
    int n = nums.size();
    int XOR = nums[0];
    for(int i=1; i<n; i++){
        XOR =XOR ^ nums[i];
    }
    int right_bit = XOR & ~(XOR-1);
    int x,y;
    x=y= 0;
    for(int i=0; i<n; i++){
        if(nums[i]&right_bit){
            x=x^nums[i];
        }
        else{
            y=y^nums[i];
        }
    }
    ans.push_back(x);
    ans.push_back(y);
    sort(ans.begin(), ans.end());
    return ans;
  }
};

/*
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. */
