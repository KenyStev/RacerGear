#ifndef RANKING_H
#define RANKING_H
#include<fstream>
#include<iostream>
#include <map>
using namespace std;

//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"
const char* rank_archivo="Ranking.txt";
class Ranking
{
    public:
        string player_name;
        int time, pista;
        ofstream out;
        RosalilaGraphics *painter;
        ifstream in;
        multimap<string,int> mi_ranking;
        void initFStream();
        void saveRanking(int pista, int tiempo);
        void readRanking();
        bool seekPlayer(string name);
        void createNewUser(string nombre);
        double average(int p,int p2,int p3,int p4,int p5,int p6);

        Ranking(string name, int time, int pista, RosalilaGraphics *painter);
        Ranking();
        virtual ~Ranking();
    protected:
    private:
};

#endif // RANKING_H
