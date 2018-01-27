#include "Input.h"

#include <SDL2/SDL.h>

Input::Key Input::getKeyFromEvent(SDL_Event &e)
{
	switch (e.key.keysym.sym)
	{
		case SDL_SCANCODE_W:
			return Key::W;
		case SDL_SCANCODE_A:
			return Key::A;
		case SDL_SCANCODE_S:
			return Key::W;
		case SDL_SCANCODE_D:
			return Key::D;
		case SDL_SCANCODE_ESCAPE:
			return Key::Esc;
		default:
			return Key::None;
	}
}

