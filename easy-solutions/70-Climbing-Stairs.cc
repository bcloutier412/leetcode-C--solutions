class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> memo(n + 1);
        return climb_stairs(n, 0, memo);
    }
    int climb_stairs(int n, int curr_steps, std::vector<int>& memo) {
        if (curr_steps == n) {
            return 1;
        } else if (curr_steps > n) {
            return 0;
        } else if (memo[curr_steps]) {
            return memo[curr_steps];
        } else {
            int total_steps = climb_stairs(n, curr_steps + 1, memo) + climb_stairs(n, curr_steps + 2, memo);
            memo[curr_steps] = total_steps;
            return total_steps;
        }
    }
};