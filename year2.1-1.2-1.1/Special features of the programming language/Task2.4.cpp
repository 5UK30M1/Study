#include <iostream>

using namespace std;

int main()
{
    int n,old,young,i;
    float avg = 0;
    cout << "Enter age of customer (Enter 0 to finish):" << endl;
    cin >> n;
    old = n;
    young = n;
    avg = n;
    if (n == 0)
    {
        return 0;
    }
    for (i = 0; n != 0; i++)
    {
        cout << "Enter age of customer (Enter 0 to finish):" << endl;
        cin >> n;
        if (n > old && n != 0 ) {
                old = n;
        }
        if (n < young && n != 0) {
                young = n;
        }
        avg += n;
    }
    avg = avg / i;
    cout << "Age of the oldest customer: " << old << endl << "Age of the youngest: " << young << endl << "Average age of customers: " << avg;
    return 0;
}
