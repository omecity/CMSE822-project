#include <iostream>
#include <omp.h> 
#include <unistd.h>

using namespace std;


// parallel_quicksort.cpp


int main(int argc, char *argv[]) {


    cout << "Hello parallel world from all threads" << endl;  
    #pragma omp parallel
    {
        int id, num_of_threads;
        num_of_threads = omp_get_num_threads();
        id = omp_get_thread_num();
        usleep(5000 * id);  // to avoid race condition when printing
        if (id == 0){
            cout << "Greetings from process " << id << " out of " << num_of_threads << " -- I am MASTER of all" << endl;  
        }
        else {
            cout << "Greetings from process " << id << " out of " << num_of_threads << endl; 
        }
    }
    cout << "Back to the sequential world." << endl;  

  return 0;
}