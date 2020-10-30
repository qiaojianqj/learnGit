package com.decorator.components;
 
public class RoseBouquet extends FlowerBouquet{
    public RoseBouquet() {
        description = "Rose bouquet";
    }
    
    @Override
    public double cost() {
        return 12.0;
    }
}