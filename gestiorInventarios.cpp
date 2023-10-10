#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

#define systemPause cout << setw(2) << " "; system("pause");
#define clearScreen system("cls");

struct Producto{
	int idProducto;
	string nombreProducto;
	double precioVenta;
	double precioCompra;
	int stock;
	string categoria;
	string marca;
};

void menuPrincipal(Producto, vector<Producto>&, bool);
void mostrar_menuPrincipal(bool&);

bool validacion_numeros_enteros(string, int&);
bool validacion_numeros_flotantes(string, double&);
bool validacion_string(string);

void registrarProductos(Producto, vector<Producto>&, bool&);

int buscarPosProducto(vector<Producto>);

void actualizarProductos(vector<Producto>&);

void mostrar_actualizarProductos(bool&);

void preguntaActualizacionProducto(vector<Producto>, bool&);
void mostrar_PreguntaActualizacionProducto(bool&);

void borrarProducto(vector<Producto>&, bool&);

void buscarProductosCoincidentes(vector<Producto>);

void mostrar_busquedaCoincidentes(bool&);

void buscarPorNombre(vector<Producto>);

void buscarPorRangoPrecios(vector<Producto>);

void buscarPorCategoria(vector<Producto>);

void buscarPorMarca(vector<Producto>);

void listadoProductos(vector<Producto>);
void mostrar_listadoProductos(bool&);
void mostrarProductos(vector<Producto>);
void guardarListaProductos(vector<Producto>);


int main(int argc, char *argv[]) {
	system ("mode con: cols=95 lines=27"); 
	vector<Producto>productos;
	Producto p;
	
	bool prodRegistrado = false;
	
	menuPrincipal(p, productos, prodRegistrado);
	
	return 0;
}

void menuPrincipal(Producto p, vector<Producto>&productos, bool prodRegistrado){
	
	
	string opcion;
	int opcionElegida;
	bool control = true, ingresoValido = true, opcionValida;
	
	
	do{
		clearScreen;
		
		mostrar_menuPrincipal(ingresoValido);
		
		getline(cin, opcion);
		
		opcionValida = validacion_numeros_enteros(opcion, opcionElegida);
		
		if(opcionValida){
			
			switch(opcionElegida){
				
				case 1:
					registrarProductos(p, productos, prodRegistrado);
					control = false;
					break;
				case 2:
					if(prodRegistrado == false){
						clearScreen;
						cout<<endl<<setw(6)<<" "<<"No se encuentran productos registrados."<<endl<<setw(6)<<" "
							<<"Por favor registrelos en seleccionando la opcion correcta en el menu... "<<endl<<endl<<endl;
						control = false;
						systemPause
						break;
					}else{
						actualizarProductos(productos);
						control = false;
						break;
					}
					break;
				case 3:
					if(prodRegistrado == false){
						clearScreen;
						cout<<endl<<setw(6)<<" "<<"No se encuentran productos registrados."<<endl<<setw(6)<<" "
							<<"Por favor registrelos en seleccionando la opcion correcta en el menu... "<<endl<<endl<<endl;
						control = false;
						systemPause
						break;
					} else{
						borrarProducto(productos, prodRegistrado);
						control = false;
						break;
					}
				case 4:
					if(prodRegistrado == false){
						clearScreen;
						cout<<endl<<setw(6)<<" "<<"No se encuentran productos registrados."<<endl<<setw(6)<<" "
						   <<"Por favor registrelos en seleccionando la opcion correcta en el menu... "<<endl<<endl<<endl;
						control = false;
						systemPause
						break;
					} else{
					   buscarProductosCoincidentes(productos);
					   control = false;
					   break;
					}
				case 5:
					if(prodRegistrado == false){
						clearScreen;
						cout<<endl<<setw(6)<<" "<<"No se encuentran productos registrados."<<endl<<setw(6)<<" "
							<<"Por favor registrelos en seleccionando la opcion correcta en el menu... "<<endl<<endl<<endl;
						control = false;
						systemPause
						break;
					} else{
						listadoProductos(productos);
						control = false;
						break;
					}
				case 6:
					control = true;
					break;
				default:
					control = false;
					ingresoValido = false;
					break;
					
			}
		}else{
			ingresoValido = false;
			control = false;
		}
		
	} while(!control);
}
	
void mostrar_menuPrincipal(bool& ingresoValido){
	
	
	cout << endl << setw(20)<<" "<<"Bienvenido al menu principal del programa"<<endl<<endl<<setw(2)
		<<endl<<" ============================================================================= "<<endl<<endl
		<<endl<<endl<<setw(6)<<" "<<"1 - Registro de productos"<<endl<<setw(6)<<" "<<"2 - Actualizacion de productos"
		<<endl<<setw(6)<<" "<<"3 - Eliminar un producto"<<endl<<setw(6)<<" "<<"4 - Buscar productos segun un filtro"
		<<endl<<setw(6)<<" "<<"5 - Listar todos los productos"<<endl<<setw(6)<<" "<<"6 - Salir del programa"<<endl<<endl<<endl
		<<endl<<" ============================================================================= "<<endl<<endl;
	
	if(ingresoValido)
		cout << endl << setw(2)<< " " << "Ingrese una opcion: ";
	else{
		cout << endl <<setw(2)<< " " << "Ingrese una opcion valida: ";
		ingresoValido = true;
	}
}

void registrarProductos(Producto p, vector<Producto>&productos, bool& prodRegistrado){
	
	int cantProd, stockito;
	double precios;
	string cadena, precio, cantStock;
	
	clearScreen
	
	cout<<endl<<setw(3)<<" "<<"Ingrese la cantidad de productos a registrar... ";
	
	getline(cin, cadena);
	
	bool entradaValida = validacion_numeros_enteros(cadena, cantProd);
	
	if(entradaValida){
		prodRegistrado = true;
		
		for(int i=0; i<cantProd; i++){
			
			bool datosValidos = true;
			bool nombre, precioV, precioC, stock, categoria, marca;
			
			do{
				clearScreen
				cout<<endl<<setw(27)<<" "<<"Registro del producto "<<i+1<<" de "<<cantProd<<endl<<endl<<endl;
				
				if(!datosValidos){
					cout << setw(3) << " " << " Ingrese los datos correctamente, por favor... " << endl << endl << endl;
				}
				
				cout<<setw(3)<<" "<<"Ingrese el nombre del producto ...  ";
				getline(cin,p.nombreProducto);
				
				nombre = validacion_string(p.nombreProducto);
				
				cout<<endl<<setw(3)<<" "<<"Ingrese el precio de venta...  ";
				getline(cin, precio);
				
				precioV = validacion_numeros_flotantes(precio, precios);
				
				p.precioVenta = precios;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese el precio al cual compra el producto...  ";
				getline(cin, precio);
				
				precioC = validacion_numeros_flotantes(precio, precios);
				
				p.precioCompra = precios;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese la cantidad de stock restante...  ";
				getline(cin, cantStock);
				
				stock = validacion_numeros_enteros(cantStock, stockito);
				
				p.stock = stockito;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese la categoria correspondiente del producto...  ";
				getline(cin,p.categoria);
				
				categoria = validacion_string(p.categoria);
				
				cout<<endl<<setw(3)<<" "<<"Ingrese la marca correspondiente del producto...  ";
				getline(cin,p.marca);
				
				marca = validacion_string(p.marca);
				
				if(nombre and precioV and precioC and stock and categoria and marca and p.precioVenta > p.precioCompra)
					datosValidos = true;
				else
					datosValidos = false;
				
			} while(!datosValidos);
			
			p.idProducto = i+1;
			productos.push_back(p);
			
		}
		
		clearScreen
		cout << endl << setw(2) << " " << "Producto(s) ingresado(s) correctamente!" << endl << endl;
		
		systemPause
	}else{
		clearScreen
		cout << endl << setw(2) << " " << "Entrada no valida... " << endl << endl;
		systemPause
	}
	
}

bool validacion_numeros_enteros(string cadena, int& numero){
	
	bool valido = false;
	
	stringstream validacion(cadena);
	
	if(validacion >> numero and numero > 0)
		valido = true;
	
	return valido;
}

bool validacion_numeros_flotantes(string cadena, double& numero){
	bool valido = false;
	
	stringstream validacion(cadena);
	
	if(validacion >> numero and numero > 0.0)
		valido = true;
	
	return valido;
}

bool validacion_string(string cadena){
	
	int i=0;
	bool control = true;
	
	cadena.erase(remove_if(cadena.begin(), cadena.end(), ::isspace), cadena.end());
	
	if(cadena.empty()){
		control = false;
	} else{
		while(i<cadena.size()){
			if(!isalpha(cadena[i])){
				control = false;
				break;
			}
			i++;
		}
	}
	
	return control;
}

int buscarPosProducto(vector<Producto>productos){
	
	clearScreen
	string nombreP;
	int pos = 0;
	bool entradaValida;
	
	cout<<endl<<setw(6)<<" "<<"Ingrese el nombre del producto a buscar... "<<endl<<setw(6)<<" "<<"(Recuerde las mayúsculas y minúsculas)"
		<<endl<<endl<<setw(6)<<" "<<"Nombre: ";
	getline(cin,nombreP);
	
	entradaValida = validacion_string(nombreP);
	
	if(entradaValida){		
		while(productos[pos].nombreProducto != nombreP && pos<productos.size()){
			pos++;
		}
	}else{
		pos = productos.size();
	}
	
	if(pos == productos.size()){
		return -1;
	} else{
		return pos;
	}
}

void actualizarProductos(vector<Producto>& productos){
	
	bool control = true, ingresoValido = true, cambio = true, opcionValida = true, cout_opcion = true;
	string precios, stock, opcion;
	
	int posicion = buscarPosProducto(productos), opcionElegida;
	
	if(posicion == -1){
		clearScreen
		cout<<endl<<setw(6)<<" "<<"Entrada invalida o producto no encontrado... " << endl << endl;
		systemPause
	}else{
		
		do{
			clearScreen
			mostrar_actualizarProductos(ingresoValido);
			getline(cin, opcion);
			
			opcionValida = validacion_numeros_enteros(opcion, opcionElegida);
			
			if(opcionValida){
				
				switch(opcionElegida){
					case 1:
						
						if(cout_opcion){
							cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo nombre del producto... ";
						}
						else{
							cout<<endl<<setw(6)<<" "<<"Ingrese un nuevo nombre de producto correcto, por favor... ";
							cout_opcion = true;
						}
						
						getline(cin, productos[posicion].nombreProducto);
						control = validacion_string(productos[posicion].nombreProducto);
						
						break;
						
					case 2:
						
						if(cout_opcion){
							cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo precio de venta del producto... ";
						}
						else{
							cout<<endl<<setw(6)<<" "<<"Ingrese un precio de venta correcto, por favor... ";
							cout_opcion = true;
						}
						
						getline(cin, precios);
						
						control = validacion_numeros_flotantes(precios, productos[posicion].precioVenta);
						
						break;
					case 3:
						if(cout_opcion){
							cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo precio de compra del producto... ";
						}else{
							cout<<endl<<setw(6)<<" "<<"Ingrese un precio de compra correcto, por favor... ";
							cout_opcion = true;
						}
						
						getline(cin, precios);
						
						control = validacion_numeros_flotantes(precios, productos[posicion].precioCompra);
						
						break;		
					case 4:
						if(cout_opcion){
							cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo stock del producto... ";
						}else{
							cout<<endl<<setw(6)<<" "<<"Ingrese un numero de stock correcto, por favor... ";
							cout_opcion = true;
						}
						
						getline(cin, stock);
						
						control = validacion_numeros_enteros(stock, productos[posicion].stock);
						
						break;
					case 5:
						if(cout_opcion){
							cout<<endl<<setw(6)<<" "<<"Ingrese la nueva categoria del producto... ";
						}else{
							cout<<endl<<setw(6)<<" "<<"Ingrese una categoria correcta, por favor... ";
							cout_opcion = true;
						}
						getline(cin, productos[posicion].categoria);
						
						control = validacion_string(productos[posicion].categoria);
						
						break;	
					case 6:
						if(cout_opcion){
							cout<<endl<<setw(6)<<" "<<"Ingrese la nueva marca del producto... ";
						}else{
							cout<<endl<<setw(6)<<" "<<"Ingrese una marca del producto correcta, por favor... ";
							cout_opcion = true;
						}	
						getline(cin,productos[posicion].marca);
						
						control = validacion_string(productos[posicion].marca);
						break;
					case 7:
						control = true;
						cambio = false;
						break;
						
					default:
						ingresoValido = false;
						control = false;
						break;
				}
				if(!control && ingresoValido){
					cout_opcion = false;
					cout<<endl<<setw(6)<< " Ingreso del dato incorrecto, vuelva a intentarlo " << endl << endl;
					systemPause
				}
				if(cambio){
					preguntaActualizacionProducto(productos, control);
				}
				
			}else{
				control = false;
				ingresoValido = false;
			}
			
		} while(!control);
	}
}

void mostrar_actualizarProductos(bool& ingresoValido){
	
	cout << endl << setw(30)<<" "<<"Actualizar Producto"<<endl<<endl<<setw(2)
		<<endl<<" ============================================================================= "<<endl<<endl
		<<setw(6)<<" "<<"1 - Actualizar el nombre del producto"<<endl<<setw(6)<<" "<<"2 - Actualizar el precio de venta del producto"
		<<endl<<setw(6)<<" "<<"3 - Actualizar el precio de compra del producto"<<endl<<setw(6)<<" "<<"4 - Actualizar el stock del producto"
		<<endl<<setw(6)<<" "<<"5 - Actualizar la categoria del producto"<<endl<<setw(6)<<" "<<"6 - Actualizar la marca del producto"
		<<endl<<setw(6)<<" "<<"7 - Volver al menu principal"<<endl<<endl;
	
	if(ingresoValido)
		cout << endl << setw(2)<< " " << "Ingrese una opcion: ";
	else{
		cout << endl <<setw(2)<< " " << "Ingrese una opcion valida: ";
		ingresoValido = true;
	}
}

void preguntaActualizacionProducto(vector<Producto>productos, bool& control){
	
	string opcion;
	int opcionElegida;
	bool controlQuest = true, ingresoValido = true, opcionValida = true;
	
	do{
		clearScreen;
		mostrar_PreguntaActualizacionProducto(ingresoValido);
		
		getline(cin, opcion);
		
		opcionValida = validacion_numeros_enteros(opcion, opcionElegida);
		
		if(opcionValida){
			switch(opcionElegida){
				case 1:
					controlQuest = true;
					control = false;
					break;
				case 2:
					controlQuest = true;
					actualizarProductos(productos);
					break;
				case 3:
					controlQuest = true;
					break;
				default:
					controlQuest = false;
					ingresoValido = false;
					break;
			}
		}else{
			controlQuest = false;
			ingresoValido = false;
		}
		
		
	}while(!controlQuest);
	
}

void mostrar_PreguntaActualizacionProducto(bool& ingresoValido){
	cout<<endl<<setw(12)<<" "<<"Para continuar seleccione una de las siguientes opciones... "
		<<endl<<endl<<endl<<setw(6)<<" "<<"1 - Continuar modificando datos del mismo producto"
		<<endl<<setw(6)<<" "<<"2 - Actualizar los datos de un nuevo producto"
		<<endl<<setw(6)<<" "<<"3 - Volver al menu principal" <<endl<<endl<<endl;
	
	if(ingresoValido){
		cout << endl << setw(2)<< " " << "Ingrese una opcion: ";
	}
	else{
		cout << endl <<setw(2)<< " " << "Ingrese una opcion valida: ";
		ingresoValido = true;
	}
}

void borrarProducto(vector<Producto>&productos, bool& prodRegistrado){
	
	clearScreen
	int posProdcuto = buscarPosProducto(productos);
	
	clearScreen
	
	if(posProdcuto == -1){
		clearScreen
		cout<<endl<<endl<<setw(6)<<" "<<"Nombre de producto no existente"<<endl;
		systemPause
	} else{
			if(productos.size() == 1){
				productos.erase(productos.begin() + posProdcuto);
				prodRegistrado = false;
			}else{
				productos.erase(productos.begin() + posProdcuto);
			}		
			cout<<endl<<endl<<setw(6)<<" "<<"Producto borrado con exito!"<<endl;
			systemPause
		}
	
}

void buscarProductosCoincidentes(vector<Producto>productos){
	
	clearScreen
	string opcion;
	int opcionElegida;
	
	bool controlCoincidencia = false, ingresoValido = false, opcionValida = true;
	
	do{
		mostrar_busquedaCoincidentes(ingresoValido);
		
		getline(cin, opcion);
		
		opcionValida = validacion_numeros_enteros(opcion, opcionElegida);
		
		if(opcionValida){
			switch(opcionElegida){
				case 1:
					controlCoincidencia = true;
					clearScreen
					buscarPorNombre(productos);
					break;
				case 2:
					controlCoincidencia = true;
					clearScreen
					buscarPorRangoPrecios(productos);
					break;
				case 3:
					controlCoincidencia = true;
					clearScreen
					buscarPorCategoria(productos);
					break;
				case 4:
					controlCoincidencia = true;
					clearScreen
					buscarPorMarca(productos);
					break;
				case 5: 
					controlCoincidencia = true;
					break;
				default:
					controlCoincidencia = false;
					ingresoValido = false;
					break;
			}
		}else{
			controlCoincidencia = false;
			ingresoValido = false;
		}
		
		
	} while(!controlCoincidencia);
}

void mostrar_busquedaCoincidentes(bool& ingresoValido){
	cout<< endl << setw(25)<<" ""Seleccione una opcion para realizar el filtrado"<<endl<<endl
		<<endl<<setw(6)<<" "<<"1 - Busqueda por nombre coincidente"<<endl
		<<setw(6)<<" "<<"2 - Busqueda por rango de precios"<<endl
		<<setw(6)<<" "<<"3 - Busqueda por categoria"<<endl
		<<setw(6)<<" "<<"4 - Busqueda por marca"<<endl
		<<setw(6)<<" "<<"5 - Volver al menu principal"<<endl << endl << endl;
	
	if(ingresoValido){
		cout << endl << setw(2)<< " " << "Ingrese una opcion: ";
	}
	else{
		cout << endl <<setw(2)<< " " << "Ingrese una opcion valida: ";
		ingresoValido = true;
	}
}

void buscarPorNombre(vector<Producto>productos){
	string nombre;
	bool entradaValida;
	
	vector<Producto>productosNombres;
	
	cin.ignore();
	cout<<setw(6)<<" "<<"Ingrese el nombre de los productos para filtrarlos... ";
	
	getline(cin,nombre);
	
	entradaValida = validacion_string(nombre);
	
	if(entradaValida){
		for(const auto& producto : productos){
			if(nombre == producto.nombreProducto){
				productosNombres.push_back(producto);
			}
		}
		if(productosNombres.size()>0){
			
			cout <<endl<<setw(6)<<" "<<"Lista de productos "<<nombre<<endl<<endl
				<<setw(6)<<" " << "ID"<<setw(10)<<" "<<"Nombre"<<setw(10)<<" "
				<<"Precio"<<setw(10)<<" "<<"Stock"<<setw(10)<<" "
				<<"Categoria"<<setw(10)<<" "<<"Marca"<<setw(10)<<" "<<endl<<endl;
			
			for(int i=0;i<productosNombres.size();i++){
				cout<<setw(6)<<" " << productosNombres[i].idProducto<<setw(10)<<" "<<productosNombres[i].nombreProducto
					<<setw(10)<<" "<<productosNombres[i].precioVenta<<setw(10)<<" "
					<<productosNombres[i].stock<<setw(10)<<" "<<productosNombres[i].categoria
					<<setw(10)<<" "<<productosNombres[i].marca<<endl<<endl;
			}
			systemPause
		}
		else{
			cout<<endl<<setw(6)<<" "<<"No se ha encontrado ningun producto con ese nombre."<<endl;
			systemPause
		}
		
	}else{
		clearScreen
		cout << endl << setw(6)<<" "<<"Entrada no valida... " << endl << endl;
		systemPause
	}
}

void buscarPorRangoPrecios(vector<Producto> productos){
	ofstream archivo("prog.txt");	
	
	double precioMin, precioMax;
	string precios;
	
	bool entradaValida1, entradaValida2;
	vector<Producto>productosPrecios;
	
	cout<< setw(6)<<" "<<"Ingrese el rango de precio para filtrar los productos... "
		<<endl<<endl<<setw(6)<<" "<<"Precio minimo... ";
	getline(cin, precios);
	
	entradaValida1 = validacion_numeros_flotantes(precios, precioMin);
	
	cout<<endl<<endl<<setw(6)<<" "<<"Precio maximo... ";
	getline(cin, precios);
	
	entradaValida2 = validacion_numeros_flotantes(precios, precioMax);
	
	if(entradaValida1 && entradaValida2){
		for(const auto& producto : productos){
			if(precioMin < producto.precioVenta && precioMax > producto.precioVenta){
				productosPrecios.push_back(producto);
			}
		}
		
		if(productosPrecios.size()>0){
			cout <<endl<<setw(6)<<" "<<"Lista de productos entre "<<precioMin<<" y "<<precioMax<<endl<<endl
				<<setw(6)<<" " << "ID"<<setw(10)<<" "<<"Nombre"<<setw(10)<<" "
				<<"Precio"<<setw(10)<<" "<<"Stock"<<setw(10)<<" "
				<<"Categoria"<<setw(10)<<" "<<"Marca"<<setw(10)<<" "<<endl<<endl;
			
			for(int i=0;i<productosPrecios.size();i++){
				cout<<setw(6)<<" " << productosPrecios[i].idProducto<<setw(10)<<" "<<productosPrecios[i].nombreProducto
					<<setw(10)<<" "<<productosPrecios[i].precioVenta<<setw(10)<<" "
					<<productosPrecios[i].stock<<setw(10)<<" "<<productosPrecios[i].categoria
					<<setw(10)<<" "<<productosPrecios[i].marca<<endl<<endl;
			}
			
			systemPause
		}
		else{
			cout<<endl<<setw(6)<<" "<<"No se ha encontrado ningun producto en ese rango de precios."<<endl;
			systemPause
		}
	}else{
		clearScreen
		cout << endl << setw(6)<<" "<< "Entrada no valida... " << endl << endl;
		systemPause
	}
}

void buscarPorCategoria(vector<Producto> productos){
	vector<Producto>productosCategorias;
	string categ;
	bool entradaValida;
	ofstream archivo("prog.txt");
	
	cin.ignore();
	cout<<"Ingrese la categoria para filtrar los productos... ";
	getline(cin, categ);
	
	entradaValida = validacion_string(categ);
	
	if(entradaValida){
		for(const auto& producto : productos){
			if(categ == producto.categoria){
				productosCategorias.push_back(producto);
			}
		}
		
		if(productosCategorias.size()>0){
			cout <<endl<<setw(6)<<" "<<"Lista de productos "<<categ<<endl<<endl
				<<setw(6)<<" " << "ID"<<setw(10)<<" "<<"Nombre"<<setw(10)<<" "
				<<"Precio"<<setw(10)<<" "<<"Stock"<<setw(10)<<" "
				<<"Categoria"<<setw(10)<<" "<<"Marca"<<setw(10)<<" "<<endl<<endl;
			
			for(int i=0;i<productosCategorias.size();i++){
				cout<<setw(6)<<" " << productosCategorias[i].idProducto<<setw(10)<<" "<<productosCategorias[i].nombreProducto
					<<setw(10)<<" "<<productosCategorias[i].precioVenta<<setw(10)<<" "
					<<productosCategorias[i].stock<<setw(10)<<" "<<productosCategorias[i].categoria
					<<setw(10)<<" "<<productosCategorias[i].marca<<endl<<endl;
			}
			
			systemPause
		}
		else{
			cout<<endl<<setw(6)<<" "<<"No se ha encontrado ningun producto perteneciente a esa categoría."<<endl;
			systemPause
		}
	}else{
		clearScreen
		cout << endl << setw(6)<<" "<< "Entrada no valida... " << endl << endl;
		systemPause
	}
	
}

void buscarPorMarca(vector<Producto>productos){
	vector<Producto>productosMarcas;
	string marc;
	bool entradaValida;
	
	cin.ignore();
	cout<<setw(6)<<" "<<"Ingrese la marca para filtrar los productos... ";
	getline(cin,marc);
	entradaValida = validacion_string(marc);
	if(entradaValida){
		
		for(const auto& producto : productos){
			if(marc == producto.marca){
				productosMarcas.push_back(producto);
			}
		}
		
		if(productosMarcas.size()>0){
			cout <<endl<<setw(6)<<" "<<"Lista de productos "<<marc<<endl<<endl
				<<setw(6)<<" " << "ID"<<setw(10)<<" "<<"Nombre"<<setw(10)<<" "
				<<"Precio"<<setw(10)<<" "<<"Stock"<<setw(10)<<" "
				<<"Categoria"<<setw(10)<<" "<<"Marca"<<setw(10)<<" "<<endl<<endl;
			
			for(int i=0;i<productosMarcas.size();i++){
				cout<<setw(6)<<" " << productosMarcas[i].idProducto<<setw(10)<<" "<<productosMarcas[i].nombreProducto
					<<setw(10)<<" "<<productosMarcas[i].precioVenta<<setw(10)<<" "
					<<productosMarcas[i].stock<<setw(10)<<" "<<productosMarcas[i].categoria
					<<setw(10)<<" "<<productosMarcas[i].marca<<endl<<endl;
			}
			
			systemPause
		}
		else{
			cout<<endl<<setw(6)<<" "<<"No se ha encontrado ningun producto perteneciente a esa marca."<<endl;
			systemPause
		}
	}else{
		clearScreen
		cout << endl << setw(6)<<" "<< "Entrada no valida... " << endl << endl;
		systemPause
	}
}

void listadoProductos(vector<Producto> productos){
	
	string opcion;
	int opcionElegida;
	
	bool control = false, ingresoValido = true, opcionValida = true;
	
	
	do{
		clearScreen
			mostrar_listadoProductos(ingresoValido);
		
		getline(cin, opcion);
		
		opcionValida = validacion_numeros_enteros(opcion, opcionElegida);
		
		if(opcionValida){
			switch(opcionElegida){
				case 1:
					clearScreen
					mostrarProductos(productos);
					control = false;
					break;
				case 2:
					clearScreen
					guardarListaProductos(productos);
					control = true;
					
					break;
				case 3:
					control = true;
					break;
				default:
					control = false;
					ingresoValido = false;
					break;
			}
		}else{
			control = false;
			ingresoValido = false;
		}
		
	} while(!control);
	
}

void mostrar_listadoProductos(bool& ingresoValido){
	cout << endl << setw(30)<<" "<<"Listar Productos"<<endl<<endl<<setw(2)
		<<endl<<" ============================================================================= "<<endl<<endl
		<<setw(6)<<" "<<"1 - Mostrar los productos en consola"<<endl<<setw(6)<<" "<<"2 - Guardar la lista de productos en un archivo"
		<<endl<<setw(6)<<" "<<"3 - Volver al menu principal"<<endl<<endl;
	
	if(ingresoValido)
		cout << endl << setw(2)<< " " << "Ingrese una opcion: ";
	else{
		cout << endl <<setw(2)<< " " << "Ingrese una opcion valida: ";
		ingresoValido = true;
	}
}

void mostrarProductos(vector<Producto> productos){
	
	clearScreen
	cout <<endl<<setw(6)<<" "<<"Lista de productos"<<endl<<endl
		<<setw(6)<<" " << "ID"<<setw(10)<<" "<<"Nombre"<<setw(10)<<" "
		<<"Precio"<<setw(10)<<" "<<"Stock"<<setw(10)<<" "
		<<"Categoria"<<setw(10)<<" "<<"Marca"<<setw(10)<<" "<<endl<<endl;
	
	for(int i=0;i<productos.size();i++){
		cout<<setw(6)<<" " << productos[i].idProducto<<setw(10)<<" "<<productos[i].nombreProducto
			<<setw(10)<<" "<<productos[i].precioVenta<<setw(10)<<" "
			<<productos[i].stock<<setw(10)<<" "<<productos[i].categoria
			<<setw(10)<<" "<<productos[i].marca<<endl<<endl;
	}
	
	systemPause
}

void guardarListaProductos(vector<Producto> productos){
	
	clearScreen
	ofstream archivo("prog.txt");
	
	if(archivo.is_open()) {
		archivo<<endl<<"Lista de productos"<<endl<<endl
			<<"ID"<<setw(10)<<" "<<"Nombre"<<setw(10)<<" "
			<<"Precio"<<setw(10)<<" "<<"Stock"<<setw(10)<<" "
			<<"Categoria"<<setw(10)<<" "<<"Marca"<<setw(10)<<" "<<endl<<endl;
		
		for(int i=0;i<productos.size();i++){
			archivo<<productos[i].idProducto<<setw(10)<<" "<<productos[i].nombreProducto
				<<setw(10)<<" "<<productos[i].precioVenta<<setw(10)<<" "
				<<productos[i].stock<<setw(10)<<" "<<productos[i].categoria
				<<setw(10)<<" "<<productos[i].marca<<endl<<endl;
		}
		
		archivo.close();
		cout<<endl<<endl<<setw(6)<<" " << "Abra el archivo para ver los resultados de el listamiento de los productos... "<<endl<<endl;
		systemPause		
	} else {
		cout << setw(6)<<" " << "No se pudo abrir el archivo." << endl << endl;
		systemPause
	}
	
}
