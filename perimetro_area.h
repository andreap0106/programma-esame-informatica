//
//  perimetro_area.h
//  Progetto esame informatica
//
//  Created by Andrea Panariello on 17/07/22.
//
#ifndef perimetro_area_h
#define perimetro_area_h

#define MAX_DIM                  30
#define DIM_NFISSO               10


typedef struct{
    char *nome_figura;
    float perimetro;
    float area;
    char *stato_errore;
    int valore_errore;
} caratteristiche_figure_piane;

typedef struct{
    char *nome_parametro;
    float valore;
} parametro_calcolo_area_perimetro;


float perimetro_rombo_con_diagonali (float diagonale_maggiore, float diagonale_minore);
float perimetro_trapezio (float base_magg, float base_min, float altezza_trapezio);
void perimetro_area_poligoni (float lato_poligono, int lati_poligono, int i, caratteristiche_figure_piane *array_figure_piane, parametro_calcolo_area_perimetro *array_parametro);

#endif /* perimetro_area_h */
