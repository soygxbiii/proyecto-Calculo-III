//Gabriela Mora
//V-31.541.893
//Calculo III

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define MAX_N 1000

void sucesionT(int cantN, double T[]); //calcula los valores exactos T_n
void sucesionR(int cantN, double r[]); //calcula la sucesión recursiva r_n partiendo de r_0 = 0.99997
void sucesionP(int cantN, double p[]); //calcula la sucesión recursiva p_n con sus dos valores iniciales
void sucesionQ(int cantN, double q[]); //calcula la sucesión recursiva q_n con sus tres valores iniciales

void comparativa(int cantN, double T[], double r[], double p[], double q[]); //muestra en pantalla la tabla comparativa de T, r, p y q
void diferencias(int cantN, double T[], double r[], double p[], double q[]); //calcula y muestra las diferencias entre T y r, p, q

int main()
{
    int opcion, cantN;

    cout << "        Ingrese la cantidad maxima de iteraciones: ";
    cin >> cantN;

    if (cantN <= 0)
    {
        cout << "        Error: Valor invalido\n";
        return 1;
    }

    if (cantN > MAX_N)
    {
        cantN = MAX_N;
    }

    double T[MAX_N + 1];
    double r[MAX_N + 1];
    double p[MAX_N + 1];
    double q[MAX_N + 1];

    sucesionT(cantN, T);
    sucesionR(cantN, r);
    sucesionP(cantN, p);
    sucesionQ(cantN, q);

    do
    {
        cout << "\n";
        cout << "        ---------------------------------------------------------------------\n";
        cout << "        |                           MENU DE OPCIONES                        |\n";
        cout << "        |-------------------------------------------------------------------|\n";
        cout << "        | 1. Tabla comparativa de valores (T_n, r_n, p_n y q_n)             |\n";
        cout << "        | 2. Tabla de diferencias absolutas |T_n-r_n|, |T_n-p_n|, |T_n-q_n| |\n";
        cout << "        | 3. Mostrar ambas tablas                                           |\n";
        cout << "        | 4. Salir                                                          |\n";
        cout << "        ---------------------------------------------------------------------\n";
        cout << "        Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            comparativa(cantN, T, r, p, q);
        }
        else if (opcion == 2)
        {
            diferencias(cantN, T, r, p, q);
        }
        else if (opcion == 3)
        {
            comparativa(cantN, T, r, p, q);
            diferencias(cantN, T, r, p, q);
        }
        else if (opcion == 4)
        {
            cout << "\n        Saliendo del programa...\n\n";
        }
        else
        {
            cout << "\n        Opcion invalida. Intente de nuevo\n";
        }
    } while (opcion != 4);

    return 0;
}

void sucesionT(int cantN, double T[])
{
    int n;

    T[0] = 1.0;
    for (n = 1; n <= cantN; n++)
    {
        T[n] = T[n - 1] / 3.0;
    }
}

void sucesionR(int cantN, double r[])
{
    int n;

    r[0] = 0.99997;
    for (n = 1; n <= cantN; n++)
    {
        r[n] = r[n - 1] / 3.0;
    }
}

void sucesionP(int cantN, double p[])
{
    int n;

    p[0] = 1.0;
    p[1] = 0.33334;

    if (cantN >= 2)
    {
        for (n = 2; n <= cantN; n++)
        {
            p[n] = (10.0 / 3.0) * p[n - 1] - p[n - 2];
        }
    }
}

void sucesionQ(int cantN, double q[])
{
    int n;

    q[0] = 1.0;
    q[1] = 1.0 / 3.0;
    q[2] = 0.11112;

    if (cantN >= 3)
    {
        for (n = 3; n <= cantN; n++)
        {
            q[n] = (28.0 / 3.0) * q[n - 1] - 27.0 * q[n - 2] + 18.0 * q[n - 3];
        }
    }
}

void comparativa(int cantN, double T[], double r[], double p[], double q[])
{
    int n;
    cout << "\n";
    cout << "        -------------------------------------------------------------------------\n";
    cout << "        |  n   | Sucesion T_n  | Sucesion r_n  | Sucesion p_n  |  Sucesion q_n  |\n";
    cout << "        -------------------------------------------------------------------------\n";

    for (n = 0; n <= cantN; n++)
    {
        cout << "        | " << setw(4) << right << n
             << " | " << setw(13) << right << fixed << setprecision(8) << T[n]
             << " | " << setw(13) << right << fixed << setprecision(8) << r[n]
             << " | " << setw(13) << right << fixed << setprecision(8) << p[n]
             << " | " << setw(14) << right << fixed << setprecision(6) << q[n]
             << " |\n";
    }

    cout << "        -------------------------------------------------------------------------\n\n";
}

void diferencias(int cantN, double T[], double r[], double p[], double q[])
{
    int n;
    cout << "\n";
    cout << "        -------------------------------------------------------\n";
    cout << "        |  n   |  |T_n - r_n|  |  |T_n - p_n|  |  |T_n - q_n|  |\n";
    cout << "        -------------------------------------------------------\n";

    for (n = 0; n <= cantN; n++)
    {
        cout << "        | " << setw(4) << right << n
             << " | " << setw(13) << right << fixed << setprecision(8) << fabs(T[n] - r[n])
             << " | " << setw(13) << right << fixed << setprecision(8) << fabs(T[n] - p[n])
             << " | " << setw(13) << right << fixed << setprecision(4) << fabs(T[n] - q[n])
             << " |\n";
    }

    cout << "        -------------------------------------------------------\n\n";
}