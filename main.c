#include <stdio.h>
#include <math.h>
//OBLICZANIE MIEJSCA ZEROWEGO
//METODA SIECZNYCH
double wsp1, wsp3, wsp4, wsp5, wsp7;
int wsp2, wsp6;
const double P_ZER = 0.0000000001; //wartosc dostatecznego przybizenia zera

/******************FUNKCJE*************************/
double fun(double x)
{
    return (wsp1*pow(x, wsp2)+wsp3*cos(wsp4)+wsp5*pow(x, wsp6)+wsp7);
}
/**************************************************/

int main()
{
    double x0, x1, x2, f0, f1, f2;
    int i;

    puts("Obliczanie miejsca zerowego funkcji wielomianowych za pomoca metody siecznych\n"
         "----------------------------------------------\n"
         "f(x) = a*x^b+c*cos(d)+e*x^f+g\n"
         "----------------------------------------------\n"
         "Gabriel Rebacz, grupa 1I1 2016\n");


    puts("Podaj wspolczynniki a, b, c, d, e, f, g funkcji:\n"); //wczytywanie wspolczynnikow i wypisanie wzoru
    if(scanf("%lf %d %lf %lf %lf %d %lf", &wsp1, &wsp2, &wsp3, &wsp4, &wsp5, &wsp6, &wsp7) != 7 || wsp2 < 0 || wsp6 < 0)
    {
        puts("bledne dane");
        return 0;
    }

    printf("--------------------------------\n"
           "%gx^%d%+gcos(%g)%+gx^%d%+g\n"
           "--------------------------------\n", wsp1, wsp2, wsp3, wsp4, wsp5, wsp6, wsp7);

    while(1) //petla umozliwiajaca wielokrotne wprowadzanie danych
    {
        puts("\nPodaj punkty poczatkowe x0, x1 oraz liczbe iteracji\n");   //wczytywanie punktow poczatkowych i ilosci powtorzen
        if(scanf("%lf %lf %d", &x0, &x1, &i) != 3)
        {
            puts("bledne dane");
            return 0;
        }

        printf("---------------------------------------\n"
               "x0 = %g x1 = %g i = %d\n"
               "---------------------------------------\n", x0, x1, i);

        f0 = fun(x0);
        f1 = fun(x1);


        while(i > 0)
        {
            if(fabs(f0 - f1) < P_ZER)
            {
                puts("niepoprawne punkty - sieczna rownolegla do osi x");
                i = 0;
                break;
            }

            x2 = x1 - (f1*(x1-x0))/(f1-f0);
            f2 = fun(x2);

            if(fabs(f2) < P_ZER)
                break;

            x0 = x1; f0 = f1;
            x1 = x2; f1 = f2;
            i--;
        }
//Zapytanie czu uzytkownik chce ponownie wprowadzic punkty poczatkowe, w razie wpisania 1 program wraca na poczatek petli
        if(i)
            printf("\nx0 = %lf\n", x2);
        else
            puts("\nnie znaleziono miejsca zerowego\n");
            puts("wcisnij 1 - zmien przedzial\n"
             "inny dowolny klawisz - koniec\n");


        getchar();
        if(getchar() != '1')
            return 0;
    }
}

