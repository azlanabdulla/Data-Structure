#include <stdio.h>
#include <stdlib.h>

struct HeapNode {
    int value;
    int ListIndex;
    int ElementIndex;
};

void Swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void HeapifyDown(struct HeapNode heap[], int n, int i) {
    int sm = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l].value < heap[sm].value) {
        sm = l;
    }
    if (r < n && heap[r].value < heap[sm].value) {
        sm = r;
    }
    if (sm != i) {
        Swap(&heap[i], &heap[sm]);
        HeapifyDown(heap, n, sm);
    }
}

void MergeSortLists(int lists[10][10], int size[], int k) {
    struct HeapNode heap[100];
    int heapsize = 0;

    for (int i = 0; i < k; i++) {
        if (size[i] > 0) {
            heap[heapsize].value = lists[i][0];
            heap[heapsize].ListIndex = i;
            heap[heapsize].ElementIndex = 0;
            heapsize++;
        }
    }

    for (int i = heapsize / 2 - 1; i >= 0; i--) {
        HeapifyDown(heap, heapsize, i);
    }

    printf("\nMerge Sorted List: ");
    while (heapsize > 0) {
        struct HeapNode root = heap[0];
        printf("%d ", root.value);

        int nextIndex = root.ElementIndex + 1;

        if (nextIndex < size[root.ListIndex]) {
            heap[0].value = lists[root.ListIndex][nextIndex];
            heap[0].ListIndex = root.ListIndex;
            heap[0].ElementIndex = nextIndex;
        } else {
            heap[0] = heap[heapsize - 1];
            heapsize--;
        }

        HeapifyDown(heap, heapsize, 0);
    }

    printf("\n");
}

int main() {
    int k;
    printf("Enter number of sorted lists: ");
    scanf("%d", &k);

    int lists[10][10];
    int size[10];

    for (int i = 0; i < k; i++) {
        printf("Enter the number of elements in List %d: ", i + 1);
        scanf("%d", &size[i]);
        printf("Enter %d sorted elements: ", size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &lists[i][j]);
        }
    }

    MergeSortLists(lists, size, k);

    return 0;
}
