#include <iostream>
#include <omp.h> 
#include <unistd.h>

using namespace std;


// parallel_quicksort.cpp


int main(int argc, char *argv[]) {


    int id, num_of_threads;

    cout << "Hello parallel world from all threads" << endl;  
    #pragma omp parallel
    {
        num_of_threads = omp_get_num_threads();
        id = omp_get_thread_num();
        usleep(5000 * id);  // to avoid race condition when printing
        cout << "Greetings from process " << id << " out of " << num_of_threads << endl;  
    }
    cout << "Back to the sequential world." << endl;  

  return 0;
}