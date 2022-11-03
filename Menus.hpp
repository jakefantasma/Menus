#pragma once
#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>
namespace MH
{ // clases
    class Fnc
    {
    private:
        int _key;
        std::string _desc;
        void (*_metodo)();

    public:
        Fnc(int key_, void (*metodo_)(), std::string desc_)
        {
            _key = key_;
            _metodo = metodo_;
            _desc = desc_;
        };
        int getKey()
        {
            return _key;
        }
        std::string getDes()
        {
            return _desc;
        }
        void CallFnc()
        {
            _metodo();
        }
        std::string getInfo()
        {
            char c = char(_key);
            std::string f = std::string(1, c);
            std::string tmp = f + ") " + _desc;
            return tmp;
        }
        ~Fnc();
    };
    class Menus
    {
    private:
        // variables
        std::string _title;
        bool _show = true;
        float _sleep = 50;
        std::vector<std::string> _info;
        std::vector<Fnc *> _listFnc;
        // is need to add funcion to set potition text <-
        const int _info_x = 2, _info_y = 2;
        void showInfo(int x, int y)
        {
            for (int i = 0; i < _info.size(); i++)
            {
                Console->gotoxy(x, y + i);
                Console->log(_info[i]);
            }
        }
        void showOpKey(int x, int y)
        {
            for (int i = 0; i < _listFnc.size(); i++)
            {
                Console->gotoxy(x, y + i);
                Fnc *fn = _listFnc[i];
                Console->log(fn->getInfo());
            }
        }
        // clear
        int _areaClear_x = 25;
        int _areaKey = 17;
        std::string _ch_clear = "  ";
    public:
        Menus(){};
        void addOp(char key, void (*fc)(), std::string desc)
        {
            _listFnc.push_back(new Fnc(key, fc, desc));
        };
        void setTitle(std::string title_)
        {
            _title = title_;
        }
        void addInfo(std::string line)
        {
            _info.push_back(line);
        }
        void close()
        {
            _show = false;
        }
        // key handler key
        void HandlerKey()
        {
            // validamos la lista de funciones y ejecutamos los metodos con las claves
            if (kbhit())
            {
                int key = getch();
                Console->gotoxy(25, 25);
                Console->setColor(6);
                std::cout << "key: " << key;
                for (int i = 0; i < _listFnc.size(); i++)
                {
                    Fnc *fnc = _listFnc[i];
                    if (fnc->getKey() == key)
                    {
                        fnc->CallFnc();
                    }
                }
            }
        }
        std::string mChar(std::string ch, int rep)
        {
            std::string tmp = "";
            for (int i = 0; i < rep; i++)
            {
                tmp = tmp + ch;
            }
            return tmp;
        }
        void clear()
        {
            for (int i = 0; i < _areaClear_x; i++)
            {
                Console->gotoxy(0, i);
                std::cout << mChar(_ch_clear, 40);
            }
        }
        void show()
        {
            _show = true;
            while (_show)
            {
                clear();
                Console->setTitle(_title);
                showInfo(_info_x, _info_y);
                showOpKey(3, _areaKey);
                HandlerKey();
                Sleep(_sleep);
            }
        }
        ~Menus();
    };
}