#include <iostream>
#include <omp.h> 
#include <unistd.h>
#include <ctime>

// std::random_device random_device;
// std::mt19937 random_engine(random_device());

int getFirstIndex();
int getLastIndex(int);
int getRandomIndex(int);
void fillArray(int [], int);
void printArray(int [], int);
void quicksort(int [], int, int);
int partition(int [], int, int);
void swap (int [], int, int);


using namespace std;

// parallel_quicksort.cpp

int main(int argc, char *argv[]) {

    int option, arr_size;
    double start, end, time_elapsed;

    /*
    if (argc != 3){
        cout << "Usage: <executable name> <pivot choice [1, 2, 3, or 4]> <array size>\n\n";
    }
    */

    // read in the choice of pivot selection strategy and array size
    // option = atoi(argv[1]);
    // arr_size = atoi(argv[2]);

    int arr[11] = {5, 10, 2, 4, 3, 5, 8, 1, 12, 23, 15};
    // int arr[arr_size];
    int i;

    arr_size = 11;
    // fillArray(arr, arr_size);
    printArray(arr, arr_size);

    quicksort(arr, 0, 10);

    cout << " ===================================== " << endl;
    printArray(arr, arr_size);
    // testing the values 
    /*
    i = getFirstIndex();
    cout << "The first index and element is : " << i << " and " << arr[i]<< endl;

    i = getLastIndex(arr_size);
    cout << "The last index and element is : " << i << " and " << arr[i]<< endl;

    i = getRandomIndex(arr_size);
    cout << "The random index and element is : " << i << " and " << arr[i]<< endl;
    */

    cout << " " << endl;
    cout << "Hello parallel world from all threads" << endl; 

    // int max_threads = omp_set_num_threads(); 
    
    start = omp_get_wtime();
    #pragma omp parallel
    {
        int rank, nthreads;
        nthreads = omp_get_num_threads();
        rank = omp_get_thread_num();
        usleep(5000 * rank);        // to avoid race condition when printing
        if (rank == 0){
            cout << "Greetings from process " << rank << " out of " << nthreads << " -- I am MASTER of all " << endl;  
        }
        else {
            cout << "Greetings from process " << rank << " out of " << nthreads << endl; 
        }
    }
    end = omp_get_wtime();
    time_elapsed = end - start;

    // //print out the resulting elapsed time
    cout << "Time for parallel computation region: "<< time_elapsed << " seconds." << endl;
    cout << "Back to the sequential world." << endl;  

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

int getFirstIndex(){      
   return 0;
}

int getLastIndex(int arr_size){      
   return arr_size-1;
}

int getRandomIndex(int arr_size){      
    srand(time(0));
    return rand()%arr_size;
}

void fillArray(int arr[], int arr_size){
    srand(time(0));
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand()%arr_size;
}

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        cout << "The elements of the array arr["<<i<<"] = " << arr[i] << endl;
}

void quicksort(int arr[], int left, int right){
    if (left < right){
        int idx = partition(arr,left,right);
        // sort the sub-arrays recursively
        quicksort(arr, left, idx-1);
        quicksort(arr, idx+1, right);
    }
}

int partition(int arr[], int start, int end) {
    int i = start + 1;
    int pivot = arr[start] ;            
    for(int j = start + 1; j <= end; j++)  {
        if (arr[j] < pivot) {
                swap (arr,i,j);
            i = i + 1;
        }
    }
   // put the pivot element in its proper place.
   swap (arr,start,i-1);
   return i-1;                      
}

void swap(int arr[], int left, int right){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
} 