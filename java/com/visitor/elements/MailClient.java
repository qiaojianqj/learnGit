package com.visitor.elements;
 
import com.visitor.operations.MailClientVisitor;
 
public interface MailClient {
    void sendMail(String[] mailInfo);
    void receiveMail(String[] mailInfo);
    boolean accept(MailClientVisitor visitor);
}