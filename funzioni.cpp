#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include "funzioni.hpp"
#define DIM 3

struct squadra{
    string nome;
    int punti;
    string capocannoniere_nome;
    int capocannoniere_gol;
}squadre[DIM];
//! \class [FUNZIONI]

//! \relates FUNZIONI

/*! \fn inserimento()
    \brief inserisce i nomi della squadra i punti ecc

*/




void inserimento ()
{

    ofstream file("MioFile.dat",ios::out|ios::binary);
    if(!file)
        cout<<"errore apertura file ";
    else
    {
        string temp;
        for(int i=0;i<DIM;i++)
        {
            cout<<"Inserimento della squadra numero"<<(i+1)<<endl;
            cout<<"Nome squadra:";
            fflush(stdin);
            getline(cin,temp);
            squadre[i].nome=temp;
            cout<<endl;
            cout<<"Punti squadra:";
            cin>>squadre[i].punti;
            cout<<endl;
            cout<<"Capocannoniere squadra:";
            fflush(stdin);
            getline(cin,temp);
            squadre[i].capocannoniere_nome=temp;
            cout<<endl;
            cout<<"Gol capocannoniere:";
            cin>>squadre[i].capocannoniere_gol;
            file.write((char *)&squadre[i],sizeof(squadre[i]));
        }
        for(int c=0; c<DIM; c++)
          {
             cout<<"Nome squadra: "<<squadre[c].nome<<" Punti: "<<squadre[c].punti<<" Nome capocannoniere:  "<<squadre[c].capocannoniere_nome<<" Gol: "<<squadre[c].capocannoniere_gol<<endl;

          }
    }
}


//! \relates FUNZIONI
/*! \fn classifica()
    \brief dice i punti delle squadre

*/
void classifica()
{
    squadra app;
    ifstream file("MioFile.dat",ios::in|ios::binary);
    if(!file)
        cout<<"errore apertura file";
    else
    {
        for(int i=0;i<DIM;i++)
            file.read((char *)&squadre[i],sizeof(squadre[i]));

        for(int i=0;i<DIM;i++)
        {
            for(int j=i+1;j<DIM;j++)
            {
               if(squadre[i].punti<squadre[j].punti)
                {
                    app=squadre[j];
                    squadre[j]=squadre[i];
                    squadre[i]=app;
                }

            }
        }
    }
     for(int c=0; c<DIM; c++)
          {
             cout<<"Nome squadra: "<<squadre[c].nome<<" Punti: "<<squadre[c].punti<<endl;

          }
}


//! \relates FUNZIONI
/*! \fn marcatori()
    \brief fa la classifica dei calciaori

*/

 void marcatori()
{
 squadra app;
    ifstream file("MioFile.dat",ios::in|ios::binary);
    if(!file)
        cout<<"errore apertura file";
    else
    {
        for(int i=0;i<DIM;i++)
            file.read((char *)&squadre[i],sizeof(squadre[i]));
        for(int i=0;i<DIM;i++)
        {
            for(int j=i+1;j<DIM;j++)
            {
                 if(squadre[i].capocannoniere_gol<squadre[j].capocannoniere_gol)
                {
                    app=squadre[j];
                    squadre[j]=squadre[i];
                    squadre[i]=app;
                }
            }
        }
    }
     for(int c=0; c<DIM; c++)
          {
             cout<<"Nome squadra: "<<squadre[c].nome<<" Nome capocannoniere:  "<<squadre[c].capocannoniere_nome<<" Gol: "<<squadre[c].capocannoniere_gol<<endl;

          }
}
