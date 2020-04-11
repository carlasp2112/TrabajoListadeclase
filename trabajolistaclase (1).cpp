#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Instituto{ // Creamos la clase Instituto
	private://atributos
		string nombreArchivo;
		string linea;
	public: // Metodos de la clase Instituto
		void escribir();
		void leer();
		void annadir();
		void fechaexamen();	
		void verexamen();
};

void Instituto::escribir(){ //Explicación del método escribir de la clase instituto
	ofstream archivo; //Creamos y abrimos el archivo para meter datos
	int alumno;
	cout<<"que lista de clase quieres crear(1B, 2A...): ";
	getline(cin,nombreArchivo); //Nos permite escribir por teclado
	archivo.open(nombreArchivo.c_str(),ios::out);//convierte el nombre en una cadena con comillas; dentro del sistema de entrada y salida, la accion que se va a realizar es de tipo out(salida)
	
	if(archivo.fail()){
		cout<<"No pude abrir el archivo";
		exit(1);
	
	}
	cout<<"¿Cuantos alumnos quieres annadir?";
	cin>>alumno;
	for(int i ; i<=alumno;i++){
	cout << "introduce el nombre del alumno que pertence a esta clase..."<<endl;
	getline(cin,linea);//Mete la informacion escrita por teclado a la siguiente linea del archivo
	archivo<<linea<<endl;
	}
	archivo.close();//Cerrar el archivo
}

void Instituto::leer(){
	ifstream archivo; //Abre un fichero  de entrada(lectura)
	cout << "Que clase quieres leer:";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in); //abre para leer el nombre del archivo que ponemos por teclado
	
	if(archivo.fail()){ //Cuandno no encentra el nombre del archivo, da error
		cout << "Esa clase no existe";
		exit(1);
	}
	while(!archivo.eof()){ //Utilizamos eof para comprobar si el archivo existe y luego abrirlo entero
		getline(archivo,linea);//Mete la informacion escrita por teclado a la siguiente linea del archivo
		cout << linea << endl;
	}
	archivo.close();//Cerrar el archivo
}

void Instituto::annadir(){
	ofstream archivo;//Creamos y abrimos el archivo para meter datos
	int nalumno;
	
	cout << "Que lista de clase quieres modificar:";
	getline(cin,nombreArchivo);//Escribe por teclado en el archivo que tenga el nombre metido por teclado
	archivo.open(nombreArchivo.c_str(),ios::app);//ios::app se utiliza para añadir contenido al archivo
	
	if(archivo.fail()){ //Si el nombre del archivo no existe da error
		cout << "Esa clase no existe";
		exit(1);
	}
	cout<<"¿Cuantos alumnos quieres annadir?";
	cin>>nalumno;
	for(int i ; i<=nalumno;i++){
	cout << "Nombre del alumno quieres annadir..."<<endl;
	getline(cin,linea);//Mete la informacion escrita por teclado a la siguiente linea del archivo
	archivo<<linea<<endl;
	}
	archivo.close();//Cerrar el archivo
	
}

void Instituto::fechaexamen(){
	ofstream archivo;//Creamos y abrimos el archivo para meter datos
	int examen;
		cout<<"El nombre del archivo que guarda la fecha de los exámenes: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::out);//convierte el nombre en una cadena con comillas; dentro del sistema de entrada y salida, la accion que se va a realizar es de tipo out(salida, escribir)
	
	if(archivo.fail()){
		cout<<"No pude abrir el archivo";
		exit(1);
	
	}
	cout<<"¿Cuantos examenes quieres annadir?";
	cin>>examen;
	for(int i ; i<=examen;i++){
	cout << "Introduce el nombre de la asignatura y el dia del examen"<<endl;
	getline(cin,linea);//Mete la informacion escrita por teclado a la siguiente linea del archivo
	archivo<<linea<<endl;
	}
	archivo.close();//Cerrar el archivo
}

void Instituto::verexamen(){
	ifstream archivo;//Abre un fichero  de entrada(lectura)	string nombreArchivo;
	cout << "¿Como se llama el archivo con examenes que quieres ver?:";
	getline(cin,nombreArchivo);//Nos permite escribir por teclado
	archivo.open(nombreArchivo.c_str(),ios::in);//abre para leer el nombre del archivo que ponemos por teclado
	
	if(archivo.fail()){
		cout << "Esa archivo no existe";
		exit(1);
	}
	while(!archivo.eof()){//Utilizamos eof para comprobar si el archivo existe y luego abrirlo entero
		getline(archivo,linea);
		cout << linea << endl;
	}
	archivo.close();//Cerrar el archivo
}

int main(){
	int numero;
	Instituto n1;
	do{ //Menu con distintas opciones para cada numero del 1 al 6
		cout<<"\n";
		cout <<"***************** INSTITUTO ********************"<<endl;
		cout<<"***** 1.-Crear lista de alumnos de una clase. *****"<<endl;
		cout<<"***** 2.-Ver lista de alumnos*****"<<endl;
		cout<<"***** 3.-Annadir alumnos a una lista existente *****"<<endl;
		cout<<"***** 4.-Hacer lista de examenes *****"<<endl;
		cout<<"***** 5.-Ver lista de examenes *****"<<endl;
		cout<<"***** 6.-Salir *****"<<endl;
		cout<<"***************************************************"<<endl;
		cout<<"Selecciona una opcion: ";
		cin>>numero;
		cin.ignore(256,'\n');//Vaciar el buffer
		
		switch(numero){ //Según el número que reciba realizará una acción u otra
			case 1: n1.escribir();
				break;
			case 2: n1.leer();
				break;
			case 3: n1.annadir();
				break;
			case 4: n1.fechaexamen(); 
				break;
			case 5: n1.verexamen(); 
				break;
			case 6: cout<<"Te ha absorbido el coronavirus"<<endl;
				break;
			default: cout<<"\nEsa opcion no esta en el menu!!!\n";
				break;
		}
	}while(numero!=6); // Si el numero es distinto de 6 la opcion no esta disponible en el menu y te pide otro numero
	
	system("pause");
	return 0;
}


