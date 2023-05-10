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
			cout << "Ìíîæåñòâî ðåøåíèé." << endl;
			return 0;
		}
		else
		{
			if ((M[i][i] == 0) and (i != rows - 1))
			{
				//cout << "Íà ãë. äèàãîíàëè íîëü." << endl;

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
					cout << "Ñèñòåìà íåñîâìåñòíà." << endl;
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
			cout << "Íîëü íà ãë. äèàãîíàëè." << endl;
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
// Äëÿ ìåòîäà Äæîðäàíà-Ãàóññà

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
	// Íà÷àëî ñîçä. ì-öû êîýôôèö. è ñâ. ÷-îâ
	cout << "Ââåäèòå êîëè÷åñòâî óðàâíåíèé." << endl;
	cin >> rows;
	cout << "Ââåäèòå êîëè÷åñòâî àðãóìåòíîâ." << endl;
	cin >> cols;
	float** arr = new float* [rows];
	for (i = 0; i < rows; i++)
	{
		arr[i] = new float[cols + 1];
	}
	// Êîíåö ñîçä. ì-öû êîýôôèö. è ñâ. ÷-îâ

	// Íà÷àëî ñîçä. ì-öû êîýôôèö. è ñâ. ÷-îâ (êîïèÿ)
	float** arr1 = new float* [rows];
	for (i = 0; i < rows; i++)
	{
		arr1[i] = new float[cols + 1];
	}
	// Êîíåö ñîçä. ì-öû êîýôôèö. è ñâ. ÷-îâ (êîïèÿ)

	// Íà÷àëî ñîçäàíèÿ ì-öû àðã-îâ
	float* arrX = new float[cols];
	// Êîíåö ñîçäàíèÿ ì-öû àðã-îâ

	// Íà÷àëî çàï-ÿ ì-öû êîýôôèö. è ñâ. ÷-îâ è å¸ êîïèè
	cout << "Çàïîëíåíèå ìàòðèöû êîýôôèöèåíòîâ è ñâîáîäíûõ ÷ëåíîâ." << endl;
	for (i = 0; i < rows; i++)
	{
		cout << " Ââåäèòå " << cols << " êîýôôèöèåíòîâ " << i + 1 << " óðàâíåíèÿ " << endl;

		for (j = 0; j < cols + 1; j++)
		{

			if (j == cols)
				cout << "Ââåäèòå ñâîáîäíûé ÷ëåí " << i + 1 << " óðàâíåíèÿ " << endl;
			cin >> arr[i][j];
			arr1[i][j] = arr[i][j];
		}
	}
	// Êîíåö çàï-ÿ ì-öû êîýôôèö. è ñâ. ÷-îâ è å¸ êîïèè

	// Íà÷àëî âûâîäà ì-öû êîýôôèö. è ñâ. ÷-îâ
	cout << "Èñõîäíàÿ ìàòðèöà:" << endl;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols + 1; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	// Êîíåö âûâîäà ì-öû êîýôôèö. è ñâ. ÷-îâ

	// ...
	float** pArr1 = arr1;
	float* parrX = arrX;
	qwe = StrWay(pArr1, rows, cols);
	if (qwe == 10)
	{
		cout << "Âîçíèê íóëåâîé ñòîëáåö." << endl;
	}
	else
	{
		if (qwe != 0)
		{
			RevWay123(pArr1, rows, cols, parrX);
		}
	}
	//RevWay(pArr1, rows, cols);

	// Íà÷àëî óä-ÿ êîýôôèö. è ñâ. ÷-îâ è å¸ êîïèè
	for (i = 0; i < rows; i++)
	{
		delete[] arr[i];
		delete[] arr1[i];
	}
	delete[] arr;
	delete[] arr1;
	// Êîíåö óä-ÿ êîýôôèö. è ñâ. ÷-îâ è å¸ êîïèè

	// Íà÷àëî óä-ÿ ì-öû àðã-îâ
	delete[] arrX;
	// Êîíåö óä-ÿ ì-öû àðã-îâ
	return 0;
}
