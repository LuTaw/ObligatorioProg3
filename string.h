#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"

const int MAX = 80;
typedef char * string;

void strcrear (string &s);
/// crea un string con memoria dinamica

void print (string s);
/// Imprime el string por pantalla ///

void scan (string &s);
/// Carga un string por pantalla ///

void strDestruir (string &s);
/// Libera la memoria dinamica asignada a string ///

int strlar (string s);
/// Devuelve el largo de un string ///

boolean strmen (string s1, string s2);
/// Recibe dos strings y devuelve TRUE si el primero es menor (en orden alfabetico) ///

boolean streq (string s1, string s2);
/// Compara dos strings y devuelve TRUE si son iguales ///

void strcop (string &s1,string s2);
/// Copia el segundo string en el primero ///

void strcon (string &s1, string s2);
/// Concatena el segundo string en el primero ///

void strswp (string &s1, string &s2);
/// Recibe dos strings y devuelve el primero en el segundo y el segundo en el primero ///


#endif // STRING_H_INCLUDED
