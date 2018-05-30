package com.thoughtworks.app;

import java.io.File;
import java.util.HashMap;

import com.thoughtworks.app.command.Command;
import com.thoughtworks.app.command.CommandParser;
import com.thoughtworks.app.graph.*;
/**
 * Directed graph search!
 *
 */
public class App 
{
	public static DirectedGraph dG;
	public static void main( String[] args ) throws Exception
    {
        File inputFile = null;
        if (args.length == 1) {
            inputFile = new File(args[0]);
        } else {
            System.out.println (App.class.getResource ( "/" ).getPath ());
            inputFile = new File(App.class.getResource("/graph.txt").toURI());
        }
        HashMap<String, Object> testMap = new HashMap<> ();
        testMap.put ( "first", "1" );
        testMap.put ( "second", "2" );
        testMap.put ( "three", "3" );
        testMap.put ( "four", "4" );
        testMap.put ( "five", "5" );
        testMap.put ( "six", "6" );
        testMap.put ( "seven", "7" );
        /*
        for (Map.Entry<String, Object> entry : testMap.entrySet ()
             ) {
            System.out.println ( "key: " + entry.getKey () + "value: "+ entry.getValue ());
        }
       */

        testMap.forEach ( (k, v) -> {System.out.println ("key: " + k + " value: " + v);} );
        CommandParser commandParser = new CommandParser();
        commandParser.addCommand(inputFile);
        commandParser.addCommand("DISTANCE", "A-B-C");
        commandParser.addCommand("DISTANCE", "A-D");
        commandParser.addCommand("DISTANCE", "A-D-C");
        commandParser.addCommand("DISTANCE", "A-E-B-C-D");
        commandParser.addCommand("DISTANCE", "A-E-D");
        
        commandParser.addCommand("TRIPS", "MAX_STOPS, 3, C-C");
        commandParser.addCommand("TRIPS", "EXACT_STOPS, 4, A-C");
        
        commandParser.addCommand("SHORTEST", "A-C");
        commandParser.addCommand("SHORTEST", "B-B");
        
        commandParser.addCommand("TRIPS", "MAX_DISTANCE, 30,C-C");
        
        for (final Command eachCommand : commandParser.getCommand()) {
            eachCommand.execute();
        }
        Thread t1 = new Thread ( new MyRunnable () );
        Thread t2 = new Thread ( new MyRunnable () );
        t1.start();
        t2.start();
    }
}

class MyRunnable implements Runnable {
	    public  static  Integer i = new Integer ( 0 );
	    @Override
        public void  run() {
	        while (true) {
	            synchronized (i) {
	                if (i < 100) {
	                    i++;
	                    System.out.println ( "i = " + i );
                    } else {
	                    break;
                    }
                }
            }
        }
    }
