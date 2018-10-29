package quickStart;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Vector;

//因为类型擦除,ArrayList<T>进入JVM，T被替换成Object
public class TestGenerics {
        public <K,V> void f(K k,V v) {
            System.out.println(k.getClass().getSimpleName());
            System.out.println(v.getClass().getSimpleName());
        }

        public static void main(String[] args) {
            TestGenerics gm = new TestGenerics ();
            //gm.<Integer, String>f(new Integer(0),new String("generic"));
            gm.f(new Integer(0),new String("generic"));

            Class c1 = new ArrayList<String> ().getClass();
            Class c2 = new ArrayList<Integer>().getClass();
            System.out.println(c1 == c2);
        }
}

//类型擦除的规则导致class Manipulator<T>找不到HasF类的方法f()
class HasF {
    public void f() {
        System.out.println("HasF.f()");
    }
}

//class Manipulator<T> {
class Manipulator<T extends  HasF> {
    private T obj;

    public Manipulator(T obj) {
        this.obj = obj;
    }

    public void manipulate() {
        obj.f (); //无法编译 找不到符号 f()
    }

    public static void main(String[] args) {
        HasF hasF = new HasF ();
        Manipulator<HasF> manipulator = new Manipulator<> ( hasF );
        manipulator.manipulate ();

    }
}

//不能new一个泛型T对象，只能new一个实际类型的对象
abstract class GenericWithCreate<T> {
    final T element;
    GenericWithCreate() { element = create(); }
    abstract T create();
}

class Inst {}

class Creator extends GenericWithCreate<Inst> {
    Inst create() { return new Inst (); }
    void f() {
        System.out.println(element.getClass().getSimpleName());
    }
}

class CreatorGeneric {
    public static void main(String[] args) {
        Creator c = new Creator();
        c.f();
    }
}

//利用泛型的类型擦除和反射绕过泛型的编译期安全检查
class ToolTest {
    public static void main(String[] args) {
        //不能创建具体类型的泛型数组
        //List<Integer>[] lst1 = new ArrayList<Integer>[];
        // 可以创建通配类型的数组， 然后进行类型转换
        List<String>[] table = (List<String>[]) new List<?>[10];
        //
        List<?>[] lst2 = new ArrayList<?>[10];
        lst2[1] = new ArrayList<String>();
        //lst2[2] = new Vector<Integer>();

        List<Integer> ls = new ArrayList<>();
        ls.add(23);
//      ls.add("text");
        try {
            Method method = ls.getClass().getDeclaredMethod("add",Object.class);


            method.invoke(ls,"test");
            method.invoke(ls,42.9f);
        } catch (NoSuchMethodException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (SecurityException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IllegalArgumentException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        for ( Object o: ls){
            System.out.println(o);
        }
    }
}

//泛型类与泛型方法共存，类型参数相互独立
class TestGenericClassAndMethod<T>{

    public  void testNormalMethod(T t){
        System.out.println(t.getClass().getName());
    }
    //此处的泛型类型T和类的泛型类型T是不一样的，所以为了清晰最好不要都用T表示
    public  <T> T testGenericMethod(T t){
        System.out.println ( t );
        return t;
    }

    public static void main(String... args) {
        //TestGenericClassAndMethod testGenericClassAndMethod = new TestGenericClassAndMethod ();
        TestGenericClassAndMethod<String> testGenericClassAndMethod = new TestGenericClassAndMethod ();
        testGenericClassAndMethod.testNormalMethod ( "generic class para" );
        testGenericClassAndMethod.testGenericMethod ( new Integer ( "123" ) );
    }
}

//通配符
class Base{}

class Sub extends Base{}

class Wildcard {
    public void testWildCards(Collection<?> collection){
        //无限定通配符<?> 提供了只读的功能，也就是它删减了增加具体类型元素的能力，只保留与具体类型无关的功能。
        //collection.add ( "123" ); //编译不过
        //collection.add ( new Object () ); //编译不过

        collection.size ();
        collection.iterator ().next ();
    }

    public void testExtends(Collection<? extends Base> para){
        //有上限的通配符<? extends Base>仍然丧失了写操作的能力
        //para.add(new Sub()); //编译不过
        //para.add(new Base()); //编译不过
    }

    public void testSuper(Collection<? super Sub> para){
        //有下限的通配符<? super Sub> ，它拥有一定程度的写操作的能力
        para.add(new Sub());//编译通过
        //para.add(new Base());//编译不通过
    }

   public static void main(String... paras) {
       //Sub是Base的子类
       Sub sub = new Sub();
       Base base = sub;
       //List<Sub>不是List<Base>的子类
       List<Sub> lsub = new ArrayList<>();
       //List<Base> lbase = lsub; //编译不过
       Object[] objArr = new Object[10];
       objArr[0] = "12345";
   }
}

