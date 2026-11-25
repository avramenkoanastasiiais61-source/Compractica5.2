#include <iostream>
#include<cmath>

using namespace std;

double cosTaylor(double x, double accuracy);
double function(double x, double accuracy);

int main()
{
    double a;
    double b;
    double h;
    double x;
    double accuracy=0.00001;

    cout << "a = ";
    cin >> a;

    cout << "b =  ";
    cin >> b;

    cout << "h = ";
    cin >> h;

    double (*pCos)(double, double) = cosTaylor;
    double (*pFunction)(double, double) = function;

    x = a;

    cout << "x\tcos(x)\te^x" << endl;

    while (x <= b)
    {
        cout << x << "\t";
        cout << pCos(x, accuracy) << "\t";
        cout << pFunction(x, accuracy) << endl;

        x = x + h;
    }
}
double cosTaylor(double x, double accuracy)
{
    double sum = 1;
    int i = 1;
    double member = 1;
    while (fabs(member) > accuracy)
    {
        member = member * (-x * x) / (2 * i * (2 * i - 1));
        sum = sum + member;
        i++;
    }
    return sum;
}
double function(double x, double accuracy)
{
    double sum = 1;
    double member = 1;
    int i = 1;

    while (fabs(member) > accuracy)
    {
        member = member * x / i;
        sum = sum + member;
        i++;
    }

    return sum;
}