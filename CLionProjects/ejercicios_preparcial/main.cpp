// main.cpp
// Menú interactivo con los ejercicios 1..6 (versión limpia para CLion)
// Compilar con C++17

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>

using namespace std;

void waitEnter() {
    cout << "\nPresiona Enter para continuar...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string dummy;
    getline(cin, dummy);
}

double readDouble(const string &prompt) {
    double x;
    while (true) {
        cout << prompt;
        if (cin >> x) break;
        cout << "Entrada invalida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}

long long readLongLong(const string &prompt) {
    long long x;
    while (true) {
        cout << prompt;
        if (cin >> x) break;
        cout << "Entrada invalida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}

int readInt(const string &prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) break;
        cout << "Entrada invalida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}

void ejercicio1() {
    cout << "Ejercicio 1 - Analisis de 8 calificaciones\n";
    const int N = 8;
    double sumaTotal = 0.0;
    int contadorAprobados = 0;
    int contadorReprobados = 0;
    int contadorExcelentes = 0;

    for (int i = 1; i <= N; ++i) {
        double nota = readDouble("Ingrese la calificacion #" + to_string(i) + ": ");
        sumaTotal += nota;
        if (nota >= 4.5) { contadorExcelentes++; contadorAprobados++; }
        else if (nota >= 3.0) { contadorAprobados++; }
        else contadorReprobados++;
    }

    double promedio = sumaTotal / N;
    cout << fixed << setprecision(2);
    cout << "\nResultados:\n";
    cout << "Aprobados: " << contadorAprobados << "\n";
    cout << "Reprobados: " << contadorReprobados << "\n";
    cout << "Excelentes: " << contadorExcelentes << "\n";
    cout << "Promedio general: " << promedio << "\n";

    waitEnter();
}

void ejercicio2() {
    cout << "Ejercicio 2 - Encuesta por edades (edad=0 termina)\n";
    int edad;
    int totalEncuestados = 0;
    double sumaCalificaciones = 0.0;
    int contadorJovenes = 0;
    int contadorCalificacionPerfecta = 0;

    while (true) {
        edad = readInt("Ingrese la edad (0 para terminar): ");
        if (edad == 0) break;
        double calificacion = readDouble("Ingrese la calificacion del servicio (0-10): ");
        totalEncuestados++;
        sumaCalificaciones += calificacion;
        if (edad >= 18 && edad <= 25) contadorJovenes++;
        if (calificacion == 10.0) contadorCalificacionPerfecta++;
    }

    cout << fixed << setprecision(2);
    cout << "\nReporte final:\n";
    cout << "Total de encuestados: " << totalEncuestados << "\n";
    if (totalEncuestados > 0) {
        cout << "Promedio de calificaciones: " << (sumaCalificaciones / totalEncuestados) << "\n";
    } else {
        cout << "No se ingresaron datos para calcular promedio.\n";
    }
    cout << "Personas entre 18 y 25 años: " << contadorJovenes << "\n";
    cout << "Personas que dieron calificacion perfecta (10): " << contadorCalificacionPerfecta << "\n";

    waitEnter();
}

void ejercicio3() {
    cout << "Ejercicio 3 - Validar secuencia ascendente\n";
    int n = readInt("Cuantos numeros va a ingresar? ");
    if (n <= 0) { cout << "Numero de elementos debe ser positivo.\n"; waitEnter(); return; }
    if (n == 1) { cout << "Con un solo numero la secuencia se considera ascendente.\n"; waitEnter(); return; }

    long long anterior = readLongLong("Ingrese numero 1: ");
    bool esAscendente = true;
    for (int i = 2; i <= n; ++i) {
        long long actual = readLongLong("Ingrese numero " + to_string(i) + ": ");
        if (actual <= anterior) esAscendente = false;
        anterior = actual;
    }

    cout << (esAscendente ? "La secuencia es estrictamente ascendente.\n" : "La secuencia NO es estrictamente ascendente.\n");
    waitEnter();
}

void ejercicio4() {
    cout << "Ejercicio 4 - Factura con descuento por volumen\n";
    double precioUnitario = readDouble("Ingrese el precio unitario del producto: ");
    int cantidad = readInt("Ingrese la cantidad de unidades a comprar: ");

    double porcentajeDescuento = 0.0;
    if (cantidad >= 11 && cantidad <= 20) porcentajeDescuento = 0.05;
    else if (cantidad >= 21 && cantidad <= 50) porcentajeDescuento = 0.10;
    else if (cantidad > 50) porcentajeDescuento = 0.15;

    double subtotal = precioUnitario * cantidad;
    double montoDescuento = subtotal * porcentajeDescuento;
    double totalPagar = subtotal - montoDescuento;

    cout << fixed << setprecision(2);
    cout << "\nFactura de Compra\n";
    cout << "Precio unitario: $" << precioUnitario << "\n";
    cout << "Cantidad: " << cantidad << "\n";
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Porcentaje de descuento: " << (porcentajeDescuento * 100.0) << "%\n";
    cout << "Descuento aplicado: $" << montoDescuento << "\n";
    cout << "TOTAL A PAGAR: $" << totalPagar << "\n";

    waitEnter();
}

void ejercicio5() {
    cout << "Ejercicio 5 - Primer caracter no repetido en una palabra\n";
    cout << "Ingrese una palabra (sin espacios, en minusculas): ";
    string palabra;
    cin >> palabra;
    vector<int> contador(256, 0);
    for (unsigned char c : palabra) contador[c]++;
    char primerUnico = '\0';
    for (unsigned char c : palabra) if (contador[c] == 1) { primerUnico = c; break; }
    if (primerUnico) cout << "El primer caracter unico es: '" << primerUnico << "'\n";
    else cout << "En la palabra '" << palabra << "' todos los caracteres se repiten.\n";
    waitEnter();
}

void ejercicio6() {
    cout << "Ejercicio 6 - Generador de Fibonacci\n";
    int n = readInt("Ingrese n (cantidad de terminos a generar): ");
    if (n <= 0) { cout << "(ninguno)\n"; waitEnter(); return; }
    cout << "Secuencia de Fibonacci: ";
    if (n == 1) cout << "0\n";
    else {
        long long a = 0, b = 1;
        cout << a << " " << b;
        for (int i = 3; i <= n; ++i) {
            long long c = a + b;
            cout << " " << c;
            a = b; b = c;
        }
        cout << "\n";
    }
    waitEnter();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cout << "\n=========================================\n";
        cout << "  Menu de ejercicios (CLion / C++)\n";
        cout << "  1. Ejercicio 1 - Analisis de 8 calificaciones\n";
        cout << "  2. Ejercicio 2 - Encuesta por edades (hasta edad=0)\n";
        cout << "  3. Ejercicio 3 - Validar secuencia ascendente\n";
        cout << "  4. Ejercicio 4 - Factura con descuento por volumen\n";
        cout << "  5. Ejercicio 5 - Primer caracter no repetido\n";
        cout << "  6. Ejercicio 6 - Generar Fibonacci (n terminos)\n";
        cout << "  0. Salir\n";
        cout << "Seleccione una opcion: ";

        int opcion;
        if (!(cin >> opcion)) {
            cout << "Opcion invalida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 0: cout << "Saliendo... hasta luego.\n"; return 0;
            default: cout << "Opcion no valida. Intente de nuevo.\n"; break;
        }
    }
    return 0;
}
