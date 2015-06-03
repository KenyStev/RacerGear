#include "ListImage.h"
#include <cmath>

ListImage::ListImage(RosalilaGraphics *paint)
{
    root = NULL;
    this->painter = paint;
    root_scale=0.66;
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
//    float scales[7] = {1, 0.66, 0.44, 0.29, 0.19, 0.125, 0.082};
//    float scales[7] = {1.2, 1.2*0.66, 1.2*0.44, 1.2*0.29, 1.2*0.19, 1.2*0.125, 1.2*0.082};
//    scale=1;
//    float scale_before=scale;

    Nodo *tmp = root;
    Nodo *last = root;
    float y_temp=painter->screen_height;
    float scale_temp=1;
    int c = 0;

    //try_init
//    for(int i=0; i<8; i+=1.0)
//    {
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
//    }
    //try_done
//    Nodo *last = root;
//    while(last->next!=NULL)
//        last=last->next;

//    Nodo *last = root;
//    int c=0;
//    while(last->next!=NULL && c<7)
//    {
//        last=last->next;
//        c++;
//    }


//    Nodo *last = NULL;
//    for(int i=0; i<8; i++)
//    {
//        last = last->next;
//    }
    cout<<"Scale: "<<last->frame->scale<<endl;
    if(last->frame->scale>=0.108468)//0.14981)//0.0631744)
//    if(root->frame->getY()>=656.999)
    {
//        last->frame->init();
         Nodo *n = pop();

         while(last->next!=NULL)
            last=last->next;

         n->frame->init(last->frame);
         add(n);
//         reset();
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
    //    float scales[7] = {1, 0.66, 0.44, 0.29, 0.19, 0.125, 0.082};
//    float scales[7] = {1.2, 1.2*0.66, 1.2*0.44, 1.2*0.29, 1.2*0.19, 1.2*0.125, 1.2*0.082};
//    scale=1;
//    float scale_before=scale;

    Nodo *tmp = root;
    Nodo *last = root;
    float y_temp=painter->screen_height;
    float scale_temp=1;
    int c = 0;

    //try_init
//    for(int i=0; i<8; i+=1.0)
//    {
    while(tmp)
    {
        Step *image = tmp->frame;
        tmp->frame->addY(flu);

        if(c<8)
        {
//            tmp->frame->draw(painter);
            last = tmp;
        }

        tmp = tmp->next;
        c++;
    }
//    }
    //try_done
//    Nodo *last = root;
//    while(last->next!=NULL)
//        last=last->next;

//    Nodo *last = root;
//    int c=0;
//    while(last->next!=NULL && c<7)
//    {
//        last=last->next;
//        c++;
//    }


//    Nodo *last = NULL;
//    for(int i=0; i<8; i++)
//    {
//        last = last->next;
//    }
    cout<<"Scale: "<<last->frame->scale<<endl;
    if(last->frame->scale>=0.108468)//0.14981)//0.0631744)
//    if(root->frame->getY()>=656.999)
    {
//        last->frame->init();
         Nodo *n = pop();

         while(last->next!=NULL)
            last=last->next;

         n->frame->init(last->frame);
         add(n);
//         reset();
    }
}
