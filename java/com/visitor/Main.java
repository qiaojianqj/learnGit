package com.visitor;

import com.visitor.elements.*;
import com.visitor.operations.*;

public class Main {
    private  static MacMailClientVisitor macVisitor;
    private  static LinuxMailClientVisitor linuxVisitor;
    private  static WindowsMailClientVisitor windowsVisitor;
    private  static OperaMailClient operaMailClient;
    private  static SquirrelMailClient squirrelMailClient;
    private  static ZimbraMailClient zimbraMailClient;

    public static void setup(){
        macVisitor=new MacMailClientVisitor();
        linuxVisitor=new  LinuxMailClientVisitor();
        windowsVisitor=new WindowsMailClientVisitor();
        operaMailClient = new OperaMailClient();
        squirrelMailClient=new SquirrelMailClient();
        zimbraMailClient=new ZimbraMailClient();
    }
    
    public static void main(String[] args) {
        setup();
        
        System.out.println("-----Testing Opera Mail Client for different environments-----");
        operaMailClient.accept(macVisitor);
        operaMailClient.accept(linuxVisitor);
        operaMailClient.accept(windowsVisitor);
 
        System.out.println("\n-----Testing Squirrel Mail Client for different environments-----");
        squirrelMailClient.accept(macVisitor);
        squirrelMailClient.accept(linuxVisitor);
        squirrelMailClient.accept(windowsVisitor);

        System.out.println("\n-----Testing Zimbra Mail Client for different environments-----");
        zimbraMailClient.accept(macVisitor);
        zimbraMailClient.accept(linuxVisitor);
        zimbraMailClient.accept(windowsVisitor);
    }
}