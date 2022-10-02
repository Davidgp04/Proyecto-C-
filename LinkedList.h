#ifndef LinkedList_h
#define LinkedList_h
#include <string>
using namespace std;
void escribir(string,string);
void borrarDatos();
class Usuario{
private:
	string username;
	string password;
	Usuario* siguiente=nullptr;
public:
	Usuario(string,string);
	~Usuario();
	void setNext(Usuario* next){this->siguiente=next;}
	void imprimirUsuarios();
	void ingresarNuevoUsuario(string,string);
	void buscarUsuario(string,string);
	void escribirLista();
	void eliminarUsuario(string,string);

};
#endif
