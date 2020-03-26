#include <stdio.h>
#include <stdlib.h>
/*------------------------------------------------------------------------------*/
 void Creation(FILE *fichier)
 {
    char NOM_FICH[] = "INFORM.TXT";
    fichier = fopen(NOM_FICH,"a");
    if(fichier)
        printf("\n*** Cr\202ation du fichier %s ***\n",NOM_FICH);
        else
      printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", NOM_FICH);
     fclose(fichier);

 }
 /*--------------------------------------------------------------------*/
void Ecriture(FILE *fichier){

    char NOM_FICH[] = "INFORM.TXT";
    char mot[10];
    printf("\nEntrer le mot que vous voulez\n");
    scanf("%s",mot);
    fichier = fopen(NOM_FICH,"w+");
    if(fichier)
    {
        fprintf(fichier,"%s",mot);
        printf("\nL'ecriture est faite");
    }
    else  printf("\nERREUR");

    fclose(fichier);

}
/*----------------------------------------------------------------------*/
 void Lecture(FILE *fichier)
 {
    char NOM_FICH[] = "INFORM.TXT";
    char mot[10];
    fichier = fopen(NOM_FICH, "r");
    if (!fichier)
    {
      printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n",NOM_FICH);
      exit(-1);
    }
     printf("*** Contenu du fichier  %s ***\n", NOM_FICH);
     while (!feof(fichier))
     {
     fscanf(fichier, "%s\n",mot);
     printf("--> %s\t",mot);
     }
    fclose(fichier);
 }
/*-----------------------------------------------------------------------*/
void Suppression(FILE * fichier)
{

        char mot[100], supp[100];
    FILE *f1=fopen("inf.txt","w");
    fichier = fopen("INFORM.TXT","r");
    printf("\nEntrer le mot que vous voulez supprimer \n");
    scanf("%s",supp);
    while(!feof(fichier))
    {
        fscanf(fichier,"%s",mot);
        if(strcmp(mot,supp)!=0)
            fprintf(f1,"%s",mot);
    }
    fclose(fichier); fclose(f1);
    fichier = fopen("INFORM.TXT","w");
    f1 = fopen("inf.txt","r");
    while(!feof(f1))
    {
        fscanf(f1,"%s",mot);
        fprintf(fichier,"%s",mot);
    }
    fclose(fichier); fclose(f1);
}
/*-----------------------------------------------------------------------*/
int main()
{
    FILE *f;
    int choix;
     do{
     //system("cls");
   printf("\n\t_________________________________________________\n\t");
     printf("|                 Gestion des fichiers           |\n\t");
     printf("|                     SMI-S5                     |\n\t");
     printf("|________________________________________________|\n");
     printf(" \n MENU PRINCIPAL \n");
     printf(" --------------- \n");
     printf(" 1. Cr\202ation d'un fichier  \n");
     printf(" 2. Ecriture dans un fichier  \n");
     printf(" 3. Lecture d'un fichier\n");
     printf(" 4. Suppression d'un fichier \n");
     printf(" 5. Quitter\n\n");
     printf(">> Entrer votre choix: ");
     while(!scanf("%d",&choix))
     {
        system("cls");
        printf("choix non valide");
     }
     switch (choix)
            {
            case 1 :
                Creation(f);
                break ;
            case 2 :
                Ecriture(f);
                break ;
            case 3 :
                Lecture(f);
                break ;
            case 4 :
                Suppression(f);
                break ;
            case 5:
                printf("\n\nAu revoir ");
                break ;
            default:
                system("cls");
                printf("Choix invalide! Recommencer\n\n");
                break;
            }
    }while(choix!=5);
char ch, source_file[20], target_file[20];
   FILE *source, *target;

   printf("Enter name of file to copy\n");
   gets(source_file);

   source = fopen(source_file, "r");

   if (source == NULL)
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   printf("Enter name of target file\n");
   gets(target_file);

   target = fopen(target_file, "w");

   if (target == NULL)
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);

   printf("File copied successfully.\n");

   fclose(source);
   fclose(target);

   return 0;
}
