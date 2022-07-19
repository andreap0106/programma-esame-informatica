//
//  errori.c
//  Progetto esame informatica
//
//  Created by Andrea Panariello on 11/07/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "errori.h"


/* Tutte queste funzioni errore sono strutturate in modo tale, usando degli if/else, da testare tutti i casi e combinazioni di errore delle singole 
variabili tra di loro per poi restituirne uno specifico */
int funzione_errori_base_altezza(float altezza, float base)
{
    int  errore = NO_ERRORI;
    if (altezza <= 0)
    {
        printf("Altezza deve essere un valore positivo \nAltezza inserita: %f\n", altezza);
        errore = ERR_ALTEZZA;
    }
    if (base <= 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Basedeve essere un valore positivo \nBase inserita: %f\n", base);
            errore = ERR_BASE;
        }
        if (errore == ERR_ALTEZZA)
        {
            printf("Base deve essere un valore positivo \nBase inserita: %f\n", base);
            errore = ERR_BASE_ALTEZZA;
        }
    }
    return errore;
}




int funzione_errori_base_altezza_lati(float altezza, float base, float lato1, float lato2)
{
    int errore = NO_ERRORI;
    if (altezza <= 0)
    {
        printf("Altezza deve essere un valore positivo \nAltezza inserita: %f\n", altezza);
        errore = ERR_ALTEZZA;
    }
    if (base <= 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Base deve essere un valore positivo \nBase inserita: %f\n", base);
            errore = ERR_BASE;
        }
        if (errore == ERR_ALTEZZA)
        {
            printf("Base deve essere un valore positivo \nBase inserita: %f\n", base);
            errore = ERR_BASE_ALTEZZA;
        }
    }
    if (lato1 < 0 || lato2 < 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Lati devono essere un valore positivo \nLati inseriti: %f e %f\n",lato1, lato2);
            errore = ERR_LATI;
        }
        if (errore == ERR_ALTEZZA)
        {
            printf("Lati devono essere un valore positivo \nLati inseriti: %f e %f\n",lato1, lato2);
            errore = ERR_LATI_ALTEZZA;
        }
        if (errore == ERR_BASE)
        {
            printf("Lati devono essere un valore positivo \nLati inseriti: %f e %f\n", lato1, lato2);
            errore = ERR_LATI_BASE;
        }
        if (errore == ERR_BASE_ALTEZZA)
        {
            printf("Lati devono essere un valore positivo \nLati inseriti: %f e %f\n", lato1, lato2);
            errore = ERR_LATI_ALTEZZA_BASE;
        }
    }
    return errore;
}




int funzione_errori_cateti_ipotenusa(float cateto1, float cateto2, float ipotenusa)
{
    int errore = NO_ERRORI;
    if (cateto1 <= 0)
    {
        printf("Cateto 1 deve essere un valore positivo \nCateto inserito: %f\n", cateto1);
        errore = ERR_CATETO_1;
    }
    if (cateto2 <= 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Cateto 2 deve essere un valore positivo \nCateto inserito: %f\n", cateto2);
            errore = ERR_CATETO_2;
        }
        if (errore == ERR_CATETO_1)
        {
            printf("Cateto 2 deve essere un valore positivo \nCateto inserito: %f\n", cateto2);
            errore = ERR_CATETI;
        }
    }
    if (ipotenusa < 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Ipotenusa deve essere un valore positivo \nIpotenusa inserita: %f\n", ipotenusa);
            errore = ERR_IPOTENUSA;
        }
        if (errore == ERR_CATETO_1)
        {
            printf("Ipotenusa deve essere un valore positivo \nIpotenusa inserita: %f\n", ipotenusa);
            errore = ERR_CATETO1_IPOTENUSA;
        }
        if (errore == ERR_CATETO_2)
        {
            printf("Ipotenusa deve essere un valore positivo \nIpotenusa inserita: %f\n", ipotenusa);
            errore = ERR_CATETO2_IPOTENUSA;
        }
        if (errore == ERR_CATETI)
        {
            printf("Ipotenusa deve essere un valore positivo \nIpotenusa inserita: %f\n", ipotenusa);
            errore = ERR_CATETI_IPOTENUSA;
        }
    }
    return errore;
}




int funzione_errori_lato_altezza(float altezza, float lato)
{
    int  errore = NO_ERRORI;
    if (altezza <= 0)
    {
        printf("Altezza relativa al lato deve essere un valore positivo \nAltezza inserita: %f\n", altezza);
        errore = ERR_ALTEZZA;
    }
    if (lato <= 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Lato del rombo deve essere un valore positivo \nLato inserito: %f\n", lato);
            errore = ERR_LATO;
        }
        if (errore == ERR_ALTEZZA)
        {
            printf("Lato del rombo deve essere un valore positivo \nLato inserito: %f\n", lato);
            errore = ERR_LATO_ALTEZZA;
        }
    }
    return errore;
}
    
    


int funzione_errore_trapezio(float base_maggiore, float base_minore, float altezza)
{
    int errore = NO_ERRORI;
    if (altezza <= 0)
    {
        printf("Altezza deve essere un valore positivo \nAltezza inserita: %f\n", altezza);
        errore = ERR_ALTEZZA;
    }
    if (base_maggiore <= 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Base maggiore deve essere un valore positivo \nBase maggiore inserita: %f\n", base_maggiore);
            errore = ERR_BASE_MAGG;
        }
        if (errore == ERR_ALTEZZA)
        {
            printf("Base maggiore deve essere un valore positivo \nBase maggiore inserita: %f\n", base_maggiore);
            errore = ERR_BASE_MAGG_ALTEZZA;
        }
    }
    if (base_minore <= 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Base minore deve essere un valore positivo \nBase minore inserita: %f\n", base_minore);
            errore = ERR_BASE_MIN;
        }
        if (errore == ERR_ALTEZZA)
        {
            printf("Base minore deve essere un valore positivo \nBase minore inserita: %f\n", base_minore);
            errore = ERR_BASE_MIN_ALTEZZA;  //snake case
        }
        if (errore == ERR_BASE_MAGG)
        {
            printf("Base minore deve essere un valore positivo \nBase maggiore inserita: %f\n", base_minore);
            errore = ERR_BASE_MAGG_MIN;
        }
        if (errore == ERR_BASE_MAGG_ALTEZZA)
        {
            printf("Base minore deve essere un valore positivo \nBase maggiore inserita: %f\n", base_minore);
            errore = ERR_BASE_MAGG_MIN_ALTEZZA;
        }
    }
    return errore;
}




int funzione_errori_diagonali (float diagonale_maggiore, float diagonale_minore)
{
    int errore = NO_ERRORI;
    if (diagonale_maggiore <= 0)
    {
        printf("Diagonale maggiore deve essere un valore positivo \nDiagonale maggiore inserita: %f\n", diagonale_maggiore);
        errore = ERR_DIAG_MAGG;
    }
    if (diagonale_minore <= 0)
    {
        if (errore == NO_ERRORI)
        {
            printf("Diagonale minore deve essere un valore positivo \nDiagonale minore inserita: %f\n", diagonale_minore);
            errore = ERR_DIAG_MIN;
        }
        else
        {
            printf("Diagonale minore deve essere un valore positivo \nDiagonale minore inserita: %f\n", diagonale_minore);
            errore = ERR_DIAG_MAGG_MIN;
        }
    }
    return errore;
}
