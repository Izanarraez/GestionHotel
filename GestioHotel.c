#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char cdHab[9];
    int tipo;
    float precio;
}tRegHabitacion;

typedef struct{
    char nom_apell[50];
    char dni[12];
    char tp_cli[10];
    tRegHabitacion rs_hab[5];
}tRegCliente;

const int Max_clientes = 100; /************************************Consultar lo del define*******************************/
const int Max_habitaciones = 50;

void barraSeparadora(){

    printf("-----------------------------------\n");
}

void menuInicio(){
    printf("Gestion de Clientes\n");
    barraSeparadora();
    printf("1.- Gestion de Clientes\n");
    printf("2.- Gestion de Habitaciones\n");
    printf("3.- Gestion de Reservas\n");
    printf("4.- Informes Economicos\n");
    printf("5.- Importar Habitaciones desde Fichero\n");
    printf("0.- Salir\n");
    printf("Elija opcion:");
}

void menuGestCli(){
    printf("Gestion de Clientes\n");
    barraSeparadora();
    printf("1.- Alta\n");
    printf("2.- Baja\n");
    printf("3.- Modificacion\n");
    printf("4.- Consulta\n");
    printf("5.- Listado General\n");
    printf("6.- Listsdo por categorias\n");
    printf("0.- Volver al Menu Principal\n");
    printf("Elija opcion:");
}

void main(){
    bool salMenIni = true;
    bool salMenGesCli = true;

    tRegCliente aRegCli[Max_clientes];
    tRegHabitacion aRegHab[5];

    int iRegCli,iRecRegCli,tamRegCli;

    do{
        int eMenIni;

        menuInicio();
        scanf("%i",&eMenIni);

        switch(eMenIni){
            case 1: //Gestion Clientes
                do{
                    int eMenCli;

                    menuGestCli();
                    scanf("%i",&eMenCli);

                    switch(eMenCli){
                        case 1: //Alta

                            while (getchar() != '\n');

                            printf("Introduce nombre:");
                            scanf("%s",aRegCli[iRegCli].nom_apell);

                            printf("Introduce DNI:");
                            scanf("%s",aRegCli[iRegCli].dni);

                            printf("Introduce Tipo Cliente:");
                            scanf("%s",aRegCli[iRegCli].tp_cli); //%i,&

                            iRegCli++;
                            break;
                        case 2: //Baja
                            break;
                        case 3: //Modificacion
                            break;
                        case 4: //Consulta
                            break;
                        case 5: //Listado General
                            //tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);
                            for(iRecRegCli = 0;iRecRegCli<sizeof(aRegCli);iRecRegCli++){
                                if(aRegCli[iRecRegCli] != NULL && aRegCli[iRecRegCli] != " "){
                                    printf("Nombre y Apellidos\tDNI\t\tCategorias\n");
                                    printf("\t%s\t,\t%s\t,%i\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli);
                                    printf("Total: %i clientes registrados.\n",sizeof(aRegCli));
                                }
                            }
                            break;
                        case 6: //Listado por categorias
                            break;
                        case 0: //Volver al menu principal
                            salMenGesCli = false;

                    }

                }while(salMenGesCli == true);
            case 2: //Gestion Habitaciones
            case 3: //Gestion Reservas
            case 4: //Informes Economicos
            case 5: //Importar Habitaciones desde ficheros
            case 0: //Salida de Menu de inicio
                printf("\n¡Gracias por utilizar la aplicacion GEST-HOTEL!\n");
                salMenIni = false;
        }

    }while(salMenIni == true);
}
