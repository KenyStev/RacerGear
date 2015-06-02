#include "ListImage.h"
#include <cmath>

ListImage::ListImage(RosalilaGraphics *paint)
{
    root = NULL;
    this->painter = paint;
}

ListImage::~ListImage()
{
    delete painter;
    delete root;
}

void ListImage::add(std::string path, float scale)
{
    if(root==NULL)
    {
        root = new Nodo(new Step(painter,path));
        float w, h, x, y;
        queryData(root->frame, &w, &h, &x, &y);

        root->frame->setX(painter->screen_width*0.5 - w*0.5*scale);
        root->frame->setY(painter->screen_height - h*scale);
        root->frame->setScale(scale);

        return;
    }
    Nodo *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new Nodo(new Step(painter,path));

    Nodo *temp2 = temp->next;

    float w, h, x, y;
    queryData(temp2->frame, &w, &h, &x, &y);

    temp2->frame->setX(painter->screen_width*0.5 - w*0.5*scale);
    temp2->frame->setY(temp->frame->getY() - h*scale);
    temp2->frame->setScale(scale);
}

void ListImage::add(Nodo *nuevo)
{
    if(root==NULL)
    {
        root = nuevo;
//        float w, h, x, y;
//        queryData(root->frame, &w, &h, &x, &y);
//
//        root->frame->setX(painter->screen_width*0.5 - w*0.5*scale);
//        root->frame->setY(painter->screen_height - h*scale);
//        root->frame->setScale(scale);

        return;
    }
    Nodo *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = nuevo;
}

Step* ListImage::pop()
{
    Nodo* temp = root;
    root = temp->next;
    temp->next = NULL;
    return temp->frame;
}

void ListImage::draw(float off_set)
{
//    float scales[7] = {1, 0.66, 0.44, 0.29, 0.19, 0.125, 0.082};
//    float scales[7] = {1.2, 1.2*0.66, 1.2*0.44, 1.2*0.29, 1.2*0.19, 1.2*0.125, 1.2*0.082};
//    scale=1;
//    float scale_before=scale;

    Nodo *tmp = root;
    float y_temp=painter->screen_height;
    float scale_temp=1;

    for(int i=0; i<8; i+=1.0)
    {
        if(tmp)
        {
//            int x, y, w, h;
            Step *image = tmp->frame;
            tmp->frame->addY(off_set);
//            scale = (float)(pow(0.66,i));
//            scale = (float)(pow(10,-0.178*i));

//            w = image->getWidth();
//            h = image->getHeight();
            //try
//            y = y_temp - h*scale + off_set;
//
//            scale_temp = (y - 432.27)/223.92;
//
//            x = painter->screen_width*0.5 - w*0.5*scale_temp;
//
//            y_temp = y;
            //done

//            std::cout<<"Scale "<<i<<": "<<scale<<", y: "<<y<<endl;

//            scale -= 0.015; //scale -= 0.1000005; //(float)(1.0/(i+1.0));

//            scale = (float)(1.0/(scale-0.3));
//            scale_before = scale;

//            painter->draw2DImage
//            (   image,
//                w,h,
//                x,y,
//                scale_temp,
//                0,
//                true,
//                0,0,
//                Color(255,255,255,255),
//                0,0,
//                false);
            tmp->frame->draw(painter);
//            scale = (float)(w / (w * (s+3.0)/2.0));

            tmp = tmp->next;

        }
    }

    Nodo *last = root;
    while(last->next!=NULL)
        last=last->next;
    if(last->frame->scale>=0.14981)
//    if(root->frame->getY()>=656.999)
    {
         Step *n = pop();
         n->init();
         Nodo *nuevo = new Nodo(n);
         add(nuevo);
    }
}
