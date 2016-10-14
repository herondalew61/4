
#include "Conecta4.h"
using namespace std;

void Conecta4::inicializar()
{
    activo=true;
}

void Conecta4::cicloJuego()
{
     /*GAME LOOP*/
    turno=true;//amarillo
    do {
        v.setTurno(turno);
        //SDL_UpdateWindowSurface(v.window);
    }while(v.accion());
    v.cerrar();
}

void Conecta4::crearVentana(){
    /*inicialiar window con ventana de manera dinámica*/
    v.inicializar();
    if (v.window==NULL){//no se creo la ventana
        errorJuego("no se puede crear ventana");
    }
    /*SI SE CREO LA VENTANA*/
    v.cargarVentana(2);
//    v.ponerFondo(2);

}
void Conecta4::errorJuego(string error)
{
    cout<<error<<" : "<<SDL_GetError()<<endl;
    SDL_FreeSurface(v.fondo);//para que no se quede en memori la imagen
    SDL_DestroyWindow(v.window);//destruimos puntero
    SDL_Quit();//quitamos la aplicacion
    exit(0);
}

