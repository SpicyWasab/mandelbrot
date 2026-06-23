# Mandelbrot
Ce code est initalement issu d'un TP de C portant sur la compilation séparée durant ma première année de CPGE MP2I.

 ![Sunset over trees](https://raw.githubusercontent.com/SpicyWasab/mandelbrot/main/examples/sunset-over-trees.gif "Sunset over trees") 

## Compilation
```console
gcc -o mandelbrot mandelbrot.c dessin.c
```
ImageMagick doit être installé pour fournir la commande `convert` utilisée par dessin.c.
(note : dessin.c est initialement issu du TP et je l'ai modifiée afin d'utiliser des couleurs, car elle exploite le format PPM)

## Usage
```console
./mandelbrot <resolution> <color_threshold> <x> <y> <radius>
```
- resolution : nombre de pixels d'un côté de l'image (carrée) ;
- color_threshold : le nombre d'itérations avant que l'algorithme ne détermine si la suite complexe diverge. Si un nombre négatif est fournit, l'algorithme génère `-<color_threshold>` images de 0 à cette valeur, afin de pouvoir réaliser une animation ;
- x, y : coordonnées du centre de l'image ;
- radius : taille de la zone de rendue, du centre au bord de l'image.

### Exemple
Pour générer les images permettant de produire le gif au début de ce README :
```console
./mandelbrot 2000 -150 -0.7 -0.4 0.1
```

## Quelques découvertes sympa
Les noms sont totalement arbitraires et attribués selon le bon vouloir de mon imagination. Explorer l'ensemble de mandelbrot donne des souvenirs similaires au fait de reconnaître des formes dans les nuages lorsqu'on est enfant.
- Cosmic Tunnel : mandelbrot 2000 4500 -0.1 0.6498 0.0001
- Sea Spiral : mandelbrot 2000 5000 -0.1000648 0.64975771 0.0000001

| Nom | `(threshold) x y zoom `| Image |
| ------------- | --- | ------------- |
| Sunset over trees | `-0.7 -0.4 0.1`![Sunset over trees](https://raw.githubusercontent.com/SpicyWasab/mandelbrot/main/examples/sunset-over-trees.gif "Sunset over trees")  |
| Lightning | à retrouver ! | ![lightning.gif](https://raw.githubusercontent.com/SpicyWasab/mandelbrot/main/examples/lightning.gif "Lightning") |
| Cosmic Tunnel | `4500 -0.1 0.6498 0.0001` |  ![Cosmic Tunnel](https://raw.githubusercontent.com/SpicyWasab/mandelbrot/main/examples/cosmic-tunnel-2k.png "Cosmic Tunnel (2k)") |
| Sea Spiral | `5000 -1000648 0.64975771 0.0000001` |  ![Sea Spiral](https://raw.githubusercontent.com/SpicyWasab/mandelbrot/main/examples/sea-spiral-2k.png "Sea Spiral (2k)")  |
| Field of Daisies | à retrouver ! |  ![Fields of Daisies](https://raw.githubusercontent.com/SpicyWasab/mandelbrot/main/examples/fields-of-daisies.png "Fields of Daisies (2k)") |
