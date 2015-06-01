#include "ListImage.h"
#include <cmath>

ListImage::ListImage(RosalilaGraphics *paint)
{
    root = NULL;
    this->painter = paint;
    acu=0;
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
        root = new Nodo(painter->getTexture(path));
        return;
    }
    Nodo *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new Nodo(painter->getTexture(path));
}

Image* ListImage::pop()
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
    float scale_temp=((float)tmp->frame->getHeight())/((float)tmp->frame->getWidth());
    cout<<"Height: "<<tmp->frame->getHeight()<<", Width: "<<tmp->frame->getWidth()<<endl;
    for(int i=0; i<7; i+=1.0)
    {
        if(tmp)
        {
            int x, y, w, h;
            Image *image = tmp->frame;
//                scale = (float)(pow(0.66,i));
            scale = (float)(pow(0.66,i));

            //change
//            float w0 = image->getWidth()*0.66956;
//            float variante=w0/image->getWidth();
//            scale = (float)(pow(variante,i));
            w = image->getWidth();
            h = image->getHeight();

//            image->setHeight(h);
//            image->setWidth(w);
            //finish

            y = (y_temp + off_set) - h*scale;

            scale = (y - 432.27)/223.92;

//            y+=off_set*scale;
            //y = y_temp - h*scale;

            x = painter->screen_width*0.5 - w*0.5*scale;

            y_temp = y;

            std::cout<<"Scale "<<i<<": "<<scale<<", y: "<<y<<", off: "<<off_set<<", width: "<<w*scale<<", height: "<<h*scale<<endl;;

            painter->draw2DImage
            (   image,
                w,h,
                x,y,
                scale,
                0,
                true,
                0,0,
                Color(255,255,255,255),
                0,0,
                false);

            tmp = tmp->next;
            scale_temp=scale;
        }
    }
}
