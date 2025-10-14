#include <stdio.h>

typedef struct {
    int value;
    int col;
    int row;
} term;

int Readmat(term mat[]) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the matrix (row col value):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
    }
    return n;
}

void Display(term mat[], int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        if (mat[i].value != 0) {
            printf("%d %d %d\n", mat[i].row, mat[i].col, mat[i].value);
        }
    }
}

int Add(term a[], int na, term b[], int nb, term sum[]) {
    int i = 0, j = 0, k = 0, total;
    while (i < na && j < nb) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            total = a[i].value + b[j].value;
            if (total != 0) {
                sum[k].row = a[i].row;
                sum[k].col = a[i].col;
                sum[k].value = total;
                k++;
            }
            i++; j++;
        } else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            sum[k++] = a[i++];
        } else {
            sum[k++] = b[j++];
        }
    }

    while (i < na) sum[k++] = a[i++];
    while (j < nb) sum[k++] = b[j++];

    return k;
}

int main() {
    term a[100], b[100], sum[200];
    int na, nb, ns;

    printf("Enter Matrix A:\n");
    na = Readmat(a);

    printf("\nEnter Matrix B:\n");
    nb = Readmat(b);

    ns = Add(a, na, b, nb, sum);

    printf("\nSum Matrix:\n");
    Display(sum, ns);

    return 0;
}