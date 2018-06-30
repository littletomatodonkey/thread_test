#include <iostream>
#include <pthread.h>
#include <unistd.h>

#include <ctime>
#include <sys/time.h>
#include <unistd.h>
#include <vector>

using namespace std;

void* thread_1(void*)
{
    // clock_t t;
    // t = clock();
    for (int i = 0; i < 20000; ++i)
    {
        for (int j = 0; j < 20000; ++j)
        {
            int m = 2*3*4*5*6;
        }
    }
    // t = clock() - t;
    // cout << (unsigned int)pthread_self() << ", time : " << ((double)t)/CLOCKS_PER_SEC << "s" << endl;
}


// the two thread will run arandom order(simutaneously).
int main()
{
    timeval t_start, t_end;
    cout << "pthread create test" << endl;

    int ret = 0;
    pthread_t th_id_1, th_id_2;

    gettimeofday( &t_start, NULL);
    std::vector<pthread_t> vec_thread(10);
    for (int i = 0; i < vec_thread.size(); ++i)
    {
        ret = pthread_create( &vec_thread[i], NULL, thread_1, NULL );
        if( ret )
        {
            cout << "create thread 1 failed..." << endl;
            return -1;
        }
    }

    for (int i = 0; i < vec_thread.size(); ++i)
    {
        pthread_join( vec_thread[i], NULL );
    }

    gettimeofday( &t_end, NULL);
    double delta_t = (t_end.tv_sec-t_start.tv_sec) + 
                    (t_end.tv_usec-t_start.tv_usec)/1000000.0;
    cout << "all time : " << delta_t  << "s" << endl;

    return 0;
}
