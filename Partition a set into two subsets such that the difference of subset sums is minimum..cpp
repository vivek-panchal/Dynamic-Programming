int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;

      for (int i = 0; i < n; i++) {
        totSum += arr[i];
      }
      vector <bool> prev(totSum+1, false);
      prev[0] = true;
      if (arr[0] <= totSum)
        prev[arr[0]] = true;
// subset sum = k wala logic
      for (int ind = 1; ind < n; ind++) {
        vector < bool > cur( totSum+1, false);
        cur[0] = true;
        for (int target = 1; target <= totSum; target++) {
          bool notTaken = prev[target];

          bool taken = false;
          if (arr[ind] <= target)
            taken = prev[target - arr[ind]];

          cur[target] = notTaken || taken;
        }
        prev = cur;
      }
// find mini mun difference 
      int mini = 1e9;
      for (int i = 0; i <= totSum; i++) {
        if (prev[i] == true) {
          int diff = abs(i - (totSum - i));
          mini = min(mini, diff);
        }
      }
      return mini;
}
