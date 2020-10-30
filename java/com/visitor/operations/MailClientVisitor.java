package com.visitor.operations;
 
import com.visitor.elements.MailClient;
 
public interface MailClientVisitor {
    void visit(MailClient mailClient);
}