#include <iostream>
#include <omp.h> 
using namespace std;


// parallel_quicksort.cpp


int main(int argc, char *argv[]) {

    // int id = omp_get_thread_num();
    int total = omp_get_num_threads();

    cout << "Hello parallel world from threads" << endl;  
    #pragma omp parallel num_threads(total)
    {
        int id = omp_get_thread_num();
        cout << "Greetings from process " << id << " out of the total " << total << endl;  
    }
    // omp end parallel
  return 0;
}