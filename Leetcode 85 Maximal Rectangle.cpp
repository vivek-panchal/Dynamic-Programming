class Solution
{
    private:
        
		// we can use the logic behind the problem "largest rectangle under histogram to solve this problem"
		//  helper function is function which solved the problem "largest rectangle under histogram to solve this problem" and returns the area
		int helper(vector<int> histo)
		{
			int n = histo.size();
			stack<int> st;
			int max_ans = 0;
			for (int i = 0; i <= n; i++)
			{
				while ((!st.empty()) && (i == n || histo[st.top()] >= histo[i]))
				{
					// height calculation
					int height = histo[st.top()];
					st.pop();
					// width calcalation
					int width;
					if (st.empty())
						width = i;
					else
						width = i - st.top() - 1;
					// max_ans  update
					max_ans = max(max_ans, height * width);
				}
				st.push(i);
			}
			return max_ans;
		}

    public:
		// we can form histograms for every row of the matrix
		// the height of the individual histogram bar keeps increasing if the col values are being 1 repeatedly
		// at any col if a 0 is encountered the height of the bar becomes 0
		// then the problem just becomes find max area in histogram problem
        int maximalRectangle(vector<vector < char>> &matrix)
        {
            int row = matrix.size();
            int col = matrix[0].size();
            int max_ans = 0;
            vector<int> histo(col, 0);
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    if (matrix[r][c] == '1')
                        histo[c]++;
                    else
                        histo[c] = 0;
                }
                int ans = helper(histo);
                max_ans = max(max_ans, ans);
            }
            return max_ans;
        }
};
