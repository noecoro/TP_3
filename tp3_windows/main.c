#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	char confirm = 0;
	char seguir = 's';

	// LinkedList* listaEmpleados;//tiene cero lugares crece a medida q la uso si esta es xq tiene algo
  //  int option = 0;
    printf("lalalla\n");
    //Employee* pE;
    //pE = empleado_newparam("lalal","lalla2")
//ll_newLinkedList(); constructor de la lista va a tener la posicio de memor del 1er elemento de esa lista
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	//imprimir el men
        switch(menu())
        {
            case 1://listaEmpleados lista dndn tiene  q ir a parar los datos
                controller_loadFromText("data.csv",listaEmpleados);// "data.csv" nombre compelto con la extension del archivo
                printf("case1lalla\n");
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaEmpleados);
            	printf("case2  lalla\n");
            	break;
            case 3:
                break;
            case 4:
                break;
            case 5:
               break;
            case 6:
               break;
            case 7:
               break;
            case 8:
               break;
            case 9:
               break;
            case 10:
                printf("Desea salir? s/n : ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (confirm == 's')
               {
                	seguir = 'n';
               }
               break;
        }
    }while(seguir == 's');
   // ll_deleteLinkedList(listaEmpleados);
    return 0;
}
//imprimir con lindkedlist lidta dinamica
//void funcionImprimir(Linkedlist* listaEmpleados){
/*for(int i=0; i < ll_len(listaEmpleados); i++)
{
	pE = ll_get(listaEmpleados,i);
	printf("nombre: %s",emp_getNombre(pE,&flagError));
}}*/

