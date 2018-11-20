#include <iostream>

using namespace std;

int main()
{
    double A, B, func;
    do {
    cout << "Enter A" << endl;
    cin >> A;
    cout << "Enter B" << endl;
    cin >> B;
    }
    while (A > B);
    for(int i = A; i <= B; i++){
        func = i * i * i;
        cout << "x=" << i << " x^3=" << func << endl;
    }
    return 0;
}
