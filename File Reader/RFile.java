/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package newpackage;

import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Logger;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.LinkedHashMap;
import java.util.Map;
import javax.swing.JFrame;
import java.io.File;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;
import javax.swing.JTextArea;
import java.util.logging.Level;
import java.io.IOException;
import java.util.*;
import javax.swing.JScrollPane;

/**
 *
 * @author boffi
 */
public class RFile extends JFrame{
    
    protected int sizeWidth = 640;
    protected int sizeHight = 480;
    protected Container mainWinContainer;
    private JButton openBut = new JButton("Отрыть");
    private JButton showBut = new JButton("Показать");
    private JButton closeBut = new JButton("Закрыть");
    JFileChooser fileopen = new JFileChooser();
    JTextArea textarea = new JTextArea();
    JScrollPane jscrollp = new JScrollPane(textarea, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
    Map linmap = new LinkedHashMap();
    
    public void weight_height(int weght, int heght){
            sizeWidth = weght; 
            sizeHight = heght;
            this.setSize(sizeWidth,sizeHight);
        }

    public void buildLayouts(){
        mainWinContainer = this.getContentPane();
        mainWinContainer.setLayout(new BorderLayout());

        //Open/Show/BUTs
        JPanel southButsJPanel = new JPanel(new BorderLayout());
        openBut.addActionListener(new openButActionListener());
        showBut.addActionListener(new showButActionListener());

        JPanel downBarLeft = new JPanel(new GridBagLayout());
        GridBagConstraints up = new GridBagConstraints();

        //Padding
        up.insets = new Insets(0,5,0,15);  //up//left/right padd

        //Open but
        up.gridx = 0;
        up.gridy = 0;
        downBarLeft.add(openBut, up);

        //Show but
        up.gridx = 1;
        up.gridy = 0;
        downBarLeft.add(showBut, up);

        southButsJPanel.setBorder(new LineBorder(new Color(0, 0, 0, 0), 10));
        southButsJPanel.add(downBarLeft, BorderLayout.WEST);
        //mainWinContainer.add(southButsJPanel, BorderLayout.SOUTH);

        //Close but
        closeBut.addActionListener(new closeButActionListener());
        JPanel closeButJPanel = new JPanel(); 
        closeButJPanel.add(closeBut);
        southButsJPanel.add(closeButJPanel, BorderLayout.EAST);

        mainWinContainer.add(southButsJPanel, BorderLayout.SOUTH);
        
        //JText Area + jscrollp
        JPanel textareaJPanel = new JPanel(new BorderLayout()); 
        textareaJPanel.add(jscrollp, BorderLayout.CENTER);
        textareaJPanel.setBorder(new LineBorder(new Color(0, 0, 0, 0), 15));
        mainWinContainer.add(textareaJPanel, BorderLayout.CENTER);
    }

    class openButActionListener implements ActionListener{
     @Override
     public void actionPerformed(ActionEvent a){    
        int ret = fileopen.showDialog(null, "Открыть файл");
        if (ret == JFileChooser.APPROVE_OPTION) {
            File file = fileopen.getSelectedFile();
            BufferedReader br = null;
            linmap.clear();
            //list.clear();
            int i = 1;
            try{
                br = new BufferedReader(new FileReader(file));
                String line;
                while((line = br.readLine()) != null){
                    //list.add(line);
                    linmap.put(line, i++);
                }
            }catch(FileNotFoundException ex){
                Logger.getLogger(RFile.class.getName()).log(Level.SEVERE, null, ex);
            }catch(IOException ex){
                Logger.getLogger(RFile.class.getName()).log(Level.SEVERE, null, ex);
            }
            finally{
                if(br != null)try{
                    br.close();
                }catch(IOException ex){
                    Logger.getLogger(RFile.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
        //JOptionPane.showMessageDialog(this., "Файл открыт, нажмите кнопку 'Показать'");
     }
    }
     class showButActionListener implements ActionListener{
     public void actionPerformed(ActionEvent a){
        // Получаем вид элементов
        Set<String> set = linmap.keySet();
        textarea.setText("");
        for(String tmp:set){
            textarea.append("" + linmap.get(tmp) + "   " + tmp +"\n");
        }
     }
     }

    class closeButActionListener implements ActionListener{
         public void actionPerformed(ActionEvent a){
             System.exit(0);
         }
     }    
    
///////////////////////////////////////////////////////////////////////////////////////////         Main Function
    
    public RFile(){
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(sizeWidth,sizeHight);
        this.setResizable(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Laba One");
        this.weight_height(960, 540);
        this.buildLayouts();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
    
    public static void main(String args[]) {
        new RFile();
    }
}
