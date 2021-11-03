#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	  int cantParametros;//4
	    Employee* auxEmployee;
	    int ok = -1;
	   // char buffer[4][100];
	    char auxId[1024];//100
	    char auxNombre[1024];
	    char auxHsTrabajadas[1024];
	    char auxSueldo[1024];

	    if (pFile != NULL  && pArrayListEmployee != NULL)
	    {
	        fscanf(pFile, "%*[^\n]\n");//text fscanf
	        while(!feof(pFile))//si no lo lee hasta el final  es  para q  vaya linea a linea//para q lea todo el archivo linea a linea
	        {
	            auxEmployee = employee_new();
	            cantParametros = fscanf(pFile,"%[^,] , %[^,], %[^,], %[^\n]\n",auxId ,auxNombre,auxHsTrabajadas ,auxSueldo );//fscanf leo cada uno de  los campos de la 1er linea dnd tengo datos id nomb sueldo hs, cuando termino de leer tengo q asegurarme q leyo 4 elementos
	            if(cantParametros == 4)//si leyo los 4 datos
	            {
	                auxEmployee = employee_newParametros(auxId ,auxNombre,auxHsTrabajadas ,auxSueldo);
	                ll_add(pArrayListEmployee, auxEmployee);
	                ok = 1;
	            }
	            else
	            {
	                break;
	            }
	        }
	    }

	    return ok;
}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    Employee* auxEmployee;

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee=employee_new();
            if ( fread ( auxEmployee, sizeof(Employee),1,pFile) != 0)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                ok = 1;
            }
        }

    }
    return ok;

}
