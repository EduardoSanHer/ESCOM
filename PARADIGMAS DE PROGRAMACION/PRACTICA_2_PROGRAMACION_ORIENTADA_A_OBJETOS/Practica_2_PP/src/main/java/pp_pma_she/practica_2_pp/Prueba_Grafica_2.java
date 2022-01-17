
package pp_pma_she.practica_2_pp;

import javax.swing.*;
import java.awt.*; // Class Container
import java.awt.event.*;

public class Prueba_Grafica_2 extends JFrame {
    private static final int WIDTH = 800;
    private static final int HEIGHT = 600;
    //String nom, int edad, String curp, String tel, String rh, String email, String s, long NumMat
    private JLabel nombreL, edadL, curpL, telL, rhL, emailL, sL, NumMatL;
    private JTextField nombreTF, edadTF, curpTF, telTF, rhTF, emailTF, sTF, NumMatTF;
    private JButton agregarB, salirB;
    
    private agregarButtonHandler abHandler;
    private salirButtonHandler sbHandler;
    
    public Prueba_Grafica_2(){
        setTitle("Agregar alumno");
        
        nombreL = new JLabel("Ingresa el nombre: ",SwingConstants.RIGHT);
        edadL = new JLabel("Ingresa la edad: ",SwingConstants.RIGHT);
        curpL = new JLabel("Ingresa el CURP: ",SwingConstants.RIGHT);
        telL = new JLabel("Ingresa el numero de telefono: ",SwingConstants.RIGHT);
        rhL = new JLabel("Ingresa el Factor RH: ",SwingConstants.RIGHT);
        emailL = new JLabel("Ingresa el correo: ",SwingConstants.RIGHT);
        sL = new JLabel("Ingresa el sexo: ",SwingConstants.RIGHT);
        NumMatL = new JLabel("Ingresa el numero de matricula: ",SwingConstants.RIGHT);
        
        nombreTF = new JTextField(30);
        edadTF = new JTextField(2);
        curpTF = new JTextField(18);
        telTF = new JTextField(10);
        rhTF = new JTextField(2);
        emailTF = new JTextField(30);
        sTF = new JTextField(9);
        NumMatTF = new JTextField(10);
        
        agregarB = new JButton("Agregar");
        abHandler = new agregarButtonHandler();
        agregarB.addActionListener(abHandler);
        
        salirB = new JButton("Salir");
        sbHandler = new salirButtonHandler();
        salirB.addActionListener(sbHandler);
        
        Container pane = getContentPane();
        pane.setLayout(new GridLayout(9, 2));
        
        pane.add(nombreL);
        pane.add(nombreTF);
        pane.add(edadL);
        pane.add(edadTF);
        pane.add(curpL);
        pane.add(curpTF);
        pane.add(telL);
        pane.add(telTF);
        pane.add(rhL);
        pane.add(rhTF);
        pane.add(emailL);
        pane.add(emailTF);
        pane.add(sL);
        pane.add(sTF);
        pane.add(NumMatL);
        pane.add(NumMatTF);
        pane.add(agregarB);
        pane.add(salirB);
        
        setSize(WIDTH, HEIGHT);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    private class agregarButtonHandler implements ActionListener {
        public void actionPerformed(ActionEvent e){
            System.out.println("HOLA MUNDO XDDD");
            JOptionPane.showMessageDialog(null, "AHHHHHHHHHHH");
	}
    }
    
    private class salirButtonHandler implements ActionListener {
	public void actionPerformed(ActionEvent e){
            System.exit(0);
	}
    }
    
    public static void main(String []args ){
	Prueba_Grafica_2 prog = new Prueba_Grafica_2();
    }
    
}
