#ifndef MENUPEDIDO_H
#define MENUPEDIDO_H


class MenuPedido
{
    public:
        static void inserirPedido();
        static void inserirItemPedido(int idPedido, int idTrufa, int quantidade);
        static void listarPedidos();
        static void mostrarMenu();
};

#endif // MENUPEDIDO_H
