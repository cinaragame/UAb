/* programa_original.c */
#include <stdio.h>

/* Calcula a soma dos pares positivos */
int p(int *a, int n){
    int i, s = 0;
    for(i = 0; i < n; i++){
        if(a[i] > 0){
            if(a[i] % 2 == 0){
                s += a[i];
            }
        }
    }
    return s;
}

/* Imprime os valores do array */
int f(int *a, int n, int lim){
    int i, c = 0;
    for(i = 0; i < n; i++){
        if(a[i] > 0){
            if(a[i] <= lim){
                printf("%d ", a[i]);
                c++;
            }
        }
    }
    return c;
}

int main(){
    int v[] = {-3, 4, 7, 8, -1, 10, 2, 15};
    int r = p(v, 8);
    printf("Resultado: %d\n", r);
    int x = f(v, 8, 10);
    printf("Contagem: %d\n", x);
    return 0;
}
