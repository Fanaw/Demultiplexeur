#include <stdlib.h>
#include <stdio.h>

int test(char trame[])
{
    //fichier de sortie
    int fichier=0;

    //si le premier octet est entre 0 et 5
    if(trame[0]>48 && trame[0]<54)
    {
        //boolean
        int follow =1;
        int i =1;

        //parcour le tableau jusquau bout
        while(follow)
        {
            //on arrive a -1
            if(trame[i]<0)
            {
                //nombre d'octet
                int nboct=i-2;
                follow--;
                //si le dernier octet est compris entre 0 et 9
                if(trame[i-1]>=48 && trame[i-1]<=57)
                {
                    //si le dernier octet est multiple par 16 du nombre d'octet
                    if(nboct%16+48==trame[i-1])
                    {
                        fichier = trame[0]-48;                    
                    }
                }
                    //si le dernier octet est compris entre 0 et 9
                if(trame[i-1]>=65 && trame[i-1]<=70)
                {
                    //si le dernier octet est multiple par 16 du nombre d'octet
                    if(nboct%16+55==trame[i-1])
                    {
                        fichier = trame[0]-48;
                    }
                }
            }
            i++;
        }
    }
    return fichier;
}

int main()
{
    char essai[]= "2lolduif8";
    essai[12]=-1;
    test(essai);
    return 0;

}