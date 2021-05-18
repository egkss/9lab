#include<iostream>
#include<cmath>
using namespace std;
double get_x();
int get_n();

class MySin {
public:
    int n;
    double* p;
    double result = 0;
    MySin(int i, double x) {
        n = i;
        p = new double[n];
        p[0] = x;
        for (int k = 0; k < n; k++)
        {
            result += (pow(-1, k) * pow(x, (2 * k) + 1)) / (p[2 * k + 1]);
        }
        cout << "sin (" << x << ") = " << result << endl;
    }
    ~MySin() { delete[] p; }
};
int main() {
    int n = get_n();
    double x = get_x();
    MySin obj(n, x);
    return 0;
}
int get_n() {
    while (true) {
        int n;
        cout << "Enter n: ";
        cin >> n;
        if (cin.fail() || n < 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "404, incorrectly entered" << endl;
        }
        else return n;
    }
}
double get_x() {
    while (true) {
        double x;
        cout << "Enter x: ";
        cin >> x;
        if (cin.fail() || x < 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "404, incorrectly entered" << endl;
        }
        else return x;
    }
}