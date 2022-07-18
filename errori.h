//
//  errori.h
//  Progetto esame informatica
//
//  Created by Andrea Panariello on 11/07/22.
//
#ifndef errori_h
#define errori_h

//definisco le costanti errore:
#define NO_ERRORI                   0
#define ERR_GENERICO               -1
#define ERR_ALTEZZA                -2
#define ERR_BASE                   -3
#define ERR_BASE_ALTEZZA           -4
#define ERR_BASE_MAGG              -5
#define ERR_BASE_MIN               -6
#define ERR_BASE_MIN_ALTEZZA       -7
#define ERR_BASE_MAGG_ALTEZZA      -8
#define ERR_BASE_MAGG_MIN          -9
#define ERR_BASE_MAGG_MIN_ALTEZZA  -10
#define ERR_DIAG_MAGG              -11
#define ERR_DIAG_MIN               -12
#define ERR_DIAG_MAGG_MIN          -13
#define ERR_CATETO_1               -14
#define ERR_CATETO_2               -15
#define ERR_CATETI                 -16
#define ERR_IPOTENUSA              -17
#define ERR_CATETO1_IPOTENUSA      -18
#define ERR_CATETO2_IPOTENUSA      -19
#define ERR_CATETI_IPOTENUSA       -20
#define ERR_LATO                   -21
#define ERR_LATO_ALTEZZA           -22
#define ERR_LATI                   -23
#define ERR_LATI_ALTEZZA           -24
#define ERR_LATI_BASE              -25
#define ERR_LATI_ALTEZZA_BASE      -26
#define ERR_RAGGIO                 -27


int funzione_errori_base_altezza(float altezza, float base);
int funzione_errori_base_altezza_lati(float altezza, float base, float lato1, float lato2);
int funzione_errori_cateti_ipotenusa(float cateto1, float cateto2, float ipotenusa);
int funzione_errore_trapezio(float base_maggiore, float base_minore, float altezza);
int funzione_errori_lato_altezza(float altezza, float lato);
int funzione_errori_diagonali (float diagonale_maggiore, float diagonale_minore);

#endif /* errori_h */
