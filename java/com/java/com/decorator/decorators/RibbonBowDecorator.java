package com.decorator.decorators;
 
import com.decorator.components.FlowerBouquet;
 
public class RibbonBowDecorator extends FlowerBouquetDecorator{
    FlowerBouquet flowerBouquet;
    
    public RibbonBowDecorator(FlowerBouquet flowerBouquet) {
        this.flowerBouquet=flowerBouquet;
    }
    
    @Override
    public  String getDescription() {
        return flowerBouquet.getDescription()+", ribbon bow";
    }
    
    @Override
    public double cost() {
        return 6.5+flowerBouquet.cost();
    }
}