typedef struct Reg_expresion {
  TOKEN token;
  char cadena[32];
  int constante;
} Reg_expresion;


TOKEN proximoToken();
void errorSintactico();
void match(TOKEN t);
void objetivo();
void programa();
void listaSentencias();
void sentencia(TOKEN t);
void listaIdentificadores();
void primaria(Reg_expresion * operando);
void listaExpresiones(void);
void expresion(Reg_expresion * resultado);
void operadorAditivo(TOKEN *op);