#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>

using namespace std;

void* thread_ret(void* arg)
{
    int *num;
    num = (int*)arg;
    cout << "num in thread: " << *num << endl;
    sleep(2);

    *num = (*num) * 2;

    return (void*)(num);
}


// the two thread will run at random order(simutaneously).
int main()
{
    cout << "pthread create test" << endl;

    int ret = 0;
    pthread_t th_id_1;

    int num = 10;
    void* thread_ret_val;

    ret = pthread_create( &th_id_1, NULL, thread_ret, (void*)&num );
    if( ret )
    {
        cout << "create thread 1 failed..." << endl;
        return -1;
    }

    // wait for thread end, else the program
    // will exit directory
    pthread_join( th_id_1, &thread_ret_val );
    cout << "thread ret : " << *(int*)thread_ret_val << endl;

    return 0;
}
