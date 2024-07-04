package com.gruppo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class Pj22SpringRelazioniApplication {

    public static void main(String[] args) {
        SpringApplication.run(Pj22SpringRelazioniApplication.class, args);
    }

//    @Bean
//    public CommandLineRunner gira(StudentiService service) {
//        return new CommandLineRunner() {
//
//            @Override
//            public void run(String... args) throws Exception {
//            	Corso c = new Corso();
//                c.setNome("Fintech23-25");
//
//                Studente s = new Studente();
//                s.setNome("Giulio");
//
//                Libretto l = new Libretto();
//                l.setNumeroMatricola("GLVA12");
//                l.setStudente(s);
//                s.setLibretto(l);
//
//                
//                service.addCorso(c);
//                s.setCorso(c);
//                service.addStudente(s);
//                c.getStudenti().add(s);
//
//                service.addLibretto(l);
//            }
//        };
//    }
}
