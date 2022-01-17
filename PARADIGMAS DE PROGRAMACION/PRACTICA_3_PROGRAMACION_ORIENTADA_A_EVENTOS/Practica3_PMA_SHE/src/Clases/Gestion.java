package Clases;
import java.util.ArrayList;

public class Gestion {
    public static ArrayList<Alumno> listaAlumnos = new ArrayList<>();
    public static ArrayList<Docente> listaDocentes = new ArrayList<>();
    public static ArrayList<Grupo> listaGrupos = new ArrayList<>();
    public static ArrayList<Matricula> listaMatriculas = new ArrayList<>();
    
    public static void agregarAlumno(Alumno unAlumno){
        listaAlumnos.add(unAlumno);
    }
    
    public static void agregarDocente(Docente unDocente){
        listaDocentes.add(unDocente);
    }
    
    public static void agregarGrupo(Grupo unGrupo){
        listaGrupos.add(unGrupo);
    }
    
    public static void agregarMatricula(Matricula unaMatricula){
        listaMatriculas.add(unaMatricula);
    }
    
    public static boolean existeAlumno(String NumMatricula){
        boolean existe=false;
        int tamaLista = listaAlumnos.size();
        for (int i=0;i<tamaLista;i++){
            if (listaAlumnos.get(i).obtenerNumeroDeMatricula().equals(NumMatricula)){
                existe=true;
                break;
            } else {
            }
        }
        return existe;
    }
    
    public static boolean existeDocente(String IDProfesor){
        boolean existe=false;
        for (int i=0;i<listaDocentes.size();i++){
            if (listaDocentes.get(i).obtenerID().equals(IDProfesor)){
                existe=true;
                break;
            }
        }
        return existe;
    }
    
     public static Alumno obtenerAlumnoPorMatricula(String NumMatricula){
        Alumno unAlumno=null;
        for (int i=0;i<listaAlumnos.size();i++){
            if (listaAlumnos.get(i).obtenerNumeroDeMatricula().equals(NumMatricula)){
               unAlumno=listaAlumnos.get(i);
               break;
            }
        }
        return unAlumno;
    }
     
     public static boolean existeGrupo(String codigo){
         boolean existe=false;
         for(int i=0;i<listaGrupos.size();i++){
             if(listaGrupos.get(i).obtenerCodigo().equals(codigo)){
                 existe=true;
                 break;
             }
         }
         return existe;
     }
     
     public static boolean estaMatriculado(Matricula unaMatricula){
         boolean existe=false;
         String NumMatricula = unaMatricula.obtenerUnAlumno().obtenerNumeroDeMatricula();
         String codigoGrupo = unaMatricula.obtenerUnCurso().obtenerCodigo();
         for(int i=0;i<listaMatriculas.size();i++){
             if(listaMatriculas.get(i).obtenerUnAlumno().obtenerNumeroDeMatricula().equals(NumMatricula)
                     && listaMatriculas.get(i).obtenerUnCurso().obtenerCodigo().equals(codigoGrupo)){
                 existe=true;
                 break;
             }
         }
         return existe;
     }
     
     public static void actualizarDocente(Docente unDocente){
         int posicion=0;
         String IDProfesor = unDocente.obtenerID();
         for(int i=0;i<listaDocentes.size();i++){
             if(listaDocentes.get(i).obtenerID().equals(IDProfesor)){
                 posicion = i;
                 break;
             }
         }        
         listaDocentes.set(posicion, unDocente);
     }
    
    
}
