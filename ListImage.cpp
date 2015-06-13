#include "ListImage.h"
#include <cmath>

ListImage::ListImage(RosalilaGraphics *paint)
{
    root = NULL;
    this->painter = paint;
    root_scale=0.66;
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
    if(root==NULL)
    {
//        this->scale = scale;
        root = new Nodo(new Step(painter,path));
        float w, h, x, y;
        queryData(root->frame, &w, &h, &x, &y);

        root->frame->setX(painter->screen_width*0.5 - w*0.5);
        root->frame->setY(painter->screen_height - h);
        root->frame->setScale(1);

        return;
    }
    Nodo *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new Nodo(new Step(painter,path));

    Nodo *temp2 = temp->next;

    float w, h, x, y;
    queryData(temp2->frame, &w, &h, &x, &y);

    temp2->frame->setX(painter->screen_width*0.5 - w*0.5*temp->frame->scale*root_scale);
    temp2->frame->setY(temp->frame->getY() - h*temp->frame->scale*root_scale);
    temp2->frame->setScale(temp->frame->scale*root_scale);
}

void ListImage::add(Nodo *nuevo)
{
    if(root==NULL)
    {
        root = nuevo;
        return;
    }
    Nodo *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = nuevo;
}

Nodo* ListImage::pop()
{
    Nodo* temp = root;
    root = temp->next;
    temp->next = NULL;
    return temp;
}

void ListImage::draw(float off_set)
{

    Nodo *tmp = root;
    Nodo *last = root;
    float y_temp=painter->screen_height;
    float scale_temp=1;
    int c = 0;

    while(tmp)
    {
        Step *image = tmp->frame;
        tmp->frame->addY(off_set);

        if(c<8)
        {
            tmp->frame->draw(painter);
            last = tmp;
        }

        tmp = tmp->next;
        c++;
    }

    cout<<"Scale: "<<last->frame->scale<<endl;
    if(last->frame->scale>=0.108468)
    {
         Nodo *n = pop();

         while(last->next!=NULL)
            last=last->next;

         n->frame->init(last->frame);
         add(n);
    }
}

void ListImage::reset()
{
    float s = root->frame->getScale();
    int cont=1;
    Nodo *tmp = root;

    while(tmp->next!=NULL)
    {
        Nodo *tmp2 = tmp->next;
        float ss = pow(s,cont);
        float x = painter->screen_width*0.5 - tmp2->frame->getWidth()*0.5*ss;
        float y = tmp->frame->getY() - tmp2->frame->getHeight()*ss;

        tmp2->frame->init(ss, x, y);
        tmp = tmp->next;
        cont++;
    }
}

void ListImage::flush(float flu)
{
    Nodo *tmp = root;
    Nodo *last = root;
    float y_temp=painter->screen_height;
    float scale_temp=1;
    int c = 0;

    while(tmp)
    {
        Step *image = tmp->frame;
        tmp->frame->addY(flu);

        if(c<8)
        {
            last = tmp;
        }

        tmp = tmp->next;
        c++;
    }

    cout<<"Scale: "<<last->frame->scale<<endl;
    if(last->frame->scale>=0.108468)
    {
         Nodo *n = pop();

         while(last->next!=NULL)
            last=last->next;

         n->frame->init(last->frame);
         add(n);
    }
}
