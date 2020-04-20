#include<iostream>
#include<ctime>  //Метод вставки
using namespace std;
void sort(int *mas, int a) {
	int j;
	for (int i = 1; i < a; i++)
	{
		int value = mas[i];
		for (j = i - 1; (j >= 0) && (mas[j] > value); j--)
		{
			mas[j + 1] = mas[j];
		}
		mas[j + 1] = value;
	}
}
void sort1(int *mas, int a, int &ifes, int &swaps) {
	int j;
	for (int i = 1; i < a; i++)
	{
		int value = mas[i];
		for (j = i - 1; (j >= 0); j--) {
			ifes++;
			if (mas[j] > value) {
				mas[j + 1] = mas[j];
			}
		}
		mas[j + 1] = value;
		swaps++;
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
	cout << "TIME:" <<  time  << endl << endl;
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