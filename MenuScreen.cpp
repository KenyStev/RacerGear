#include "MenuScreen.h"
#include "RaceGear.h"

MenuScreen::MenuScreen(Game*game)
{
    this->game=game;
}

MenuScreen::~MenuScreen()
{
    //dtor
}

void MenuScreen::show ()
{
        //Fondo init
        fondo= game->rosalila_graphics->getTexture(assets_directory+"Menu.png");
        //Play button init
        pu = game->rosalila_graphics->getTexture(assets_directory+"PLAY_UP.png");
        pd = game->rosalila_graphics->getTexture(assets_directory+"PLAY_DWN.png");
        centro_x=game->rosalila_graphics->screen_width/2-(pu->getWidth()/2);
        centro_y=game->rosalila_graphics->screen_height/2-(pu->getHeight()/2);
        Pb = new PlayButton(centro_x,centro_y-100,pu,pd,game->rosalila_graphics, this->game);
        //Instrctions Button init
        iu = game->rosalila_graphics->getTexture(assets_directory+"INSTR_UP.png");
        id = game->rosalila_graphics->getTexture(assets_directory+"INSTR_DWN.png");
        centro_x=game->rosalila_graphics->screen_width/2-(iu->getWidth()/2);
        centro_y=game->rosalila_graphics->screen_height/2-(iu->getHeight()/2);
        Ib = new InstrButton(centro_x,centro_y,iu,id,game->rosalila_graphics,this->game);
        //Ranking Button init
        ru = game->rosalila_graphics->getTexture(assets_directory+"RANK_UP.png");
        rd = game->rosalila_graphics->getTexture(assets_directory+"RANK_DWN.png");
        centro_x=game->rosalila_graphics->screen_width/2-(ru->getWidth()/2);
        centro_y=game->rosalila_graphics->screen_height/2-(ru->getHeight()/2);
        Rb = new RankButton(centro_x,centro_y+100,ru,rd,game->rosalila_graphics,this->game);
        //Exit Button init
        eu = game->rosalila_graphics->getTexture(assets_directory+"EXIT_UP.png");
        ed = game->rosalila_graphics->getTexture(assets_directory+"EXIT_DWN.png");
        centro_x=game->rosalila_graphics->screen_width/2-(eu->getWidth()/2);
        centro_y=game->rosalila_graphics->screen_height/2-(eu->getHeight()/2);
        Eb = new ExitButton(centro_x,centro_y+200,eu,ed,game->rosalila_graphics);
        mouse_x=0;
        mouse_y=0;
        click=false;

}

void MenuScreen::render (RosalilaGraphics*painter)
{
    update();
    painter->draw2DImage(fondo,fondo->getWidth(),fondo->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
    mouse_x = game->receiver->getMouse_X();
    mouse_y = game->receiver->getMouse_Y();
    click = game->receiver->isLeftClickDown();
    Pb->draw(mouse_x,mouse_y,click);
    Ib->draw(mouse_x,mouse_y,click);
    Rb->draw(mouse_x,mouse_y,click);
    Eb->draw(mouse_x,mouse_y,click);
}
//        void resize (int width, int height);
void MenuScreen::pause ()
{

}

void MenuScreen::resume ()
{

}
void MenuScreen::hide ()
{

}

void MenuScreen::dispose ()
{

}

void MenuScreen::update(){
        mouse_x = game->receiver->getMouse_X();
        mouse_y = game->receiver->getMouse_Y();
        click = game->receiver->isLeftClickDown();
//        Pb->update(mouse_x,mouse_y,click);
        if(Pb->clicked(mouse_x,mouse_y,click)){
            game->setScreen(((RaceGear*)game)->SELECT);//new PlayScreen(game));
        }
        Ib->update(mouse_x,mouse_y,click);
        Rb->update(mouse_x,mouse_y,click);
        Eb->update(mouse_x,mouse_y,click);
}
