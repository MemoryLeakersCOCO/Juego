#pragma once
#include "Scene.h"
#include <SDL.h>
#include "GameObject.h"

class Scene1 :
    public Scene
{
public:
    Scene1();
    ~Scene1();
    void Start();
    void Update();
    void OnEnd();
    GameObject* juanpi;
};

