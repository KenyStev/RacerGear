#include "PlayScreen.h"
#include "RaceGear.h"

PlayScreen::PlayScreen(Game *game)
{
    this->game = game;
    loadCars("cars.xml");
    player_car = cars[0];//new Car(game->rosalila_graphics);
    track = new Pista(player_car, game->rosalila_graphics, game->receiver,"pista_1.xml");

    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(100,100,bu,bd,game->rosalila_graphics);
    track->init();
}

PlayScreen::~PlayScreen()
{
    //dtor
}

void PlayScreen::show ()
{
//    loadCars("cars.xml");
    player_car = cars[((RaceGear*)game)->selected_car];
    //player_car = new Car(game->rosalila_graphics);
    track = new Pista(player_car, game->rosalila_graphics, game->receiver,"pista_1.xml");

    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(100,100,bu,bd,game->rosalila_graphics);
    track->init();
}

void PlayScreen::render (RosalilaGraphics*)
{
    track->logica();
    track->draw();

//    back_button->update(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    if(back_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
        game->setScreen(((RaceGear*)game)->MENU);
    back_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
}
//        void resize (int width, int height);
void PlayScreen::pause ()
{

}

void PlayScreen::resume ()
{

}

void PlayScreen::hide ()
{
    track->clear();
//    delete player_car;
//    delete track;
//    delete bu;
//    delete bd;
//    delete back_button;
}

void PlayScreen::dispose ()
{

}

void PlayScreen::loadCars(string path)
{
    TiXmlDocument doc((assets_directory+path).c_str());
    doc.LoadFile();

    TiXmlNode *Cars = doc.FirstChild("Cars");
    int i=0;
    for(TiXmlNode *car = Cars->FirstChild("car");
        car!=NULL;
        car = car->NextSibling("car"),i++)
        {
            cars[i] = new Car(game->rosalila_graphics);
            cars[i]->v_max = atof(car->ToElement()->Attribute("velocity"));
            cars[i]->a = atof(car->ToElement()->Attribute("aceleration"));
            cars[i]->CHANGE_TURN = atof(car->ToElement()->Attribute("turn"));
        }
}
