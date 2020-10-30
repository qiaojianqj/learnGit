package com.templateMethod;

public class main {
    static public void main(String[] args) {
        System.out.println("-----Making Veg Pizza-----");
        PizzaMaker vegPizzaMaker = new VegPizzaMaker();
        vegPizzaMaker.makePizza();
 
        System.out.println("-----Making Non Veg Pizza-----");
        PizzaMaker nonVegPizzaMaker = new NonVegPizzaMaker();
        nonVegPizzaMaker.makePizza();
 
        System.out.println("-----Making In-House Assorted Pizza-----");
        PizzaMaker inHouseAssortedPizzaMaker = new InHouseAssortedPizzaMaker();
        inHouseAssortedPizzaMaker.makePizza();
    }
}