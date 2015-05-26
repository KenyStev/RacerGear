#include "Step.h"

Step::Step(RosalilaGraphics* painter, std::string path)
{
    Image* img = painter->getTexture(path);
    this->setTexture(img->getTexture());
    this->setWidth(img->getWidth());
    this->setHeight(img->getHeight());

    //probando
    delete img;
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
    this->y += y;
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
}
