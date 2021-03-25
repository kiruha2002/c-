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
    int row1, row2, column1, column2; //row1-��� ������ �������, row2-��� ������ �������, column1-������� ������ �������, column2-������� ������ �������
    double **a,**b,**c;               //�������� ���������� a ��� ������ �������, b ��� ������ �������, �-��� ������������ ���� ���� ������
    system("chcp 1251");
    system("cls");
    cout << " ������� ���������� ����� ������ ������� " ;
    cin >> row1;
    cout << " ������� ���������� �������� ������ ������� ";
    cin >> column1;
    cout << " ������� ��������� ����� ������ ������� " ;
    cin >> row2;
    cout << " ������� ��������� �������� ������ ������� " ;
    cin >> column2;

//��� ������ ����� ��������� ��������, �������� �� ������ �������� ��� �������, �.�.�� ��� ������� �������� �����������

    if (column1 != row2)
  {
    cout << "��������� ����������!";
    cin.get(); cin.get();
    return 0;
  }


//����� ��������� ������ �������
a = new double* [row1];
cout << "������� �������� ������ �������" << endl;
  for (int i = 0; i < row1; i++)
  {
      a[i] = new double[column1];
    for (int j = 0; j < column1; j++)
    {
      cout << "a[" << i << "][" << j << "]= ";
      cin >> a[i][j];
    }
 }
//����� ��������� ������ �������


for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column1; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }



//����� ��������� ������ �������

b = new double* [row2];
cout << "������� �������� ������ �������" << endl;
  for (int i = 0; i < row2; i++)
  {
      b[i] = new double[column2];
    for (int j = 0; j < column2; j++)
    {
      cout << "b[" << i << "][" << j << "]= ";
      cin >> b[i][j];
    }
  }
//����� ��������� ������ �������


  for (int i = 0; i < row2; i++)
  {
    for (int j = 0; j < column2; j++)
      cout << b[i][j] << " ";
    cout << endl;
  }

//���� �������� ���������:

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
// ����� ������� ������������
  cout << "������� ������������" << endl;
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column2; j++)
      cout << c[i][j] << " ";
    cout << endl;
  }
  cin.get(); cin.get();
  return 0;
}
