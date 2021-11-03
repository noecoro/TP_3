#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
Employee* employee_new(void)
{
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));
	return auxiliarP;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);//paraliberar lo q pedi con malloc
	}
}


int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if ( this != NULL && id >0 && id <= 100000)
    {
       this-> id = id;
       retorno = 1;
   }
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 127)
    {
        strcpy(this -> nombre, nombre);
        retorno = 1;
    }
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{

		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;

    if ( this != NULL && horasTrabajadas >0 && horasTrabajadas <= 2000 )
    {
        this-> horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return  retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;

    if ( this != NULL && sueldo >0 && sueldo <= 500000 )
    {
        this-> sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if ( this != NULL && sueldo != NULL)
    {
        *sueldo = this -> sueldo;
        retorno = 1;
    }
    return retorno;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {

        if   ( (employee_setId(newEmployee, atoi(idStr)) == -1) ||
                (employee_setNombre(newEmployee, nombreStr) ==-1) ||
                (employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) ==-1)||
                (employee_setSueldo(newEmployee, atoi(sueldoStr)) == -1))
        {

            employee_delete(newEmployee);//como free
            newEmployee = NULL;
        }

    }
    return newEmployee;
}
//Employee* employee_new();//hace un malloc
//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char sueldoStr);
//void employee_delete();
//davila
//void employee_delete(Employee* this);

//int employee_setId(Employee* this,int id);
//int employee_getId(Employee* this,int* id);

//int employee_setNombre(Employee* this,char* nombre);
//int employee_getNombre(Employee* this,char* nombre);

//int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
//int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

//int employee_setSueldo(Employee* this,int sueldo);
//int employee_getSueldo(Employee* this,int* sueldo);
