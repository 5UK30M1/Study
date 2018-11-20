//1.	Дано натуральное число n (которое также может быть равно нулю). Вычислить n!
#include <iostream>

using namespace std;

int main()
{
    int n,i;
    int f = 1;
    do
    {
    cout << "n!=?" << endl << "enter value of variable n" << endl << "n=";
    cin >> n;
    }
    while (n < 0);
    for (i = 2; i <= n; i++){
        f *= i;
    }
    cout << endl << "!n=" << f;
    return 0;
}
