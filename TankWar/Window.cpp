#include "Window.h"
#include <stdexcept>

using namespace std;

Window::Window(void): mWindow(nullptr), mRenderer(nullptr)
{
}


Window::~Window(void)
{
}

void Window::Init(string title)
{
	//initialize all SDL subsystems
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		throw runtime_error("SDL Init Failed");
	}
	if (TTF_Init() == -1)
		throw runtime_error("TTF Init Failed");
	//Setup our window size
	mBox.x = 0;
	mBox.y = 0;
	mBox.w = SCREEN_WIDTH;
	mBox.h = SCREEN_HEIGHT;

	//Create our window
	mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, mBox.w, mBox.h, SDL_WINDOW_SHOWN);
	//Make sure it created ok
	if (mWindow == nullptr)
	{
		throw runtime_error("Failed to create window");
	}

	//Create the renderer
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//Make sure it created ok
	if (mRenderer == nullptr)
	{
		throw runtime_error("Failed to create renderer");
	}
}

//Quit SDL and TTF
void Window::Quit()
{
	SDL_Quit();
	TTF_Quit();
}

//Draw an SDL_Texture
void Window::Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip ,float angle, int xPivot, int yPivot,SDL_RendererFlip flip)
{
	//Convert pivot pos from relative to object's center to screen space
	xPivot += dstRect.w / 2;
	yPivot += dstRect.h / 2;
	//SDL expects an SDL_Point as the pivot location
	SDL_Point pivot = { xPivot, yPivot };
	//Draw the texture
	SDL_RenderCopyEx(mRenderer, tex, clip, &dstRect, angle, &pivot, flip);
}

//Load an image
SDL_Texture* Window::LoadImage(string file)
{
	return IMG_LoadTexture(mRenderer,file.c_str());
}

//Render some text
SDL_Texture* Window::RenderText(string message, string fontFile, SDL_Color color, int fontSize)
{
	SDL_Texture* texText = nullptr;
	TTF_Font *font = nullptr;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (nullptr != texText)
	{
		SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
		texText = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_free(surf);
	}
	TTF_CloseFont(font);

	return texText;
}

//Clear window
void Window::Clear()
{
	SDL_RenderClear(mRenderer);
}

//Present renderer
void Window::Present()
{
	SDL_RenderPresent(mRenderer);
}

//Get the window's box
SDL_Rect Window::Box()
{
	//Update mBox to match the current window size
	SDL_GetWindowSize(mWindow, &mBox.w, &mBox.h);
	return mBox;
}
