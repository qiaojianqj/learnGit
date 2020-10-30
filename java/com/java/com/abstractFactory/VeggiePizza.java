package com.abstractFactory;

public class VeggiePizza extends Pizza {
    BaseToppingFactory toppingFactory;
    public VeggiePizza(BaseToppingFactory toppingFactory){
 
        this.toppingFactory=toppingFactory;
    }
    
    @Override
    public void addIngredients() {
        System.out.println("Preparing ingredients for veggie pizza.");
        toppingFactory.createCheese();
        toppingFactory.createSauce();
    }
}