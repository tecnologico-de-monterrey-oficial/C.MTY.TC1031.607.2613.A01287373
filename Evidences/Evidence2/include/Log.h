

// Carolina Vildósola Guzmán A01287373

#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Log {
    string mes;
    int dia;
    int anio;
    string hora;
    string ip;
    string descripcion;

    // Guarda el orden en el que llego el registro
    int ordenLlegada;

    // Constructor
    Log() {
        mes = "";
        dia = 0;
        anio = 0;
        hora = "";
        ip = "";
        descripcion = "";
        ordenLlegada = 0;
    }

    // convierte el mes a numero
    int numeroMes() const {
        if (mes == "Jan") return 1;
        if (mes == "Feb") return 2;
        if (mes == "Mar") return 3;
        if (mes == "Apr") return 4;
        if (mes == "May") return 5;
        if (mes == "Jun") return 6;
        if (mes == "Jul") return 7;
        if (mes == "Aug") return 8;
        if (mes == "Sep") return 9;
        if (mes == "Oct") return 10;
        if (mes == "Nov") return 11;
        if (mes == "Dec") return 12;

        return 0;
    }

    // crea una clave para comparar las fechas
    long long claveFecha() const {
        int horas = 0;
        int minutos = 0;
        int segundos = 0;
        char separador1, separador2;

        stringstream ss(hora);
        ss >> horas >> separador1 >> minutos >> separador2 >> segundos;

        long long clave = anio;
        clave = clave * 100 + numeroMes();
        clave = clave * 100 + dia;
        clave = clave * 100 + horas;
        clave = clave * 100 + minutos;
        clave = clave * 100 + segundos;

        return clave;
    }

    // compara dos registros por fecha y hora
    bool operator<(const Log& otro) const {
        if (claveFecha() == otro.claveFecha()) {
            return ordenLlegada < otro.ordenLlegada;
        }

        return claveFecha() < otro.claveFecha();
    }

    // muestra el registro completo
    void mostrar() const {
        cout << mes << " "
             << dia << " "
             << anio << " "
             << hora << " "
             << ip << " "
             << descripcion << endl;
    }
};