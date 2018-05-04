package com.abstractFactory;

public class PepperoniPizza extends Pizza {
    BaseToppingFactory toppingFactory;
    public PepperoniPizza(BaseToppingFactory toppingFactory){
 
        this.toppingFactory=toppingFactory;
    }
    
    @Override
    public void addIngredients() {
        System.out.println("Preparing ingredients for pepperoni pizza.");
        toppingFactory.createCheese();
        toppingFactory.createSauce();
    }
}