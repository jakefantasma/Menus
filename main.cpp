#include "./Console/Console.hpp"
#include <iostream>
#include "./Menus.hpp"
MH::Menus *MainMenu = new MH::Menus();
MH::Menus *Publico = new MH::Menus();
MH::Menus *Qa = new MH::Menus();
MH::Menus *Tecnicos = new MH::Menus();
MH::Menus *Reporte = new MH::Menus();
int main()
{

    //manager reportes
    Reporte->setTitle("manager");
    Reporte->addInfo("REPORTE TOTAL");
    Reporte->addInfo("");
    Reporte->addInfo("gestor de reportes");
    Reporte->addOp(
        49, []()
        { Tecnicos->close(); },
        "Listado de Ingreso");
    Reporte->addOp(
        50, []()
        { Tecnicos->close(); },
        "Listado de tecnico A");
    Reporte->addOp(
        51, []()
        { Tecnicos->close(); },
        "Listado de tecnico B");
    Reporte->addOp(
        52, []()
        { Tecnicos->close(); },
        "Listado de tecnico C");
    Reporte->addOp(
        53, []()
        { Tecnicos->close(); },
        "Listado de contro de calidad");
    Reporte->addOp(
        54, []()
        { Tecnicos->close(); },
        "Listado de ordenes");
    Reporte->addOp(
        55, []()
        { Tecnicos->close(); },
        "Punteo");
    Reporte->addOp(
        48, []()
        { Reporte->close(); },
        "SALIR");
    // hdc
    Tecnicos->setTitle("it interface");
    Tecnicos->addInfo("SECCION DE TECNICOS");
    Tecnicos->addInfo("");
    Tecnicos->addInfo("Pendiente de listar los tecnicos disponibles !");
    Tecnicos->addOp(
        48, []()
        { Tecnicos->close(); },
        "SALIR");
    // calidad
    Qa->setTitle("qa interface");
    Qa->addInfo("CONTROL DE CALIDAD");
    Qa->addInfo("");
    Qa->addInfo("gestor de control de calidad");
    Qa->addOp(
        49, []() {},
        "Verificar Orden");
    Qa->addOp(
        50, []() {},
        "Listado de Ordenes");
    Qa->addOp(
        48, []()
        { Qa->close(); },
        "SALIR");
    // publico para usuario
    Publico->setTitle("user interface");
    Publico->addInfo("ATENCION AL PUBLICO");
    Publico->addInfo("");
    Publico->addInfo("Gestiones disponibles para usuarios");
    Publico->addOp(
        49, []() {},
        "Ingresar Orden");
    Publico->addOp(
        50, []() {},
        "Verificar Orden Lista");
    Publico->addOp(
        51, []() {},
        "Listado de Ordenes Lista");
    Publico->addOp(
        52, []() {},
        "Listado de Ordenes en Espera");
    Publico->addOp(
        53, []() {},
        "Buscar Orden");
    Publico->addOp(
        48, []()
        { Publico->close(); },
        "SALIR");
    // ventana principal
    MainMenu->setTitle("SISTEMA DE ORDENES");
    MainMenu->addInfo("");
    MainMenu->addInfo("Sistema desarollado para la implementacion de punteros para pilas y colas");
    MainMenu->addInfo("a) Publico");
    MainMenu->addInfo("     ");
    MainMenu->addInfo("     -Ingresar orden");
    MainMenu->addInfo("     -Verificar orden");
    MainMenu->addInfo("     -Listado ordenes lista");
    MainMenu->addInfo("     -Listado ordenes en espera");
    MainMenu->addInfo("     -Buscar orden");
    MainMenu->addInfo("b) Calidad");
    MainMenu->addInfo("     -Verificar orden");
    MainMenu->addInfo("     -Listado de ordenes");
    MainMenu->addInfo("c) Tecnicos");
    MainMenu->addInfo("     -Listado de tecnicos");
    MainMenu->addOp(
        97, []()
        { Publico->show(); },
        "Atencion al publico");
    MainMenu->addOp(
        98, []()
        { Qa->show(); },
        "Control de calidad");
    MainMenu->addOp(
        99, []()
        { Tecnicos->show(); },
        "Tecnicos");
    MainMenu->addOp(
        100, []()
        { Reporte->show(); },
        "Reporte total");
    MainMenu->addOp(
        48, []()
        { 
            Console->setColor(7);
            MainMenu->clear();
            MainMenu->close(); },
        "salir");
    MainMenu->show();
    return 0;
}