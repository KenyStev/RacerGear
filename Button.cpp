#include "Button.h"

Button::Button(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter)
{
    x=x_position;
    y=y_position;
    clickLeft=false;
    this->painter = painter;
//    this->receiver=receiver;
    this->img_up = up;
    this->img_dwn= down;
    this->mouse_x=0;
    this->mouse_y=0;
    this->rect_img.x= x_position;
    this->rect_img.y= y_position;
    this->rect_img.w= img_up->getWidth();
    this->rect_img.h= img_up->getHeight();

    this->xMinima = rect_img.x;
    this->yMaxima = rect_img.y+rect_img.h;
	this->xMaxima = rect_img.x + rect_img.w;
    this->yMinima = rect_img.y;
    //ctor
}

Button::Button(){

}

void Button::update(int M_x, int M_y,bool click){
    if(sePulsaBoton(M_x,M_y,click)){
        clickLeft=false;
        funcionamiento();

    }
}

bool Button::clicked(int M_x, int M_y, bool click){
    if(sePulsaBoton(M_x,M_y,click)){
        return true;
    }
    return false;
}

bool Button::sePulsaBoton(int M_x, int M_y, bool click){
    setMouse(M_x,M_y,click);
    return clickLeft && mouse_x >= xMinima && mouse_x <= xMaxima && // Devuelve true si se pulsa dentro de los límites
			   mouse_y >= yMinima && mouse_y <= yMaxima;
}
void Button::setMouse(int M_x, int M_y, bool click){

    mouse_x=M_x;
    mouse_y = M_y;
    clickLeft=click;
}
void Button:: draw(int M_x, int M_y, bool click){
    if(mouseEncima(M_x,M_y,click))
    painter->draw2DImage(img_dwn,img_dwn->getWidth(),img_up->getHeight(),x,y,1,0,false,0,0,Color(255,255,255,255),0,0,false);
    else
    painter->draw2DImage(img_up,img_up->getWidth(),img_up->getHeight(),x,y,1,0,false,0,0,Color(255,255,255,255),0,0,false);
}

bool Button::mouseEncima(int M_x, int M_y, bool click){
    setMouse(M_x, M_y,click);
    return mouse_x >= xMinima && mouse_x <= xMaxima && // Devuelve true si se pulsa dentro de los límites
			   mouse_y >= yMinima && mouse_y <= yMaxima;
}
Button::~Button()
{
    //dtor
    delete painter;
    delete img_up;
    delete img_dwn;
    delete &rect_img;
}
