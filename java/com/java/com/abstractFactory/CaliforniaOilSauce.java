package com.abstractFactory;
 
public class CaliforniaOilSauce implements Sauce {
    public CaliforniaOilSauce(){
        prepareSauce();
    }
    
    @Override
    public void prepareSauce() {
        System.out.println("Preparing california oil sauce..");
    }
}