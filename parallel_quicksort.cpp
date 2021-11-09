#include <iostream>
#include <omp.h> 
using namespace std;


// parallel_quicksort.cpp


int main(int argc, char *argv[]) {

    int id, num_of_threads;
    // int total = omp_get_num_threads();

    cout << "Hello parallel world from threads" << endl;  
    #pragma omp parallel
    {
        num_of_threads = omp_get_num_threads();
        id = omp_get_thread_num();
        cout << "Greetings from process " << id << " out of " << total << endl;  
    }
    cout << "Back to the sequential world." << endl;  
    // omp end parallel
  return 0;
}