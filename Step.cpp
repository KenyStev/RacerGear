#include "Step.h"


Step::Step(RosalilaGraphics* painter, std::string path)
{
    next = NULL;

    this->painter = painter;

    Image* img = painter->getTexture(path);
    this->setTexture(img->getTexture());
    this->setWidth(img->getWidth());
    this->setHeight(img->getHeight());
    this->setX(0);
    this->setY(0);
    this->setOff_X(0);
    this->setOff_Y(0);
    this->setScale(1);
}

Step::Step(RosalilaGraphics* painter, Image *img)
{
    next = NULL;
    this->painter = painter;
    this->setTexture(img->getTexture());
    this->setWidth(img->getWidth());
    this->setHeight(img->getHeight());
    this->setX(0);
    this->setY(0);
    this->setOff_X(0);
    this->setOff_Y(0);
    this->setScale(1);
    hit_left=false;
    hit_right=false;
    hit_center=false;
    isMeta=false;
    borders=false;
}

Step::~Step()
{
    glDeleteTextures( 1, &texture );
}

double Step::getX()
{
    return x;
}

double Step::getY()
{
    return y;
}

double Step::getScale()
{
    return scale;
}

double Step::getOff_X()
{
    return off_set_x;
}

double Step::getOff_Y()
{
    return off_set_y;
}

void Step::setX(double x)
{
    this->x = x;
}

void Step::setY(double y)
{
    this->y = y;
}

void Step::setScale(double scale)
{
    this->scale = scale;
}

void Step::setOff_X(double off_set_x)
{
    this->off_set_x = off_set_x;
}

void Step::setOff_Y(double off_set_y)
{
    this->off_set_y = off_set_y;
}

void Step::addX(double x)
{
    this->x += x;
}

void Step::addY(double y)
{
//    scale = ((this->y) - 432.27)/223.92; //no borrar
    scale = ((this->y) - 440.27)/220.92;
    this->y+=y*scale;
    rect_left.x=off_set_x;
    rect_right.x=getWidth() - rect_right.w + off_set_x;
    rect_center.x=getWidth()*0.5 - rect_center.w*0.3 + off_set_x;

    border_left.x = getX() - border_left.w*3.5 + off_set_x;
    border_right.x = getX() + getWidth()*scale + border_right.w*1.5 + off_set_x;

    setX(painter->screen_width*0.5 - width*0.5*scale + off_set_x);

    border_left.y = getY();
    border_right.y = getY();

    rect_left.y=getY();
    rect_right.y=getY();
    rect_center.y=getY();
}

void Step::addScale(double scale)
{
    this->scale += scale;
}

void Step::addOff_X(double off_set_x)
{
    this->off_set_x += off_set_x;
}

void Step::addOff_Y(double off_set_y)
{
    this->off_set_y += off_set_y;
}

void Step::setHit_Left(bool hit_left)
{
    this->hit_left=hit_left;
    rect_left.x = getX();
    rect_left.y = getY();
    rect_left.w = getWidth()*0.35;
    rect_left.h = getHeight()*0.9;
//    hurt=8;
}

void Step::setHit_Right(bool hit_right)
{
    this->hit_right=hit_right;
    rect_right.y = getY();
    rect_right.w = getWidth()*0.25;
    rect_right.x = getX() + getWidth()*0.65;
    rect_right.h = getHeight()*0.9;
//    hurt=8;
}

void Step::setHit_Center(bool hit_center)
{
    this->hit_center=hit_center;
    rect_center.y = getY();
    rect_center.w = getWidth()*0.2;
    rect_center.x = getWidth()*0.5 - rect_center.w*0.5;
    rect_center.h = getHeight()*0.8;
//    hurt=8;
}

void Step::setBorders()
{
    border_left.y = getY();
    border_left.w = getWidth()*0.1;
    border_left.x = getX() - border_left.w;
    border_left.h = getHeight();

    border_right.y = getY();
    border_right.w = getWidth()*0.1;
    border_right.x = getX() + getWidth() + border_right.w;
    border_right.h = getHeight();

    borders=true;
}

//void Step::init()
//{
////    scale*=0.66;//0.0826539;
////    x=painter->screen_width*0.5 - width*0.5*scale;//621.629;
////    y=y - height*scale;//456.558;
//
//    scale=0.0847309;
//    x=621.629;
//    y=456.558;
//}
//
//void Step::init(double scale, double x, double y)
//{
//    this->scale=scale;
//    this->x=x;
//    this->y=y;
//}

void Step::init(Step *tmp)
{
    scale = tmp->scale*0.66;//0.0811825;//*0.66;//0.0826539;
    x=painter->screen_width*0.5 - width*0.5*scale;//621.629;
    y=tmp->y - height*scale;//456.558;
}

void Step::draw(RosalilaGraphics* painter)
{

    painter->draw2DImage(   this,
                            this->getWidth(),this->getHeight(),
                            x,y,
                            scale,
                            0,
                            false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
//    if(hit_left)
//        painter->drawRectangle(rect_left.x,rect_left.y,rect_left.w,rect_left.h,
//                            0,255,0,0,100,false);
//    if(hit_right)
//        painter->drawRectangle(rect_right.x,rect_right.y,rect_right.w,rect_right.h,
//                            0,255,0,0,100,false);
//    if(hit_center)
//        painter->drawRectangle(rect_center.x,rect_center.y,rect_center.w,rect_center.h,
//                            0,255,0,0,100,false);

//    draw_borders
//    if(borders)
//    {
//        painter->drawRectangle(border_left.x,border_left.y,border_left.w,border_left.h,
//                                0,255,0,0,100,false);
//        painter->drawRectangle(border_right.x,border_right.y,border_right.w,border_right.h,
//                                0,255,0,0,100,false);
//    }
//    cout<<"x: "<<x<<endl;
//    exit(0);
}

void queryData(Step *s, double *w, double *h, double *x, double *y)
{
    *w = s->getWidth();
    *h = s->getHeight();
    *x = s->getX();
    *y = s->getY();
}
