#ifndef GRANDINT_H_INCLUDED
#define GRANDINT_H_INCLUDED
#include "pole.h"

struct grandint_s { //struktura pro mozne budouci rozsireni
    POLE * data;
};

typedef struct grandint_s GRANDINT;

GRANDINT * grandint_init(char * inithodnota);
GRANDINT * grandint_copy(GRANDINT * co);
void grandint_nastav(GRANDINT * zdroj, GRANDINT * cil);//moc otrocke, stejne nastavim primo 'data'
void grandint_plus(GRANDINT * kam, int co);
void grandint_plusG(GRANDINT * kam, GRANDINT * co);
void grandint_krat(GRANDINT * kam, int cim);
void grandint_krat10NaN(GRANDINT * co, int n);
void grandint_kratG(GRANDINT * co, GRANDINT * cim);
int grandint_jePalindrom(GRANDINT * co);
void grandint_tiskni(GRANDINT * co);
void grandint_likviduj(GRANDINT * jake);


#endif // GRANDINT_H_INCLUDED
