#include <stdio.h>
#include <stdlib.h>
#include "dessin.h"

// just to explain git and github to someone

void point_suivant(double x, double y, double x_c, double y_c, double* x_next, double* y_next) {
  // printf("Point suivant ! (%f, %f, %f, %f, %f, %f)\n", x, y, x_c, y_c, *x_next, *y_next);
  *x_next = x * x - y * y + x_c;
  *y_next = 2 * x * y + y_c;
}

double norme_carree(double x, double y) {
  return x * x + y * y;
}

int suite_bornee(double x_c, double y_c, int max_iteration) {
  double x = 0;
  double y = 0;
  double x_next = 0;
  double y_next = 0;
  
  // printf("Suite bornée !\n");

  for(int i = 0 ; i < max_iteration ; i++) {
    // printf("%f, %f, %f, %f, %f, %f\n", x, y, x_c, y_c, x_next, y_next);
    point_suivant(x, y, x_c, y_c, &x_next, &y_next);
    x = x_next;
    y = y_next;
    if(norme_carree(x, y) >= 4) {
      // printf("wesh 2\n");
      return i;
    
    }
  }

  return 0;
}

int** mandelbrot(int h, int l, double center_x, double center_y, double r, int max_iteration) {
  printf("rendering mandelbrot with parameters (h=%d, l=%d)\n", h, l);

  // donc au milieu on est à (0, 0), en haut on est à y = 1, en bas en y = -1, à gauche en x = -1, à droite en x = 1
  double x_step = (r * 2.0) / l;
  double y_step = (r * 2.0) / h;
  // double x_offset = 3.0 / 2.0 ;// x_step * (l / 3.0);
  // double y_offset = 3.0 / 2.0 ;// y_step * (h / 3.0);
  double x = center_x - r;
  double y = center_y - r;

  printf("around (%f, %f) with radius %f\n", center_x, center_y, r);
  printf("calculated steps : (%f, %f)\n", x_step, y_step);
  printf("starting rendering from coordinates (%f, %f)...\n", x, y);

  int** render = malloc(h * sizeof(int*));

  // float progress = 0;
  for(int i = 0 ; i < h ; i++) {
    render[i] = malloc(l * sizeof(int));
    for(int j = 0 ; j < l ; j++) {
      x = center_x + i * x_step - r; //- x_offset; //c fo AH BAH PARDON, DÉSOLÉ, JE CORRIGE (konar)
      y = center_y + j * y_step - r; // - y_offset; // méchant !
      
      // printf("rendering pixel (%f, %f) at index (%d, %d)\n", x, y, i, j);
      
      render[i][j] = suite_bornee(x, y, max_iteration);

      /*if((i * l + j) / ((float)h * (float)l) - progress > 0.1) {
        progress = (i * l + j) / (float)h * (float)l;
        printf("progress : %f %%\n", progress * 100);
      }*/
    }
    printf("rendered %d pixels out of %d (%d%%)\n", i * l, h * l, (int)((float)i / (float)h * 100));
  }

  printf("last pixel rendered at coordinates (%f, %f)\n", x, y);

  return render;
}

int main(int argc, char* argv[]) {
  // mandelbrot <size> <x> <y> <radius>
  if(argc != 2 && argc != 6) return 42;
  int size = atoi(argv[1]);
  int max_iteration = (argc == 6) ? atof(argv[2]) : 100;
  double x = (argc == 6) ? atof(argv[3]) : 0;
  double y = (argc == 6) ? atof(argv[4]) : 0;
  double r = (argc == 6) ? atof(argv[5]) : 1.5;

  if(max_iteration < 0) {
    for(int i = 0 ; i < -max_iteration ; i++) {
      char file_name[20];
      sprintf(file_name, "mandelb-%03d.png", i);
      int** render = mandelbrot(size, size, x, y, r, i);
      sauvegarder(file_name, render, size, size, i);
    }
  } else {
    int** render = mandelbrot(size, size, x, y, r, max_iteration);
    sauvegarder("mandelbrot.png", render, size, size, max_iteration);
  }

  return 0;
}
