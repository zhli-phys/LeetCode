vector<int> countSubarrays(vector<int> arr) {
	stack<int> sk;
	int n = arr.size();
	vector<int> ans(n, 1);
	sk.push(0);
	for (int i = 1; i < n; ++i) {
		while(!sk.empty() && arr[i] >= arr[sk.top()]) 
			sk.pop();
		if (sk.empty())
			ans[i] += i;
		else
			ans[i] += (i - sk.top() - 1);
		sk.push(i);
	}
	
	while (!sk.empty())
		sk.pop();
	sk.push(n-1);
	for (int i = n-2; i >= 0; --i) {
		while(!sk.empty() && arr[i] >= arr[sk.top()])
			sk.pop();
		if (sk.empty())
			ans[i] += (n - 1 - i);
		else
			ans[i] += (sk.top() - i - 1);
		sk.push(i);
	}
	return ans;
}