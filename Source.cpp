#include <iostream>
#include <locale>
using namespace std;

void PRNT(float** M, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols + 1; j++)
		{
			cout << M[i][j] << "\t";
		}
		cout << endl;


	}

	cout << endl;
}

int StrWay(float** M, int rows, int cols)
{
	int i, j, i1, j1, t, y;
	int oo = 1;
	float q, tmp, tt;
	for (i = 0; i < rows; i++)
	{
		oo = 1;
		if ((M[i][i] == 0) and (i == rows - 1) and (M[i][cols] == 0))
		{
			cout << "Множество решений." << endl;
			return 0;
		}
		else
		{
			if ((M[i][i] == 0) and (i != rows - 1))
			{
				//cout << "На гл. диагонали ноль." << endl;

				for (y = 0; y < (rows + 1 - i); y++)
				{
					if (M[i][i] != 0)
					{
						break;
					}
					else
					{


						for (t = i; t < cols + 1; t++)
						{
							tt = M[i][t];
							M[i][t] = M[i + 1][t];
							M[i + 1][t] = tt;
						}


					}
				}
				if (M[i][i] == 0)
				{

					return 10;
					oo = 0;
				}
			}
			if (oo != 0)
			{
				if ((M[i][i] == 0) and (i == rows - 1) and (M[i][cols] != 0))
				{
					cout << "Система несовместна." << endl;
					return 0;
				}
				else
				{


					tmp = M[i][i];
					for (j = i; j < cols + 1; j++)
					{
						M[i][j] = M[i][j] / tmp;
					}



					//<--
					for (i1 = i + 1; i1 < rows; i1++)
					{
						q = M[i1][i] / M[i][i];
						for (j1 = i; j1 < cols + 1; j1++)
						{
							M[i1][j1] = M[i1][j1] - q * M[i][j1];
						}


					}
					PRNT(M, rows, cols);
				}
			}
		}
	}

	//PRNT(M, rows, cols);
	return 2;
}

int RevWay(float** M, int rows, int cols)
{
	int i, j, i1, j1;
	float q, tmp;
	for (i = rows - 1; i >= 0; i--)
	{
		if (M[i][i] == 0)
		{
			cout << "Ноль на гл. диагонали." << endl;
			return 0;
		}
		else
		{
			tmp = M[i][i];
			for (j = i; j < cols + 1; j++)
			{
				M[i][j] = M[i][j] / tmp;
			}



			//<--
			for (i1 = i - 1; i1 >= 0; i1--)
			{
				q = M[i1][i] / M[i][i];
				for (j1 = i; j1 < cols + 1; j1++)
				{
					M[i1][j1] = M[i1][j1] - q * M[i][j1];
				}


			}
			PRNT(M, rows, cols);
		}

	}

	//PRNT(M, rows, cols);
	return 1;
}
// Для метода Джордана-Гаусса

int RevWay123(float** M, int rows, int cols, float* arrX)
{
	int i, j, i1, j1;
	float q, tmp;

	for (i = rows - 1; i >= 0; i--)
	{

		arrX[i] = M[i][cols];
		for (j = 0; j < i; j++)
		{
			M[j][i] = M[j][i] * arrX[i];
			M[j][cols] = M[j][cols] - M[j][i];
		}
	}



	for (j1 = 1; j1 < rows + 1; j1++)
	{
		cout << "x" << j1 << " = " << arrX[j1 - 1] << endl;
	}

	return 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int rows, cols, i, j;
	int qwe;
	// Начало созд. м-цы коэффиц. и св. ч-ов
	cout << "Введите количество уравнений." << endl;
	cin >> rows;
	cout << "Введите количество аргуметнов." << endl;
	cin >> cols;
	float** arr = new float* [rows];
	for (i = 0; i < rows; i++)
	{
		arr[i] = new float[cols + 1];
	}
	// Конец созд. м-цы коэффиц. и св. ч-ов

	// Начало созд. м-цы коэффиц. и св. ч-ов (копия)
	float** arr1 = new float* [rows];
	for (i = 0; i < rows; i++)
	{
		arr1[i] = new float[cols + 1];
	}
	// Конец созд. м-цы коэффиц. и св. ч-ов (копия)

	// Начало создания м-цы арг-ов
	float* arrX = new float[cols];
	// Конец создания м-цы арг-ов

	// Начало зап-я м-цы коэффиц. и св. ч-ов и её копии
	cout << "Заполнение матрицы коэффициентов и свободных членов." << endl;
	for (i = 0; i < rows; i++)
	{
		cout << " Введите " << cols << " коэффициентов " << i + 1 << " уравнения " << endl;

		for (j = 0; j < cols + 1; j++)
		{

			if (j == cols)
				cout << "Введите свободный член " << i + 1 << " уравнения " << endl;
			cin >> arr[i][j];
			arr1[i][j] = arr[i][j];
		}
	}
	// Конец зап-я м-цы коэффиц. и св. ч-ов и её копии

	// Начало вывода м-цы коэффиц. и св. ч-ов
	cout << "Исходная матрица:" << endl;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols + 1; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	// Конец вывода м-цы коэффиц. и св. ч-ов

	// ...
	float** pArr1 = arr1;
	float* parrX = arrX;
	qwe = StrWay(pArr1, rows, cols);
	if (qwe == 10)
	{
		cout << "Возник нулевой столбец." << endl;
	}
	else
	{
		if (qwe != 0)
		{
			RevWay123(pArr1, rows, cols, parrX);
		}
	}
	//RevWay(pArr1, rows, cols);

	// Начало уд-я коэффиц. и св. ч-ов и её копии
	for (i = 0; i < rows; i++)
	{
		delete[] arr[i];
		delete[] arr1[i];
	}
	delete[] arr;
	delete[] arr1;
	// Конец уд-я коэффиц. и св. ч-ов и её копии

	// Начало уд-я м-цы арг-ов
	delete[] arrX;
	// Конец уд-я м-цы арг-ов
	return 0;
}
