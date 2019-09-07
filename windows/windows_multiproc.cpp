// in the name of God

/*
*   Os Mini Project
*   OS : Windows
*   MultiThread
*   Milad Rezaei 9433088
*/

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <windows.h>
# include <ctime>

using namespace std;

const int maxN = 10000000 + 10;
int a[maxN] , n;
clock_t starting_time;

void init(){
    n = 10000000;
    for (int i = 1 ; i <= n ; i++)
        a[i] = rand() % 10000;
    a[100] = a[10000] = a[1000000] = -1;
}

void find(int pos){
    // cout << pos << endl;
    if (pos > n)
        return ;
    if (a[pos] == -1){
        cout << "There is a 14 in position: " << pos << endl; 
    }
    find(2 * pos);
    find(2 * pos + 1);
    return ;
}

DWORD WINAPI find_thread(LPVOID lpParameter){
    int pos = *((int*)lpParameter);
    if (a[(int)pos] == -1){
        cout << "There is a 14 in position: " << pos << endl; 
    }
    find(2 * (int)pos);
    find(2 * (int)pos + 1);

    return 0;
}

int main()
{
    starting_time = clock();
    init();

    
    cout << endl << endl << "The time of code is " << (long long)(clock() - starting_time) << " ms" << endl;
    return 0;   
}