#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>

using namespace std;

void* thread_params(void* arg)
{
    std::vector<int>* nums;
    nums = (std::vector<int>*)arg;
    for(int i = 0; i < nums->size(); ++i)
        cout << (*nums)[i] << endl;
    sleep(2);
}


// the two thread will run at random order(simutaneously).
int main()
{
    cout << "pthread create test" << endl;

    int ret = 0;
    pthread_t th_id_1;

    std::vector<int> nums = {1,2,3,10};

    ret = pthread_create( &th_id_1, NULL, thread_params, (void*)&nums );
    if( ret )
    {
        cout << "create thread 1 failed..." << endl;
        return -1;
    }

    // wait for thread end, else the program
    // will exit directory
    pthread_join( th_id_1, NULL );

    return 0;
}
