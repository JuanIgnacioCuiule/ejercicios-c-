#include "automata.c"
#include "aux.c"
#include "tokens.c"
#include "listaTokensTS.c"

Nodo* lista = NULL;
Simbolo tabla[100] = { {100,"\0"}  };

int scanner () {
  FILE *fp;
  fp = fopen("archivo.micro","r");
  while (!feof(fp)) {
    char letra = getc(fp);
    if (esOperadorAditivo(letra)) {
      char cadena[2] = "\0";
      cadena[0] = letra;
      agregar(&lista, token(letra), cadena, linea);
    }
    else if (letra == ':') {
      char prox = getc(fp);
      if (prox == '=' && !feof(fp)) {
        agregar(&lista, ASIGNACION, ":=", linea);
      } else if (feof(fp)) {
        break;
      } else {
        ungetc(prox, fp);
      }
    }
    else if(esCaracterDePuntuacion(letra)) {
      char cadena[2] = "_\0";
      cadena[0] = letra;
      agregar(&lista, token(letra), cadena, linea);
    }
    else {
      while (!feof(fp) && !esEspacio(letra)) {
        buffer[i] = letra;
        i++;
        letra = getc(fp);
        if (esCaracterDePuntuacion(letra) || esOperadorAditivo(letra)) {
          ungetc(letra, fp);
          break;
        }
      }
      if (esPalabraReservada()) {
        agregar(&lista, tokenCadena(buffer), buffer, linea);
        char prox = getc(fp);
        if (prox != '(') {
          linea++; 
        } else {
          ungetc(prox, fp);
        }
      } else if (esConstanteNumerica(buffer)) {
        agregar(&lista, CONSTANTE, buffer, linea);
        agregarSimbolo(tabla, CONSTANTE, buffer);
      } else if (!feof(fp) && buffer[0] != '\0') {
        if (esIdentificador()) {
          agregar(&lista, ID, buffer, linea);
          agregarSimbolo(tabla, ID, buffer);
        } else {
          agregar(&lista, ERRORLEXICO, buffer, linea);
          printf("Error lexico \"%s\" en linea %d\n", buffer, linea);
          exit(1);
        }
      }
      limpiarBuffer();
    }
  }
  agregar(&lista, FDT, "\0", linea);

  fclose(fp);
  return 0; 
}
