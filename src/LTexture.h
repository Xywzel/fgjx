#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class LTexture
{
	public:
		LTexture();

		//Deallocates memory
		~LTexture();

		//Initializes variables
		bool init(SDL_Renderer* renderer, std::string path );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render(float x, float y, float w, float h);

		//Gets image dimensions
		int getWidth();
		int getHeight();

		bool ready;
	private:
		//Image dimensions
		int mWidth;
		int mHeight;
		//The actual hardware texture
		SDL_Texture* mTexture;
		SDL_Renderer* renderer;
};
