package com.command;
 
import com.command.commandobjects.*;
import com.command.receiver.*;
import com.command.invoker.*;

 
public class main {
    public static void main(String[] args) {
        RemoteControl remoteControl=new RemoteControl();
        
        System.out.println("-----Testing onButtonPressed on RemoteControl for Car-----");
        Car car=new Car();
        CommandBase carMoveCommand=new CarMoveCommand(car);
        remoteControl.onButtonPressed(carMoveCommand);
        
        System.out.println("-----Testing offButtonPressed on RemoteControl for Car-----");
        CommandBase carStopCommand=new CarStopCommand(car);
        remoteControl.offButtonPressed(carStopCommand);
        
        System.out.println("-----Testing undoButtonPressed() on RemoteControl for Car-----");
        remoteControl.undoButtonPressed();
 
        System.out.println("-----Testing onButtonPressed on RemoteControl for RotatingTop-----");
        RotatingTop top=new RotatingTop();
        CommandBase topRotateCommand=new TopRotateCommand(top);
        remoteControl.onButtonPressed(topRotateCommand);
 
        System.out.println("-----Testing offButtonPressed on RemoteControl for RotatingTop-----");
        CommandBase topStopRotateCommand=new TopStopRotateCommand(top);
        remoteControl.offButtonPressed(topStopRotateCommand);
 
       System.out.println("-----Testing undoButtonPressed on RemoteControl for RotatingTop-----");
        remoteControl.undoButtonPressed();
    }
}