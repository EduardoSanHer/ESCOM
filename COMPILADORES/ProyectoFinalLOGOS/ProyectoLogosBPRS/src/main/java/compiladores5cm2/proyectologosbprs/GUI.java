/*
    |---------------------------------------------------|
    |              Proyecto Final: LOGO                 |
    |                 Datos del equipo                  |
    |   Integrantes: Bernal Trani Marco Antonio         |
    |                Patlani Mauricio Adriana           |
    |                Ruvalcaba Flores Martha Catalina   |
    |                Sandoval Hernández Eduardo         |
    |   Opcion: LOGO                                    |
    |   Fecha de entrega: 13 de junio de 2022           |
    |   Grupo: 5CM2                                     |
    |   Materia: Compiladores                           |
    |----------------------------------------------------|
*/
package compiladores5cm2.proyectologosbprs;

import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.ScrollPaneConstants;
import javax.swing.UIManager;


public class GUI extends JFrame {

    Parser parser;

    //Elementos Interfaz
    JTextArea codeArea;
    JScrollPane codeScroll;
    JPanelDibujo drawArea;
    JButton nombres,trazar, limpiar, limpiarDibujo;
    JComboBox combo;
    
    public GUI() {
     
        super("LOGO");
        UIManager.put("Button.background", Color.pink);
        UIManager.put("Button.foreground", Color.white);
        UIManager.put("Button.select", Color.white);
        UIManager.put("Button.focus", Color.black);
        UIManager.put("ComboBox.background", Color.pink);
        UIManager.put("ComboBox.foreground", Color.white);
        UIManager.put("ComboBox.selectionBackground", Color.white);
        setSize(1900, 1600); //tamaño pantalla
        getContentPane().setBackground(new Color(245,11,11)); //color panel
        parser = new Parser();
        parser.symbolInst();

        //Dibujo
        drawArea = new JPanelDibujo();
        drawArea.setBounds(470, 10, 610, 800);
        drawArea.setBackground(new Color(255,255,255));
        add(drawArea);

        //Codigo
        codeArea = new JTextArea(20, 20);
        codeArea.setBackground(new Color(76,0,153));
        codeArea.setFont(new Font("Consolas", Font.PLAIN, 14));
        codeArea.setForeground(new Color(255,255,255));
        codeArea.setLineWrap(true);
        codeArea.setWrapStyleWord(true);
        codeArea.setTabSize(4);
        codeScroll = new JScrollPane(codeArea);
        codeScroll.setBounds(10,10,450,700);
        add(codeScroll);
        
        //Combo Defaults
        combo = new JComboBox();
        combo.addItem("SELECCIONAR FIGURA");
        combo.addItem("ESPIRÓGRAFO 1");
        combo.addItem("ESPIRÓGRAFO 2");
        combo.addItem("POLÍGONOS");
        combo.addItem("ESTRELLA DE DAVID");
        combo.addItem("PENTAGRAMA");
        combo.addItem("ESPIRAL CUADRADA");
        combo.addItem("HILBERT");
        combo.addItem("KOCH");
        combo.addItem("ÁRBOL");
        combo.addItem("REGLA");
        combo.setBounds(30,720,200,40);
        combo.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae){
                int sel = combo.getSelectedIndex();
                switch(sel){
                    case 0:
                        codeArea.setText(null);
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        break;
                    case 1:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure espirografo(){\n"
                        + "	for(i=0;i<150;i=i+1){\n"
                        + "         COLOR[450, i*320, i*510];\n"
                        + "         AVANZAR[i*4];\n"
                        + "         GIRAR[145];\n"
                        + "     }\n"
                        + "}\n"
                        + "BAJAR[100];\n"
                        + "espirografo();");
                        break;
                    case 2:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure cuadrado(){\n"
                        + "	for(i=0;i<4;i=i+1){\n"
                        + "         AVANZAR[150];\n"
                        + "         GIRAR[90];\n"
                        + "     }\n"
                        + "}\n"
                        + "\n"
                        + "procedure espirografo2(){\n"
                        + "	for(j=0;j<24;j=j+1){\n"
                        + "         COLOR[j*120, j*480, j*60];\n"
                        + "         cuadrado();\n"
                        + "         GIRAR[15];\n"
                        + "     }\n"
                        + "}\n"
                        + "BAJAR[50];\n"
                        + "espirografo2();");
                        break;
                    case 3:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure poligonos()\n"
                        + "{\n"
                        + "AVANZAR[-100];\n"
                        + "GIRAR[90];\n"
                        + "AVANZAR[-200];\n"
                        + "GIRAR[-90];\n"
                        + "\n"
                        + "for(i=0;i<3;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[120];\n"
                        + "}\n"
                        + "\n"
                        + "for(i=0;i<4;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[90];\n"
                        + "}\n"
                        + "\n"
                        + "for(i=0;i<5;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[72];\n"
                        + "}\n"
                        + "for(i=0;i<6;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[60];\n"
                        + "}\n"
                        + "for(i=0;i<7;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[51];\n"
                        + "}\n"
                        + "for(i=0;i<8;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[45];\n"
                        + "}\n"
                        + "for(i=0;i<9;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[40];\n"
                        + "}\n"
                        + "for(i=0;i<10;i=i+1){\n"
                        + "   	COLOR[i*13, i*26, i*51];   	\n"
                        + "	AVANZAR[100];\n"
                        + "\n"
                        + "GIRAR[36];\n"
                        + "}\n"
                        + "}\n"
                        + "AVANZAR[55]; \n"
                        + "poligonos();");
                        break;
                    case 4:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure estrella()\n"
                        + "{\n"
                        + "\n"
                        + "for(i=0;i<6;i=i+1){\n"
                        + "   	COLOR[255,0,0];\n"
                        + "	AVANZAR[150];\n"
                        + "\n"
                        + "GIRAR[60];\n"
                        + "}\n"
                        + "for(i=0;i<6;i=i+1){\n"
                        + "	AVANZAR[-150];\n"
                        + "	GIRAR[60];\n"
                        + "	AVANZAR[150];\n"
                        + "	GIRAR[-120];\n"
                        + "}\n"
                        + "}\n"
                        + "AVANZAR[-70];\n"
                        + "BAJAR[270];\n"
                        + "estrella();");
                        break;
                    case 5:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure pentagrama()\n"
                        + "{\n"
                        + "\n"
                        + "GIRAR[108];\n"
                        + "for(i=0;i<5;i=i+1){\n"
                        + "   	COLOR[255,0,255]; \n"
                        + "	AVANZAR[100];\n"
                        + "GIRAR[72];\n"
                        + "}\n"
                        + "GIRAR[-72];\n"
                        + "for(i=0;i<5;i=i+1){\n"
                        + "	AVANZAR[160];\n"
                        + "	GIRAR[144];\n"
                        + "	AVANZAR[160];\n"
                        + "	GIRAR[-72];\n"
                        + "}\n"
                        + "}\n"
                        + "AVANZAR[100]; \n"
                        + "BAJAR[100]; \n"
                        + "pentagrama();");
                        break;
                    case 6:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("for(i=0;i<80;i=i+1){\n" 
                        +"  COLOR[i*18, i*16, i*31];\n" 
                        +"  AVANZAR[i*5];\n" 
                        +"  GIRAR[90];\n" 
                        +"}");
                        break;
                    case 7:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure hilbert(){\n" 
                        +"	for(i=0; i<$1; i=i+1){\n" 
                        +"	COLOR[50,205,50];\n" 
                        +"	GIRAR[$2];\n" 
                        +"	hilbert($1-1,-$2);\n" 
                        +"	AVANZAR[15];\n" 
                        +"	GIRAR[-$2];\n" 
                        +"	hilbert($1-1,$2);\n" 
                        +"	AVANZAR[15];\n" 
                        +"	hilbert($1-1,$2);\n" 
                        +"	GIRAR[-$2];\n" 
                        +"	AVANZAR[15];\n" 
                        +"	hilbert($1-1,-$2);\n" 
                        +"	GIRAR[$2];\n" 
                        +"	}\n" 
                        +"}\n" 
                        +"AVANZAR[-220];\n" 
                        +"BAJAR[300];\n"
                        +"hilbert(5,90);");
                        break;
                    case 8:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure segmento()\n"
                        + "{\n"
                        + "if($1==0){\n"
                        + "	COLOR[30, 144, 255];\n"
                        + "	AVANZAR[$2];\n"
                        + "	\n"
                        + "}\n"
                        + "if($1>=1){\n"
                        + "	segmento($1-1, $2*0.3333);\n"
                        + "	GIRAR[60];\n"
                        + "	segmento($1-1, $2*0.3333);\n"
                        + "	GIRAR[-120];\n"
                        + "	segmento($1-1, $2*0.3333);\n"
                        + "	GIRAR[60];\n"
                        + "	segmento($1-1, $2*0.3333);\n"
                        + "}\n"
                        + "}\n"
                        + "\n"
                        + "procedure koch(){\n"
                        + "     AVANZAR[-250];\n"
                        + "     GIRAR[90];\n"
                        + "     AVANZAR[-150];\n"
                        + "     GIRAR[-90];\n"
                        + "     GIRAR[60];\n"
                        + "     segmento($1, 500);\n"
                        + "     GIRAR[-120];\n"
                        + "     segmento($1, 500);\n"
                        + "     GIRAR[-120];\n"
                        + "     segmento($1, 500);\n"
                        + "}\n"
                        + "BAJAR[80];\n"
                        + "koch(4);");
                        break;
                    case 9:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure arbol(){\n"
                        + " if($1>4){\n"
                        + "     AVANZAR[$1];\n"
                        + "     GIRAR[20];\n"
                        + "     COLOR[67, 101, 4];\n"
                        + "     arbol($1-4);\n"
                        + "     GIRAR[320];\n"
                        + "     COLOR[154, 205, 50];\n"
                        + "     arbol($1-4);\n"
                        + "     GIRAR[20];\n"
                        + "     COLOR[154, 205, 50];\n"
                        + "     AVANZAR[(-1)*($1)];\n"
                        + "}\n"
                        + "}\n"
                        + "\n"
                        + "GIRAR[90];\n"
                        + "AVANZAR[-200];\n"
                        + "arbol(54);");
                        break;
                    case 10:
                        parser = new Parser();
                        parser.symbolInst();
                        drawArea.setCurrentState(parser.getCurrentState());
                        drawArea.repaint();
                        codeArea.setText("procedure regla(){\n"
                        + "\n"
                        + "if($2>0){\n"
                        + "	regla($1*0.5, $2-1);\n"
                        + "	AVANZAR[$1*0.5];\n"
                        + "	GIRAR[90];\n"
                        + "	AVANZAR[$2*40];\n"
                        + "	AVANZAR[-$2*40];\n"
                        + "	GIRAR[-90];\n"
                        + "	regla($1*0.5, $2-1);\n"
                        + "	AVANZAR[-$1*0.5];\n"
                        + "}\n"
                        + "}\n"
                        + "AVANZAR[-250];\n"
                        + "BAJAR[100];\n"
                        + "COLOR[0, 128, 128];\n"
                        + "regla(520,6);");
                        break;
                }
            }
        });
        add(combo);
  
        //Boton DIBUJAR
        trazar = new JButton("DIBUJAR");
        trazar.setBounds(240,720,200,40);
        trazar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                parser.limpiar();
                if (parser.compilar(codeArea.getText())) {
                    drawArea.setCurrentState(parser.ejecutar());
                } else {
                    parser = new Parser();
                    parser.symbolInst();
                    drawArea.setCurrentState(parser.getCurrentState());
                }
                drawArea.repaint();
            }
        });
        add(trazar);

        //Boton LIMPIAR CÓDIGO
        limpiar = new JButton("LIMPIAR CÓDIGO");
        limpiar.setBounds(240,770,200,40);
        limpiar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                codeArea.setText(null);
            }
        });
        add(limpiar);
        
        //Boton LIMPIAR LIENZO
        limpiarDibujo = new JButton("LIMPIAR LIENZO");
        limpiarDibujo.setBounds(30,770,200,40);
        limpiarDibujo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                parser = new Parser();
                parser.symbolInst();
                drawArea.setCurrentState(parser.getCurrentState());
                drawArea.repaint();
            }
        });
        add(limpiarDibujo);
       
        this.setLayout(null);
        this.setBounds(50,50,1100,849);
        this.setVisible(true);
        this.setResizable(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

}
