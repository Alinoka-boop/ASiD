#include <iostream>
using namespace std;

int main() {
	int N, M;
	cout << "Enter N: ";
	cin >> N;
	cout << "Enter M: ";
	cin >> M;
	int **Arr = new int *[N];
	for (int i = 1; i <= N; i++) {
		Arr[i] = new int [M];
	}
	cout << "Enter massiv" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << "Arr[" << i << "][" << j << "]=";
			cin >> Arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << Arr[i][j]<<"  ";
		}
		cout << endl;
	}
	int k = Arr[1][1];
	int i = 1, j = 1;
	int a1 = 1, a2 = 1;
	cout << a1 << "   " << a2 << endl;
	while (j+1 <= M || i+1 <= N){
			if (j == M) {
				k += Arr[i+1][j];
				i = i + 1;
				a1 = i;
				a2 = j;
				cout << a1 << "   " << a2 << endl;
			}
			else if (i == N) {
				k += Arr[i][j+1];
				j = j + 1;
				a1 = i;
				a2 = j;
				cout << a1 << "   " << a2 << endl;
				
			}
			else {
				if (Arr[i + 1][j] < Arr[i][j + 1]) {
					k += Arr[i + 1][j];
					i = i + 1;
					a1 = i;
					a2 = j;
					cout << a1 << "   " << a2 << endl;
				}
			
				else {
					k += Arr[i][j+1];
					j = j + 1;
					a1 = i;
					a2 = j;
					cout << a1 << "   " << a2 << endl;
				}
			}
			
		
	}

	cout << "Min: " << k << endl;

	cin.get();
	cin.get();
	return 0;
}