USE its_2024;

-- 1) Quali sono i nomi completi egli studenti
select concat(nome, ' ', cognome) as Nomi_Completi
from studenti
order by nome;

-- 2) corsi disponibili e quanti crediti offrono
select nomecorso, crediti from corsi;

-- 3) docenti e le loro email
select concat(nome, ' ', cognome) as Nomi_Completi, email from docenti;

-- 4) Quali esami sono stati sostenuti da uno specific studente
select * from esami where matricola = 1001;

-- 5) voti studenti in un corso specifico
select concat(studenti.nome, ' ', studenti.cognome) as nomi_completi,
		esami.data, esami.codCorso,
        esami.voto 
from esami
inner join studenti
on studenti.matricola = esami.matricola
 where esami.codcorso = 101;
 
 -- 5) secondo modo
select concat(studenti.nome, ' ', studenti.cognome) as nomi_completi,
		esami.data, esami.codCorso,
        esami.voto 
from esami, studenti
where esami.codcorso = 101
and
studenti.matricola = esami.matricola;

 
 -- 6) studenti che hanno superato determinato corso con voto > 25
select concat(s.nome, ' ', s.cognome) as nomi_completi,
		e.data, e.codCorso,
        e.voto 
from esami e
inner join studenti s
on s.matricola = e.matricola
 where e.codcorso = 101
 and 
 e.voto > 25;
 
 -- 7) media voti studenti in tutti i corsi
 select avg(voto) as media from esami;
 
  -- 7) media voti studenti in un corso
 select matricola, avg(voto) as media, codcorso
 from esami
 where codcorso = 101
 group by matricola order by matricola;
 
 -- 8) corsi media alta
 select c.nomecorso, count(e.voto) as quanti,sum(e.voto) as totale, avg(e.voto) as media 
 from esami e inner join corsi c
 on e.codcorso= c.codcorso
 group by c.nomecorso
 order by avg(e.voto) desc;
 
 select * from corsi;
 
 -- 9) corsi non sostenuti
 select c.nomecorso
 from corsi c
 where c.codcorso
not in 
(select codcorso from esami)
 ;
 
 select c.nomecorso
 from corsi c, esami e
 where c.codcorso = e.codcorso
 and e.matricola is null;
 
 -- 9bis) studenti con 27 e 29
 select s.cognome, e.voto, c.nomecorso
 from studenti s, esami e, corsi c 
 where s.matricola = e.matricola
 and e.codcorso = c.codcorso
 -- and (e.voto = 27 or e.voto = 29)
 and e.voto in(27,29);
 
 
 -- 10) corsi di un docente
 select c.nomecorso as Corso, d.cognome as Cognome
 from corsi c, docenti d
 where c.coddocente = d.coddocente
 and d.cognome = "Ricci";
 
