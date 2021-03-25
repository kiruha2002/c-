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
    int row1, row2, column1, column2; //row1 is the row of the first matrix, row2 is the row of the second matrix, column1 is the column of the first matrix, column2 is the column of the second matrix
    double **a,**b,**c;               //add variables a for the first matrix, b for the second matrix, c-for the multiplication of these two matrices
    system("chcp 1251");
    system("cls");
    cout << " enter the number of rows of the first matrix " ;
    cin >> row1;
    cout << " enter the number of columns of the first matrix ";
    cin >> column1;
    cout << " enter the number of rows of the second matrix " ;
    cin >> row2;
    cout << " enter the number of columns of the second matrix " ;
    cin >> column2;

//first you need to check whether it is possible to multiply these matrices at all, because not all matrices can be multiplied

    if (column1 != row2)
  {
    cout << " Multiplication is impossible! ";
    cin.get(); cin.get();
    return 0;
  }


//Let's introduce the parameters of the first matrix
a = new double* [row1];
cout << " Enter the elements of the first matrix " << endl;
  for (int i = 0; i < row1; i++)
  {
      a[i] = new double[column1];
    for (int j = 0; j < column1; j++)
    {
      cout << "a[" << i << "][" << j << "]= ";
      cin >> a[i][j];
    }
 }
//Derivation of the elements of the first matrix


for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column1; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }



//Let's introduce the parameters of the second matrix

b = new double* [row2];
cout << " Enter the elements of the second matrix " << endl;
  for (int i = 0; i < row2; i++)
  {
      b[i] = new double[column2];
    for (int j = 0; j < column2; j++)
    {
      cout << "b[" << i << "][" << j << "]= ";
      cin >> b[i][j];
    }
  }
//Derivation of the elements of the second matrix


  for (int i = 0; i < row2; i++)
  {
    for (int j = 0; j < column2; j++)
      cout << b[i][j] << " ";
    cout << endl;
  }

//The multiplication operation itself:

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
// Derivation of the product matrix
  cout << " Product matrix " << endl;
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column2; j++)
      cout << c[i][j] << " ";
    cout << endl;
  }
  cin.get(); cin.get();
  return 0;
}
