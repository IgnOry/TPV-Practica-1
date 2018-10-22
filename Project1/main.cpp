
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
using namespace std;

using uint = unsigned int;

/*
void firstTest() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("My first test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else {

		SDL_Texture* textures[2];
		string filename[] = { "..\\images\\background1.png" , "..\\images\\dog.png" };

		for (int i = 0; i < 2; i++)
		{
			SDL_Surface* surface = IMG_Load(filename[i].c_str());
			textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_FreeSurface(surface);
		}

		for (int i = 1; i < 4; i++)
		{
			SDL_Rect srcRect = { 0, 0, 128, 82 };

			SDL_Rect destRect = { 0 + 128*i, 500, 100, 100 };

			SDL_RenderCopy(renderer, textures[0], nullptr, nullptr);

			SDL_RenderCopy(renderer, textures[1], &srcRect, &destRect);
			SDL_RenderPresent(renderer);
			SDL_Delay(1000);

		}
		//SDL_Delay(5000);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	}
	*/

int main(int argc, char* argv[]){
	

}