#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class LTexture
{
	public:
		//Initializes variables
		LTexture(SDL_Renderer* sdl_renderer);

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( int x, int y );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
		SDL_Renderer* renderer = NULL;
};
