package com.visitor.operations;
 
import com.visitor.elements.*;
 
public class WindowsMailClientVisitor implements MailClientVisitor{
    @Override
    public void visit(MailClient mailClient) {
        if (mailClient.getClass().equals(OperaMailClient.class)) {
            System.out.println("Configuration of Opera mail client for Windows complete");
        } else if (mailClient.getClass().equals(SquirrelMailClient.class)) {
            System.out.println("Configuration of Squirrel mail client for Windows complete");
        }else if (mailClient.getClass().equals(ZimbraMailClient.class)) {
            System.out.println("Configuration of Zimbra mail client for Windows complete");
        }
        
    }

}