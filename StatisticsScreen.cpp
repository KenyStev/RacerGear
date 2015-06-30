#include "StatisticsScreen.h"
#include "RaceGear.h"

StatisticsScreen::StatisticsScreen(Game *game)
{
    this->game = game;
    //ctor
}

void StatisticsScreen::show (){

    background = game->rosalila_graphics->getTexture(assets_directory+"StaScreen.png");
    mu = game->rosalila_graphics->getTexture(assets_directory+"Menu_UP.png");
    md = game->rosalila_graphics->getTexture(assets_directory+"Menu_DOWN.png");
    menu = new BackButton(1039,188,mu,md,game->rosalila_graphics);
    ru = game->rosalila_graphics->getTexture(assets_directory+"Reiniciar_UP.png");
    rd = game->rosalila_graphics->getTexture(assets_directory+"Reiniciar_DOWN.png");
    reiniciar = new BackButton(1039,264,ru,rd,game->rosalila_graphics);

    cars[0]= game->rosalila_graphics->getTexture(assets_directory+"gray_left.png");
    cars[1]= game->rosalila_graphics->getTexture(assets_directory+"blue_left.png");
    cars[2]= game->rosalila_graphics->getTexture(assets_directory+"green_left.png");
    cars[3]= game->rosalila_graphics->getTexture(assets_directory+"red_left.png");
    car=((RaceGear*)game)->selected_car;
    carro = cars[car];
    name = ((RaceGear*)game)->name_player;
    rts[1]="For Beginners";
    rts[2]="No.1";
    rts[3]="No.2";
    rts[4]="No.3";
    track = rts[((RaceGear*)game)->id_pista];
    time=((RaceGear*)game)->seg;
    ranking = new Scores();
    if(ranking->seekUser(name)>0){
        ranking->seekRLP(((RaceGear*)game)->id_pista);
        mi_posicion= ranking->getRLP(name);
    }else{
        mi_posicion=0;
    }
    estrellas.push_back(game->rosalila_graphics->getTexture(assets_directory+"Estrella.png"));
    estrellas.push_back(game->rosalila_graphics->getTexture(assets_directory+"Estrella2.png"));
    estrellas.push_back(game->rosalila_graphics->getTexture(assets_directory+"Estrella3.png"));
    estrellas.push_back(game->rosalila_graphics->getTexture(assets_directory+"Estrella4.png"));
    estrellas.push_back(game->rosalila_graphics->getTexture(assets_directory+"Estrella5.png"));
    stars=-1;
    font = new Font("font.ttf");
    font->setSize(52);
    font->setColor(255,255,255);
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
                            88,222,1,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
    paintStars(5);
    font->drawText(toString(time),316,470);
    font->drawText(toString(mi_posicion),221,556);
    font->drawText(name,87,117);
    font->drawText(track,463,385);
    int x = game->receiver->getMouse_X();
    int y = game->receiver->getMouse_Y();
    font->drawText(toString(x),0,0);
    font->drawText(toString(y),0,50);

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
////    delete reiniciar;
////    delete menu;
//    delete background;
////    delete mu;
////    delete md;
////    delete ru;
////    delete rd;
//    delete carro;
//    delete ranking;
}
void StatisticsScreen::dispose (){

}

void StatisticsScreen::paintStars(int s){
    if(stars>=0){
        game->rosalila_graphics->draw2DImage(estrellas[stars],
                                estrellas[stars]->getWidth(),estrellas[stars]->getHeight(),
                                74,626,1,
                                0,false,
                                0,0,
                                Color(255,255,255,255),
                                0,0,
                                false);
    }
    if(stars<s-1){
        if(game->rosalila_graphics->frame%40==0){
            stars++;
        }
    }
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
