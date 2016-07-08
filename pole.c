#include "pole.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//nove pole
POLE * pole_init(int avelikost, int aprirustek) {
    POLE * novepole = malloc(sizeof(POLE));
    novepole->velikost = avelikost;
    novepole->prirustek = aprirustek;
    novepole->index = 0;
    novepole->buffer = calloc(avelikost,sizeof(char));
    return novepole;
}

//copy construktor
POLE * pole_copy(POLE * co) {
    POLE * novepole = malloc(sizeof(POLE));
    novepole->velikost = co->velikost;
    novepole->prirustek = co->prirustek;
    novepole->index = co->index;
    novepole->buffer = malloc(co->velikost*sizeof(char));
    memcpy(novepole->buffer,co->buffer,co->velikost);
    return novepole;
}

//prepsani existujiciho pole novym
void pole_nastav(POLE * zdroj, POLE * cil) {
    free(cil->buffer);
    cil->velikost = zdroj->velikost;
    cil->prirustek = zdroj->prirustek;
    cil->index = zdroj->index;
    cil->buffer = malloc(zdroj->velikost*sizeof(char));
    memcpy(cil->buffer,zdroj->buffer,zdroj->velikost);
}


void pole_navysit(POLE * jake) {
    char*  novybuf = calloc((jake->velikost+jake->prirustek),sizeof(char));
    for(int i=0;i<jake->velikost;i++) {
            novybuf[i]=jake->buffer[i];
    }
    free(jake->buffer);
    jake->buffer = novybuf;
    jake->velikost+=jake->prirustek;

}


void pole_pridej(POLE * kam, char jaky) {

    //podminka ze uz nestaci pole
    if ( kam->velikost  ==  kam->index   ) {
        pole_navysit(kam);
    }
    kam->buffer[kam->index++]=jaky;
}

void pole_vlozPredPrvni(POLE * kam, int kolik) {
    if (kolik>0) {
        char * novybuf = calloc(kam->velikost+kolik,sizeof(char));
        memcpy(novybuf+kolik,kam->buffer,kam->index);
        free(kam->buffer);kam->buffer=novybuf;
        kam->index+=kolik;kam->velikost+=kolik;
    }
}


char * pole_dejUkNaZnak(POLE * jake, int index) {
    while (index>=jake->velikost) {
        pole_navysit(jake);
    }
    if (jake->index<=index) //aktualni pole rozsirim az k poskytnutemu ukazateli, aby se data uchovala
              jake->index=index+1;
    return jake->buffer+index;
}


void pole_tiskni(POLE * jakepole){

    for(int i=0;i<jakepole->index;i++) {
            printf("%c,",jakepole->buffer[i]);
    }
    printf("\n");

}

void pole_likviduj(POLE * jakepole){
    free(jakepole->buffer);
}
