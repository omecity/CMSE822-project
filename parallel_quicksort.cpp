#include <iostream>
#include <omp.h> 
#include <unistd.h>
#include <ctime>

int getLastIndex(int);
void fillArray(int [], int);
void printArray(int [], int);
void quicksort(int [], int, int);
int firstPartition(int [], int, int);
int lastPartition(int [], int, int);
int randomPartition(int [], int, int);
void swap(int [], int, int);


using namespace std;

// parallel_quicksort.cpp

int main(int argc, char *argv[]) {

    int option, arr_size;
    double start, end, time_elapsed;

    if (argc != 2){
        cout << "Usage: <executable name><array size>\n\n";
    }

    // read in the array size
    arr_size = atoi(argv[1]);
    int arr[arr_size];

    cout << " " << endl;
    
    start = omp_get_wtime();

    int pivot = randomPartition(arr, 0, arr_size-1);
    #pragma omp parallel sections
        {
        #pragma omp section
        {
            quicksort(arr, 0, pivot-1);  
        }
        #pragma omp section
        {
            quicksort(arr, pivot+1, arr_size-1);
        }
    }
    end = omp_get_wtime();
    time_elapsed = end - start;

    cout << "Time for parallel computation region: "<< time_elapsed << " seconds." << endl;

    cout << " ------------------------------------------------------ " << endl;

    cout << "  " << endl;    
    
  return 0;
}

int getFirstIndex(){      
   return 0;
}

int getLastIndex(int arr_size){      
   return arr_size-1;
}

void fillArray(int arr[], int arr_size){
    srand(time(0));
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand()%100;
}

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        cout << "The elements of the array arr["<<i<<"] = " << arr[i] << endl;
}

void quicksort(int arr[], int left, int right){
    int idx;
    if (left < right){
        int idx = randomPartition(arr,left,right);
        // sort the sub-arrays recursively
        quicksort(arr, left, idx-1);  
        quicksort(arr, idx+1, right);
    }
}

int firstPartition(int arr[], int start, int end){
    int i = start + 1;
    int pivot = arr[start];         
    for(int j = start + 1; j <= end; j++)  {
        if (arr[j] < pivot) {
            swap (arr,i,j);
            i = i + 1;
        }
    }
   // put the pivot element in its proper place.
   swap(arr,start,i-1);
   return i-1;                      
}

int lastPartition(int arr[], int start, int end){
    int pivot = arr[end]; 
    int i = (start-1);         
    for(int j = start; j <= end-1; j++)  {
        if (arr[j] < pivot){
            i = i + 1;
            swap (arr,i,j);
        }
    }
   // put the pivot element in its proper place.
   swap(arr,i+1,end);
   return (i+1);                      
}

int randomPartition(int arr[], int start, int end){
    int pivot, N;
    N = rand();     
    pivot = start + N%(end-start+1);       
   // put the pivot element in its proper place.
   swap(arr,end,pivot);
   return firstPartition(arr,start,end);                      
}

void swap(int arr[], int left, int right){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
} 