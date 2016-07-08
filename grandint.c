#include "pole.h"
#include "grandint.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

GRANDINT * grandint_init(char * inithodnota) {
    GRANDINT * cislo = malloc(sizeof(GRANDINT));
    int delka = strlen(inithodnota);
    cislo->data = pole_init(delka,10);
    for (int i=delka-1;i>=0;i--) {
        if ((inithodnota[i]>47)&&(inithodnota[i]<58)) //krome desitkove soustavy vse ignorovat
            pole_pridej(cislo->data,inithodnota[i] - 48);
    }
    return cislo;
}

GRANDINT * grandint_copy(GRANDINT * co) {
   GRANDINT * nove = malloc(sizeof(GRANDINT));
   nove->data = pole_copy(co->data);
   return nove;
}

int prictiCifru(char * kam, int jakou) {
    int pom = *kam + jakou;
    *kam=pom%10;
    return pom/10;
}

int vynasobCifrou(char * kam, int jakou, int prenos) {
    int pom = *kam * jakou+prenos;
    *kam=pom%10;
    return pom/10;
}

void grandint_plus(GRANDINT * kam, int co) {
    int pom;
    int dig, i=0;
    char * u;
    while (co>0) {
        pom = co/10;
        dig = co-pom*10;
        u=pole_dejUkNaZnak(kam->data,i++);
        co=pom+prictiCifru(u,dig);
    }
}

//nasobeni jednocifernym
void grandint_krat(GRANDINT * kam, int cim) {
    int pom=0;
    int  i=0;
    char * u;
     while ((i<kam->data->index)|| pom){

        u=pole_dejUkNaZnak(kam->data,i++);
        pom=vynasobCifrou(u,cim,pom);
    }
}

//nasobi 10^n, kde n je prirozene cislo
void grandint_krat10NaN(GRANDINT * co, int n) {
    pole_vlozPredPrvni(co->data,n);
}



void grandint_plusG(GRANDINT * kam, GRANDINT * co) {
    int pom=0; //co si pamatujeme do dalsiho souctu
    char * u1,*u2;
    int i;
    for(i=0;i<co->data->index;i++){
        u1=pole_dejUkNaZnak(kam->data,i);
        u2=pole_dejUkNaZnak(co->data,i);
        pom=prictiCifru(u1,*u2+pom);
    }
    while (pom) {
        u1=pole_dejUkNaZnak(kam->data,i++);
        pom=prictiCifru(u1,pom);
    }
}

void grandint_kratG(GRANDINT * co, GRANDINT * cim) {
    GRANDINT * zaloha= grandint_copy(co);
    GRANDINT * sum = grandint_init("0");
    char * u;
    for(int i=0;i<cim->data->index;i++){
        u=pole_dejUkNaZnak(cim->data,i);
        grandint_krat(zaloha,*u);
        grandint_krat10NaN(zaloha,i);//vynasobi 10^i
        grandint_plusG(sum,zaloha);
        pole_nastav(co->data,zaloha->data);
    }
    grandint_likviduj(co);co->data=sum->data;free(sum);
    grandint_likviduj(zaloha);free(zaloha);
}

int grandint_jePalindrom(GRANDINT * co) {
    if (co->data->index==0)
        return 0;
    if (co->data->index==1)
        return 1;

    char *u1 = co->data->buffer;
    char *u2 = co->data->buffer+co->data->index-1;
    while (u1<u2) {
        if (*u1++!=*u2--)
            return 0;
    }
    return 1;
}

void grandint_tiskni(GRANDINT * co) {
    char * b = co->data->buffer;
    for (int i=co->data->index-1;i>=0;i--) {
        printf("%c",b[i] + 48);
    }
}
void grandint_likviduj(GRANDINT * jake) {
    pole_likviduj(jake->data);
    free(jake->data);
}

