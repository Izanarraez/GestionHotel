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
    char cdHab[10];
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
    printf("   4.- Listado General de Reservas\n");
    printf("   0.- Volver al Menu Principal\n");
    printf("Elija opcion:");
}

void menuGesInf(){
    printf("\nINFORMES ECONOMICOS\n");
    barraSeparadora();
    printf("   1.- Informe Mensual por Categoria de Cliente\n");
    printf("   2.- Informe Mensual de Ocupacion de Habitaciones\n");
    printf("   3.- Informe Mensual de Ingresos por Reservas\n");
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
int buscarCliente(tRegCliente *aRegCli,char *cDni){
    for(int i = 0;i<Max_clientes;i++){
        if(strcmp(aRegCli[i].dni,cDni)==0){
            return i;
        }
    }
    return -1;
}

int buscarHabitacion(tRegHabitacion *aRegHab,char *cdHab){
    for(int i = 0;i<Max_habitaciones;i++){
        if(strcmp(aRegHab[i].cdHab,cdHab)==0){
            return i;
        }
    }
    return -1;
}

int buscarReservaCliente(tRegCliente *aRegCli,char *cDni){

    int posCli = buscarCliente(aRegCli,cDni);

    for(int i = 0;i < 5;i++){
        if(strcmp(aRegCli[i].dni,cDni) == 0){
            return i;
        }
    }
    return -1;
}

int contRegCli(tRegCliente *aRegCli){
    int cont = 0;
    for(int i = 0;i<Max_clientes;i++){
        if(strlen(aRegCli[i].nom_apell) > 0 && strlen(aRegCli[i].dni) > 0 && strlen(aRegCli[i].tp_cli) > 0){
            cont++;
        }
    }
    return cont;
}

int contRegHab(tRegHabitacion *aRegHab){
    int cont = 0;
    for(int i = 0;i<Max_habitaciones;i++){
        if(strlen(aRegHab[i].cdHab) > 0 && strlen(aRegHab[i].tipo) > 0 && aRegHab[i].precio > 0){
            cont++;
        }
    }
    return cont;
}

int numeroHabitacionesReservadas(tRegCliente *aRegCli,int posicion){
    int cont = 0;
    if(posicion != -1){
        for(int i=0;i<5;i++){
            if(strlen(aRegCli[posicion].rs_hab[i].cdHab)>0){
                cont++;
            }
        }
    }
    return cont;
}

bool habitacionesReservadas(tRegCliente *aRegCli,tRegHabitacion *aRegHab,int posicion){

    if(posicion != -1){
        for(int i= 0;i<Max_clientes;i++){
            for(int j=0;j<5;j++){
                if(strcmp(aRegCli[i].rs_hab[j].cdHab,aRegHab[posicion].cdHab) == 0){
                    return true;
                }
            }
        }
    }
    return false;
}


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

int encontrarMayorNumero(tRegHabitacion *aRegHab) {
    int mayor = -1; // Inicializamos con un valor negativo

    for (int i = 0; i < Max_habitaciones; i++) {
        // Buscamos el guión bajo '_' en la cadena
        char *underscore = strchr(aRegHab[i].cdHab, '_');

        if (underscore != NULL) {
            // Convertimos la parte después del '_' a número
            int numero = atoi(underscore + 1);

            if (numero > mayor) {
                mayor = numero;
            }
        }
    }

    return mayor;
}

/*bool diaYaReservado(char (*aRegRes)[31][10],char *cCodHab){
    for(int i = 0;i < Max_habitaciones;i++){
        fr(int j = 0;j < 31;j++){
           if(strcmp(aRegRes[i][j],cCodHab) == 0){
                return true;
           }
        }
    }
    return false;
}*/

void errEscFich(size_t eleEsc,size_t numEle){
    if (eleEsc != numEle) {
        perror("Error al escribir en el archivo");
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

    int iRegCli = contRegCli(aRegCli);
    printf("%i",iRegCli);
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

    char cDniCli[12],resCli[4];

    FILE *clientes;

    while (getchar() != '\n');

    printf("Introduzca Dni para dar de baja");
    scanf("%s",cDniCli);

    int posCli = buscarCliente(aRegCli,cDniCli);
    int tamCli = contRegCli(aRegCli);

    if(tamCli != 0){
        tamCli = contRegCli(aRegCli) - 1;
    }

    if(posCli != -1){
        printf("¿Desea dar de baja a este ciente?(S/N)");
        scanf("%s",resCli);
        if(strcmp(resCli,"S") == 0 && numeroHabitacionesReservadas(aRegCli,posCli) == 0){

            clientes = apertCorrTxt("bajaHcoClientes.txt");
            fprintf(clientes,"%s-%s-%s\n",aRegCli[posCli].dni,aRegCli[posCli].nom_apell,aRegCli[posCli].tp_cli);
            fclose(clientes);

            strcpy(aRegCli[posCli].nom_apell,aRegCli[tamCli].nom_apell);
            strcpy(aRegCli[posCli].dni,aRegCli[tamCli].dni);
            strcpy(aRegCli[posCli].tp_cli,aRegCli[tamCli].tp_cli);

            strcpy(aRegCli[tamCli].nom_apell,"\0");
            strcpy(aRegCli[tamCli].dni,"\0");
            strcpy(aRegCli[tamCli].tp_cli,"\0");

            resAso = false;
        }
        dniNoEnc = false;
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
    char cDniCli[12];

    while (getchar() != '\n');

    printf("\nIntroduzca Dni para modificar un cliente");
    scanf("%s",cDniCli);

    int posCli = buscarCliente(aRegCli,cDniCli);

    if(posCli != -1){

        while (getchar() != '\n');

        printf("Introduzca nombre:");
        scanf("%s",aRegCli[posCli].nom_apell);

        printf("Introduce Tipo Cliente:");
        scanf("%s",aRegCli[posCli].tp_cli);
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
    char cDniCli[12];

    while (getchar() != '\n');

    printf("Introduzca Dni a colsultar:");
    scanf("%s",cDniCli);

    int posCli = buscarCliente(aRegCli,cDniCli);

    if(posCli != -1){
        printf("Nombre y Apellidos:%s\n",aRegCli[posCli].nom_apell);
        printf("DNI:%s\n",aRegCli[posCli].dni);
        printf("Tipo de Cliente:%s\n",aRegCli[posCli].tp_cli);

        if(numeroHabitacionesReservadas(aRegCli,posCli) == 0){
            printf("Habitaciones Reservadas:%i\n",0);
        }
        else{
            for(int i = 0;i < 5;i++){
                if(strlen(aRegCli[posCli].rs_hab[i].cdHab) > 0){
                    printf("Habitaciones Reservadas:%s\n",aRegCli[posCli].rs_hab[i].cdHab);
                }
            }
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

    int totCliReg = contRegCli(aRegCli);

    for(int iRecRegCli = 0;iRecRegCli<Max_clientes;iRecRegCli++){
        if(strlen(aRegCli[iRecRegCli].nom_apell) > 0 && strlen(aRegCli[iRecRegCli].dni) > 0 && strlen(aRegCli[iRecRegCli].tp_cli) > 0){
            printf("%i\t%s\t\t%s\t\t%s\n",iRecRegCli,aRegCli[iRecRegCli].nom_apell,aRegCli[iRecRegCli].dni,aRegCli[iRecRegCli].tp_cli);
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

    int iRegHab = contRegHab(aRegHab);

    printf("%i",iRegHab);
    while (getchar() != '\n');
    printf("%i",encontrarMayorNumero(aRegHab));
    sprintf(aRegHab[iRegHab].cdHab, "HAB_%03d", encontrarMayorNumero(aRegHab)+1);

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

    int posHab = buscarHabitacion(aRegHab,cCodHab);
    //printf("%i",posHab);
    int tamHab = contRegHab(aRegHab);

    if(tamHab != 0){
        tamHab = contRegHab(aRegHab) - 1;
    }
    //printf("%i",tamHab);

    if(posHab != -1){
        if(habitacionesReservadas(aRegCli,aRegHab,posHab) == false){

            cont_Habitaciones = apertCorrTxt("bajaHcoHabitaciones.txt");
            fprintf(cont_Habitaciones,"%s-%s-%s\n",aRegHab[posHab].cdHab,aRegHab[posHab].tipo,fechForm);
            fclose(cont_Habitaciones);

            strcpy(aRegHab[posHab].cdHab,aRegHab[tamHab].cdHab);
            strcpy(aRegHab[posHab].tipo,aRegHab[tamHab].tipo);
            aRegHab[posHab].precio = aRegHab[tamHab].precio;

            strcpy(aRegHab[tamHab].cdHab,"\0");
            strcpy(aRegHab[tamHab].tipo,"\0");
            aRegHab[tamHab].precio = 0;

            habNoResv = false;
        }
        habNoEnc = false;
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

    int totHabReg = contRegHab(aRegHab);
    int iRecRegHab;

    printf("\nCodigo\tTipo\t\tPrecio/Noche)\n");
    for(iRecRegHab = 0;iRecRegHab < Max_habitaciones;iRecRegHab++){
        if(strlen(aRegHab[iRecRegHab].cdHab) > 0 && strlen(aRegHab[iRecRegHab].tipo) > 0 && aRegHab[iRecRegHab].precio > 0){
            printf("%i\t%s\t\t%s\t%f\n",iRecRegHab,aRegHab[iRecRegHab].cdHab,aRegHab[iRecRegHab].tipo,aRegHab[iRecRegHab].precio);
        }
    }
    printf("Total: %i habitaciones registradas.\n",totHabReg);
}

void altaReserva(tRegCliente *aRegCli, tRegHabitacion *aRegHab, char (*aRegRes)[31][12],char *cDniCli,char *cCodHab){

    int diaRes = 0;

    while (getchar() != '\n');

    do{
        printf("Introduzca dia a reservar:");
        scanf("%i",&diaRes);
    }while(diaRes < 1 || diaRes > 30);

    int posCli = buscarCliente(aRegCli,cDniCli);
    int posHab = buscarHabitacion(aRegHab,cCodHab);

    if(habitacionesReservadas(aRegCli,aRegHab,posHab) == false && numeroHabitacionesReservadas(aRegCli,posCli) < 5 && aRegRes[posHab][diaRes][0] == '\0' && posCli != -1 && posHab != -1){
        strcpy(aRegRes[posHab][diaRes],aRegCli[posCli].dni);
        printf("Alta realizada con éxito\n");
    }
    else{
        printf("No se pudo dar de alta la reserva");
    }
}

tRegCliente *asignarReserva(tRegCliente *aRegCli, tRegHabitacion *aRegHab,char *cDniCli,char *cCodHab){

    int posCli = buscarCliente(aRegCli,cDniCli);
    int posHab = buscarHabitacion(aRegHab,cCodHab);

    int totResCli = numeroHabitacionesReservadas(aRegCli,posCli);

    if(habitacionesReservadas(aRegCli,aRegHab,posHab) == false && numeroHabitacionesReservadas(aRegCli,posCli) < 5 && posCli != -1 && posHab != -1){
        strcpy(aRegCli[posCli].rs_hab[totResCli].cdHab,aRegHab[posHab].cdHab);
        strcpy(aRegCli[posCli].rs_hab[totResCli].tipo,aRegHab[posHab].tipo);
        aRegCli[posCli].rs_hab[totResCli].precio = aRegHab[posHab].precio;
    }
    return aRegCli;
}

void bajaReserva(tRegCliente *aRegCli, char (*aRegRes)[31][12],char *cDniCli){

    int posCli = buscarCliente(aRegCli,cDniCli);
    int posResCli = buscarReservaCliente(aRegCli,cDniCli);

    int tamRes = numeroHabitacionesReservadas(aRegCli,posCli);

    if(tamRes != 0){
        tamRes = numeroHabitacionesReservadas(aRegCli,posCli) - 1;
    }

    if(posCli != 0 && posResCli != -1){
       strcpy(aRegCli[posCli].rs_hab[posResCli].cdHab,aRegCli[posCli].rs_hab[tamRes].cdHab);
       strcpy(aRegCli[posCli].rs_hab[posResCli].tipo,aRegCli[posCli].rs_hab[tamRes].tipo);
       aRegCli[posCli].rs_hab[posResCli].precio = aRegCli[posCli].rs_hab[tamRes].precio;

       strcpy(aRegCli[posCli].rs_hab[tamRes].cdHab,"/0");
       strcpy(aRegCli[posCli].rs_hab[tamRes].tipo,"/0");
       aRegCli[posCli].rs_hab[tamRes].precio = 0;

        for(int i = 0;i < Max_habitaciones;i++){
            for(int j = 0;j < 31;j++){
                if(strcmp(aRegRes[i][j],cDniCli) == 0){
                    strcpy(aRegRes[i][j],0);
                }
            }
        }
    }
}

void consultarReservasCliente(tRegCliente *aRegCli){

    char cdDni[12];
    float importeTot = 0;

    while (getchar() != '\n');

    printf("Introduzca dni a consultar");
    scanf("%s",cdDni);

    int posCli = buscarCliente(aRegCli,cdDni);

    for(int i = 0;i< 5;i++){
        if(strlen(aRegCli[posCli].rs_hab[i].cdHab) > 0){
            printf("Habitaciones reservadas %s",aRegCli[posCli].rs_hab[i].cdHab);

            importeTot = importeTot + aRegCli[posCli].rs_hab[i].precio;
        }
    }
    printf("Importe Total %f",importeTot);
}

void listaGeneralReservas(tRegCliente *aRegCli, char (*aRegRes)[31][12]){

    printf("\nEstado de reservas:\n");
    for(int i = 0; i < Max_habitaciones; i++) {
        for(int j = 0; j < 31; j++) {
            if(aRegRes[i][j][0] != '\0') {
                printf("Hab %d, día %i: %s\n", i,j+1, aRegRes[i][j]);
            }
        }
    }
}

tRegHabitacion *importarNuevaHabitacionFichero(tRegHabitacion *aRegHab){
    int iRegHab = contRegHab(aRegHab);
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

            sprintf(aRegHab[iRegHab].cdHab, "HAB_%03d", encontrarMayorNumero(aRegHab)+1);
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
    FILE *clientes = lecCorr("clientes.dat");

    size_t numLeiCli = fread(aRegCli, sizeof(tRegCliente), Max_clientes, clientes);
    fclose(clientes);

    if (numLeiCli != Max_clientes) {
        printf("Error al leer el fichero o el fichero no contiene suficientes datos.\n");
    }
}

void importarHabitacionFichero(tRegHabitacion *aRegHab){
    FILE *habitaciones = lecCorr("habitaciones.dat");

    size_t numLeiHab = fread(aRegHab, sizeof(tRegHabitacion), Max_habitaciones, habitaciones);
    fclose(habitaciones);

    if (numLeiHab != Max_habitaciones) {
        printf("Error al leer el fichero o el fichero no contiene suficientes datos.\n");
    }
}

void importarReservasFichero(char (*aRegRes)[31][12]){
    FILE *reservas = lecCorr("reservas.dat");

    size_t elemHab = 31 * 12;
    size_t totElem = Max_habitaciones * elemHab;

    size_t numLeiRes = fread(aRegRes, sizeof(char), totElem, reservas);
    fclose(reservas);

    if (numLeiRes != totElem) {
        printf("Error al leer el fichero o el fichero no contiene suficientes datos.\n");
    }
}

void informeMensualCategoriasCliente(tRegCliente *aRegCli){

    int norm = 0,vip = 0,empre = 0;
    int normCan = 0,vipCan = 0,empreCan = 0; //cantidad monetaria
    printf("\nINFORME MENSUAL (Por categorias de clientes)");
    barraSeparadora();

    for(int i = 0;i < Max_clientes;i++){
        for(int j = 0; j < 5;j++){
            if(strcmp(aRegCli[i].rs_hab[j].tipo,"NORMAL")){
                normCan += aRegCli[i].rs_hab[j].precio;
                norm++;
            }
            if(strcmp(aRegCli[i].rs_hab[j].tipo,"VIP")){
                vipCan += aRegCli[i].rs_hab[j].precio;
                vip++;
            }
            if(strcmp(aRegCli[i].rs_hab[j].tipo,"EMPRESA")){
                empreCan += aRegCli[i].rs_hab[j].precio;
                empre++;
            }
        }
    }

    printf("\n** Numero de clientes\n");
    printf("\nNormal:%i",norm);
    printf("\nVip:%i",vip);
    printf("\nEmpre:%i",empre);
    printf("\nTotal:%i Clientes",norm+vip+empre);

    printf("\n** Importe Registrados\n");
    printf("\nNormal:%i $",normCan);
    printf("\nVip:%i $",vipCan);
    printf("\nEmpre:%i $",empreCan);
    printf("\nImporte Total:%i $",normCan+vipCan+empreCan);
}

void informeMensualOcupacionHabitacion(tRegHabitacion *aRegHab){

    int ocup = contRegHab(aRegHab);
    float tot = (ocup*100)/Max_habitaciones;
    printf("\nINFORME MENSUAL (Ocupacion de Habitaciones)\n");
    barraSeparadora();

    printf("\nTotal Habitaciones: %i",Max_habitaciones);
    printf("\nOcupadas: %i",ocup);
    printf("\nLibres: %i",Max_habitaciones - ocup);
    printf("\nPorcentaje de ocupacion: %f %%\n",tot);

}

void guardarClienteFichero(tRegCliente *aRegCli){
    FILE *clientes = apertCorr("clientes.dat");
    size_t numEscCli = fwrite(aRegCli, sizeof(tRegCliente), Max_clientes, clientes);
    fclose(clientes);

    if (numEscCli != Max_clientes) {
        printf("Error: No se escribieron todos los datos en el fichero.\n");
    } else {
        printf("Datos guardados correctamente en el fichero.\n");
    }
}

void guardarHabitacionFichero(tRegHabitacion *aRegHab){
    FILE *habitaciones = apertCorr("habitaciones.dat");
    size_t numEscHab = fwrite(aRegHab, sizeof(tRegHabitacion), Max_habitaciones, habitaciones);
    fclose(habitaciones);

    if (numEscHab != Max_habitaciones) {
        printf("Error: No se escribieron todos los datos en el fichero.\n");
    } else {
        printf("Datos guardados correctamente en el fichero.\n");
    }
}

void guardarReservasFichero(char (*aRegRes)[31][12]){
    FILE *reservas = apertCorr("reservas.dat");

    size_t elemHab = 31 * 12;
    size_t totElem = Max_habitaciones * elemHab;

    size_t numEscRes = fwrite(aRegRes, sizeof(char), totElem, reservas);
    fclose(reservas);

    if (numEscRes != totElem) {
        printf("Error: No se escribieron todos los datos en el fichero.\n");
    } else {
        printf("Datos guardados correctamente en el fichero.\n");
    }
}

void main(){


    printf("¡Bienvenido a la aplicacion GEST_HOTEL!");

    bool salMenIni = true, salMenGesCli = true, salMenGesHab = true, salMenGesRes = true, salMenInf = true;

    tRegCliente aRegCli[Max_clientes];
    tRegHabitacion aRegHab[Max_habitaciones];
    char aRegRes[Max_habitaciones][31][12];

    char cDniCli[12], cCodHab[10];

    memset(aRegCli,0,sizeof(aRegCli)); //Inicializa todos los elementos del array a 0 o cadena vacia
    memset(aRegRes,0,sizeof(aRegRes));

    importarClientesFichero(aRegCli);
    importarHabitacionFichero(aRegHab);
    importarReservasFichero(aRegRes);

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

                            altaReserva(aRegCli,aRegHab,aRegRes,cDniCli,cCodHab);
                            asignarReserva(aRegCli,aRegHab,cDniCli,cCodHab);

                            break;
                        case 2: //cancelar reserva

                            while (getchar() != '\n');

                            printf("Introduzca Dni a colsultar:");
                            scanf("%s",cDniCli);

                            bajaReserva(aRegCli,aRegRes,cDniCli);

                            break;
                        case 3: // consultar reserva de un cliente

                            consultarReservasCliente(aRegCli);

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
                do{
                    int eMenInf;

                    menuGesInf();
                    scanf("%i",&eMenInf);

                    switch(eMenInf){
                        case 1:
                            informeMensualCategoriasCliente(aRegCli);
                            break;
                        case 2:
                            informeMensualOcupacionHabitacion(aRegHab);
                            break;
                        case 3:
                            break;
                        case 0:
                            salMenInf = false;
                            break;
                        default:
                            salMenInf = false;
                            break;
                    }
                }while(salMenInf == true);
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
    guardarReservasFichero(aRegRes);

}
