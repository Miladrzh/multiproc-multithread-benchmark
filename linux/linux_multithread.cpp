// in the name of God

/*
*   Os Mini Project
*   OS : Linux
*   MultiThread
*   Milad Rezaei 9433088
*/

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <pthread.h>

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

void *find_thread(void *pos_pointer){
    int pos = *(int *)pos_pointer;
    // cout << pos << endl;
    if (a[(int)pos] == -1){
        cout << "There is a 14 in position: " << pos << endl; 
    }
    find(2 * (int)pos);
    find(2 * (int)pos + 1);
    pthread_exit(0);
}



int main()
{
    starting_time = clock();
    init();

    // check position 1 , 2 , 3 manually
    for (int i = 1 ; i <= 3 ; i++){
        if (a[i] == -1){
            cout << "There is a 14 in position: " << i << endl; 
        }
    }

    
    /*
        running with 4 thread in 4 subtree
        the tree is like this
                        1
                      /   \                        
                    2       3
                   / \     / \
                  4   5   6   7
    */
  
    pthread_t first , second , third , fourth;
    int first_ind = 4 , second_ind = 5 , third_ind = 6 , fourth_ind = 7;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&first , &attr , find_thread , (void *)&first_ind);
    pthread_create(&second , &attr , find_thread , (void *)&second_ind);
    pthread_create(&third , &attr , find_thread , (void *)&third_ind);
    pthread_create(&fourth , &attr , find_thread , (void *)&fourth_ind);

    // joining threads!
    pthread_join(first, NULL);
    pthread_join(second, NULL);
    pthread_join(third, NULL);
    pthread_join(fourth, NULL);
    cout << endl << endl << "The time of code is " << (long long)(clock() - starting_time) << " ms" << endl;
    return 0;   
}

/*

Linux:

MultiProc

141623
137576
132810

SingleThread
162438
164665
164191

MultiThread
176626
181866
184450

g++ -pthread -o a Linux_MultiThread.cpp


single
237
236
227


multi 
207
203
207

*/