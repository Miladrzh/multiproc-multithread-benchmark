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

    // Check pos 1..3 Manually
    for (int i = 1 ; i <= 3 ; i++){
        if (a[i] == -1){
            cout << "There is a 14 in position: " << i << endl; 
        }
    }
    // Running with 4 thread
    int first_begin = 4;
    int second_begin = 5;
    int third_begin = 6;
    int fourth_begin = 7;

    DWORD first_thread;
    HANDLE first = CreateThread(NULL,0,find_thread,&first_begin,0,&first_thread);
    DWORD second_thread;
    HANDLE second = CreateThread(NULL,0,find_thread,&second_begin,0,&second_thread);
    DWORD third_thread;
    HANDLE third = CreateThread(NULL,0,find_thread,&third_begin,0,&third_thread);
    DWORD fourth_thread;
    HANDLE fourth = CreateThread(NULL,0,find_thread,&fourth_begin,0,&fourth_thread);
    cout << "S";
    WaitForSingleObject(first,INFINITE);
    CloseHandle(first);
    cout << "S";
    WaitForSingleObject(second,INFINITE);
    CloseHandle(second);
    WaitForSingleObject(third,INFINITE);
    CloseHandle(third);
    WaitForSingleObject(fourth,INFINITE);
    CloseHandle(fourth);
    cout <<"S";
    cout << endl << endl << "The time of code is " << (long long)(clock() - starting_time) << " ms" << endl;
    return 0;   
}