#include <stdio.h>

// merge two array after sorting them
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int l[n1], r[n2];

  for(int i = 0; i < n1; ++i) {
    l[i] = arr[left + i];
  }
  for(int j = 0; j < n2; ++j) {
    r[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;

  while(i < n1 && j < n2) {
    if(l[i] <= r[j]) {
      arr[k++] = l[i++];
    } else {
      arr[k++] = r[j++];
    }
  }

  while(i < n1) arr[k++] = l[i++];
  while(j < n2) arr[k++] = r[j++];
}

void mergeSort(int arr[], int left, int right) {
  if(left < right) {
    int mid = left + (right - left) / 2;

    // sort left array
    mergeSort(arr, left, mid);
    // sort right array
    mergeSort(arr, mid + 1, right);
    // merge
    merge(arr, left, mid, right);
  }
}

int main() {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n-1);

  printf("Sorted array: ");
  for(int i = 0; i < n; i++) printf("%d ", arr[i]);
  return 0;
}
