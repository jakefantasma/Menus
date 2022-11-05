# Menus
permite gestionar un menu de opciones persistentes, con un pequeno panel de informacion, opciones y seleccion, por el momento permite desplegar.

- cambiar titulo
- agregar informacion
- agregar opcion de selccion (call back)
- mostrar el menu

## implementacion
Crea un nuevo objeto Menu al cual podremos modificarle caracteristicas.-
``` cpp
#include "./Console/Console.hpp"
#include "./Menus.hpp"
MH::Menus *MainMenu = new MH::Menus();
int main()
{
  MainMenu->setTitle("VENTANA DE MUESTRA");
  MainMenu->addInfo("-informacion para muestra de menu"); 
  MainMenu->addOp(
          97, []()
          { 
          //call back 
          },
          "opcion a seleccionar"
          );
  MainMenu->show();
  return 0;
}
```


> nota para la implementacion de Menus es necesario importar Console 
