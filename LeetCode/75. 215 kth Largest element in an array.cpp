// Q:

// Comments

// Initial Instinct

// Solution Code
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            q.push(nums[i]);
        }
        for (int i = 1; i < k; i++)
        {
            q.pop();
        }

        return q.top();
    }
};

// Optimised solution

// FeedBack and more