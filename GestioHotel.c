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


const int Max_clientes = 100;
const int Max_habitaciones = 50;

typedef struct{
    char cdHab[9];
    char tipo[12];
    float precio;
}tRegHabitacion;

typedef struct{
    char nom_apell[50];
    char dni[12];
    char tp_cli[10];
    tRegHabitacion rs_hab[5];
}tRegCliente;

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

FILE* apertCorr(char *fich){
    FILE *open = fopen(fich,"ab");
    if(open == NULL){
        printf("El fichero no se a habierto correctamente o no existe");
        return 1;
    }
    return open;
}

FILE* lecCorr(char *fich){
    FILE *open = fopen(fich,"rb");
    if(open == NULL){
        printf("El fichero no se a leido correctamente o no existe, creando fichero");
        return apertCorr(fich);
    }
    return open;
}

/***************************************************************************/
/*Subprograma:Generador de codigo de Habitacion*/
/*Tipo:Procedimiento(función tipo char*)*/
/*Parametros de Entrada: int i */
/*parametros de salida: char[] */
/*Objetivo: Generar el codigo de Habitacion de forma automatica*/
/***************************************************************************/

char* geneCodHab(char *cadena,int i){
    ++i;
    return sprintf(cadena, "HAB_%03d", i);
}

void impArrCli(tRegCliente *regCli){
    int i = 0;
    int tam = sizeof(regCli)/ sizeof(regCli[0]);
    for(i;i < sizeof(tam);i++){
        if(regCli[i].nom_apell != "" && regCli[i].dni != "" && regCli[i].tp_cli != ""){
            printf("%s,%s,%s\n",regCli[i].dni,regCli[i].nom_apell,regCli[i].tp_cli);
        }
    }
}

tRegCliente *rellArrCli(tRegCliente *arr){
    int i = 0;
    int j = 0;
    //int tam = sizeof(arr) / sizeof(arr[0]);
    for(i;i<Max_clientes;i++){
        strcpy(arr[i].nom_apell,"");
        strcpy(arr[i].dni,"");
        strcpy(arr[i].tp_cli,"");

        int tam2 = sizeof(arr[i].rs_hab) / sizeof(arr[i].rs_hab[0]);

        for(j;j<5;j++){
            strcpy(arr[i].rs_hab[j].cdHab,"");
            strcpy(arr[i].rs_hab[j].tipo,"");
            arr[i].rs_hab[j].precio = 0.0;
        }
    }
    return arr;
}
//,FILE *habitaciones, FILE* reservas

void errEscFich(size_t eleEsc,size_t numEle){
    if (eleEsc != numEle) {
        perror("Error al escribir en el archivo");
        return 1;
    }
}
void main(){


    printf("¡Bienvenido a la aplicacion GEST_HOTEL!");

    bool salMenIni = true;
    bool salMenGesCli = true;
    bool salMenGesHab = true;
    bool salMenGesRes = true;

    tRegCliente aRegCli[Max_clientes];
    tRegHabitacion aRegHab[Max_habitaciones];

    size_t tamRegCli = 0;
    size_t eleEscriRegCli = 0;

    int iRegCli = 0,iRecRegCli = 0,totCliReg = 0,totCliCat;
    int iRegHab = 0,iCodHab = 1,tamRegHab = 0,totHabReg;

    char cDniCli[10], cCodHab[10], cTipoCli[12];

    FILE *cont_Clientes, *cont_Habitaciones, *cont_Reservas,cont_hcoHabitaciones, *totalGlobalHotel; //.dat
    FILE *habitacionesNuevas, *bajaHcoClientes, *bajaHcoHabitaciones, *bajaHcoReservas; //.txt

    memcpy(aRegCli,rellArrCli(aRegCli),sizeof(aRegCli));

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
                        case 1: //Alta (bien)

                            while (getchar() != '\n');

                            printf("Introduce nombre:");
                            scanf("%s",aRegCli[iRegCli].nom_apell);

                            printf("Introduce DNI:");
                            scanf("%s",aRegCli[iRegCli].dni);

                            printf("Introduce Tipo Cliente:");
                            scanf("%s",aRegCli[iRegCli].tp_cli);

                            iRegCli++;
                            break;
                        case 2: //Baja (bien)

                            //bajaHcoClientes = apertCorr(fopen("bajaHcoClientes.txt","a"));

                            printf("Introduzca Dni para dar de baja");
                            scanf("%s",cDniCli);

                            for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
                                if(strcmp(aRegCli[iRecRegCli].dni,cDniCli) == 0){
                                    strcpy(aRegCli[iRecRegCli].nom_apell,"");
                                    strcpy(aRegCli[iRecRegCli].dni,"");
                                    strcpy(aRegCli[iRecRegCli].tp_cli,"");
                                }
                            }
                            //fclose(bajaHcoClientes);
                            break;
                        case 3: //Modificacion (bien)
                            printf("\nIntroduzca Dni para modificar un cliente");
                            scanf("%s",cDniCli);

                            for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
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

                            printf("Introduzca Dni a colsultar:");
                            scanf("%s",cDniCli);

                            //tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);

                            for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
                                if(strcmp(aRegCli[iRecRegCli].dni, cDniCli) == 0){
                                    printf("Nombre y Apellidos:%s\n",aRegCli[iRecRegCli].nom_apell);
                                    printf("DNI:%s\n",aRegCli[iRecRegCli].dni);
                                    printf("Pipo de Cliente:%s\n",aRegCli[iRecRegCli].tp_cli);
                                    printf("Habitaciones Reservadas:%d\n",aRegCli[iRecRegCli].rs_hab); //Falta
                                }
                            }
                            break;
                        case 5: //Listado General (bien)
                            printf("\nNombre y Apellidos\tDNI\t\tCategorias\n");

                            totCliReg = 0;

                            for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
                                if(strlen(aRegCli[iRecRegCli].nom_apell) > 0 && strlen(aRegCli[iRecRegCli].dni) > 0 && strlen(aRegCli[iRecRegCli].tp_cli) > 0){
                                    printf("\t%s\t\t%s\t\t%s\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli);
                                    totCliReg++;

                                }
                            }

                            printf("Total: %i clientes registrados.\n",totCliReg);
                            break;
                        case 6: //Listado por categorias
                            printf("Introduzca Categoria a consultar:");
                            scanf("%s",cTipoCli);

                            //tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);

                            totCliCat = 0;
                            printf("LISTADO DE CLIENTES - Categoria %s\n",cTipoCli);
                            barraSeparadora();
                            printf("   Nombre y Apellidos\tDNI\n");
                            for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
                                if(strcmp(aRegCli[iRecRegCli].tp_cli, cTipoCli) == 0){
                                    printf("%s\t%s\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni);
                                    totCliCat++;
                                }
                            }
                            printf("Total: %i clientes registrados.\n",totCliCat);
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

                            while (getchar() != '\n');

                            //geneCodHab(aRegHab[iRegHab].cdHab,iCodHab);

                            sprintf(aRegHab[iRegHab].cdHab, "HAB_%03d", iCodHab);

                            printf("Introduce tipo de habitacion:");
                            scanf("%s",aRegHab[iRegHab].tipo);

                            printf("Introduce el precio de la habitacion:");
                            scanf("%f",&aRegHab[iRegHab].precio);

                            iCodHab++;
                            iRegHab++;
                            break;
                        case 2: //Baja Habitacion
                            //iCodHab = 0;
                            //printf(geneCodHab(++iCodHab));

                            break;
                        case 3: //Modificacion Habitacion
                            break;
                        case 4: //Consulta Habitacion

                            printf("Introduzca Dni a colsultar");
                            scanf("%s",cCodHab);

                            tamRegHab = sizeof(aRegHab) / sizeof(aRegHab[0]);

                            for(iRegHab = 0;aRegHab < Max_habitaciones;iRegHab++){
                                if(strcmp(aRegHab[iRegHab].cdHab, cCodHab) == 0){
                                    printf("Codigo Habitacion:%s\n",aRegHab[iRegHab].cdHab);
                                    printf("Tipo:%s\n",aRegHab[iRegHab].tipo);
                                    printf("Precio:%s\n",aRegHab[iRegHab].precio);
                                    break;
                                }
                            }
                            printf("Error codigo no existe");
                            break;
                        case 5: //Listado General de Habitacion

                            //tamRegHab = sizeof(aRegHab) / sizeof(aRegHab[0]);

                            totHabReg = 0;
                            printf("\nNombre y Apellidos\tDNI\t\tCategorias\n");
                            for(iRegHab = 0;iRegHab < Max_habitaciones;iRegHab++){
                                if(strlen(aRegHab[iRegHab].cdHab) > 0 && strlen(aRegHab[iRegHab].tipo) > 0 && aRegHab[iRegHab].precio > 0){
                                    printf("\t%s\t\t%s\t%f\n",aRegHab[iRegHab].cdHab,aRegHab[iRegHab].tipo,aRegHab[iRegHab].precio);
                                    totHabReg++;
                                }
                            }
                            printf("Total: %i habitaciones registradas.\n",totHabReg);
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

                cont_Clientes = apertCorr("Clientes.dat");
                tamRegCli = sizeof(aRegCli) / sizeof(aRegCli[0]);
                eleEscriRegCli = fwrite(aRegCli,sizeof(tRegCliente),100,cont_Clientes);
                errEscFich(eleEscriRegCli,tamRegCli);
                fclose(cont_Clientes);

                impArrCli(aRegCli);

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
