#include <iostream>
#include "LinkedList.h"
#include <fstream>
#include <stdlib.h>
Usuario::Usuario(string username, string password){
this->username=username;
this->password=password;
}
void Usuario::imprimirUsuarios(){
	if(this){
		cout<<this->username<<endl;
		this->siguiente->imprimirUsuarios();
	}
}
void Usuario::ingresarNuevoUsuario(string username1, string password1){
	if(this->siguiente){
		if(this->username.compare(username1)==0){
			cout<<"El usuario se encuentra repetido, vuelva a intentarlo"<<endl;
		}else{
			this->siguiente->ingresarNuevoUsuario(username1,password1);
		}
	}else{
		this->siguiente=new Usuario(username1,password1);
		escribir(username1,password1);
	}
}
void Usuario::buscarUsuario(string usuario, string contraseña){
	if(this){
		if(this->username.compare(usuario)==0 && this->password.compare(contraseña)==0){
			cout<<"Bienvenido"<<endl;
		}else{
			this->siguiente->buscarUsuario(usuario, contraseña);
		}
	}else{
	cout<<"El usuario no fue encontrado"<<endl;
	}
}
void Usuario::eliminarUsuario(string usuario,string contraseña){
	if(this){
		if (this->username.compare(usuario)==0 && this->password.compare(contraseña)==0){
		Usuario* temp=this->siguiente;
		this->username=this->siguiente->username;
		this->password=this->siguiente->password;
		this->siguiente=this->siguiente->siguiente;
		delete temp;
		return;
		}else{ if(this->siguiente->username.compare(usuario)==0 && this->siguiente->password.compare(contraseña)==0){
			Usuario* temp=this->siguiente;
			this->siguiente=this->siguiente->siguiente;
			delete temp;
			return;
		}else{
						this->siguiente->eliminarUsuario(usuario,contraseña);
					}
		}
	}else{cout<<"El usuario no fue encontrado"; return;}
}
void Usuario::escribirLista(){
	ofstream archivo;
	archivo.open("Usuarios.txt",ios::out);
	Usuario* current=this;
	while(current){
	escribir(current->username,current->password);
	}
}
Usuario::~Usuario(){
	cout<<"Usuario eliminado"<<endl;
}
void escribir(string texto1, string texto2=""){
	ofstream archivo;
	string linea1;
	archivo.open("usuarios.txt",ios::app);
		if(archivo.fail()){
			cout<<"El archivo no pudo abrirse\n";
			exit(1);
		}

	archivo<<endl<<texto1<<endl;
	archivo<<texto2;

}
void borrarDatos(){
	ofstream archivo;
	string linea1;
	archivo.open("usuarios.txt",ios::out);
		if(archivo.fail()){
			cout<<"El archivo no pudo abrirse\n";
			exit(1);
		}

	archivo<<"";

}
int main(){
	ifstream archivo;
	archivo.open("usuarios.txt",ios::in);
	if(archivo.fail()){
		cout<<"El archivo no pudo abrirse\n";
		exit(1);
	}
	string username,password;
	getline(archivo,username);
	getline(archivo,password);
	Usuario* first=new Usuario(username,password);
	Usuario* actual=first;
	while (!archivo.eof()){
		getline(archivo,username);
		getline(archivo,password);
		Usuario* newUser=new Usuario(username,password);
		actual->setNext(newUser);
		actual=newUser;
	}
	actual=first;
	int opcion=90;
	while(true){
	cout<<"Elige una opción"<<endl;
	cout<<"0. Salir del programa"<<endl;
	cout<<"1. Ingresar un nuevo usuario"<<endl;
	cout<<"2. Buscar usuario existente"<<endl;
	cout<<"3. Eliminar usuario"<<endl;
	cout<<"4. Imprimir lista"<<endl;
	cin>>opcion;
	string vacia="";
	if(opcion==0){
		break;
	}else if(opcion<4){
		cout<<"Ingrese el nombre de usuario"<<endl;
		cin>>username;
		cout<<"Ingrese la contraseña"<<endl;
		cin>>password;
	switch(opcion){
	case 1:
		actual->ingresarNuevoUsuario(username, password);
		break;
	case 2:
		actual->buscarUsuario(username,password);
		break;
	case 3:
		actual->eliminarUsuario(username, password);
		actual->escribirLista();
		break;

	}
	}else if(opcion==4){
		actual->imprimirUsuarios();
	}else{
		cout<<"Esa opción no está disponible"<<endl;
	}
	}
	cout<<"Fin del programa";
	return 0;
}





