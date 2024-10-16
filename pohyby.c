#include "pohyby.h"

void levo (int *pole, int sloupec, int radek, int* body){

    int pomocr, pomocs;

    for (int i = 0; i < radek ; i++){
        pomocs = 0;
        pomocr = i * sloupec;
        for (int j= 1; j<sloupec; j++){
            if(pole[i*sloupec +j] != 0){
                if(pole[i*sloupec + (j -1)] == 0 || pole[pomocr + j -1]== pole[pomocr+j]){
                    if(pole[pomocr+pomocs]==pole[pomocr+j]){
                        pole[pomocr+pomocs] = pole[pomocr+pomocs] *2;
                        pole[pomocr+j]=0;
                        *body += pole[pomocr+pomocs];
                    }
                    else{
                        if(pole[pomocr+pomocs]==0){
                            pole[pomocr+pomocs] = pole[pomocr +j];
                            pole[pomocr+j]=0;
                        }
                        else{

                            pole[pomocr+(++pomocs)] = pole[pomocr +j];
                            pole[pomocr+j]=0;
                        }
                    }
                }
                else pomocs++ ;
            }
        }
    }
}



void pravo (int *pole, int sloupec, int radek, int* body){

    int pomocr, pomocs;

    for (int i = 0; i < radek ; i++){
        pomocs = sloupec-1;
        pomocr = i * sloupec;
        for (int j= sloupec-2; j>=0; j--){
            if(pole[pomocr + j] != 0){
                if(pole[pomocr + j +1] == 0 || pole[pomocr + j +1]== pole[pomocr+j]){
                    if(pole[pomocr+pomocs]==pole[pomocr+j]){
                        pole[pomocr+pomocs] = pole[pomocr+pomocs] * 2;
                        pole[pomocr+j] = 0;
                        *body += pole[pomocr+pomocs];
                    }
                    else{
                        if(pole[pomocr+pomocs]==0){
                            pole[pomocr+pomocs] = pole[pomocr +j];
                            pole[pomocr+j] = 0;
                        }
                        else{
                            pomocs = pomocs -1;
                            pole[pomocr+pomocs] = pole[pomocr +j];
                            pole[pomocr+j]=0;
                        }
                    }
                }
                else pomocs = pomocs -1;
            }
        }
    }

}

void nahoru (int *pole, int sloupec, int radek, int* body){

    for (int j = 0; j < sloupec ; j++){
        int a = 0;
        for (int i= 1; i<radek; i++){
            if(pole[i*sloupec +j] != 0){
                if(pole[i*sloupec-sloupec + j ] == 0 || pole[i*sloupec-sloupec + j ]== pole[i*sloupec +j]){
                    if(pole[a*sloupec+j]==pole[i*sloupec +j]){
                        pole[a*sloupec+j] = pole[a*sloupec+j] *2;
                        pole[i*sloupec +j] = 0;
                        *body += pole[a*sloupec+j];
                    }
                    else{
                        if(pole[a*sloupec+j]==0){
                            pole[a*sloupec+j] = pole[i*sloupec +j];
                            pole[i*sloupec +j] = 0;
                        }
                        else{
                            pole[(++a)*sloupec+j] = pole[i*sloupec +j];
                            pole[i*sloupec +j]=0;
                        }
                    }
                }
                else a++;
            }
        }
    }

}

void dolu (int *pole, int sloupec, int radek, int *body){

    for (int j = 0; j < sloupec ; j++){
        int a = radek-1;
        for (int i= radek-2; i>=0; i--){
            if(pole[i*sloupec +j] != 0){
                if(pole[(i+1)*sloupec + j ] == 0 || pole[(i+1)*sloupec + j ]== pole[i*sloupec +j]){
                    if(pole[a*sloupec+j]==pole[i*sloupec +j]){
                        pole[a*sloupec+j] = pole[a*sloupec+j] *2;
                        pole[i*sloupec +j] = 0;
                        *body += pole[a*sloupec+j];
                    }
                    else{
                        if(pole[a*sloupec+j]==0){
                            pole[a*sloupec+j] = pole[i*sloupec +j];
                            pole[i*sloupec +j] = 0;
                        }
                        else{
                            pole[(--a)*sloupec+j] = pole[i*sloupec +j];
                            pole[i*sloupec +j]=0;
                        }
                    }
                }
                else a--;
            }
        }
    }

}