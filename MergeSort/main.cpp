/****************************
 *
 * Name: Devam Shah
 * Project Name: Merge Sort Recursive Algorithm
 * Date: 12/19/2022
 *
*****************************/
#include <iostream>
using namespace std;

void mergeArray(int arr[], int left, int middle, int right){
    int leftIndex = 0, rightIndex = 0, mergeIndex = left, leftLength = middle - left + 1, rightLength = right - middle;
    int leftArray[leftLength];
    int rightArray[rightLength];
    for(int i =0; i< leftLength; i++){
        leftArray[i] = arr[left+i];
    }
    for (int j=0; j< rightLength; j++) {
        rightArray[j] = arr[middle + 1 + j];
    }
    while ((leftIndex < leftLength) && (rightIndex < rightLength)){
        if (leftArray[leftIndex] <= rightArray[rightIndex]){
            arr[mergeIndex] = leftArray[leftIndex];
            leftIndex++;
        }else{
            arr[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }
    while(leftIndex < leftLength){
        arr[mergeIndex] = leftArray[leftIndex];
        leftIndex++;
        mergeIndex++;
    }
    while(rightIndex < rightLength){
        arr[mergeIndex] = rightArray[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
    return;
}

void sorter(int arr[], int left, int right){
    if (left < right){
        int middle = (left+right)/2;
        sorter(arr, left, middle);
        sorter(arr, middle+1, right);
        mergeArray(arr, left, middle, right);
    }
    return;
}

int main(){
    int arraySize, arrayValue;
    cout << "Enter the size of the array that you want to sort " << endl;
    cin >> arraySize;
    int givenArray[arraySize];
    cout << "Enter " << arraySize << " values followed by enter key" << endl;
    for(int i = 0; i<arraySize; i++){
        cout << "value " << i+1 << ": ";
        cin >> arrayValue;
        givenArray[i] = arrayValue;
    }
    cout << "Given array is ";
    for(int i = 0; i < arraySize; i++){
        cout << givenArray[i] << " ";
    }
    cout << endl;
    sorter(givenArray, 0, arraySize-1);
    cout << "Sorted array is ";
    for(int i = 0; i < arraySize; i++) {
        cout << givenArray[i] << " ";
    }
}
