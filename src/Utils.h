#pragma once
#include <SDL2/SDL.h>
#include <SDL_image/SDL_image.h>
#include <string>
#include <iostream>

namespace Utils
{
	
	SDL_Renderer* gRenderer = NULL;
    SDL_Texture* LoadTexture(std::string path, SDL_Renderer* renderer)
	{      
		SDL_Texture* newTexture  = NULL;
		SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		if( loadedSurface == NULL )
		{
			std::cout <<  "Unable to load image! Error: " << SDL_GetError() << std::endl;
			return NULL;
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
			if( newTexture == NULL )
			{
				std::cout <<  "Unable to create texture from!" << SDL_GetError() << std::endl;
				return NULL;
			}
			SDL_FreeSurface( loadedSurface );
		}
		return newTexture;
	}
}
