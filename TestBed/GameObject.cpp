#include "GameObject.h"
#include <iostream>
#include "App.h"
GameObject::GameObject()
{
	sprite = nullptr;
	spritePosition = new SDL_Rect();
	spritePosition->x = 0;
	spritePosition->y = 0;
}

GameObject::GameObject(std::string ingName)
{
	sprite = SDL_LoadBMP(ingName.c_str());
		
	if (sprite == nullptr)
	{
		std::cout << "Unable to load image %s! SDL Error:\n" << SDL_GetError() << "download.bmp";
	}
	spritePosition = new SDL_Rect();
	spritePosition->x = 0;
	spritePosition->y = 0;
}

void GameObject::CreateSprite(std::string ingName)
{
	if (sprite == nullptr)
	{
		sprite = SDL_LoadBMP(ingName.c_str());
		if (sprite == nullptr)
		{
			std::cout << "Unable to load image %s! SDL Error:\n" << SDL_GetError() << "download.bmp";
		}
	}
}

void GameObject::DeleteSprite()
{
	if (sprite != nullptr)
	{
		SDL_FreeSurface(sprite);
	}
}

void GameObject::Start()
{
}

void GameObject::Update()
{
	if(sprite!=nullptr)
	{
		SDL_BlitSurface(sprite, NULL, App::GetScreenSurface(), spritePosition);
	}
}

void GameObject::SetX(int x)
{
	spritePosition->x= x;
}

void GameObject::SetY(int y)
{
	spritePosition->y = y;
}

void GameObject::SetPos(int x, int y)
{
	spritePosition->x = x;
	spritePosition->y = y;
}

void GameObject::MoveX(int x)
{
	spritePosition->x += x;
}

void GameObject::MoveY(int y)
{
	spritePosition->y += y;
}

void GameObject::Moce(int x, int y)
{
	spritePosition->x += x;
	spritePosition->y += y;
}

GameObject::~GameObject()
{
	DeleteSprite();
}
