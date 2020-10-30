package com.objectsize;
import com.objectsize.ObjectShallowSize;

class A {
    private int a;
    private String aa;
}

class B extends A {
    private int b;
    private String bb;
}

public class Main {
    public static void main(String args[]) {
        System.out.println("A object size:");
        System.out.println(ObjectShallowSize.sizeOf(new A()));
        System.out.println("B object size:");
        System.out.println(ObjectShallowSize.sizeOf(new B()));
    }
}