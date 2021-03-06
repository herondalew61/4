#ifndef VENTANA_H_INCLUDED
#define VENTANA_H_INCLUDED
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;

class Ventana{
    public:
        int tipo;
        bool turno;
        TTF_Font *letra = NULL;
        SDL_Window* window;
        SDL_Surface* pantalla; //variable para la ventana
        SDL_Surface* fondo; //variable para imagen
        SDL_Surface* tablero; //imagen tablero
        SDL_Surface* mano_r;
        SDL_Surface* mano_a;
        SDL_Surface* turno_mano;
        SDL_Event evento;//variable para detectar eventos

    public:
        bool accion();
        void inicializar();
        void aplicarSurface(int x,SDL_Surface* poner,
                            int y, SDL_Surface* destino);
        void actualizar();
        void cerrar();
        void setTurno(bool t);
        void cargarVentana(int t);
        bool cargarArchivos();


};

#endif // VENTANA_H_INCLUDED
