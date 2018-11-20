#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int f;
    int l=0;
    int k=0;
    cout << "Enter positive integer" << endl;
    cin >> f;
    for(; f;)
    {
        if ( f % 2){
            l++;
        }
        else {
            k++;
        }
        f = f / 10;
    }
    cout << "Number of even numerals :" << k <<endl;
    cout << "Number of uneven numerals :" << l;
    return 0;
}
