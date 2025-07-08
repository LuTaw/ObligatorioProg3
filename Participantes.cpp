#include "Participantes.h"


void CrearLista(ListaParticipante &lista)
{
    lista = nullptr;
}

// Make:   Diccionario
// Crea un diccionario vacío.
void Make(Participantes &p)
{
    for (int i = 0; i < CantParticipantes; i++) {
        CrearLista(p[i]);
    }
}

int funcionDispersion(int cedula)
{
    return cedula % CantParticipantes;
}

boolean PerteneceLista(ListaParticipante lista, int cedula)
{
    boolean pertenece = FALSE;
    while(!pertenece && lista != nullptr) {
        if (DarCedula(lista->participante) == cedula)
            pertenece = TRUE;
        else
            lista = lista->sig;
    }

    return pertenece;
}

// Member : Diccionario x K  Boolean
// Determina si en el diccionario existe un elemento con la clave especificada
boolean Member(Participantes p, int cedula)
{
    int cubeta = funcionDispersion(cedula);

    return PerteneceLista (p[cubeta], cedula);
}

void Insfront(ListaParticipante &lista, Participante participante)
{
    nodoParticipante* nuevo = new nodoParticipante;
    nuevo->participante = participante;
    nuevo->sig = lista;
    lista = nuevo;
}

// Insert : Diccionario x T
// Diccionario Inserta un elemento de tipo T en el diccionario.
// Precondición: el elemento a insertar no es miembro del diccionario.
void Insert(Participantes &p, Participante part)
{
    int clave = DarCedula(part);
    int cubeta = funcionDispersion(clave);

    Insfront(p[cubeta], part);
}

Participante ObtenerEnLista(ListaParticipante lista, int cedula)
{
    boolean encontro = FALSE;
    while(!encontro) {
        if(DarCedula(lista->participante) == cedula)
            encontro = TRUE;
        else
            lista = lista->sig;
    }

    return lista->participante;
}

// Find : Diccionario x K  T
// Dada la clave de un elemento devuelve el elemento con dicha clave
// Precondición: el elemento es miembro del diccionario.
Participante Find(Participantes p, int cedula)
{
    int cubeta = funcionDispersion(cedula);

    return ObtenerEnLista(p[cubeta], cedula);
}

void ModificarLista(ListaParticipante &lista, Participante part)
{
    boolean encontro = FALSE;
    ListaParticipante laux = lista;
    while(!encontro) {
        if(DarCedula(laux->participante) == DarCedula(part)) {
            encontro = TRUE;
            laux->participante = part;
        } else {
            laux = laux->sig;
        }
    }
}

// Modifiy : Diccionario x T
// Diccionario Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
// Precondición: el elemento a sustituir es miembro del diccionario
void Modify(Participantes &p, Participante part)
{
    int clave = DarCedula(part);
    int cubeta = funcionDispersion(clave);

    ModificarLista(p[cubeta], part);
}

void DesplegarParticipantesEnLista(ListaParticipante lista)
{
    while(lista != nullptr) {
        desplegarParticipante(lista->participante);
        lista = lista->sig;
    }
}

///despliega participantes por pantalla
void desplegarParticipantes(Participantes participantes)
{
    for (int i = 0; i < CantParticipantes; i++) {
        DesplegarParticipantesEnLista(participantes[i]);
    }
}

void cantParticipantesSegunFechaEnLista(ListaParticipante lista, Fecha fecha, int &cantIgual, int &cantMenor, int &cantMayor)
{
    while(lista != nullptr) {
        Fecha fechaParticipante = DarFechaNacimiento(lista->participante);
        if(sonIguales(fechaParticipante, fecha))
            cantIgual++;
        else if (esAnterior(fechaParticipante, fecha))
            cantMenor++;
        else if (esPosterior(fechaParticipante, fecha))
            cantMayor++;

        lista = lista->sig;
    }
}

///determina para una fecha dada, cantidad de participantes que nacieron antes, durante y luego de la misma
void cantParticipantesSegunFecha(Participantes participantes, Fecha f1, int &cantIgual, int &cantMenor, int &cantMayor)
{
    for (int i = 0; i < CantParticipantes; i++) {
        cantParticipantesSegunFechaEnLista(participantes[i], f1, cantIgual, cantMenor, cantMayor);
    }
}

/// determina cantidad de encuentros ganados por jugador
void desplegarJugadoresGanadores(Participantes participantes)
{
    int maxGanadas = -1;

    // Primera pasada: para encontrar el máximo de partidas ganadas entre todos los participantes
    for (int i = 0; i < CantParticipantes; ++i) {
        ListaParticipante actual = participantes[i];
        while (actual != nullptr) {
            if (DarCantPartidasGanadas(actual->participante) > maxGanadas) {
                maxGanadas = DarCantPartidasGanadas(actual->participante);
            }
            actual = actual->sig;
        }
    }

    // Segunda pasada: para mostrar a todos los jugadores que tienen ese máximo
    printf("Ganador/es del torneo con %d partidas ganadas", maxGanadas);

    for (int i = 0; i < CantParticipantes; ++i) {
        ListaParticipante actual = participantes[i];
        while (actual != nullptr) {
            if (DarCantPartidasGanadas(actual->participante) == maxGanadas) {
                desplegarParticipante(actual->participante);
            }
            actual = actual->sig;
        }
    }
}

int seleccionarParticipante(Participantes participantes)
{
    boolean selecciono = FALSE;
    int cedulaParticipante;
    while (!selecciono) {
        printf("Ingrese la cedula de un participante: \n");
        scanf("%d", &cedulaParticipante);
        if (!Member(participantes, cedulaParticipante)) {
            printf("La cedula no es correcta. \n\n");
        } else {
            selecciono = TRUE;
        }
    }

    return cedulaParticipante;
}
