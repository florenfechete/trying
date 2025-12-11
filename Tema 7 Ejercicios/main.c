#include <stdio.h>

// -------------------- Ejercicio 20 --------------------- //

enum revelado {digital , tradicional};
enum papel { mate, brillo, satinado};
typedef struct {
    int dia;
    int mes;
    int an;
} fechas;
typedef struct {

    int numsolicitud;
    char nombre[105];
    char apellidos[105];
    int tfno;
    enum revelado tippo;
    enum papel tipo;
    fechas entrega;
    fechas enviolab;
    fechas vuelta;
    int numfotos;

}Solicituddata ;

// -------------------- ------------ ---------------------- //


// -------------------- Ejercicio 21 --------------------- //

typedef struct {
    float nota[3]; // Guardamos 3 notas de un único curso ( las notas de un alumno )
}Notasindividuales;

typedef struct { // Ficha del alumno
    int DNI;
    char nombre[250];
    char direccion[250];
    Notasindividuales notas_entrada[3]; // [Curso 1] tres notas, [Curso 2] tres notas...
}Aludata;

void leeralumnos (Aludata lista[]);
float calcular_media_curso(Aludata alumno, int curso_elegido );

int main(void) {
    // Ejercicio 20

    Aludata matriculas[30]; // Numero máximo de fichas de alumnos (arbitrario)
    int curso_elegido ;
    float mediacurso_1;
    leeralumnos (matriculas);

    // Comprobamos que los datos han sido guardados correctamente
    printf("\n\n--- DATOS ALUMNO LEiDO ---\n");
    printf("Nombre: %s\n", matriculas[0].nombre);
    printf("DNI: %d\n", matriculas[0].DNI);
    printf("Direccion: %s\n", matriculas[0].direccion);
    printf("--------------------------\n");

    // Guardamos la media del curso

    printf("Introduce el curso que quieres consultar: ");
    scanf("%d", &curso_elegido);

    mediacurso_1= calcular_media_curso(matriculas[0], curso_elegido - 1);
    printf("La media de tu %d curso es: %.2f",curso_elegido, mediacurso_1 );


    return 0;
}

void leeralumnos (Aludata lista[]) {
    int numalumnos = 1; // Suponemos X alumnos

    for (int i=0; i < numalumnos ; i++) {
        printf("\nNombre alumno : ");
        scanf("%s", lista[i].nombre);
        printf("\nDNI alumno (sin letra): ");
        scanf("%d", &lista[i].DNI);
        printf("\nDireccion alumno : ");
        scanf("%s", lista[i].direccion);


        for (int j=0; j<3 ; j++) { // Bucle para los 3 cursos
            printf("\n----------Notas Curso %d----------",j+1);

            for (int k = 0; k<3 ; k++) { // Bucle para las 3 notas de cada curso
                printf("\nNota %d del curso: ", k+1);
                scanf("%f", &lista[i].notas_entrada[j].nota[k]);
            }
        }
    }
}
float calcular_media_curso(Aludata alumno, int curso_elegido ) {
    float media = 0;

    for (int k=0; k < 3 ; k++) { // Bucle para sumar las tres notas del curso elegido
        media += alumno.notas_entrada[curso_elegido].nota[k];
    }

    media /= 3;

    return media;
}