#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h>


using namespace std;


void Funk1(const vector<double>& vec) {
    for (double val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {



    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;

   
    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "������� ������������ ������� A � ������ b:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> A[i][j];
        }
        cout << "b[" << i + 1 << "]: ";
        cin >> b[i];
    }


    vector<double> x(n, 0.0);
    vector<double> x_old(n);


    double pogresh;
    int max_iterations;

    cout << "������� ����������� �������� ����������� (�������� 0): ";
    cin >> pogresh;
    cout << "������� ������������ ���������� ��������: ";
    cin >> max_iterations;

    cout << "�������:\n";
    for (int iter = 1; iter <= max_iterations; ++iter) {
        x_old = x;

        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }


        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error = max(error, fabs(x[i] - x_old[i]));
        }

        cout << "�������� " << iter << ": ";
        Funk1(x);

        if (error < pogresh) {
            cout << "������� ������� � �������� ��������� �� " << iter << " ��������.\n";                                                        
            break;
        }

        if (iter == max_iterations) {
            cout << "��������� ������������ ���������� ��������.\n";
        }
    }

    cout << "-----------------------------------------------";
    cout << "\n\n\t\tDev. By P.Koval\n\n\t\t";
    cout << "\n-----------------------------------------------";


    return 0;
}