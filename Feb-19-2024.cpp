class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1)
            return false;
        if(log2(n)-(floor)(log2(n))==0.0)
            return true;
        else
            return false;
    }
};