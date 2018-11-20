#include <iostream>

using namespace std;

unsigned long long int Marsen (int n);// Числа Мэрсэна
void disp_binary (unsigned u);// Бинарная интерпретация

int main()
{
    int n;
    unsigned u;
    cout << "Enter number of Marsen:" << endl;
    cin >> n;
    cout << "M(" << n << ") = " << (*Marsen)(n) << endl;
    cout << "Binary interpretation of number(-256 to 255):";
    cin >> u;
    (*disp_binary)(u);
    return 0;
}
// Числа Мэрсэна
unsigned long long int Marsen (int n)
{
    unsigned long long int m(1);
    for (int i(1); i <= n; i++)
    {
        m *= 2;
    }
    return m - 1;
}
// Бинарная интерпретация
void disp_binary (unsigned u)
{
    register int t;
    for (t = 128; t > 0; t = t / 2)
    {
        if (u & t)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n";
}
