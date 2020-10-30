package com.decorator.decorators;
 
import com.decorator.components.FlowerBouquet;
 
public abstract class FlowerBouquetDecorator extends FlowerBouquet {
    public abstract String getDescription();
}