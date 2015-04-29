/*
 * File: Controller2.cpp
 * Author: Eric Jesse
 * Class: CSE20212, Sp 2015
 * Description: GUI for 7 Wonders game
 *    Can move a card image around the window via the arrow keys.
 *
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//GLOBAL VARIABLES
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
SDL_Window* gWindow = NULL;		//Window that appears (g for global)
SDL_Renderer* gRenderer = NULL; //The renderer that puts images in window
SDL_Texture* gCard = NULL;		//Surface for Card controller
SDL_Texture* gButton = NULL;	//Texture for Button controller

//Vectors for various image storage
vector<SDL_Texture*> gCards;
vector<SDL_Texture*> gButtons;
vector<SDL_Texture*> gAge;
vector<SDL_Texture*> gNum;

//Function declarations
bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture(std::string path);


//Main Function
int main() {

	//Start SDL/window
	if( !init() ) cout << "Failed to initialize!" << endl;
	//Load media
	else if( !loadMedia() ) cout << "Failed to load media!" << endl;
	else {

		bool quit = false;  //Main loop flag
		bool reset = false; //Reset selection flag
		int xi=0, yi=0; //Mouse input variables
		int cardSelect = 0, buttonSelect = 0; //Selection variablea
		int playerTurn = 1, Age = 1, numCards=7, numPlayers=2; //Game Test Variables
		SDL_Event e; //Event handler
		//Initialize Button/Card selection
		gCard = gCards[0];
		gButton = gButtons[0];

		//Setup windows
		SDL_Rect Button1 = {010,0,100,100};
		SDL_Rect Button2 = {120,0,100,100};
		SDL_Rect Button3 = {230,0,100,100};
		SDL_Rect Button4 = {340,0,100,100};
		SDL_Rect AgeSpot = {450,0,100,100};
		SDL_Rect PlayerSpot = {560,0,100,100};
		vector<SDL_Rect> Card;

		SDL_Rect Card1 = {010,400,100,200};
		SDL_Rect Card2 = {120,400,100,200};
		SDL_Rect Card3 = {230,400,100,200};
		SDL_Rect Card4 = {340,400,100,200};
		SDL_Rect Card5 = {450,400,100,200};
		SDL_Rect Card6 = {560,400,100,200};
		SDL_Rect Card7 = {670,400,100,200};
		Card.push_back(Card1);
		Card.push_back(Card2);
		Card.push_back(Card3);
		Card.push_back(Card4);
		Card.push_back(Card5);
		Card.push_back(Card6);
		Card.push_back(Card7);


		//Main while loop
		while (!quit) {

			//Handle events in event queue
			while (SDL_PollEvent(&e)!=0) {
				//User requests quit
				if (e.type == SDL_QUIT) quit = true;
				//Mouse click
                else if (e.type == SDL_MOUSEBUTTONDOWN)	SDL_GetMouseState(&xi,&yi);
			}//End event while loop

			//Clean the screen
			SDL_RenderClear(gRenderer);

			//Display Age and Player Number
			SDL_RenderSetViewport(gRenderer, &AgeSpot);
			SDL_RenderCopy(gRenderer, gAge[Age-1], NULL, NULL);
			SDL_RenderSetViewport(gRenderer, &PlayerSpot);
			SDL_RenderCopy(gRenderer, gNum[playerTurn-1], NULL, NULL);

			//Display Cards/Selection
			for (int i = 0; i<numCards; i++){
				gCard = gCards[0];
				if ((Card[i].x<xi && xi< Card[i].x+Card[i].w && Card[i].y<yi && yi < Card[i].y+Card[i].w) || cardSelect==i+1) {gCard = gCards[1]; cardSelect = i+1;}
				SDL_RenderSetViewport(gRenderer, &Card[i]);
				SDL_RenderCopy(gRenderer, gCard, NULL, NULL);
			}

			//Display Button/Selection
			gButton = gButtons[0];
			if ((Button2.x<xi && xi< Button2.x+Button2.w && Button2.y<yi && yi < Button2.y+Button2.w) || buttonSelect==1) {gButton = gButtons[1]; buttonSelect = 1;}
					SDL_RenderSetViewport(gRenderer, &Button2);
					SDL_RenderCopy(gRenderer, gButton, NULL, NULL);
			gButton = gButtons[2];
			if ((Button3.x<xi && xi< Button3.x+Button3.w && Button3.y<yi && yi < Button3.y+Button3.w) || buttonSelect==2) {gButton = gButtons[3]; buttonSelect = 2;}
					SDL_RenderSetViewport(gRenderer, &Button3);
					SDL_RenderCopy(gRenderer, gButton, NULL, NULL);
			gButton = gButtons[4];
			if ((Button4.x<xi && xi< Button4.x+Button4.w && Button4.y<yi && yi < Button4.y+Button4.w) || buttonSelect==3) {gButton = gButtons[5]; buttonSelect = 3;}
					SDL_RenderSetViewport(gRenderer, &Button4);
					SDL_RenderCopy(gRenderer, gButton, NULL, NULL);

			//Conditionally display next player turn.
			if (cardSelect!=0 && buttonSelect!=0){
				//If button pressed...
				if (Button1.x<xi && xi< Button1.x+Button1.w && Button1.y<yi && yi < Button1.y+Button1.w && reset==true) {
					//Reset player selections
					cardSelect=0;
					buttonSelect=0;
					reset = false;
					//Dummy Game controls
					if (playerTurn==numPlayers){
						playerTurn=0;
						numCards--;
						if (numCards == 1){
							numCards=7;
							Age++;
						}
					}
					playerTurn++;
				//else keep button displayed
				} else {
					SDL_RenderSetViewport(gRenderer, &Button1);
					SDL_RenderCopy(gRenderer, gButtons[6], NULL, NULL);
					reset = true;
				}
			}

			//Update the surface
			SDL_RenderPresent(gRenderer);

		}//End main while loop

	}//End if initialization conditional

	//Close everything
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
			//Create Renderer
			gRenderer = SDL_CreateRenderer(gWindow,-1,0);
			if (gRenderer==NULL){
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			} else {
				//Set default background to black
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			}
		}
	}

	return success;
}


//Load the specific image into a surface
bool loadMedia(){

	//Success flag
	bool success = true;

	//Load Card images
	gCards.push_back(loadTexture("Images/7_wonders.jpg"));
	gCards.push_back(loadTexture("Images/7_wonders1.jpg"));

	//Load Age numbers
	gAge.push_back(loadTexture("Images/Age1.jpg"));
	gAge.push_back(loadTexture("Images/Age2.jpg"));
	gAge.push_back(loadTexture("Images/Age3.jpg"));

	//Load Player numbers
	gNum.push_back(loadTexture("Images/Num1.jpg"));
	gNum.push_back(loadTexture("Images/Num2.jpg"));
	gNum.push_back(loadTexture("Images/Num3.jpg"));
	gNum.push_back(loadTexture("Images/Num4.jpg"));
	gNum.push_back(loadTexture("Images/Num5.jpg"));
	gNum.push_back(loadTexture("Images/Num6.jpg"));
	gNum.push_back(loadTexture("Images/Num7.jpg"));

	//Load Buttons
	gButtons.push_back(loadTexture("Images/PlayButtonU.jpg"));
	gButtons.push_back(loadTexture("Images/PlayButtonS.jpg"));
	gButtons.push_back(loadTexture("Images/WonderButtonU.jpg"));
	gButtons.push_back(loadTexture("Images/WonderButtonS.jpg"));
	gButtons.push_back(loadTexture("Images/CoinU.jpg"));
	gButtons.push_back(loadTexture("Images/CoinS.jpg"));
	gButtons.push_back(loadTexture("Images/NextButton.jpg"));

	return success;
}


//Shut down the SDL and free the surfaces to avoid memory leaks
void close(){

	//Destroy Renderer
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	//Deallocate surface
	SDL_DestroyTexture(gCard);
	gCard = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL
	IMG_Quit();
	SDL_Quit();

}


//Load specified image into a texture
SDL_Texture* loadTexture(string path){

	//Final optimized image
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL){
		cout << "Unable to load image " << path << "! SDL_Error: " << SDL_GetError() << endl;
	} else {
		newTexture = SDL_CreateTextureFromSurface(gRenderer,loadedSurface);
		//Make sure texture not null
		if(newTexture == NULL){
			cout << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << endl;
		}
		//Free old surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;

}

