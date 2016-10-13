#include <iostream>
using namespace std;
#include "Ventana.h"
#include "Conecta4.h"
#include <SDL.h>



int main(int argc,char* argv[]){
/*INICIALIZAR*/
    Conecta4 C4;
    /*COMENZAR Todo de SDL*/
    if (SDL_Init(SDL_INIT_EVERYTHING)<0){//-1 es error
        cout<<"ERROR-> "<<SDL_GetError()<<endl;
        return 1;
    }
    C4.crearVentana();
    C4.cicloJuego();
    SDL_Quit();//quitamos la aplicacion
    return 0;
}
