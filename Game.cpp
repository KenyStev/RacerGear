#include "Game.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"

Game::Game()
{
    screen=NULL;

    //Input receiver initialization
    receiver = new Receiver();

    //Graphics initialization
    rosalila_graphics = new RosalilaGraphics();
    rosalila_graphics->video(rosalila_graphics);
}

Game::~Game()
{
    //dtor
}

void Game::dispose()
{
    if (screen != NULL) screen->hide();
}

void Game::pause()
{
    if (screen != NULL) screen->pause();
}

void Game::resume()
{
    if (screen != NULL) screen->resume();
}

void Game::render()
{
    if (screen != NULL) screen->render(rosalila_graphics);
    receiver->updateInputs();
    rosalila_graphics->updateScreen();
    if(receiver->isKeyDown(SDLK_ESCAPE))
        exit(0);
}

//void Game::setScreen(std::string name)
//{
//
//}

void Game::setScreen(Screen *screen)
{
    if (this->screen != NULL) this->screen->hide();
        this->screen = screen;
        if (this->screen != NULL) {
            this->screen->show();
    }
}

Screen* Game::getScreen()
{
    return screen;
}
