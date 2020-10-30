package com.decorator.decorators;

import com.decorator.components.FlowerBouquet;
 
public class PaperWrapperDecorator extends FlowerBouquetDecorator{
    FlowerBouquet flowerBouquet;
    
    public PaperWrapperDecorator(FlowerBouquet flowerBouquet) {
        this.flowerBouquet=flowerBouquet;
    }
    
    @Override
    public  String getDescription() {
        return flowerBouquet.getDescription()+", paper wrap";
    }
    
    @Override
    public double cost() {
        return 3+flowerBouquet.cost();
    }
}