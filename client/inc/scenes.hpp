/**
 * This file is automatically generated by make.
 * All changes will be overrided next time you compile
**/
#ifndef _CREATESCENES_HPP
#define _CREATESCENES_HPP

#include <iostream>
#include <vector>
#include <string>

#include <../inc/scenes/Game.hpp>
#include <../inc/scenes/Lobby.hpp>
#include <../inc/scenes/Menu.hpp>

void import_scenes();


using namespace std;

std::vector<pair<string, Scene*>> scenes;

void import_scenes() {
	scenes.emplace_back("Game", new Game());
	scenes.emplace_back("Lobby", new Lobby());
	scenes.emplace_back("Menu", new Menu());
}
#endif
