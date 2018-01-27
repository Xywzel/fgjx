#include "LTexture.h"

LTexture::LTexture()
{
	ready = false;
	mWidth = 0;
	mHeight = 0;
	mTexture = NULL;
	renderer = NULL;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::init(SDL_Renderer* sdl_renderer, std::string path)
{
	free();
	renderer = sdl_renderer;

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_BLEND);

	ready = true;

	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(float x, float y, float w, float h)
{
	//Set rendering space and render to screen
	int imageWidth = 1280;
	int imageHeight = 800;
	SDL_Rect renderQuad = { x*imageWidth, y*imageHeight, w*imageWidth, h*imageHeight };
	SDL_RenderCopy( renderer, mTexture, NULL, &renderQuad );
}

void LTexture::render(float x, float y, float scale)
{
	//Set rendering space and render to screen
	int imageWidth = 1280;
	int imageHeight = 800;
	int xp = (int) ((x*imageWidth) - (scale*mWidth*0.5f));
	int yp = (int) ((y*imageHeight) - (scale*mHeight*0.5f));
	SDL_Rect renderQuad = { xp, yp, scale*mWidth, scale*mHeight};
	SDL_RenderCopy( renderer, mTexture, NULL, &renderQuad );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
