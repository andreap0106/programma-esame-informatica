//
//  main.c
//  Progetto esame informatica => calcolatore area/perimetro figure piane
//
//  Created by Andrea Panariello on 08/06/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "errori.h"
#include "perimetro_area.h"

#define MAX_DIM         20

int main()
{
//dichiarazione variabili che verranno usate per calcolare area e perimetro delle figure
    /* sono state dichiarate tutte all'inizio del main (e non in prossimità delle funzioni delle rispettive figure) poiché alcune variabili 
    sono usate da più funzioni */
    float base;
    float altezza;
    float lato_1;
    float lato_2;
    float cateto_1;
    float cateto_2;
    float ipotenusa;
    float base_maggiore;
    float base_minore;
    float diagonale_maggiore;
    float diagonale_minore;
    float lato_rombo;
    float altezza_relativa;
    float lato_quadrato;
    float raggio;
    float diametro;
    const float pi = 3.141592;
//dichiarazione e inizializzazione errore generico ed errori specifici per singole figure
    /* sono stati dichiarati un errore generico e un altro come caratteristica della struct in modo tale da restiuire quello generico nel caso di calcolo 
     di piu figure (n>1 nel ciclo for) mentre nel caso di calcolo di figura singola (n=1 nel ciclo for) viene restituito un errore specifico secondo i 
     codici definiti in "errori.h". Tutto ciò per ovviare al problema che nel ciclo for veniva restituitito alla fine l'errore dell'ultima figura soltanto 
     andando a trascurare le altre (restituendo quindi un NO_ERROR anche se c'era un errore precedente nel ciclo */
    int errore = NO_ERRORI;
    
    /* l'errore definito nella struct, essendo una caratteristica della struct FigurePiane definita come array, permette di ovviare al problema 
       della sovrascrittura degli stessi quando si sceglievano due o più figure uguali: l'errore dell'ultima calcolata sovrascriveva quello delle 
       precedenti portando talvolta a ritornare 0 (NO_ERRORI) quando in realtà le figure precedenti riportavano effettivamente degli errori.
       Con l'array[MAX_DIM] si riserva un posto iesimo [i] all'errore per ciascuna figura anche se dello stesso tipo */

//definizione degli array delle struct
    /* è stato definito un array di questa struct per stipare, ad ogni iterazione del ciclo for, la figura con tutte le sue caratteristiche 
    (definite dalla struct) all'iesimo posto dell'array per un totale di 20(MAX_DIM) */
    caratteristiche_figure_piane FigurePiane [MAX_DIM] = {0};
    /* array delle struct di 4 parametri generci che a seconda della figura in cui vengono richiamati assumono nomi e valori specifici.
     Es. nel rettangolo: parametro_1[i].nome_parametro = "Base", parametro_2[i].nome_parametro = "Altezza".
     La modalità di array permette ancora questa volta di associare, ad ogni iterazione del ciclo for, le caratteristiche dettate dalla struct 
     all'iesimo posto dell'array */
    parametro_calcolo_area_perimetro parametro_1 [MAX_DIM];
    parametro_calcolo_area_perimetro parametro_2 [MAX_DIM];
    parametro_calcolo_area_perimetro parametro_3 [MAX_DIM];
    parametro_calcolo_area_perimetro parametro_4 [MAX_DIM];
    
    int n,i;    //dichiarate qui in alto per poter essere utilizzate anche fuori dal ciclo do/while successivamente
    unsigned int continuare_si_no;    //utilizzata da questo grande ciclo do/while per permettere di ripetere il codice o terminarlo
    do
    {
        do
        {
        printf("Di quante figure vuoi calcolare e stampare area e perimetro (MAX 30)?\n");
        scanf("%d",&n);
        } while (n > 20);
        for(i = 0; i < n; i++)
        {
            unsigned int scelta_figura_geometrica;
            do
            {
                printf("Di quale figura vuoi calcolare area e perimetro?\n");
                printf("1: Rettangolo\n2: Triangolo\n3: Trapezio\n4: Rombo\n5: Quadrato\n6: Cerchio\n7: Poligoni regolari\n");
                scanf("%d", &scelta_figura_geometrica);
                if (scelta_figura_geometrica < 0 || scelta_figura_geometrica > 7)
                {
                    printf("INSERIRE UN VALORE DELLA LISTA\n");
                }
            } while (scelta_figura_geometrica < 1 || scelta_figura_geometrica > 7);
            const unsigned int RETTANGOLO = 1;
            const unsigned int TRIANGOLO = 2;
            const unsigned int TRAPEZIO = 3;
            const unsigned int ROMBO = 4;
            const unsigned int QUADRATO = 5;
            const unsigned int CERCHIO = 6;
            const unsigned int POLIGONI_REGOLARI = 7;
            const unsigned int TERMINA = 0;
            //inserendo 0 durante la selezione della figura verranno interrotti gli inserimenti successivi e stampati solo i precedenti
            if (scelta_figura_geometrica == TERMINA)
            {
                break;
            }
    
            
            if (scelta_figura_geometrica == RETTANGOLO)
            {
                FigurePiane[i].nome_figura = "RETTANGOLO";  //l'iesima figura calcolata avrà nome rettangolo nella stampa finale
                printf("Inserisci base\n");
                scanf("%f", &base);
                printf("Inserisci altezza\n");
                scanf("%f", &altezza);
                //in questo caso ci sono solo due parametri; gli altri due verranno stampati come (NULL) = 0
                //sono stati scelti 4 parametri poiché il max usato da una funzione è proprio di 4 (vd. blocco codice calcolo areea/perimetro triangolo)
                parametro_1[i].nome_parametro = "Base";
                parametro_1[i].valore = base;
                parametro_2[i].nome_parametro = "Altezza";
                parametro_2[i].valore = altezza;
                parametro_3[i].nome_parametro = "(NULL)";
                parametro_3[i].valore = 0;
                parametro_4[i].nome_parametro = "(NULL)";
                parametro_4[i].valore = 0;
                FigurePiane[i].valore_errore = funzione_errori_base_altezza(altezza, base);
                /* qui come nelle funzioni delle altre figure sono stati definiti due volte con lo stesso valore due tipologie di errore: quello 
                generico "errore" e quello specifico relativo alla figura presa in esame dalla funzione "errore_rettangolo" */
                errore = FigurePiane[i].valore_errore;
                if (errore == NO_ERRORI)
                {
                    FigurePiane[i].stato_errore = "Nessun Errore";
                    FigurePiane[i].area = base * altezza;
                    FigurePiane[i].perimetro = (2*base) + (2*altezza);
                }
                else
                {
                    /* in questo caso è stato inserito un else nel caso in cui le funzioni errore (dichiarate e definite nell'"errori.h" e "errori.c") 
                    restituiscano qualcosa di diverso da NO_ERRORI.
                    A questo punto area e perimetro della figura assumeranno i valori del codice errore corrispondente all'errore che si è verificato */
                    FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                    FigurePiane[i].area = errore;
                    FigurePiane[i].perimetro = errore;
                }
            }
/* L'APPROCCIO E TUTTE LE CONSIDERAZIONE APPENA FATTE PER QUESTO BLOCCO DI CODICE CHE PRENDE IN ESAME IL RETTANGOLO SONO STATE ADOTTATE, 
            E QUINDI SONO DA RITENERSI VALIDE, ANCHE PER TUTTE LE ALTRE FIGURE DEL PROGRAMMA */
            
            
        //figure come triangolo e rombo hanno due modalità diverse di calcolo area/perimetro utilizzando diverse variabili
            unsigned int scelta_area_triangolo;
            const int area_base_altezza = 1;
            const int area_cateti = 2;
            if (scelta_figura_geometrica == TRIANGOLO)
            {
                FigurePiane[i].nome_figura = "TRIANGOLO";
                do
                {
                printf("In che modo vuoi calcolare l'area?\n");
                printf("1: Con base e altezza\n2: Con i cateti\n");
                scanf("%d", &scelta_area_triangolo);
                } while (scelta_area_triangolo != 1 && scelta_area_triangolo != 2);
                if (scelta_area_triangolo == area_base_altezza )
                {
                    printf("Inserisci base\n");
                    scanf("%f", &base);
                    printf("Inserisci altezza\n");
                    scanf("%f", &altezza);
                    printf("Se si vuole calcolare anche il perimetro inseririre gli altri due lati altrimenti inserire 0. \nSe uguali inserirli due volte\n");
                    scanf("%f", &lato_1);
                    printf("Inserisci l'altro (o nuovamente 0 se NON si vuole calcolare il perimetro)\n");
                    scanf("%f", &lato_2);
                    parametro_1[i].nome_parametro = "Base";
                    parametro_1[i].valore = base;
                    parametro_2[i].nome_parametro = "Altezza";
                    parametro_2[i].valore = altezza;
                    parametro_3[i].nome_parametro = "lato 1";
                    parametro_3[i].valore = lato_1;
                    parametro_4[i].nome_parametro = "Lato 2";
                    parametro_4[i].valore = lato_2;
                    FigurePiane[i].valore_errore = funzione_errori_base_altezza_lati(altezza, base, lato_1, lato_2);
                    errore = FigurePiane[i].valore_errore;
                    if (errore] == NO_ERRORI)
                    {
                        FigurePiane[i].stato_errore = "Nessun Errore";
                        FigurePiane[i].area = (base * altezza)/2;
                        if ((lato_1 > 0) && (lato_2 > 0))
                        {
                            FigurePiane[i].perimetro = base + altezza + lato_1 + lato_2;
                        }
                        else
                        {
                            FigurePiane[i].perimetro = 0;
                        }
                    }
                    else
                    {
                        FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                        FigurePiane[i].area = errore;
                        FigurePiane[i].perimetro = errore;
                    }
                }
                if (scelta_area_triangolo == area_cateti)
                {
                    printf("Inserisci cateto 1\n");
                    scanf("%f", &cateto_1);
                    printf("Inserisci cateto 2\n");
                    scanf("%f", &cateto_2);
                    printf("Se si vuole calcolare anche il perimetro inseririre l'ipotenusa altrimenti inserire 0.\n");
                    scanf("%f", &ipotenusa);
                    parametro_1[i].nome_parametro = "Cateto 1";
                    parametro_1[i].valore = cateto_1;
                    parametro_2[i].nome_parametro = "Cateto 2";
                    parametro_2[i].valore = cateto_2;
                    parametro_3[i].nome_parametro = "Ipotenusa";
                    parametro_3[i].valore = ipotenusa;
                    parametro_4[i].nome_parametro = "(NULL)";
                    parametro_4[i].valore = 0;
                    FigurePiane[i].valore_errore = funzione_errori_cateti_ipotenusa(cateto_1, cateto_2, ipotenusa);
                    errore = FigurePiane[i].valore_errore;
                    if (errore == NO_ERRORI)
                    {
                        FigurePiane[i].stato_errore = "Nessun Errore";
                        FigurePiane[i].area = (cateto_1 * cateto_2)/2;
                        if (ipotenusa != 0 && ipotenusa > 0)
                        {
                            FigurePiane[i].perimetro = ipotenusa + cateto_1 + cateto_2;
                        }
                    }
                    else
                    {
                        FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                        FigurePiane[i].area = errore;
                        FigurePiane[i].perimetro = errore;
                    }
         
                }
            }
    
            
            else if (scelta_figura_geometrica == TRAPEZIO)
            {
                FigurePiane[i].nome_figura = "TRAPEZIO";
                printf("Inserisci base maggiore\n");
                scanf("%f", &base_maggiore);
                printf("Inserisci base minore\n");
                scanf("%f", &base_minore);
                printf("Inserisci altezza\n");
                scanf("%f", &altezza);
                parametro_1[i].nome_parametro = "Base maggiore";
                parametro_1[i].valore = base_maggiore;
                parametro_2[i].nome_parametro = "Base minore";
                parametro_2[i].valore = base_minore;
                parametro_3[i].nome_parametro = "Altezza";
                parametro_3[i].valore = altezza;
                parametro_4[i].nome_parametro = "(NULL)";
                parametro_4[i].valore = 0;
                FigurePiane[i].valore_errore = funzione_errore_trapezio(base_maggiore, base_minore, altezza);
                errore = FigurePiane[i].valore_errore;
                if (errore == NO_ERRORI)
                {
                    FigurePiane[i].stato_errore = "Nessun Errore";
                    FigurePiane[i].area = ((base_maggiore + base_minore)*altezza)/2;
                    FigurePiane[i].perimetro = perimetro_trapezio(base_maggiore, base_minore, altezza);
                }
                else
                {
                    FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                    FigurePiane[i].area = errore;
                    FigurePiane[i].perimetro = errore;
                }
            }
    
            
            unsigned int scelta_area_rombo;
            const int area_diagonali = 1;
            const int area_lato_altezza = 2;
            if (scelta_figura_geometrica == ROMBO)
            {
                FigurePiane[i].nome_figura = "ROMBO";
                do
                {
                printf("In che modo vuoi calcolare l'area?\n");
                printf("1: Con le diagonali\n2: Con lato e altezza relativa\n");
                scanf("%d", &scelta_area_rombo);
                } while (scelta_area_rombo != 1 && scelta_area_rombo != 2);
                if (scelta_area_rombo == area_diagonali)
                {
                    printf("Inserisci diagonale maggiore\n");
                    scanf("%f", &diagonale_maggiore);
                    printf("Inserisci diagonale minore\n");
                    scanf("%f", &diagonale_minore);
                    parametro_1[i].nome_parametro = "Diagonale maggiore";
                    parametro_1[i].valore = diagonale_maggiore;
                    parametro_2[i].nome_parametro = "Diagonale minore";
                    parametro_2[i].valore = diagonale_minore;
                    parametro_3[i].nome_parametro = "(NULL)";
                    parametro_3[i].valore = 0;
                    parametro_4[i].nome_parametro = "(NULL)";
                    parametro_4[i].valore = 0;
                    FigurePiane[i].valore_errore = funzione_errori_diagonali(diagonale_maggiore, diagonale_minore);
                    errore = FigurePiane[i].valore_errore;
                    if (errore == NO_ERRORI)
                    {
                        FigurePiane[i].stato_errore = "Nessun Errore";
                        FigurePiane[i].area = (diagonale_maggiore * diagonale_minore)/2;
                        FigurePiane[i].perimetro = perimetro_rombo_con_diagonali(diagonale_maggiore, diagonale_minore);
                    }
                    else
                    {
                        FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                        FigurePiane[i].area = errore;
                        FigurePiane[i].perimetro = errore;
                    }
                }
                if (scelta_area_rombo == area_lato_altezza)
                {
                    printf("Inserisci lato\n");
                    scanf("%f", &lato_rombo);
                    printf("Inserisci altezza relativa\n");
                    scanf("%f", &altezza_relativa);
                    parametro_1[i].nome_parametro = "Lato rombo";
                    parametro_1[i].valore = lato_rombo;
                    parametro_2[i].nome_parametro = "Altezza relativo al rombo";
                    parametro_2[i].valore = altezza_relativa;
                    parametro_3[i].nome_parametro = "(NULL)";
                    parametro_3[i].valore = 0;
                    parametro_4[i].nome_parametro = "(NULL)";
                    parametro_4[i].valore = 0;
                    FigurePiane[i].valore_errore = funzione_errori_lato_altezza(altezza_relativa, lato_rombo);
                    errore = FigurePiane[i].valore_errore;
                    if (errore == NO_ERRORI)
                    {
                        FigurePiane[i].stato_errore = "Nessun Errore";
                        FigurePiane[i].area = (lato_rombo * altezza_relativa);
                        FigurePiane[i].perimetro = (lato_rombo * 4);
                    }
                    else
                    {
                        FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                        FigurePiane[i].area = errore;
                        FigurePiane[i].perimetro = errore;
                    }
                }
            }
    
            
            else if (scelta_figura_geometrica == QUADRATO)
            {
                FigurePiane[i].nome_figura = "QUADRATO";
                printf("Inserisci lato\n");
                scanf("%f", &lato_quadrato);
                parametro_1[i].nome_parametro = "Lato";
                parametro_1[i].valore = lato_quadrato;
                parametro_2[i].nome_parametro = "(NULL)";
                parametro_2[i].valore = 0;
                parametro_3[i].nome_parametro = "(NULL)";
                parametro_3[i].valore = 0;
                parametro_4[i].nome_parametro = "(NULL)";
                parametro_4[i].valore = 0;
                if (lato_quadrato <= 0)
                {
                    printf("Lato deve essere un valore positivo \nLato inserito: %f\n", lato_quadrato);
                    FigurePiane[i].valore_errore = ERR_LATO;
                    errore = FigurePiane[i].valore_errore;
                    FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                    FigurePiane[i].area = errore;
                    FigurePiane[i].perimetro = errore;
                }
                else
                {
                    FigurePiane[i].stato_errore = "Nessun Errore";
                    FigurePiane[i].area = lato_quadrato * lato_quadrato;
                    FigurePiane[i].perimetro = lato_quadrato * 4;
                }
            }
    
            
            else if (scelta_figura_geometrica == CERCHIO)
            {
                FigurePiane[i].nome_figura = "CERCHIO";
                printf("Inserisci raggio\n");
                scanf("%f", &raggio);
               parametro_1[i].nome_parametro = "Raggio";
                parametro_1[i].valore = raggio;
                parametro_2[i].nome_parametro = "Diametro";
                parametro_3[i].nome_parametro = "(NULL)";
                parametro_3[i].valore = 0;
                parametro_4[i].nome_parametro = "(NULL)";
                parametro_4[i].valore = 0;
                
                if (raggio <= 0)
                {
                    FigurePiane[i].valore_errore = ERR_RAGGIO;
                    errore = FigurePiane[i].valore_errore;
                    FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                    FigurePiane[i].area = errore;
                    FigurePiane[i].perimetro = errore;
                    diametro = 0;
                }
                else
                {
                    FigurePiane[i].stato_errore = "Nessun Errore";
                    FigurePiane[i].area = pi*raggio*raggio;
                    FigurePiane[i].perimetro = 2*pi*raggio;
                    diametro = raggio + raggio;
                    parametro_2[i].valore = diametro;
                }
            }
            
            
            unsigned int lati_poligono;
            float lato_poligono;
            if (scelta_figura_geometrica == POLIGONI_REGOLARI)
            {
                parametro_1[i].nome_parametro = "Lato";
                parametro_1[i].valore = lato_poligono;
                parametro_2[i].nome_parametro = "(NULL)";
                parametro_2[i].valore = 0;
                parametro_3[i].nome_parametro = "(NULL)";
                parametro_3[i].valore = 0;
                parametro_4[i].nome_parametro = "(NULL)";
                parametro_4[i].valore = 0;
                do
                {
                    printf("Quanti lati ha il poligono regolare (MAX 12)?\n");
                    scanf("%d", &lati_poligono );
                    if (lati_poligono <= 2 || lati_poligono > 12)
                    {
                        printf("Non e' un poligono oppure è stata definita una figura con più di 12 lati. Riprova.\n");
                    }
                } while (lati_poligono <= 2 || lati_poligono > 12);
                printf("Quanto vale il lato?\n");
                scanf("%f", &lato_poligono );
                if (lato_poligono > 0)
                {
                perimetro_area_poligoni(lato_poligono, lati_poligono, i, FigurePiane, parametro_1);
                }
                else
                {
                    FigurePiane[i].nome_figura = "POLIGONO";
                    FigurePiane[i].valore_errore = ERR_LATO;
                    errore = FigurePiane[i].valore_errore;
                    FigurePiane[i].stato_errore = "ERRORE RILEVATO: i valori di area e perimetro indicano l'errore specifico.";
                    FigurePiane[i].area = errore;
                    FigurePiane[i].perimetro = errore;
                    parametro_1[i].nome_parametro = "Lato";
                    parametro_1[i].valore = lato_poligono;
                }
            }
        }
        
        printf("\nPremi invio per stampare man mano i risultati\n");
        while( getchar() != '\n' ); //getchar utilizzato per avere un input prima di procedere alla stampa per maggiore pulizia del programma in esecuzione
        for(i = 0; i < n && getchar(); i++)
        {
            /* stampa della figura numerata a secondda dell'iterazione del ciclo for (i+1) completa di nome, area, perimetro, 
            stato errore ed eventuali parametri (1-4 ) */
            printf("Figura %d: %s\nStato errore: %s\n Area: %f\n Perimetro: %f\n\t%s: %f\n\t%s: %f\n\t%s: %f\n\t%s: %f\n", i+1, FigurePiane[i].nome_figura, FigurePiane[i].stato_errore, FigurePiane[i].area, FigurePiane[i].perimetro, parametro_1[i].nome_parametro, parametro_1[i].valore, parametro_2[i].nome_parametro, parametro_2[i].valore, parametro_3[i].nome_parametro, parametro_3[i].valore, parametro_4[i].nome_parametro, parametro_4[i].valore);
        }
        printf("\nContinuare?");
        printf("\n1: Sì, continua\n0: No, termina e ritorna l'errore\n");
        scanf("%d", &continuare_si_no);
    } while (continuare_si_no == 1);
    
    /* qui è stata usata la variabile int n dichiarata fuori dal ciclo for e dal ciclo do/while per poter scegliere la condizione in cui
    restituire solo un errore generico (0/-1) nel caso anche solo una figura abbia restituito un qualsiasi errore diverso da NO_ERRORI 
    oppure un errore specifico (nel caso di n=1) */
    if (n > 1)
    {
        if (FigurePiane[0].valore_errore != 0 || FigurePiane[1].valore_errore != 0 || FigurePiane[2].valore_errore != 0 || FigurePiane[3].valore_errore != 0 || FigurePiane[4].valore_errore != 0 || FigurePiane[5].valore_errore != 0 || FigurePiane[6].valore_errore != 0 || FigurePiane[7].valore_errore != 0 || FigurePiane[8].valore_errore != 0 || FigurePiane[9].valore_errore != 0 || FigurePiane[10].valore_errore != 0 || FigurePiane[11].valore_errore != 0 || FigurePiane[12].valore_errore != 0 || FigurePiane[13].valore_errore != 0 || FigurePiane[14].valore_errore != 0 || FigurePiane[15].valore_errore != 0 ||
            FigurePiane[16].valore_errore != 0 || FigurePiane[17].valore_errore != 0 || FigurePiane[18].valore_errore != 0 || FigurePiane[19].valore_errore != 0)
        {
            return ERR_GENERICO;
        }
        else
        {
            return NO_ERRORI;
        }
    }
    if (n == 1)
    {
        return errore;
    }
}



    
