#include <vector>
class Solution {
public:
    int climbStairs(int n) {
        if(n < 1) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int ways[(size_t) n];
        ways[0] = 1;
        ways[1] = 2;
        for(int i = 2; i<n; i++){
            std::cout << i;
            ways[i] = ways[i -1] + ways[i - 2];
        } 
        return ways[n-1];
    }
};