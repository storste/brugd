#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "GameEngine.h"
//#include "MatrixGraph.h"
//#include "ListGraph.h"
//#include "Dijkstra.h"

void GameEngine::addDrawable(Drawable* d){
	objects.push_back(d);
}

void GameEngine::renderScene(){

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	for (auto& o : objects){
		o->draw();
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);

}

void GameEngine::graph(){

	//MatrixGraph m("My graph");
	////ListGraph m("My graph");
	//Node* a = new Node("Node A", Point(100, 200));
	//Node* b = new Node("Node B", Point(200, 300));
	//Node* c = new Node("Node C", Point(200, 300));
	//Node* f = new Node("Node F", Point(200, 300));
	//Node* g = new Node("Node G", Point(200, 300));
	//Node* h = new Node("Node H", Point(200, 300));
	//Node* i = new Node("Node I", Point(200, 300));

	//m.add(a);
	//m.add(b);
	//m.add(c);
	//m.add(f);
	//m.add(g);
	//m.add(h);
	//m.add(i);
	//m.connect(a, b, "Link ab", 14);
	//m.connect(a, g, "Link ag", 10);
	//m.connect(a, h, "Link ah", 17);
	//m.connect(b, c, "Link bc", 9);
	//m.connect(b, f, "Link bf", 10);
	//m.connect(b, g, "Link bg", 3);
	//m.connect(c, f, "Link cf", 2);
	//m.connect(f, i, "Link fi", 7);
	//m.connect(g, h, "Link gh", 6);
	//m.connect(g, i, "Link gi", 4);
	//m.connect(h, i, "Link hi", 1);





	//for (auto e : m.getEdgesFrom(a)){ std::cout << e.getName() << std::endl; }


	//std::cout << ((Graph::pathExists(m, n1, n2)) ? "A" : "No")
	//	<< " path exists between " << n1->getName() << " and " << n2->getName() << "." << std::endl;

	//std::cout << ((Graph::pathExists(m, n1, n4)) ? "A" : "No")
	//	<< " path exists between " << n1->getName() << " and " << n4->getName() << "." << std::endl;

	//std::cout << ((Graph::pathExists(m, n1, n5)) ? "A" : "No")
	//	<< " path exists between " << n1->getName() << " and " << n5->getName() << "." << std::endl;

	//std::cout << std::endl;
	//printShortestPath(m, a, b);
	//std::cout << std::endl;
	//printShortestPath(m, a, c);
	//std::cout << std::endl;
	//printShortestPath(m, a, f);
	//std::cout << std::endl;
	//printShortestPath(m, a, g);
	//std::cout << std::endl;
	//printShortestPath(m, a, h);
	//std::cout << std::endl;
	//printShortestPath(m, a, i);

}

//static GameEngine getEngineInstance(){
//	if (GameEngine::instance = nullptr)
//}

//GameEngine::GameEngine()
//{
//	std::cout << "Running engine constructor" << std::endl;
//	init();
//}

GameEngine::GameEngine(int width, int height) : screen_width(width), screen_height(height)
{
	std::cout << "Running engine constructor" << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "SDL inititalized" << std::endl;
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	else{
		std::cout << "SDL_image inititalized" << std::endl;
	}
}

GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(renderer);
	std::cout << "Running engine destructor" << std::endl;
	//Quit TTF subsystems
	if (ttf_init)
		TTF_Quit();
	//Quit SDL subsystems
	SDL_Quit();

}

void GameEngine::render_dot(){
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	if (!getRenderer())
		std::cout << "No renderer..." << std::endl;

	// lite irriterande att path refererar till Game och inte GameEngine här...
	SDL_Texture* golddot = IMG_LoadTexture(getRenderer(), "../GameEngine/golddot.png");
	if (!golddot)
		std::cout << "Image failed to load" << std::endl;

	SDL_Rect src;
	src.h = 32; src.w = 32;
	SDL_Rect dst;
	dst.h = 32; dst.w = 32;
	src.x = 1 * 32;

	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 20; ++j){
			dst.x = j * 32; dst.y = i * 32;
			SDL_RenderCopyEx(getRenderer(), golddot, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
		}
		src.y = i * 32;
	}


	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	std::cout << "Rendering dot" << std::endl;
	SDL_RenderPresent(getRenderer());
	SDL_Delay(2000);
}



//SDL_Renderer* gRenderer;
//SDL_Surface* createSurface();
//static SDL_Window* window = nullptr;


TTF_Font *gFont = NULL;

//SDL_Window* getWindow(void){
//	//The window we'll be rendering to
//	static SDL_Window* window = nullptr;
//
//	if (window != nullptr){
//		//std::cout << "Window already created" << std::endl;
//		return window;
//	}
//
//	//Initialize SDL
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//	}
//	else
//	{
//		std::cout << "SDL inititalized" << std::endl;
//		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//		if (window == NULL)
//		{
//			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//		}
//	}
//
//	gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//	return window;
//}

//SDL_Surface* createSurface(){
//	SDL_Window* window = getWindow();
//	//The surface contained by the window
//	SDL_Surface* screenSurface = NULL;
//
//	//Get window surface
//	screenSurface = SDL_GetWindowSurface(window);
//
//	return screenSurface;
//}
//void UpdateSurface(){
//	//Update the surface
//	SDL_UpdateWindowSurface(getWindow());
//
//}
//
//void DestroyWindow(){
//	SDL_DestroyWindow(getWindow());
//}
//bool GameEngine::init(){
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//		return false;
//	}
//	else
//	{
//		std::cout << "SDL inititalized" << std::endl;
//		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
//		if (window == NULL)
//		{
//			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//		}
//
//		gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//		return true;
//	}
//
//}
//
void GameEngine::render_grid_dots(){
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	for (int i = 0, z = 0; i < 15; ++i){
		for (int j = 0; j < 20; ++j, ++z){


			//Set rendering space and render to screen
			SDL_Rect renderQuad = { j * 32, i * 32, 32, 32 };

			//Render to screen
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, j * 32, i * 32);
		}
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);

}

//int _main(int argc, char *argv[]){
//
//	SDL_Surface* screenSurface = createSurface();
//	//Fill the surface white
//	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
//
//
//
//	std::vector<SDL_Surface*> surfaces;
//
//	//surfaces.push_back(createSurface());
//
//
//
//
//	SDL_Rect r;
//	r.h = 20; r.w = 20; r.x = 0; r.y = 0;
//
//	for (int y = 0; y < SCREEN_HEIGHT; ++y){
//		for (int x = 0; x < SCREEN_WIDTH; ++x){
//			r.y = y;
//			r.x = x;
//			SDL_FillRect(screenSurface, &r, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
//			x += 20;
//		}
//		y += 20;
//	}
//
//
//
//	bool quit = false;
//
//	//Event handler
//	SDL_Event e;
//
//
//	//While application is running
//	while (!!quit)
//	{
//		//Handle events on queue
//		while (SDL_PollEvent(&e) != 0)
//		{
//			//User requests quit
//			if (e.type == SDL_QUIT)
//			{
//				quit = true;
//			}
//
//
//		}
//
//
//		//Update the surface
//		UpdateSurface();
//
//
//		//Wait two seconds
//		SDL_Delay(2000);
//	}
//
//
//	////Initialize SDL_ttf
//	//if (TTF_Init() == -1)
//	//{
//	//	printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
//
//	//}
//	//else{
//	//	gFont = TTF_OpenFont("16_true_type_fonts/lazy.ttf", 32);
//	//	SDL_Color textColor = { 0, 0, 0 };
//	//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	//	SDL_RenderClear(gRenderer);
//	//	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
//	//	for (int i = 0, z = 0; i < 15; ++i){
//	//		for (int j = 0; j < 20; ++j, ++z){
//
//	//			std::string textureText = std::to_string(z);
//	//			SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
//
//	//			SDL_Texture* mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
//
//	//			//Set rendering space and render to screen
//	//			SDL_Rect renderQuad = { j * 32, i * 32, 32, 32 };
//	//			
//	//			//Render to screen
//	//			SDL_RenderCopyEx(gRenderer, mTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
//	//			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0x00);
//	//			SDL_RenderDrawPoint(gRenderer, j * 32, i * 32);
//	//		}
//	//	}
//	//	SDL_RenderPresent(gRenderer);
//	//	SDL_Delay(2000);
//	//}
//
//	//int imgFlags = IMG_INIT_PNG;
//	//if (!(IMG_Init(imgFlags) & imgFlags))
//	//{
//	//	printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//	//}
//	//SDL_Texture* tileimg = IMG_LoadTexture(gRenderer, "tiles.png");
//	//SDL_Rect src;
//	//src.h = 32; src.w = 32;
//	//SDL_Rect dst;
//	//dst.h = 32; dst.w = 32;
//	//src.x = 1 * 32;
//	//for (int i = 0; i < 15; ++i){
//	//	for (int j = 0; j < 20; ++j){
//	//		dst.x = j * 32; dst.y = i * 32;
//	//		SDL_RenderCopyEx(gRenderer, tileimg, &src, &dst, 0.0, NULL, SDL_FLIP_NONE);
//	//	}
//	//	src.y = i * 32;
//	//}
//	//SDL_RenderPresent(gRenderer);
//	//SDL_Delay(10000);
//
//	//Destroy window
//	DestroyWindow();
//
//	//
//	//	//Free global font
//	TTF_CloseFont(gFont);
//	gFont = NULL;
//
//	//
//
//
//
//
//	return (0);
//}
//

