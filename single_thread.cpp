// in the name of God

/*
*   Os Mini Project
*   SingleThread
*   Milad Rezaei 9433088
*/

# include <iostream>
# include <fstream>
# include <cstdlib>
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
    if (pos > n)
        return ;
    if (a[pos] == -1){
        cout << "There is a 14 in position: " << pos << endl; 
    }

    find(2 * pos);
    find(2 * pos + 1);
}

int main()
{
    starting_time = clock();
    init();
    find(1);
    
    cout << endl << endl << "The time of code is " << (long long)(clock() - starting_time) << " ms" << endl;
    return 0;   
}