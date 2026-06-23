# Mandelbrot
Ce code est initalement issu d'un TP de C portant sur la compilation séparée durant ma première année de CPGE MP2I.

| Nom (arbitraire) | Image |
| ------------- | ------------- |
| Sunset over trees | ![Sunset over trees](./examples/sunset-over-trees.gif)  |
| Lightning | ![lightning.gif](./examples/lightning.gif) |


## Usage
### Compilation
```console
gcc -o mandelbrot mandelbrot.c dessin.c
```
ImageMagick doit être installé pour fournir la commande `convert` utilisée par dessin.c.
(note : dessin.c est initialement issu du TP et je l'ai modifiée afin d'utiliser des couleurs, car elle exploite le format PPM)

### Usage
```console
./mandelbrot <resolution> <color_threshold> <x> <y> <radius>
```
- resolution : nombre de pixels d'un côté de l'image (carrée) ;
- color_threshold : le nombre d'itérations avant que l'algorithme ne détermine si la suite complexe diverge. Si un nombre négatif est fournit, l'algorithme génère `-<color_threshold>` images de 0 à cette valeur, afin de pouvoir réaliser une animation ;
- x, y : coordonnées du centre de l'image ;
- radius : taille de la zone de rendue, du centre au bord de l'image.

#### Exemple
Pour générer les images permettant de produire la vidéo au début de ce README :
```console
./mandelbrot 2000 -150 -0.7 -0.4 0.1
```

## Quelques coordonnées sympa
Les noms sont totalement arbitraires.
- Cosmic Tunnel : mandelbrot 2000 4500 -0.1 0.6498 0.0001
- Sea Spiral : mandelbrot 2000 5000 -0.1000648 0.64975771 0.0000001
- Sunrise : mandelbrot 500 -100 -0.7 -0.4 0.1
