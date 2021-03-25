#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <numeric>
#include <functional>
#include <complex>



using namespace std;


int main()
{
    int row1, row2, column1, column2; //row1-ряд первой матрицы, row2-ряд второй матрицы, column1-столбец первой матрицы, column2-столбец второй матрицы
    double **a,**b,**c;               //добавить переменные a для первой матрицы, b для второй матрицы, с-для перемножения этих двух матриц
    system("chcp 1251");
    system("cls");
    cout << " введите количество строк первой матрицы " ;
    cin >> row1;
    cout << " введите количество столбцов первой матрицы ";
    cin >> column1;
    cout << " введите количеств строк второй матрицы " ;
    cin >> row2;
    cout << " введите количеств столбцов второй матрицы " ;
    cin >> column2;

//для начала нужно выполнить проверку, возможно ли вообще умножить эти матрицы, т.к.не все матрицы возможно перемножать

    if (column1 != row2)
  {
    cout << "Умножение невозможно!";
    cin.get(); cin.get();
    return 0;
  }


//Введём параметры первой матрицы
a = new double* [row1];
cout << "Введите элементы первой матрицы" << endl;
  for (int i = 0; i < row1; i++)
  {
      a[i] = new double[column1];
    for (int j = 0; j < column1; j++)
    {
      cout << "a[" << i << "][" << j << "]= ";
      cin >> a[i][j];
    }
 }
//Вывод элементов первой матрицы


for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column1; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }



//Введём параметры второй матрицы

b = new double* [row2];
cout << "Введите элементы второй матрицы" << endl;
  for (int i = 0; i < row2; i++)
  {
      b[i] = new double[column2];
    for (int j = 0; j < column2; j++)
    {
      cout << "b[" << i << "][" << j << "]= ";
      cin >> b[i][j];
    }
  }
//Вывод элементов второй матрицы


  for (int i = 0; i < row2; i++)
  {
    for (int j = 0; j < column2; j++)
      cout << b[i][j] << " ";
    cout << endl;
  }

//Сама операция умножения:

c = new double* [row1];
  for (int i = 0; i < row1; i++)
  {
    c[i] = new double[column2];
    for (int j = 0; j < column2; j++)
    {
      c[i][j] = 0;
      for (int k = 0; k < column1; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }
// Вывод матрицы произведения
  cout << "Матрица произведения" << endl;
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column2; j++)
      cout << c[i][j] << " ";
    cout << endl;
  }
  cin.get(); cin.get();
  return 0;
}
