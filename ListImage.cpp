#include "ListImage.h"
#include <cmath>

ListImage::ListImage(RosalilaGraphics *paint)
{
    root = NULL;
    this->painter = paint;
    root_scale=0.66;
    max_draw = 13;
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
        root = new Step(painter,path);
        double w, h, x, y;
        queryData(root, &w, &h, &x, &y);

        root->setX(painter->screen_width*0.5 - w*0.5);
        root->setY(painter->screen_height - h);
        return;
    }
    Step *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new Step(painter,path);
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

void ListImage::draw(double off_set_x, double off_set_y)
{
    Step *tmp = root;
    while(tmp)
    {
        tmp->addOff_X(off_set_x);
        tmp = tmp->next;
    }
    draw(root,root->next,0,off_set_x,off_set_y);
}

void ListImage::draw(Step*anterior,Step*actual,int c,double off_set_x, double off_set_y)
{
    if(c==max_draw)
    {
        if(anterior->scale>=0.0563964)//0.108468)
        {
            add(pop());
        }
        return;
    }
    anterior->addY(off_set_y);
    anterior->draw(painter);
    actual->init(anterior);
    draw(actual,actual->next,c+1,off_set_x,off_set_y);
}

void ListImage::reset()
{
//    double s = root->getScale();
//    int cont=1;
//    Step *tmp = root;
//
//    while(tmp->next!=NULL)
//    {
//        Step *tmp2 = tmp->next;
//        double ss = pow(s,cont);
//        double x = painter->screen_width*0.5 - tmp2->getWidth()*0.5*ss;
//        double y = tmp->getY() - tmp2->getHeight()*ss;
//
//        tmp2->init(ss, x, y);
//        tmp = tmp->next;
//        cont++;
//    }
}

void ListImage::flush(double flu)
{
//    Step *tmp = root;
//    Step *last = root;
//    double y_temp=painter->screen_height;
//    double scale_temp=1;
//    int c = 0;
//
//    while(tmp)
//    {
//        Step *image = tmp->frame;
//        tmp->addY(flu);
//
//        if(c<8)
//        {
//            last = tmp;
//        }
//
//        tmp = tmp->next;
//        c++;
//    }
//
//    cout<<"Scale: "<<last->scale<<endl;
//    if(last->scale>=0.108468)
//    {
//         Step *n = pop();
//
//         while(last->next!=NULL)
//            last=last->next;
//
//         n->init(last);
//         add(n);
//    }
}

void ListImage::clear()
{
    root=NULL;
}
