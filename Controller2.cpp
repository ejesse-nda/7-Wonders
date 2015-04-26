/*
 * File: tutorialBMP.cpp
 * Author: Eric Jesse
 * Class: CSE20212, Sp 2015
 * Lab: 7&8
 * Description: SDL tutorial driver for bitmap images.
 *    Can move a card image around the window via the arrow keys.
 *
 */

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//GLOBAL VARIABLES
const int SCREEN_WIDTH = 600;	//335 is width of Card image
const int SCREEN_HEIGHT = 600;	//515 is length of Card image
SDL_Window* gWindow = NULL;		//Window that appears (g for global)
SDL_Surface* gScreenSurface = NULL; //Surface of window to write to
SDL_Surface* gCard = NULL;		//Surface containing Card image
SDL_Surface* gButton = NULL;
vector<SDL_Surface*> gCards;
vector<SDL_Surface*> gButtons;

//Function declarations
bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string path);

//Main Function
int main() {

	//Start SDL/window
	if( !init() ) cout << "Failed to initialize!" << endl;
	//Load media
	else if( !loadMedia() ) cout << "Failed to load media!" << endl;
	else {

		bool quit = false; //Main loop flag
		bool mouseDown = false;
		bool reset = false;
		int x=0, y=0, xt=0, yt=0, xi=0, yi=0, xf=0, yf=0; //Initial image offset
		int cardSelect = 0, buttonSelect = 0;
		SDL_Event e; //Event handler
		gCard = gCards[0];
		gButton = gButtons[0];

		//Main while loop
		while (!quit) {

			//Handle events in event queue
			while (SDL_PollEvent(&e)!=0) {
				//User requests quit
				if (e.type == SDL_QUIT) quit = true;
				//User presses a key
                else if (e.type == SDL_KEYDOWN) {
                    //Set new card position based on arrow key press
                    switch (e.key.keysym.sym) {
                        case SDLK_UP:
						y = 300-y;
						break;

                        case SDLK_DOWN:
						y = 300-y;
                        break;

                        case SDLK_LEFT:
						x = 300-x;
                        break;

                        case SDLK_RIGHT:
						x = 300-x;
                        break;

						case SDLK_RETURN:
						if (gCard == gCards[0]) gCard = gCards[1];
						else if (gCard == gCards[1]) gCard = gCards[0];

                        default:
                        break;
                    }
                } else if (e.type == SDL_MOUSEBUTTONDOWN){
					SDL_GetMouseState(&xi,&yi);
					if ( x<xi && xi< x+gCard->w/2 && y<yi && yi < y+gCard->h/2){
						mouseDown = true;
						xt = x;
						yt = y;
					}
//					cout << "Xi: " << xi << endl << "Yi: " << yi << endl;
				} else if (e.type == SDL_MOUSEMOTION){
					SDL_GetMouseState(&xf,&yf);
					if (mouseDown == true){
						x = xt+(xf-xi);
						if (x < 0) x = 0;
						if (x+gCard->w/2 > SCREEN_WIDTH) x = SCREEN_WIDTH - gCard->w/2;
						y = yt+(yf-yi);
						if (y < 0) y = 0;
						if (y+gCard->h/2 > SCREEN_HEIGHT) y = SCREEN_HEIGHT - gCard->h/2;
					}
				} else if (e.type == SDL_MOUSEBUTTONUP){
					mouseDown = false;
				}
			}//End event while loop

			SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0x00, 0x00, 0x00)); //Make black to "erase" old image
			//Apply the image stretched to Cards
			SDL_Rect stretchRect;


			if (cardSelect!=0 && buttonSelect!=0){
				stretchRect.x = 3*gButton->w+110; //Set x,y image start position (0,0 is upper left)
				if (stretchRect.x<xi && xi< stretchRect.x+stretchRect.w && stretchRect.y<yi && yi < stretchRect.y+stretchRect.w && reset==true) {
					cardSelect=0;
					buttonSelect=0;
					reset = false;
				} else {
					SDL_BlitScaled(gButton, NULL, gScreenSurface, &stretchRect);
					reset = true;
				}
			}
			gButton = gButtons[0];


			stretchRect.x = 20; //Set x,y image start position (0,0 is upper left)
			stretchRect.y = SCREEN_HEIGHT-gCard->h/2;
			stretchRect.w = gCard->w/2;//SCREEN_WIDTH/2; //Make the image fill a quarter of the window
			stretchRect.h = gCard->h/2;//SCREEN_HEIGHT/2;
			if ((stretchRect.x<xi && xi< stretchRect.x+gCard->w/2 && stretchRect.y<yi && yi < stretchRect.y+gCard->h/2) || cardSelect==1) {gCard = gCards[1]; cardSelect = 1;}
			SDL_BlitScaled(gCard, NULL, gScreenSurface, &stretchRect);
			gCard = gCards[0];

			stretchRect.x = gCard->w/2+50; //Set x,y image start position (0,0 is upper left)
			if ((stretchRect.x<xi && xi< stretchRect.x+gCard->w/2 && stretchRect.y<yi && yi < stretchRect.y+gCard->h/2) || cardSelect==2) {gCard = gCards[1]; cardSelect = 2;}
			SDL_BlitScaled(gCard, NULL, gScreenSurface, &stretchRect);
			gCard = gCards[0];

			stretchRect.x = 2*gCard->w/2+80; //Set x,y image start position (0,0 is upper left)
			if ((stretchRect.x<xi && xi< stretchRect.x+gCard->w/2 && stretchRect.y<yi && yi < stretchRect.y+gCard->h/2) || cardSelect==3) {gCard = gCards[1]; cardSelect = 3;}
			SDL_BlitScaled(gCard, NULL, gScreenSurface, &stretchRect);
			gCard = gCards[0];

			//Apply to Buttons
			stretchRect.x = 20; //Set x,y image start position (0,0 is upper left)
			stretchRect.y = 0;
			stretchRect.w = gButton->w;//SCREEN_WIDTH/2; //Make the image fill a quarter of the window
			stretchRect.h = gButton->h;//SCREEN_HEIGHT/2;

			if ((stretchRect.x<xi && xi< stretchRect.x+stretchRect.w && stretchRect.y<yi && yi < stretchRect.y+stretchRect.h) || buttonSelect==1) {gButton = gButtons[1]; buttonSelect = 1;}
			SDL_BlitScaled(gButton, NULL, gScreenSurface, &stretchRect);
			gButton = gButtons[2];

			stretchRect.x = gButton->w+50; //Set x,y image start position (0,0 is upper left)
			if ((stretchRect.x<xi && xi< stretchRect.x+stretchRect.w && stretchRect.y<yi && yi < stretchRect.y+stretchRect.w) || buttonSelect==2) {gButton = gButtons[3]; buttonSelect = 2;}
			SDL_BlitScaled(gButton, NULL, gScreenSurface, &stretchRect);
			gButton = gButtons[4];

			stretchRect.x = 2*gButton->w+80; //Set x,y image start position (0,0 is upper left)
			if ((stretchRect.x<xi && xi< stretchRect.x+stretchRect.w && stretchRect.y<yi && yi < stretchRect.y+stretchRect.w) || buttonSelect==3) {gButton = gButtons[5]; buttonSelect = 3;}
			SDL_BlitScaled(gButton, NULL, gScreenSurface, &stretchRect);
			gButton = gButtons[2];




			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

		}//End main while loop

	}//End if initialization conditional

	close();

	return 0;
}


//Initializes the window and surfaces
bool init(){

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init(SDL_INIT_VIDEO)<0 ) {
		cout << "SDL couldn't initialize! SLD_Error: " << SDL_GetError() << endl;
		success = false;
	} else {
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow==NULL) {
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		} else {
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}


//Load the specific image into a surface
bool loadMedia(){

	//Success flag
	bool success = true;

	//Load image
	gCards.push_back(NULL);//resize(2);
	gCards.push_back(NULL);//resize(2);
	gCards[0] = loadSurface("Images/7_wonders.bmp");
	gCards[1] = loadSurface("Images/7_wonders1.bmp");

cout << "Cards" << endl;
	gButtons.push_back(NULL);//resize(2);
	gButtons.push_back(NULL);//resize(2);
	gButtons.push_back(NULL);//resize(2);
	gButtons.push_back(NULL);//resize(2);
	gButtons.push_back(NULL);//resize(2);
	gButtons.push_back(NULL);//resize(2);
	gButtons[0] = loadSurface("Images/PlayButtonU.bmp");
	gButtons[1] = loadSurface("Images/PlayButtonS.bmp");
	gButtons[2] = loadSurface("Images/WonderButtonU.bmp");
	gButtons[3] = loadSurface("Images/WonderButtonS.bmp");
	gButtons[4] = loadSurface("Images/CoinU.bmp");
	gButtons[5] = loadSurface("Images/CoinS.bmp");
cout << "buttons" << endl;

	return success;
}


//Shut down the SDL and free the surfaces to avoid memory leaks
void close(){

	//Deallocate surface
	SDL_FreeSurface(gCard);
	gCard = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL
	SDL_Quit();

}


//Load the specified image into a surface
SDL_Surface* loadSurface(std::string path){

	//Final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) {
		cout << "Unable to load image " << path << "! SDL_Error: " << SDL_GetError() << endl;
	} else {
		//If surface not null, Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL) cout << "Unable to optimize image " << path << "! SDL_Error: " << SDL_GetError() << endl;

		//Free old surface
		SDL_FreeSurface(loadedSurface);

	}

	return optimizedSurface;
}

