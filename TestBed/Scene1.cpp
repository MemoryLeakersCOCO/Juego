#include "Scene1.h"
#include <iostream>
#include "App.h"

Scene1::Scene1()
{
    juanpi = new GameObject("download.bmp");

}

Scene1::~Scene1()
{

}

void Scene1::Start() 
{
    Scene::Start();
   
}

void Scene1::Update()
{
    Scene::Update();
    juanpi->MoveX(1);
    juanpi->Update();
}

void Scene1::OnEnd()
{
    Scene::OnEnd();
    delete juanpi;
}
