#include "SelectScreen.h"
#include "RaceGear.h"

SelectScreen::SelectScreen(Game *game)
{
    this->game=game;
}

SelectScreen::~SelectScreen()
{
    dispose();
}

void SelectScreen::show ()
{
    play_button = new PlayButton(1162,712,game->rosalila_graphics->getTexture(assets_directory+"PLAY_UP.png"),
                                    game->rosalila_graphics->getTexture(assets_directory+"PLAY_DWN.png"),
                                    game->rosalila_graphics,game);
    name="";
    display = new Font("font.ttf");

    //load cars
    loadCars();

    //load tracks
    loadTracks();
}

void SelectScreen::render (RosalilaGraphics*p)
{
    //draw cars
    for(int i=0;i<buttons.size();i++)
    {
        if(buttons[i]->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
                    ((RaceGear*)game)->selected_car=buttons[i]->num;
        buttons[i]->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    }

    //draw track
    for(int i=0;i<tracks.size();i++)
    {
        if(tracks[i]->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
                    ((RaceGear*)game)->selected_track=tracks[i]->name;
        tracks[i]->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    }

    if(play_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
                    game->setScreen(((RaceGear*)game)->PLAY);

    play_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());

    int x = game->receiver->getMouse_X();
    int y = game->receiver->getMouse_Y();
    display->drawText(toString(x),0,0);
    display->drawText(toString(y),0,50);

    display->drawText("Su Nombre:",830,200);
    display->drawText(name,830,217);
    catchName();
}

void SelectScreen::pause ()
{

}

void SelectScreen::resume ()
{

}

void SelectScreen::hide ()
{
    ((RaceGear*)game)->name_player=name;
}

void SelectScreen::dispose ()
{
    delete play_button;
    for(int i=0;i<buttons.size();i++)
        delete buttons[i];
    for(int i=0;i<tracks.size();i++)
        delete tracks[i];
}

void SelectScreen::loadCars()
{
    TiXmlDocument doc((assets_directory+"cars.xml").c_str());
    doc.LoadFile();

    TiXmlNode *Cars = doc.FirstChild("Cars");

    int i=0;
    for(TiXmlNode *car = Cars->FirstChild("car");
        car!=NULL;
        car = car->NextSibling("car"),i++)
        {
            string path = car->ToElement()->Attribute("image");
            string path_s = path+"_s.png";
            path+=".png";
            buttons.push_back(new CarButton(i,0,i*182,game->rosalila_graphics->getTexture(assets_directory+path),
                                game->rosalila_graphics->getTexture(assets_directory+path_s),
                                game->rosalila_graphics));
        }
}

void SelectScreen::loadTracks()
{
    TiXmlDocument doc((assets_directory+"pistas.xml").c_str());
    doc.LoadFile();

    TiXmlNode *Track = doc.FirstChild("Pistas");

    int i=0;
    for(TiXmlNode *track = Track->FirstChild("pista");
        track!=NULL;
        track = track->NextSibling("pista"),i++)
        {
            string path_file = track->ToElement()->Attribute("path");
            string path = track->ToElement()->Attribute("button");
            string path_s = path+"_s.png";
            path+=".png";
            tracks.push_back(new TrackButton(path_file,350,i*182,game->rosalila_graphics->getTexture(assets_directory+path),
                                game->rosalila_graphics->getTexture(assets_directory+path_s),
                                game->rosalila_graphics));
            cout<<path_file<<"   "<<path<<"   "<<path_s<<endl;
        }
}

void SelectScreen::catchName()
{

    for(int i=0; i<26;i++)
    {
        if(game->receiver->isKeyPressed(i+97))
        {
            char c = i+65;
            name+=c;
        }
    }
}
