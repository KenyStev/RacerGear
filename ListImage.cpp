#include "ListImage.h"
#include <cmath>

ListImage::ListImage(RosalilaGraphics *paint)
{
    root = NULL;
    this->painter = paint;
    root_scale=0.66;
    max_draw = 13;

    texturas["Meta"] = new Step(painter,assets_directory+"Meta.png");
    texturas["rect"] = new Step(painter,assets_directory+"rect.png");
    texturas["puas_left"] = new Step(painter,assets_directory+"puas_left.png");
    texturas["puas_right"] = new Step(painter,assets_directory+"puas_right.png");
    texturas["puas_center"] = new Step(painter,assets_directory+"puas_center.png");
    texturas["flags"] = new Step(painter,assets_directory+"flags.png");
}
ListImage::ListImage()
{
    root = NULL;
    this->painter = NULL;
    root_scale=0;
}

ListImage::~ListImage()
{
    delete painter;
    delete root;
}

void ListImage::add(std::string path)
{
    Step *newStep = new Step(painter,texturas[path]);
    if(strcmp(path.c_str(),"puas_left")==0)
        newStep->setHit_Left(true);
    if(strcmp(path.c_str(),"puas_right")==0)
        newStep->setHit_Right(true);
    if(strcmp(path.c_str(),"puas_center")==0)//cout<<"-->>>>>>>>>>>>>>>>>>>paso el if "<<endl;
        newStep->setHit_Center(true);
    if(root==NULL)
    {
        root = newStep;//new Step(painter,texturas[path]);//path);
        double w, h, x, y;
        queryData(root, &w, &h, &x, &y);

        root->setX(painter->screen_width*0.5 - w*0.5);
        root->setY(painter->screen_height - h);
        return;
    }
    Step *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newStep;//new Step(painter,texturas[path]);//path);
}

void ListImage::add(Step *nuevo)
{
    if(root==NULL)
    {
        root = nuevo;
        return;
    }
    Step *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = nuevo;
}

Step* ListImage::pop()
{
    Step* temp = root;
    root = temp->next;
    temp->next = NULL;
    return temp;
}

void ListImage::draw(Car*car,double off_set_x, double off_set_y)
{
    Step *tmp = root;
    while(tmp)
    {
        tmp->addOff_X(off_set_x);
        tmp = tmp->next;
    }
    draw(car,root,root->next,0,off_set_x,off_set_y);
}

void ListImage::draw(double off_set_x, double off_set_y)
{
    Step *tmp = root;
    while(tmp)
    {
        tmp->addOff_X(off_set_x);
        tmp = tmp->next;
    }
    draw(NULL,root,root->next,0,off_set_x,off_set_y);
}

void ListImage::draw(Car*car,Step*anterior,Step*actual,int c,double off_set_x, double off_set_y)
{
    if(c==max_draw)
    {
        if(anterior->scale>=0.0563964)//0.108468)
        {
            add(pop());
        }
        return;
    }
    checkColosions(car,anterior);
    anterior->addY(off_set_y);
    anterior->draw(painter);
    actual->init(anterior);
    draw(car,actual,actual->next,c+1,off_set_x,off_set_y);
}

void ListImage::checkColosions(Car*car,Step *actual)
{
    if(car!=NULL)
    {
        SDL_Rect r, c=car->wheels;
        if(actual->hit_center)
        {
            r = actual->rect_center;
            if(hitboxCollision(r.x,r.y,r.w,r.h,0,
                                c.x,c.y,c.w,c.h,0))
            {
                car->v=actual->hurt;//car->a*2;
            }
        }
        if(actual->hit_left)
        {
            r = actual->rect_left;
            if(hitboxCollision(r.x,r.y,r.w,r.h,0,
                                c.x,c.y,c.w,c.h,0))
            {
                car->v=actual->hurt;//car->a*2;
            }
        }
        if(actual->hit_right)
        {
            r = actual->rect_right;
            if(hitboxCollision(r.x,r.y,r.w,r.h,0,
                                c.x,c.y,c.w,c.h,0))
            {
                car->v=actual->hurt;//car->a*2;
            }
        }
    }
}

void ListImage::clear()
{
    root=NULL;
}
