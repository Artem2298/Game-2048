
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include <unistd.h>
#include "ctverce.h"
#include "definice.h"
#include "pomocne.h"
#include "pohyby.h"

int main()
{
    
    if(SLOUPEC == 0 || RADA == 0){
        printf("spatne parametry");
        return 1;
    }

    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Event e;
    SDL_Window *window = SDL_CreateWindow("2048 - Šumšalová", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    TTF_Font * font = TTF_OpenFont("text.ttf", 50);
    TTF_Font * fontEnd = TTF_OpenFont("text.ttf", 120);

    int tah = 1;
    int pohyb = 0;
    int len = RADA * SLOUPEC;
    int body = 0;

    int *pole;
    pole = (int *) malloc(sizeof(int) * len);

    if (!pole){
        printf("dosla pamet\n");
        return 1;
    }
 
    
    vynuluj(pole, len);
    nahodne(pole, SLOUPEC, RADA);
    nahodne(pole, SLOUPEC, RADA);

    int beh = 1; 
    while (beh)
    {
        while (SDL_PollEvent(&e))
        {
            //uzavreni okna
            if (e.type == SDL_QUIT)
            {
                beh = 0;
            }
            
            if (e.type == SDL_KEYDOWN)
            {
                switch(e.key.keysym.sym) {
                    case SDLK_q: {
                        beh = 0;
                        break;
                    }

                    case SDLK_UP: {
                        nahoru(pole, SLOUPEC, RADA, &body);
                        pohyb = 1;
                        break;
                    }

                    case SDLK_LEFT: {
                        levo(pole, SLOUPEC, RADA, &body);
                        pohyb = 1;
                        break;
                    }

                    case SDLK_DOWN: {
                        dolu(pole, SLOUPEC, RADA, &body);
                        pohyb = 1;
                        break;
                    }

                    case SDLK_RIGHT: {
                        pravo(pole, SLOUPEC, RADA, &body);
                        pohyb = 1;
                        break;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 250, 240, 255); //barva pozadi
        SDL_RenderClear(renderer);
        
        pozadi(renderer); //to je ten cerny ctverec
        

        if (nula(pole, len))
        {
            if (moznytah(pole, SLOUPEC, RADA)) {
                tah = 1;

                if (pohyb) {
                    pohyb = 0;
                    nahodne(pole, SLOUPEC, RADA);
                }
            } else {
                tah = 0;
            }

            if (vyhraj(pole, len)) {
                tah = 2;
            }
        } else {
            if(moznytah(pole, SLOUPEC, RADA)){
                tah = 1;
            }
            else{
                tah = 0;
            }
        }

        SDL_Color barva;
        SDL_Rect okno;
        char text[100];
        int textSirka = 0;
        int textVyska = 0;

        // Vyhra
        if(tah == 2) {
            sprintf(text, "Vyhral jsi!");
            TTF_SizeText(font, text, &textSirka, &textVyska);

            barva.r = 128;  
            barva.g = 0;
            barva.b = 0;
            barva.a = 255;

            okno.x = (WINDOW_WIDTH/2)-(textSirka/2); //pozice x
            okno.y = 100; //pozice y
            okno.w = textSirka; //sirka obrazku
            okno.h = textVyska;  //vyska obrazku

            kreslitext(renderer, fontEnd, barva, okno, text);      
        } else if (tah == 0) {
            sprintf(text, "Prohral jsi!");
            TTF_SizeText(font, text, &textSirka, &textVyska);

            barva.r = 128;
            barva.g = 0;
            barva.b = 0;
            barva.a = 255;

            okno.x = (WINDOW_WIDTH/2)-(textSirka/2); //pozice x
            okno.y = 100; //pozice y
            okno.w = textSirka; //sirka obrazku
            okno.h = textVyska;  //vyska obrazku

            kreslitext(renderer, fontEnd, barva, okno, text);
        } else {
            sprintf(text, "SCORE: %d", body);
            TTF_SizeText(font, text, &textSirka, &textVyska);

            barva.r = 222;   
            barva.g = 184;   
            barva.b = 135; 
            barva.a = 255;

            okno.x = (WINDOW_WIDTH/2)-(textSirka/2); //pozice x
            okno.y = 100; //pozice y
            okno.w = textSirka; //sirka obrazku
            okno.h = textVyska;  //vyska obrazku

            kreslitext(renderer, font, barva, okno, text);
            ctverce_kresli(renderer, pole);
        }

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    TTF_CloseFont(fontEnd);
    TTF_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    free(pole);
    pole = NULL;
}