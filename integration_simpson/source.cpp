#include <iostream>
#define _USE_MATH_DEFINES
#include "ATLComTime.h"
#include <cmath>

using namespace std;

//�������� �������, ����������� ��������������� ��������� e^(cos(x))*sin(x)
double func(double x){
	double f=exp(cos(x))*sin(x);
	return f;
}

//�������, ����������� ��������� �������������� ������� ��������,
//������ ������ � ������� ������� ��������������, �������� ����������
double IntegratoinSimpson(double a, double b, double accuracy){
	double x, f, h, f_max = INT_MIN, integral = 0;
	int n;

	//���� ��������, ������ ���
	for (x = a; x < b;){
		f = fabs(sin(x) * exp(cos(x)) * ((pow(sin(x), 4)) + 5 * (cos(x) + 1)*(3 * cos(x) - 2 * pow(sin(x), 2)) + 1));
		if (f > f_max) f_max = f;
		x += 0.1;
	}
	n = ceil(pow((f_max*(pow((b - a), 5)) / (180 * accuracy)), 0.25));
	cout << "���������� ����� n = " << n << endl;
	h = (b - a) / (n * 2);
	cout << "��� h = " << h << endl;
	int q = 1; //���������� ��� ����������� ������� � ��������� �����
	for (x = a; x <= b;){
		if (x == a) integral += func(x);
		else if (x == b) integral += func(x);
		else if (q==1)
		{
			integral += 4*func(x);
			q = 2;
		}
		else if (q == 2)
		{
			integral += 2 * func(x);
			q = 1;
		}
		x += h;
	}
	integral = integral*h / 3;
	return integral;
}

int main(){
	setlocale(LC_ALL, "ru");
	double a = 0, b = M_PI / 2, accuracy = 0.0001, I;
	double true_I = 1.7183;
	cout.precision(4);
	cout.setf(ios::fixed);
	cout << "����������� �� ������� ["<<a<<", "<<b<<"]"<<" � �������� "<< accuracy << endl;
	I = IntegratoinSimpson(a, b, accuracy);
	cout << "������������ �������� ����� = " << I << endl;
	cout << "������ �������� ����� = " << true_I<< endl;
	cout << "����������� ����� = " << fabs(I - true_I) << endl;
}