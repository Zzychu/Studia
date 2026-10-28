#include <stdio.h>
#define N 10
#define M 9

int pierwsza(int n){
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) { 
            return 0; 
        }
    }
    
    return 1;
}

int main()
{
    int counter = 0;
    
    int counter1 = 1;
    int cRow = 0;
    int cCol = 1; 
    
    
    
    int matrix[M][N];
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }
    
    
    
    while (1 == 1){
        
        for (int i = cRow; i <= N-counter1; i++){
            counter++;
            matrix[cRow][i] = counter;
        }
        
        if (counter >= M*N){
            break;
        }
        
        for (int i = cCol; i <= M-counter1; i++){
            counter++;
            matrix[i][N-cCol] = counter;
        }
        
        if (counter >= M*N){
            break;
        }
            
        counter1++;
        
        for (int i = N-counter1; i >= cRow; i--){
            counter++;
            matrix[M-cCol][i] = counter;
        }
        
        if (counter >= M*N){
            break;
        }
        
        for (int i = M-counter1; i >= cCol ; i--){
            counter++;
            matrix[i][cRow] = counter;
        }
        
        cRow++;
        cCol++;
        
        if (counter >= M*N){
            break;
        }
        

    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // printf("%i ", matrix[i][j]);
            if (pierwsza(matrix[i][j])) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    return 0;
}
