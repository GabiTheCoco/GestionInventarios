#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
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

void funcionPrueba(vector<Producto>&);

void actualizarNuevoProducto(vector<Producto>&);
void mostrar_actualizarNuevoProducto(bool&);

void actualizarProductos(vector<Producto>, int);
void mostrar_actualizarProductos(bool&);

void reemplazarDatosProducto(vector<Producto>&, int, int);

void preguntaActualizacionProducto(vector<Producto>);
void borrarProducto(vector<Producto>&);
void buscarProductosCoincidentes(vector<Producto>);
void listarProductos(vector<Producto>&);



int main(int argc, char *argv[]) {
	
	vector<Producto>productos;
	Producto p;
	
	bool prodRegistrado = false;
	
	menuPrincipal(p, productos, prodRegistrado);
	
	return 0;
}

void menuPrincipal(Producto p, vector<Producto>&productos, bool prodRegistrado){
	
	
	int opcion;
	bool control = true, ingresoValido = true;
	
	
	do{
		clearScreen;
		
		mostrar_menuPrincipal(ingresoValido);
		
		cin>>opcion;
		
		switch(opcion){
			
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
				funcionPrueba(productos);
				/*actualizarNuevoProducto(productos);*/
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
				borrarProducto(productos);
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
					  listarProductos(productos);
					  control = false;
					  break;
				  }
		case 6:
					 control = true;
					 break;
		default:
			control = false;
			ingresoValido = false;
			cin.clear();
			cin.ignore();
			break;
			
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
	
	cin.ignore();
	
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
				
				cout << endl << nombre << endl << p.nombreProducto;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese el precio de venta...  ";
				getline(cin, precio);
				
				precioV = validacion_numeros_flotantes(precio, precios);
				
				p.precioVenta = precios;
				
				cout << endl << precioV << endl << p.precioVenta;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese el precio al cual compra el producto...  ";
				getline(cin, precio);
				
				precioC = validacion_numeros_flotantes(precio, precios);
				
				p.precioCompra = precios;
				
				cout << endl << precioC<< endl<<p.precioCompra;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese la cantidad de stock restante...  ";
				getline(cin, cantStock);
				
				stock = validacion_numeros_enteros(cantStock, stockito);
				
				p.stock = stockito;
				
				cout << endl << stock << endl<<p.stock;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese la categoria correspondiente del producto...  ";
				getline(cin,p.categoria);
				
				categoria = validacion_string(p.categoria);
				
				cout << endl << categoria << endl<<p.categoria;
				
				cout<<endl<<setw(3)<<" "<<"Ingrese la marca correspondiente del producto...  ";
				getline(cin,p.marca);
				
				marca = validacion_string(p.marca);
				
				cout << endl << marca << endl<<p.marca;
				
				if(nombre and precioV and precioC and stock and categoria and marca and p.precioVenta > p.precioCompra)
					datosValidos = true;
				else
					datosValidos = false;
				
			} while(!datosValidos);
			
			p.idProducto = i+1;
			productos.push_back(p);
			cout<<productos[i].idProducto<<" "<<productos[i].nombreProducto<<" "<<productos[i].precioVenta<<" "<<productos[i].precioCompra<<" "<<productos[i].stock<<" "<<productos[i].categoria<<" "<<productos[i].marca<<endl;
			
			system("pause");
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
	
	while(i<cadena.size()){
		if(!isalpha(cadena[i])){
			control = false;
			break;
		}
		i++;
	}
	
	return control;
}

int buscarPosProducto(vector<Producto>productos){
	
	clearScreen
	
	string nombreP;
	int pos = 0;
	bool entradaValida;
	
	cin.ignore();
	
	cout<<endl<<setw(6)<<" "<<"Ingrese el nombre del producto a buscar... ";
	getline(cin,nombreP);
	
	entradaValida = validacion_string(nombreP);
	
	if(entradaValida){
		cout << productos.size() << " size" << endl << endl;
		
		while(productos[pos].nombreProducto != nombreP && pos<=productos.size()){
			pos++;
		}
		
		cout << endl << pos <<  " pos" << endl; systemPause
	}else{
		clearScreen
		cout<<endl<<setw(6)<<" "<<"Entrada invalida o producto no encontrado... ";
		
		systemPause
	}
	
	if(pos == productos.size()){
		return -1;
	} else{
		return pos;
	}
}
	
void funcionPrueba(vector<Producto>& productos){
	clearScreen

	bool control = true, ingresoValido = true;
	string precios, stock;

	int posicion = buscarPosProducto(productos), opcion;

	
	
	if(posicion == -1){
		cout<<endl<<setw(6)<<" "<<"Entrada invalida o producto no encontrado... ";
	}else{

		do{
			clearScreen
			mostrar_actualizarProductos(ingresoValido);
			cin>>opcion;
			cin.ignore();
			
			switch(opcion){
			
			case 1:
				if(control){
					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo nombre del producto... ";
				}
				else{
					cout<<endl<<setw(6)<<" "<<"Ingrese un nuevo nombre del producto correcto, por favor... ";
				}
				
				getline(cin, productos[posicion].nombreProducto);
				
				control = validacion_string(productos[posicion].nombreProducto);
				cout << endl << control << endl;
				systemPause
			break;
				
			case 2:
				
				if(control)
					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo precio de venta del producto... ";
				else
					cout<<endl<<setw(6)<<" "<<"Ingrese un precio de venta correcto, por favor... ";
				
				getline(cin, precios);
				
				control = validacion_numeros_flotantes(precios, productos[posicion].precioVenta);
				cout << endl << control << endl;
				
				systemPause
				break;
			case 3:
				if(control)	
					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo precio de compra del producto... ";
				else
					cout<<endl<<setw(6)<<" "<<"Ingrese un precio de compra correcto, por favor... ";
				
				getline(cin, precios);
				
				control = validacion_numeros_flotantes(precios, productos[posicion].precioCompra);
				cout << endl << control << endl;
				
				systemPause
				break;		
			case 4:
				if(control)
					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo stock del producto... ";
				else
					cout<<endl<<setw(6)<<" "<<"Ingrese un numero de stock correcto, por favor... ";
				
				getline(cin, stock);
				
				control = validacion_numeros_enteros(stock, productos[posicion].stock);
				cout << endl << control << endl;
				
				
				systemPause
				break;
			case 5:
				if(control)
					cout<<endl<<setw(6)<<" "<<"Ingrese la nueva categoria del producto... ";
				else
					cout<<endl<<setw(6)<<" "<<"Ingrese una categoria correcta, por favor... ";
				
				getline(cin, productos[posicion].categoria);
				
				control = validacion_string(productos[posicion].categoria);
				cout << endl << control << endl;
				
				systemPause
				break;	
			case 6:
				if(control)
					cout<<endl<<setw(6)<<" "<<"Ingrese la nueva marca del producto... ";
				else
					cout<<endl<<setw(6)<<" "<<"Ingrese una marca del producto correcta, por favor... ";
				getline(cin,productos[posicion].marca);
				
				control = validacion_string(productos[posicion].marca);
				cout << endl << control << endl;
				systemPause
				
			break;
			case 7:
				control = true;
				break;

			default:
				ingresoValido = false;
				control = false;
		}

		preguntaActualizacionProducto(productos);
			
		} while(!control);

	}
	
}

//void actualizarNuevoProducto(vector<Producto>& productos){
//	
//	clearScreen
//	
//	int posProdcuto = buscarPosProducto(productos), opcion;
//	bool controlOpcion = false, ingresoValido  = true;
//	
//	if(posProdcuto < 0){
//		cout << setw(2) << " " <<"Nombre de producto no existente"<<endl;
//		systemPause
//	} else{
//		do{
//			clearScreen
//			mostrar_actualizarNuevoProducto(ingresoValido);
//			cin>>opcion;
//			switch(opcion){
//			case 1:
//				controlOpcion = true;
//				break;
//			case 2:
//				controlOpcion = true;
//				break;
//			case 3:
//				controlOpcion = true;
//				break;
//			case 4:
//				controlOpcion = true;
//				break;
//			case 5:
//				controlOpcion = true;
//				break;
//			case 6:
//				controlOpcion = true;
//				break;
//			case 7:
//				controlOpcion = true;
//				break;
//			default:
//				controlOpcion = false;
//				ingresoValido = false;
//				break;
//			}
//		} while(controlOpcion != true);
//		
//		reemplazarDatosProducto(productos, opcion, posProdcuto);	
//	}
//}
//	
//void mostrar_actualizarNuevoProducto(bool& ingresoValido){
//	
//	cout << endl << setw(30)<<" "<<"Actualizar Producto"<<endl<<endl<<setw(2)
//		<<endl<<" ============================================================================= "<<endl<<endl
//		<<setw(6)<<" "<<"1 - Actualizar el nombre del producto"<<endl<<setw(6)<<" "<<"2 - Actualizar el precio de venta del producto"
//		<<endl<<setw(6)<<" "<<"3 - Actualizar el precio de compra del producto"<<endl<<setw(6)<<" "<<"4 - Actualizar el stock del producto"
//		<<endl<<setw(6)<<" "<<"5 - Actualizar la categoria del producto"<<endl<<setw(6)<<" "<<"6 - Actualizar la marca del producto"
//		<<endl<<setw(6)<<" "<<"7 - Volver al menu principal"<<endl<<endl<<endl;
//	
//	if(ingresoValido)
//		cout << endl << setw(2)<< " " << "Ingrese una opcion: ";
//	else{
//		cout << endl <<setw(2)<< " " << "Ingrese una opcion valida: ";
//		ingresoValido = true;
//	}
//}
//
//void actualizarProductos(vector<Producto>productos, int posicion){
//	
//	clearScreen
//	
//	int opcion;
//	bool controlOpcion = false, ingresoValido = true;
//	
//	do{
//		mostrar_actualizarProductos(ingresoValido);
//		
//		cin>>opcion;
//		cin.ignore();
//		
//		switch(opcion){
//		case 1:
//			controlOpcion = true;
//			break;
//		case 2:
//			controlOpcion = true;
//			break;
//		case 3:
//			controlOpcion = true;
//			break;
//		case 4:
//			controlOpcion = true;
//			break;
//		case 5:
//			controlOpcion = true;
//			break;
//		case 6:
//			controlOpcion = true;
//			break;
//		case 7:
//			controlOpcion = true;
//			break;
//		default:
//			controlOpcion = false;
//			ingresoValido = false;
//			break;
//		}
//	} while(!controlOpcion);
//	
//	reemplazarDatosProducto(productos, opcion, posicion);	
//	
//}
	
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
	
//void reemplazarDatosProducto(vector<Producto>& productos, int opcion, int posicion){
//	
//	clearScreen
//	string precios, stock;
//	bool control = true;
//	
//	cout << endl << opcion << endl << posicion << endl;
//	
//	do{
//		clearScreen
//		cin.ignore();
//		switch(opcion){
//			
//			case 1:
//				if(control)
//					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo nombre del producto... ";
//				else
//					cout<<endl<<setw(6)<<" "<<"Ingrese un nuevo nombre del producto correcto, por favor... ";
//				
//				getline(cin, productos[posicion].nombreProducto);
//				
//				control = validacion_string(productos[posicion].nombreProducto);
//				cout << endl << control << endl;
//				systemPause
//				break;
//				
//			case 2:
//				
//				if(control)
//					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo precio de venta del producto... ";
//				else
//					cout<<endl<<setw(6)<<" "<<"Ingrese un precio de venta correcto, por favor... ";
//				
//				getline(cin, precios);
//				
//				control = validacion_numeros_flotantes(precios, productos[posicion].precioVenta);
//				cout << endl << control << endl;
//				
//				systemPause
//				break;
//			case 3:
//				if(control)	
//					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo precio de compra del producto... ";
//				else
//					cout<<endl<<setw(6)<<" "<<"Ingrese un precio de compra correcto, por favor... ";
//				
//				getline(cin, precios);
//				
//				control = validacion_numeros_flotantes(precios, productos[posicion].precioCompra);
//				cout << endl << control << endl;
//				
//				systemPause
//				break;		
//			case 4:
//				if(control)
//					cout<<endl<<setw(6)<<" "<<"Ingrese el nuevo stock del producto... ";
//				else
//					cout<<endl<<setw(6)<<" "<<"Ingrese un numero de stock correcto, por favor... ";
//				
//				getline(cin, stock);
//				
//				control = validacion_numeros_enteros(stock, productos[posicion].stock);
//				cout << endl << control << endl;
//				
//				
//				systemPause
//				break;
//			case 5:
//				if(control)
//					cout<<endl<<setw(6)<<" "<<"Ingrese la nueva categoria del producto... ";
//				else
//					cout<<endl<<setw(6)<<" "<<"Ingrese una categor�a correcta, por favor... ";
//				
//				getline(cin, productos[posicion].categoria);
//				
//				control = validacion_string(productos[posicion].categoria);
//				cout << endl << control << endl;
//				
//				systemPause
//				break;	
//			case 6:
//				if(control)
//					cout<<endl<<setw(6)<<" "<<"Ingrese la nueva marca del producto... ";
//				else
//					cout<<endl<<setw(6)<<" "<<"Ingrese una marca del producto correcta, por favor... ";
//				getline(cin,productos[posicion].marca);
//				
//				control = validacion_string(productos[posicion].marca);
//				cout << endl << control << endl;
//				systemPause
//				
//			break;
//			case 7:
//				control = true;
//				break;
//		}
//		
//		preguntaActualizacionProducto(productos);
//		
//	} while(!control);
//	
//}

void preguntaActualizacionProducto(vector<Producto>productos){
	
	int opcion;
	bool controlQuest = true;

	do{
		clearScreen;
		cout<<endl<<setw(12)<<" "<<"Para continuar seleccione una de las siguientes opciones... "
			<<endl<<endl<<endl<<setw(6)<<" "<<"1 - Continuar modificando datos del mismo producto"
			<<endl<<setw(6)<<" "<<"2 - Actualizar los datos de un nuevo producto"
			<<endl<<setw(6)<<" "<<"3 - Volver al menu principal"
			<<endl<<endl<<endl<<"Su opcion...  ";
			
		cin>>opcion;
		
		switch(opcion){
			
		case 1:
			controlQuest = true;
			break;
		case 2:
			controlQuest = true;
			funcionPrueba(productos);
			break;
		case 3:
			controlQuest = true;
			break;
		default:
			controlQuest = false;
			break;
		}
		
	}while(!controlQuest);

}
	
void borrarProducto(vector<Producto>&productos){
	
	clearScreen
		
		int posProdcuto = buscarPosProducto(productos), opcion;
	
	if(posProdcuto>productos.size()){
		cout<<endl<<setw(6)<<" "<<"Nombre de producto no existente"<<endl<<setw(6)<<" ";
		cin>>opcion;
		switch (opcion){
		default:
			/*menuPrincipal(p, productos);*/
			break;
		}
	} else{
		for(int i = productos.size() - 1;i>posProdcuto;i--){
			productos[i] = productos[i - 1];
		}
		productos.pop_back();
		cout<<"Producto borrado con exito!"<<endl;
		systemPause
//			menuPrincipal(p, productos);
	}
	
}
												
void buscarProductosCoincidentes(vector<Producto>productos){
	
	clearScreen
		
		int opcion, precioMin, precioMax;
	string nombre, categ, marc;
	vector<Producto>productosNombres;
	vector<Producto>productosPrecios;
	vector<Producto>productosCategorias;
	vector<Producto>productosMarcas;
	bool controlCoincidencia = false;
	
	do{
		cout<<"Seleccione una opcion para realizar el filtrado"<<endl<<endl
			<<"1 - Busqueda por nombre coincidente"<<endl
			<<"2 - Busqueda por rango de precios"<<endl
			<<"3 - Busqueda por categoria"<<endl
			<<"4 - Busqueda por marca"<<endl
			<<endl<<"Su opcion...  ";
		cin>>opcion;
		
		switch(opcion){
		case 1:
			controlCoincidencia = true;
			break;
		case 2:
			controlCoincidencia = true;
			break;
		case 3:
			controlCoincidencia = true;
			break;
		case 4:
			controlCoincidencia = true;
			break;
		case 5:
			controlCoincidencia = true;
			break;
		case 6:
			controlCoincidencia = true;
			break;
		case 7:
			controlCoincidencia = true;
			break;
		default:
			controlCoincidencia = false;
			break;
		}
	} while(controlCoincidencia != true);
	
	switch(opcion){
	case 1:
		cin.ignore();
		cout<<"Ingrese el nombre de los productos para filtrarlos... ";
		getline(cin,nombre);
		for(const auto& producto : productos){
			if(nombre == producto.nombreProducto){
				productosNombres.push_back(producto);
			}
		}
		break;
	case 2:
		cout<<"Ingrese el rango de precio para filtrar los productos... "
			<<endl<<endl<<"Precio minimo... ";
		cin>>precioMin;
		cout<<endl<<endl<<"Precio maximo... ";
		cin>>precioMax;
		for(const auto& producto : productos){
			if(precioMin < producto.precioVenta && precioMax > producto.precioVenta){
				productosPrecios.push_back(producto);
			}
		}
		break;
	case 3:
		cin.ignore();
		cout<<"Ingrese la categoria para filtrar los productos... ";
		getline(cin,categ);
		for(const auto& producto : productos){
			if(categ == producto.categoria){
				productosCategorias.push_back(producto);
			}
		}
		break;
	case 4:
		cin.ignore();
		cout<<"Ingrese la marca para filtrar los productos... ";
		getline(cin,marc);
		for(const auto& producto : productos){
			if(marc == producto.marca){
				productosMarcas.push_back(producto);
			}
		}
		break;
	}
	

	/*	switch(opcion){
	case 1:
	for(const auto& producto : productos){
	if(nombre == producto.nombreProducto){
	productosNombres.push_back(producto);
	}
	}
	break;
	case 2:
	for(const auto& producto : productos){
	if(precioMin < producto.precioVenta && precioMax > producto.precioVenta){
	productosPrecios.push_back(producto);
	}
	}
	break;
	case 3:
	for(const auto& producto : productos){
	if(categ == producto.categoria){
	productosCategorias.push_back(producto);
	}
	}
	break;
	case 4:
	for(const auto& producto : productos){
	if(marc == producto.marca){
	productosMarcas.push_back(producto);
	}
	}
	break;
	}*/
	cout<<"Abra el archivo para ver los resultados de la busqueda... "<<endl;
	systemPause;
//	menuPrincipal(p, productos);
	
}
void listarProductos(vector<Producto>&productos){
	
	clearScreen
		
		ofstream archivo("prog.txt");	
	if (archivo.is_open()) {
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
		cout<<endl<<endl<<"Abra el archivo para ver los resultados de el listamiento de los productos... "<<endl<<endl;
		systemPause
//			menuPrincipal(p, productos);
		
	} else {
		cout << "No se pudo abrir el archivo." << endl << endl;
		systemPause
//			menuPrincipal(p, productos);
	}
	
}
