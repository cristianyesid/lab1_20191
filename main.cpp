#include<iostream>
#include<typeinfo>

using namespace std;

struct Complex
{
	/* 1. Se deben declarar dos miembros tipo double para
	la parte real e imaginaria del numero complejo */
	double real;
	double imag;
};

/* 2. Declare una estructura local de tipo Complex llamada complejo, inicialice sus miembros con los
   valores que usted desee */
   
   struct Complex complejo;
   complejo.real=25.6;
   complejo.imag=31.11;
   
/* 3. Declare una variable llamada "state" que puede cambiar desde el valor
   INICIAL, pasando por los valores PREPARACION y TRABAJANDO hasta el valor FINALIZACION
   el valor INICIAL equivale a 2 */

enum state = {INICIAL=2,PREPARACION,TRABAJANDO,FINALIZACION};

/* 4. Declare una variable global que debe almacenar un valor entero positivo mayor a 4294967296
   y ademas debe poderse compartir entre distintos archivos de codigo fuente .cpp */
extern unsigned long int n1;

/* 5. Declare de las dos maneras expuestas en clase dos cantidades constantes globales con los
   valores 3.1416 y 123456789.987654321123456789567444433321 */
   
   const float g1= 3.1416;
   #define g2= 123456789.987654321123456789567444433321;

/* 6. Declare una variable global de tipo entero que a lo sumo puede almacenar numeros en 2 bytes 
   y solo puede visibilizarse dentro de este archivo de codigo fuente*/
   
   static short int n2;

/* 7. Corrija la siguiente declaracion para que el compilador no arroje un error (o warning) por
   incumplir con el criterio de "Semantica" al usar el lenguaje C++ */

unsigned float latina_stereo = 100.9;

/* 8. La siguiente funcion (mas adelante aprenderemos mas de funciones) necesita que se le declare
   una variable (llamada extr_var) de tipo caracter, cuyo valor simpre sera positivo, y que ademas puede cambiar en 
   cualquier momento debido a una interrupcion por el hardware de un periferico conectado al PC */

void funcion_no_optimizable(void)
{
	/*Declare la variable extr_var aqui */
  volatile unsigned char extr_var;
	if(&extr_var != NULL)
		cout<<"2. Optimizer no debe optimizar a extr_var.."<<endl;
}

/* 9. La siguiente funcion tiene un problema, reparela para que pueda correr bien */
void funcion_erronea(void)
{
  double x = 14e12;
	cout<<"3. El valor de x en la funcion erronea es: "<<x<<endl;
}

/* 10. En la siguiente funcion asigne el tipo de dato adecuado a la variable "result"
   para que no haya problemas de compilacion */
void tipo_del_resultado(void)
{
	int Int = -45;
	unsigned char Char = 125;
	short Short = 10500;
	float Float = 62.23;
	double Double = 3.8678908e5;
	
	double result = Float * Int + Char + Double - Short;
	cout<<"4. El tipo de dato de result en la funcion resultado es: "<<typeid(result).name()<<endl;
}

/* 11. La siguiente funcion necesita una modificacion en la declaracion de result para que no
   haya perdida de datos ni truncamientos luego de ejecutar la operacion matematica 
   Ademas necesita de otra modificacion para evitar un warning...   */
   
void declaracion_explicita(void)
{
	double oper_1 = 5678983456.44444444444;
	unsigned long double oper_2 = 5e15;
	unsigned long double result = 0;
	
	result = oper_1 + oper_2;
	cout<<"5. El tipo de dato de result "<<result<<" en la funcion declaracion_explicita es: "<<typeid(result).name()<<endl;
}

/* 12. funcion_necesitada requiere el valor de la variable letr_a de funcion_amiga, haga las declaraciones
   y/o asignaciones (modificaciones) necesarias para que funcion_necesitada pueda visibilizar el valor de letra_a */

void funcion_amiga(void)
{
	const unsigned char letra_a;
	letra_a = 'A';
}
unsigned char modificacion;
void funcion_necesitada(void)
{
  unsigned char letra_a= modificacion;
	if(letra_a == 'A')
		cout<<"6. Es el caracter esperado: "<<letra_a<<endl;
	else
		cout<<"Esperando el caracter adecuado..."<<endl;
			
}

void state_machine(void)
{
	static unsigned int sm_counter = 0x30;   /* Esta variable debe almacenar un valor entero positivo menor a 256
	                     Ademas el valor de la variable debe conservarse entre llamados de la funcion
						 Inicialice esta variable con el valor 0x30;*/
						 
	/* De aqui en adelante y por el resto de la funcion, no es necesario que modifique nada */
	
	switch (state){
		case INICIAL:
			cout<<"Estado incial de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = PREPARACION;
			break;
		case PREPARACION:
			cout<<"Estado preparacion de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = TRABAJANDO;
			break;
		case TRABAJANDO:
			cout<<"Estado en trabajo de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = FINALIZACION;
			break;
		case FINALIZACION:
			cout<<"Estado en finalizacion de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = INICIAL;
			sm_counter = 0x30;
			break;
		default:
			state = INICIAL;
			sm_counter = 0x30;
			break;
	}			
}

/* 13. Pregunta para profundizar: Suponga que usted declara dos variables int a = -1 y unsigned int b = 2
   Luego suponga que usted compara (en C++) las dos variables para saber cual es mayor. ¿Cuál diria C++ que es la mayor entre a y b?b
   ¿Por qué? Porque 2 es mayor que 1 ¿Cuál sería la forma adecuada de hacer la comparación en C++? Creo una variable llamada 'menor' 
   de tipo entero le asigno el valor de 'a', luego comparo, si 'menor' es mayor que 'b', entonces 'menor' toma el valor de b*/

int main()
{	/* Espacio para declaraciones en la funcion main */
	
	
	/* De esta linea en adelante usted no debe modificar nada */
	cout<<"1. Complejo es igual a: "<<complejo.real<<((complejo.imag > 0)?"+":"-")<<(abs(complejo.imag))<<"j"<<endl;
	
	funcion_no_optimizable();
	funcion_erronea();
	tipo_del_resultado();
	declaracion_explicita();
	funcion_amiga();
	funcion_necesitada();
	for(int i = 0; i<5; i++)
		state_machine();
	
	return 0;
}
