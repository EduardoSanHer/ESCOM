
package pp_pma_she.practica_2_pp;


public class Test {
    public static void main(String[] args){
        
        //Alumnos
        Alumno A1 = new Alumno("Adriana Patlani Mauricio",20,"PAMA010321MTLTRDA2","2411036533","O+","patladyxwalker54@gmail.com","Femenino",2020630637);
        Alumno A2 = new Alumno("Eduardo Sandoval Hernandez",19,"SAHE011108HHGNRDA1","7731145074","O+","eduardosanher@gmail.com","Masculino",2020630632);
        Alumno A3 = new Alumno("Oscar Ramirez Vazquez",20,"RAVO001108HHFGRDA1","7731159536","O-","simpozkar@gmail.com","No binario",2020630666);
        Alumno A4 = new Alumno("Michelle Ramirez Vazquez",20,"RAVM000508HQWQRDA1","7731155566","O-","michellneni@gmail.com","Femenino",2020630600);
        Alumno A5 = new Alumno("Alejandra Guzman Jimenez",20,"GUJA000908HQWQRDA1","7731772266","O+","alejandraguzman@gmail.com","Femenino",2020630699);
        
        //Docentes
        Docente D1 = new Docente("Rafael Aguilar Garcia",40,"AGGR800908HQWQRDA1","7731774435","O+","rafaelaguilar@gmail.com","Masculino",1234567890,"ISC");
        
        //Tutores
        Tutor T1 = new Tutor("Karina Viveros Vazquez",50,"VIVK700904HQWQKLJ1","5512348965","O-","karinavv@gmail.com","Femenino",1234567891,"ISC");
        
        //Grupos
        Grupo G1 = new Grupo("3CM1");
        Grupo G2 = new Grupo("3CM2");
        
        //Materias
        Materia M1 = new Materia("Calculo", "CR7", 55, 20);
        Materia M2 = new Materia("Finanzas", "FN4", 55, 20);
        Materia M3 = new Materia("Bases de datos", "NA5", 40, 15);
        
        //Calificaciones
        Calificacion C1 = new Calificacion(M1);
        Calificacion C2 = new Calificacion(M2);
        Calificacion C3 = new Calificacion(M2,9);
        Calificacion C4 = new Calificacion(M3,7,7);
        Calificacion C5 = new Calificacion(M3,7,7,5);
        
        //Asignar docentes a materias
        D1.agregarMateria(M1);
        M1.agregarDocente(D1);
        D1.agregarMateria(M2);
        M2.agregarDocente(D1);
        T1.agregarMateria(M3);
        M3.agregarDocente(T1);
        
        //Inscribir alumnos a materias
        A1.agregarMateria(M1);
        M1.agregarAlumno(A1);
        //A2.agregarMateria(M2);
        A2.listaMaterias.add(M2);
        M2.agregarAlumno(A2);
        A3.agregarMateria(M1);
        M1.agregarAlumno(A3);
        A4.agregarMateria(M3);
        M3.agregarAlumno(A4);
        A5.agregarMateria(M3);
        M3.agregarAlumno(A5);
        
        //Agregar calificaciones a alumnos
        A1.agregarCalificacion(C1);
        A2.agregarCalificacion(C3);
        A3.agregarCalificacion(C1);
        A4.agregarCalificacion(C5);
        A5.agregarCalificacion(C4);
        
        //Asignar docentes a grupos
        D1.agregarGrupo(G1);
        G1.agregarMateria(M1);
        G1.agregarMateria(M2);
        T1.agregarGrupo(G2);
        G2.agregarMateria(M3);
        
        //Asignar grupos a alumnos
        A1.agregarGrupo(G1);
        //A2.agregarGrupo(G1);
        A2.listaGrupos.add(G1);
        A3.agregarGrupo(G1);
        A4.agregarGrupo(G2);
        A5.agregarGrupo(G2);
        
        //Reportar alumnos de un grupo
        System.out.println("-----------------");
        G1.obtenerAlumnos();
        System.out.println("-----------------");
        G2.obtenerAlumnos();
        
        //Reportar docentes a cargo de los grupos
        System.out.println("-----------------");
        G1.obtenerDocentes();
        System.out.println("-----------------");
        G2.obtenerDocentes();
        
        //Reportar calificaciones de alumnos
        System.out.println("-----------------");
        A1.obtenerCalificaciones();
        System.out.println("-----------------");
        A2.obtenerCalificaciones();
        System.out.println("-----------------");
        A3.obtenerCalificaciones();
        System.out.println("-----------------");
        A4.obtenerCalificaciones();
        System.out.println("-----------------");
        A5.obtenerCalificaciones();
        
        //Asignar y reportar los alumnos a cargo del tutor
        T1.agregarAlumno(A1);
        T1.agregarAlumno(A2);
        System.out.println("-----------------");
        T1.obtenerAlumnos();
        
        //Reportar static
        System.out.println("-----------------");
        System.out.println("El total de personas es: " + Persona.totalPersonas());
        System.out.println("El total de alumnos es: " + Alumno.totalAlumnos());
        System.out.println("El total de docentes es: " + Docente.totalDocentes());
        System.out.println("El total de tutores es: " + Tutor.totalTutores());
        
        //Redefinicion de metodos
        System.out.println("-----------------");
        System.out.println(D1);
        System.out.println("-----------------");
        System.out.println(T1);
        
    }
}
