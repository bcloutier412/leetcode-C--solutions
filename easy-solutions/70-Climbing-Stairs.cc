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

/**
 * SOLUTION DESCRIPTION:
 * The prompt asked to compute the total number of ways to get to the top of a staircase if the user were to take either 1 step or 2 steps.
 * First what came to mind was a tree where each node is a decision of 1 step or 2 steps. To create a tree I would use recursion.
 * The recursive function would continue to execute until it hits a base case of the user is at the top of the staircase or the user has
 * has went past the top of the stair case. In the branch case where the user gets to the top we could return a 1 since it is 1 competed path
 * that is found. If the user ends up past the top of the staircase then it is an invalid path so it would return 0. Originally this was a 
 * Brute Force solution since it would check redundant branches.
 * 
 * OPTIMIZATION:
 * One way that I optimized my solution was to use a cache (memo) that saved already solved nodes so that it could imediately return the value.
 * The length of the cache was n + 1 because thats the highest value for a node. 
 */