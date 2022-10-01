// Q:

// Comments

// Initial Instinct

// Solution Code
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = n - 1;
        int r = 0;
        while (r < m and matrix[r][0] <= target)
        {
            r++;
        }
        if (r == 0)
            return false;
        r--;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (matrix[r][m] == target)
            {
                return true;
            }
            else if (matrix[r][m] > target)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return false;
    }
};

// Optimised solution
class Solution
{
public
    boolean searchMatrix(int[][] matrix, int target)
    {

        int rows = matrix.length;
        int cols = matrix[0].length;

        int targetRow = -1;
        int low = 0;
        int high = rows - 1;
        // Binary search for finding the row
        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            if (matrix[mid][0] > target)
            {
                high = mid - 1;
            }
            else if (matrix[mid][cols - 1] < target)
            {
                low = mid + 1;
            }
            else
            {
                targetRow = mid;
                break;
            }
        }

        if (targetRow == -1)
        {
            return false;
        }
        low = 0;
        high = cols - 1;
        // Binary search for finding the col value
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[targetRow][mid] == target)
            {
                return true;
            }
            if (matrix[targetRow][mid] < target)
            {
                low = mid + 1;
            }
            else if (matrix[targetRow][mid] > target)
            {
                high = mid - 1;
            }
        }
        return false;
    }

}

// FeedBack and more