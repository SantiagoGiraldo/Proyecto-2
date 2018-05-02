#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define reservar (Nodo *)malloc(sizeof(Nodo))

// Estructura principal para la pila y la cola.
struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu(); // Menu Principal

void menuPila();
void generarNumerosAleatoriosPila(Nodo *&); // Genera X cantidad de elementos a la pila.
void insertarElementosPila(Nodo *&, int); // Inserta los elementos generados a la pila.
void imprimirPila(Nodo *); // Imprime los elementos de la cola.
void ordenarElementosPila_Burbuja(Nodo *); // Metodo de ordenamiento por burbuja.

void menuCola();
void generarNumerosAleatoriosCola(Nodo *&, Nodo *&); // Genera X cantidad de elementos a la cola.
void insertarElementosCola(Nodo *&, Nodo *&, int); // Inserta los elementos generados a la cola.
void imprimirCola(Nodo *); // Imprime los elementos de la cola.
void ordenarElementosCola_Burbuja(Nodo *); // Metodo de ordenamiento por burbuja.

void menuPunto2();
void generarNumerosAleatorios(); // Genera X cantidad de elementos y los inserta.
void imprimir(); // Imprime los elementos.
void ordenarElementos_Burbuja(); // Metodo de ordenamiento por burbuja.

int main(){
    menu();
    return 0;
}

int iniciar, finalizar; // Variables globales para capturar el tiempo de inicio y fin para cada seccion dentro del programa. EJ: Imprimir Pila se demoro 5 segundos.

void menu(){
    int opcionMenu = 0;
    do{
        printf("\n|-----------------------------------------------|");
        printf("\n|                        |                      |");
        printf("\n| 1. Menu Pilas          | 2. Menu Colas        |");
        printf("\n| 3. Punto 2             |                      |");
        printf("\n|                        | 0. Cerrar Programa   |");
        printf("\n|                        |                      |");
        printf("\n|------------------------|----------------------|");
        printf("\n\nEscoja una opcion: ");
        scanf("%d", &opcionMenu);
        switch(opcionMenu){
            case 1:
                system("cls");
                menuPila();
                break;
            case 2:
                system("cls");
                menuCola();
                break;
            case 3:
                system("cls");
                menuPunto2();
                break;
            case 0:
                system("cls");
                exit(0);
                break;
            default:
               system("cls");
               printf("\n          La opcion que ha introducido no es valida. \n");
        }
    }while(opcionMenu != 0);
}

void menuPila(){
    Nodo *cabeza = NULL;
    int opcionMenu = 0;
    do{
        printf("\n|-----------------------------------------------|");
        printf("\n|------------------------|----------------------|");
        printf("\n|                        |                      |");
        printf("\n| 1. Generar numeros     | 2. Imprimir Pila     |");
        printf("\n| 3. Ordenar con Burbuja |                      |");
        printf("\n|                        |                      |");
        printf("\n|                        | 0. CERRAR            |");
        printf("\n|                        |                      |");
        printf("\n|------------------------|----------------------|");
        printf("\n|-----------------------------------------------|");
        printf("\n\nEscoja una opcion: ");
        scanf("%d", &opcionMenu);
        switch(opcionMenu){
            case 1:
                system("cls");
                iniciar = clock();
                generarNumerosAleatoriosPila(cabeza);
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 2:
                system("cls");
                iniciar = clock();
                imprimirPila(cabeza);
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 3:
                system("cls");
                iniciar = clock();
                ordenarElementosPila_Burbuja(cabeza);
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 0:
                system("cls");
                break;
            default:
               system("cls");
               printf("\n          La opcion que ha introducido no es valida \n");
        }
    }while(opcionMenu != 0);
}
void generarNumerosAleatoriosPila(Nodo *&cabeza){
    int num, nDatos, i = 0;
	printf("Ingrese cantidad de datos: ");
	scanf("%d", &nDatos);
	srand(time(NULL));
	while(i < nDatos){
		num = (rand() % 99999) + 1;
		insertarElementosPila(cabeza, num);
		i += 1;
	}
}
void insertarElementosPila(Nodo *&cabeza, int n){
    Nodo *nuevo = reservar;
	nuevo -> dato = n;
	nuevo -> siguiente = NULL;
	nuevo->siguiente = cabeza;
    cabeza = nuevo;
}
void imprimirPila(Nodo *cabeza){
    Nodo *actual = reservar;
    actual = cabeza;
    if(cabeza != NULL){
        while(actual != NULL){
            printf(" %d |", actual -> dato);
            actual = actual -> siguiente;
        }
    }else{
        printf("\nLa pila se encuentra sin informacion\n");
    }
}
void ordenarElementosPila_Burbuja(Nodo *cabeza){
    if(cabeza != NULL){
		Nodo *p = reservar;
		Nodo *j = reservar;
		int aux;
		p = cabeza;
		while(p != NULL){
			j = p -> siguiente;
			while(j != NULL){
				if(p -> dato > j -> dato){
					aux = p -> dato;
					p -> dato = j -> dato;
					j -> dato = aux;
				}
				j = j -> siguiente;
			}
			p = p -> siguiente;
		}
	}else{
		printf("\nLa pila se encuentra sin informacion\n");
	}
}

void menuCola(){
    Nodo *cabeza = NULL;
    Nodo *cola = NULL;
    int opcionMenu = 0;
    do{
        printf("\n|------------------------|----------------------|");
        printf("\n|                        |                      |");
        printf("\n| 1. Generar Numeros     | 2. Imprimir Cola     |");
        printf("\n| 3. Ordenar con Burbuja |                      |");
        printf("\n|                        |                      |");
        printf("\n|                        | 0. Volver Atras      |");
        printf("\n|                        |                      |");
        printf("\n|------------------------|----------------------|");
        printf("\n\nEscoja una opcion: ");
        scanf("%d", &opcionMenu);
        switch(opcionMenu){
            case 1:
                system("cls");
                iniciar = clock();
                generarNumerosAleatoriosCola(cabeza, cola);
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 2:
                system("cls");
                iniciar = clock();
                imprimirCola(cabeza);
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 3:
                system("cls");
                iniciar = clock();
                ordenarElementosCola_Burbuja(cabeza);
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 0:
                system("cls");
                break;
            default:
               system("cls");
               printf("\n          La opcion que ha introducido no es valida. \n");
        }
    }while(opcionMenu != 0);
}
void generarNumerosAleatoriosCola(Nodo *&cabeza, Nodo *&cola){
    int num, nDatos, i = 0;
	printf("Ingrese cantidad de datos: ");
	scanf("%d", &nDatos);
	srand(time(NULL));
	while(i < nDatos){
		num = (rand() % 99999) + 1;
		insertarElementosCola(cabeza, cola, num);
		i += 1;
	}
}
void insertarElementosCola(Nodo *&cabeza, Nodo *&cola, int n){
    Nodo *nuevo = reservar;
	nuevo -> dato = n;
	nuevo -> siguiente = NULL;
	if(cabeza == NULL){
		cabeza = nuevo;
	}else{
		cola -> siguiente = nuevo;
	}
	cola = nuevo;
}
void imprimirCola(Nodo *cabeza){
    if(cabeza != NULL){
		Nodo *actual = reservar;
		actual = cabeza;
		while(actual != NULL){
			printf(" %d |", actual -> dato);
			actual = actual -> siguiente;
		}
	}else{
        printf("\nLa cola se encuentra sin informacion\n");
	}
}
void ordenarElementosCola_Burbuja(Nodo *cabeza){
    if(cabeza != NULL){
		Nodo *p = reservar;
		Nodo *j = reservar;
		int aux;
		p = cabeza;
		while(p != NULL){
			j = p -> siguiente;
			while(j != NULL){
				if(p -> dato > j -> dato){
					aux = p -> dato;
					p -> dato = j -> dato;
					j -> dato = aux;
				}
				j = j -> siguiente;
			}
			p = p -> siguiente;
		}
	}else{
		printf("\nLa cola se encuentra sin informacion\n");
	}
}

void menuPunto2(){
    int opcionMenu = 0;
    do{
        printf("\n|------------------------|----------------------|");
        printf("\n|                        |                      |");
        printf("\n| 1. Generar Numeros     | 2. Imprimir Numeros  |");
        printf("\n| 3. Ordenar con Burbuja |                      |");
        printf("\n|                        |                      |");
        printf("\n|                        | 0. Volver Atras      |");
        printf("\n|                        |                      |");
        printf("\n|------------------------|----------------------|");
        printf("\n\nEscoja una opcion: ");
        scanf("%d", &opcionMenu);
        switch(opcionMenu){
            case 1:
                system("cls");
                iniciar = clock();
                generarNumerosAleatorios();
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 2:
                system("cls");
                iniciar = clock();
                imprimir();
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 3:
                system("cls");
                iniciar = clock();
                ordenarElementos_Burbuja();
                finalizar = clock();
                printf("\nTiempo: %d segundos\n", (finalizar - iniciar)/CLK_TCK);
                break;
            case 0:
                system("cls");
                break;
            default:
               system("cls");
               printf("\n          La opcion que ha introducido no es valida. \n");
        }
    }while(opcionMenu != 0);
}
void generarNumerosAleatorios(){
    int nDatos, num, i;
    printf("Ingrese cantidad de datos: ");
	scanf("%d", &nDatos);
    srand(time(NULL));
    FILE *pf;
    pf = fopen("numeros.txt","w");
    for(i = 1; i <= nDatos; i++){
        num = (rand() % 99999) + 1;
        fprintf(pf, " %d |", num);
    }
    fclose(pf);
}
void imprimir(){
    int c;
    FILE *pf = fopen("numeros.txt", "r");
    while((c = fgetc(pf))!= EOF){
        putchar(c);
    }
}
void ordenarElementos_Burbuja(){
    printf("Sin hacer");
}
