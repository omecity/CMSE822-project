#include <iostream>
#include <omp.h> 
#include <unistd.h>
#include <ctime>

// #include "parallel_quicksort.h"

int getFirstIndex();
int getLastIndex();
int getRandomIndex();                                                      
void fillArray();
void printArray();

using namespace std;

// parallel_quicksort.cpp

int main(int argc, char *argv[]) {

    int option, arr_size;
    double start, end, time_elapsed;

    if (argc != 3){
        cout << "Please enter a positive integer for option and array size " << endl; 
    }

    option = atoi(argv[1]);
    arr_size = atoi(argv[2]);

    int arr[arr_size];

    cout << " " << endl;
    cout << "Hello parallel world from all threads" << endl;  
    
    start = omp_get_wtime();
    #pragma omp parallel
    {
        int rank, num_of_threads;
        // start = omp_get_wtime(); 
        num_of_threads = omp_get_num_threads();
        rank = omp_get_thread_num();
        usleep(5000 * rank);  // to avoid race condition when printing
        if (rank == 0){
            cout << "Greetings from process " << rank << " out of " << num_of_threads << " -- I am MASTER of all " << endl;  
        }
        else {
            cout << "Greetings from process " << rank << " out of " << num_of_threads << endl; 
        }
        // end = omp_get_wtime();
        // time_elapsed = end - start;

        //print out the resulting elapsed time
        // cout << "Time for parallel computation region : "<< time_elapsed << " seconds." << endl;
        // cout << "Back to the sequential world." << endl;
    }
    end = omp_get_wtime();
    time_elapsed = end - start;

    // //print out the resulting elapsed time
    cout << "Time for parallel computation region: "<< time_elapsed << " seconds." << endl;
    cout << "Back to the sequential world." << endl;  

    // getFirstElement();
    // getLastElement();

    // int option, index, arr_size;
    cout << "  " << endl;    
    cout << "The pivot options are as copied below: " << endl;

    // cout << "       1 -- first element " << endl;
    // cout << "       2 -- last element " << endl;
    // cout << "       3 -- random element " << endl;
    // cout << "       4 -- parallel prefix operation " << endl;

    // cout << "Enter an integer between 1 and 4 to choose the pivot options you want : " ;
    // cin >> option;
    
    // If (option == 1){
    //     index = getFirstElement(arr);
    // }
    // else if (option == 2){
    //     index = getLastElement(arr);
    // }
    // else if (option == 3){
    //     index = getRandomElement(arr);
    // }
    // else{
    //     index = getPrefixElement(arr);
    // }

  return 0;
}

// print the elements of the array
// std::cout << "arr: ";
// std::copy(arr.begin(),arr.end(), std::ostream_iterator<int>(std::cout, ","));
// cout << "This is the first element" << endl;
// cout << "This is the first element" << endl;
// cout << "This is the first element" << endl;

int getFirstIndex(){      
   cout << "This is the first element" << endl;
   return 0;
}

int getLastIndex(){      
   // cout << "This is the last element" << endl;
   return 0;
}

int getRandomIndex(){      
   cout << "This is the random element" << endl;
   return 0;
}

void fillArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand()%arr_size;
}

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        cout << "The elements of the array is/are " << arr[i] << endl;
}