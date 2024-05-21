package repos;

import java.util.List;

import model.Esame;

public interface EsameDAO {
	String FIND_ALL = "select * from esami";
	String ADD_ESAME= "insert into esami(matricola, cod_corso, data, voto) values(?,?,?,?)";

	List<Esame> getAll();
	void addEsame(Esame e);

}
