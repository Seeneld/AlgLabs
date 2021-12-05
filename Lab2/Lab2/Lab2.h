#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

using namespace std;

void PrintArray(int arr[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << " ";
	}
}

int Search_Binary(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (1)
	{
		mid = (left + right) / 2;
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else
			return mid;
		if (left > right)
			return -1;
	}
}

void QuickSort(int arr[], int SIZE) {
	int i = 0;
	int j = SIZE - 1;
	int mid = arr[SIZE / 2];
	do {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		QuickSort(arr, j + 1);
	}
	if (i < SIZE) {
		QuickSort(&arr[i], SIZE - i);
	}
}

void InsertionSort(int SIZE, int arr[]) {
	for (int k = 1; k < SIZE; k++)
	{
		int temp = arr[k];
		int j = k - 1;
		while (j >= 0 && temp <= arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

bool isSorted(int arr[], int SIZE)
{
	while (--SIZE >= 1)
		if (arr[SIZE] < arr[SIZE - 1]) return false;
	return true;
}

bool isSortedChar(char arr[], int SIZE)
{
	while (--SIZE >= 1)
		if (arr[SIZE] < arr[SIZE - 1]) return false;
	return true;
}

void shuffle(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		swap(arr[i], arr[rand() % SIZE]);
}

void BogoSort(int arr[], int SIZE)
{
	while (!isSorted(arr, SIZE))
		shuffle(arr, SIZE);
}

void CountingSort(char a[], int n)
{
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int* c = new int[max + 1 - min];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i] - min] = c[a[i] - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			a[i] = j;
			c[j - min]--;
			i++;
		}
	}
}

int Random(int min, int max) {
	return min + rand() % (max - min);
}
