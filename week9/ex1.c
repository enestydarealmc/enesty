#include<stdio.h>
#include<limits.h>
#include<string.h>

int search(const int *ptr, int N, int value) {
    for (int i = 0; i < N; i++) {
        if (ptr[i] == value)
            return i;

    }
    return -1;
}

int min(const unsigned int *ptr, int N) {
    int min = ptr[0];
    int minIndex = 0;
    for (int i = 1; i < N; i++) {
        if (ptr[i] < min) {
            min = ptr[i];
            minIndex = i;
        }
    }
    return minIndex;
}


int main() {
    FILE *file = fopen("ex1 input.txt", "r");
    int ptr[100000];
    int i = 0;
    while (fscanf(file, "%d", &ptr[i]) == 1) {
        i++;
    }
    int n = i;
    int NumFrame;
    printf("Input the number of frames: ");
    scanf("%d", &NumFrame);
    int miss = 0, frame[NumFrame];
    unsigned int age[NumFrame];
    memset(age,0,NumFrame*sizeof(int));
    memset(frame,0,NumFrame*sizeof(int));
    for (i = 0; i < n; i++) {
        int found = search(frame, NumFrame, ptr[i]);
        if (found != -1) {
            for(int k = 0 ; k < NumFrame ; k ++) age[k] = age[k] >> 1u;
            age[found] = age[found] | 1u << (sizeof(unsigned int) * 8 - 1);
            continue;
        } else {
            miss++;
            found = search(frame, NumFrame, 0);
            if (found != -1) {
                frame[found] = ptr[i];
                for(int k = 0 ; k < NumFrame ; k ++) age[k] = age[k] >> 1u;
                age[found] = INT_MAX;
            } else {
                int min_index = min(age, NumFrame);
                frame[min_index] = ptr[i];
                for(int k = 0 ; k < NumFrame ; k ++) age[k] = age[k] >> 1u;
                age[min_index] = INT_MAX;
            }
        }
    }
    printf("MISS: %d", miss);
}

