#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    printf("\nGestion de Clientes\n");
    barraSeparadora();
    printf("   1.- Gestion de Clientes\n");
    printf("   2.- Gestion de Habitaciones\n");
    printf("   3.- Gestion de Reservas\n");
    printf("   4.- Informes Economicos\n");
    printf("   5.- Importar Habitaciones desde Fichero\n");
    printf("   0.- Salir\n");
    printf("Elija opcion:");
}

void menuGestCli(){
    printf("\nGestion de Clientes\n");
    barraSeparadora();
    printf("   1.- Alta\n");
    printf("   2.- Baja\n");
    printf("   3.- Modificacion\n");
    printf("   4.- Consulta\n");
    printf("   5.- Listado General\n");
    printf("   6.- Listsdo por categorias\n");
    printf("   0.- Volver al Menu Principal\n");
    printf("Elija opcion:");
}

void menuGestHab(){
    printf("\nGestion de Habitaciones\n");
    barraSeparadora();
    printf("   1.- Alta\n");
    printf("   2.- Baja\n");
    printf("   3.- Modificacion\n");
    printf("   4.- Consulta\n");
    printf("   5.- Listado General\n");
    printf("   0.- Volver al Menu Principal\n");
    printf("Elija opcion:");
}

void menuGestRes(){
    printf("\nGestion de Reservas\n");
    barraSeparadora();
    printf("   1.- Realizar Reserva\n");
    printf("   2.- Cancelar Reserva\n");
    printf("   3.- Consultar Reserva de un Cliente\n");
    printf("   5.- Listado General de Reservas\n");
    printf("   0.- Volver al Menu Principal\n");
    printf("Elija opcion:");
}

FILE* apertCorr(FILE *fich){
    if(fich != NULL){
        return fich;
    }
    else{
        printf("El fichero no se a habierto correctamente");
    }
}

char* geneCodHab(){
    int i;
    return ("HAB_%03d\n",++i);
}

void main(){
    bool salMenIni = true;
    bool salMenGesCli = true;
    bool salMenGesHab = true;
    bool salMenGesRes = true;

    tRegCliente aRegCli[Max_clientes];
    tRegHabitacion aRegHab[5];

    int iRegCli,iRecRegCli,tamRegCli,totCliReg;
    int iRegHab;

    FILE *altaCliFich;

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

                    totCliReg = 0;

                    switch(eMenCli){
                        case 1: //Alta

                            altaCliFich = apertCorr(fopen("Clientes.dat","ab"));

                            while (getchar() != '\n');

                            printf("Introduce nombre:");
                            scanf("%s",aRegCli[iRegCli].nom_apell);

                            printf("Introduce DNI:");
                            scanf("%s",aRegCli[iRegCli].dni);

                            printf("Introduce Tipo Cliente:");
                            scanf("%s",aRegCli[iRegCli].tp_cli); //%i,&

                            ++totCliReg;

                            fwrite(aRegCli,sizeof(aRegCli),Max_clientes,altaCliFich); //"Nombre y Apellidos:%s,DNI:%s,Tipo Cliente:%s\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli
                            fclose(altaCliFich);

                            iRegCli++;
                            break;
                        case 2: //Baja
                            break;
                        case 3: //Modificacion
                            break;
                        case 4: //Consulta
                            break;
                        case 5: //Listado General
                            tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);

                            for(iRecRegCli = 0;iRecRegCli<sizeof(tamRegCli);iRecRegCli++){
                                if(strlen(aRegCli[iRecRegCli].dni) > 0){
                                    printf("\nNombre y Apellidos\tDNI\t\tCategorias\n");
                                    printf("\t%s\t\t%s\t%s\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli);
                                    printf("Total: %i clientes registrados.\n",totCliReg);
                                }
                            }
                            break;
                        case 6: //Listado por categorias
                            break;
                        case 0: //Volver al menu principal
                            salMenGesCli = false;
                            break;
                        default: //Volver al menu principal
                            salMenGesCli = false;
                            break;
                    }

                }while(salMenGesCli == true);
                break;
            case 2: //Gestion Habitaciones
                do{
                    int eMenHab;

                    menuGestHab();
                    scanf("%i",&eMenHab);

                    switch(eMenHab){
                        case 1: //Alta Habitacion
                            if(totCliReg > 0){      //Preguntar**********************

                                iRegHab = 0;

                                while (getchar() != '\n');

                                strcpy(aRegHab[iRegHab].cdHab,geneCodHab());

                                printf("Introduce tipo de habitacion:");
                                scanf("%i",aRegHab[iRegHab].tipo);

                                printf("Introduce el precio de la habitacion:");
                                scanf("%f",aRegHab[iRegHab].precio);

                                printf("%s,%i,%f",aRegHab[iRegHab].cdHab,aRegHab[iRegHab].tipo,aRegHab[iRegHab].precio);
                            }
                            else{
                                printf("No existen cientes para asignar una habitacion");
                            }
                            break;
                        case 2: //Baja Habitacion
                            break;
                        case 3: //Modificacion Habitacion
                            break;
                        case 4: //Consulta Habitacion
                            break;
                        case 5: //Listado General de Habitacion
                            break;
                        case 0: //Volver al menu principal
                            salMenGesHab = false;
                            break;
                        default: //Volver al menu principal
                            salMenGesHab = false;
                            break;
                    }

                }while(salMenGesHab == true);
                break;
            case 3: //Gestion Reservas
                break;
            case 4: //Informes Economicos
                break;
            case 5: //Importar Habitaciones desde ficheros
                break;
            case 0: //Salida de Menu de inicio
                printf("\n¡Gracias por utilizar la aplicacion GEST-HOTEL!\n");
                salMenIni = false;
                break;
            default:
                printf("\n¡Gracias por utilizar la aplicacion GEST-HOTEL!\n");
                salMenIni = false;
                break;
        }

    }while(salMenIni == true);
}
