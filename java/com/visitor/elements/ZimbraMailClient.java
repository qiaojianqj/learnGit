package com.visitor.elements;
 
 
import com.visitor.operations.MailClientVisitor;
 
public class ZimbraMailClient implements MailClient{
    @Override
    public void sendMail(String[] mailInfo) {
        System.out.println(" ZimbraMailClient: Sending mail");
    }
 
    @Override
    public void receiveMail(String[] mailInfo) {
        System.out.println(" ZimbraMailClient: Receiving mail");
    }
 
    @Override
    public boolean accept(MailClientVisitor visitor) {
       visitor.visit(this);
       return true;
    }
}