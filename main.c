#include <stdio.h>
#include <stdlib.h>
#include "pole.h"
#include "grandint.h"
#include <time.h>

#define DELKAVSTUPU 80
int main()
{
        char vstup[DELKAVSTUPU];
        time_t cas1=time(NULL),cas2=time(NULL);
        int i=1;

        puts("Tak od jake hodnoty mam zacit? (beru v uvahu jen prvnich 80 cifer ;-)");
        fgets(vstup,DELKAVSTUPU,stdin);

        GRANDINT * c = grandint_init(vstup);
        GRANDINT * d = grandint_copy(c);
        //int j=1;
        //grandint_plus(c,1);
        //grandint_plus(d,1);
        //grandint_kratG(c,c);

        //for(int i=0;i<10000;i++) {
        while(i++) {
            if (i>100000000) {
                puts("jsem u >> ");
                grandint_tiskni(c);puts("");i=1;
            }
            grandint_kratG(d,d);
            if(grandint_jePalindrom(d)) {
                cas2=time(NULL);
                printf("----\nCas:%i. Druha mocnina cisla:",cas1);
                cas1=cas2;
                grandint_tiskni(c);
                puts("\n... je palindrom:");
                grandint_tiskni(d);
                puts("\n----\n");
            }
            grandint_plus(c,1); //navysime o jednicku
            pole_nastav(c->data,d->data); //do decka nastav navysene cecko
        }

        grandint_likviduj(c);
        grandint_likviduj(d);
        free(c);free(d);


    /*
    GRANDINT * c2 = grandint_init("4");
    GRANDINT *c3 = grandint_copy(c);

    grandint_tiskni(c);
    puts("");
    //grandint_krat(c,9);
    grandint_kratG(c,c2);
    //grandint_tiskni(c);
    //grandint_krat10NaN(c,4);
    puts("");
    grandint_tiskni(c);



    pole_t * moje = pole_init(10,10);
    pole_pridej(moje,'1');
    pole_pridej(moje,'2');
    pole_pridej(moje,'3');
    pole_pridej(moje,67);
    pole_tiskni(moje);
    pole_likviduj(moje);
    free(moje);
    */

    return 0;
    }
