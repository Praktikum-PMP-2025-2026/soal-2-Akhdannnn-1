#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[100];
    int massa;
    int kemurnian;
} meteorit;

void swap(meteorit *a, meteorit *b) {
    meteorit temp = *a;
    *a = *b;
    *b = temp;
}

int pembanding(const meteorit *a, const meteorit *b) {
    const meteorit *m1 = (const meteorit *)a;
    const meteorit *m2 = (const meteorit *)b;

    if (m1->kemurnian != m2->kemurnian)
        return m2->kemurnian - m1->kemurnian;

    if (m1->massa != m2->massa)
        return m1->massa - m2->massa;

    return strcmp(m1->nama, m2->nama);
}

void quickSort(meteorit arr[], int low, int high, int (*cmp)(const meteorit*, const meteorit*)) {
    if (low < high) {
        meteorit pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (cmp(&arr[j], &pivot) <= 0) { 
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int pi = i + 1;

        quickSort(arr, low, pi - 1, cmp);
        quickSort(arr, pi + 1, high, cmp);
    }
}

int main() {
    int n;
    meteorit meteor[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%100s %d %d", meteor[i].nama, &meteor[i].massa, &meteor[i].kemurnian);
    }

    quickSort(meteor, 0, sizeof(meteorit), pembanding);
    

    if (n <= 3) {
        for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", meteor[i].nama, meteor[i].massa, meteor[i].kemurnian);
        }
    }
    else if (n > 3) {
        for (int i = 0; i < 3; i++) {
        printf("%s %d %d\n", meteor[i].nama, meteor[i].massa, meteor[i].kemurnian);
        }
    }

    return 0;
}
