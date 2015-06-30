#include "SelectScreen.h"
#include "RaceGear.h"

SelectScreen::SelectScreen(Game *game)
{
    this->game=game;
}

SelectScreen::~SelectScreen()
{
    delete play_button;
    delete &buttons;
    delete &tracks;
    //dtor
    dispose();

}

void SelectScreen::show ()
{
     background = game->rosalila_graphics->getTexture(assets_directory+"Selec.png");
    play_button = new PlayButton(1004,501,game->rosalila_graphics->getTexture(assets_directory+"PLAY_UP.png"),
                                    game->rosalila_graphics->getTexture(assets_directory+"PLAY_DWN.png"),
                                    game->rosalila_graphics,game);
    name="";
    display = new Font("font.ttf");
    nuevo = new Font("font.ttf");
    nuevo->setColor(213,255,230);
    nuevo->setSize(48);
    display->setColor(255,255,0);
    display->setSize(48);

    //load cars
    loadCars();

    //load tracks
    loadTracks();
    cars[0]= game->rosalila_graphics->getTexture(assets_directory+"gray.png");
    cars[1]= game->rosalila_graphics->getTexture(assets_directory+"blue.png");
    cars[2]= game->rosalila_graphics->getTexture(assets_directory+"green.png");
    cars[3]= game->rosalila_graphics->getTexture(assets_directory+"red.png");

    rts[1]="Racetrack For Beginners";
    rts[2]="Racetrack No.1";
    rts[3]="Racetrack No.2";
    rts[4]="Racetrack No.3";

}

void SelectScreen::render (RosalilaGraphics*p)
{
    game->rosalila_graphics->draw2DImage(background,
                            background->getWidth(),background->getHeight(),
                            0,0,1,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
    //draw cars
    for(int i=0;i<buttons.size();i++)
    {
        if(buttons[i]->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
                    ((RaceGear*)game)->selected_car=buttons[i]->num;
        buttons[i]->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    }
    car_chosed=cars[((RaceGear*)game)->selected_car];
     game->rosalila_graphics->draw2DImage(car_chosed,
                            car_chosed->getWidth(),car_chosed->getHeight(),
                            968,251,1,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);

    //draw track
    for(int i=0;i<tracks.size();i++)
    {
        if(tracks[i]->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
        {
            ((RaceGear*)game)->selected_track=tracks[i]->name;
            ((RaceGear*)game)->id_pista=tracks[i]->num_pista;
        }
        tracks[i]->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    }

    if(play_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
                    game->setScreen(((RaceGear*)game)->PLAY);

    play_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());


    display->drawText(name,888,410);
    nuevo->drawText(rts[((RaceGear*)game)->id_pista],790,185);
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
            tracks.push_back(new TrackButton(i+1,path_file,350,i*182,game->rosalila_graphics->getTexture(assets_directory+path),
                                game->rosalila_graphics->getTexture(assets_directory+path_s),
                                game->rosalila_graphics));
            cout<<path_file<<"   "<<path<<"   "<<path_s<<endl;
        }
}

void SelectScreen::catchName()
{
    if(name.size()<15){
        for(int i=0; i<26;i++)
        {
            if(game->receiver->isKeyPressed(i+97))
            {
                char c = i+65;
                name+=c;
            }
            if(game->receiver->isKeyPressed(SDLK_SPACE)){
                name +=" ";
            }
        }
    }
    if(game->receiver->isKeyPressed(SDLK_BACKSPACE)){
                name ="";
    }
}
