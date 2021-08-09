vector<int> findSingnatureCounts(vector<int>& arr) {
	int n = arr.size();
	vector<bool> visited(n, false);
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			unordered_set<int> curr;
			visited[i] = true;
			curr.insert(i);
			while (!visited[arr[i]-1]) {
				visited[arr[i]-1] = true;
				curr.insert(arr[i]-1);
				i = arr[i] - 1;
			}
			int s = curr.size();
			for (auto num : curr)
				ans[num] = s;
		}
	}
	return ans;
}