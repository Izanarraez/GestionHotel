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
#include <time.h>


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

typedef union{
    tRegCliente regCli;
    char **resv;
}strucMatr;

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
    printf("   4.- Listado General de Reservas\n");
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

FILE *apertCorr(char *fich){
    FILE *open = fopen(fich,"wb");
    if(open == NULL){
        printf("El fichero no se a habierto correctamente o no existe");
    }
    return open;
}

FILE *lecCorr(char *fich){
    FILE *open = fopen(fich,"rb");
    if(open == NULL){
        printf("El fichero no se a leido correctamente o no existe, creando fichero.\n");
    }
    return open;
}

FILE *apertCorrTxt(char *fich){
    FILE *open = fopen(fich,"a");
    if(open == NULL){
        printf("El fichero no se a leido correctamente o no existe, creando fichero.\n");
    }
    return open;
}

int contRegCli(tRegCliente *aRegCli,int maxCli){
    int cont = 0;
    for(int i = 0;i<maxCli;i++){
        if(strlen(aRegCli[i].nom_apell) > 0 && strlen(aRegCli[i].dni) > 0 && strlen(aRegCli[i].tp_cli) > 0){
            cont++;
        }
    }
    return cont;
}

int contRegHab(tRegHabitacion *aRegHab,int maxHab){
    int cont = 0;
    for(int i = 0;i<maxHab;i++){
        if(strlen(aRegHab[i].cdHab) > 0 && strlen(aRegHab[i].tipo) > 0 && aRegHab[i].precio > 0){
            cont++;
        }
    }
    return cont;
}

void impArrCli(tRegCliente *regCli){
    int i = 0;
    int j = 0;
    int tam = sizeof(regCli)/ sizeof(regCli[0]);
    for(i;i < sizeof(tam);i++){
        if(regCli[i].nom_apell != "\0" && regCli[i].dni != "\0" && regCli[i].tp_cli != "\0"){
            printf("%s,%s,%s\n",regCli[i].dni,regCli[i].nom_apell,regCli[i].tp_cli);
            for(j;j<5;j++){
                printf("%s,%s,%f\n",regCli[i].rs_hab[j].cdHab,regCli[i].rs_hab[j].tipo,&regCli[i].rs_hab[j].precio);
            }
        }
    }
}

void errEscFich(size_t eleEsc,size_t numEle){
    if (eleEsc != numEle) {
        perror("Error al escribir en el archivo");
        return 1;
    }
}

/***************************************************************************/
/*Subprograma:Alta Cliente*/
/*Tipo:Procedimiento(función tipo tRegCliente *)*/
/*Parametros de Entrada: tRegCliente * */
/*parametros de salida: tRegCliente * */
/*Objetivo: Dar de alta un cliente en el array de tipo tRegCliente*/
/***************************************************************************/

tRegCliente *altaCliente(tRegCliente *aRegCli){
    while (getchar() != '\n');

    int iRegCli = contRegCli(aRegCli,Max_clientes);

    printf("Introduce nombre:");
    scanf("%s",aRegCli[iRegCli].nom_apell);

    printf("Introduce DNI:");
    scanf("%s",aRegCli[iRegCli].dni);

    printf("Introduce Tipo Cliente:");
    scanf("%s",aRegCli[iRegCli].tp_cli);

    iRegCli++;

    return aRegCli;
}

/***************************************************************************/
/*Subprograma:Baja Cliente*/
/*Tipo:Procedimiento(función tipo tRegCliente *)*/
/*Parametros de Entrada: tRegCliente * */
/*parametros de salida: tRegCliente * */
/*Objetivo: Dar de baja a un cliente en el array de tipo tRegCliente*/
/***************************************************************************/

tRegCliente *bajaCliente(tRegCliente *aRegCli){

    bool resAso = true;
    bool dniNoEnc = true;

    int totResCli = 0;
    int iRecRegCli, iRecRegHabCli;

    char cDniCli[10],resCli[4];

    FILE *cont_Clientes;

    while (getchar() != '\n');

    printf("Introduzca Dni para dar de baja");
    scanf("%s",cDniCli);

    for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        for(iRecRegHabCli = 0;iRecRegHabCli < 5;iRecRegHabCli++){
            if(strlen(aRegCli[iRecRegCli].rs_hab[iRecRegHabCli].cdHab) > 0){
                totResCli++;
            }
        }
    }

    for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        if(strcmp(aRegCli[iRecRegCli].dni,cDniCli) == 0){
            printf("¿Desea dar de baja a este ciente?(S/N)");
            scanf("%s",resCli);
            if(strcmp(resCli,"S") == 0 && totResCli < 1){

                cont_Clientes = apertCorrTxt("bajaHcoClientes.txt");
                fprintf(cont_Clientes,"%s-%s-%s\n",aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].tp_cli);
                fclose(cont_Clientes);

                strcpy(aRegCli[iRecRegCli].nom_apell,"\0");
                strcpy(aRegCli[iRecRegCli].dni,"\0");
                strcpy(aRegCli[iRecRegCli].tp_cli,"\0");

                resAso = false;
            }
        dniNoEnc = false;
        }
    }
    if(resAso == true){
        printf("ERROR:No se pudo dar de baja al cliente %s ya que tiene reserva asociada",cDniCli);
    }
    if(dniNoEnc == true){
        printf("ERROR:Este cliente no se encuentra en nuestro registro de datos");
    }

    return aRegCli;
}

/***************************************************************************/
/*Subprograma:Modificacion de Cliente*/
/*Tipo:Procedimiento(función tipo tRegCliente *)*/
/*Parametros de Entrada: tRegCliente * */
/*parametros de salida: tRegCliente */
/*Objetivo: Modifica los datos a un cliente en el array de tipo tRegCliente (Excepto el DNI)*/
/***************************************************************************/

 tRegCliente *modificacionCliente(tRegCliente *aRegCli){

    int iRecRegCli;
    char cDniCli[10];

    while (getchar() != '\n');

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
    return aRegCli;
}

/***************************************************************************/
/*Subprograma:Consulta de un Cliente*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: tRegCliente * */
/*parametros de salida: nada */
/*Objetivo: Mostrar los datos de un cliente a traves de su DNI*/
/***************************************************************************/
void consultaCliente(tRegCliente *aRegCli){

    int iRecRegCli;
    char cDniCli[10];

    while (getchar() != '\n');

    printf("Introduzca Dni a colsultar:");
    scanf("%s",cDniCli);

    for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        if(strcmp(aRegCli[iRecRegCli].dni, cDniCli) == 0){
            printf("Nombre y Apellidos:%s\n",aRegCli[iRecRegCli].nom_apell);
            printf("DNI:%s\n",aRegCli[iRecRegCli].dni);
            printf("Pipo de Cliente:%s\n",aRegCli[iRecRegCli].tp_cli);
            printf("Habitaciones Reservadas:%d\n",aRegCli[iRecRegCli].rs_hab); //Falta
        }
    }
}

/***************************************************************************/
/*Subprograma: Listado general de Clientes*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: tRegCliente * */
/*parametros de salida: nada  */
/*Objetivo: Mostrar todos clientes*/
/***************************************************************************/

void listadoGeneralCliente(tRegCliente *aRegCli){
    printf("\nNombre y Apellidos\tDNI\t\tCategorias\n");

    int iRecRegCli;
    int totCliReg = contRegCli(aRegCli,Max_clientes);

    for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        if(strlen(aRegCli[iRecRegCli].nom_apell) > 0 && strlen(aRegCli[iRecRegCli].dni) > 0 && strlen(aRegCli[iRecRegCli].tp_cli) > 0){
            printf("\t%s\t\t%s\t\t%s\n",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli);
            if(iRecRegCli >= totCliReg){
                totCliReg++;
            }
        }
    }
    printf("Total: %i clientes registrados.\n",totCliReg);
}

/***************************************************************************/
/*Subprograma: Listado por categorias de Clientes*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: tRegCliente * */
/*parametros de salida: nada */
/*Objetivo: Mostrar los datos de un cliente a traves de la categoria*/
/***************************************************************************/

void listadoPorCategoriasCliente(tRegCliente *aRegCli){

    int iRecRegCli,totCliCat = 0;
    char cTipoCli[10];

    while (getchar() != '\n');

    printf("Introduzca Categoria a consultar:");
    scanf("%s",cTipoCli);

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
}

/***************************************************************************/
/*Subprograma: Alta habitacion*/
/*Tipo:Procedimiento(función tipo tRegHabitacion *)*/
/*Parametros de Entrada: tRegHabitacion * */
/*parametros de salida: tRegHabitacion * */
/*Objetivo: Dar de alta a una habitacion*/
/***************************************************************************/

tRegHabitacion *altaHabitacion(tRegHabitacion *aRegHab){

    int iRegHab = contRegHab(aRegHab,Max_habitaciones);

    while (getchar() != '\n');

    sprintf(aRegHab[iRegHab].cdHab, "HAB_%03d", iRegHab);

    printf("Introduce tipo de habitacion:");
    scanf("%s",aRegHab[iRegHab].tipo);

    printf("Introduce el precio de la habitacion:");
    scanf("%f",&aRegHab[iRegHab].precio);

    iRegHab++;

    return aRegHab;
}

/***************************************************************************/
/*Subprograma: Baja habitacion*/
/*Tipo:Procedimiento(función tipo tRegHabitacion *)*/
/*Parametros de Entrada: tRegHabitacion * y tRegCliente * */
/*parametros de salida: tRegHabitacion * */
/*Objetivo: Dar de baja una habitacion*/
/***************************************************************************/

tRegHabitacion *bajaHabitacion(tRegCliente *aRegCli,tRegHabitacion *aRegHab){

    bool habNoEnc = true;
    bool habNoResv = true;

    char cCodHab[10],fechForm[50];

    int iRecRegCli,iRecRegHabCli,iRecRegHab;

    FILE *cont_Habitaciones;

    time_t tiemActu = time(NULL);
    struct tm *fecha = localtime(&tiemActu);
    strftime(fechForm, sizeof(fechForm), "%d/%m/%Y", fecha);

    while (getchar() != '\n');

    printf("Introduzca codigo de habitacion para dar de baja");
    scanf("%s",cCodHab);

    for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        for(iRecRegHabCli = 0;iRecRegHabCli < 5;iRecRegHabCli++){
            if(strcmp(aRegCli[iRecRegCli].rs_hab[iRecRegHabCli].cdHab, cCodHab) != 0){
                for(iRecRegHab = 0;iRecRegHab<Max_habitaciones;iRecRegHab++){
                    if(strcmp(aRegHab[iRecRegHab].cdHab,cCodHab) == 0){

                        cont_Habitaciones = apertCorrTxt("bajaHcoHabitaciones.txt");
                        fprintf(cont_Habitaciones,"%s-%s-%s\n",aRegHab[iRecRegHab].cdHab,aRegHab[iRecRegHab].tipo,fechForm);
                        fclose(cont_Habitaciones);

                        strcpy(aRegHab[iRecRegHab].cdHab,"\0");
                        strcpy(aRegHab[iRecRegHab].tipo,"\0");
                        aRegHab[iRecRegHab].precio = 0.0;
                        habNoEnc = false;
                    }
                }
            habNoResv = false;
            }
        }
    }

    if(habNoEnc == true){
        printf("Error, La habitacion no figura en nuestros registros");
    }
    if(habNoResv == true){
        printf("Error, no se puede dar de baja la habitacion %s ya que tiene reservas asociadas",cCodHab);
    }
    return aRegHab;
}


/***************************************************************************/
/*Subprograma: Modificar habitacion*/
/*Tipo:Procedimiento(función tipo tRegHabitacion *)*/
/*Parametros de Entrada: tRegHabitacion * */
/*parametros de salida: tRegHabitacion * */
/*Objetivo: Dar una  habitacion (No se puede cambiar el codigo habitacion)*/
/***************************************************************************/

tRegHabitacion *modificacionHabitacion(tRegHabitacion *aRegHab){

    bool habNoEnc = true;

    char cCodHab[10];

    int iRecRegHab;

    while (getchar() != '\n');

    printf("Introduzca codigo de habitacion para ser modificado");
    scanf("%s",cCodHab);

    for(iRecRegHab = 0;iRecRegHab < Max_habitaciones;iRecRegHab++){
        if(strcmp(aRegHab[iRecRegHab].cdHab, cCodHab) == 0){
            while (getchar() != '\n');

            printf("Introduzca tipo:");
            scanf("%s",aRegHab[iRecRegHab].tipo);

            printf("Introduce precio:");
            scanf("%f",&aRegHab[iRecRegHab].precio);

            habNoEnc = false;
        }
    }

    if(habNoEnc == true){
        printf("Error, La habitacion no figura en nuestros registros");
    }
    return aRegHab;
}

/***************************************************************************/
/*Subprograma: Consultar una habitacion*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: tRegHabitacion * */
/*parametros de salida: nada */
/*Objetivo: Mostrar los datos de una habitacion (introduciendo codigo habitacion)*/
/***************************************************************************/

void consultaHabitacion(tRegHabitacion *aRegHab){

    char cCodHab[10];

    int iRecRegHab;

    while (getchar() != '\n');

    printf("Introduzca codigo de habitacion a colsultar");
    scanf("%s",cCodHab);

    for(iRecRegHab = 0;iRecRegHab < Max_habitaciones;iRecRegHab++){
        if(strcmp(aRegHab[iRecRegHab].cdHab, cCodHab) == 0){
            printf("Codigo Habitacion:%s\n",aRegHab[iRecRegHab].cdHab);
            printf("Tipo:%s\n",aRegHab[iRecRegHab].tipo);
            printf("Precio:%f\n",aRegHab[iRecRegHab].precio);
        }
    }
}

/***************************************************************************/
/*Subprograma: Listado de habitaciones*/
/*Tipo:Procedimiento(función tipo void)*/
/*Parametros de Entrada: tRegHabitacion * */
/*parametros de salida: nada */
/*Objetivo: Mostrar todas las habitaciones registradas*/
/***************************************************************************/

void listadoGeneralHabitacion(tRegHabitacion *aRegHab){

    int totHabReg = contRegHab(aRegHab,Max_habitaciones);
    int iRecRegHab;

    printf("\nNombre y Apellidos\tDNI\t\tCategorias\n");
    for(iRecRegHab = 0;iRecRegHab < Max_habitaciones;iRecRegHab++){
        if(strlen(aRegHab[iRecRegHab].cdHab) > 0 && strlen(aRegHab[iRecRegHab].tipo) > 0 && aRegHab[iRecRegHab].precio > 0){
            printf("\t%s\t\t%s\t%f\n",aRegHab[iRecRegHab].cdHab,aRegHab[iRecRegHab].tipo,aRegHab[iRecRegHab].precio);
            if(iRecRegHab >= totHabReg){
                totHabReg++;
            }
        }
    }
    printf("Total: %i habitaciones registradas.\n",totHabReg);
}

char **altaReserva(tRegCliente *aRegCli, tRegHabitacion *aRegHab, char **aRegRes,char *cdDniCli,char *cCodHab){

    int diaRes,iRecRegCli,iRecRegHab,iRecRegHabCli;

    bool habNoResv = false;

    while (getchar() != '\n');

    printf("Introduzca dia a reservar:");
    scanf("%i",&diaRes);

    for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        for(iRecRegHabCli = 0;iRecRegHabCli < 5;iRecRegHabCli++){
            if(strcmp(aRegCli[iRecRegCli].rs_hab[iRecRegHabCli].cdHab, cCodHab) != 0){
                habNoResv = true;
            }
        }
    }

    if(habNoResv == true){
        for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
            for(iRecRegHab = 0;iRecRegHab<Max_habitaciones;iRecRegHab++){
                if(strcmp(aRegHab[iRecRegHab].cdHab, cCodHab) == 0){
                    strcpy(aRegRes[iRecRegHab][diaRes],aRegCli[iRecRegCli].dni);
                }
            }
        }
    }
    return aRegRes;
}

tRegCliente *asignarReserva(tRegCliente *aRegCli, tRegHabitacion *aRegHab,char *cdDniCli,char *cCodHab){

    int iRecRegCli,iRecRegHab,iRecRegHabCli,totResCli = 0;

    bool habNoResv = false;

    for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        for(iRecRegHabCli = 0;iRecRegHabCli < 5;iRecRegHabCli++){
            if(strcmp(aRegCli[iRecRegCli].rs_hab[iRecRegHabCli].cdHab, cCodHab) != 0){
                totResCli++;
                habNoResv = true;
            }
        }
    }

    if(habNoResv == true){
        for(iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
            for(iRecRegHab = 0;iRecRegHab<Max_habitaciones;iRecRegHab++){
                if(strcmp(aRegHab[iRecRegHab].cdHab, cCodHab) == 0){
                    strcpy(aRegCli[iRecRegCli].rs_hab[totResCli].cdHab,aRegHab[iRecRegHab].cdHab);
                    strcpy(aRegCli[iRecRegCli].rs_hab[totResCli].tipo,aRegHab[iRecRegHab].tipo);
                    aRegCli[iRecRegCli].rs_hab[totResCli].precio = aRegHab[iRecRegHab].precio;
                }
            }
        }
    }
    return aRegCli;
}

void listaGeneralReservas(tRegCliente *aRegCli, char **aRegRes){

    int iRecRegHab,iDiaRes,iRecRegCli,iRecRegHabCli;

    printf("LISTADO GENERAL DE RESERVAS\n");
    barraSeparadora();
    printf("\nNombre Cliente\tCodigo Habitación\tTipo Habitacion");
    for(iRecRegHab = 0;iRecRegHab<Max_habitaciones;iRecRegHab++){
        for(iDiaRes = 0;iDiaRes < 31;iDiaRes++){
            for(iRecRegCli = 0;iRecRegCli < Max_clientes;iRecRegCli++){
                if(strcmp(aRegRes[iRecRegHab][iDiaRes],aRegCli[iRecRegCli].dni) == 0){
                    for(iRecRegHabCli = 0;iRecRegHabCli<5;iRecRegHabCli++){
                        printf("%s\t%s\t%s",aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].rs_hab[iRecRegHabCli].cdHab,aRegCli[iRecRegCli].rs_hab[iRecRegHabCli].tipo);
                    }
                }
            }
        }
    }
}

tRegHabitacion *importarNuevaHabitacionFichero(tRegHabitacion *aRegHab){
    int iRegHab = contRegHab(aRegHab,Max_habitaciones);
    printf("%i",iRegHab);
    FILE *cont_Habitaciones = fopen("habitacionesNuevas.txt","r");
    char linea[100];
    char *token;

    if (cont_Habitaciones == NULL) {
        printf("Error: No se pudo abrir el fichero.\n");
    }

    while(fgets(linea, sizeof(linea), cont_Habitaciones) != NULL){
        linea[strcspn(linea, "\n")] = '\0';
        token = strtok(linea,"#");
        if(token != NULL) {

            sprintf(aRegHab[iRegHab].cdHab, "HAB_%03d", iRegHab);
            strcpy(aRegHab[iRegHab].tipo,token);

            token = strtok(NULL, "#");
            if(token != NULL){
                aRegHab[iRegHab].precio = atoi(token);
            }
        }
    iRegHab++;
    }
    fclose(cont_Habitaciones);
    return aRegHab;
}

void importarClientesFichero(tRegCliente *aRegCli){
    FILE *cont_Clientes = lecCorr("Clientes.dat");

    size_t numLeiCli = fread(aRegCli, sizeof(tRegCliente), Max_clientes, cont_Clientes);
    fclose(cont_Clientes);

    if (numLeiCli != Max_clientes) {
        printf("Error al leer el fichero o el fichero no contiene suficientes datos.\n");
    }
}

void importarHabitacionFichero(tRegHabitacion *aRegHab){
    FILE *cont_Habitaciones = lecCorr("Habitaciones.dat");

    size_t numLeiHab = fread(aRegHab, sizeof(tRegHabitacion), Max_habitaciones, cont_Habitaciones);
    fclose(cont_Habitaciones);

    if (numLeiHab != Max_habitaciones) {
        printf("Error al leer el fichero o el fichero no contiene suficientes datos.\n");
    }
}

void guardarClienteFichero(tRegCliente *aRegCli){
    FILE *cont_Clientes = apertCorr("Clientes.dat");
    size_t numEscCli = fwrite(aRegCli, sizeof(tRegCliente), Max_clientes, cont_Clientes);
    fclose(cont_Clientes);

    if (numEscCli != Max_clientes) {
        printf("Error: No se escribieron todos los datos en el fichero.\n");
    } else {
        printf("Datos guardados correctamente en el fichero.\n");
    }
}

void guardarHabitacionFichero(tRegHabitacion *aRegHab){
    FILE *cont_Habitaciones = apertCorr("Habitaciones.dat");
    size_t numEscHab = fwrite(aRegHab, sizeof(tRegHabitacion), Max_habitaciones, cont_Habitaciones);
    fclose(cont_Habitaciones);

    if (numEscHab != Max_habitaciones) {
        printf("Error: No se escribieron todos los datos en el fichero.\n");
    } else {
        printf("Datos guardados correctamente en el fichero.\n");
    }
}

void main(){


    printf("¡Bienvenido a la aplicacion GEST_HOTEL!");

    bool salMenIni = true, salMenGesCli = true, salMenGesHab = true, salMenGesRes = true;

    tRegCliente aRegCli[Max_clientes];
    tRegHabitacion aRegHab[Max_habitaciones];
    char aRegRes[Max_habitaciones][31];

    size_t tamRegCli = 0;
    size_t eleEscriRegCli = 0;

    int iRegCli,iRecRegCli = 0,totCliReg = 0,totCliCat,totResCli;
    int iRecRegHab = 0,iRecRegHabCli,iCodHab = 1,tamRegHab = 0,totHabReg;
    int iDiaRes = 0, diaRes,iRecRegResHab = 0, iRecRegResDia = 0;

    char cDniCli[10], cCodHab[10];

    FILE *cont_Clientes, *cont_Habitaciones, *cont_Reservas,cont_hcoHabitaciones, *totalGlobalHotel; //.dat
    FILE *habitacionesNuevas, *bajaHcoClientes, *bajaHcoHabitaciones, *bajaHcoReservas; //.txt

    memset(aRegCli,0,sizeof(aRegCli)); //Inicializa todos los elementos del array a 0 o cadena vacia

    importarClientesFichero(aRegCli);
    importarHabitacionFichero(aRegHab);

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

                            altaCliente(aRegCli);

                            break;
                        case 2: //Baja (bien)

                            bajaCliente(aRegCli);

                            break;
                        case 3: //Modificacion (bien)

                            modificacionCliente(aRegCli);

                            break;
                        case 4: //Consulta

                            consultaCliente(aRegCli);

                            break;
                        case 5: //Listado General (bien)

                            listadoGeneralCliente(aRegCli);

                            break;
                        case 6: //Listado por categorias

                            listadoPorCategoriasCliente(aRegCli);

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

                            altaHabitacion(aRegHab);

                            break;
                        case 2: //Baja Habitacion

                            bajaHabitacion(aRegCli,aRegHab);

                            break;
                        case 3: //Modificacion Habitacion

                            modificacionHabitacion(aRegHab);

                            break;
                        case 4: //Consulta Habitacion

                            consultaHabitacion(aRegHab);

                            break;
                        case 5: //Listado General de Habitacion

                            listadoGeneralHabitacion(aRegHab);

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
                do{
                    int eMenRes;

                    menuGestRes();
                    scanf("%i",&eMenRes);

                    switch(eMenRes){
                        case 1: //realizar reserva

                            while (getchar() != '\n');

                            printf("Introduzca Dni a colsultar:");
                            scanf("%s",cDniCli);

                            printf("Introduzca codigo de habitacion:");
                            scanf("%s",cCodHab);

                            asignarReserva(aRegCli,aRegHab,cDniCli,cCodHab);
                            altaReserva(aRegCli,aRegHab,aRegRes,cDniCli,cCodHab);

                            break;
                        case 2: //cancelar reserva
                            break;
                        case 3: // consultar reserva de un cliente
                            break;
                        case 4: //Listado general de reservas

                            listaGeneralReservas(aRegCli,aRegRes);

                            break;
                        case 0:
                            salMenGesRes = false;
                            break;
                        default:
                            salMenGesRes = false;
                            break;
                    }
                }while(salMenGesRes == true);
                break;
            case 4: //Informes Economicos
                break;
            case 5: //Importar Habitaciones desde ficheros

                importarNuevaHabitacionFichero(aRegHab);

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

    guardarClienteFichero(aRegCli);
    guardarHabitacionFichero(aRegHab);

}
