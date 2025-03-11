#include <iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void limpiar() {
    system("cls");
}

// Definimos la clase CuentaBancaria para manejar cuentas bancarias
class CuentaBancaria {
private:
    double Saldo;       // Saldo de la cuenta
    string Idcuenta;    // Identificador de la cuenta
    bool Activada, Bloqueada; // Estado de la cuenta (activa o bloqueada)
    int Intentos;       // Contador de intentos fallidos de retiro

public:
    // Constructor con valores por defecto
    CuentaBancaria(double saldo = 1000, bool activada = true, bool bloqueada = false, string idcuenta = "0000")
        : Saldo(saldo), Activada(activada), Bloqueada(bloqueada), Idcuenta(idcuenta), Intentos(0) {
    }

    // Método para depositar dinero en la cuenta
    void depositar(double monto) {
        if (Bloqueada) { // No se puede depositar si la cuenta está bloqueada
            cout << "Error: No se puede depositar en una cuenta bloqueada.\n";
            return;
        }
        if (!Activada) { // No se puede depositar si la cuenta está inactiva
            cout << "Error: No se pueden hacer depósitos en cuentas inactivas.\n";
            return;
        }
        Saldo += monto; // Se suma el monto al saldo
        cout << "Depósito exitoso. Saldo actual: " << Saldo << endl;
    }

    // Método para retirar dinero de la cuenta
    void retirar(double monto) {
        if (Bloqueada) { // No se puede retirar si la cuenta está bloqueada
            cout << "Error: No se pueden hacer retiros en cuentas bloqueadas.\n";
            return;
        }
        if (monto > Saldo) { // Si el monto a retirar es mayor que el saldo
            cout << "Fondos insuficientes.\n";
            Intentos++; // Se incrementa el contador de intentos fallidos
            if (Intentos > 3) { // Si hay más de 3 intentos fallidos, la cuenta se bloquea
                Bloqueada = true;
                cout << "Cuenta bloqueada por demasiados intentos fallidos.\n";
            }
            return;
        }

        Saldo -= monto; // Se resta el monto del saldo
        cout << "Retiro exitoso. Saldo actual: " << Saldo << endl;

        if (Saldo < 100) { // Advertencia si el saldo es bajo
            cout << "Advertencia: Su saldo es bajo.\n";
        }
    }

    // Método para consultar el saldo de la cuenta
    void mostrarSaldo() {
        cout << "Su saldo es: " << Saldo << endl;
    }

    // Método para verificar si la cuenta está activa o bloqueada
    void verificarEstado() {
        if (Bloqueada) {
            cout << "La cuenta está BLOQUEADA.\n";
        }
        else {
            cout << "La cuenta está ACTIVA.\n";
        }
    }
};

int main() {
    // Definimos 30 cuentas bancarias
    CuentaBancaria cuenta1, cuenta2, cuenta3, cuenta4, cuenta5;
    CuentaBancaria cuenta6, cuenta7, cuenta8, cuenta9, cuenta10;
    CuentaBancaria cuenta11, cuenta12, cuenta13, cuenta14, cuenta15;
    CuentaBancaria cuenta16, cuenta17, cuenta18, cuenta19, cuenta20;
    CuentaBancaria cuenta21, cuenta22, cuenta23, cuenta24, cuenta25;
    CuentaBancaria cuenta26, cuenta27, cuenta28, cuenta29, cuenta30;

    int opcione; // Variable para almacenar la opción del menú
    double monto; // Variable para el monto de depósito o retiro
    int idCuenta; // Variable para el número de cuenta seleccionada

    do {

        // Menú de opciones
        int x = 30, y = 5;

        gotoxy(x, y);     cout << "--- Menú ---";
        gotoxy(x, y + 1); cout << "1. Depositar";
        gotoxy(x, y + 2); cout << "2. Retirar";
        gotoxy(x, y + 3); cout << "3. Consultar saldo";
        gotoxy(x, y + 4); cout << "4. Verificar estado de la cuenta";
        gotoxy(x, y + 5); cout << "5. Salir";
        gotoxy(x, y + 7); cout << "Ingrese la opción: ";
        cin >> opcione;

        if (opcione >= 1 && opcione <= 4) {
            gotoxy(x, y + 9);
            cout << "Ingrese el número de cuenta (1-30): ";
            cin >> idCuenta;

            if (idCuenta < 1 || idCuenta > 30) {
                gotoxy(x, y + 10);
                cout << "Número de cuenta inválido.\n";
            }
        
            // Seleccionamos la cuenta usando una estructura ternaria
            CuentaBancaria& cuentaSeleccionada =
                (idCuenta == 1) ? cuenta1 : (idCuenta == 2) ? cuenta2 : (idCuenta == 3) ? cuenta3 :
                (idCuenta == 4) ? cuenta4 : (idCuenta == 5) ? cuenta5 : (idCuenta == 6) ? cuenta6 :
                (idCuenta == 7) ? cuenta7 : (idCuenta == 8) ? cuenta8 : (idCuenta == 9) ? cuenta9 :
                (idCuenta == 10) ? cuenta10 : (idCuenta == 11) ? cuenta11 : (idCuenta == 12) ? cuenta12 :
                (idCuenta == 13) ? cuenta13 : (idCuenta == 14) ? cuenta14 : (idCuenta == 15) ? cuenta15 :
                (idCuenta == 16) ? cuenta16 : (idCuenta == 17) ? cuenta17 : (idCuenta == 18) ? cuenta18 :
                (idCuenta == 19) ? cuenta19 : (idCuenta == 20) ? cuenta20 : (idCuenta == 21) ? cuenta21 :
                (idCuenta == 22) ? cuenta22 : (idCuenta == 23) ? cuenta23 : (idCuenta == 24) ? cuenta24 :
                (idCuenta == 25) ? cuenta25 : (idCuenta == 26) ? cuenta26 : (idCuenta == 27) ? cuenta27 :
                (idCuenta == 28) ? cuenta28 : (idCuenta == 29) ? cuenta29 : cuenta30;

            // Ejecutamos la acción correspondiente según la opción del menú
            switch (opcione) {
            case 1:
                cout << "Ingrese monto a depositar: ";
                cin >> monto;
                cuentaSeleccionada.depositar(monto);
                break;
            case 2:
                cout << "Ingrese monto a retirar: ";
                cin >> monto;
                cuentaSeleccionada.retirar(monto);
                break;
            case 3:
                cuentaSeleccionada.mostrarSaldo();
                break;
            case 4:
                cuentaSeleccionada.verificarEstado();
                break;
            }
        }
        
        system("cls"); // Limpiar la pantalla
    } while (opcione != 5); // El programa sigue ejecutándose hasta que se elija la opción 5 (salir)
    

    return 0; // Fin del programa
}
// Que aprendi?
// lo que aprendi seria a reinventar algo que normalmente usaba que eran los punteros, matrices,vectores o arreglos ya que realmente nunca habia hecho un programa que pidiera modificar
//tantas objetos y fue un reto nuevo tratar de manejar varias datos para varias cuentas en este caso fue un reto imaginar y poder llevarlo al codigo pero es util ya que gracias ah esto
//ahora siento que puedo manejar los punteros, matrices y vectores de manera mas eficente y puedo hacerlo tambien de forma manueal 
