#include <iostream>
#include <omp.h> 
#include <unistd.h>

using namespace std;


// parallel_quicksort.cpp


int main(int argc, char **argv) {


    cout << "Hello parallel world from all threads" << endl;  
    #pragma omp parallel
    {
        int rank, num_of_threads;
        num_of_threads = omp_get_num_threads();
        rank = omp_get_thread_num();
        usleep(5000 * rank);  // to avoid race condition when printing
        if (rank == 0){
            cout << "Greetings from process " << rank << " out of " << num_of_threads << " -- I am MASTER of all" << endl;  
        }
        else {
            cout << "Greetings from process " << rank << " out of " << num_of_threads << endl; 
        }
    }
    cout << "Back to the sequential world." << endl;  

    int option;
    cout << "  " << endl;
    cout << "Enter an integer between 1 and 4 to choose the pivot options you want : ";
    cout << " 1 -- first element ";
    cout << " 2 -- second element ";
    cout << " 3 -- random element ";
    cout << " 4 -- parallel prefix operation ";
    cin >> option;

  return 0;
}