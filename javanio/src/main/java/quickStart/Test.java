package quickStart;

import java.util.Date;
import org.omg.CORBA.IntHolder;

enum GameEnum{
    BIG,
    SMALL,
    FATTER
}

interface Named {
    default String getName() {
        return "default names";
    }
}

interface  Person {
    default  String getName() {
        return "person";
    }
}

public class Test implements Named, Person {
    private final  StringBuilder evaluations;
    private String desc = "third";
    private  static  String staticDesc = "static first";
    /**/
    public String getName() {
        System.out.println ( Named.super.getName () );
        System.out.println ( "Named.class: " + Named.class );
        return Named.super.getName ();
    }
    /**/
    public Test(){
        desc = "fifth";
        System.out.println ( desc );
        evaluations = new StringBuilder (  );
    }

    static {
        System.out.println ( staticDesc );
        staticDesc = "static second";
        System.out.println ( staticDesc );
    }

    {
        System.out.println ( desc );
        desc = "forth " + staticDesc;
        System.out.println ( desc );
    }

    //final 关键字只是表示存储在 evaluations 变量中的对象引用不会再指示其他 StringBuilder 对象。 不过这个对象可以更改
    public void giveGoldStar() {
        evaluations.append ( new Date () + ": Gold Star!\n" );
    }

    public  void printTest() {
        System.out.println ( evaluations );
    }

    public static void print() {
        Test test = new Test ();
        test.getName ();
        test.giveGoldStar ();
        test.printTest ();
    }

    public static void triple1(Integer x) {
        x = 3 * x;
    }

    public static void triple2(IntHolder x) {
        x.value = 3 * x.value;
    }

    public static void testEnumEqual() {
        GameEnum s1 = GameEnum.BIG;
        GameEnum s2 = GameEnum.BIG;
        GameEnum ss1 = GameEnum.SMALL;
        System.out.println("s1 == s2：" + (s1 == s2));
        System.out.println("s1.equals(s2)：" + (s1.equals(s2)));

        System.out.println("s1 == ss1：" + (s1 == ss1));
        System.out.println("s1.equals(ss1)：" + (s1.equals(ss1)));
    }

    public static void testInteger() {
        // 自动装箱规范
        Integer a = 1000;
        Integer b = 1000;
        System.out.println ("Integer a = 1000, b = 1000; a == b ? " + (a == b) );

        Integer c = 100;
        Integer d = 100;
        System.out.println ("Integer c = 100, d = 100; c == d ? " + (c == d) );

        Integer e = new Integer ( 10 );
        Integer f = new Integer ( 10 );
        System.out.println ("Integer e = 10, f = 10; e == f ? " + (e == f) );

        int g = 1000;
        System.out.println ("Integer a = 1000; int g = 1000; a == g ? " + (a == g) );

    }

    public static void testInnerClass(String name) {
       new Thread (  new Runnable () {
           public void run() {
               try {
                   Thread.sleep ( 1000 );
               } catch (InterruptedException e) {
                   e.printStackTrace ();
               }
               System.out.println ( "\nmethod parameter " + name +" passed to inner class\n" );
           }
       } ).start ();
    }
}
