#include "PlayScreen.h"
#include "RaceGear.h"

PlayScreen::PlayScreen(Game *game)
{
    this->game = game;
    loadCars("cars.xml");
//    player_car = cars[0];//new Car(game->rosalila_graphics);
//    track = new Pista(player_car, game->rosalila_graphics, game->receiver,"pista_1.xml");
//
//    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
//    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
//    back_button = new BackButton(100,100,bu,bd,game->rosalila_graphics);
//    track->init();
}

PlayScreen::~PlayScreen()
{
    delete track;
    delete back_button;
    delete background;
    delete bu;
    delete bd;
    delete track;
    delete player_car;
}

void PlayScreen::show ()
{
    time=0;
    scr=new Scores();
    finish=false;
//    loadCars("cars.xml");
    player_car = cars[((RaceGear*)game)->selected_car];
    player_car->initCar();

    //player_car = new Car(game->rosalila_graphics);
//    track = new Pista(player_car, game->rosalila_graphics, game->receiver,"pista_01.xml");
    track = new Pista(player_car, game->rosalila_graphics, game->receiver,((RaceGear*)game)->selected_track);

    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(20,18,bu,bd,game->rosalila_graphics);
    track->init();
    n =((RaceGear*)game)->name_player;
    if(scr->seekUser(n)<0){
        notexitst=-1;
        //scr->createNewUserBinary(n);
    }
    num_rt = ((RaceGear*)game)->id_pista;
    display_laps = new Font("airstrikeplat.ttf");
    display_laps->setSize(30);
    display_laps->setColor(0,0,0);
}

void PlayScreen::render (RosalilaGraphics*p)
{
    track->draw();
    if(!track->getLose()){
        track->logica();
    }

    if(track->laps==0)
    {
        finish=true;
        ((RaceGear*)game)->seg=track->seg;
        //exit(11);
       if(game->rosalila_graphics->frame%100==0)
            game->setScreen(((RaceGear*)game)->STATISTICS);

    }
//    back_button->update(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    if(back_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
        game->setScreen(((RaceGear*)game)->MENU);
    back_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());

    display_laps->drawText("Laps: "+toString(track->laps),117,87);

//    int x = game->receiver->getMouse_X();
//    int y = game->receiver->getMouse_Y();
//    p->drawText(toString(x),0,0);
//    p->drawText(toString(y),0,50);
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
    time = ((RaceGear*)game)->seg;
    cout<<notexitst<<endl;
    cout<<n<<endl;
    cout<<((RaceGear*)game)->selected_car<<endl;
    cout<<num_rt<<endl;
    cout<<time<<endl;
    cout<<"-------------------AQUI"<<endl;
//    if(finish){
//        scr->setPuntosToPista(n,time,num_rt);
//    }
//    //scr->setPuntosToPista(n,time,num_rt);
//    track->clear();
//    delete background;
//    delete scr;
//    delete track;
//    delete player_car;
//    delete cars[0];
//    delete cars[1];
//    delete cars[2];
//    delete cars[3];
//    delete &cars;
}

void PlayScreen::dispose ()
{
    delete player_car;
    delete track;
    delete bu;
    delete bd;
    delete back_button;
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
            cars[i] = new Car(game->rosalila_graphics,car->ToElement()->Attribute("image"));
            cars[i]->maximum = atof(car->ToElement()->Attribute("velocity"));
            cars[i]->a = atof(car->ToElement()->Attribute("aceleration"));
            cars[i]->CHANGE_TURN = atof(car->ToElement()->Attribute("turn"));
        }
}
