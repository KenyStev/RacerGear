#include "StatisticsScreen.h"
#include "RaceGear.h"

StatisticsScreen::StatisticsScreen(Game *game)
{
    this->game = game;
    //ctor
}

void StatisticsScreen::show (){
    font = new Font("font.ttf");
    font->setSize(72);
    font->setColor(255,255,255);
    background = game->rosalila_graphics->getTexture(assets_directory+"StaScreen.png");
    mu = game->rosalila_graphics->getTexture(assets_directory+"Menu_UP.png");
    md = game->rosalila_graphics->getTexture(assets_directory+"Menu_DOWN.png");
    menu = new BackButton(1039,188,mu,md,game->rosalila_graphics);
    ru = game->rosalila_graphics->getTexture(assets_directory+"Reiniciar_UP.png");
    rd = game->rosalila_graphics->getTexture(assets_directory+"Reiniciar_DOWN.png");
    reiniciar = new BackButton(1039,264,ru,rd,game->rosalila_graphics);
    car=((RaceGear*)game)->selected_car;
    track=((RaceGear*)game)->getSelectedTrack();
    time=((RaceGear*)game)->time;
    cars[0]= game->rosalila_graphics->getTexture("blue_left.png");
    cars[1]= game->rosalila_graphics->getTexture("gray_left.png");
    cars[2]= game->rosalila_graphics->getTexture("green_left.png");
    cars[3]= game->rosalila_graphics->getTexture("red_left.png");

    carro = cars[0];
    if(car==1){
        carro = cars[1];
    }
    else if(car==2){
        carro = cars[2];
    }
    else if(car==3){
        carro = cars[3];
    }
    ranking = new Scores();
    string num = "";//track[7];
    for(int i=0;i<track.size()-4;i++){
        nombre_pista+=track[i];
        if(i == 7)
            num+=track[i];
    }
    if(num=="2"){
        ranking->seekRLP(2);
    }
    else if(num=="3"){
        ranking->seekRLP(3);
    }
    else if(num=="4"){
        ranking->seekRLP(4);
    }
    else
        ranking->seekRLP(1);

    mi_posicion = ranking->getRLP("");
}
void StatisticsScreen::render (RosalilaGraphics* painter){
    game->rosalila_graphics->draw2DImage(background,
                            background->getWidth(),background->getHeight(),
                            0,0,1,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
    game->rosalila_graphics->draw2DImage(carro,
                            carro->getWidth(),carro->getHeight(),
                            88,355,1,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
    font->drawText(toString(time),316,521);
    font->drawText(toString(mi_posicion),221,608);
    font->drawText("nombre",87,117);
    font->drawText(nombre_pista,463,437);

    if(menu->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
            game->setScreen(((RaceGear*)game)->MENU);
        menu->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());

    if(reiniciar->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
            game->setScreen(((RaceGear*)game)->PLAY);
        reiniciar->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());

}
void StatisticsScreen::pause (){

}
void StatisticsScreen::resume (){

}
void StatisticsScreen::hide (){
    delete font;
//    delete reiniciar;
//    delete menu;
    delete background;
//    delete mu;
//    delete md;
//    delete ru;
//    delete rd;
    delete carro;
    delete ranking;
}
void StatisticsScreen::dispose (){

}

StatisticsScreen::~StatisticsScreen()
{
    delete font;
    delete reiniciar;
    delete menu;
    delete background;
    delete mu;
    delete md;
    delete ru;
    delete rd;
    delete carro;
    delete ranking;
    //dtor
}
