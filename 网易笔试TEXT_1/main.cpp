// 网易笔试TEXT_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


int Find_Max_Crossing_Subarray(int arr[], int low, int mid, int high)
{
	const int infinite = -9999;
	int left_sum = infinite;
	int right_sum = infinite;

	int max_left = -1, max_right = -1;

	int sum = 0; //from mid to left;
	for (int i = mid; i >= low; i--) {
		sum += arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;  //from mid to right
	for (int j = mid + 1; j <= high; j++) {
		sum += arr[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	return (left_sum + right_sum);
}

int Find_Maximum_Subarray(int arr[], int low, int high)
{
	if (high == low) //only one element;
		return arr[low];
	else {
		int mid = (low + high) / 2;
		int leftSum = Find_Maximum_Subarray(arr, low, mid);
		int rightSum = Find_Maximum_Subarray(arr, mid + 1, high);
		int crossSum = Find_Max_Crossing_Subarray(arr, low, mid, high);

		if (leftSum > rightSum&&leftSum > crossSum) {
			return leftSum;
		}
		else if (rightSum > leftSum&&rightSum > crossSum) {
			return rightSum;
		}
		else {
			return crossSum;
		}
	}
}