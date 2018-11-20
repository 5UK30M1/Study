#include <iostream>

using namespace std;

int main()
{
    double num;
    char ch;
    cout << "Enter real number" << endl;
    cin >> num;
    num *= num;
    cout << num << endl;
    cout << "Enter 'y' to continue" << endl;
    cin >> ch;
    if (ch == 'y') {
        main();
    }
    else {
        return 0;
    }
}
