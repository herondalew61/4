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
    // recorta la imagen
    //    posicion.h=300;
    //    posicion.w=300;
    if (poner==NULL){
        cout<<"error : "<<SDL_GetError()<<endl;
    }
    SDL_BlitSurface(poner,NULL,destino,&posicion);
}

void Ventana::cargarimagen(string archivo){



}

void Ventana::setTurno(bool t){
//TRUE ES TURNO AMARILLO
//FALSE ES TURNO ROJO
    turno=t;
    if (turno){
        pantalla=SDL_GetWindowSurface(window);
        SDL_SetColorKey (mano_a, SDL_TRUE, SDL_MapRGB(mano_a->format,255,255,255));
        aplicarSurface(505,mano_a,-8,pantalla);
        SDL_UpdateWindowSurface(window);
    }

}
void Ventana::ponerFondo(int tipo){
    if (tipo==1){
        /*colocamos fondo*/
        pantalla=SDL_GetWindowSurface(window);
        fondo=SDL_LoadBMP("recursos/fondo_papel.bmp");
        aplicarSurface(0,fondo,0,pantalla);

        /*colocamos tablero*/
        pantalla=SDL_GetWindowSurface(window);
        fondo=SDL_LoadBMP("recursos/tablero.bmp");
        if (imagen==NULL){
            cout<<"error : "<<SDL_GetError()<<endl;
        }
        SDL_SetColorKey (fondo, SDL_TRUE, SDL_MapRGB(fondo->format,255,255,255));
        aplicarSurface(450,fondo,81,pantalla);

        SDL_UpdateWindowSurface(window);pantalla=SDL_GetWindowSurface(window);
        fondo=SDL_LoadBMP("recursos/ficha_amarilla.bmp");
        if (imagen==NULL){
            cout<<"error : "<<SDL_GetError()<<endl;
        }
        SDL_SetColorKey (fondo, SDL_TRUE, SDL_MapRGB(fondo->format,255,255,255));
        aplicarSurface(483,fondo,111,pantalla);
        SDL_UpdateWindowSurface(window);
        //SDL_SetColorKey(1) parametro imagen,
        // 2) parametro Flag si deseamos o no transparencia color,
        // 3) formato y color de transparencia)
    }else if (tipo==2){

    }
}

bool Ventana::accion()
{
    while(SDL_PollEvent(&evento)){
        if (evento.type==SDL_QUIT){//cerrar ventana
                return false;//sale del GAME LOOP
                //SDL_UpdateWindowSurface(window);
        }else {
            switch(evento.key.keysym.sym){
            //Left arrow
            case SDLK_LEFT: //Moving sprite left
                break;
            //right arrow
            case SDLK_RIGHT: //Moving sprite right

                /*combinamos ambos surfaces*/

                //ponerFondo(1);
                //SDL_FillRect(pantalla,0,SDL_MapRGB(pantalla->format,254,255,255));
                //SDL_FillRect(mano_a,0,SDL_MapRGB(mano_a->format,0,0,0));
                //SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 0xFF, 0xFF, 0xFF));
                pantalla=SDL_GetWindowSurface(window);
                aplicarSurface(575,mano_a,-8,pantalla);
                //SDL_UpdateWindowSurface(window);
                break;
            }

        }
        //aplicar surface
        //llenando de informacion el buffer de video
        SDL_UpdateWindowSurface(window);
    }
    return true;
}

void Ventana::cerrar(){
    //DL_FreeSurface(imagen);
    SDL_FreeSurface(mano_r);
    SDL_FreeSurface(mano_a);
    SDL_FreeSurface(fondo);//para que no se quede en memori la imagen
    SDL_DestroyWindow(window);//destruimos punt
}

