#ifndef TIPOTRUFA_H
#define TIPOTRUFA_H

#include <string>

using namespace std;
class TipoTrufa
{
    public:
        TipoTrufa(int id, string tipoTrufa);

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        string GetTipoTrufa() { return tipoTrufa; }
        void SetTipoTrufa(string val) { tipoTrufa = val; }

    protected:

    private:
        int id;
        string tipoTrufa;
};

#endif // TIPOTRUFA_H
