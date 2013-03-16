// Standard Library
#include <iostream>
#include <vector>

// Boost Libraries
#include <boost/shared_ptr.hpp>

// SDL Libraries
#include <SDL.h>
#include <SDL_opengl.h>

// This Project


// --------------------------------------------------------
// Main Program
//

const int WIDTH=1000;
const int HEIGHT=900;
const int BPP=4;
const int DEPTH=32;


int main(int argc, char* argv[]) {
	
	std::vector< boost::shared_ptr<int> > dummyBoostContainer;
	
	std::cout << "Hello World,\nI was compiled using Intel ICL compiler and cmake\n";
	std::cout << "So far I am linked to the Boost Libraries\n";
	std::cout << "and the SDL libaraies\n";  
	
	


	SDL_Surface *screen;
	SDL_Color text_color = {0, 0, 0}; 
	SDL_Event event;
  
	//initialise Screen
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ) return 1;
   
    //if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_FULLSCREEN|SDL_HWSURFACE)))
    if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF)))
    {
        SDL_Quit();
        return 1;
    }
	SDL_WM_SetCaption( "Program Name", 0 );
	
	
	
	bool running=true;
	
    do { 
		///// SDL OUTPUT TO SCREEN ////////////////
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));	
			//ostringstream oss;
			//oss.str("");
			//oss << "hi";
			//writeTextToSurface(oss.str(), screen, 20 ,20 , graphfont, text_color); 
			
			while (SDL_PollEvent(&event))
			{
				// Check for the quit message
				if (event.type == SDL_QUIT)
				{
					// Quit the program
					std::cerr << "SDL_QUIT event"<< std::endl;
					running=false;
					break;
				}
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						
					}
					if (event.key.keysym.sym == SDLK_c) {
						
					}
					if (event.key.keysym.sym == SDLK_s) {
						
					}
				}
			}
			
	// do pretty things here.	


		
	
	   
	SDL_Flip(screen);
  
	SDL_FreeSurface(screen);
	
	
	
	} while (running==true);

	return 0;

}



