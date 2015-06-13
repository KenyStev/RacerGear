#include "Step.h"

Step::Step(RosalilaGraphics* painter, std::string path)
{
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

    //probando
//    delete img;
}

Step::~Step()
{
    glDeleteTextures( 1, &texture );
}

float Step::getX()
{
    return x;
}

float Step::getY()
{
    return y;
}

float Step::getScale()
{
    return scale;
}

float Step::getOff_X()
{
    return off_set_x;
}

float Step::getOff_Y()
{
    return off_set_y;
}

void Step::setX(float x)
{
    this->x = x;
}

void Step::setY(float y)
{
    this->y = y;
//    scale = (this->y - 432.27)/223.92;
}

void Step::setScale(float scale)
{
    this->scale = scale;
}

void Step::setOff_X(float off_set_x)
{
    this->off_set_x = off_set_x;
}

void Step::setOff_Y(float off_set_y)
{
    this->off_set_y = off_set_y;
}

void Step::addX(float x)
{
    this->x += x;
}

void Step::addY(float y)
{
    scale = ((this->y) - 432.27)/223.92;
        this->y+=y*scale;
        setX(painter->screen_width*0.5 - width*0.5*scale);
}

void Step::addScale(float scale)
{
    this->scale += scale;
}

void Step::addOff_X(float off_set_x)
{
    this->off_set_x += off_set_x;
}

void Step::addOff_Y(float off_set_y)
{
    this->off_set_y += off_set_y;
}

void Step::init()
{
    scale*=0.66;//0.0826539;
    x=painter->screen_width*0.5 - width*0.5*scale;//621.629;
    y=y - height*scale;//456.558;
}

void Step::init(float scale, float x, float y)
{
    this->scale=scale;
    this->x=x;
    this->y=y;
}

void Step::init(Step *tmp)
{
    scale = tmp->scale*0.66;//0.0826539;
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
                            true,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
//    cout<<"x: "<<x<<endl;
    cout<<"a: "<<scale<<endl;
//    exit(0);
}

void queryData(Step *s, float *w, float *h, float *x, float *y)
{
    *w = s->getWidth();
    *h = s->getHeight();
    *x = s->getX();
    *y = s->getY();
}
