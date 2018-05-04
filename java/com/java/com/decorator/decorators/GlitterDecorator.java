package com.decorator.decorators;
 
import com.decorator.components.FlowerBouquet;
 
public class GlitterDecorator extends FlowerBouquetDecorator {
        FlowerBouquet flowerBouquet;
        
        public GlitterDecorator(FlowerBouquet flowerBouquet) {
            this.flowerBouquet=flowerBouquet;
        }
        
        @Override
        public  String getDescription() {
            return flowerBouquet.getDescription()+", glitter";
        }
        
        @Override
        public double cost() {
            return 4+flowerBouquet.cost();
        }
}