#include <stdio.h>


/*
 *
1 - Escribe una función que lea e imprima los datos de una matriz de dos dimensiones
de un tamaño fijo nxm. Tanto la lectura como la escritura se deben hacer con funciones.
La función de lectura debe ir pidiendo los datos de cada fila.

2 - Basándonos en el programa anterior, haz un programa que lea dos matrices de enteros,
las sume, y muestre el resultado. El tamaño máximo de cada matriz ha de ser 20.

3 - Escribe un programa que reciba dos matrices de números en coma flotante, y devuelva su multiplicación.
Para ello, ha de comprobar primero que las matrices son compatibles, es decir, que el número de columnas
de la primera es igual al número de columnas de la segunda.

4 - Crea una función que dada una matriz de nxm devuelva un vector de tamaño n donde estén
los valores mínimos de cada una de las columnas.

5 - Crea un subprograma que almacene en un vector la suma de cada una de las columnas de una
matriz.

6 - Escribe un programa que lea una matriz e imprima su traspuesta.
Usar también un tamaño máximo de 20 filas y columnas.

7 - Escribe una función que dada una matriz de a[n][m] devuelva la suma de todos sus elementos
menos los de la diagonal principal

8 - Crea una función que obtenga la suma de los elementos de las diagonales de una matriz.

10 - Se tiene una secuencia de longitud indeterminada acabada en punto, formada únicamente por
letras minúsculas. Se pide un programa que determine todas las parejas de letras que aparecen,
diga cuáles son y cuántas hay. La salida debe producirse en orden alfabético
 */



void leer (int F, int C, float dosd[F][C]);

void imprimir (int F, int C ,float dosd[F][C]);

void suma(int F, int C, float dosd[F][C], float dosd_2[F][C], float result[F][C]);

void mult(int F, int C, float dosd[F][C],int F1, int C1, float dosd_2[F1][C1], float multresult[F][C1]);

void min(int F, int C, float dosd[F][C], float vecmin[C]);

void imprimirmin(int C, float vecmin[C]);

void sumacolumnas(int F, int C, float dosd[F][C], float vecsumcolum[C]);

void traspuesta( int F, int C, float dosd[F][C], float trasp[C][F]);

float nodiago(int F, int C, float dosd[F][C]);

float sidiago(int F, int C, float dosd[F][C]);

void parejas(char secuencia[]);



int main(void) {
    ////////////////////////////Matrices////////////////////////////////////////////////
    int F,F1;
    int C,C1;


    printf("Introduce numero de filas F: ");
    scanf("%d", &F);
    printf("Introduce numero de columnas C: ");
    scanf("%d", &C);
    printf("Introduce numero de filas F1: ");
    scanf("%d", &F1);
    printf("Introduce numero de columnas C1: ");
    scanf("%d", &C1);

    float dosd[F][C], dosd_2[F1][C1], result[F][C], multresult[F][C1], trasp[C][F];
    float vecmin[C], vecsumcolum[C];
    float sumnodiago, sumsidiago;

    printf("--- Lectura de Matriz A (%d x %d) ---\n", F, C);
    leer (F, C, dosd);


    printf("--- Lectura de Matriz B (%d x %d) ---\n", F1, C1);
    leer (F1, C1, dosd_2);


    printf("----- Matriz A  -----\n");
    imprimir (F, C, dosd);
    printf ("\n");


    printf("----- Matriz B  -----\n");
    imprimir (F1, C1, dosd_2);
    printf ("\n");


    printf("--- Suma de Matrices A y B ---\n");
    if (F == F1 && C == C1) {
        suma (F, C, dosd, dosd_2, result);
        imprimir(F, C, result);
    } else printf("No son compatibles y no se puede sumar.\n");


    printf("\n--- Multiplicacion de Matrices A y B ---\n");
    if (C == F1) {
        mult (F, C, dosd,F1, C1, dosd_2, multresult);
        imprimir(F, C1, multresult);
    } else printf("No son compatibles y no se puede multiplicar.\n");


    printf("\n\n--- Valores Minimos Columna Matriz A ---\n");
    min (F, C, dosd, vecmin);
    imprimirmin (C, vecmin);


    printf("\n\n--- Suma Valores Columna Matriz A ---\n");
    sumacolumnas(F, C, dosd, vecsumcolum);
    imprimirmin(C, vecsumcolum);


    printf("\n\n--- Matriz A TRASPUESTA ---\n");
    traspuesta(F, C, dosd, trasp);
    imprimir(C, F, trasp);


    printf("\n\n--- Suma SIN diagonal principal ---\n");
    sumnodiago = nodiago(F, C, dosd);
    printf("%f", sumnodiago);

    printf("\n\n--- Suma SOLO diagonal principal ---\n");
    sumsidiago = sidiago(F, C, dosd);
    printf("%f", sumsidiago);

    printf("\n\n");

/////////////////////////////////////Strings-Matrices///////////////////////////////////////////////////////
    printf("\n Seccion Strings-Matrices/\n");
    // Lectura de la cadena de caracteres y break cuando se pone punto
    char secuencia[105];
    int i = 0;
    char leer;

    printf("\n\nIntroduce secuencia de letras y acaba en punto: ");
    for ( i; i < 105; i++) {
        if (scanf(" %c", &leer) != 1) {
            break;
        }
        if (leer == '.') {
            break;
        }
        secuencia[i] = leer ;
    }
    secuencia[i] = '\0';

    parejas(secuencia);

    return 0;

}




void leer(int F, int C ,float dosd[F][C]) {
    for (int i=0; i < F ; i++) {
        for (int j=0; j < C ; j++) {
            printf ("\nIntroduce valores: ");
            scanf("%f", &dosd[i][j]);
        }
    }
}

void imprimir (int F, int C ,float dosd[F][C]) {
    for (int i=0; i < F; i++) {
        for (int j=0; j < C ; j++) {
            printf ("\t%.2f\t", dosd[i][j]);
        }
        printf ("\n");
    }

}

void suma(int F, int C, float dosd[F][C], float dosd_2[F][C], float result[F][C]) {
    for (int i=0; i < F; i++) {
        for (int j=0; j < C ; j++) {
        result[i][j] = dosd[i][j] + dosd_2[i][j];
        }
    }


}

void mult(int F, int C, float dosd[F][C],int F1, int C1, float dosd_2[F1][C1], float multresult[F][C1]) {
    for (int i=0; i < F; i++) {
        for (int j=0; j < C1 ; j++) {
            multresult[i][j] = 0.0f;
            for (int k = 0; k < C; k++) {
                multresult[i][j] += dosd[i][k] * dosd_2[k][j];
            }
        }
    }
}

void min(int F, int C, float dosd[F][C], float vecmin[C]) {
    for (int j=0; j < C; j++) {
        vecmin[j] = dosd[0][j];
        for (int i=1; i < F ; i++) {
            if (dosd[i][j] < vecmin[j]) {
                                vecmin[j] = dosd[i][j];
            }
        }
    }
}

void imprimirmin(int C, float vecmin[C]) {
    for (int j=0; j < C ; j++) {
        printf ("%.2f", vecmin[j]);
        if (j < C - 1) {printf(", ");
        }
    }
}

void sumacolumnas(int F, int C, float dosd[F][C], float vecsumcolum[C]) {
    for (int j=0; j < C; j++) {
        vecsumcolum[j] = 0;
        for (int i=0; i < F ; i++) {
            vecsumcolum[j]+=dosd[i][j];
        }
    }
}

void traspuesta( int F, int C, float dosd[F][C], float trasp[C][F]) {
    for (int j=0; j < C; j++) {
        for (int i=0; i < F ; i++) {
            trasp[j][i]= dosd[i][j];
        }
    }
}
float nodiago(int F, int C, float dosd[F][C]) {
    float nodiago = 0;
    for (int j=0; j < C; j++) {
        for (int i=0; i < F ; i++) {
            if (i != j)
                nodiago += dosd[i][j];
        }
    }
    return nodiago;
}



float sidiago(int F, int C, float dosd[F][C]) {
                    float sidiago = 0;
                    for (int j=0; j < C; j++) {
                        for (int i=0; i < F ; i++) {
                            if (i == j) {
                                sidiago += dosd[i][j];
                            }
                        }
                    }
                    return sidiago;
                }

void parejas(char secuencia[]) {
    int numparejas [26][26] = {0};
    int totalparejas = 0;

    for (int i = 0; secuencia [i] != '\0' && secuencia [i+1] != '\0' ; i++) {
        char letra1 = secuencia[i];
        char letra2 = secuencia[i+1];

        // Pista 1: Calcula los índices (0 a 25)
        int indice_fila = letra1 - 'a';
        int indice_columna = letra2 - 'a';

        // Pista 2: Incrementa el contador de esta pareja específica
        numparejas[indice_fila][indice_columna]++;

        totalparejas++; // Esta línea es opcional pero útil para verificar la longitud
        }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {

            // Pista: Si la frecuencia en [i][j] es mayor a 0, imprima
            if (numparejas[i][j] > 0) {
                // 1. Convertir los índices 'i' y 'j' de vuelta a char
                char letra1 = i + 'a' ;
                char letra2 = j + 'a' ;
                int frecuencia = numparejas[i][j];

                // 2. Imprimir la pareja y la frecuencia
                // (puedes usar el formato que te mostré con el valor ASCII si quieres)
                printf("Pareja '%c%c': aparece %d vez(es)\n", letra1, letra2, frecuencia);
            }
        }
    }
}