#include <iostream>
#include <vector>
//ссылка на гитхаб https://github.com/Alinoka-boop/ASiD . В файле-ресурсе указан пример входных данных.
/*Построим граф, в котором вершины соответствуют людям, а ребро соединяет две вершины,
если эти люди знакомы другс другом.Задача сводится к определению двудольности графа.
Двудольный граф - граф, вершины которого можно разбить на два множества так, что каждое ребро соединяет вершины из разных множеств.*/
using namespace std;

int kol_1 = 0;

void DFS_res(bool& res, vector<vector<int>> v, vector<int> &dvud, vector<bool> &used, int i, int ind) {
	if (res == false)
		return;
	used[i] = true;
	dvud[i] = ind;
	if (ind == 1)
	{
		kol_1++;
		ind = 2;
	}
	else ind = 1;
	for (int j = 0; j < (int)v.size(); j++)
	{
		if (res == false)
			break;
		if (v[i][j] == 1)
		{
			if (!used[j]) {
				DFS_res(res, v, dvud, used, j, ind);
			}
			else if (dvud[j] != ind)
				res = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;//ввод кол-ва людей
	vector<vector<int>> mas;//матрица знакомств
	for (int i = 0; i < n; i++) {
		vector<int> tmp_vect;
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			tmp_vect.push_back(tmp);
		}
		mas.push_back(tmp_vect);
	}
	vector<int>dvud(n);
	vector<bool>used(n);
	bool res = true;
	while (true) {
		if (res == false)
			break;
		int k;
		for (k = 0; k < n; k++) {
			if (!used[k])
				break;
		}
		if (k != n)
			DFS_res(res, mas, dvud, used, k, 1);
		else break;
	}
	if (res == true) {
		cout << "YES!!!" << endl;
	}
	else cout << "NO!!!" << endl;
	system("pause");
	return 0;
}
/*Произведём серию поисков в ширину.Т.е.будем запускать поиск в ширину из каждой непосещённой вершины.
Ту вершину, из которой мы начинаем идти, мы помещаем в первую долю.В процессе поиска в ширину, если мы идём 
в какую - то новую вершину, то мы помещаем её в долю, отличную от доли текущей вершину.
Если же мы пытаемся пройти по ребру в вершину, которая уже посещена, то мы проверяем, чтобы эта вершина и текущая вершина 
находились в разных долях.В противном случае граф двудольным не является.*/