#ifndef SABORTRUFA_H
#define SABORTRUFA_H
#include <string>

using namespace std;
class SaborTrufa
{
    public:
        SaborTrufa(int id, string sabor);

        string GetSabor() { return sabor; }
        void SetSabor(string val) { sabor = val; }

        int Getid() { return id; }

    private:
        int id;
        string sabor;
};

#endif // SABORTRUFA_H
