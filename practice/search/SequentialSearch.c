/*顺序查找方法的时间复杂度是O(n),n越大，查找所要花费的时间就越多！*/
int Sequential_search (int *a, int n, int key)
{
	int i;
	for (i = 0; i < n; ++i)
		if (a[i] == key)
			return i;
	return 0;
}

int Sequential_search2 (int *a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while (a[i]	!= key)
		--i;
	return i;
}
/*有序表查找法*/
int Binary_Search (int *a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;/*改为mid = low + (high - low) * (key - a[low]) / (a[high] - a[low])插值查找实现*/
		if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
		else 
			return mid;
	}
	return 0;
}

