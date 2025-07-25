BEGIN TRANSACTION;

-- Tabela Cliente
INSERT INTO Cliente (nome, cpf, data_nascimento, genero) VALUES
('Ana Souza', 12345678901, '1990-05-15', 'F'),
('Carlos Lima', 23456789012, '1985-09-22', 'M'),
('Beatriz Martins', 34567890123, '2000-01-10', 'F');

-- Tabela TipoTrufa
INSERT INTO TipoTrufa (id_tipo_trufa, tipo_trufa) VALUES
(1, 'Tradicional'),
(2, 'Recheada'),
(3, 'Diet');

-- Tabela SaborTrufa
INSERT INTO SaborTrufa (id_sabor_trufa, sabor) VALUES
(1, 'Chocolate ao Leite'),
(2, 'Chocolate Branco'),
(3, 'Morango'),
(4, 'Maracujá'),
(5, 'Avelã');

-- Tabela Trufa (relacionando tipo + sabor)
INSERT INTO Trufa (id_tipo_trufa, id_sabor_trufa, preco, estoque) VALUES
(1, 1, 3.50, 30), -- Tradicional / Chocolate ao Leite
(1, 2, 3.50, 25), -- Tradicional / Branco
(2, 3, 4.00, 20), -- Recheada / Morango
(2, 4, 4.00, 22), -- Recheada / Maracujá
(3, 5, 5.00, 15); -- Diet / Avelã

-- Tabela Pedido
INSERT INTO Pedido (id_cliente, data_pedido) VALUES
(1, '2025-07-20 14:30:00'),
(2, '2025-07-21 09:00:00');

-- Tabela ItemPedido (relacionando pedido com trufas)
INSERT INTO ItemPedido (id_pedido, id_trufa, quantidade, total_pedido) VALUES
(1, 1, 3, 10.50), -- Pedido 1, 3x trufa id 1 (3.50)
(1, 2, 2, 7.00),  -- Pedido 1, 2x trufa id 2
(2, 3, 1, 4.00),  -- Pedido 2, 1x trufa id 3
(2, 5, 2, 10.00); -- Pedido 2, 2x trufa id 5

COMMIT;
