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
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;
import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class JPanelDibujo extends JPanel{
    
    CurrentState currentState;
    
    public JPanelDibujo(){
        currentState = new CurrentState();  
    }
    
    public void setCurrentState(CurrentState currentState){
        BufferedImage img = null;
        try {
            img = ImageIO.read(getClass().getResourceAsStream("Media/pincel.png"));
        } catch (Exception e){
            System.out.println(e);
        }
        this.currentState = currentState;
    }
    
    @Override
    public void paint(Graphics g) {
        super.paint(g);
         BufferedImage img = null;
        ArrayList<Linea> lineas = currentState.getLineas();
        for(int i = 0; i < lineas.size(); i++){
            int x0 = 300 + lineas.get(i).getX0();
            int y0 = 300 - lineas.get(i).getY0();
            int x1 = 300 + lineas.get(i).getX1();
            int y1 = 300 - lineas.get(i).getY1();;
            g.setColor(lineas.get(i).getColor());
            g.drawLine(x0, y0, x1, y1);
            
        }
        
       
        try {
            img = ImageIO.read(getClass().getResourceAsStream("Media/pincel.png"));
        } catch (Exception e){
            System.out.println(e);
        }
        
        int drawLocationX = 275+(int)currentState.getX();
        int drawLocationY = 275-(int)currentState.getY();

        double rotationRequired = Math.toRadians ((-1)*currentState.getAngulo());
        double locationX = img.getWidth() / 2 ;
        double locationY = img.getHeight() / 2;
        AffineTransform tx = AffineTransform.getRotateInstance(rotationRequired, locationX, locationY);
        AffineTransformOp op = new AffineTransformOp(tx, AffineTransformOp.TYPE_BILINEAR);

        g.drawImage(op.filter(img, null), drawLocationX, drawLocationY, 50, 50, this);
        
    }
}