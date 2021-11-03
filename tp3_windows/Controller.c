#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	 int ok = -1;
	 FILE* pFile;
	    if(path != NULL && pArrayListEmployee != NULL)
	    {

	        pFile = fopen(path, "r");
	        if(pFile != NULL)
	        {
	            if( parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
	            {
	                ok = 1;
	                printf("Empleados cargados correctamente. \n");
	            }
	            else
	            {
	                printf("No se pudieron cargar los empleados.\n");
	            }
	            fclose(pFile);
	        }
	        else
	        {
	            printf("\nEl archivo no pudo abrirse.\n");
	        }
	    }

	    return ok;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	 int ok=-1;
	    FILE* pFile;
	    if(path!=NULL && pArrayListEmployee!=NULL)
	    {

	        pFile=fopen(path,"rb");
	        if( pFile != NULL)
	        {
	            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==1)
	            {
	                ok=1;
	                printf("Empleados cargados correctamente. \n");
	            }
	            else
	            {
	                printf("No se pudieron cargar los empleados.\n");
	            }

	        }
	        else
	        {
	            printf("\nEl archivo no pudo abrirse.\n");
	        }
	        fclose(pFile);
	    }
	    return ok;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	 char nombre[128];
	    int id ;
	    int horasTrabajadas;
	    int sueldo;
	    int nuevoNombre;
	    int nuevaHorasTrabajadas;
	    int nuevoSalario;
	    char horasTrabajadasStr[20];
	    char sueldoStr[20];
	    char idStr[20];
	    int empAgregado = -1;
	    Employee* auxEmployee;
	   // system("cls");
	    printf("=== Alta nuevo empleado === \n\n");

	    if ( pArrayListEmployee != NULL)
	    {
	    	nuevoNombre = utn_getNombre(nombre, 127,"Ingrese nuevo nombre: ", "El nombre solo puede contener letras .\n",  3);
	    	nuevaHorasTrabajadas = utn_getNumero(&horasTrabajadas, "Ingrese la nueva cantidad de horas trabajadas: ", "La cantidad de horas debe ser un numero del 1 al 2000.\n", 1, 2000, 3);
	    	nuevoSalario = utn_getNumero(&sueldo, "Ingrese el nuevo sueldo: ", "El sueldo debe ser entre 1 y 500000.\n", 1, 500000, 3);

	        if(nuevoNombre && nuevaHorasTrabajadas && nuevoSalario  )
	        {
	        	obtenerIdDelArchivo(&id);//

	            strlwr(nombre);
	            nombre[0]= toupper(nombre[0]);
	            /*
	             Esta función se utiliza para convertir un valor numérico
	             en una cadena de texto, es decir, que permite convertir
	              un número entero en un texto. La cadena contendrá tantos
	              carácteres como dígitos tenga el resultado.
	             */
	            itoa(horasTrabajadas, horasTrabajadasStr, 10);
	            itoa(sueldo, sueldoStr, 10);
	            itoa(id, idStr, 10);
	            auxEmployee = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);
	            if (auxEmployee != NULL)
	            {
	                ll_add(pArrayListEmployee, auxEmployee);
	                printf("Se ha agregado satisfactoriamente el empleado.\n");

	                actualizarId(id);

	                empAgregado = 1;
	            }

	        }
	        else
	        {
	            printf("Se produjeron errores durante la carga del empleado. Por favor intentelo de nuevo\n");

	        }
	    }
	    system("pause");
	    return empAgregado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
/** \brief abre el archivo proximoId.bin en modo lectura, si no existe lo crea y si existe lee el numero de id que contiene y lo guarda en la variable recibida por parametro
 *
 * \param puntero a varible del tipo entero
 * \return devuelve 1 si pudo conseguir el id del archivo y -1 si el archivo no existia
 *
 */
int obtenerIdDelArchivo(int* id)
{

    *id = 1001;
    int succes = -1;

    FILE* f;
    f = fopen("proximoId.bin","rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        succes = 1;
    }

    return succes;
}
/** \brief al id recibido por parametro le suma 1 y lo escribe en el archivo proximoId.bin
 *
 * \param variable del tipo entero
 * \return 1 si pudo actualizar el archivo con la nueva variable, -1 en caso contrario
 *
 */

int actualizarId(int id)
{
    int proxId =id;
    proxId++;
    int succes  = -1;
    FILE* f;
    f = fopen("proximoid.bin","wb");

    if(f != NULL)
    {
        fwrite(&proxId,sizeof(int),1,f);

        fclose(f);
        succes = 1;
    }

    return succes;
}
