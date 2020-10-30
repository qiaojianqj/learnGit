package com.abstractFactory;

public class main {
    public static void main(String[] args) {
        System.out.println("Test create gourmet pizza");
        testCreateGourmetPizza();
        System.out.println("\nTest create sicilian pizza");
        testCreateSicilianPizza();
    }
    
    public  static void testCreateGourmetPizza() {
        BasePizzaFactory pizzaFactory = new GourmetPizzaFactory();
        Pizza cheesePizza = pizzaFactory.createPizza("cheese");
        Pizza veggiePizza = pizzaFactory.createPizza("veggie");
    }
    
    public  static void testCreateSicilianPizza() {
        BasePizzaFactory pizzaFactory=new SicilianPizzaFactory();
        Pizza cheesePizza=pizzaFactory.createPizza("cheese");
        Pizza pepperoniPizza =pizzaFactory.createPizza("pepperoni");
    }
}