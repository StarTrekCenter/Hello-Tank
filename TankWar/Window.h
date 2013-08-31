#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <memory>

class Window
{
public:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;

public:
	Window(void);
	~Window(void);
	//Start SDL and TTF, create the window and renderer
	static void Init(std::string title);
	//Quit SDL and TTF
	static void Quit();
	//Draw an SDL_Texture
	static void Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip = NULL,float angle = 0.0, 
				  int xPivot = 0, int yPivot = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
	//Load an image
	static SDL_Texture* LoadImage(std::string file);
	//Render some text
	static SDL_Texture* RenderText(std::string, std::string, SDL_Color, int);
	//Clear window
	static void Clear();
	//Present renderer
	static void Present();
	//Get the window's box
	static SDL_Rect Box();

private:
	static SDL_Window* mWindow;
	static SDL_Renderer* mRenderer;
	static SDL_Rect mBox;

};

