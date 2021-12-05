#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "Lab2.h"
#include <ctime>
#include <cstdio>
#include <chrono>

using namespace std;
using nanoseconds = chrono::duration<long long, nano>;


int main()
{
	setlocale(LC_ALL, "ru");

	const int SIZE = 10;
	int array[SIZE];
	int key = 0;
	int target = 0;
	char arrChar[SIZE];
	int Choice = 0;



	cout << "Choose method of sort (Type a number) \n\n";
	cout << "\t1 - Quick Sort\n";
	cout << "\t2 - Insertion Sort\n";
	cout << "\t3 - Bogo Sort\n";
	cout << "\t4 - Counting Sort\n\n";
	cin >> Choice;

	cout << "\tArray:\n";
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand();
		cout << array[i] << " ";
	}

	cout << "\n\n\tChar Array:\n";
	for (int i = 0; i < SIZE; i++) {
		arrChar[i] = Random(97, 122);
		cout << arrChar[i] << " ";
	}

	if (Choice == 1) {

		auto start_time = std::chrono::steady_clock::now();

		QuickSort(array, SIZE);

		auto end_time = std::chrono::steady_clock::now();
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

		cout << "\n\n\tQuick Sort:\n";
		PrintArray(array, SIZE);
		cout << "\n\nQuickSort time :" << elapsed_ns.count() << " ns\n";
	}


	if (Choice == 2) {

		auto start_time = std::chrono::steady_clock::now();

		InsertionSort(SIZE, array);

		auto end_time = std::chrono::steady_clock::now();
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

		cout << "\n\n\tInsertion Sort:\n";
		PrintArray(array, SIZE);
		cout << "\n\nInsetrionSort time :" << elapsed_ns.count() << " ns\n";
	}


	if (Choice == 3) {
		BogoSort(array, SIZE);

		cout << "\n\n\tBogo Sort:\n";
		PrintArray(array, SIZE);
	}


	if (Choice == 4) {
		CountingSort(arrChar, SIZE);

		cout << "\n\n\tCounting Sort:\n";
		for (int i = 0; i < SIZE; i++)
			cout << arrChar[i] << " ";
	}

	cout << "\n\n\tBinary Search\n";
	cout << "\nEnter any number in array: ";
	cin >> key;

	target = Search_Binary(array, 0, SIZE, key);

	if (target >= 0)
		cout << "That number got index: " << target << "\n\n";
	else
		cout << "Array do not have that number\n\n";
}