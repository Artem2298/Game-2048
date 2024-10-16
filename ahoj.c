
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void vynuluj(int *pole,int len){
    for(int i =0; i<len; i++){
        pole [i] = 0;
        
    }
}

void nahodne (int *pole, int len, int sloupec, int radek){
    int nahx = rand() % sloupec;
    int nahy = rand() % radek;
    while (pole[nahx*sloupec+nahy] != 0){
        nahx = rand() % sloupec;
        nahy = rand() % radek;
    }
    int nahc = rand() % 10 +1;
    if (nahc <  10){
        pole[nahx*sloupec+nahy] = 2;
    }
    else {
        pole[nahx*sloupec+nahy] = 4;
    }
}

void tiskni(int *pole, int radek, int sloupec, int body){
    printf("\n%d\n\n", body);

    for(int i = 0; i < radek ; i++){
        for(int j =0; j<sloupec; j++){
            printf("%d", pole[i*sloupec+j]);
        }
        printf("\n");
    }
}

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


int moznytah(int *pole, int sloupec, int radek)
{
    int a = pole[0];

    //po radcich

    for (int i = 0; i < radek; i++)
    {
        for (int j = 1; j < sloupec; j++)
        {
            a = pole[i * sloupec + j - 1];
            if (a == pole[sloupec * i + j])
            {
                return 1;
            }
        }
    }

    // po sloupcich

    for (int j = 0; j < sloupec; j++)
    {
        int a = 0;
        for (int i = 1; i < radek; i++)
        {
            if (pole[a * sloupec + j] == pole[i * sloupec + j])
            {
                return 1;
            }
            a++;

        }
    }

    return 0;
}

int nula(int *pole, int len)
{
    for(int i = 0; i<len; i++){
        if(pole[i]==0){
            return 1;
        }
    }
    return 0;
}

int vyhraj(int *pole, int len){
    for (int i = 1; i<len; i++){
            //vitez
        if(pole[i] == 2048){
                return 1;
            }
    }
    
    return 0;
}

int main(){ 
    
    int sloupec = 0;
    int radek = 0;
    scanf(" %d", &sloupec);
    scanf(" %d", &radek);

    int len = sloupec*radek;
    int *pole = (int*)malloc(sizeof(int)*len);
    
    vynuluj (pole, len);
    nahodne (pole, len, sloupec, radek);
    nahodne (pole, len, sloupec, radek);

    int body = 0;

    tiskni(pole, radek, sloupec, body);

    //hra 
    int tah = 1;
    char pohyb;
    int jenula;
    int vyhra = 0;

    while(tah == 1){

        scanf(" %c", &pohyb); 
        jenula = nula(pole, len);
    

        switch (pohyb){
            case 'w':
                nahoru(pole, sloupec, radek, &body);
                if (jenula == 1){
                    nahodne(pole, len, sloupec, radek);
                }
                break;
            case 'a':
                levo(pole, sloupec, radek, &body);                
                if (jenula == 1){
                    nahodne(pole, len, sloupec, radek);
                }
                break;
            case 's':
                dolu(pole, sloupec, radek, &body);
                if (jenula == 1){
                    nahodne (pole, len, sloupec, radek);
                }
                break;
            case 'd':
                pravo(pole, sloupec, radek, &body);
                if (jenula == 1){
                    nahodne (pole, len, sloupec, radek);
                }
                break;    
        }
        
        if(jenula == 0){
            tah = moznytah(pole, sloupec, radek);
        }
        vyhra = vyhraj(pole, len);
        if(vyhra == 1){
            tah = 2;
        }
        tiskni(pole, radek, sloupec, body);
        
    }
    
    if (tah == 2){
        printf("gratulujeme");
    }
    else{
        printf("prohrali jste");
    }


    free(pole);
    pole = NULL;


    return 0;
}