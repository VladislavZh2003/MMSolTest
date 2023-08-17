#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Row {
    int rowNum;
    int M; 
    int *number;
    double res;
} Row;

void *trFunc(void *argv) {

    Row *row = (Row*) argv;

    int sumNum = 0;
    
    for (int i = 0; i < row->M; i++) {
        sumNum += row->number[i];
    }
    row->res = (double)sumNum / row->M;

    return row;
}

int main() {

    int num, M;
    scanf("%d %d", &num, &M);

    int i, j;

    Row rows[num];
    for(i = 0; i < num; i++) {
        char temp[4];
        scanf("%s %d", temp, &(rows[i].rowNum));
        rows[i].number = (int *) malloc(M * sizeof(int));
        rows[i].M = M;
        for(j = 0; j < M; j++) {
            scanf("%d", &(rows[i].number[j]));
        }
    }

    char file_name[30];
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "r");
    if(file) {

        printf("File occured.\n");
        exit(-1);
    }

    pthread_t threads[num];

    for (int i = 0; i < num; i++) {
        pthread_create(&threads[i], NULL, trFunc, &rows[i]);
        pthread_join(threads[i], NULL);
    }
    
    file = fopen(file_name, "w");
    for (int i = 0; i < num; i++) {
        fprintf(file, "ROW %d %lf\n", rows[i].rowNum, rows[i].res);
        free(rows[i].number);
    }
    fclose(file);
    
    return 0;
}
