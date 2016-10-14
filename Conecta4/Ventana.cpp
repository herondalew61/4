#include <iostream>
#include "Ventana.h"
using namespace std;

#define TITULO  "Conecta 4"
#define ARCHIVO "recursos/fondo_papel.bmp"
#define W 1250
#define H 700

void Ventana::inicializar()
{
    tipo=0;
    window = NULL;
    pantalla=NULL; //variable para la ventana
    fondo=NULL; //variable para imagen
    window=SDL_CreateWindow(
    TITULO,//const char* title
    SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,//posicion x y
    W,H,//ancho largo w h
    SDL_WINDOW_SHOWN);//Uint32      flags
    //SDL_CreateWindow(titulo,Pos x,pos y,ancho,alto,mostrar);
    fondo=SDL_LoadBMP("recursos/fondo_papel.bmp");
    tablero=SDL_LoadBMP("recursos/tablero.bmp");
    mano_a=SDL_LoadBMP("recursos/manita_a.bmp");
    mano_r=SDL_LoadBMP("recursos/manita_r.bmp");
}

void Ventana::aplicarSurface(int x,SDL_Surface* poner,
                             int y, SDL_Surface* destino){
    //rectangulo temporal para lo desplazamientos
    SDL_Rect posicion;//variable para segundo null de blitsurface
    //desde donde comienza a pintar
    posicion.x=x;
    posicion.y=y;
    if (poner==NULL){
        cout<<"error : "<<SDL_GetError()<<endl;
        cerrar();
    }
    //poner la imagen transparente
    //SDL_SetColorKey(1) parametro imagen,
    // 2) parametro Flag si deseamos o no transparencia color,
    // 3) formato y color de transparencia)
    SDL_SetColorKey (poner, SDL_TRUE, SDL_MapRGB(poner->format,255,255,255));
    SDL_BlitSurface(poner,NULL,destino,&posicion);
}

void Ventana::actualizar(){
    cargarVentana(tipo);
//    SDL_FillRect(fondo,&posicion, SDL_MapRGB(pantalla->format, 0xFF, 0xFF, 0xFF));

}

void Ventana::setTurno(bool t){
//TRUE ES TURNO AMARILLO
//FALSE ES TURNO ROJO
    turno=t;
    if (turno){
//        pantalla=SDL_GetWindowSurface(window);

//        aplicarSurface(505,mano_a,-8,pantalla);
//        SDL_UpdateWindowSurface(window);
    }

}

void Ventana::cargarVentana(int t){
        tipo=t;
        pantalla=SDL_GetWindowSurface(window);
        /*colocamos fondo*/
        aplicarSurface(0,fondo,0,pantalla);
    if (tipo==1){
        /*colocamos tablero*/
        aplicarSurface(450,tablero,81,pantalla);
//        SDL_UpdateWindowSurface(window);pantalla=SDL_GetWindowSurface(window);

//        SDL_SetColorKey (fondo, SDL_TRUE, SDL_MapRGB(fondo->format,255,255,255));
//        aplicarSurface(483,fondo,111,pantalla);
//        SDL_UpdateWindowSurface(window);

    }else if (tipo==2){

    }
}

bool Ventana::accion()
{
//TRUE ES TURNO AMARILLO
//FALSE ES TURNO ROJO
    if (turno){
        turno_mano=mano_a;
    }else{
        turno_mano=mano_r;
    }
    while(SDL_PollEvent(&evento)){
        switch(evento.type){//revision de eventos
            case SDL_QUIT:
                return false;//sale del GAME LOOP
                break;
                //SDL_UpdateWindowSurface(window);
            case SDL_MOUSEBUTTONDOWN: //Moving sprite right
                cout<<"x "<<evento.motion.x<<" y "<<evento.motion.y<<endl;
                if (turno){
                    setTurno(false);
                }else{
                    setTurno(true);
                }
                break;
            case SDL_MOUSEMOTION: //Moving sprite right
                if (tipo==1){
                    actualizar();
                    /*dibuja en el cursor una mano*/
                    //pos de la mano
                    aplicarSurface(evento.motion.x-22,turno_mano,evento.motion.y-72,pantalla);
                }
                break;
        }
        //aplicar surface
        //llenando de informacion el buffer de video
        SDL_UpdateWindowSurface(window);
    }
    return true;
}

void Ventana::cerrar(){
    //SDL_FreeSurface(ficha_a);
    //SDL_FreeSurface(ficha_r);
    SDL_FreeSurface(mano_r);
    SDL_FreeSurface(mano_a);
    SDL_FreeSurface(tablero);
    SDL_FreeSurface(fondo);//para que no se quede en memori la imagen
    SDL_DestroyWindow(window);//destruimos punt
}

