#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char *mot;
    int chara;
     char r;
    fichier = fopen(NOM_FICH,"W");
    printf("voulez -vs entrez qlq chose (oui) O/o (non) N/n \n");
     scanf(" %c",&r);
    while(r=='o' || r=='O')
    {
         printf("\nEntrer le mot que vous voulez\n"); fflush(stdin);
        gets(*mot);
        fprintf(fichier,"\t%s \n",mot);
        printf("\nL'ecriture est faite");
        printf("voulez -vs entrez qlq chose (oui) O/o (non) N/n \n");
        scanf(" %c",&r);
    }
    fclose(fichier);

}
/*----------------------------------------------------------------------*/
 void Lecture(FILE *fichier)
 {
    char NOM_FICH[] = "INFORM.TXT";
    char mot[100];
    fichier = fopen(NOM_FICH, "r");
    if (!fichier)
    {
      printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n",NOM_FICH);
      exit(-1);
    }
     printf("*** Contenu du fichier  %s ***\n", NOM_FICH);
     while (!feof(fichier))
     {
     fscanf(fichier,"%s",mot);
     printf("--> %s \n",mot);
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
            fprintf(f1,"%s \n",mot);
    }
    fclose(fichier); fclose(f1);
    fichier = fopen("INFORM.TXT","w");
    f1 = fopen("inf.txt","r");
    while(!feof(f1))
    {
        fscanf(f1,"%s",mot);
        fprintf(fichier,"%s \n",mot);
    }
    fclose(fichier); fclose(f1);
}
/*-----------------------------------------------------------------------*/
void copy(FILE *F_cop,FILE *F_col)
{
    char *mot[100];
  /*  printf("entrez le nom du fichier à copier\n");
    gets(nom_fichier);
    printf("entrez le nom du fichier dans lequel vs voulez copier");
    gets(nom_fichier2);*/
    F_cop=fopen("INFORM.TXT","r");
    F_col=fopen("copy.txt","w");
    if(F_cop==NULL){printf("error!");
                     exit(1);}
    while(!feof(F_cop))
                     {
                         fscanf(F_cop,"%s",mot);
                         fprintf(F_col,"%s \n",mot);
                     }
                     fclose(F_cop);
                     fclose(F_col);

}
void concat(FILE *F1,FILE *F2,FILE *F3)
{
    char *mot[100];
    F3=fopen("fichier3.txt","w");
    if(F3==NULL){printf("Error!");
                exit(0);}
    F1=fopen("INFORM.TXT","r");
    while(!feof(F1))
    {
        fscanf(F1,"%s",mot);
        fprintf(F3,"%s \n",mot);
    }
    fclose(F1);
    F2=fopen("inf.txt","r");
    while(!feof(F2))
    {
        fscanf(F2,"%s",mot);
        fprintf(F3,"%s \n",mot);
    }
    fclose(F2);
    fclose(F3);

}
int main()
{
    FILE *f,*f1,*f2;
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
     printf(" 4. Suppression dans un fichier \n");
     printf(" 5. Copier le fichier dans un autre\n");
     printf(" 6. Concat\202nation des deux fichiers \n");
     printf(" 7. Quitter\n\n");
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
                copy(f,f1);
                break;
            case 6:
                concat(f,f1,f2);
                break;
            case 7:
                printf("\n\nAu revoir ");
                break ;
            default:
                system("cls");
                printf("Choix invalide! Recommencer\n\n");
                break;
            }
    }while(choix!=7);
/*char ch, source_file[20], target_file[20];
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
   fclose(target);*/

   return 0;
}
