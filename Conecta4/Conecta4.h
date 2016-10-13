#ifndef CONECTA4_H_INCLUDED
#define CONECTA4_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include "Ventana.h"



class Conecta4{
    public:
        bool activo;
        bool turno;
        string j1;
        string j2;
        Ventana v;
        SDL_Event evento;//variable para detectar eventos
        SDL_Rect posicion;//variable para segundo null de blitsurface
    public:
        void inicializar();
        void cicloJuego();
        void crearVentana();
        void errorJuego(string error);
};

#endif // CONECTA4_H_INCLUDED
