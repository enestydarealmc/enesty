#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool fit(int *M, int *N, int m) { //return false if vector M exceeds vector N and vice versa.
    for (int i = 0; i < m; i++) {
        if (*(M + i) > *(N + i)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./ex1 filename");
        exit(-1);
    }
    printf("Input number of processes: ");
    unsigned int P, T;
    scanf("%d", &P);
    printf("Input number of types of resources: ");
    scanf("%d", &T);

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Something went wrong while opening input");
        exit(-1);
    }

    int E[T], A[T], C[P][T], R[P][T];
    //E : Numbers of instances each type of resource has.
    //A : Numbers of instances available for each type of resource.
    //C : Currently allocated instances of each resource type.
    //R : Numbers of instances of each resource type in request.

    for (int i = 0; i < T; i++) {
        if (fscanf(input, "%d", E + i) != 1) {
            printf("Something went wrong while reading E");
            exit(-1);
        }
    }

    for (int i = 0; i < T; i++) {
        if (fscanf(input, "%d", A + i) != 1) {
            printf("Something went wrong while reading A");
            exit(-1);
        }
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < T; j++) {
            if (fscanf(input, "%d", &C[i][j]) != 1) {
                printf("Something went wrong while reading C");
                exit(-1);
            }
        }
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < T; j++) {
            if (fscanf(input, "%d", &R[i][j]) != 1) {
                printf("Something went wrong while reading R");
                exit(-1);
            }
        }
    }

    int A_new[T], finished = 0, finished_old = 0;
    bool F[P];
    //F: finish state of each process
    //A_new : new available resource after each iteration
    //finished: number of finished processes

    for (int i = 0; i < T; i++) {
        A_new[i] = A[i];
    }

    for (int i = 0; i < P; i++) {
        F[P] = false;
    }

    do {
        finished_old = finished;
        for (int i = 0; i < P; i++) {
            if (fit((int *) (R + i), A_new, T) && F[i] == false) {
                finished++;
                F[i] = true;
                for (int j = 0; j < T; j++) {
                    A_new[j] += C[i][j];
                }
            }
        }
    } while (finished_old != finished && finished != P);

    FILE *output;
    if (finished == P) {
        output = fopen("output_ok.txt", "w");
        if (output == NULL) {
            printf("Something went wrong while opening output");
            fclose(input);
            exit(-1);
        }
        fprintf(output, "No deadlock detected");
    } else {
        output = fopen("output_dl.txt", "w");
        if (output == NULL) {
            printf("Something went wrong while opening output");
            fclose(input);
            exit(-1);
        }
        fprintf(output, "There are %d deadlock processes: ", P - finished);
	for(int i = 0 ; i < P; i++){
		if(F[i] == false)
			fprintf(output, "P%d ", i);
	}
    }
    fclose(input);
    fclose(output);
    return 0;
}
