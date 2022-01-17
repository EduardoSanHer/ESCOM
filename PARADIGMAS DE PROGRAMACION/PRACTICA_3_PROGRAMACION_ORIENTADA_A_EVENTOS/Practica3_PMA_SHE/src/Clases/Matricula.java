package Clases;
import java.util.Date;

public class Matricula {
    private Grupo unGrupo;
    private Alumno unAlumno;
    private Date fecha;

    public Matricula(Grupo unCurso, Alumno unAlumno, Date fecha) {
        this.unGrupo = unCurso;
        this.unAlumno = unAlumno;
        this.fecha = fecha;
    }

    public Grupo obtenerUnCurso() {
        return unGrupo;
    }

    public void darUnCurso(Grupo unGrupo) {
        this.unGrupo = unGrupo;
    }

    public Alumno obtenerUnAlumno() {
        return unAlumno;
    }

    public void darUnAlumno(Alumno unAlumno) {
        this.unAlumno = unAlumno;
    }

    public Date obtenerFecha() {
        return fecha;
    }

    public void darFecha(Date fecha) {
        this.fecha = fecha;
    }

    public String toString() {
        return "Matricula{" + "unCurso=" + unGrupo + ", unAlumno=" + unAlumno + ", fecha=" + fecha + '}';
    }   
}
