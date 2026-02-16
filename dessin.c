#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "dessin.h"

void color(int val, int max_val, int* r, int* g, int* b) {
  // int max = 600; // should match the value that I put in mandelbrot.c, I should refactor later // done
  
  // safe guard until I fix this shit...
  if(max_val % 3 == 2) max_val++;

  int third = max_val / 3;
  if(val < third) { // 
    *b = val;
  } else if(val < (max_val - third)) {
    *b = third - (val - third);
    *g = val - third;
  } else {
    *g = third - (val - (max_val - third));
    *r = val - (third * 2);
  }

  // parce que flemme de corriger mdrrr donc on va sauver les apparences
  // if(*r >= third) *r = third - 1;
  // if(*g >= third) *g = third - 1;
  // if(*b >= third) *b = third - 1;
}

void sauvegarder(const char* fichier, int** img, int h, int l, int max_color_value){
    FILE* file;
    int val;
    
    // ce qui suit sera vu plus tard dans l'année
    file = fopen("toto.ppm", "w");
    fprintf(file, "P3\n%d %d\n%d\n", l, h, max_color_value / 3);
    for(int j=0; j<h; j++){
        for(int i=0; i<l; i++){
            val = img[i][j];
            int r = 0;
            int g = 0;
            int b = 0;
            color(val, max_color_value, &r, &g, &b);
            fprintf(file, "%d %d %d ", r, g, b);
        }
        fprintf(file, "\n");
    }    
    fclose(file);
        
    // ce qui suit est complètement hors programme
    if(fork()==0){
        execlp("convert", "convert", "toto.ppm", fichier, NULL);
    }
    wait(NULL);
}
