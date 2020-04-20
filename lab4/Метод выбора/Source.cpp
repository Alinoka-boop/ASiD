#include<iostream>//метод выбора
#include<ctime>
using namespace std;
void sort(int *mas, int a) {
	int min;
	for (int i = 0; i < a - 1; i++) {
		min = i;
		for (int j = i + 1; j < a; j++) {
			if (mas[j] < mas[min]) { min = j; }
		}
		int buf = mas[i];
		mas[i] = mas[min];
	}
}
void sort1(int *mas, int a, int &ifes, int &swap) {
	int min;
	for (int i = 0; i < a - 1; i++) {
		min = i;
		for (int j = i + 1; j < a; j++) {
			ifes++;
			if (mas[j] < mas[min]) { min = j; }
		}
		int buf = mas[i];
		mas[i] = mas[min];
		mas[min] = buf;
		swap++;
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