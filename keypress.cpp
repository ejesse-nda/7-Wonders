#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;

// Surfaces that will be displayed
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;

// event structure
SDL_Event event;

// color of the font
SDL_Color textColor = { 0, 0, 0 };

SDL_Surface *load_image( std::string filename ) {
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;

  loadedImage = IMG_Load( filename.c_str() );

  if ( loadedImage != NULL ) {
    optimizedImage = SDL_DisplayFormat( loadedImage );
    SDL_FreeSurface( loadedImage );
  }

  return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
  SDL_Rect offset;
  
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init() {
  if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) return 0;
  
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

  if ( screen == NULL ) return 0;

  SDL_WM_SetCaption( "Keypress test", NULL );

  return 1;
}

bool load_files() {

// loads image to be display initially before a key press
  image = load_image( "card.jpg" );

// check for problems loading the images or font
  if ( image == NULL ) return 0;

  return 1;
}

void clean_up() {
// free the surfaces
  SDL_FreeSurface( image );
}

// main driver
int main( int argc, char *args[] )
{
  bool change = false;
  bool quit = false;

// initialization
  if ( init() == 0 ) return 1;

// load files
  if ( load_files() == 0 ) return 1;

// sets background to white
SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) );

// applies image to the center of the screen
  apply_surface( (SCREEN_WIDTH - image->w) / 2 , (SCREEN_HEIGHT - image->h) / 2, image, screen );

// while user has not quit
  while ( quit == false ) {
    if ( SDL_PollEvent( &event ) ) {
      if ( event.type == SDL_KEYDOWN ) {
        switch ( event.key.keysym.sym ) {
          case SDLK_UP:
            SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) );
            apply_surface( (SCREEN_WIDTH - image->w) / 2, 0, image, screen);
            break;
          case SDLK_DOWN:
            SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) );
            apply_surface( (SCREEN_WIDTH - image->w) / 2, (SCREEN_HEIGHT - image->h), image, screen);
            break;
          case SDLK_LEFT:
            SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) );
            apply_surface( 0, (SCREEN_WIDTH - image->h) / 2, image, screen);
            break;
          case SDLK_RIGHT:
            SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) );
            apply_surface( (SCREEN_WIDTH - image->w) , (SCREEN_HEIGHT - image->h) / 2, image, screen);
            break;
          default:
            SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) );
            apply_surface( (SCREEN_WIDTH - image->w) / 2 , (SCREEN_HEIGHT - image->h) / 2, image, screen );
            break;
        }
      } else if ( event.type == SDL_QUIT ) {
        quit = true;
      }
    }

// update the screen
    if( SDL_Flip( screen ) == -1 ) return 1;
  } // end while

  clean_up();
}
