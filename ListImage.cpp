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
    float scale_temp=1;
    for(int i=0; i<7; i+=1.0)
    {
        if(tmp)
        {
            int x, y, w, h;
            Image *image = tmp->frame;
//            scale -= 0.119; //0.015;//0.119;//0.1000005;

//            scale = (float)(1.2*pow(10,-0.178*i));
            scale = (float)(pow(10,-0.178*i));
//            scale = (float)(1.2*pow(0.66666667,abs(i-off_set)));
//            scale = (float)(1.2*pow(0.66666667,i));

            w = image->getWidth();
            h = image->getHeight();
//            x = painter->screen_width*0.5 - w*0.5*scale;
//            y = painter->screen_height - h*(i+1);

            y = y_temp - h*scale + off_set*10;
//            y_temp = y;

            scale_temp = (y - 432.27)/223.92;

            x = painter->screen_width*0.5 - w*0.5*scale_temp;

            y_temp = y;

//            y = y_temp + off_set*scale_temp*scale;
           /* scale_temp = (y - 432.27)/223.92;

            x = painter->screen_width*0.5 - w*0.5*scale_temp;
            y = y + scale_temp;*/
//            y = painter->screen_height - h*(i+1);

//            y = y_temp - h*scale;

            std::cout<<"Scale "<<i<<": "<<scale<<", y: "<<y<<endl;

//            scale -= 0.015; //scale -= 0.1000005; //(float)(1.0/(i+1.0));

//            scale = (float)(1.0/(scale-0.3));
//            scale_before = scale;

            painter->draw2DImage
            (   image,
                w,h,
                x,y,
                scale_temp,
                0,
                true,
                0,0,
                Color(255,255,255,255),
                0,0,
                false);
//            scale = (float)(w / (w * (s+3.0)/2.0));

            tmp = tmp->next;

        }
    }
}
