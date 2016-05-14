#include <stdio.h>
#include <stdlib.h>

struct sehir{
	char* c;
	int depth;
	//bu sehirden gidilebilen 1. sehir
	struct sehir* sehir1;
	//bu sehirden gidilebilen 1. þehre kadar olan mesafe
	int mesafe1;
	struct sehir* sehir2;
	int mesafe2;
	struct sehir* sehir3;
	int mesafe3;
	struct sehir* sehir4;
	int mesafe4;
	struct sehir* sehir5;
	int mesafe5;
};
typedef struct sehir Sehir;
typedef Sehir* SehirPtr;

SehirPtr yeni_sehir(char* name){
	SehirPtr YeniSehir;
	YeniSehir=malloc(sizeof(Sehir));
	YeniSehir->c=name;
	YeniSehir->sehir1=NULL;
	YeniSehir->sehir2=NULL;
	YeniSehir->sehir3=NULL;
	YeniSehir->sehir4=NULL;
	YeniSehir->sehir5=NULL;
	return YeniSehir;
}
void sehir_bagla(SehirPtr BSehir1,SehirPtr BSehir2,int mesafe,int kacinci){
	if(kacinci==1){
		BSehir1->sehir1=BSehir2;
		BSehir1->mesafe1=mesafe;
	}
	if(kacinci==2){
			BSehir1->sehir2=BSehir2;
			BSehir1->mesafe2=mesafe;
		}
	if(kacinci==3){
			BSehir1->sehir3=BSehir2;
			BSehir1->mesafe3=mesafe;
		}
	if(kacinci==4){
			BSehir1->sehir4=BSehir2;
			BSehir1->mesafe4=mesafe;
		}
	if(kacinci==5){
			BSehir1->sehir5=BSehir2;
			BSehir1->mesafe5=mesafe;
		}
}


//her þehir için derinlik hesapla
void derinlik_hesapla(SehirPtr sehirler[]){
	int i;
	int k;
	printf("derinlik hesaplama calisiyor \n");
	//15 þehir için tek tek hesapla
	for(i=0;i<15;i++){
        //bir þehirden en fazla beþ þehire gidilebiliyor
        //bu 5 þehrin herbirine gore derinlikleri tut
		int derinlikler[5];
		for(k=0;k<5;k++)
			derinlikler[k]=0;
        //bu þehirden gidilecek 1. þehir için derinliyi hesapla
		if(sehirler[i]->sehir1!=NULL){
			derinlikler[0]++;
			SehirPtr onceki;
			SehirPtr shr=sehirler[i]->sehir1;
			while(shr->sehir1!=NULL){
				derinlikler[0]++;
				onceki=shr;
                shr=shr->sehir1;
                if(shr->sehir1!=NULL)
                    if(onceki->c==shr->sehir1->c)
                        shr=shr->sehir2;
			}

		}
		//ikinci þehir için derinliyi hesapla
		if(sehirler[i]->sehir2!=NULL){
			derinlikler[1]++;
			SehirPtr shr=sehirler[i]->sehir2;
            SehirPtr onceki;
			while(shr->sehir1!=NULL){
                derinlikler[1]++;
                onceki=shr;
                shr=shr->sehir1;
                if(shr->sehir1!=NULL)
                    if(onceki->c==shr->sehir1->c)
                        shr=shr->sehir2;
			}
		}
		if(sehirler[i]->sehir3!=NULL){
					derinlikler[2]++;
					SehirPtr shr=sehirler[i]->sehir3;
                    SehirPtr onceki;
					while(shr->sehir1!=NULL){
						derinlikler[2]++;
                        onceki=shr;
                        shr=shr->sehir1;
                        if(shr->sehir1!=NULL)
                            if(onceki->c==shr->sehir1->c)
                                shr=shr->sehir2;
					}
		}
		if(sehirler[i]->sehir4!=NULL){
					derinlikler[3]++;
					SehirPtr shr=sehirler[i]->sehir4;
					SehirPtr onceki;
					while(shr->sehir1!=NULL){
						derinlikler[3]++;
                        onceki=shr;
                        shr=shr->sehir1;
                        if(shr->sehir1!=NULL)
                            if(onceki->c==shr->sehir1->c)
                                shr=shr->sehir2;
					}
		}
		if(sehirler[i]->sehir5!=NULL){
					derinlikler[4]++;
					SehirPtr shr=sehirler[i]->sehir5;
					SehirPtr onceki;
					while(shr->sehir1!=NULL){
						derinlikler[4]++;
                        onceki=shr;
                        shr=shr->sehir1;
                        if(shr->sehir1!=NULL)
                            if(onceki->c==shr->sehir1->c)
                                shr=shr->sehir2;
					}
		}

		//bu þehirden gidilebilen en fazla beþ þehre gore en buyuk
		// olan derinligi bu þehrin derinliyi olarak ata
		int enb=derinlikler[0],j;
		for(j=0;j<5;j++)
			if(enb<derinlikler[j])
				enb=derinlikler[j];

		sehirler[i]->depth=enb;

	}
}
//gidilecek sonraki sehri derinligine gore bul
SehirPtr getNext(SehirPtr shr,SehirPtr onceki){
    struct sehir *next=(struct sehir *)malloc(sizeof(struct sehir));
    next->depth=0;
    if(shr->sehir1!=NULL && onceki->c!=shr->sehir1->c)
            next=shr->sehir1;
    if(shr->sehir2!=NULL)
        if(next->depth<shr->sehir2->depth && onceki->c!=shr->sehir2->c)
            next=shr->sehir2;
    if(shr->sehir3!=NULL)
        if(next->depth<shr->sehir3->depth && onceki->c!=shr->sehir3->c)
            next=shr->sehir3;
    if(shr->sehir4!=NULL)
        if(next->depth<shr->sehir4->depth &&onceki->c!=shr->sehir4->c)
            next=shr->sehir4;
    if(shr->sehir5!=NULL)
        if(next->depth<shr->sehir5->depth&&onceki->c!=shr->sehir5->c)
            next=shr->sehir5;
    return next;

};

//gecilen sehirler arasýndaki mesafeleri ve toplam mesafeyi bul ve yaz
void mesafeleri_yaz(SehirPtr dizi[]){
    int i=0,toplam=0;
    while(dizi[i+1]!=NULL){
        //sonraki sehrin adýný tut
        char* name;
        if(dizi[i+1]!=NULL)
            name=dizi[i+1]->c;
        //sonraki sehir bu sehrin ilk sehrimi kontrol et
        if(dizi[i]->sehir1->c==name){
            //bu sehirler arasýndaki mesafeyi bul
             printf("%d->",dizi[i]->mesafe1);
             toplam+=dizi[i]->mesafe1;
        }
        else if(dizi[i]->sehir2->c==name){
            printf("%d->",dizi[i]->mesafe2);
            toplam+=dizi[i]->mesafe2;
        }
        else if(dizi[i]->sehir3->c==name){
             printf("%d->",dizi[i]->mesafe3);
               toplam+=dizi[i]->mesafe3;
        }
        else if(dizi[i]->sehir4->c==name){
            printf("%d->",dizi[i]->mesafe4);
            toplam+=dizi[i]->mesafe4;
        }
        else{
            printf("%d->",dizi[i]->mesafe5);
            toplam+=dizi[i]->mesafe5;
        }
        i++;
    }
    printf("0\n");
    printf("Toplam Mesafe::%d\n",toplam);
}



SehirPtr en_derin_sehiri_getir(SehirPtr shr,SehirPtr gecilenler[]){
    //geriye donuþ için bir sehir oluþtur
    struct sehir *en_derin=(struct sehir*)malloc(sizeof(struct sehir));
    //varsayýlan derinligi 0 olsun
    en_derin->depth=0;
    if(en_derin->depth<shr->sehir1->depth)
    {
        //daha once çanakkaleden bu þehre gelinmiþmi kontrol et
        int kont=0,i;
        for(i=0;i<5;i++)
            if(gecilenler[i]!=NULL)
                if(gecilenler[i]->c==shr->sehir1->c)
                    kont=1;
        if(kont==0)
            en_derin=shr->sehir1;
    }

    if(en_derin->depth<shr->sehir2->depth)
    {
         //daha once çanakkaleden bu þehre gelinmiþmi kontrol et
        int kont=0,i;
        for(i=0;i<5;i++)
            if(gecilenler[i]!=NULL)
                if(gecilenler[i]->c==shr->sehir2->c)
                    kont=1;
        if(kont==0)
            en_derin=shr->sehir2;
    }

    if(en_derin->depth<shr->sehir3->depth)
    {
         //daha once çanakkaleden bu þehre gelinmiþmi kontrol et
        int kont=0,i;
        for(i=0;i<5;i++)
            if(gecilenler[i]!=NULL)
                if(gecilenler[i]->c==shr->sehir3->c)
                    kont=1;
        if(kont==0)
            en_derin=shr->sehir3;
    }

    if(en_derin->depth<shr->sehir4->depth)
    {
         //daha once çanakkaleden bu þehre gelinmiþmi kontrol et
        int kont=0,i;
        for(i=0;i<5;i++)
            if(gecilenler[i]!=NULL)
                if(gecilenler[i]->c==shr->sehir4->c)
                    kont=1;
        if(kont==0)
            en_derin=shr->sehir4;
    }
    if(en_derin->depth<shr->sehir5->depth)
    {
        //daha once çanakkaleden bu þehre gelinmiþmi kontrol et
        int kont=0,i;
        for(i=0;i<5;i++)
            if(gecilenler[i]!=NULL)
                if(gecilenler[i]->c==shr->sehir5->c)
                    kont=1;
        if(kont==0)
            en_derin=shr->sehir5;
    }
    return en_derin;

}
void dfs(SehirPtr baslangic){

    //canakkaleden derinlige gore diger þehire
    //gecerken daha once gecilmiþmi kontrol etmek için dizi
    SehirPtr gecilenler[5];
    int i;
    for(i=0;i<5;i++)
        gecilenler[i]=NULL;
    i=0;
    int j;
   // gecilen_sehirler[i]=next;
    for(j=0;j<5;j++){
        //ekrana yazmak için gecilen sehirleri tut
        SehirPtr rota[15];
        for(i=0;i<15;i++)
            rota[i]=NULL;
        //çanakkaleyi yaz
        printf("%s->",baslangic->c);
        //onceki ve sonrakini tut
        SehirPtr onceki;
        SehirPtr next;
        //next=getNext(baslangic,onceki);
        i=0;
        rota[i]=baslangic;
        i++;
        //çanakkaleden sonraki sehri bul
        next=en_derin_sehiri_getir(baslangic,gecilenler);
        //çanakalenin nextleri
        gecilenler[j]=next;
        rota[i]=next;
        while(next->c!="ankara"){
            i++;
            printf("%s->",next->c);
            //nerden geldiyini tut.geri  donme olabilir.ornegin izmir->manisa
            onceki=next;
            //bir sonraki sehri bul
            next=getNext(next,onceki);
            if(next->c=="ankara")
                printf("ankara\n");
            //sehri gecilen sehirler arsýna ekle
            rota[i]=next;
        }
        //elde edilen rotanýn sehir-sehir mesafelerini ve toplam mesafeyi yaz
        mesafeleri_yaz(rota);
    }
}

int main(void) {
    //sehirleri oluþtur
	SehirPtr sehirler[15];
	SehirPtr canakkale=yeni_sehir("canakkale");
	sehirler[0]=canakkale;
	SehirPtr izmir=yeni_sehir("izmir");
	sehirler[1]=izmir;
	SehirPtr balikesir=yeni_sehir("balikesir");
	sehirler[2]=balikesir;
	SehirPtr edirne=yeni_sehir("edirne");
	sehirler[3]=edirne;
	SehirPtr manisa=yeni_sehir("manisa");
	sehirler[4]=manisa;
	SehirPtr bursa=yeni_sehir("bursa");
	sehirler[5]=bursa;
	SehirPtr tekirdag=yeni_sehir("tekirdag");
	sehirler[6]=tekirdag;
	SehirPtr usak=yeni_sehir("usak");
	sehirler[7]=usak;
	SehirPtr istanbul=yeni_sehir("istanbul");
	sehirler[8]=istanbul;
	SehirPtr kocaeli=yeni_sehir("kocaeli");
	sehirler[9]=kocaeli;
	SehirPtr eskisehir=yeni_sehir("eskisehir");
	sehirler[10]=eskisehir;
	SehirPtr kutahya=yeni_sehir("kutahya");
	sehirler[11]=kutahya;
	SehirPtr bolu=yeni_sehir("bolu");
	sehirler[12]=bolu;
	SehirPtr afyon=yeni_sehir("afyon");
	sehirler[13]=afyon;
	SehirPtr ankara=yeni_sehir("ankara");
	sehirler[14]=ankara;
    //sehirler arasýndaki baglantýyý sagla
    //canakaleden izmire 325 KM,buradaki 1 ise izmir canakaleden gidilen 1. sehir demek
    //struct yapýsýnda sehir1'e karþýlýk geliyor.
	sehir_bagla(canakkale,izmir,325,1);
	sehir_bagla(canakkale,balikesir,207,2);
	sehir_bagla(canakkale,bursa,271,3);
	sehir_bagla(canakkale,edirne,217,4);
	sehir_bagla(canakkale,tekirdag,188,5);
	sehir_bagla(izmir,manisa,36,1);
	sehir_bagla(izmir,usak,211,2);
	sehir_bagla(balikesir,manisa,137,1);
	sehir_bagla(balikesir,bursa,151,1);
	sehir_bagla(bursa,eskisehir,149,1);
	sehir_bagla(bursa,kocaeli,132,2);
	sehir_bagla(bursa,istanbul,243,3);
	sehir_bagla(tekirdag,istanbul,132,1);
	sehir_bagla(edirne,tekirdag,140,1);
	sehir_bagla(edirne,istanbul,229,2);
	sehir_bagla(istanbul,kocaeli,111,1);
	sehir_bagla(kocaeli,eskisehir,219,1);
	sehir_bagla(kocaeli,bolu,151,2);
	sehir_bagla(eskisehir,kutahya,78,1);
	sehir_bagla(eskisehir,ankara,233,2);
	sehir_bagla(bolu,ankara,191,1);
	sehir_bagla(kutahya,afyon,100,1);
	sehir_bagla(afyon,ankara,256,1);
	sehir_bagla(usak,afyon,115,1);
	sehir_bagla(manisa,izmir,36,1);
	sehir_bagla(manisa,balikesir,137,2);

    int i;
	derinlik_hesapla(sehirler);
	printf("\nderinlikler ......................\n");
	for(i=0;i<15;i++)
		printf("%s::%d\n",sehirler[i]->c,sehirler[i]->depth);
	printf("................geziliyor................\n");
	//depth first search u çagýr.canakaleden baþlayarak gez
	dfs(canakkale);
	return EXIT_SUCCESS;
}
