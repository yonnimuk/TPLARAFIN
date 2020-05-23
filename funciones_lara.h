#ifndef FUNCIONES_LARA_H_INCLUDED
#define FUNCIONES_LARA_H_INCLUDED
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <string.h>
using namespace std;
///////STRUCTURAS//////
struct platos
{
    int id;
    char nombre[50];
    float costo_de_preparacion;
    float valor_de_venta;
    int tiempo_de_preparacion;
    int id_restaurante;
    int comision_restaurante;
    int id_categoria;
    bool estado;
};
struct fecha
{
    int dia;
    int mes;
    int anio;
};
struct clientes
{
    int id_cliente;
    char nombre_cliente[50];
    char apellido_cliente[50];
    char mail_cliente[50];
    char domicilio_cliente[100];
    int cp_cliente;
    struct fecha f;
    bool estado;
};
struct pedido
{
    int ID_pedido; /// auto numerico
    int IDCliente_pedido;
    int ID_platto;
    int cantidad_pedido;
    float   precioUnitario_pedido;
    struct fecha fech_pedido;
    float   valoracion_pedido;
    int estado_pedido;
};


////////////prototipos///////////////
bool restaura_copia_s_platos();
bool restaura_copia_s_clientes();
bool restaura_copia_s_pedidos();
bool copia_s_platos();
bool copia_s_clientes();
bool copia_s_pedidos();
void realizar_copia_de_seguridad();
int cant_ped();
int cant_platos();
void configuraciones();
void todos_los_pedidos();
void listar_pedido_x_id();
struct pedido buscar_struct_pedido(int id);
int posicion_pedido_buscar(int id);
void modificar_pedido();
bool platos_validacion(int id);
struct platos buscar_struct_plato(int id);
bool cliente_validacion(int id);
float precio_plato(int id);
int autonumerado_pedido();
bool cargar_pedido();
bool nuevo_pedido(struct pedido *reg);
bool baja_logica_cliente();
void test();
int cantidad_clientes();
void acomoda_por_nombre(struct clientes vec, int cant);
void pide_memoria_dinamicamente();
struct clientes buscar_struct_cliente(int id);
int posicion_cliente(int id);
void modificar_cliente();
void mostrar_cliente_por_id();
void mostrar_cliente(struct clientes reg);
bool crea_archivo_cliente( struct clientes *);
struct fecha fecha_actual();
bool check_anio(int d, int m, int a);
int autonumerado();
bool cargar_cliente(struct clientes *);//
bool baja_logica();
void listar_todos_los_platos();
void platos_por_restaurant();
int validacion_plato(int);
void mostrare(struct platos);
struct platos copypage_platos();
bool cargar_plato(struct platos *);
void guardar_plato(struct platos *);
void mostrar_plato();
int posicion_plato(int);
int menuI();
void menuII();
void menuII();
void menuIV();
////////MOSTRAR O LISTAR//////////////
void mostrare(struct platos mostrare)
{

    cout << "ID: " << mostrare.id << endl;
    cout << "NOMBRE: " << mostrare.nombre << endl;
    cout << "COSTO DE PREPARACION: $" << mostrare.costo_de_preparacion << endl;
    cout << "VALOR DE VENTA: $" << mostrare.valor_de_venta << endl;
    cout << "TIEMPO DE PREPARACION: mnts" << mostrare.tiempo_de_preparacion << endl;
    cout << "ID RESTAURANTE: " << mostrare.id_restaurante << endl;
    cout << "COMISION RESTAURANTE: %" << mostrare.comision_restaurante << endl;
    cout << "ID CATEGORIA: " << mostrare.id_categoria << endl;
    if(mostrare.estado)
    {
        cout << "-HAY STOCK-" << endl;
    }
    else
    {
        cout << "-NO HAY STOCK-" << endl;
    }
    //system("pause");
}
void mostrar_cliente(struct clientes reg)//recibe una estructura ya armada con datos solo para mostrarla.
{
    if(reg.estado)
    {
        cout<<"ID cliente: "<<reg.id_cliente<<endl;
        cout<<"Nombre: "<<reg.nombre_cliente<<endl;
        cout<<"Apellido: "<<reg.apellido_cliente<<endl;
        cout<<"Mail: "<<reg.mail_cliente<<endl;
        cout<<"Domicilio: "<<reg.domicilio_cliente<<endl;
        cout<<"CP(codigo postal): "<<reg.cp_cliente<<endl;
        cout<<"Fecha de nacimiento: "<<reg.f.dia<<"/"<<reg.f.mes<<"/"<<reg.f.anio<<endl;
        if(reg.estado)
        {
            cout<<"En circulacion."<<endl;
        }
        else
        {
            cout<<"Dado de baja."<<endl;
        }
        system("pause");
        return;
    }
}
void mostrar_pedido(struct pedido reg)
{
    cout<<"ID pedido: "<< reg.ID_pedido <<endl;
    cout<<"ID cliente: "<< reg.IDCliente_pedido <<endl;
    cout<<"ID plato: "<< reg.ID_platto <<endl;
    cout<<"Cantidad: "<< reg.cantidad_pedido <<endl;
    cout<<"Precio unitario: "<< reg.precioUnitario_pedido <<endl;
    cout<<"Fecha de el pedido: "<< reg.fech_pedido.dia <<"/"<< reg.fech_pedido.mes << "/" << reg.fech_pedido.anio <<endl;
    cout<<"Valoracion: "<< reg.valoracion_pedido <<endl;
    cout<<"Estado: "<< reg.estado_pedido <<endl;
    system("pause");

    return;
}
///////CARGA/////
bool cargar_plato(struct platos *registro)
{
    system("cls");
    cout << "ID: ";
    cin>>registro->id;
    int ids=registro->id;
    if(registro->id<0)
    {
        cout << "el numero no puede ser menor a cero. " << endl;
        system("pause");
        return false;
    }
    if(validacion_plato(ids)>0)
    {
        system("cls");
        cout << "Este numero ya se encuentra en uso." << endl;
        system("pause");
        return false;
    }
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(registro->nombre,50);

    cout << "COSTO DE PREPARACION: ";
    cin>>registro->costo_de_preparacion;
    if(registro->costo_de_preparacion<0)
    {
        cout << "el numero no puede ser menor a cero. ";
        system("pause");
        return false;
    }
    cout << "VALOR DE VENTA: ";
    cin>>registro->valor_de_venta;
    if(registro->valor_de_venta < 0 || registro->valor_de_venta < registro->costo_de_preparacion)
    {
        cout << "el numero no puede ser menor a cero, o a su costo de preaparacion. ";
        system("pause");
        return false;
    }
    cout << "TIEMPO DE PREPARACION: ";
    cin>>registro->tiempo_de_preparacion;
    if(registro->tiempo_de_preparacion<0)
    {
        cout << "el numero no puede ser menor a cero. ";
        system("pause");
        return false;
    }
    cout << "ID RESTAURANTE: ";
    cin>>registro->id_restaurante;
    if(registro->id_restaurante<0)
    {
        cout << "el numero no puede ser menor a cero. ";
        system("pause");
        return false;
    }
    cout << "COMISION RESTAURANTE: ";
    cin>>registro->comision_restaurante;
    if(registro->comision_restaurante < 0 && registro->comision_restaurante <100 )
    {
        cout << "La comision debe ser entre 0 y 100. ";
        system("pause");
        return false;
    }
    cout << "ID CATEGORIA: ";
    cin>>registro->id_categoria;
    if(registro->id_categoria<0)
    {
        cout << "el numero no puede ser menor a cero. ";
        system("pause");
        return false;
    }
    registro->estado=true;
    system("pause");
    cin.ignore();
    return true;
}

bool cargar_cliente(struct clientes *cliente_cargado)
{
    system("cls");
    int autonum;                            ////
    autonum=autonumerado();                     ////
    if(autonum==-1)                                 ////
    {
        ////
        cliente_cargado->id_cliente=1;                      //// ASIGNANDO ID AUTOMATICO.
    }                                                   ////
    if(autonum>0)                                   ////
    {
        ////
        cliente_cargado->id_cliente=autonum+1;  ////
    }
    //ingreso numero de cliente.
    cout<<"cliente numero: "<< cliente_cargado->id_cliente<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre de el cliente: ";
    cin.getline(cliente_cargado->nombre_cliente,50);
    cin.ignore();
    if(cliente_cargado->nombre_cliente[0]=='\0')
    {
        cout<<"El espacio de el nombre no puede estar vacio."<<endl;
        system("pause");
        return false;
    }
    //ingrese el apellido del cliente.
    cout<<"Ingrese el apellido de el cliente: ";
    cin.getline(cliente_cargado->apellido_cliente,50);
    cin.ignore();
    if(cliente_cargado->nombre_cliente[0]=='\0')
    {
        cout<<"El espacio de el apellido no puede estar vacio."<<endl;
        system("pause");
        return false;
    }

    //ingrese el mail del cliente

    cout<<"Ingrese el mail del cliente: ";
    cin.getline(cliente_cargado->mail_cliente,50);
    cin.ignore();
    int i=0,b=0;
    bool tengopunto=false;
    //numeros desde el 48 hasta el 57//letras mayusculas desde 65 hasta el 90//letras minusculas desde 97 hasta 122 // el (@=64) // el (_ = 95) // el (. = 46 )
    while((cliente_cargado->mail_cliente[i]>=48 && cliente_cargado->mail_cliente[i]<=57)||(cliente_cargado->mail_cliente[i]>=65 && cliente_cargado->mail_cliente[i]<=90) || (cliente_cargado->mail_cliente[i]>=97 && cliente_cargado->mail_cliente[i]<=122) || (cliente_cargado->mail_cliente[i]==64) || (cliente_cargado->mail_cliente[i]==46) || (cliente_cargado->mail_cliente[i]==95))
    {
        if((cliente_cargado->mail_cliente[0]==64) || (cliente_cargado->mail_cliente[0]==46))
        {
            cout<<"no puede empezar con un ''@'' o un ''.'' " <<endl;
            system("pause");
            return false;
        }
        if(cliente_cargado->mail_cliente[i]==64)
        {
            if(cliente_cargado->mail_cliente[i+1]=='\0')
            {
                cout<<"no puede finalizar con un arroba"<<endl;
                system("pause");
                return false;
            }

            if(b==0)
            {
                b=1;
            }
            else
            {
                cout<<"No puede tener mas de un @ en el mail."<<endl;
                system("pause");
                return false;
            }
            if((cliente_cargado->mail_cliente[i+1]==46) ||(cliente_cargado->mail_cliente[i-1]==46))
            {
                cout<<"No puede poner un punto antes o despues de el arroba"<<endl;
                system("pause");
                return false; // revisamos q notenga puntos o guiones antes o despues del arroba.
            }
            if((cliente_cargado->mail_cliente[i+1]==95) || (cliente_cargado->mail_cliente[i-1]==95) )
            {
                cout<<"No puede poner un guion antes o despues de el arroba"<<endl;
                system("pause");
                return false;
            }

        }

        if(cliente_cargado->mail_cliente[i]==46)
        {
            tengopunto=true;
            if((cliente_cargado->mail_cliente[i+1]==46) || (cliente_cargado->mail_cliente[i+1]=='\0'))
            {
                cout<<"no puede tener dos puntos seguidos o terminar con un punto."<<endl;
                system("pause");
                return false;
            }


        }
        i++;
    }
    if(b==0)
    {
        cout<<"debe tener un arroba por lo menos."<<endl;
        system("pause");
        return false;
    }
    if(tengopunto==false)
    {
        cout<<"debe tener al menos un punto. "<<endl;
        system("pause");
        return false;
    }

    cout<<"Ingrese el domicilio: ";
    cin.getline(cliente_cargado->domicilio_cliente,100);
    cin.ignore();
    if(cliente_cargado->domicilio_cliente[0]=='\0' || cliente_cargado->domicilio_cliente[0]==' ')
    {
        return false;
    }
    cout<<"ingrese el codigo postal(un numero entre 1000 y 9999): ";
    cin>>cliente_cargado->cp_cliente;
    cin.ignore();
    if(cliente_cargado->cp_cliente<1000 || cliente_cargado->cp_cliente>9999)
    {
        return false;
    }
    int d,m,a;
    cout<<"ingrese la fecha de nacimeinto."<<endl;
    cout<<"dia: ";
    cin>>cliente_cargado->f.dia;
    cin.ignore();
    d=cliente_cargado->f.dia;
    cout<<endl;
    cout<<"mes: ";
    cin>>cliente_cargado->f.mes;
    cin.ignore();
    m=cliente_cargado->f.mes;
    cout<<endl;
    cout<<"anio: ";
    cin>>cliente_cargado->f.anio;
    cin.ignore();
    a=cliente_cargado->f.anio;
    if(check_anio(d,m,a)==false)
    {
        return false;
    }

    cliente_cargado->estado=true;
    cin.ignore();
    return true;
}
bool cargar_pedido(struct pedido *reg)
{
    int idd=autonumerado_pedido();
    if(idd==-1)
    {
        reg->ID_pedido=1;
    }
    if(idd>0)
    {
        reg->ID_pedido=idd+1;
    }
    cout<<"pedido numero #"<<reg->ID_pedido<<endl;
    cout<<"Ingrese el ID de el cliente que realiza el pedido: ";
    cin>>reg->IDCliente_pedido;
    int id=reg->IDCliente_pedido;
    if(cliente_validacion(id))
    {
        if(posicion_cliente(id)>=0)
        {
            /// si. lo se esto no se hace.
        }
        else
        {
            return false;
        }
        cout<<"ingrese el ID de el plato solicitado: ";
        cin>>reg->ID_platto;
        int idp=reg->ID_platto;
        if(platos_validacion(idp))
        {
            if(posicion_plato(idp)<0)
            {
                return false;
            }
            int cant;
            cout<<"Ingrese la cantidad: ";
            cin>>reg->cantidad_pedido;
            cant=reg->cantidad_pedido;
            if(cant<=0)
            {
                cout<<"la cantidad no puede ser menor o igual a cero"<<endl;
                system("pause");
                return false;
            }
            float pup = precio_plato(idp);
            if(pup<0)
            {
                return false;
            }
            else
            {
                reg->precioUnitario_pedido=pup;
            }
            cin.ignore();
            int d,m,a;
            cout<<"Fecha de el pedido: "<<endl;
            cout<<"Dia: ";
            cin>> reg->fech_pedido.dia;
            d=reg->fech_pedido.dia;
            cout<<"Mes: ";
            cin>>reg->fech_pedido.mes;
            m=reg->fech_pedido.mes;
            cout<<"Anio: ";
            cin>>reg->fech_pedido.anio;
            a=reg->fech_pedido.anio;
            if(check_anio(d,m,a)==false)
            {
                return false;
            }
            cin.ignore();
            cout<<"Valoracion: ";
            cin>>reg->valoracion_pedido;
            if(reg->valoracion_pedido<0)
            {
                cout<<"El numero no puede ser menor a 0."<<endl;
                system("pause");
                return false;
            }
            reg->estado_pedido=1;
            cout<<"El estado de el pedido: en curso"<<endl;
            return true;
        }
    }
        return false;
}

////anio bisiesto///////
bool check_anio(int d, int m, int a)/// Es una cochinada. pero fuciona :V .
{
    struct fecha fechactual;
    fechactual = fecha_actual();
    if(a==fechactual.anio)
    {
        //cout<<"paso el if 1a"<<endl;
        //system("pause");
        if(m<=fechactual.mes) /// este if y otros parecidos pueden denegar la secuencia if(m<=fechactual.mes)
        {
            //cout<<"paso el if 2a"<<endl;
            //system("pause");
            if(d<=fechactual.dia || d>=fechactual.dia)
            {
                //cout<<"paso el if 3a"<<endl;
                //system("pause");
                if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))///el año es bisiesto?
                {
                    //cout<<"paso el if 4a"<<endl;
                    //system("pause");
                    if(m==4 || m==6 || m==9 || m==11)
                    {
                        //cout<<"paso el if 5a"<<endl;
                        //system("pause");
                        if(d>0 && d<=30)
                        {
                            //cout<<"paso el if 6a"<<endl;
                            //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
                    {
                        //cout<<"paso el if 7a"<<endl;
                        //system("pause");
                        if(d>0 && d<=31)
                        {
                           cout<<"paso el if 8a"<<endl;
                            system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==2)
                    {
                        //cout<<"paso el if 9a"<<endl;
                        //system("pause");
                        if(d>0 && d<=29)
                        {
                            //cout<<"paso el if 10a"<<endl;
                            //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else  /// en caso de no ser bisiesto.
                {
                    //cout<<"paso el else"<<endl;
                    //system("pause");
                    if(m==4 || m==6 || m==9 || m==11)
                    {
                        //cout<<"paso el if 11a"<<endl;
                        //system("pause");
                        if(d>0 && d<=30)
                        {
                            //cout<<"paso el if 12a"<<endl;
                            //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
                    {
                        //cout<<"paso el if 13a"<<endl;
                        //system("pause");
                        if(d>0 && d<=31)
                        {
                            //cout<<"paso el if 14a"<<endl;
                            //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==2)
                    {
                        //cout<<"paso el if 15a"<<endl;
                        //system("pause");
                        if(d>0 && d<=28)
                        {
                            //cout<<"paso el if 16a"<<endl;
                            //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            {
                return false;
            }
        }
        {
            return false;
        }
    }
    else if(a<fechactual.anio)
    {
        if(m<=fechactual.mes || m>=fechactual.mes) /// este if y otros parecidos pueden denegar la secuencia if(m<=fechactual.mes)
        {
            //cout<<"paso el if 2"<<endl;
            //system("pause");
            if(d<=fechactual.dia || (d>=fechactual.dia && m<fechactual.mes))
            {
                //cout<<"paso el if 3"<<endl;
                //system("pause");
                if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))///el año es bisiesto?
                {
                    //cout<<"paso el if 4"<<endl;
                    //system("pause");
                    if(m==4 || m==6 || m==9 || m==11)
                    {
                        //cout<<"paso el if 5"<<endl;
                        //system("pause");
                        if(d>0 && d<=30)
                        {
                            //cout<<"paso el if 6"<<endl;
                            //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
                    {
                        //cout<<"paso el if 7"<<endl;
                        //system("pause");
                        if(d>0 && d<=31)
                        {
                             //cout<<"paso el if 8"<<endl;
                             //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==2)
                    {
                        //cout<<"paso el if 9"<<endl;
                        //system("pause");
                        if(d>0 && d<=29)
                        {
                             //cout<<"paso el if 10"<<endl;
                             //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else  /// en caso de no ser bisiesto.
                {
                    //cout<<"paso el else"<<endl;
                    //system("pause");
                    if(m==4 || m==6 || m==9 || m==11)
                    {
                        //cout<<"paso el if 11"<<endl;
                         //system("pause");
                        if(d>0 && d<=30)
                        {
                             //cout<<"paso el if 12"<<endl;
                            //system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
                    {
                        //cout<<"paso el if 13"<<endl;
                        //system("pause");
                        if(d>0 && d<=31)
                        {
                            // cout<<"paso el if 14"<<endl;
                            // system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(m==2)
                    {
                        //cout<<"paso el if 15"<<endl;
                        //system("pause");
                        if(d>0 && d<=28)
                        {
                            // cout<<"paso el if 16"<<endl;
                            // system("pause");
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            {
                return false;
            }
        }
    }
    {
        return false;
    }
//system("pause");
}

struct fecha fecha_actual()
{
    //este link explica que hace ->  https://www.youtube.com/watch?v=c0ZMWN1RLt4
    time_t t;
    t=time(NULL);
    struct tm*f;
    f=localtime(&t);
    fecha aux;
    aux.dia = f->tm_mday;
    aux.mes = f->tm_mon+1;
    aux.anio = f->tm_year+1900;
    //system("pause");
    return aux;

}
///--------------------------------------------COSAS FILE-----------------------------------------------------------///

///--------------------------------------------CONFIGURACIONES-----------------------------------------------------------///
void restaurar_copia_de_seguridad()
{
    if(restaura_copia_s_clientes())
    {
        cout<<"Restauracion ESITOSA de clientes."<<endl;
        system("pause");
    }else{cout<<"Restauracion FALLIDA de clientes."<<endl; system("pause");}
    if(restaura_copia_s_pedidos())
    {
        cout<<"Restauracion EXITOSA de pedidos."<<endl;
        system("pause");
    }else{cout<<"Restauracion FALLIDA de pedidos."<<endl; system("pause");}
    if(restaura_copia_s_platos())
    {
        cout<<"Restauracion EXITOSA de platos."<<endl;
        system("pause");
    }else{cout<<"Restauracion FALLIDA de platos."<<endl; system("pause");}

}

bool restaura_copia_s_platos()
{
    struct platos *regpla;
    int cantpla;
    cantpla=cant_platos();
    regpla=(struct platos*)malloc(cantpla*sizeof(struct platos));

    if(regpla==NULL)
    {
        cout<<"Falta memoria para continuar."<<endl;
        system("pause");
        return false;
    }
    FILE *p;
    p=fopen("platos.bkp","rb");
    if(p==NULL)
    {
        free(regpla);
        free(regpla);
        cout<<"Error al abrir el archivo: cliente. "<<endl;
        system("pause");
        return false;
    }
    fread(regpla,sizeof(platos),cantpla,p);
    FILE *b;
    b=fopen("archivo.dat","wb");
    if(b==NULL)
    {
        fclose(b);
        free(regpla);
        cout<<"error NULL b"<<endl;
        system("pause");
        return false;
    }
    fwrite(regpla,sizeof(platos),cantpla,b);
    fclose(b);
    free(regpla);
    return true;
}

bool restaura_copia_s_clientes()
{
    struct clientes *regc;
    int cantc;
    cantc=cantidad_clientes(); ///ya existe fuera de configuraciones en clientes.
    regc=(struct clientes*)malloc(cantc*sizeof(struct clientes));

    if(regc==NULL)
    {
        cout<<"Falta memoria para continuar."<<endl;
        system("pause");
        return false;
    }
    FILE *p;
    p=fopen("cliente.bkp","rb");
    if(p==NULL)
    {
        free(regc);
        cout<<"Error al abrir el archivo: cliente. "<<endl;
        system("pause");
        return false;
    }
    fread(regc,sizeof(clientes),cantc,p);
    FILE *b;
    b=fopen("cliente.dat","wb");
    if(b==NULL)
    {
        fclose(b);
        free(regc);
        cout<<"error NULL b"<<endl;
        system("pause");
        return false;
    }
    fwrite(regc,sizeof(clientes),cantc,b);
    fclose(b);
    free(regc);
    return true;

}

bool restaura_copia_s_pedidos()
{

    struct pedido *reped;
    int cantped;
    cantped=cant_ped();
    reped=(struct pedido*)malloc(cantped*sizeof(struct pedido));

    if(reped==NULL)
    {
        cout<<"Falta memoria para continuar."<<endl;
        system("pause");
        return false;
    }
    FILE *p;
    p=fopen("pedido.bkp","rb");
    if(p==NULL)
    {
        free(reped);
        cout<<"Error al abrir el archivo: cliente. "<<endl;
        system("pause");
        return false;
    }
    fread(reped,sizeof(pedido),cantped,p);
    FILE *b;
    b=fopen("pedido.dat","wb");
    if(b==NULL)
    {
        fclose(b);
        free(reped);
        cout<<"error NULL b2"<<endl;
        system("pause");
        return false;
    }
    fwrite(reped,sizeof(pedido),cantped,b);
    fclose(b);
    free(reped);
    return true;

}


void realizar_copia_de_seguridad()
{
    if(copia_s_clientes())
    {
        cout<<"Copia ESITOSA de clientes."<<endl;
        system("pause");
    }else{cout<<"Copia FALLIDA de clientes."<<endl; system("pause");}
    if(copia_s_pedidos())
    {
        cout<<"Copia EXITOSA de pedidos."<<endl;
        system("pause");
    }else{cout<<"Copia FALLIDA de clientes."<<endl; system("pause");}
    if(copia_s_platos())
    {
        cout<<"Copia EXITOSA de platos."<<endl;
        system("pause");
    }else{cout<<"Copia FALLIDA de platos."<<endl; system("pause");}

return;
}
/*void mostrar_copias()
{
    struct pedido reg;
    FILE *p;
    p=fopen("pedido.bkp","rb");
    if(p==NULL)
    {
        cout<<"Error NULL."<<endl; system("pause");
        fclose(p);
        return;
    }
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {
        cout<<"-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.--.-."<<endl;
        mostrar_pedido(reg);
        cout<<"-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.--.-."<<endl;
    }
    fclose(p);
    cout<<"finalizo la mostrada"<<endl;
    system("pause");
    return;
}
*/

bool copia_s_pedidos()
{

    struct pedido *reped;
    int cantped;
    cantped=cant_ped();
    reped=(struct pedido*)malloc(cantped*sizeof(struct pedido));

    if(reped==NULL)
    {
        cout<<"Falta memoria para continuar."<<endl;
        system("pause");
        return false;
    }
    FILE *p;
    p=fopen("pedido.dat","rb");
    if(p==NULL)
    {
        free(reped);
        cout<<"Error al abrir el archivo: cliente. "<<endl;
        system("pause");
        return false;
    }
    fread(reped,sizeof(pedido),cantped,p);
    FILE *b;
    b=fopen("pedido.bkp","wb");
    if(b==NULL)
    {
        fclose(b);
        free(reped);
        cout<<"error NULL b"<<endl;
        system("pause");
        return false;
    }
    fwrite(reped,sizeof(pedido),cantped,b);
    fclose(b);
    free(reped);
    return true;

}

bool copia_s_clientes()
{
    struct clientes *regc;
    int cantc;
    cantc=cantidad_clientes(); ///ya existe fuera de configuraciones en clientes.
    regc=(struct clientes*)malloc(cantc*sizeof(struct clientes));

    if(regc==NULL)
    {
        cout<<"Falta memoria para continuar."<<endl;
        system("pause");
        return false;
    }
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL)
    {
        free(regc);
        cout<<"Error al abrir el archivo: cliente. "<<endl;
        system("pause");
        return false;
    }
    fread(regc,sizeof(clientes),cantc,p);
    FILE *b;
    b=fopen("cliente.bkp","wb");
    if(b==NULL)
    {
        fclose(b);
        free(regc);
        cout<<"error NULL b"<<endl;
        system("pause");
        return false;
    }
    fwrite(regc,sizeof(clientes),cantc,b);
    fclose(b);
    free(regc);
    return true;

}

bool copia_s_platos()
{
    struct platos *regpla;
    int cantpla;
    cantpla=cant_platos();
    regpla=(struct platos*)malloc(cantpla*sizeof(struct platos));

    if(regpla==NULL)
    {
        cout<<"Falta memoria para continuar."<<endl;
        system("pause");
        return false;
    }
    FILE *p;
    p=fopen("archivo.dat","rb");
    if(p==NULL)
    {
        free(regpla);
        free(regpla);
        cout<<"Error al abrir el archivo: cliente. "<<endl;
        system("pause");
        return false;
    }
    fread(regpla,sizeof(platos),cantpla,p);
    FILE *b;
    b=fopen("platos.bkp","wb");
    if(b==NULL)
    {
        fclose(b);
        free(regpla);
        cout<<"error NULL b"<<endl;
        system("pause");
        return false;
    }
    fwrite(regpla,sizeof(platos),cantpla,b);
    fclose(b);
    free(regpla);
    return true;
}

int cant_ped()
{
    struct pedido reg;
    int cant=0;
    FILE *p;
    p=fopen("pedido.dat","rb");
    if(p==NULL)
    {
        fclose(p);
        return -1;
    }
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {
        cant++;
    }
    fclose(p);
    return cant;
}


int cant_platos()
{
    struct platos reg;
    int cant=0;
    FILE *p;
    p=fopen("archivo.dat","rb");
    if(p==NULL)
    {
        fclose(p);
        return -1;
    }
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {
        cant++;
    }
    fclose(p);
    return cant;
}


///--------------------------------------------PEDIDOS-----------------------------------------------------------///
void todos_los_pedidos()
{
    struct pedido reg;
    FILE *p;
    p=fopen("pedido.dat","rb");
    if(p==NULL)
    {
        cout<<"Error NULL en func: todos los pedidos "<<endl;
        system("pause");
        return;
    }
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {
        cout<<"--------------------------------------"<<endl;
        mostrar_pedido(reg);
        cout<<"--------------------------------------"<<endl;
    }
    system("pause");
    fclose(p);
    return;
}

void listar_pedido_x_id()
{
    struct pedido reg;
    int id;
    cout<<"Ingrese el ID de el pedido que desea ver: ";
    cin>>id;
    FILE *p;
    p=fopen("pedido.dat","rb");
    if(p==NULL)
    {
        cout<<"Error NULL en listar pedido por id"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {
        if(reg.ID_pedido==id)
        {
            mostrar_pedido(reg);
            fclose(p);
            return;
        }
    }
    fclose(p);
    cout<<"Error. no se encontro el pedido."<<endl;
    system("pause");
    return;
}

struct pedido buscar_struct_pedido(int id)
{
    struct pedido reg;
    FILE *p;
    p=fopen("pedido.dat","rb");
    if(p==NULL)
    {
        cout<<"Error NULL buscar struct pedido."<<endl;
        system("pause");
        fclose(p);
        reg.estado_pedido=-1;
        return reg;
    }
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {
        if(reg.ID_pedido==id)
        {
            fclose(p);
            return reg;
        }
    }
    reg.estado_pedido=-2;
    return reg;
};

int posicion_pedido_buscar(int id)
{
    struct pedido reg;
    int cont=0;
    FILE *p;
    p=fopen("pedido.dat","rb");
    if(p==NULL)
    {
        cout<<"Error NULL en posicion pedido buscar. "<<endl;
        system("pause");
        fclose(p);
        cont=-1;
        return cont;
    }
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {
        if(reg.ID_pedido==id)
        {
            return cont;
        }
        cont++;
    }
    cont=-2;
    return cont;
}

void modificar_pedido()
{
    struct pedido reg;
    int pos,id;
    cout<<"Ingrese el ID de el pedido que desea modificar el estado: ";
    cin>>id;
    pos=posicion_pedido_buscar(id);
    if(pos>=0)
    {
    FILE *p;
    p=fopen("pedido.dat","rb+");
    if(p==NULL)
    {
        cout<<"Error NULL"<<endl;
        fclose(p);
        return;
    }
    reg=buscar_struct_pedido(id);
        if(reg.estado_pedido>0)
        {
        cout<<"Datos anteriores: "<<endl;
        mostrar_pedido(reg);
        cout<<"Cambie el estado de el pedido con: "<<endl;
        cout<<"1-Pedido en curso."<<endl;
        cout<<"2-Pedido completado."<<endl;
        cout<<"3-Pedido cancelado."<<endl;
        cin>>reg.estado_pedido;
            if(reg.estado_pedido>3 || reg.estado_pedido<0)
            {
                cout<<"Te acabo de dar tres opciones...TR3S!"<<endl;
                system("pause");
                return;
            }
        cout<<"Estado actual: "<<endl;
        fseek(p,pos*sizeof(pedido),SEEK_SET);
        fwrite(&reg,sizeof(pedido),1,p);
        mostrar_pedido(reg);
        fclose(p);
        return;
        }
    fclose(p);
    return;
    }

}

bool nuevo_pedido(struct pedido *reg) /// crea el pedido de a uno.
{
    FILE *p;
    p=fopen("pedido.dat","ab");
    if(p==NULL)
    {
        fclose(p);
        system("pause");
        return false;
    }
    fwrite(reg,sizeof(pedido),1,p);
    fclose(p);
    return true;
}

bool platos_validacion(int id) /// para la carga de datos
{
    struct platos reg;
    reg=buscar_struct_plato(id);
    if(reg.id>0)
    {
    if(reg.estado==false)
        {
            system("pause");
            return false;
        }else{return true;}
    }else{return false;}
}
struct platos buscar_struct_plato(int id)///para la carga de pedidos
{
    struct platos reg;
    FILE *p;
    p=fopen("archivo.dat","rb");
    if(p==NULL)
    {
        fclose(p);
        reg.id=-1;
        return reg;
    }
    while(fread(&reg,sizeof(platos),1,p)==1)
    {
        if(reg.id==id)
        {
            if(reg.estado)
            {
            fclose(p);
            return reg;
            }
        }
    }
    fclose(p);
    reg.id=-2;
    return reg;
};
bool cliente_validacion(int id)///para la carga de pedidos
{
    struct clientes reg;
    reg=buscar_struct_cliente(id);
    if(reg.id_cliente>0)
    {
    if(reg.estado==false)
        {
            return false;
        }
    }
    return true;
}
float precio_plato(int id)
{
    float pretunrn;
    struct platos reg;
    int pos=posicion_plato(id);
    FILE *p;
    p=fopen("archivo.dat","rb");
    if(p==NULL)
    {
        fclose(p);
        return -1;
    }
    if(pos>=0)
    {
    fseek(p,pos*sizeof(platos),SEEK_SET);
    fread(&reg,sizeof(platos),1,p);
    pretunrn=reg.valor_de_venta;
    fclose(p);
    return pretunrn;
    }
    fclose(p);
    return -2;
}

int autonumerado_pedido()
{
    struct pedido reg;
    int numreturn;
    FILE *p;
    p=fopen("pedido.dat","rb");
    if(p==NULL)
    {
        cout<<"No se encontro el pedido. Puede que no este creado."<<endl;
        system("pause");
        fclose(p);
        return -1;//en caso de no existir retorno -1
    }
    int con=0;
    while(fread(&reg,sizeof(pedido),1,p)==1)
    {

        con++;
    }
    numreturn=con;
    fclose(p);
    return numreturn;//en caso de existir retorno el ultimo numero guardado.
}

///--------------------------------------------CLIENTES-----------------------------------------------------------///

bool baja_logica_cliente()
{
    struct clientes reg;
    int pos;
    int id;
    cout << "DANDO DE BAJA UN CLIENTE. "<<endl;
    cout<<"ingrese el id de el archivo que desea dar de baja: ";
    cin>>id;
    pos=posicion_cliente(id);
    FILE *p;
    p=fopen("cliente.dat","rb+");
    if(p==NULL)
    {
        cout<<"nope"<<endl;
        system("pause");
        fclose(p);
        return false;
    }
    if(pos>=0)
    {
        reg=buscar_struct_cliente(id);
        reg.estado=false;
        fseek(p,pos*sizeof(clientes),SEEK_SET);
        fwrite(&reg,sizeof(clientes),1,p);
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}
void acomoda_por_nombre(struct clientes *vec, int cant)/// ESTA FUNCION ME LA PASO NAZARENO. EXAMINAR PARA ENTENDER.
{
    int i, j, pos;
    struct clientes aux;
    for(i=0; i<cant-1; i++)
    {
        pos=i;
        for(j=i+1; j<cant; j++)
        {
            if(strcasecmp(vec[j].apellido_cliente, vec[pos].apellido_cliente)<0) ///esta funcion fue la clave strcasecmp.
            {
                //pos=j;
                aux=vec[i];
                vec[i]=vec[pos];
                vec[pos]=aux;
            }
        }
        /*aux=vec[i];
        vec[i]=vec[pos];
        vec[pos]=aux;*/
    }
}

void pide_memoria_dinamicamente() /// parkour(?
{
    int cant=cantidad_clientes();
    struct clientes *vec;///por alguna razon solo puedo pasarlo con el asterisco eso lleva a poner el astersico en todos lados menos en
    vec=(struct clientes*) malloc(cant*sizeof(struct clientes));///sizeof(struct cliente) por el resto si pide q le ponga asterisco. osea-
    /// tiene q ser un puntero struct de vec para poder crear un vector de struct
    if(vec==NULL)
    {
        cout<<"Falta memoria para continuar."<<endl;
        system("pause");
        return;
    }
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL)
    {
        free(vec);
        cout<<"Error al abrir el archivo: cliente. "<<endl;
        system("pause");
        return;
    }
    fread(vec,sizeof(clientes),cant,p);
    acomoda_por_nombre(&(*vec),cant);
    for(int i=0; i<cant; i++)
    {
        mostrar_cliente(vec[i]);
    }
    system("pause");

    free(vec);
}

void test()
{
    int cant=cantidad_clientes();
    cout<<cant<<endl;
    system("pause");
    return;
}
int cantidad_clientes()/// devuelve un entero que indica la cantidad de clientes que hay.(no discrimina si el estado bool es false)
{
    struct clientes reg;
    int cant=0;
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL)
    {
        fclose(p);
        return -1;
    }
    while(fread(&reg,sizeof(clientes),1,p)==1)
    {
        //if(reg.estado)   esto generaba q se achicaran los vectores y en listar los productos se auto limitaba.
        //{
        cant++;
        //}
    }
    fclose(p);
    return cant;
}

struct clientes buscar_struct_cliente(int id) /// recibe un id para buscar y retornar el cliete como structura.
{
    struct clientes reg;
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL)
    {
        reg.id_cliente=-1;
        return reg;
    }
    while(fread(&reg,sizeof(clientes),1,p)==1)
    {
        if(reg.id_cliente==id)
        {
            fclose(p);
            return reg;
        }
    }
    reg.id_cliente=-2;
    fclose(p);
    return reg;
};

int posicion_cliente(int id) /// recibe un id para buscar la posicion y retornarla como entero.
{
    struct clientes reg;
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL)
    {
        fclose(p);
        return -1;
    }
    int i=0;
    while(fread(&reg,sizeof(clientes),1,p)==1)
    {
        if(reg.id_cliente==id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -2;
}


void modificar_cliente()///modifica el cliente. usando las funciones posicion_cliente(id); y buscar_struct_cliente(id);
{
    struct clientes reg;
    int pos,id;
    cout<<"ingrese el id de el producto que desea modificar: ";
    cin>>id;
    cin.ignore();
    pos=posicion_cliente(id);
    FILE *p;
    p=fopen("cliente.dat","rb+");
    if(p==NULL)
    {
        cout<<"no se encontro el archivo."<<endl;
        system("pause");
        return;
    }
    if(pos>=0)
    {
        reg=buscar_struct_cliente(id);
        if(reg.estado==true)
        {
            if(reg.id_cliente>=0)
            {
                mostrar_cliente(reg);
                cout<<"modifique el domicilio. "<<endl;
                cin.getline(reg.domicilio_cliente,100);
                cin.ignore();
                fseek(p,pos*sizeof(clientes),SEEK_SET);
                fwrite(&reg,sizeof(clientes),1,p);
                cout<<"Dato cambiado: "<<endl;
                mostrar_cliente(reg);
                fclose(p);
                return;
            }
        }
        else
        {
            cout<<"Dado de baja"<<endl;
        }
    }
    cout<<"No se pudo cambiar datos."<<endl;
    system("pause");
    fclose(p);
    return;
}

void mostrar_cliente_por_id()///acopla con: void mostrar_cliente(struct clientes reg);
{
    struct clientes reg;
    int id;
    cout<<"Inrese el ID de el cliente que desea ver. "<<endl;
    cin>>id;
    //cin.ignore();
    if(id<0)
    {
        cout<<"El no puede ser menor a cero."<<endl;
        system("pause");
        return;
    }
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL)
    {
        cout<<"cliente no encontrado. "<<endl;
        system("pause");
        fclose(p);
        return;
    }
    while(fread(&reg,sizeof(clientes),1,p)==1)
    {
        if(reg.id_cliente==id)
        {
            if(reg.estado==true)
            {
                mostrar_cliente(reg);
                fclose(p);
                return;
            }
        }
    }
    cout<<"El cliente con el id indicado no se encuentra. puede no existir o estar dado de baja. "<<endl;
    system("pause");
    fclose(p);
    return;
}

bool crea_archivo_cliente( struct clientes *reg)///si viene con puntero se guarda sin el ampersan NO TE LO OLVIDES ANOTALO PELOTUDDO
{
    FILE *p;
    p=fopen("cliente.dat","ab");
    if(p==NULL)
    {
        cout<<"error al cargar el cliente."<<endl;
        system("pause");
        fclose(p);
        return false;
    }
    fwrite(reg,sizeof(clientes),1,p); // aca en reg no va el ampersan.
    fclose(p);
    return true;
}
int autonumerado()///reviso si ya existe el numero de registro.
{
    struct clientes reg;
    int numreturn;
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL)
    {
        cout<<"No se encontro el cliente. Puede que no este creado."<<endl;
        system("pause");
        fclose(p);
        return -1;//en caso de no existir retorno -1
    }
    int con=0;
    while(fread(&reg,sizeof(clientes),1,p)==1)
    {

        con++;
    }
    numreturn=con;
    fclose(p);
    return numreturn;//en caso de existir retorno el ultimo numero guardado.
}
///--------------------------------------------PLATOS-----------------------------------------------------------///
int validacion_plato(int id) /// se esta usando para la cargarga de platos.
{
    struct platos reg;
    FILE *p;
    p=fopen("archivo.dat","rb"); //abrimos archivo como lectura.
    if(p==NULL)
    {
        fclose(p);
        return-1;
    }
    while(fread(&reg,sizeof(platos),1,p)==1)  //pasamos a la memoria y chekeamos.
    {
        if(reg.id==id)  //nos fijamos que el id concuerde con el que buscamos
        {
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return-2;
}
void guardar_plato(struct platos *cargado)  /// pase mal el dato, estaba pasando un dato nuevo con basura para guardar,
///y no el que ya estaba guardado. estaba haciendo void guardar_plato(struct platos cargadp){}
{
    FILE *guardar;
    guardar = fopen("archivo.dat","ab");
    if(guardar == NULL)
    {
        cout << "ERROR EN GUARDAR PLATO." << endl;
        system("pause");
        return;
        fclose(guardar);
    }
    fwrite(cargado,sizeof(platos),1,guardar);
    cout<<"plato guardado con exito!"<<endl;
    fclose(guardar);
}
void mostrar_plato()
{
    int id;
    cout << "Ingresa El ID del producto que desea ver: ";
    cin>>id;
    cin.ignore();
    cout<<endl;
    struct platos reg;
    FILE *mostrar;
    mostrar = fopen("archivo.dat","rb");
    if(mostrar == NULL)
    {
        cout << "ERROR EN MOSTRAR PLATO." << endl;
        system("pause");
        fclose(mostrar);
        return;
    }
    while(fread(&reg,sizeof(platos),1,mostrar)==1)
    {
        if(reg.id == id && reg.estado == true)
        {
            mostrare(reg);
        }
        else if(reg.id == id && reg.estado == false)
        {
            cout<<"Este archivo fue dado de baja. consulte al soporte para volver a darlo de alta. Por que solo pidio la baja en su menu. "<<endl;

        }
    }
    system("pause");
    fclose(mostrar);
    return;

}
int posicion_plato(int id)  /// solicitamos un id para devolver la posicion de el archivo.
{
    int i=0;
    struct platos reg;
    FILE *p;
    p=fopen("archivo.dat","rb"); //abrimos archivo como lectura.
    if(p==NULL)
    {
        cout << "ERROR EN LA BUSQUEDA DE POSICION DE EL PLATO." << endl;
        system("pause");
        fclose(p);
        return-1;
    }
    while(fread(&reg,sizeof(platos),1,p)==1)  //pasamos a la memoria y chekeamos.
    {
        if(reg.id==id)  //nos fijamos que el id concuerde con el que buscamos
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return-2;
}
struct platos copypage_platos(int ids) /// usamos la funcion de posicion para saber que archivo debemos retornar y modificar en otra funcion.
{
    struct platos platico;
    long int pos=posicion_plato(ids);
    FILE *p;
    p=fopen("archivo.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR EN LA MODIFICACION DE PLATOS. " << endl;
        system("pause");
        fclose(p);
        platico.id=-1;
        return platico;
    }
    fseek(p,pos*sizeof(platos),SEEK_SET);
    fread(&platico,sizeof(platos),1,p);
    fclose(p);
    return platico;

};
void mod_platos()/// modificar platos.
{
    struct platos reg;
    int pos;
    int id;
    cout << "Modificando Datos ingrese id: ";
    cin>>id;
    pos=posicion_plato(id);

    FILE *p;
    p=fopen("archivo.dat","rb+");
    if(p==NULL)
    {
        cout<<"nope"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    if(pos>=0)
    {
        reg=copypage_platos(id);
        mostrare(reg);
        cout<<"Modifique el precio: "<<endl;
        cin>>reg.valor_de_venta;
        cin.ignore();
        cout<<endl;
        cout<<"Modifique el tiempo de preparacion. "<<endl;
        cin>>reg.tiempo_de_preparacion;
        cin.ignore();
        fseek(p,pos*sizeof(platos),SEEK_SET); ///acomod ala posicion que deso modificar
        fwrite(&reg,sizeof(platos),1,p);   ///guardo el cambio de datos (estamos pisando el archivo viejo.
        mostrare(reg);  ///muestro el archivo ya alterado
    }
    system("pause");
    fclose(p);
    return;
}
void platos_por_restaurant()
{
    struct platos reg;
    int id;
    cout<<"ingrese el id del restaurant: ";
    cin>>id;
    cin.ignore();
    FILE *p;
    p=fopen("archivo.dat","rb");
    if(p==NULL)
    {
        cout<<"No se encontro." << endl;
        system("pause");
        fclose(p);
        return;
    }
    cout<<"PLATOS DEL RESTAURANT: #"<< id <<endl;
    while(fread(&reg,sizeof(platos),1,p)==1)
    {
        if(reg.id_restaurante==id)
        {
            cout<<"-------------------------"<<endl;
            mostrare(reg);

        }
    }
    system("pause");
    fclose(p);
    return;
}
void listar_todos_los_platos()
{
    struct platos reg;
    FILE *p;
    p=fopen("archivo.dat","rb");
    if(p==NULL)
    {
        cout<<"no se pudo encontrar el archivo: "<<endl;
        system("pause");
        return;
    }
    while(fread(&reg,sizeof(platos),1,p)==1)
    {
        cout<<"--------------------------------------"<<endl;
        mostrare(reg);
        cout<<"--------------------------------------"<<endl;
    }
    system("pause");
    fclose(p);
    return;
}
bool baja_logica()/// baja logica de platos.
{
    struct platos reg;
    int pos;
    int id;
    cout << "DANDO DE BAJA UN ARCHIVO. "<<endl;
    cout<<"ingrese el id de el archivo que desea dar de baja: ";
    cin>>id;
    pos=posicion_plato(id);
    FILE *p;
    p=fopen("archivo.dat","rb+");
    if(p==NULL)
    {
        cout<<"nope"<<endl;
        system("pause");
        fclose(p);
        return false;
    }
    if(pos>=0)
    {
        reg=copypage_platos(id);
        reg.estado=false;
        fseek(p,pos*sizeof(platos),SEEK_SET);
        fwrite(&reg,sizeof(platos),1,p);
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}
//////////MENUS/////////////
int menuI()/// MENU DE PRINCIPAL ///
{
    int op;
    cout << "MENU PRINCIPAL." << endl;
    cout << "------------------------" << endl;
    cout << "1) PLATOS. " << endl;
    cout << "2) CLIENTES." << endl;
    cout << "3) PEDIDOS." << endl;
    cout << "4) REPORTES." << endl;
    cout << "5) CONFIGURACION." << endl;
    cout << "------------------------" << endl;
    cout << "0) SALIR" << endl;
    cin>>op;
    return op;
}
void menuII()/// MENU DE PLATOS ///
{
    struct platos cargado;
    while(true)
    {
        system("cls");
        int op;
        cout << "MENU PLATOS." << endl;
        cout << "------------------------" << endl;
        cout << "1) NUEVO PLATO. " << endl;
        cout << "2) MODIFICAR PLATO." << endl;
        cout << "3) LISTAR PLATO POR ID." << endl;
        cout << "4) PLATOS POR RESTAURANT." << endl;
        cout << "5) LISTAR TODOS LOS PLATOS." << endl;
        cout << "6) ELIMINAR PLATO." << endl;
        cout << "------------------------" << endl;
        cout << "0) SALIR" << endl;
        cin>>op;

        switch(op)
        {
        case (1):
        {
            system("cls");
            cout<<"CARGANDO PLATO. "<<endl;
            if(cargar_plato(&cargado))
            {
                guardar_plato(&cargado);
                system("pause");
            }

        }
        break;
        case (2): //pide un ID y solo permite modificar el costo de venta y tiempo de preparacion.
        {
            system("cls");
            cout<<"MODIFICANDO COSTO DE VENTA Y TIEMPO DE PREPARACION. "<<endl;
            mod_platos();
        }
        break;
        case (3):
        {
            system("cls");
            cout<<"LISTANDO PLATO. "<<endl;
            mostrar_plato();
        }
        break;
        case (4):
        {
            system("cls");
            platos_por_restaurant();
        }
        break;
        case (5):
        {
            listar_todos_los_platos();
        }
        break;
        case (6):
        {
            if(baja_logica())
            {
                cout<<"El plato fue dado de baja con exito! "<<endl;
                system("pause");
            }
            else
            {
                cout<<"El plato No pudo darse de baja exitosamente. "<<endl;
                system("pause");
            }
        }
        break;
        case (0):
        {
            return;
        }
        break;
        default:
        {
            cout<<"Opcion incorrecta vuelva a intetarlo."<<endl;
            system("pause");
        }
        break;

        };

    }
}
void menuIII()
{
    struct clientes cliente_cargado;
    int op;
    while(true)
    {
        system("cls");
        cout<<"MENU DE CLIENTES. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1) NUEVO CLIENTE. "<<endl;
        cout<<"2) MODIFICAR CLIENTE. "<<endl;
        cout<<"3) LISTAR CLIENTE POR ID. "<<endl;
        cout<<"4) LISTAR TODOS LOS CLIENTES. "<<endl;
        cout<<"5) ELIMINAR CLIENTE. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL. "<<endl;
        cin>>op;
        switch(op)
        {
        case(1):
        {
            if(cargar_cliente(&cliente_cargado))
            {
                if(crea_archivo_cliente(&cliente_cargado))
                {
                    system("cls");
                    cout<<"cliente creado correctamente. "<<endl;
                    system("pause");
                }
                else
                {
                    system("cls");
                    cout<<"problema al cargar el cliente. revisar funcion ''crear_archivo_cliente'' "<<endl;
                    system("pause");
                }
            }
            else
            {
                system("cls");
                cout<<"el cliente no se cargo correctamente. datos no validos."<<endl;
                system("pause");
            }
        }
        break;
        case(2):
        {
            modificar_cliente();
        }
        break;
        case(3):
        {
            mostrar_cliente_por_id();
        }
        break;
        case(4):
        {
            //test();
            pide_memoria_dinamicamente();
        }
        break;
        case(5):
        {
            if(baja_logica_cliente()==true)
            {
                cout<<"Baja exitosa!"<<endl;
                system("pause");
            }
            else
            {
                cout<<"Baja Fallida!"<<endl;
                system("pause");
            }
        }
        break;
        case(0):
        {
            return;
        }
        break;
        default:
        {
            cout<<"Opcion incorrecta."<<endl;
        }
        break;
        };
    }
}

void menuIV()
{
        struct pedido pedido_cargado;
    int op;
    while(true)
    {
        system("cls");
        cout<<"MENU PEDIDOS. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1) NUEVO PEDIDO. "<<endl;
        cout<<"2) MODIFICAR PEDIDO. "<<endl;
        cout<<"3) LISTAR PEDIDO POR ID. "<<endl;
        cout<<"4) LISTAR TODOS LOS PEDIDOS. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL. "<<endl;
        cin>>op;
        switch(op)
        {
        case(1):
        {
            if(cargar_pedido(&pedido_cargado)==true)
            {
                if(nuevo_pedido(&pedido_cargado))
                {
                    cout<<"Pedido cargado con exito."<<endl;
                    system("pause");
                    mostrar_pedido(pedido_cargado);
                }else{cout<<"El pedido no se cargo con exito. " <<endl; system("pause");}
            }
        }
        break;
        case(2):
        {
            modificar_pedido();
        }
        break;
        case(3):
        {
            listar_pedido_x_id();
        }
        break;
        case(4):
        {
            todos_los_pedidos();
        }
        break;
        case(0):
        {
            return;
        }
        break;
        default:
        {
            cout<<"Opcion incorrecta."<<endl;
        }
        break;
        };
    }
}
void configuraciones()
{
    int op;
    while(true)
    {
        system("cls");
        cout<<"MENU PEDIDOS. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1) REALIZAR COPIA DE SEGURIDAD. "<<endl;
        cout<<"2) RESTAURAR COPIA DE SEGURIDAD. "<<endl;
        cout<<"3) MOSTRAR LO QUE HIZO EL PUNTO 1. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL. "<<endl;
        cin>>op;
        switch(op)
        {
        case(1):
        {
            realizar_copia_de_seguridad();
        }
        break;
        case(2):
        {
            cout<<"seguro que quiere restaurar lo ultimo guardado?. Podria perder informacion importante"<<endl;
            cout<<"Para si seleccione ''1''. para no ''2''"<<endl;
            int seguro;
            cin>>seguro;
            if(seguro==1)
            {
                restaurar_copia_de_seguridad();
            }else if(seguro==2 || seguro != 2)
            {
                cout<<"volvamos al menu principal entonces!"<<endl;
                system("pause");
                return;
            }
        }
        break;
       /*
        case(3):
        {
            //mostrar_copias();
        }
        break;*/
        case(0):
        {
            return;
        }
        break;
        default:
        {
            cout<<"Opcion incorrecta."<<endl;
            system("pause");
        }
        break;
        }
    }
}
#endif // FUNCIONES_LARA_H_INCLUDED
