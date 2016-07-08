#ifndef POLE_H_INCLUDED
#define POLE_H_INCLUDED

struct pole_s {
	char* buffer;
	int index;
	int velikost;
	int prirustek;
};

typedef struct pole_s POLE;

POLE * pole_init(int avelikost, int aprirustek);
POLE * pole_copy(POLE * co);
void pole_nastav(POLE * zdroj, POLE * cil);
void pole_pridej(POLE * kam, char jaky);
void pole_vlozPredPrvni(POLE * kam, int kolik);//vlozi pred prvni prvek 'kolik' vynulovanych mist
void pole_tiskni(POLE * jakepole);
void pole_likviduj(POLE * jakepole);
char * pole_dejUkNaZnak(POLE * jake, int index);

#endif // POLE_H_INCLUDED
