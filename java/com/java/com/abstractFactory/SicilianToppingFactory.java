package com.abstractFactory;

public class SicilianToppingFactory extends BaseToppingFactory{
    @Override
    public  Cheese createCheese() {
        return new MozzarellaCheese();
    }
    
    @Override
    public  Sauce createSauce() {
        return new TomatoSauce();
    }
}