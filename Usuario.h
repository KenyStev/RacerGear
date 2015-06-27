#ifndef USUARIO_H
#define USUARIO_H

#include<fstream>
#include<iostream>
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"

    using namespace std;
class Usuario
{
    public:
    int pista1,pista2,pista3,pista4,promedio;
        // Insertion operator
//	friend std::ostream& operator<<(std::ostream& os, const Usuario& s)
//	{
//		// write out individual members of s with an end of line between each one
//		os << s.nombre << '\t';
//		os << s.pista1<<'\t';
//		os << s.pista2<<'\t';
//		os << s.pista3<<'\t';
//		os << s.pista4<<'\t';
//		os << s.promedio<<'\t';
//		delete &s;
//		return os;
//	}
//
//	// Extraction operator
//	friend std::istream& operator>>(std::istream& is, Usuario& s)
//	{
//		// read in individual members of s
//		is >> s.nombre >> s.pista1>> s.pista2>> s.pista3>> s.pista4;
//		return is;
//	}
        string nombre;
        Usuario(string name);
        Usuario(string name, int p1,int p2,int p3,int p4,int pro);
        Usuario();
        void imprimir();
        void print(RosalilaGraphics* painter,int c);
        int average();
        int getAverage();
        void setAverage();
        virtual ~Usuario();
    protected:
    private:
};

#endif // USUARIO_H
