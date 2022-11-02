#include "./Console/Console.hpp"
#include <iostream>
#include "./Menus.hpp"
MH::Menus *MainMenu = new MH::Menus();
MH::Menus *Cliente = new MH::Menus();
MH::Menus *CrearOrden = new MH::Menus();
int main()
{
    CrearOrden->setTitle("Crear orden");
    CrearOrden->addInfo("Para generar una orden es neceario contar ");
    CrearOrden->addInfo("con una cuenta y estara afiliado a RTO ");
    CrearOrden->addInfo("esta tramite es personal");
    CrearOrden->addOp(
        48, []()
        { CrearOrden->close(); },
        "regresar");
    Cliente->setTitle("ventana cliente");
    Cliente->addInfo("en este apartado se podra generar una orden ");
    Cliente->addInfo("el cliente contara con opciones simples y faciles ");
    Cliente->addInfo("de gestionar y de controlar ");
    Cliente->addOp(
        48, []()
        { Cliente->close(); },
        "regresar");
    Cliente->addOp(
        50, []()
        { CrearOrden->show(); },
        "crear orden");
    Cliente->addOp(
        51, []() {},
        "garantia");
    // menu principal
    MainMenu->setTitle("ventana principal");
    MainMenu->addInfo("esta es una muestra de las ventanas interactivas");
    MainMenu->addInfo("pretende dar una interfaz amigable al usuario ");
    MainMenu->addInfo("con metodos simples de aplicar para el developer ");
    MainMenu->addOp(
        49, []()
        { Cliente->show(); },
        "Cliente");
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