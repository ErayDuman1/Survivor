#include <stdio.h>
#include <stdlib.h>
#include <time.h>


  struct xurvivor
  {
      int Parkur_uzunlugu;
      int Engel_sayisi;

  };

int *dinamik(struct xurvivor parkur)
{

      int *engel;
      engel = malloc(sizeof(int)* parkur.Engel_sayisi);
      return engel;
}

void engel(int *engel,int hp,struct xurvivor parkur)
{
      int gecici,i,j,k,kontrol=0,buyuk,kucuk,a=0;
      srand(time(NULL));
      for(i=0;i<parkur.Engel_sayisi;i++)
      {
          engel[i]=rand()%(parkur.Parkur_uzunlugu-5) +5;
      }
      for(i=0;i<parkur.Engel_sayisi;i++)
      {
        for(j=a;j<parkur.Engel_sayisi;j++)
          {
              if(engel[i]==engel[j+1])
              engel[i]=rand()%(parkur.Parkur_uzunlugu-5) +5;
          }
          a++;
      }


     for( i=0; i<parkur.Engel_sayisi-1;i++){
     for( j=i+1; j<parkur.Engel_sayisi; j++){
     if(engel[i] > engel[j]){
     gecici = engel[i];
     engel[i] = engel[j];
     engel[j] = gecici;
 }
 }
 }


}


int main()
{
      int *p,Yasam_puani=100;
      struct xurvivor parkur;
      srand(time(NULL));
      parkur.Parkur_uzunlugu = rand()%50 +50;
      printf("parkur %d metredir\n",parkur.Parkur_uzunlugu);
      parkur.Engel_sayisi = rand()%4 +2;
      printf("parkurdaki engel sayisi %d  \n",parkur.Engel_sayisi);
      p=dinamik(parkur);
      engel(p,Yasam_puani,parkur);
      Asal_yazdirma(p,Yasam_puani,parkur);

    return 0;
}

void Asal_yazdirma(int *engel,int hp,struct xurvivor parkur)
{
    FILE *fp;
    fp=fopen("log.txt","w");
    fprintf(fp,"!!Yarisma Basladi!!\n");
    int i,k,buyuk,kucuk,kontrol;
   for(i=0;i<parkur.Engel_sayisi;i++)
 {
     kontrol=0;
     if (hp >engel[i])
        {
        buyuk = hp;
        kucuk = engel[i];
        }
     if (engel[i]>hp)
       {
        buyuk = engel[i];
        kucuk = hp;
       }

     for(k=2; k<=kucuk; k++)
        {
        if( (buyuk % k == 0) && (kucuk % k == 0) )
        {
            kontrol++;
            break;
        }
        }
        if(kontrol>0)
        {
         fprintf(fp,"\nYarismaci %d. metreye kadar hicbir engelle karsilasmadi.\n",engel[i]);
         fprintf (fp,"%d. metrede bir engel var. %d ile %d aralarinda asal degildir.\n",engel[i],hp,engel[i]);
         fprintf(fp,"Yarismaci hp %d\n",hp);


        }

        if(kontrol==0)
        {
        fprintf(fp,"\nYarismaci %d. metreye kadar hicbir engelle karsilasmadi.\n",engel[i]);
        fprintf (fp,"%d. metrede bir engel var. %d ile %d aralarinda asaldir.\n",engel[i],hp,engel[i]);
        hp-=engel[i];
        fprintf(fp,"Yarismaci hp %d \n",hp);

        }

    }


     if(hp>0)
         fprintf(fp,"\n!!TEBRIKLER!! Yarismayi %d hp ile bitirdiniz!!\n",hp);

     if(hp<=0)
        fprintf(fp,"\nUZGUNUM !!! Yarismayi tamamlayamadin.\n");

}

