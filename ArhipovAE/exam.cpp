#include <iostream>
using namespace std;

int main(){
    int i,j;
    bool fl;
    int n;
    cout << "n= ";
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        fl = true;
        for(j = 2;j < i;j++)
        {
            if(i % j == 0)
            {
                fl = false;
                break;
            }
        }
        if(fl)
        {
            cout << i << endl;
        }
    }
}
