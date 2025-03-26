// Yainelly Ortiz   @Yainelly
// 801-23-1813
// Helpers: Cap. 6 - data dependency y funct decomp 

#include <iostream>
#include <cmath>  
#include <iomanip>

using namespace std;

// definir PI (lo hice asi para poder simplemente llamar a PI)
const double PI = 3.141592653589793;

// calculamos el volumen de la esfera y del cilindro

double Volumen(double radio) { // para la esfera
    double volumen = (4.0 / 3.0) * PI * pow(radio, 3);
    return volumen;
}

double Volumen(double radio, double altura) { // para el ilindro
        double volumen = PI * pow(radio, 2) * altura;
        return volumen;
}

double Volumen(double largo, double ancho, double altura) { // para el prisma rectangular
    double volumen = largo * ancho * altura;
    return volumen;
}

// calculamos el área de la superficie

double Area(double radio) { // para la esfera
    double area = 4 * PI * pow(radio, 2);
    return area;
}

double Area(double radio, double altura) { // para el cilindro
    double area = 2 * PI * radio * (radio + altura);
    return area;
}

double Area(double largo, double ancho, double altura) { // para el prisma rectangular
    double area = 2 * (largo * ancho + largo * altura + ancho * altura);
    return area;
}

int main() { // llamamos a main y le pedimos al usuario que escoja entre las 3 figuras
    char Figura, Calculo;
    cout << "Este programa calcula el volumen y el área de la superficie de tres figuras.\n" << endl;
    cout << "Escoja una figura:\n" << endl;
    cout << "  a. Cilindro\n  b. Esfera\n  c. Prisma rectangular\n";
    cout << "\nSelección: ";
    cin >> Figura;

    // Hacemos un while para por si entra una letra o un numero que no sea a, b o c 
    while (Figura != 'a' && Figura != 'b' && Figura != 'c') {
        cout << "\nError: Por favor escoja entre las letras 'a', 'b' o 'c': ";
        cin >> Figura;
    }

    cout << "\nEscoja entre las siguientes opciones:\n" << endl;
    cout << "  a. Volumen\n  b. Área de la superficie\n";
    cout << "\nSelección: ";
    cin >> Calculo;

    // Hacemos otro while para por si entra otra letra o numero que no sea a o b
    while (Calculo != 'a' && Calculo != 'b') {
        cout << "\nError: Por favor escoja entre las letras 'a' o 'b': ";
        cin >> Calculo;
    }

    double radio, altura, largo, ancho;
    cout << fixed << setprecision(2); // Para que se redondeen los decimales y ponerlos a dos espacios despues del punto, usamos fixed setprecision

    switch (Figura) { 
        case 'a': // para el caso del cilindro
            cout << "\nEntre el radio del cilindro: ";
            cin >> radio;
            while (radio <= 0) {
                cout << "\nEl radio debe ser un numero positivo. Entre el radio del cilindro: ";
                cin >> radio;
            }

            cout << "\nEntre la altura del cilindro: ";
            cin >> altura;
            while (altura <= 0) {
                cout << "\nLa altura debe ser un numero positivo positivo. Entre la altura del cilindro: ";
                cin >> altura;
            }

            if (Calculo == 'a') {
                cout << "\nEl volumen del cilindro es " << Volumen(radio, altura) << "\n";
            } else {
                cout << "\nEl área de la superficie del cilindro es " << Area(radio, altura) << "\n";
            }
            break;
        
        case 'b': // para el caso de la esfera
            cout << "\nEntre el radio de la esfera: ";
            cin >> radio;
            while (radio <= 0) {
                cout << "\nEl radio debe ser un numero positivo. Entre el radio de la esfera: " << endl;
                cin >> radio;
            }

            if (Calculo == 'a') {
                cout << "\nEl volumen de la esfera es " << Volumen(radio) << "\n";
            } else {
                cout << "\nEl área de la superficie de la esfera es " << Area(radio) << "\n";
            }
            break;
        
        case 'c': // para el caso del prisma rectangular
            cout << "\nEntre el largo del prisma: ";
            cin >> largo;
            while (largo <= 0) {
                cout << "\nEl largo debe ser un numero positivo. Entre el largo del prisma: ";
                cin >> largo;
            }

            cout << "\nEntre el ancho del prisma: ";
            cin >> ancho;
            while (ancho <= 0) {
                cout << "\nEl ancho debe ser un numero positivo. Entre el ancho del prisma: ";
                cin >> ancho;
            }

            cout << "\nEntre la altura del prisma: ";
            cin >> altura;
            while (altura <= 0) {
                cout << "\nLa altura debe ser un numero positivo. Entre la altura del prisma: ";
                cin >> altura;
            }

            if (Calculo == 'a') {
                cout << "\nEl volumen del prisma rectangular es " << Volumen(largo, ancho, altura) << "\n";
            } else {
                cout << "\nEl área de la superficie del prisma rectangular es " << Area(largo, ancho, altura) << "\n";
            }
            break;
    }

    return 0;
}

