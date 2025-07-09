#ifndef PARTICIPANTES_H_INCLUDED
#define PARTICIPANTES_H_INCLUDED
#include "Participante.h"

typedef struct nodoP { Participante participante;
                       nodoP* sig;
                     } nodoParticipante;
typedef nodoParticipante * ListaParticipante;

const int CantParticipantes = 4;
typedef ListaParticipante Participantes[CantParticipantes];

// Make:   Diccionario
// Crea un diccionario vacío.
void Make(Participantes &p);

// Member : Diccionario x K  Boolean
// Determina si en el diccionario existe un elemento con la clave especificada
boolean Member(Participantes p, int ced);

// Insert : Diccionario x T
// Diccionario Inserta un elemento de tipo T en el diccionario.
// Precondición: el elemento a insertar no es miembro del diccionario.
void Insert(Participantes &p, Participante part);

// Find : Diccionario x K  T
// Dada la clave de un elemento devuelve el elemento con dicha clave
// Precondición: el elemento es miembro del diccionario.
Participante Find(Participantes p, int ced);

// Modifiy : Diccionario x T
// Diccionario Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
// Precondición: el elemento a sustituir es miembro del diccionario
void Modify(Participantes &p, Participante part);

///despliega participantes por pantalla
void desplegarParticipantes(Participantes participante);

///determina para una fecha dada, cantidad de participantes que nacieron antes, durante y luego de la misma
void cantParticipantesSegunFecha(Participantes participantes,Fecha f1, int &cantIgual, int &cantMenor, int &cantMayor);

/// determina cantidad de encuentros ganados por jugador
void desplegarJugadoresGanadores(Participantes participantes);

// permite al usuario seleccionar una cedula por consola
void seleccionarParticipante(Participantes participantes, int &cedulaParticipante, boolean &deseaContinuar);

#endif // PARTICIPANTES_H_INCLUDED
