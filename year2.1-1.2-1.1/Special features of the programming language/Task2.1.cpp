#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int N, i;
    float t0, t;
    float s = 0;
    cout << "Enter integer(Enter 0 to end):" << endl;
    t0 = time(0);
    for(i = -1; N != 0; i++){
        cin >> N;
        s += N;
    }
    if (i){
        s = s / i;
    }
    else
    {
        return 0;
    }
    t = time(0);
    cout << endl << "Middle Average = " << s << endl << "time=" << t-t0;
    return 0;
}
