// in the name of God

/*
*   Os Mini Project
*   MultiThread
*   Milad Rezaei 9433088
*/

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <pthread.h>
# include <unistd.h>

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

int main()
{
    starting_time = clock();
    init();

    // Check pos 1 Manually
    if (a[1] == -1){
        cout << "There is a 14 in position: " << 1 << endl; 
    }
    // Running with 2 process
    pid_t pid = fork();
    cout << pid << endl;
    // Left subtree
    if (!pid){
        find(3);
    }// Right subtree
    else{
        find(2);
    }

    // printing time of parrent
    if (pid != 0)
        cout << endl << endl << "The time of code is " << (long long)(clock() - starting_time) << " ms" << endl;
    return 0;   
}