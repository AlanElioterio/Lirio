#ifndef SABORTRUFA_H
#define SABORTRUFA_H
#include <string>

using namespace std;
class SaborTrufa
{
    public:
        SaborTrufa(int id, string sabor);

        int Getid() { return id; }
        string GetSabor() { return sabor; }

    private:
        int id;
        string sabor;
};

#endif // SABORTRUFA_H
