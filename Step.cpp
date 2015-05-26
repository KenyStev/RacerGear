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

float Step::getRight()
{
    return right;
}

float Step::getLeft()
{
    return left;
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

void Step::setRight(float right)
{
    this->right = right;
}

void Step::setLeft(float left)
{
    this->left = left;
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

void Step::addRight(float right)
{
    this->right += right;
}

void Step::addLeft(float left)
{
    this->left += left;
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
