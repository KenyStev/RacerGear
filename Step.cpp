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
    setX(painter->screen_width*0.5 - width*0.5*scale + off_set_x);
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

void Step::init()
{
//    scale*=0.66;//0.0826539;
//    x=painter->screen_width*0.5 - width*0.5*scale;//621.629;
//    y=y - height*scale;//456.558;

    scale=0.0847309;
    x=621.629;
    y=456.558;
}

void Step::init(double scale, double x, double y)
{
    this->scale=scale;
    this->x=x;
    this->y=y;
}

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
//    cout<<"x: "<<x<<endl;
    cout<<"a: "<<scale<<endl;
    cout<<"off_x: "<<off_set_x<<endl;
    cout<<"x: "<<x<<"y: "<<y<<endl;
//    exit(0);
}

void queryData(Step *s, double *w, double *h, double *x, double *y)
{
    *w = s->getWidth();
    *h = s->getHeight();
    *x = s->getX();
    *y = s->getY();
}
