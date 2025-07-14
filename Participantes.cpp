#include "Participantes.h"

void crearLista(ListaParticipante &lista)
{
    lista = nullptr;
}

// Make:   Diccionario
// Crea un diccionario vacío.
void Make(Participantes &p)
{
    for (int i = 0; i < CantParticipantes; i++) {
        crearLista(p[i]);
    }
}

int funcionDispersion(int cedula)
{
    return cedula % CantParticipantes;
}

boolean perteneceLista(ListaParticipante lista, int cedula)
{
    boolean pertenece = FALSE;
    while(!pertenece && lista != nullptr) {
        if (darCedula(lista->participante) == cedula)
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

    return perteneceLista (p[cubeta], cedula);
}

void insfront(ListaParticipante &lista, Participante participante)
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
    int clave = darCedula(part);
    int cubeta = funcionDispersion(clave);

    insfront(p[cubeta], part);
}

Participante obtenerEnLista(ListaParticipante lista, int cedula)
{
    boolean encontro = FALSE;
    while(!encontro) {
        if(darCedula(lista->participante) == cedula)
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

    return obtenerEnLista(p[cubeta], cedula);
}

void modificarLista(ListaParticipante &lista, Participante part)
{
    boolean encontro = FALSE;
    ListaParticipante laux = lista;
    while(!encontro) {
        if(darCedula(laux->participante) == darCedula(part)) {
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
    int clave = darCedula(part);
    int cubeta = funcionDispersion(clave);

    modificarLista(p[cubeta], part);
}

void desplegarParticipantesEnLista(ListaParticipante lista)
{
    while(lista != NULL) {
        desplegarParticipante(lista->participante);
        lista = lista->sig;
    }
}

// despliega participantes por pantalla
void desplegarParticipantes(Participantes participantes)
{
    for (int i = 0; i < CantParticipantes; i++) {
        desplegarParticipantesEnLista(participantes[i]);
    }
}

void cantParticipantesSegunFechaEnLista(ListaParticipante lista, Fecha fecha, int &cantIgual, int &cantMenor, int &cantMayor)
{
    while(lista != NULL) {
        Fecha fechaParticipante = darFechaNacimiento(lista->participante);
        if(sonIguales(fechaParticipante, fecha))
            cantIgual++;
        else if (esAnterior(fechaParticipante, fecha))
            cantMenor++;
        else if (esPosterior(fechaParticipante, fecha))
            cantMayor++;

        lista = lista->sig;
    }
}

// determina para una fecha dada, cantidad de participantes que nacieron antes, durante y luego de la misma
void cantParticipantesSegunFecha(Participantes participantes, Fecha f1, int &cantIgual, int &cantMenor, int &cantMayor)
{
    cantIgual = 0;
    cantMenor = 0;
    cantMayor = 0;
    for (int i = 0; i < CantParticipantes; i++) {
        cantParticipantesSegunFechaEnLista(participantes[i], f1, cantIgual, cantMenor, cantMayor);
    }
}

// determina cantidad de encuentros ganados por jugador
void desplegarJugadoresGanadores(Participantes participantes)
{
    int maxGanadas = -1;

    // Primera pasada: para encontrar el máximo de partidas ganadas entre todos los participantes
    for (int i = 0; i < CantParticipantes; ++i) {
        ListaParticipante actual = participantes[i];
        while (actual != NULL) {
            if (darCantPartidasGanadas(actual->participante) > maxGanadas) {
                maxGanadas = darCantPartidasGanadas(actual->participante);
            }
            actual = actual->sig;
        }
    }

    // Segunda pasada: para mostrar a todos los jugadores que tienen ese máximo
    printf(" Ganador/es del torneo con %d partidas ganadas", maxGanadas);

    for (int i = 0; i < CantParticipantes; ++i) {
        ListaParticipante actual = participantes[i];
        while (actual != NULL) {
            if (darCantPartidasGanadas(actual->participante) == maxGanadas) {
                desplegarParticipante(actual->participante);
            }
            actual = actual->sig;
        }
    }
}

// permite al usuario seleccionar una cedula por consola
void seleccionarParticipante(Participantes participantes, int &cedulaParticipante, boolean &deseaContinuar)
{
    boolean selecciono = FALSE;
    int resultado, valorContinuar;
    while (!selecciono && deseaContinuar) {
        printf(" Ingrese la cedula de un participante: \n");
        scanf("%d", &cedulaParticipante);
        if (!Member(participantes, cedulaParticipante)) {
            printf(" La cedula no es correcta. \n\n");

            printf(" Desea continuar seleccionando participante? Ingrese 0 por No y 1 por Si. \n");
            resultado = scanf("%d", &valorContinuar);
            while(resultado != 1 || (valorContinuar != 0 && valorContinuar !=1)) {
                printf(" Entrada invalida. Ingrese 0 por No y 1 por Si. \n ");
                resultado = scanf("%d", &valorContinuar);
            }
            if (valorContinuar == 0)
                deseaContinuar = FALSE;
        } else {
            selecciono = TRUE;
        }
    }
}
