int esPalabraReservada();
int esEspacio(char caracter);
int esOperadorAditivo(char caracter);
int esCaracterDePuntuacion(char caracter);
int esIdentificador();

typedef enum {
  INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, PARENDERECHO,
  PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERRORLEXICO
} TOKEN;

TOKEN token(char letra);
TOKEN tokenCadena(char cadena[]);
