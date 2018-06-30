#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>

using namespace std;

void* thread_info_1(void* arg)
{
    cout << "thread_info_1" << endl;
    cout << "[thread1]This thread's id is : " << (unsigned int)pthread_self() << endl;
    cout << "[thread1]The process pid is : " << getpid() << endl;
}

void* thread_info_2(void* arg)
{
    cout << "thread_info_2" << endl;
    cout << "[thread2]This thread's id is : " << (unsigned int)pthread_self() << endl;
    cout << "[thread2]The process pid is : " << getpid() << endl;
}

// the process id is the same, but the thread id is different.
int main()
{
    cout << "pthread create test" << endl;

    int ret = 0;
    pthread_t th_id_1, th_id_2;

    ret = pthread_create( &th_id_1, NULL, thread_info_1, NULL );
    if( ret )
    {
        cout << "create thread 1 failed..." << endl;
        return -1;
    }

    ret = pthread_create( &th_id_2, NULL, thread_info_2, NULL );
    if( ret )
    {
        cout << "create thread 2 failed..." << endl;
        return -1;
    }

    // wait for thread end, else the program
    // will exit directory
    pthread_join( th_id_1, NULL );
    pthread_join( th_id_2, NULL );

    return 0;
}
