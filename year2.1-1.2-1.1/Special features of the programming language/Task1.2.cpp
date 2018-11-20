//Дано число. Найти сумму и произведение его цифр.
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n,i,f;
    int digitnumb;
    int s=0;
    cout << "Enter positive integer" << endl;
    cin >> n;
    digitnumb = log10(n);
    cout << "Number of digits:" << digitnumb+1 << endl;
    for(i = digitnumb; i >= 0; i--)
    {
        f= n / pow(10, i);
        s += f;
        n -= pow(10, i) * f;
    }
    cout << "Sum of numerals:" << s;
    return 0;
}
