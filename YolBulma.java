import java.util.LinkedList;
public class YolBulma{
	
	static class Sehir{
			//kuþ uçuþu mesafesi
			private int flight_distance_to_ankara;
			private String name;
			//bir onceki sehirden bu þehre olan kara mesafesi
			private int distance=0;
			//bu þehirden gidilebilen þehirleri tutan baglý liste
			LinkedList<Sehir>bagli_sehirler;
			public Sehir(){}
			public Sehir(String name,int flight_distance_to_ankara){
				this.name=name;
				this.flight_distance_to_ankara=flight_distance_to_ankara;
				bagli_sehirler=new LinkedList<Sehir>();
			}
			//bu þehre bagli olan þehirleri ve aralarýndaki kara mesafelerini ekle
			public void addSehir(Sehir sehir,int distance){
				Sehir shr=new Sehir();
				shr.distance=distance;
				shr.name=sehir.name;
				shr.flight_distance_to_ankara=sehir.flight_distance_to_ankara;
				this.bagli_sehirler.add(shr);
			}
	}
	//ziyaret edilecek olan sonraki þehri bull
	public Sehir getNext(Sehir suanki,LinkedList<Sehir>visited,LinkedList<Sehir>tum_sehirler){
		int i=0;
		Sehir next=new Sehir();
		//sonraki þehri baþta bu þehre bagli olan 0. sehir olarak al
		next=new YolBulma().getForName(suanki.bagli_sehirler.get(i).name, tum_sehirler);
		//bu þehir daha onceden ziyaret edilmiþse 1. sehri al
		if(new YolBulma().is_visited(next, visited))
			next=new YolBulma().getForName(suanki.bagli_sehirler.get(i+1).name, tum_sehirler);
		for(i=1;i<suanki.bagli_sehirler.size();i++)
			if(suanki.bagli_sehirler.get(i).flight_distance_to_ankara<next.flight_distance_to_ankara &&
					!new YolBulma().is_visited(suanki.bagli_sehirler.get(i), visited))
				next=new YolBulma().getForName(suanki.bagli_sehirler.get(i).name, tum_sehirler);
		
		return next;
	}
	//bir þehrin daha once ziyaret edilip edilmedigini bulan metot
	 public boolean is_visited(Sehir shr,LinkedList<Sehir>visited){
		 for (Sehir sehir : visited) {
			if(shr.name==sehir.name)
				return true;
		}
		 return false;
	 }
	 //þehir ismine gore main metodunda oluþturulmuþ þehirlerden birini geri donduren metot
	 public Sehir getForName(String name,LinkedList<Sehir>tum_sehirler){
		 for (Sehir sehir : tum_sehirler) {
			if(sehir.name==name)
				return sehir;
		}
		 return null;
	 }
	//toplam mesafeyi bulan metot
	public int getSumDistance(LinkedList<Sehir>list){
		int toplam=0;
		int i;
		for(i=0;i<list.size()-1;i++){
			String next_name=list.get(i+1).name;
			for (Sehir sehir :list.get(i).bagli_sehirler)
				if(sehir.name==next_name)
					toplam+=sehir.distance;
		}
		return toplam;
	}
	public static void main(String[] args) {
		LinkedList<Sehir>tum_sehirler=new LinkedList<Sehir>();
		//þehirleri ve bunlarýn kuþ uçuþu mesafelerini oluþtur
		Sehir canakkale=new Sehir("canakkale", 547);
		tum_sehirler.add(canakkale);
		Sehir izmir=new Sehir("izmir",521);
		tum_sehirler.add(izmir);
		Sehir balikesir=new Sehir("balikesir", 427);
		tum_sehirler.add(balikesir);
		Sehir bursa=new Sehir("bursa",323);
		tum_sehirler.add(bursa);
		Sehir edirne=new Sehir("edirne",565);
		tum_sehirler.add(edirne);
		Sehir tekirdag=new Sehir("tekirdag", 468);
		tum_sehirler.add(tekirdag);
		Sehir manisa=new Sehir("manisa",490);
		tum_sehirler.add(manisa);
		Sehir usak=new Sehir("usak", 328);
		tum_sehirler.add(usak);
		Sehir kutahya=new Sehir("kutahya", 253);
		tum_sehirler.add(kutahya);
		Sehir kocaeli=new Sehir("kocaeli",265);
		tum_sehirler.add(kocaeli);
		Sehir istanbul=new Sehir("istanbul", 350);
		tum_sehirler.add(istanbul);
		Sehir eskisehir=new Sehir("eskisehir", 199);
		tum_sehirler.add(eskisehir);
		Sehir bolu=new Sehir("bolu", 139);
		tum_sehirler.add(bolu);
		Sehir afyon=new Sehir("afyon", 239);
		tum_sehirler.add(afyon);
		Sehir ankara=new Sehir("ankara", 0);
		tum_sehirler.add(ankara);
		//bir þehirden hangi þehirlere gidile bilir ve bunlar arasýndaki kara mesafesini tanýmla
		canakkale.addSehir(izmir, 325);
		canakkale.addSehir(balikesir, 207);
		canakkale.addSehir(bursa, 271);
		canakkale.addSehir(edirne, 217);
		canakkale.addSehir(tekirdag, 188);
		izmir.addSehir(usak,211);
		izmir.addSehir(manisa, 36);
		manisa.addSehir(izmir, 36);
		manisa.addSehir(balikesir, 137);
		balikesir.addSehir(manisa, 137);
		balikesir.addSehir(bursa,151);
		bursa.addSehir(eskisehir, 149);
		bursa.addSehir(kocaeli,132);
		bursa.addSehir(istanbul, 243);
		tekirdag.addSehir(istanbul, 132);
		edirne.addSehir(istanbul, 229);
		edirne.addSehir(tekirdag, 140);
		istanbul.addSehir(kocaeli, 111);
		kocaeli.addSehir(eskisehir, 219);
		kocaeli.addSehir(bolu,151);
		eskisehir.addSehir(ankara, 233);
		eskisehir.addSehir(kutahya, 78);
		bolu.addSehir(ankara, 191);
		kutahya.addSehir(afyon, 100);
		afyon.addSehir(ankara, 256);
		usak.addSehir(afyon,116);
		//ziyaret edilmiþ þehirleri tutmak için baglý liste oluþtur
		LinkedList<Sehir>visited=new LinkedList<Sehir>();
		Sehir onceki=new Sehir();
		onceki=canakkale;
		visited.add(onceki);
		//gezmeye baþla
		while(true){
			Sehir next=new Sehir();
			next=new YolBulma().getNext(onceki,visited,tum_sehirler);
			if(next.name=="ankara"){
				//ankaraya kadar gelinmiþse donguden çýk
				visited.add(ankara);
				break;
			}
			else
				visited.add(next);
			onceki=new Sehir();
			onceki=next;
		}
		for (Sehir sehir : visited)
			System.out.println(sehir.name);
		System.out.println("Toplma mesafe:"+new YolBulma().getSumDistance(visited));
		
	}
}