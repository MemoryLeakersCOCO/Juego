#pragma once
#include <string>
#include <SDL.h>
class GameObject
{
	public:
		GameObject();
		GameObject(std::string ingName);
		void CreateSprite(std::string ingName);
		void DeleteSprite();
		virtual void Start();
		virtual void Update();
		void SetX(int x);
		void SetY(int y);
		void SetPos(int x, int y);
		void MoveX(int x);
		void MoveY(int y);
		void Moce(int x, int y);
		~GameObject();
	private:
		SDL_Surface* sprite;
		SDL_Rect* spritePosition;
};

