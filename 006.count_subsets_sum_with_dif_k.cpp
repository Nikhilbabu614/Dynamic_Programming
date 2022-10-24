// count number of partitions that sum and have difference - k
int countPartitions(int n, int d, vector<int> &arr) {	
	int sum = 0;
	for(int x : arr)
        sum += x;
	if(d > sum || (sum + d) % 2 ==1) 
        return 0;
	return countSubsets(arr, n, (sum + d) / 2);
}