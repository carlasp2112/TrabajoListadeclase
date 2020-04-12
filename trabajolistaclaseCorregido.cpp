#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Alumno{ //Creamos la clase alumno
	private: // Atributos de la clase alumno
		string nombre;
	public: //Métodos de la clase alumno
		string linea;
		string nombreArchivo;
		Alumno(string);
		void leerlista();
		void verexamen();
};

class Profesor : public Alumno{ // Creamos la clase Profesor que hereda la clase Alumno
	private:// Atributos de la clase Profesor
		int profe;
		string asignatura;
	public: // Metodos de la clase Profesor
		Profesor(string, int, string);
		void crearlista();
		void annadirnombres();
		void fechaexamen();	//*métodos leerlista y verexamen
};

Alumno::Alumno(string _nombre){
	nombre = _nombre;
}

Profesor :: Profesor (string _nombre, int _profe, string _asignatura) : Alumno (_nombre){
	profe = _profe;
	asignatura = _asignatura;
}

void Profesor::crearlista(){ //Explicación del método escribir de la clase instituto
	ofstream archivo; //Creamos y abrimos el archivo para meter datos
	int alumno;
	cout<<"que lista de clase quieres crear(1B, 2A...): ";
	getline(cin,nombreArchivo); //Nos permite escribir por teclado
	archivo.open(nombreArchivo.c_str(),ios::out); //convierte el nombre en una cadena con comillas; dentro del sistema de entrada y salida, la accion que se va a realizar es de tipo out(salida)
	
	if(archivo.fail()){
		cout<<"No pude abrir el archivo";
		exit(1);
	
	}
	cout<<"Cuantos alumnos quieres annadir"<< endl;
	cin>>alumno;
	for(int i ; i<=alumno;i++){
	cout << "introduce el nombre del alumno que pertence a esta clase..."<<endl;
	getline(cin,linea);//Mete la informacion escrita por teclado a la siguiente linea del archivo
	archivo<<linea<<endl;
	}
	archivo.close();//Cerrar el archivo
}

void Alumno::leerlista(){
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

void Profesor::annadirnombres(){
	ofstream archivo;//Creamos y abrimos el archivo para meter datos
	int nalumno;
	
	cout << "Que lista de clase quieres modificar:";
	getline(cin,nombreArchivo);//Escribe por teclado en el archivo que tenga el nombre metido por teclado
	archivo.open(nombreArchivo.c_str(),ios::app);//ios::app se utiliza para añadir contenido al archivo
	
	if(archivo.fail()){ //Si el nombre del archivo no existe da error
		cout << "Esa clase no existe";
		exit(1);
	}
	cout<<"Cuantos alumnos quieres annadir"<< endl;
	cin>>nalumno;
	for(int i ; i<=nalumno;i++){
	cout << "Nombre del alumno que quieres annadir..."<<endl;
	getline(cin,linea);//Mete la informacion escrita por teclado a la siguiente linea del archivo
	archivo<<linea<<endl;
	}
	archivo.close();//Cerrar el archivo
	
}

void Profesor::fechaexamen(){
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

void Alumno::verexamen(){
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
	string nombre;
	int profe;
	string asignatura;
	
	cout<<"Como te llamas? ";
	cin >> nombre;
	cout<<"Si eres profesor marca 1"<<endl;
	cin>> profe;
	if (profe == 1) {
		cout << "Que asignatura das? "<<endl;
		cin >> asignatura;
			int numero;
	Profesor n1= Profesor(nombre,profe,asignatura);//Construimos eun usuario de la clase Profesor con tres parámetros de entrada
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
			case 1: n1.crearlista();
				break;
			case 2: n1.leerlista();
				break;
			case 3: n1.annadirnombres();
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
	}
	else{ //Si no eres profesor no te deja crear listas de alumnos
		int num;
		Alumno n2= Alumno(nombre); //Construimos un usuario de la clase Alumno con el nombre de atributo
		do{ //Menu con distintas opciones para cada numero del 1 al 6
			cout<<"\n";
			cout <<"***************** INSTITUTO ********************"<<endl;
			cout<<"***** 1.-Ver lista de alumnos*****"<<endl;
			cout<<"***** 2.-Ver lista de examenes *****"<<endl;
			cout<<"***** 3.-Salir *****"<<endl;
			cout<<"***************************************************"<<endl;
			cout<<"Selecciona una opcion: ";
			cin>>num;
			cin.ignore(256,'\n');//Vaciar el buffer
			
			switch(num){ //Según el número que reciba realizará una acción u otra
				case 1: n2.leerlista();
					break;
				case 2: n2.verexamen();
					break;
				case 3: cout<<"Te ha absorbido el coronavirus"<<endl;
					break;
				default: cout<<"\nEsa opcion no esta en el menu!!!\n";
					break;
			}
		}while(num!=3); // Si el numero es distinto de 3 la opcion no esta disponible en el menu y te pide otro numero
	}
	
	
	system("pause");
	return 0;
}


