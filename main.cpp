#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "funzioni.hpp"
#define DIM 3
 using namespace std;

    /*! \mainpage <CENTER> esercizio tpsit </CENTER>
    * \author <B> Nicole Tozzi </B>
    * \version <B> V1.0 </B>
    * \date <B> Consegna progetto:    </B>
    *
    * \section caratteristiche CARATTERISTICHE DEL PROGETTO
    *
    *  Il software permette di:
    * - fa l'input delle squadre
    * - Stampa la classifica dei punti
    * - Stampa la classifica dei marcatori
    *
    *\section UML DIAGRAMMA UML DEL PROGETTO
    * <IMG SRC = "uml.jpg" ALT = "Diagramma UML del progetto"/>
    *
    *\section CLASS DIAGRAMMA DELLE CLASSI PRESENTI NEL PROGETTO
    *<IMG SRC = "classi.jpg" ALT = "Diagramma delle classi del progetto"/>
    */




 int main()
{
     //! \brief main nel quale tutto accade
    int scelta;
    do
    {
        do
        {
            cout<<"Quale operazione vuoi eseguire?"<<endl;
            cout<<"1)Inserimento dati"<<endl;
            cout<<"2)Stampa classifica punti"<<endl;
            cout<<"3)Stampa classifica marcatori"<<endl;
            cout<<"4)Exit"<<endl;
            cin>>scelta;
        }
        while(scelta<1||scelta>4);
         system("cls");
        switch(scelta)
        {
            case 1:inserimento();
                   break;
            case 2:
                   classifica();
                   break;
            case 3:marcatori();
                   break;
            case 4:cout<<"Fine programma ";
                   break;
        }
    }
    while(scelta!=4);
    return 0;
}
