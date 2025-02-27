/*
Asignatura: Metodología de la programación Curso: 1
Tarea que realiza el programa: Gestión de clientes, habitaciones y reservas de un hotel
Alumno 1:< Arraez Pulido Izan>
Alumno 2:<>
Grupo de laboratorio:<1L>
Fecha:<>
*/

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

/***************************************************************************/
/*Subprograma:Barra Separadora*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: ninguno*/
/*parametros de salida: nunguno*/
/*Objetivo: Mostrar la separacion de la cabecera con el menu*/
/***************************************************************************/

void barraSeparadora(){

    printf("-----------------------------------\n");
}

/***************************************************************************/
/*Subprograma:Menu de Inicio*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: ninguno*/
/*parametros de salida: nunguno*/
/*Objetivo: Mostrar el menu de inicio*/
/***************************************************************************/

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

/***************************************************************************/
/*Subprograma:Menu de Gestion de Clientes*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: ninguno*/
/*parametros de salida: nunguno*/
/*Objetivo: Mostrar el menu de Gestion de Clientes*/
/***************************************************************************/

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

/***************************************************************************/
/*Subprograma:Menu de Gestion de Habitaciones*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: ninguno*/
/*parametros de salida: nunguno*/
/*Objetivo: Mostrar el menu Gestion de Habitaciones*/
/***************************************************************************/

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

/***************************************************************************/
/*Subprograma:Menu de Gestion de Reservas*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: ninguno*/
/*parametros de salida: nunguno*/
/*Objetivo: Mostrar el menu de Gestion de Reservas*/
/***************************************************************************/

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

/***************************************************************************/
/*Subprograma:Apertira correcta de un fichero*/
/*Tipo:Procedimiento(función tipo FILE*)*/
/*Parametros de Entrada: File* */
/*parametros de salida: File* */
/*Objetivo: Compribar si el fichero se abre correctamente*/
/***************************************************************************/

FILE* apertCorr(FILE *fich){
    if(fich != NULL){
        return fich;
    }
    else{
        printf("El fichero no se a habierto correctamente o no existe");
    }
}

/***************************************************************************/
/*Subprograma:Generador de codigo de Habitacion*/
/*Tipo:Procedimiento(función tipo char*)*/
/*Parametros de Entrada: int i */
/*parametros de salida: char[] */
/*Objetivo: Generar el codigo de Habitacion de forma automatica*/
/***************************************************************************/

char* geneCodHab(int i){
    return ("HAB_%03d\n",++i);
}



void main(){

    printf("¡Bienvenido a la aplicación GEST_HOTEL!");

    bool salMenIni = true;
    bool salMenGesCli = true;
    bool salMenGesHab = true;
    bool salMenGesRes = true;

    tRegCliente aRegCli[Max_clientes];
    tRegHabitacion aRegHab[5];

    int iRegCli,iRecRegCli,tamRegCli;
    int iRegHab,iCodHab;
    int totCliReg = 0;

    char cDniCli[10];

    FILE *cont_Clientes, *cont_Habitaciones, *cont_Reservas,cont_hcoHabitaciones, *totalGlobalHotel; //.dat
    FILE *habitacionesNuevas, *bajaHcoClientes, *bajaHcoHabitaciones, *bajaHcoReservas; //.txt

    /*cont_Clientes = apertCorr(fopen("Cientes.dat","rb"));
    cont_Habitaciones = apertCorr(fopen("Habitaciones.dat","rb"));
    cont_Reservas = apertCorr(fopen("Reservas.dat","rb"));*/

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
                        case 1: //Alta (bien)

                            //cont_Clientes = apertCorr(fopen("Clientes.dat","ab"));

                            while (getchar() != '\n');

                            printf("Introduce nombre:");
                            scanf("%s",aRegCli[iRegCli].nom_apell);

                            printf("Introduce DNI:");
                            scanf("%s",aRegCli[iRegCli].dni);

                            printf("Introduce Tipo Cliente:");
                            scanf("%s",aRegCli[iRegCli].tp_cli); //%i,&

                            //fwrite(aRegCli,sizeof(int),Max_clientes,altaCliFich); //"Nombre y Apellidos:%s,DNI:%s,Tipo Cliente:%s\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli
                            //fclose(altaCliFich);

                            iRegCli++;
                            break;
                        case 2: //Baja

                            bajaHcoClientes = apertCorr(fopen("bajaHcoClientes.txt","a"));

                            printf("Introduzca Dni para dar de baja");
                            scanf("%s",cDniCli);

                            tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);

                            for(iRecRegCli = 0;iRecRegCli<sizeof(tamRegCli);iRecRegCli++){
                                if(aRegCli[iRecRegCli].dni == cDniCli){
                                    fprintf(bajaHcoClientes,"Nombre y apellidos:%s,Dni:%s,Tipo cliente:%s",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].tp_cli);
                                    strcpy(aRegCli[iRecRegCli].dni,"");
                                    strcpy(aRegCli[iRecRegCli].nom_apell,"");
                                    strcpy(aRegCli[iRecRegCli].tp_cli,"");
                                }
                            }
                            fclose(bajaHcoClientes);
                            break;
                        case 3: //Modificacion (bien)
                            printf("\nIntroduzca Dni para modificar un cliente");
                            scanf("%s",cDniCli);

                            tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);

                            for(iRecRegCli = 0;iRecRegCli<sizeof(tamRegCli);iRecRegCli++){
                                if(strcmp(aRegCli[iRecRegCli].dni, cDniCli) == 0){

                                    while (getchar() != '\n');

                                    printf("Introduzca nombre:");
                                    scanf("%s",aRegCli[iRecRegCli].nom_apell);

                                    printf("Introduce Tipo Cliente:");
                                    scanf("%s",aRegCli[iRecRegCli].tp_cli);
                                }
                            }
                            break;
                        case 4: //Consulta

                            printf("Introduzca Dni a colsultar");
                            scanf("%s",cDniCli);

                            tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);

                            for(iRecRegCli = 0;iRecRegCli<sizeof(tamRegCli);iRecRegCli++){
                                if(strcmp(aRegCli[iRecRegCli].dni, cDniCli) == 0){
                                    printf("Nombre y Apellidos:%s\n",aRegCli[iRecRegCli].nom_apell);
                                    printf("DNI:%s\n",aRegCli[iRecRegCli].dni);
                                    printf("Pipo de Cliente:%s\n",aRegCli[iRecRegCli].tp_cli);
                                    printf("Habitaciones Reservadas:%d\n",aRegCli[iRecRegCli].rs_hab); //Falta
                                }
                            }
                            break;
                        case 5: //Listado General (bien)
                            tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);

                            printf("\nNombre y Apellidos\tDNI\t\tCategorias\n");
                            for(iRecRegCli = 0;iRecRegCli<sizeof(tamRegCli);iRecRegCli++){
                                if(strlen(aRegCli[iRecRegCli].nom_apell) > 0 && strlen(aRegCli[iRecRegCli].dni) > 0 && strlen(aRegCli[iRecRegCli].tp_cli) > 0){
                                    printf("\t%s\t\t%s\t%s\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli);
                                    totCliReg++;
                                }
                            }
                            printf("Total: %i clientes registrados.\n",totCliReg);
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

                                //strcpy(aRegHab[iRegHab].cdHab,geneCodHab());

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
                            //iCodHab = 0;
                            //printf(geneCodHab(++iCodHab));
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
