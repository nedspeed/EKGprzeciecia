#include<stdio.h>     //zalaczenie biblioteki//
#define STOP 99       //warunek stopu programu przy danej wartosci wejsciowej//
#define END 99        //stala oznaczajaca rozmiar paczki danych(strumienia danych)//
#define LOWER -10     //dolna granica dopuszczalnej wartosci wejsciowej//
#define UPPER 10      //gorna granica dopuszczalnej wartosci wejciowej//
#define X 8           //dolna granica prawidlowej ilosci przeciec//
#define Y 14          //gorna granica prawidlowej ilosci przeciec//
int main(){           //funkcja zwraca liczbe calkowita//
  int l_p=0, next=0, previous=0,ln=0;   //dodanie zmiennych calkowitych//
  printf("\n Witaj w programie przeciecia zera.\n");
  while(next!=STOP)       //petla glowna z warunkiem zatrzymania programu//
    {
      ln=0;next=0;previous=0;l_p=0;   //wyzerowanie zmiennych//
      while(next!=STOP&&ln<END)      //warunek kontynuacji pakietu danych//
     {
       do      //polecenie wykonania ponizszej instrukcji//
 {
   scanf("%d", &next);      //wczytaj wartosc next dziesietnie//
   ln+=1;      //zwieksz liczbe wczytanych danych o 1//
 }
       while((next<=UPPER || next>=LOWER || next==0)&&next!=STOP);   /* o poleceniu przeczytaj pod kodem programu*/
       if(next*previous<0)      //czy nastapilo przeciecie?//
	 l_p+=1;      //jesli tak, zwieksz liczbe przeciec o 1//
       previous=next;      //nastepna staje sie poprzednia//
  }
      if(ln==END)      //jesli pakiet zawiera 99 danych wykonaj ponizsza instrukcje//
     {
   if(l_p>X && l_p<Y)
     printf("\n Wszystko w normie.\n");      /*wydrukuj ten komunikat jesli liczba przeciec miesci sie w normalnym zakresie*/
   else
     printf("\n Wynik nienormalny.\n");      /*w przypadku, kiedy l_p nie miesci sie w normalnym zakresie, wydrukuj ten komunikat*/
   printf("\n Liczba przeciec %d\n",l_p);}      //odstep od rozpoczecia kolejnego procesu//
}
  return 0;      //zwroc 0//
}
/*Odnosnie warunku while w petli do-while; zostal on zrobiony na potrzebe unikniecia sytuacji, gdzie w zwyklej petli while program po rozpoczeciu dzialania przypisuje "poprzedniej" liczbie wartosc 0 a "nastepnej" np. wartosc 2 i kiedy po zakonczeniu obliczania czy nastapilo przeciecie, program w pierwszej kolejnosci zanim wczytano "nastepna" liczbe, najpierw chcialby sprawdzic warunek dotyczacy "nastepnej" liczby, ktorej jeszcze by nie bylo, poniewaz po wykonaniu obliczenia liczba 2 stala sie "poprzednia", a 0 zostalo zapomniane, tym samym nie ma jeszcze liczby "nastepnej".*/
/*Sprawozdanie:

Imie i nazwisko autora: Arkadiusz Dyjas

Temat cwiczenia: Przeciecia zera

Data wykonania: ostateczne czynnosci 02.11.2019r.

Kod zrodlowy: zadanie.c

Testy: W celu przetestowania programu wczytalem do niego dwa pliki tekstowe: przeciecia_zera1.txt oraz przeciecia_zera2.txt z pominietymi kolumnami czasu, ktore byly nieistotne. W obu przypadkach wczytania plikow wyniki okazaly sie takie same, w 100% poprawne, pakiety,ktore mialy niepelna ilosc danych zostaly pominiete przez program zgodnie z zamiarami. Ogolny wynik testu dowiodl poprawnosci dzialania programu. Program testowalem rowniez za pomoca manualnego wprowadzania danych przy jednoczesnie zmniejszonej wielkosci paczki danych(strumienia danych), lecz postanowilem pominac szczegoly tych testow ze wzgledu na prawdopodobnie zbyt duzy stopien skomplikowania sprawozdania po ich zalaczeniu.

Wnioski: Paczki danych sa niezalezne od siebie. Na poczatku kazdej paczki zmienne sa zerowane. Ilosc paczek nie jest zliczana. Liczby poza zakresem LOWER-UPPER oraz 0 nie sa brane pod uwage przy liczeniu przeciec zera. Liczby te jednak wciaz sa liczone w rozmiarze paczki, jesli nastepuja pomiedzy normalnymi wartosciami.
*/
