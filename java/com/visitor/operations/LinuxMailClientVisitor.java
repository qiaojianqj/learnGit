package com.visitor.operations;
 
import com.visitor.elements.*;
 
public class LinuxMailClientVisitor implements MailClientVisitor{
    @Override
    public void visit(MailClient mailClient) {
        if (mailClient.getClass().equals(OperaMailClient.class)) {
            System.out.println("Configuration of Opera mail client for Linux complete");
        } else if (mailClient.getClass().equals(SquirrelMailClient.class)) {
            System.out.println("Configuration of Squirrel mail client for Linux complete");
        }else if (mailClient.getClass().equals(ZimbraMailClient.class)) {
            System.out.println("Configuration of Zimbra mail client for Linux complete");
        }
        
    }

}