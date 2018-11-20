#include <iostream>

using namespace std;

int main()
{
    int n,m,i;
    float s = 0;
    do {
        cout << "Enter diapason:" << endl;
        cin >> n;
        cin >> m;
    }
    while(n >= m);

    if(n % 2){
        n++;
    }
    for( ;n <= m; n += 2){
        s += n;
    }
    cout << endl << s;
    return 0;
}
