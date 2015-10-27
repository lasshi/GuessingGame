#ifndef _MENU_HPP
#define _MENU_HPP

#include <iostream>

#include "Engine.hpp"

class Menu : public Scene {
private:
    /* private data */
protected:
    /* protected data */
public:
    /* public data */
    inline Menu () {}

    inline virtual ~Menu () {

    }

    inline void awake() override {
        InetConnection::connectTCP("127.0.0.1", 3000);
        gui->addText("hint", new GUIText(Window::getRenderer(), R::getFont("res/fonts/OpenSans.ttf")));
        gui->addInput("ip", new GUIInput(Window::getRenderer(), R::getFont("res/fonts/OpenSans.ttf")));
        gui->getText("hint")->setX(Camera::getWidth()/2.0f)->setY(Camera::getHeight()/2.0f-30);
        gui->getText("hint")->setAlign(TEXT_ALIGN::CENTER_XY);
        gui->getInput("ip")->setMaxLength(15);
        gui->getInput("ip")->setX(Camera::getWidth()/2.0f-200)->setY(Camera::getHeight()/2.0f+30);
    }

    inline void update(float dt) override {
        if(Input::isKeyPressed(SDLK_RETURN) && gui->getInput("ip")->getText().length() > 2) {
            gui->getInput("ip")->hide();
            gui->getText("hint")->setText("Connecting to: "+gui->getInput("ip")->getText());
            InetConnection::setState(ConnectionState::CONNECTING);
        } else if(InetConnection::m_state == ConnectionState::CONNECTING)
            InetConnection::connectTCP(gui->getInput("ip")->getText(), 3000);
        else if(InetConnection::m_state == ConnectionState::CONNECTED) {
            Engine::startScene("Lobby");
        }
    }

    inline void end() override {

    }

    inline void draw() override {
        if(InetConnection::m_state == ConnectionState::DISCONNECTED) {
            gui->getText("hint")->setText("Enter server IP address")->show();
            gui->getInput("ip")->show();
        } else {
            gui->getInput("ip")->hide();
        }
    }
};

#endif