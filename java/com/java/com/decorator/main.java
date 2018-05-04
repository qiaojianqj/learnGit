package com.decorator;

import com.decorator.decorators.*;
import com.decorator.components.*;

public class main {
    public static void main(String[] args) {
        /*Rose bouquet with no decoration*/
        FlowerBouquet roseBouquet = new RoseBouquet();
        System.out.println(roseBouquet.getDescription()
                + " $ " + roseBouquet.cost());
 
        /*Rose bouquet with paper wrapper, ribbon bow, and glitter*/
        FlowerBouquet decoratedRoseBouquet = new RoseBouquet();
        decoratedRoseBouquet=new PaperWrapperDecorator(decoratedRoseBouquet);
        decoratedRoseBouquet=new RibbonBowDecorator(decoratedRoseBouquet);
        decoratedRoseBouquet=new GlitterDecorator(decoratedRoseBouquet);
        System.out.println(decoratedRoseBouquet.getDescription()
                + " $ " + decoratedRoseBouquet.cost());
 
        /*Orchid bouquet with double paper wrapper and ribbon bow*/
        FlowerBouquet decoratedOrchidBouquet = new OrchidBouquet();
        decoratedOrchidBouquet=new PaperWrapperDecorator(decoratedOrchidBouquet);
        decoratedOrchidBouquet=new PaperWrapperDecorator(decoratedOrchidBouquet);
        decoratedOrchidBouquet=new RibbonBowDecorator(decoratedOrchidBouquet);
        System.out.println(decoratedOrchidBouquet.getDescription()
                + " $ " + decoratedOrchidBouquet.cost());
    }
}