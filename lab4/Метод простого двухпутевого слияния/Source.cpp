#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

void SortUnsorted(int *arr, int low, int high, int size, int &compare, int &swap) {


	if (high <= low) {
		compare++;
		return;
	}

	int mid = (high + low) / 2;
	SortUnsorted(arr, low, mid, size, compare, swap);
	SortUnsorted(arr, mid + 1, high, size, compare, swap);

	int *buf = new int[size];
	for (int k = low; k <= high; k++) {
		buf[k] = arr[k];
	}

	int i = low;
	int j = mid + 1;
	for (int k = low; k <= high; k++)
	{
		if (i > mid)
		{
			arr[k] = buf[j];
			j++;
			swap++;
			compare++;
		}
		else if (j > high) {
			arr[k] = buf[i];
			i++;
			swap++;
			compare++;
		}
		else if (buf[j] < buf[i]) {//убывание - меняем знак
			arr[k] = buf[j];
			j++;
			swap++;
			compare++;
		}
		else {
			arr[k] = buf[i];
			i++;
			swap++;
			compare++;
		}
	}

}

int main() {
	int size;
	cout << "size  ";
	cin >> size;
	int swap = 0;
	int compare = 0;

	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	//	arr[i]=rand() % 100;
	}

	cout << "" << endl;
	

	int low = 0;
	int high = size - 1;
	clock_t time = clock();
	SortUnsorted(arr, low, high, size, compare, swap);
	clock_t time1 = clock();
	for (int i = 0; i < size; i++) {
	cout << arr[i] << " ";
	}
	cout << endl;
	

	cout << "time: " << time1 - time << endl;
	cout << "compare: " << compare << endl;
	cout << "swap: " << swap << endl;

	cin.get();
	cin.get();
	return 0;
}
