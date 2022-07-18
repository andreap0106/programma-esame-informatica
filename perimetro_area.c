//
//  perimetro_area.c
//  Progetto esame informatica
//
//  Created by Andrea Panariello on 17/07/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "perimetro_area.h"


float perimetro_rombo_con_diagonali (float diagonale_maggiore, float diagonale_minore)
{
    float perimetro;
    perimetro = sqrtf((((diagonale_maggiore/2)*(diagonale_maggiore/2))+((diagonale_minore/2)*(diagonale_minore/2)))) * 4;
    //printf("Perimetro del rombo vale: %d", perimetro);
    return perimetro;
}



//la funzione chiede se si vuole calcolare anche il perimetro e di che tipo di trapezio si tratta per poi procedere al calcolo di conseguenza
float perimetro_trapezio (float base_magg, float base_min, float altezza_trapezio)
{
    int voglioperimetro;
    printf("Vuoi calcolare anche il perimetro?\n");
    printf("1: Sì\n2: No\n");
    scanf("%d", &voglioperimetro);
    float perimetro = 0;
    if (voglioperimetro == 1)
    {
        float lat1;
        float lat2;
        int tipologiatrapezio;
        printf("Che tipologia di trapezio?\n");
        printf("1: isoscele\n2: Scaleno\n3: Rettangolo\n");
        scanf("%d", &tipologiatrapezio);
        if (tipologiatrapezio == 1)
        {
            do
            {
                printf("inserisci il lato obliquo\n");
                scanf("%f", &lat1);
                if (lat1 <= 0)
                {
                    printf("Lato obliquo deve essere un valore positivo \nLato obliquo inserito: %f.", lat1);
                    printf(" Inserire un valore valido\n");
                }
            } while (lat1 <= 0 );
            perimetro =(2*lat1) + base_min + base_magg;
        }
        if (tipologiatrapezio == 2)
        {
            do
            {
                printf("inserisci i due lati obliqui\n");
                scanf("%f", &lat1);
                printf("inserire l'altro\n");
                scanf("%f", &lat2);
                if (lat1 <= 0 || lat2 <= 0)
                {
                    printf("Lati obliqui devono essere un valore positivo \nLati obliquo inseriti: %f e %f.", lat1, lat2);
                    printf(" Inserire dei valori validi\n");
                }
            } while (lat1 <= 0 || lat2 <= 0);
            perimetro = lat2 + lat1 + base_min + base_magg;
        }
        if (tipologiatrapezio == 3)
        {
            do
            {
                printf("inserisci il lato obliquo\n");
                scanf("%f", &lat1);
                if (lat1 <= 0)
                {
                    printf("Lato obliquo deve essere un valore positivo \nLato obliquo inserito: %f.", lat1);
                    printf(" Inserire un valore valido\n");
                }
            } while (lat1 <= 0 );
            perimetro = lat1 + base_min + base_magg + altezza_trapezio;
        }
    }
    return perimetro;
}




void perimetro_area_poligoni (float lato_poligono, int lati_poligono, int i, caratteristiche_figure_piane *array_figure_piane, parametro_calcolo_area_perimetro *array_parametro)
{
    array_figure_piane[i].stato_errore = "Nessun Errore";
    array_parametro[i].nome_parametro = "lato poligono";
    array_parametro[i].valore = lato_poligono;
    /* con questo array, contenente i numeri fissi per ogni poligno regolare, tramite gli switch case sarà possibile caso per caso a seconda del numero
     di lati del poligono, richiamare il numero fisso dall'indice corrispondente per calcolare l'area */
    float array [DIM_NFISSO] = {0.289, 0.5, 0.688, 0.866, 1.038, 1.207, 1.374, 1.539, 1.703, 1.866};
     // area poligono = (perimetro * apotema)/2
     // apotema = lato * numero fisso
     // apotema = lato_poligono * array[];
    float perimetro_poligono = lati_poligono * lato_poligono; //perimetro uguale per tutti i casi di poligono regolare
    float area_poligono;
        
    switch (lati_poligono)
    {
        case 3:
            area_poligono = (perimetro_poligono * lato_poligono * array[0])/2;
            array_figure_piane[i].nome_figura = "TRIANGOLO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 4:
            area_poligono = (perimetro_poligono * lato_poligono * array[1])/2;
            array_figure_piane[i].nome_figura = "QUADRATO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 5:
            area_poligono = (perimetro_poligono * lato_poligono * array[2])/2;
            array_figure_piane[i].nome_figura = "PENTAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 6:
            area_poligono = (perimetro_poligono * lato_poligono * array[3])/2;
            array_figure_piane[i].nome_figura = "ESAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 7:
            area_poligono = (perimetro_poligono * lato_poligono * array[4])/2;
            array_figure_piane[i].nome_figura = "ETTAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 8:
            area_poligono = (perimetro_poligono * lato_poligono * array[5])/2;
            array_figure_piane[i].nome_figura = "OTTAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 9:
            area_poligono = (perimetro_poligono * lato_poligono * array[6])/2;
            array_figure_piane[i].nome_figura = "ENNAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 10:
            area_poligono = (perimetro_poligono * lato_poligono * array[7])/2;
            array_figure_piane[i].nome_figura = "DECAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 11:
            area_poligono = (perimetro_poligono * lato_poligono * array[8])/2;
            array_figure_piane[i].nome_figura = "ENDECAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
        case 12:
            area_poligono = (perimetro_poligono * lato_poligono * array[9])/2;
            array_figure_piane[i].nome_figura = "DODECAGONO";
            array_figure_piane[i].area = area_poligono;
            array_figure_piane[i].perimetro = perimetro_poligono;
            break;
    }
}
