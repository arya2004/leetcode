#include <stdio.h>
#include <stdlib.h>

int mn() {
    int* arr = NULL;  // Initialize a pointer to int
    int size = 5;     // Initial size of the array

    // Allocate memory for the initial array
    arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    // Print the initial array
    printf("Initial Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory to increase the size of the array
    int newSize = 10;
    arr = (int*)realloc(arr, newSize * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    // Initialize the additional elements
    for (int i = size; i < newSize; i++) {
        arr[i] = i * 10;
    }

    // Print the resized array
    printf("Resized Array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
