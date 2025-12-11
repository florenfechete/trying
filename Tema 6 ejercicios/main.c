#include <stdio.h>

void traductor (char pal[]);

int main(void) {
    // Ejercicio 9 Matrices

        int N;
        int M;

    // Se pide el tamaño de la matriz
        printf("Introduce FILAS: ");
        scanf("%d",&N);
        printf("Introduce COLUMNAS: ");
        scanf("%d",&M);

        int matriz[N][M];

    // Se rellena la matriz de valores
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                printf("Introduce el valor para la celda [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
            }
        }


        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                int max_fila = 1;
                for (int k=0; k<M; k++){
                    if (matriz[i][k] > matriz[i][j]) {
                        max_fila = 0;
                        break;
                    }
                }
                int min_columna = 1;
                for (int l=0; l<N; l++){
                    if (matriz[l][j] < matriz[i][j]) {
                        min_columna = 0;
                        break;
                    }
                }
                if (max_fila == 1 && min_columna == 1) {
                    printf("Posicion [%d][%d] con valor %d\n", i , j , matriz[i][j]);
                }
            }
        }





    // Ejercicio 11 Strings

    char cadena[] = "E s t o   t i e n e   e s p a c i o s";
    int i = 0;
    int j= 0;

    for (i ; cadena[i] != '\0' ; i++) {
        if (cadena[i] != ' ') {
            cadena[j]=cadena[i];
            j++;
        }
    }
    cadena[j]= '\0';

    printf("Cadena sin espacios: %s\n", cadena);




    // Ejercicio 12

    char pal1 [11];
    char pal2 [11];
    char pal3 [11];
    char pal4 [11];


    printf("Bienvenido al traductor al latin!!\n\n");


    printf("Introduce palabra 1: ");
    scanf("%s", pal1);
    printf("Introduce palabra 2: ");
    scanf("%s", pal2);
    printf("Introduce palabra 3: ");
    scanf("%s", pal3);
    printf("Introduce palabra 4: ");
    scanf("%s", pal4);

    traductor(pal1);
    traductor(pal2);
    traductor(pal3);
    traductor(pal4);

    printf("Frase en latin: %s %s %s %s\n", pal1, pal2, pal3, pal4);




}







void traductor (char pal[]) {
    int l = 0;
    char latin [] = "us";
    char vocales[]="aeiou";

    for ( l ; pal[l] != '\0' ; l++);
    // l llega al caracter nulo, la última letra será l-1

    int es_vocal = 0;


    for ( int j = 0; vocales[j] != '\0'; j++) {
        // Compara la vocal actual (vocales[j]) con la última letra (pal[l-1])
        if (vocales[j] == pal[l-1] ) {
            es_vocal = 1;
        }
        if (es_vocal == 1) {
            pal[l-1] = latin[0];
            pal[l] = latin[1];
            pal[l+1] = '\0';
        } else {
            pal[l] = latin[0];
            pal[l+1] = latin[1];
            pal[l+2] = '\0';
        }
    }
}
