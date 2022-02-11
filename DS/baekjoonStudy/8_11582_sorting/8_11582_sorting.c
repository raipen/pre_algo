//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int chicken[1048577];
//int tmp[1048577];
//int n, r;
//int cnt = 0;
//
//void merge(int start, int mid, int end);
//void merge_sort(int start, int end);
//
//int main()
//{
//	int i, j;
//
//	scanf("%d", &n);
//	cnt = n;
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &chicken[i]);
//	}
//
//	scanf("%d", &r);
//
//	merge_sort(0, n - 1);
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", chicken[i]);
//	}
//
//	return 0;
//}
//
//void merge(int start, int mid, int end) {
//	int i = start;
//	int j = mid + 1;
//	int k = 0;
//
//	if (end - start > n / r) return;
//	while (i <= mid && j <= end) {
//		if (chicken[i] <= chicken[j]) {
//			tmp[k] = chicken[i];
//			i++;
//		}
//		else {
//			tmp[k] = chicken[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i <= mid) tmp[k++] = chicken[i++];
//	while (j <= end) tmp[k++] = chicken[j++];
//
//	for (int i = start; i <= end; i++) {
//		chicken[i] = tmp[i-start];
//	}
//}
//
//void merge_sort(int start, int end) {
//	if (start == end) return;
//	int mid = (start + end) / 2;
//	merge_sort(start, mid);
//	merge_sort(mid + 1, end);
//	merge(start, mid, end);
//}
