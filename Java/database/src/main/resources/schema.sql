-- 1) Crea Tabella prodotti
create table if not exists prodotti(
	id int auto_increment,
	nome varchar(50),
	prezzo decimal(6, 2),
    quantita int
	check (quantita < 100),
    constraint pk_id_prodotti primary key(id)
);

-- 2) Modifica tabella prodotti
alter table 
	prodotti 
add 
    descrizione varchar(100)
after
	nome;
    