
#include <math.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void decimalaBinario(int dec)
{
    int residuos = 0, num = dec, aux, i = 0;
    int inversor[100];
    while (num != 0)
    {
        inversor[i] = num % 2;
        i++;
        num = num / 2;
        if (num == 1)
        {
            inversor[i + 1] = 1;
        }
        else if (num == 0)
        {
            inversor[i + 1] = 0;
        }
    }
    cout << "El numero en binario es: ";
    for (int b = i - 1; b > -1; b--)
    {
        cout << inversor[b];
    }
    cout << endl;
}
void decimalaOctal(int dec)
{
    int residuos = 0, num = dec, aux, i = 0;
    int inversor[100];
    while (num != 0)
    {
        inversor[i] = num % 8;
        i++;
        num = num / 8;
        if (num == 1)
        {
            inversor[i + 1] = 1;
        }
        else if (num == 0)
        {
            inversor[i + 1] = 0;
        }
    }
    cout << "El numero en octal es: ";
    for (int b = i - 1; b > -1; b--)
    {
        cout << inversor[b];
    }
    cout << endl;
}
void decimalaHexadecimal(int dec)
{
    char hexal[100];
    char[16]=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'];

        hexal[dec]=char[dec];
        num = num / 16;
        i++;
        if (num == 1)
        {
            hexal[i + 1] = 1;
        }
        else if (num == 0)
        {
            hexal[i + 1] = 0;
        }
    }
    cout << "El numero en hexadecimal es: ";
    for (int b = i - 1; b > -1; b--)
    {
        cout << hexal[b];
    }
    cout << endl;
}
int binarioaDecimal(int long long bin)
{
    int tamano=0, posicion=0, aux;
    int long long numdec = bin, numero = bin;
    while (numero)
    {
        numero = numero / 10;
        tamano++;
    }
    for (int i = 0; i < tamano; i++)
    {
        aux = numdec % 10;
        if (aux == 1)
        {
            posicion = posicion + pow(2, i);
        }
        numdec = numdec / 10;
    }
    return posicion;
}
void binarioaOctal(int long long bin)
{
    int long decimal;
    decimal = binarioaDecimal(bin);
    decimalaOctal(decimal);
}
void binarioaHexadecimal(int long long bin)
{
    int long decimal;
    decimal = binarioaDecimal(bin);
    decimalaHexadecimal(decimal);
}
int octalaDecimal(int oct)
{
    int aux, num=oct,decimal=0,i=0;
    while (num != 0)
    {
        aux = num % 10;
        decimal = decimal + aux*pow(8, i);
        num = num / 10;
        i++;
    }
    return decimal;
}
void octalahexadecimal(int oct)
{
    int decimal;
    decimal=octalaDecimal(oct);
    decimalaHexadecimal(decimal);
}
void octalaBinario(int oct)
{
    int decimal;
    decimal = octalaDecimal(oct);
    decimalaBinario(decimal);
}
void hexadecimalaBinario(int hxal)
{
    decimalaBinario(hxal);
}
void hexadecimalaOctal(int hxal)
{
    decimalaOctal(hxal);
}
void menu(int sisnum)
{
    int dec, oct,decimal,posicion,hxal;
    int long long bin;
    while (sisnum > 0 || sisnum < 5)
    {
        switch (sisnum)
        {
        case 1:
            cout << "Ingrese el numero bianrio que quiere transformar" << endl;
            cin >> bin;
            posicion=binarioaDecimal(bin);
            cout << "El numero en decimal es: " << posicion<<endl;
            binarioaOctal(bin);
            binarioaHexadecimal(bin);
            break;
        case 2:
            cout << "Ingrese el numero decimal que quiere transformar" << endl;
            cin >> dec;
            decimalaBinario(dec);
            decimalaOctal(dec);
            decimalaHexadecimal(dec);
            break;
        case 3:
            cout << "Ingrese el numero octal que quiere transformar" << endl;
            cin >> oct;
            octalaBinario(oct);
            decimal=octalaDecimal(oct);
            cout << "El numero en decimal es: " << decimal << endl;
            octalahexadecimal(oct);
            break;
        case 4:
            cout << "Ingrese el numero hexadecimal que desea transformar" << endl;
            cin >> hex >> hxal;
            hexadecimalaBinario(hxal);
            cout << "El numero en decimal es: " << hxal<<endl;
            hexadecimalaOctal(hxal);
            break;
        }
        cout << "Si quiere ingrese un otro sistema al cual quiere transformar, sino aprete el numero 5" << endl;
        cin >> sisnum;
    }
}
int main()
{
    system("color 8f");
    int sisnum;
    cout << "Ingrese el sistema que quiere convertir"<<endl<<"1.-Binario"<<endl<<"2.-Decimal"<<endl<<"3.-Octal"<<endl<<"4.-Hexadecimal"<<endl;
    cin >> sisnum;
    menu(sisnum);
}
