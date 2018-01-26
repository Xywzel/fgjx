#pragma once
#include <SDL2/SDL.h>

namespace Input
{
	enum class Key : int
	{
		None,
		Up,
		Down,
		Left,
		Right,
		Esc,
		Enter,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		KeysTotal,
	};

	const int KeyCount = (int) Key::KeysTotal;

	Key getKeyFromEvent(SDL_Event &e);
}
