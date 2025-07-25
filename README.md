# Lírio Azul - Sistema de Controle de Estoque de Trufas

Este é um sistema de controle de estoque de trufas desenvolvido em **C++ com SQLite**. O objetivo é permitir o gerenciamento de **clientes**, **trufas**, **pedidos** e **estoque**, de forma simples e eficiente via terminal.

---

## 📋 Funções Principais

### 🧍 Clientes
- Cadastro de clientes com nome, CPF, data de nascimento e gênero
- Listagem dos clientes registrados

### 🍬 Trufas
- Cadastro de trufas com tipo, sabor, preço e estoque
- Atualização e exclusão de trufas
- Listagem com tipo e sabor legível

### 🛒 Pedidos
- Criação de pedidos vinculados a um cliente
- Adição de múltiplas trufas por pedido
- Cálculo automático de total por item
- Desconto automático do estoque ao vender
 
---

## 🗃️ Estrutura do Banco (SQLite)

O sistema utiliza as seguintes tabelas:

- `Cliente`
- `TipoTrufa`
- `SaborTrufa`
- `Trufa`
- `Pedido`
- `ItemPedido`

Veja o arquivo `EsquemaLirio.sql` para detalhes da estrutura e chaves estrangeiras.

---

## 🧱 Tecnologias

- **Linguagem:** C++
- **Banco de Dados:** SQLite3
- **Bibliotecas:** `sqlite3.h`, `ctime`, `vector`, `iostream`

---
