#include "ListImage.h"
#include <cmath>

ListImage::ListImage(RosalilaGraphics *paint)
{
    root = NULL;
    this->painter = paint;
    root_scale=0.66;
    max_draw = 11;
    size=0;
    pops=0;

    loadSteps("steps.xml");
}
ListImage::ListImage()
{
    root = NULL;
    this->painter = NULL;
    root_scale=0;
}

ListImage::~ListImage()
{
    delete root;
}

void ListImage::add(int hurt,string path)
{
    Step *newStep = new Step(painter,texturas[path]);

    if(strcmp(path.c_str(),"Meta")==0)
        newStep->isMeta=true;

    if(strcmp(path.c_str(),"puas_left")==0)
        newStep->setHit_Left(true);
    if(strcmp(path.c_str(),"puas_right")==0)
        newStep->setHit_Right(true);
    if(strcmp(path.c_str(),"puas_center")==0)
        newStep->setHit_Center(true);

    newStep->hurt=hurt;

    if(strcmp(path.c_str(),"flags")!=0 && strcmp(path.c_str(),"flags_2")!=0)
        newStep->setBorders();

    if(strcmp(path.c_str(),"puas_1-2")==0)
    {
        newStep->setHit_Left(true);
        newStep->setHit_Center(true);
    }

    if(strcmp(path.c_str(),"puas_2-3")==0)
    {
        newStep->setHit_Right(true);
        newStep->setHit_Center(true);
    }

    if(strcmp(path.c_str(),"puas_1-3")==0)
    {
        newStep->setHit_Right(true);
        newStep->setHit_Left(true);
    }

    if(root==NULL)
    {
        root = newStep;
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
    size++;
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
    if(pops==0)
        pops++;
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
            if(hitboxCollision(r,0,c,0))
            {
                if(car->v_max-actual->hurt>0)
                    car->hurt=car->v_max-actual->hurt;
                else
                    car->hurt=car->v_max*0.5;
            }
        }
        if(actual->hit_left)
        {
            r = actual->rect_left;
            if(hitboxCollision(r,0,c,0))
            {
                if(car->v_max-actual->hurt>0)
                    car->hurt=car->v_max-actual->hurt;
                else
                    car->hurt=car->v_max*0.5;
            }
        }
        if(actual->hit_right)
        {
            r = actual->rect_right;
            if(hitboxCollision(r,0,c,0))
            {
                if(car->v_max-actual->hurt>0)
                    car->hurt=car->v_max-actual->hurt;
                else
                    car->hurt=car->v_max*0.5;
            }
        }
        if(hitboxCollision(actual->border_left,0,c,0) || hitboxCollision(actual->border_right,0,c,0))
            car->outOfRoad=true;
    }
}

void ListImage::clear()
{
    root=NULL;
}

bool ListImage::isMeta()
{
    if(root!=NULL)
        return root->isMeta;
    return false;
}

void ListImage::loadSteps(std::string path)
{
    TiXmlDocument doc((assets_directory+path).c_str());
    doc.LoadFile();
    TiXmlNode *Steps = doc.FirstChild("Steps");

    for(TiXmlNode* step=Steps->FirstChild("step");
        step!=NULL;
        step=step->NextSibling("step"))
        {
            string s = step->ToElement()->Attribute("path");
            //cout<<s<<endl;
            texturas[s] = new Step(painter,assets_directory+s+".png");
        }
}
