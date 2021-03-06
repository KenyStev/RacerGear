/**
* Copyright (C) Kevin J. Estevez (kenystev) and Luis C. Isaula (lisaula)
*
* GNU GENERAL PUBLIC LICENSE Version 2
* The licenses for most software are designed to take away your
* freedom to share and change it.  By contrast, the GNU General Public
* License is intended to guarantee your freedom to share and change free
* software--to make sure the software is free for all its users.  This
* General Public License applies to most of the Free Software
* Foundation's software and to any other program whose authors commit to
* using it.
*/

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
    menu = new BackButton(1039,188,mu,md,game->rosalila_graphics,game);
    ru = game->rosalila_graphics->getTexture(assets_directory+"Reiniciar_UP.png");
    rd = game->rosalila_graphics->getTexture(assets_directory+"Reiniciar_DOWN.png");
    reiniciar = new PlayButton(1039,264,ru,rd,game->rosalila_graphics,game);

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
    s=0;
    font = new Font("font.ttf");
    font->setSize(52);
    font->setColor(255,255,255);
    s=calculateStars(time,((RaceGear*)game)->id_pista);
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
    paintStars(s);
    font->drawText(toString(time),316,470);
    font->drawText(toString(mi_posicion),221,556);
    font->drawText(name,87,117);
    font->drawText(track,463,385);

    menu->update(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    menu->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());

    reiniciar->update(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    reiniciar->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());

}
void StatisticsScreen::pause (){

}
void StatisticsScreen::resume (){

}
void StatisticsScreen::hide (){

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
        if(game->rosalila_graphics->frame%50==0){
            stars++;
        }
    }
}

int StatisticsScreen::calculateStars(int seg, int pista){
    if(pista==1){
        switch (seg)
        {
            case 1 ... 220:
                return 5;
            case 221 ... 254:
                return 4;
            case 255 ... 280:
                return 3;
            case 281 ... 294:
                return 2;
            default:
                return 1;
        }
    }else if(pista == 2){
        switch (seg)
        {
            case 1 ... 100:
                return 5;
            case 101 ... 115:
                return 4;
            case 116 ... 128:
                return 3;
            case 129 ... 135:
                return 2;
            default:
                return 1;
        }
    }else if(pista ==3){
        switch (seg)
        {
            case 1 ... 185:
                return 5;
            case 186 ... 212:
                return 4;
            case 213 ... 233:
                return 3;
            case 234 ... 244:
                return 2;
            default:
                return 1;
        }
    }else if(pista ==4){
        switch (seg)
        {
            case 1 ... 85:
                return 5;
            case 86 ... 95:
                return 4;
            case 96 ... 104:
                return 3;
            case 105 ... 110:
                return 2;
            default:
                return 1;
        }
    }
    return 0;
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
}
