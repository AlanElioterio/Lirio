#ifndef TIPOTRUFA_H
#define TIPOTRUFA_H

#include <string>

using namespace std;
class TipoTrufa
{
    public:
        TipoTrufa(int id, string tipoTrufa);

        int Getid() { return id; }
        string GetTipoTrufa() { return tipoTrufa; }

    protected:

    private:
        int id;
        string tipoTrufa;
};

#endif // TIPOTRUFA_H
