#include <iostream>
#include <math.h>
#include <cmath>
#include<clocale>
using namespace std;
typedef double(*pointFunc)(double);
double f(double x) {
setlocale(LC_ALL,"Russian");
  return (10 - x);
}
double simpson_integral(pointFunc f, double a, double b, int n) {
  const double h = (b-a)/n;
  double k1 = 0, k2 = 0;
  for(int i = 1; i < n; i += 2) {
    k1 += f(a + i*h);
    k2 += f(a + (i+1)*h);
  }
  return h/3*(f(a) + 4*k1 + 2*k2);
}
int main() {
  double a, b, eps;
  double s1, s;
  int n = 1; //��������� ����� �����
  cout << "������� ����� ������� �������������� a = ";
  cin >> a;
  cout << "\n ������� ������ ������� �������������� b = ";
  cin >> b;
  cout << "\n ������� ��������� �������� eps = ";
  cin >> eps;
  s1 = simpson_integral(f, a, b, n); //������ ����������� ��� ���������
  do {
    s = s1;     //������ �����������
    n = 2 * n;  //���������� ����� ����� � ��� ����,
                //�.�. ���������� �������� ���� � ��� ����
    s1 = simpson_integral(f, a, b, n);
  }
  while (fabs(s1 - s) > eps);  //��������� ����������� � �������� ���������
  cout << "\n �������� = " << s1 << endl;
}
