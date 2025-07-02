#ifndef ENCUENTRO_H_INCLUDED
#define ENCUENTRO_H_INCLUDED

typedef struct { int nroEncuentro;
                 int cedulaParticipante1;
                 int cedulaParticipante2;
                 int cedulaGanador;
               } Encuentro;

///da el numero de encuentro
int DarNroEncuentro(Encuentro encuentro);

//obtener cedula participante 1
int DarCedulaParticipante1(Encuentro encuentro);

//obtener cedula participante 1
int DarCedulaParticipante2(Encuentro encuentro);

//obtener cedula participante ganador
int DarCedulaGanador(Encuentro encuentro);

///crea un encuentro
void crearEncuentro(Encuentro &encuentro);

///despliega por pantalla los datos del encuentro
void desplegarEncuentro(Encuentro encuentro);


#endif // ENCUENTRO_H_INCLUDED
