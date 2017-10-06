#include <stdlib.h>
#include <stdio.h>
#define FICHIER = data

int main(int argc,char *argv[])
{
    const int TAILLE_MAX_TRAM=64;
    FILE* fichier=NULL;
    FILE* fichier0=NULL;
    int caractereActuel=0;
    fichier=fopen("FICHIER","r");
    if(fichier!=NULL)
    {
        do
        {
            caractereActuel=fgetc(fichier);
            int* trame=malloc(TAILLE_MAX_TRAM*sizeof(int));
            int i=0;

            while(caractereActuel!='\n') //DIFFERENCE DE TYPE !/\!
            {
                *(trame+i)=caractereActuel;
                i++;
            }

            *(trame+i)=-1; //mettre marqueur d'arret

            int j=0;
            for(j=i+1;i<TAILLE_MAX_TRAM;j++) //liberer le reste non utilisé
            {
                free(trame+j);
            }

            int test=0; //apres test vaut 0 ou 1 suivant le test
            int numeroFichier=1;//nettoyerTrame
            //attention a avoir une trame qui finit par -1
            switch (numeroFichier)
            {
            case 0:
                fichier0=fopen("f0","a");
                if(fichier0!=NULL)
                {
                    int arret=0;
                    j=0;//compteur de la trame
                    i=0;//compteur du paquet
                    while(arret==0)
                    {
                        for(i=0;i<8;i++)
                        {
                            int codeErreur=0;
                            if(i==7)
                            {
                                fputc((char)(codeErreur),fichier0);
                            }
                            else if(*(trame+j)!=-1)
                            {
                                fputc(*(trame+j),fichier0);
                                codeErreur++;
                            }
                            else
                            {
                                arret=1;
                                fputc('?',fichier0);
                            }
                            j++;
                        }
                    }
                    fclose(fichier0);
                }
                break;
            case 1:
                fichier0=fopen("f0","a");
                if(fichier0!=NULL)
                {
                    int arret=0;
                    j=0;//compteur de la trame
                    i=0;//compteur du paquet
                    while(arret==0)
                    {
                        for(i=0;i<8;i++)
                        {
                            int codeErreur=0;
                            if(i==7)
                            {
                                fputc((char)(codeErreur),fichier0);
                            }
                            else if(*(trame+j)!=-1)
                            {
                                fputc(*(trame+j),fichier0);
                                codeErreur++;
                            }
                            else
                            {
                                arret=1;
                                fputc('?',fichier0);
                            }
                            j++;
                        }
                    }
                    fclose(fichier0);
                }
                break;
            case 2:
                fichier0=fopen("f0","a");
                if(fichier0!=NULL)
                {
                    int arret=0;
                    j=0;//compteur de la trame
                    i=0;//compteur du paquet
                    while(arret==0)
                    {
                        for(i=0;i<8;i++)
                        {
                            int codeErreur=0;
                            if(i==7)
                            {
                                fputc((char)(codeErreur),fichier0);
                            }
                            else if(*(trame+j)!=-1)
                            {
                                fputc(*(trame+j),fichier0);
                                codeErreur++;
                            }
                            else
                            {
                                arret=1;
                                fputc('?',fichier0);
                            }
                            j++;
                        }
                    }
                    fclose(fichier0);
                }
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            default:
                break;
            }


        }while(caractereActuel!=EOF);
        fclose(fichier);
    }



}
