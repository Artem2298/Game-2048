#include "ctverce.h"

void ctverce_kresli (SDL_Renderer *renderer, int* pole){
    SDL_Texture * texture;

    int a = 0;

    if(SLOUPEC>=RADA){
        a = (HRACI_POLE - ((SLOUPEC - 1)*5)) / SLOUPEC ;

    }
    else if(SLOUPEC<RADA){
        a = (HRACI_POLE - ((RADA - 1)*5)) / RADA ;
    }

    int zacatek = 0 ;
    int zacatek_y = 0 ;

    int posun = a + 5;

   
    zacatek = (WINDOW_WIDTH - (SLOUPEC * a + (RADA-1)*5)) / 2 ;
    zacatek_y = ((WINDOW_HEIGHT - (RADA*a +(SLOUPEC-1)*5 ) ) / 2 ) + 100 ;
    
    
   

    SDL_Rect ctverec;
    ctverec.x = zacatek; //pozice x
    ctverec.y = zacatek_y; //pozice y
    ctverec.w = a; //sirka obrazku
    ctverec.h = a; //vyska obrazku
    

    
    for(int i = 0; i < RADA; i++){
        for(int j = 0; j < SLOUPEC; j++ ){
            if(pole[i*SLOUPEC+j]==0){
                texture = IMG_LoadTexture(renderer, "0.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 2){
                texture = IMG_LoadTexture(renderer, "2.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 4){
                texture = IMG_LoadTexture(renderer, "4.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 8){
                texture = IMG_LoadTexture(renderer, "8.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 16){
                texture = IMG_LoadTexture(renderer, "16.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 32){
                texture = IMG_LoadTexture(renderer, "32.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 64){
                texture = IMG_LoadTexture(renderer, "64.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 128){
                texture = IMG_LoadTexture(renderer, "128.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 256){
                texture = IMG_LoadTexture(renderer, "256.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 512){
                texture = IMG_LoadTexture(renderer, "512.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 1024){
                texture = IMG_LoadTexture(renderer, "1024.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            else if(pole[i*SLOUPEC + j] == 2048){
                texture = IMG_LoadTexture(renderer, "2048.png");
                SDL_RenderCopyEx(renderer, texture, NULL, &ctverec, 0, NULL, 0);
            }
            ctverec.x += posun;
        }
        ctverec.y += posun;
        ctverec.x = zacatek;
    }
    SDL_DestroyTexture(texture);
}

void pozadi(SDL_Renderer *renderer){

    int a = 0;

    if(SLOUPEC>=RADA){
        a = (HRACI_POLE - ((SLOUPEC - 1)*5)) / SLOUPEC ;

    }
    else if(SLOUPEC<RADA){
        a = (HRACI_POLE - ((RADA - 1)*5)) / RADA ;
    }

    int zacatek = 0 ;
    int zacatek_y = 0 ;

   
    zacatek = (WINDOW_WIDTH - (SLOUPEC * a + (RADA-1)*5)) / 2 ;
    zacatek_y = ((WINDOW_HEIGHT - (RADA*a +(SLOUPEC-1)*5 ) ) / 2 ) + 100 ;
    

    SDL_Rect ctverec;
    ctverec.x = zacatek -10; //pozice x
    ctverec.y = zacatek_y-10; //pozice y
    ctverec.w = (SLOUPEC * a + (SLOUPEC+1)*5)+10; //sirka obrazku
    ctverec.h = (RADA * a + (RADA+1)*5)+10; //vyska obrazku

    
    
    SDL_SetRenderDrawColor(renderer, 222, 184, 135, 255); //barva ctverce
    SDL_RenderFillRect(renderer, &ctverec);
}