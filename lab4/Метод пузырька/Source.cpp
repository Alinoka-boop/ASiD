#include<iostream>
#include<ctime>//сортировка обменом
using namespace std;
void sort(int *mas, int a) {
	for (int i = 1; i < a - 1; i++) {
		for (int k = 0; k < a - 1; k++)
			if (mas[k] > mas[k + 1]) {
				int buf = mas[k];
				mas[k] = mas[k + 1];
				mas[k + 1] = buf;
			}
	}
}
void sort1(int *mas, int a, int &ifes, int &swaps) {
	for (int i = 1; i < a - 1; i++) {
		for (int k = 0; k < a - 1; k++) {
			ifes++;
			if (mas[k] > mas[k + 1]) {
				int buf = mas[k];
				mas[k] = mas[k + 1];
				mas[k + 1] = buf;
				swaps++;
			}
		}
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
	sort(mas, a);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;
	delete[]mas;

	int *mas1 = new int[a];
	int k = a;
	for (int i = 0; i < a; i++) {
		mas4[i] = k;
		mas1[i] = k;
		k--;
	}
	start = clock();
	sort(mas1, a);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;
	delete[]mas1;

	int *mas2 = new int[a];
	for (int i = 0; i < a; i++) {
		mas5[i] = mas2[i] = rand();
	}
	start = clock();
	sort(mas2, a);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;
	delete[]mas2;

	int ifes = 0;
	int swap = 0;
	start = clock();
	sort1(mas3, a, ifes, swap);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;
	delete[]mas3;

	ifes = 0;
	swap = 0;

	start = clock();
	sort1(mas4, a, ifes, swap);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;
	delete[]mas4;

	ifes = 0;
	swap = 0;
	start = clock();
	sort1(mas5, a, ifes, swap);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;
	delete[]mas5;

	system("pause");
	return 0;
}
