#include <stdio.h>
#include <stdlib.h>

#define kMaxSize 1000000

void Merge(int arr[], int left, int mid, int right, int temp[]) {
  int i = left;    //for first half
  int j = mid + 1; //for second half
  int k = left;    //new temp index k, which start at left

  while (i <= mid && j <= right) {  //compare and put the small data in temp.
    if (arr[i] <= arr[j]) {       //if i(first half)< j(sec half)
      temp[k++] = arr[i++];      //put i in temp, and move i to next element
    } else {
      temp[k++] = arr[j++];       //else if j <i
                                // put j in temp, and move j to next element
    }
  }
5
  while (i <= mid) { //if left(first half) < mid
    temp[k++] = arr[i++]; // then, put i in temp, move i to next element
  }

  while (j <= right) { // if j(sec half) < right
    temp[k++] = arr[j++];  //then, put j in temp, move j to next element
  }

  for (i = left; i <= right; i++) {
    arr[i] = temp[i]; //copy back all in temp to arr
  }
}

void MergeSortRecursive(int arr[], int left, int right, int temp[]) {
  if (left < right) {   //if right data bigger than left
    int mid = (left + right) / 2;  //divide array by 2 

    MergeSortRecursive(arr, left, mid, temp);  // sort for left, keep divide half
    MergeSortRecursive(arr, mid + 1, right, temp); //sort for right

    Merge(arr, left, mid, right, temp);  // go to merge to compare, call merge again and compare
  }
}

void MergeSort(int arr[], int n) {    
  int* temp = (int*)malloc(n * sizeof(int));
  if (temp == NULL) {                       //check memory allocation
    printf("Memory allocation failed\n"); 
    return;
  }

  MergeSortRecursive(arr, 0, n - 1, temp); // if ok, go to mergerecursive
  // arr, start index(left), end index(right), temp

  free(temp);
}

int main() {
  int n;
  scanf("%d", &n);  // enter size of array

  int* arr = (int*)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);  // enter array data use for
  }

  MergeSort(arr, n);   //merge data 

  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);   //print the sorted data
  }

  free(arr);
  return 0;
}