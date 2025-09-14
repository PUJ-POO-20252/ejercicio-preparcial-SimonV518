#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// --------------------- EJERCICIO 1 ---------------------
// Pedir 8 notas y mostrar:
// cuántos aprobaron, reprobaron, cuántos sacaron excelente (>=4.5)
// y el promedio del curso
void ejercicio1() {
    vector<float> notas(8);
    int aprobados = 0, reprobados = 0, excelentes = 0;
    float suma = 0;

    cout << "\nEJERCICIO 1\n";
    for (int i = 0; i < 8; i++) {
        cout << "Ingrese la nota del estudiante " << i+1 << ": ";
        cin >> notas[i];

        suma += notas[i]; // acumula para promedio
        if (notas[i] >= 3.0) aprobados++;
        else reprobados++;
        if (notas[i] >= 4.5) excelentes++;
    }
    // resultados
    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
    cout << "Excelentes: " << excelentes << endl;
    cout << "Promedio del curso: " << (suma/8) << endl;
}

// --------------------- EJERCICIO 2 ---------------------
// Leer edad y nota (1 a 10) hasta que la edad sea 0
// Mostrar total de personas, promedio de notas, cuántos son jóvenes (18-25)
// y cuántos sacaron 10
void ejercicio2() {
    int edad;
    float nota;
    int total = 0, jovenes = 0, perfectos = 0;
    float suma = 0;

    cout << "\nEJERCICIO 2\n";
    while (true) {
        cout << "Ingrese edad (0 para terminar): ";
        cin >> edad;
        if (edad == 0) break; // condición de salida

        cout << "Ingrese calificacion (1 a 10): ";
        cin >> nota;

        total++;
        suma += nota;
        if (edad >= 18 && edad <= 25) jovenes++;
        if (nota == 10) perfectos++;
    }

    if (total > 0) {
        cout << "Total personas: " << total << endl;
        cout << "Promedio de calificaciones: " << (suma/total) << endl;
        cout << "Personas jovenes (18 a 25): " << jovenes << endl;
        cout << "Personas con nota 10: " << perfectos << endl;
    } else {
        cout << "No se ingreso ningun dato\n";
    }
}

// --------------------- EJERCICIO 3 ---------------------
// Leer n números y decir si están en orden estrictamente ascendente
void ejercicio3() {
    int n;
    cout << "\nEJERCICIO 3\n";
    cout << "Cuantos numeros va a ingresar? ";
    cin >> n;

    int anterior, actual;
    bool ascendente = true;
    // primero número
    cout << "Ingrese el numero 1: ";
    cin >> anterior;
    // ciclo desde el 2 hasta n
    for (int i = 2; i <= n; i++) {
        cout << "Ingrese el numero " << i << ": ";
        cin >> actual;
        if (actual <= anterior) ascendente = false;
        anterior = actual;
    }

    if (ascendente) cout << "La secuencia esta en orden ascendente\n";
    else cout << "La secuencia NO esta en orden ascendente\n";
}

// --------------------- EJERCICIO 4 ---------------------
// Calcular el total a pagar con descuentos
// segun la cantidad comprada
void ejercicio4() {
    float precio;
    int cantidad;
    cout << "\nEJERCICIO 4\n";
    cout << "Ingrese el precio unitario: ";
    cin >> precio;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    float descuento = 0;
    if (cantidad >= 11 && cantidad <= 20) descuento = 0.05;
    else if (cantidad >= 21 && cantidad <= 50) descuento = 0.10;
    else if (cantidad > 50) descuento = 0.15;

    float total = precio * cantidad * (1 - descuento);
    cout << "Total a pagar: " << total << endl;
}

// --------------------- EJERCICIO 5 ---------------------
// Leer una palabra y mostrar el primer caracter
// que no se repite
void ejercicio5() {
    string palabra;
    cout << "\nEJERCICIO 5\n";
    cout << "Ingrese una palabra en minusculas: ";
    cin >> palabra;

    for (int i = 0; i < palabra.length(); i++) {
        bool seRepite = false;
        for (int j = 0; j < palabra.length(); j++) {
            if (i != j && palabra[i] == palabra[j]) {
                seRepite = true;
                break;
            }
        }
        if (!seRepite) {
            cout << "Primer caracter no repetido: " << palabra[i] << endl;
            return;
        }
    }
    cout << "Todos los caracteres se repiten\n";
}

// --------------------- EJERCICIO 6 ---------------------
// Mostrar los n primeros números de la serie Fibonacci
void ejercicio6() {
    int n;
    cout << "\nEJERCICIO 6\n";
    cout << "Cuantos numeros de Fibonacci quiere ver? ";
    cin >> n;

    int a = 0, b = 1, c;
    cout << "Secuencia: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// --------------------- MENU ---------------------
int main() {
    int opcion;

    do {
        cout << "\n===== MENU DE EJERCICIOS =====\n";
        cout << "1. Calificaciones de 8 estudiantes\n";
        cout << "2. Encuesta de satisfaccion\n";
        cout << "3. Secuencia ascendente\n";
        cout << "4. Descuento en tienda\n";
        cout << "5. Primer caracter no repetido\n";
        cout << "6. Serie de Fibonacci\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "⚠ Entrada no valida, intente de nuevo.\n";
            opcion = -1; // forzar que siga en el menú
            continue;
        }

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}
