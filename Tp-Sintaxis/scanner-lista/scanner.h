#include <stdio.h>
#include <stdlib.h>
#include "automata.h"
#include "aux.h"
#include "tokens.h"
#include "listaTokensTS.h"

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
      agregar(&lista, token(letra), cadena);
    }
    else if (letra == ':') {
      char prox = getc(fp);
      if (prox == '=' && !feof(fp)) {
        agregar(&lista, ASIGNACION, ":=");
      } else if (feof(fp)) {
        break;
      } else {
        ungetc(prox, fp);
      }
    }
    else if(esCaracterDePuntuacion(letra)) {
      char cadena[2] = "_\0";
      cadena[0] = letra;
      agregar(&lista, token(letra), cadena);
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
        agregar(&lista, tokenCadena(buffer), buffer);
      } else if (esConstanteNumerica(buffer)) {
        agregar(&lista, CONSTANTE, buffer);
        agregarSimbolo(tabla, CONSTANTE, buffer);
      } else if (!feof(fp) && buffer[0] != '\0') {
        if (esIdentificador()) {
          agregar(&lista, ID, buffer);
          agregarSimbolo(tabla, ID, buffer);
        }
      }
      limpiarBuffer();
    }
  }
  agregar(&lista, FDT, "\0");

  fclose(fp);
  return 0; 
}
