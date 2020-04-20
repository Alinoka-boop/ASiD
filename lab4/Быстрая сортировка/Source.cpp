#include<iostream>//быстрая сортировка
#include<ctime>
using namespace std;
void sort(int *arr, int b, int e) {
	int l = b, r = e;
	int piv = arr[(l + r) / 2];
	do {
		while (arr[l] < piv) {
			l++;
		}
		while (arr[r] > piv) {
			r--;
		}
		if (l <= r) {
			swap(arr[l++], arr[r--]);
		}
	} while (l <= r);
	if (b < r) {
		sort(arr, b, r);
	}
	if (e > l) {
		sort(arr, l, e);
	}
}
void sort1(int *arr, int b, int e, int &ifes, int &swaps) {
	int l = b, r = e;
	int piv = arr[(l + r) / 2];
	do {
		ifes++;
		while (arr[l] < piv) {
			l++;
			ifes++;
		}
		ifes++;
		while (arr[r] > piv) {
			r--;
			ifes++;
		}
		if (l <= r) {
			swap(arr[l++], arr[r--]);
			swaps++;
		}
	} while (l <= r);
	if (b < r) {
		sort1(arr, b, r, ifes, swaps);
	}
	if (e > l) {
		sort1(arr, l, e, ifes, swaps);
	}
}
int main() {
	setlocale(0, "");
	int a;
	cin >> a;
	int *mas3 = new int[a];
	int *mas4 = new int[a];
	int *mas5 = new int[a];

	int *mas = new int[a];
	for (int i = 0; i < a; i++) {
		mas3[i] = i;
		mas[i] = i;
	}
	clock_t time, start, finish;
	start = clock();
	sort(mas, 0, a);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;

	int *mas1 = new int[a];
	int k = a;
	for (int i = 0; i < a; i++) {
		mas4[i] = k;
		mas1[i] = k;
		k--;
	}
	start = clock();
	sort(mas1, 0, a);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;

	int *mas2 = new int[a];
	for (int i = 0; i < a; i++) {
		mas5[i] = mas2[i] = rand();
	}
	start = clock();
	sort(mas2, 0, a);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;

	int ifes = 0;
	int swap = 0;
	start = clock();
	sort1(mas3, 0, a, ifes, swap);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;

	ifes = 0;
	swap = 0;

	start = clock();
	sort1(mas4, 0, a, ifes, swap);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;

	ifes = 0;
	swap = 0;
	start = clock();
	sort1(mas5, 0, a, ifes, swap);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;

	system("pause");
	return 0;
}