#ifndef IMAGE_H 
#define IMAGE_H 

#include <sys/types.h>
#include <dirent.h>
#include "Main.h"

#define IMAGES_DIR "images"

SDL_Surface *title;
SDL_Surface *tom[8];

void loadImages();
void loadImagesFromTar();

#define TYPE_WALL 1
#define TYPE_LADDER 2
#define TYPE_OBJECT 4
#define TYPE_DOOR 8
#define TYPE_HARMFUL 16
#define TYPE_SPRING 32

typedef struct image {
  char *name;
  SDL_Surface *image;
  Uint16 type;
  int monster_index;
} Image;

Image *images[256];
int image_count;

// known image indexes
int img_brick, img_rock, img_back, img_key, img_door, img_door2, img_key, img_smash, img_smash2, img_smash3, img_smash4;
int img_water, img_spring, img_spring2, img_spider, img_spider2;
int img_balloon[3];

#endif
