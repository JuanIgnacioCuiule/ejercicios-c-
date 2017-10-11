typedef struct Nodo {
  struct Nodo* ant;
  TOKEN token;
  char cadena[33];
  struct Nodo* sig; 
} Nodo;

typedef struct Simbolo {
  TOKEN token;
  char cadena[33];
} Simbolo;

void agregar(Nodo** cola, TOKEN token, char cadena[]);
void agregarSimbolo(Simbolo tabla[], TOKEN token, char cadena[]);
void mostrar(Nodo* lista);
void mostrarTabla(Simbolo tabla[]);