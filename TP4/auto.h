#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    char marca [20];
    char color [20];
    int anio;
    int precio;

} Auto;

#endif // AUTO_H_INCLUDED

Auto* auto_new();
Auto* new_AutoParam(int id, char* marca, char* color, int anio, int precio);
Auto* auto_newParametros(char* idStr,char* marcaStr,char* colorStr, char* anio, char* precio);
int mostrarAutosP(Auto* vec);

int listarAutos(LinkedList* pArrayListEmployee);
int cargarCsvAutos(char* path, LinkedList* pArrayListEmployee);
int guardarAutos(char* path, LinkedList* pArrayListEmployee);

int auto_setId(Auto* this,int id);
int auto_getId(Auto* this,int* id);

int auto_setMarca(Auto* this,char* marca);
int auto_getMarca(Auto* this,char* marca);
int auto_setColor(Auto* this,char* color);
int auto_getColor(Auto* this,char* color);

int auto_setAnio(Auto* this,int anio);
int auto_getAnio(Auto* this,int* anio);

int auto_setPrecio(Auto* this,int precio);
int auto_getPrecio(Auto* this,int* precio);

int altaAuto(LinkedList* pArrayListEmployee);
int modificarAuto(LinkedList* pArrayListEmployee);
int bajaAuto(LinkedList* pArrayListEmployee);
int ordenarAutos(LinkedList* pArrayListEmployee);
int comparaAutosAnio(void* a,void* b);
int comparaAutoPrecio(void* a,void* b);
int comparaAutoMarca(void* a,void* b);
