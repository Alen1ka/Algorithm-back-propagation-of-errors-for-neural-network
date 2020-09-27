#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int mistake(){
	//������ ���������� �������� �� ����
	int k_in;
	cout << "���������� �������� �� ����: ";
	cin >> k_in;
	double *mas = new double[k_in];

	//������ ����� ���������� ��������
	int k_sum;
	cout << "����� ���������� ��������: ";
	cin >> k_sum;
	double **mas_link = new double*[k_sum];

	for (int z = 0; z<k_sum; z++){
		mas_link[z] = new double[k_sum];
	}

	//������ �������� �������� �� ����
	for (int k = 0; k<k_in; k++){
		cout << "�������� ������� " << k << " �� ����: ";
		cin >> mas[k];
	}

	//������ �������� ������� �� �����
	double out;
	cout << "�������� ������� �� �����: ";
	cin >> out;

	//������ �������� �����
	double norm;
	cout << "�������� �����: ";
	cin >> norm;
	cout << "\n";

	//������ ����� ����� ���������
	for (int n = 0; n < k_in; n++){
		for (int i = 0; i<k_sum; i++){
			mas_link[i][n] = 0;
		}
	}

	for (int j = k_in; j<k_sum; j++){
		for (int i = 0; i<k_sum; i++){
			cout << "���� �� ����� ����� �������� " << i << " � ����� �������� " << j << "? �������� ����� �� ���� " << j << ", ���� ��� ���� (0 - ���� ����� ���): ";
			cin >> mas_link[i][j];
		}
		cout << "\n";
	}

	//������������ ��������������� ���� ��������� � ����������
	double e;
	int q = k_sum - k_in;
	double *net = new double[q];
	double *f_net = new double[q];
	for (int q = k_in; q<k_sum - 1; q++){
		double ne_t = 0;
		for (int k = 0; k<k_in; k++){
			ne_t = ne_t + mas[k] * mas_link[k][q];
		}
		net[q] = ne_t;
		cout << "��������������� ���� �������� " << q << " ����� " << net[q] << ".\n";
		e = exp(-net[q]);
		f_net[q] = 1 / (1 + e);
		cout << "���������� �������� " << q << " ����� " << f_net[q] << ".\n";
	}
	int j = k_sum - 1;
	double ne_t = 0;
	for (int q = k_in; q < k_sum; q++){
		ne_t = ne_t + f_net[q] * mas_link[q][j];
		net[k_sum - 1] = ne_t;
	}
	cout << "��������������� ���� �������� " << k_sum-1 << " ����� " << net[k_sum-1] << ".\n";
	e = exp(-net[k_sum - 1]);
	f_net[k_sum - 1] = 1 / (1 + e);
	cout << "���������� �������� " << k_sum - 1	 << " ����� " << f_net[k_sum - 1] << ".\n\n" ;
	
	//������������ �������������
	double *betta = new double[q - 1];
	betta[q - 1] = (out - f_net[k_sum-1]) * f_net[k_sum-1] * (1 - f_net[k_sum-1]);
	cout << "������������� �������� " << k_sum - 1 << " ����� " << betta[q - 1] << ".\n";
	
	int z = 0;
	for (int s = k_in; s < k_sum - 1; s++){
		betta[z] = (1 - f_net[s])*f_net[s] * mas_link[s][k_sum - 1] * betta[q-1];
		cout << "������������� �������� " << s << " ����� " << betta[z] << ".\n";
		z++;
	}
	cout << "\n";

	//������������ �������� ����
	double w = 0;

	e=k_in;
	for (int f = 0; f < k_in; f++){
		for (int g = 0; g < q-1; g++){
			w = norm * mas[f] * betta[g];
			cout << "��� �������� w" << f << "" << e << " ����� " << w << ".\n";
			e++;
			if(e==q+1) e=k_in;
		}
	}
	for (int f = k_in; f < k_sum-1; f++){
		w = norm * f_net[f] * betta[q-1];
		cout << "��� �������� w" << f << "" << k_sum-1 << " ����� " << w << ".\n";
	}
	cout << "\n";
	return 0;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	mistake();
	system("pause");
}

