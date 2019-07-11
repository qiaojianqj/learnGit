# java学习

###数据类型

> byte(1字节), short(2字节), int(4字节), long(8字节), float(4字节), double(8字节), char(2字节), boolean(true, false)
>
> Java 没有任何无符号(unsigned) 形式的 int、long、short 或 byte 类型。 
>
> char 类型描述了 UTF-16 编码中的一个代码单元，占2字节，（有的字符编码占用两个代码单元）建议不要在程序中使用 char 类型。 
>
> 整数被 0 除将会产生一个异常， 而浮点数被 0 除将会得到无穷大或 NaN 结果。 
>
> &&和||运算符是按照“ 短路”方式来求值的: 如果第一个操作数已经能够确定表达式的值，第二个操作数就不必计算了。 
>
> \>>运算符会用符号位填充高位，\>>>运算符会用 0 填充高位。
>
> 移位运算符的右操作数要完成模32的运算(除非左操作数是long类型，在这种情况下需要对右操作数模 64 )。 例如，1<<35 的值等同于 1<<3 。
>
> ~~~java
> System.out.println ( 1.0 / 0 );
> //output Infinity
> 
> int valInt = 1<<35;
> System.out.println ( valInt);
> //output 8
> 
> long valLong = (long)1<<35;
> System.out.println ( valLong );
> //output 34359738368
> ~~~
>
> 字符串“xxoo”是unicode字符x、x、o、o组成的序列。字符串、String类对象是不可变对象。
>
> 判断字符串内容相等用equals，==运算符是判断字符串的地址是否相等。
>
> String取length是取的字符串的代码单元的个数。
>
> Console类用于输入密码，为了安全起见，返回的密码存放在一维字符数组中， 而不是字符串中。
>
> 在 C++ 中， 可以在嵌套的块中重定义一个变量。 在内层定义的变量会覆盖在外层定义的变量。 但是，在java中不允许嵌套块中重定义外层的变量。
>
> 在 Java 中， 允许数组长度为 0。 在 Java 中， 允许将一个数组变量拷贝给 另一个数组变量。这时， 两个变量将引用同 一个数组。如果希望将 一个数组的所有值拷贝到一个新的数组中去， 就要使用 Arrays 类的 copyOf 方法。可以通过二维数组创建不规则数组（先创建行，再单独创建每行的数组）
>
> ~~~java
> //浮点数默认为双精度的（double）
> //float i = 1.1;
> float i = (float) 1.1;
> 
> short j = 1;
> //整型默认为int
> //j = j + 1;
> // += 运算自动向下转型 int -> short
> j += 1;
> 
> //不使用临时变量交换两个整数的值
> //方法1. 使用异或操作swap a 和 b 的值
> int a = 456;
> int b = 123;
> a = a ^ b;
> b = a ^ b;
> a = a ^ b;
> System.out.println ( a ); //123
> System.out.println ( b ); //456
> 
> //方法2. 使用加减法运算
> int a = 123;
> int b = 456;
> a = a + b;
> b = a - b;
> a = a - b;
> System.out.println ( a );
> System.out.println ( b );
> 
> //编译时能确定的String对象都放入常量池
> //运行时才能确定或者new出的String对象都放入堆
> String str1 = "I am String1"; //变量str1引用指向字符串常量池
> final String str2 = "I am String"; //final修饰，str2是编译期常量
> String str3 = "I am String"; //变量str3引用指向字符串常量池
> String str4 = str2 + 1; // str2 + 1 得到的也是个常量，放在常量池
> String str5 = str3 + 1; // str3 + 1 得到的是个变量，放在堆上 （因为str3变量在运行时才可以取到它所引用的值）
> System.out.println ( str1 == str4 );
> System.out.println ( str1 == str5 );
> 
> //try语句带return，finally执行时机
> try {
>     if (a == 123) {
>         System.out.println ( "in try return a = " + a );
>         return; // 执行到此处，记录return的值，然后执行finally代码块，再然后return
>     }
> } finally {
>     a = 1234;
>     System.out.println ( "in finally a = " + a );
> }
> ~~~

### 类与对象

> 识别类的简单规则是在分析问题的过程中寻找名词， 而方法对应着动词。 
>
> | 关系        | 含义                                      |
> | ----------- | ----------------------------------------- |
> | 继承(is a)  | is a，类A扩展自类B                        |
> | 接口实现    | 类实现接口中的方法                        |
> | 依赖(use a) | use a，一个类的方法操纵另一个类的对象     |
> | 聚合(has a) | has a，类A的对象包含类B的对象（属性关联） |
> | 关联        | 通过属性、方法关联                        |
>
> 构造器总是伴随着 new 操作符的执行被调用。
>
> 不要编写返回引用可变数据域对象的访问器方法。 如果需要返回一个可变数据域的拷贝， 就应该使用 clone。 
>
> 对于可变的类， 使用 final 修饰符可能会对读者造成混乱。  
>
> ```java
> class Test {
>     private final  StringBuilder evaluations;
> 
>     public Test(){
>         evaluations = new StringBuilder (  );
>     }
> 
>     //final 关键字只是表示存储在 evaluations 变量中的对象引用不会再指示其他 StringBuilder 对象。 不过这个对象可以更改
>     public void giveGoldStar() {
>         evaluations.append ( new Date () + ": Gold Star!\n" );
>     }
> 
>     public  void printTest() {
>         System.out.println ( evaluations );
>     }
> }
> ```
>
> 静态变量使用得比较少， 但静态常量(static final)却使用得比较多。 静态方法是没有this参数的方法，在一个非静态方法中this参数是该方法的隐式参数，代表操作此方法的对象。
>
> java方法调用参数是按值传递，下面总结一下 Java 中方法参数的使用情况: 
>
> • 一个方法不能修改一个基本数据类型的参数 (即数值型或布尔型)。 
>
> • 一个方法可以改变一个对象参数的状态。 
>
> • 一个方法不能让对象参数引用一个新的对象。 
>
> 类属性与局部变量的主要不同点： 必须明确地初始化方法中的局部变量。 但是，如果没有初始化类中的属性， 它将会被自动初始化为默认值(0、false 或 null )，但是，这并不是一种良好的编程习惯。
>
> 仅当类没有提供任何构造器的时候，系统才会提供一个默认的构造器 。
>
> 可以在类定义中， 直接将一个值赋给任何属性。在执行构造器之前，将会先执行赋值操作。
>
> ~~~java
> class Employee {
>     private String name = "";
>     ...
> }
> ~~~
>
>  一个构造函数可以通过this引用调用另一个构造函数
>
> ~~~java
> public Employee(double s) {
>     //call Employee(String, double)
>     this("something", s);
>     ...
> }
> ~~~
>
> 类构造初始化次序：
>
> 1. static 属性赋值
> 2. static 初始化块
> 3. 实例属性赋值
> 4. 实例属性初始化块
> 5. 构造函数体
>
> 可以为任何一个类添加 finalize 方法。finalize 方法将在垃圾回收器清除对象之前调用。 在实际应用中， 不要依赖于使用 finalize 方法回收任何短缺的资源，这是因为很难知道这个方法什么时候才能够调用。 
>
> 从编译器的角度来看，嵌套的包之间没有任何关系。 例如， java.util 包与 java.util.jar 包毫无关系。每一个都拥有独立的类集合。 
>
> 将包中的文件放到与完整的包名匹配的子目录中。 
>
> 利用 -classpath 选项设置类路径是首选的方法， 也可以通过设置 CLASSPATH 环境变量 完成这个操作。 
>
> ~~~java
> java -classpath c:\classdir;.;c:\archives\archive.jar MyProg
> //或者
> export CLASSPATH=/home/user/classdir:.:/home/user/archives/archive.jar
> ~~~

### 继承

> 如果子类的构造器没有显式地调用超类的构造器，则将自动地调用超类默认(没有参数 ) 的构造器。 如果超类没有不带参数的构造器，并且在子类的构造器中又没有显式地调用超类的其他构造器， 则 Java 编译器将报告错误。 
>
> 是否应该设计为继承关系的一个简单规则： “is-a” 规则。它的另一种表述法是置换法则。它表明程序中出现超类对象的任何地方都可以用子类对象置换。
>
> ~~~java
> Employee e;
> e = new Employee();
> e = new Manager(); //ok, Manager extends from Employee
> ~~~
>
>  在 Java 中，子类数组的引用可以转换成超类数组的引用，而不需要采用强制类型转换。但是一定要注意这种用法会引起以下类型紊乱的错误。
>
> ~~~java
> Manager[] managers = new Manager[10];
> Employee[] staff = managers; //ok, but now staff and managers reference to the same Objects
> staff[0] = new Employee(); //ok
> managers[0].setBonus(1000); //error, this will arise ArrayStoreException
> ~~~
>
>  返回类型不是签名的一部分， 因此，在覆盖方法时，一定要保证返回类型的兼容性。允许子类将覆盖方法的返回类型定义为原返回类型的子类型。 
>
> 方法调用的两种方式：静态绑定（private方法、static方法、final方法），动态绑定（其他）
>
> 如果将一个类声明为 final， 只有其中的方法自动地成为 final, 而不包括属性。
>
> 只能在继承层次内进行类型转换。 在将超类转换成子类之前，应该使用 instanceof 进行检查。 但是尽量不要使用类型转换，如果必须使用类型转换，则应该检查超类的设计是否合理。
>
> 包含一个或多个抽象方法的类本身必须被声明为抽象的。 但是，类即使不含抽象方法， 也可以将类声明为抽象类。  
>
> 在 Java 中，只有基本类型 ( primitive types ) 不是对象， 所有的数组类型，不管是对象数组还是基本类型的数组都是扩展自Object的类对象。
>
> 为一个类编写equals方法的完美建议：
>
> > 1. 显示参数命名为otherObject
> > 2. 检测this与otheObject是否引用同一对象：
> >
> > ~~~java
> > if (this == otherObject) return true;
> > ~~~
> >
> > 3. 检测otherObject是否为null
> >
> > ~~~java
> > if (otherObject == null) return false;
> > ~~~
> >
> > 4. 检测this与otherObject是否属于同一个类：
> >
> >    如果equals的语义在每个子类有所改变，则使用getClass检测
> >
> >    ~~~java
> >    if (getClass() != otherObject.getClass()) return false;
> >    ~~~
> >
> >    如果所有子类使用相同的语义，即由超类决定相等的概念，则使用instanceof检测
> >
> >    ~~~java
> >    if (!(otherObject instanceof ClassName)) return false;
> >    ~~~
> >
> > 5. 将otherObject转换为相应的类类型变量
> >
> > ~~~java
> > ClassName other = (ClassName) otherObject;
> > ~~~
> >
> > 6. 开始属性域的比较，使用==比较基本类型，使用Objects.equals比较对象
>
> 如果重新定义 equals 方法， 就必须重新定义 hashCode 方法。
>
> 强烈建议为自定义的每一个类增加toString方法。 
>
> 动态数组：Vector（老版本，不建议使用），ArrayList\<E\> (建议使用)
>
> 如果存储的元素数比较多，又经常需要在中间位置插入、删除元素，就应该考虑使用链表了。 
>
> 对象包装器类（Integer，Long，Float，Double，Short，Byte，Character，Void，Boolean）是final类, 因此不能定义它们的子类。
>
> 自动装箱规范要求 boolean、byte、char 127， 介于 -128 ~ 127 之间的 short 和 int 被包装到固定的对象中。 因此
>
> ~~~java
> Integer a = 1000;
> Integer b = 1000;
> if (a == b) // false
> 
> Integer a = 100;
> Integer b = 100;
> if (a == b) // true
> ~~~
>
>  不能通过将对象包装器类作为方法参数来修改它包装的数值，如果想编写一个修改数值参数值的方法，就需要使用在 org.omg.CORBA 包中定义的持有者(holder) 类型， 包括 IntHolder、BooleanHolder 等。 
>
> ~~~java
> public static void triple1(Integer x) { //won't work
>    x = 3 * x; //modify local variable
> }
> 
> public static void triple2(IntHolder x) { //work
>     x.value = 3 * x.value;
> }
> ~~~
>
> 允许将一个数组传递给可变参数方法的最后一个参数。 
>
> ~~~java
> public class PrintStream
> {
> 	public PrintStream printf(String fmt, Object... args) { 
> 		return format(fmt, args); 
> 	} 
> }
> 
> System.out.printf("%d %s", new Object[]{ new Integer(n), "widgets" } );
> ~~~
>
> 反过来，也可以将已经存在且最后一个参数是数组的方法重新定义为可变参数的方法，而不会破坏任何已经存在的代码。 
>
> ~~~java
> public static void main(String[] args)
> public static void main(String... args) //ok
> ~~~
>
> 比较两个枚举类型的值时，直接使用==比较即可，因为enum类型的实例不会超出enum常量定义的实例。枚举内部实现及应用参考 https://blog.csdn.net/javazejian/article/details/71333103
>
> 反射机制的默认行为受限于 Java 的访问控制。然而，如果一个 Java 程序没有受到安全管理器的控制， 就可以覆盖访问控制。为了达到这个目的， 需要调用 Field、 Method 或 Constructor 对象的setAccessible 方法。 

### 接口、lambda表达式和内部类

> 因为接口不能被定义为 protect 或 private，所以除 public 之外就是默认的 package 访问级别。
>
> 接口中的所有方法自动地属于 public。接口中的域将被自动设为 public static final。接口绝不能含有实例域。
>
> 在接口声明中， 没有将方法声明为 public，这是因为在接口中的所有方法都自动地是public。不过，在实现接口时，必须把方法声明为public。
>
> 从Java SE 8 开始， 允许在接口中增加静态方法。 理论上讲， 没有任何理由认为这是不合法 的。只是这有违于将接口作为抽象规范的初衷。通常的做法都是将静态方法放在伴随类中。在标准库中，你会看到成对出现的接口和实用工具类， 如Collection/Collections 或 Path/Paths。
>
> 可以为接口方法提供一个默认实现。 必须用 default 修饰符标记这样一个方法。默认方法可以调用任何其他方法。 好处1:  默认方法可以为将来的接口扩展提供后向兼容的特性。好处2: 默认方法可以让实现这个接口的程序员只覆盖接口中的个别方法。
>
> ~~~java
> public interface Collection {
>     int size();// An abstract method
>     default boolean isEmpty() {
>         return size() == 0;
>     }
> }
> ~~~
>
> 解决默认方法冲突：即如果先在一个接口中将一个方法定义为默认方法， 然后又在超类或另一个接口中定义了同样的方法， 规则如下: 
>
> 1. 超类优先。如果超类提供了一个具体方法， 同名而且有相同参数类型的默认方法会被忽略。 
> 2. 由程序员解决接口冲突。
>
> ~~~java
> public interface Named {
>     default String getName() {
>         return "default names";
>     }
> }
> 
> public interface  Person {
>     default  String getName() {
>         return "person names";
>     }
> }
> 
> public class Student implements Named,Person {
> 	//必须覆盖这个方法来解决冲突。
>     public String getName() {
>        	return Named.super.getName ();
>     }
> }
> ~~~
>
> 利用接口实现回调函数，参考Swing的Timer和ActionListner
>
> Object 类中 clone 方法声明为 protected是因为子类扩展自Object类时添加自己的属性可能需要深拷贝而子类并未覆盖clone方法，此时子类对象若调用clone将不会符合需求，所以将此方法声明为protected。
>
> 即使 clone 的默认(浅拷贝)实现能够满足要求，还是需要实现 Cloneable 接口（标记接口），将 clone 重新定义为public，再调用super.clone()。  
>
> 无需指定 lambda 表达式的返回类型。 lambda 表达式的返回类型总是会由上下文推导得出。如果一个 lambda 表达式只在某些分支返回一个值， 而在另外一些分支不返回值， 这是不合法的。
>
> 对于只有一个抽象方法的接口，称为函数式接口。  
>
> ~~~tex
> a functional interface has exactly one abstract method. Since default methods have an implementation, they are not abstract. If an interface declares an abstract method overriding one of the public methods of java.lang.Object, that also does not count toward the interface's abstract method count since any implementation of the interface will have an implementation from java.lang.Object or elsewhere.
> Note that instances of functional interfaces can be created with lambda expressions(lambda表达式), method references(方法引用), or constructor references(构造器引用).
> ~~~
>
> 在 Java 中， 对 lambda 表达式所能做的只是能转换为函数式接口。在其他支持函数字面量的程序设计语言中，可以声明函数类型(如(String,String)-> int)、声明这些类型的变量，还可以使用变量保存函数表达式。不过， Java 设计者还是决定保持我们熟悉的接口概念，没有为 Java 语言增加函数类型。
>
> 方法引用等价于lambda表达式，它的使用方式：
>
> 1. object::instanceMethod [this::equals 等价于 (x) -> this.equals(x)]
> 2. Class::staticMethod
> 3. Class::instanceMethod [此时，第1个参数会成为方法的目标，例如String::compareToIgnoreCase等价于(x, y) -> x.compareToIgnoreCase(y); super::instanceMethod将调用超类的方法]
>
> 构造器引用同方法引用，也等价于lambda表达式，只是使用方式是：Class::new 
>
>  lambda 表达式可以捕获外围作用域中变量的值。 但是只能引用值不会改变的变量。 
>
> 可以在一个 lambda 表达式中使用 this 关键字， 是指创建这个 lambda 表达式的方法的 this 参数。 
>
> 使用 lambda 表达式的重点是延迟执行 deferred execution )  [同回调的用法]
>
> Comparator 接口包含很多方便的静态方法来创建比较器。这些方法可以用于 lambda 表达式或方法引用。 
>
> ~~~java
> Arrays.sort(people, Comparator.comparing(Person::getName));
> 
> Arrays.sort(people, Comparator.comparing(Person::getLastName).thenComparing(Person::getFirstName));
> 
> Arrays.sort(people, Comparator.comparing(Person::getName, (s,t) -> Integer.compare(s.length(), t.length())));
> 
> Arrays.sort(people, Comparator.comparing(p -> p.getName().length()));
> 
> import static java.util.Comparator.*;
> Arrays.sort(people, comparing(Person::getMiddleName, nullFirst(naturalOrder())));
> ~~~
>
> 内部类的对象有一个隐式引用，它引用了实例化该内部对象的外围类对象。通过这个指针， 可以访问外围类对象的全部状态。 static 内部类没有这种附加指针，它不能访问外围类的状态。
>
> ~~~java
> //这个隐式引用的显示使用语法如下
> OuterClass.this
> //在外围类的作用域内，显示构造public内部类
> InnerClass innerClassObject = this.new InnerClass(construction parameters);
> //在外围类的作用域之外，显示构造public内部类
> OuterClass.InnerClass innerClassObject = outerClassObject.new InnerClass(construction parameters);
> ~~~
>
> 只有内部类可以声明为私有类，这样一来， 只有外围类的方法才能够构造私有内部类对象。 而常规类只可以具有包可见性 或公有可见性。
>
> ~~~java
> //常规类 Error: modifier private not allowed here
> private class Test {
>     ...
> }
> ~~~
>
> 内部类中声明的所有静态域都必须是 final。 原因很简单。 我们希望一个静态域只有一个实例，不过对于每个外部对象，会分别有一个单独的内部类实例。 如果这个域不是final, 它可能就不是唯一的。编译器将会把内部类翻译成用 $ ( 美元符号)分隔外部类名与内部类名的常规类文件，而虚拟机则对此一无所知。
>
> 内部类不能有 static 方法（静态内部类可以有static域和static方法）。 
>
> 在一个方法中定义的内部类称为局部内部类。局部类不能用 public 或 private 访问说明符进行声明。它的作用域被限定在声明这个局部类的方法块中。除此方法外，其他任何方法都不知道局部内部类的存在。
>
> 局部内部类不仅能够访问包含它们的外部类，还可以访问局部变量。 
>
> 匿名内部类用于只需创建某个类的一个对象，则不需命名。匿名类不能有构造器。 它的语法如下
>
> ~~~java
> new supertype(construction parameters) {
>     //inner class methods and data...
> }
> 
> new interface(){
>     //inner class methods and data...
> }
> 
> //使用匿名类实现在static方法里获取包含static方法的类
> new Object(){}.getClass().getEnclosingClass();
> ~~~
>
> 静态内部类的对象除了没有对生成它的外围类对象 的引用特权外， 与其他所有内部类完全一样。 
>
> 声明在接口中的内部类自动成为 static 和 public 类。 
>
>  代理类可以在运行时创建全新的类。这样的代理类能够实现指定的接口。 Java Proxy分析参考https://www.ibm.com/developerworks/cn/java/j-lo-proxy1/index.html
>
> 

### 异常、断言和日志

>  Java 中的异常层次结构
>
> 从 Error 继承的错误。任何程序代码都具有抛出那些异常的潜能，而我们对其没有任何控制能力。 
>
> 方法声明抛出异常规则：受查异常（不可控）应该抛出，非受查异常（可控）应该由程序员保证
>
> ~~~java
> //ok, 抛出受查异常
> public Image loadlmage(String s) throws FileNotFoundException, EOFException {
>     ...
>     throw new EOFException(); 
>     throw new FileNotFoundException();
> }
> //bad style, 抛出非受查异常
> void drawlmage(int i) throws ArraylndexOutOfBoundsException {
>     
> }
> ~~~
>
> 如果在子类中覆盖了超类的一个方法，子类方法中声明的受查异常不能比超类方法中声明的异常更通用 
>
> 通常，应该捕获（try.catch.finnally字句）那些知道如何处理的异常， 而将那些不知道怎样处理的异常继续进行传递（throw & throws）
>
> 强烈建议将try/catch/finally解耦合为 try/catch 和 try/finally 语句块或者使用带资源的try语句 
>
> ~~~java
> InputStream in = ...
> try {
>     try{
> 		...
>     }finally{
>         in.close();
>     }
> }catch(IOException e){
> 	...
> }
> //带资源的try语句，会自动关闭资源并抑制关闭资源时可能产生的异常
> //想得到此异常，可以调用getSuppressed方法
> try(InputStream in = ...){
>     
> }
> ~~~
>
> 分析堆栈轨迹（方法调用过程的列表）：两个方法
>
> ~~~java
> printStackTrace & getStackTrace
> ~~~
>
> 断言机制允许在测试期间向代码中插入一些检査语句。当代码发布时，这些插人的检测语句将会被自动地移走。 
>
> Java log框架：原生态java.util.logging；log4j；logback
>
> 日志门面，底层可适配不同的log框架：commons-logging；SLF4J

### 泛型

> 类型参数化，更安全，在编译期间就能检查出类型异常
>
> Java泛型只能算是“伪泛型”，因为在进入JVM前会进行类型擦除，比如\<T\>会替换成Object；\<T extends String\>会被替换成String；\<T extends Comparable & Serializable\>会替换成Comparable；为了提高效率，应该将标签(tagging) 接口 (即没有方法的接口)放在边界列表的末尾。
>
> 泛型通配符的出现是为了指定泛型中的类型范围：
>
> 通配符有 3 种形式：
>
> 1. `<?>` 被称作无限定的通配符。它删减了增加具体类型元素的能力，只保留与具体类型无关的功能。	
> 2. `<? extends T>` 被称作有上限的通配符。表示T及T的子类。
> 3. `<? super T>` 被称作有下限的通配符。表示T及T的超类。

### 集合

>  FIFO：队列，先进先出，队尾添加，队头删除；实现方式：循环数组 或 链表；
>
>  循环数组：效率高（直接通过数组下标取值），容量有限，队列满了会自动扩容
>
>  链表：效率较低（每次都要修改链表的结构），容量没有上限
>
>  哈希表、红黑树
>

### CentOS - Redis - MySQL

~~~tcl
centos 安装 redis：
yum install tcl
wget http://download.redis.io/releases/redis-3.2.11.tar.gz 
tar zxvf redis-3.2.11.tar.gz 
cd redis-3.2.11
make
make install
mkdir /etc/redis
mkdir /var/redis
cp utils/redis_init_script /etc/init.d/redis_6379
vi redis_6379 
(
add comments:
# redis   Startup script for Redis Server
#
# chkconfig: - 80 12
)
cp redis.conf /etc/redis/6379.conf
mkdir /var/redis/6379
vi /etc/redis/6379.conf
(
Set daemonize to yes (by default it is set to no).
Set the pidfile to /var/run/redis_6379.pid (modify the port if needed).
Change the port accordingly. In our example it is not needed as the default port is already 6379.
Set your preferred loglevel.
Set the logfile to /var/log/redis_6379.log
Set the dir to /var/redis/6379 (very important step!)
)
chkconfig redis_6379 on
service redis_6379 start
~~~



> centos 安装mysql 修改root密码：
>
> > 1. vi /etc/my.cnf  添加skip-grant-tables、skip-networking
> > 2. systemctl restart mariadb
> > 3. mysql_secure_installation
> > 4. vi /etc/my.cnf 注释skip-grant-tables、skip-networking
> > 5. systemctl restart mariadb
> > 6. mysql -uroot -p12345678
> > 7. quit （允许远程主机连接）



### ClassLoader

ClassLoader

总线锁、缓存锁与volatile可见性

synchronized 优化实现与（偏向锁、轻量级锁、重量级锁）



### Java int转String三种方式效率

>  int a = 123；
>
> 1. **a + "";**  //java源码对’+’运算符进行了重载, ’+’运算符的主要方式是使用StringBuilder或者StringBuffer来实现的
> 2. **String.valueOf(a)**  //String.valueOf(a)->Integer.toString(a)->IntegralToString.intToString(a)->convertInt(null, a)
> 3. **Integer.toString(a)**  //Integer.toString(a)->IntegralToString.intToString(a)->convertInt(null, a)
>
> 1效率最低，2，3一样。



### Java 0大小数组和null的区别

>  0大小数组作为参数无须进行null检查，因为0大小数组已分配对象，只是包含0个元素而已。
>
>  null则明确表示为空，对其进行的任何操作都会引起NullPointerException
>
>  ~~~java
>      //test ( new Object[0] ); // this is safe
>      //test ( null ); // this will cause NullPointerException
>  	public static void test(Object[] para) {
>          int[] arr1 = new int[0];
>          int[] arr2 = null;
>          for (Object o: para) {
>              System.out.println ( o );
>          }
>      }
>  ~~~



### SpringBoot 启动 

> 1.  new SpringApplication(sources)).run(args) //sources为@SpringBootApplication注解的启动类，args为启动类里main方法的参数，一般为0大小的String数组，将sources类对象存入sources set属性中。
>
> 2. 遍历springboot和web资源目录下的spring.factories文件，读取其中的Initializers配置，并实例化这些Initializers类对象，排序后存入SpringApplication类的initializers list属性中。
>
> 3. 遍历springboot和web资源目录下的spring.factories文件，读取其中的Listeners配置，并实例化这些Listeners类对象，排序后存入SpringApplication类的Listeners list属性中。
>
> 4. 根据new RuntimeException().getStackTrace()得到的堆栈信息遍历得到main方法所在的类，并将此类对象存入SpringApplication类的mainApplicationClass属性中。
>
> 5. 正式进入SpringApplication的实例方法run中。
>
> 6. 启动计时器StopWatch，用于记录应用启动时间。
>
> 7. 遍历springboot和web资源目录下的spring.factories文件，读取其中的SpringApplicationRunListener
>
>    配置，并实例化这些SpringApplicationRunListener类对象，排序后存入list，作为参数传入SpringApplicationRunListeners的构造函数，构造SpringApplicationRunListeners对象，然后启动list中的这些RunListener。
>
> 8.  createAndRefreshContext函数分析 - applyInitializers - publishEvent - multicastEvent - callRunner
>
>    Executor - execute



### Java事件监听与观察者模式

> ```
> EventListener
> Observable & Observer
> ```



### Java NIO 与 Netty

> Java IO: BIO(同步阻塞IO，一个连接一个线程)、伪异步IO(线程池)、NIO(Buffer、Channel、Selector，非阻塞IO基于操作系统的epoll实现)、AIO(AsynchronousChannel，异步IO，基于操作系统的AIO)
>
> **责任链模式**
>
> 



### maven自定义plugin

>   maven 自定义plugin：工程在Downloads/testmavenplugin下
>   步骤：
>
>   1. 新建maven工程
>     mvn archetype:generate \
>       -DgroupId=com.test \
>       -DartifactId=leo-demo-maven-plugin \
>       -DarchetypeGroupId=org.apache.maven.archetypes \
>       -DarchetypeArtifactId=maven-archetype-mojo
>
>   2. 新建Mojo类   
>     新建文件：BuildInfoMojo.java，继承自AbstractMojo，实现execute方法
>
>   3. mvn clean install，安装plugin到本地maven仓库
>
>   4. 使用plugin：
>     mvn com.test:leo-demo-maven-plugin:1.0-SNAPSHOT:buildinfo -Dbuildinfo.prefix=xxoo
>
>   5. 在其他工程中使用此plugin，在pom.xml中添加此plugin
>
>     ~~~
>                 <plugin>
>                     <groupId>com.test</groupId>
>                     <artifactId>leo-demo-maven-plugin</artifactId>
>                     <version>1.0-SNAPSHOT</version>
>                     <configuration>
>                         <prefix>xxoo</prefix>
>                     </configuration>
>                     <executions>
>                         <execution>
>                             <id>buildinfo</id>
>                             <phase>process-sources</phase>
>                             <goals>
>                                 <goal>buildinfo</goal>
>                             </goals>
>                         </execution>
>                     </executions>
>                 </plugin>
>     ~~~
>



### Lombok包：减少java代码冗余，让java代码更优雅

>  val 关键字： 实现类型推导
>
>  @NonNull：对方法参数加上非null限制
>
>  @Cleanup：实现局部变量的资源释放（如打开文件流后需要对应关闭文件流的操作）
>
>  @Getter/@Setter：自动生成getter、setter
>
>  @ToString：debug log最强帮手
>



### Java List 遍历删除的正确姿势

>  ~~~java
>  //动态数组remove元素的坑
>         List<Integer> listCards = new ArrayList<> ( Arrays.asList ( seqCards )  );
>  //错误姿势
>  /*      for (Integer listcard: listCards
>              ) {
>             if (Card.card2point ( listcard.intValue () ) == Card.PointA) {
>                 listCards.remove (listcard);
>             }
>         }
>  */
>  //正确姿势
>         Iterator<Integer> it = listCards.iterator ();
>         while (it.hasNext ()) {
>             Integer next = it.next ();
>             if (Card.card2point ( next.intValue () ) == Card.Point0) {
>                 it.remove ();
>             }
>         }
>  
>  ~~~
>



### Java Debug

>  Java 调试器和被调试程序是以 C/S 架构的形式运行的，首先必须有一端以服务器的形式启动起来，然后另一段以客户端连接上去。
>
> IDEA 在调试的时候，首先以服务器形式启动调试器，并在 xx 端口监听，然后 Java 程序以 socket 通信方式连接该端口，并将 JVM 暂停等待调试。
>
> IDEA远程调试的时候，首先以服务器形式在远程启动待调试的Java程序（启动Java程序时，加上以下JVM调试参数：-agentlib:jdwp=transport=dt_socket,server=y,suspend=n,address=4001），然后IDEA以客户端的形式去连接该端口，启动调试。



### Java 泛型方法与可变参数的bug：反编译查看类型转换的错误

>  ~~~java
>  public static void main(String[] args) {
>         test ( arg() );
>     }
>  
>     public static void test(Object... args) {
>         System.out.println ( args );
>     }
>  
>     //error
>     //public static <T> T arg() {
>     //    return (T) "df"; 
>     //}
>  
>  	public static <T> T[] arg(T... t) {
>          return t;
>      }
>     
>     //反编译后的代码：
>     
>     public static void main(String[] args) {
>         test ((Object[]) arg() ); //此处会报类型转换的错
>     }
>  
>     public static void test(Object... args) {
>         System.out.println ( args );
>     }:
>  
>     public static Object arg() {
>         return "df";
>     }
>  
>  	/************************/
>  
>     public static void main(String[] args) {
>  		System.out.println((Object) args);
>         test ( arg() );
>     }
>  
>     public static void test(Object... args) {
>         System.out.println ( args );
>     }
>  
>     public static String arg() {
>         return  "df";
>     }
>  
>  	//反编译后的代码：
>  
>  	public static void main(String args[])
>     {
>         System.out.println(args);
>         test(new Object[] {
>             arg()
>         });
>     }
>  
>     public static transient void test(Object aobj[])
>     {
>         System.out.println(((Object) (aobj)));
>     }
>  
>     public static String arg()
>     {
>         return "df";
>     }
>  ~~~



### 缓存更新

>  参考：https://coolshell.cn/articles/17416.html
>
> 1. Cache Aside Pattern: 更新由应用程序处理
>
>    - **失效**：应用程序先从cache取数据，没有得到，则从数据库中取数据，成功后，放到缓存中。
>
>    - **命中**：应用程序从cache中取数据，取到后返回。
>
>    - **更新**：先把数据存到数据库中，成功后，再让缓存失效。
>
> 2. Read/Write Through Pattern：更新由缓存模块处理
>
> 3. Write Behind Caching Pattern：更新由缓存异步批量同步到数据库



### 并发

> 并发即指：多线程(实现高并发的手段之一)，并发安全即指：多线程下的安全（多线程有共享变量即会产生安全问题）
>
> 多线程安全需保证三个特性：
>
> 1. 原子性（多个操作要么全部执行，要么全部不执行，不能存在部分执行部分不执行这种中间状态。代码的操作大部分都不是原子操作，因此需要额外的措施来保证原子操作）
>
> 2. 可见性（Java内存模型决定了有工作内存和主内存之分，机器硬件架构都决定了有缓存和主存之分，因此需要额外的措施保证对工作内存的修改会立即刷新到主内存）
>
> 3. 顺序性（编译器和CPU会有指令重排序，所以需要额外的措施来保证代码执行的顺序性）
>
> 
>
> **ThreadLocal** 适用于如下两种场景 (<http://www.jasongj.com/java/threadlocal/>)
>
> - 每个线程需要有自己单独的实例
> - 实例需要在多个方法中共享，但不希望被多线程共享
>
> 对于第一点，每个线程拥有自己实例，实现它的方式很多。例如可以在线程内部构建一个单独的实例。ThreadLocal 可以以非常方便的形式满足该需求。
>
> 对于第二点，可以在满足第一点（每个线程有自己的实例）的条件下，通过方法间引用传递的形式实现。ThreadLocal 使得代码耦合度更低，且实现更优雅。
>
> ~~~
> ThreadLocal 并不解决线程间共享数据的问题
> ThreadLocal 通过隐式的在不同线程内创建独立实例副本避免了实例线程安全的问题
> 每个线程持有一个 Map 并维护了 ThreadLocal 对象与具体实例的映射，该 Map 由于只被持有它的线程访问，故不存在线程安全以及锁的问题
> ThreadLocalMap 的 Entry 对 ThreadLocal 的引用为弱引用，避免了 ThreadLocal 对象无法被回收的问题
> ThreadLocalMap 的 set 方法通过调用 replaceStaleEntry 方法回收键为 null 的 Entry 对象的值（即为具体实例）以及 Entry 对象本身从而防止内存泄漏
> ThreadLocal 适用于变量在线程间隔离且在方法间共享的场景
> 
> ThreadLocal 内存泄漏问题？？？？
> ~~~
>
> 
>
> **volatile**适用于不需要保证原子性，但却需要保证可见性的场景。volatile最合适使用的场景是：**一个线程写，多个线程读**
>
> 一种典型的使用场景是用它修饰用于停止线程的状态标记。
>
> 
>
> **Synchronized**关键字 和 **ReentrantLock**都是可重入锁，
>
> 区别：
>
> Synchronized是Java语言特性上的同步，更简洁，适用范围广
>
> ReentrantLock是可定制的锁机制，提供了Synchronized没有的特性，比如Condition，可中断获取锁，timeout获取锁，公平获取锁。
>
> 
>
> **final** 关键字保证变量在构造阶段完成初始化，符合**可见性**，但是final的引用类型，要保证线程安全，仍需要同步
>
> ~~~java
>  //多线程下对list的读写不是线程安全的
> 	public static final List<String> strList = new ArrayList<> ( );
> 
>  public static void main(String[] args) {
>      for (int i = 0; i < 20; i++) {
>          if (i % 2 == 0) {
>              int finalI = i;
>              new Thread ( () -> {
>                  System.out.println ( "Thread: " + Thread.currentThread ().getName () );
>                  strList.add ( finalI + "" );
>              } ).start ();
>          } else {
>             new Thread ( () -> {
>                 for (String str: strList
>                      ) {
>                    System.out.println ("Thread: " + Thread.currentThread ().getId () + "; strList member: " + str );
>                 }
>             } ).start ();
>          }
>      }
>  }
> ~~~
>
> 



### 线程安全的单例模式

> 1. 饿汉模式：在类构造阶段就完成实例的创建，可以保证线程安全
>
>    ~~~java
>    
>    public class MySingleton {
>    	
>    	private static MySingleton instance = new MySingleton();
>    	
>    	private MySingleton(){}
>    	
>    	public static MySingleton getInstance() {
>    		return instance;
>    	}
>    	
>    }
>    ~~~
>
>    
>
> 2. 懒汉模式：方法块加Synchronized关键字，或者使用DCL（Double Check Locking）+ volatile 模式
>
>    ~~~java
>    
>    public class MySingleton {
>    	
>    	private static MySingleton instance = null;
>    	
>    	private MySingleton(){}
>    	//方法块加synchronized关键字
>    	public synchronized static MySingleton getInstance() {
>    		try { 
>    			if(instance == null){
>    				instance = new MySingleton();
>    			}
>    		} catch (InterruptedException e) { 
>    			e.printStackTrace();
>    		}
>    		return instance;
>    	}
>    }
>    ~~~
>
>    ~~~java
>    
>    public class MySingleton {
>    	
>    	private volatile static MySingleton instance = null;
>    	
>    	private MySingleton(){}
>    	//DCL + volatile
>    	public static MySingleton getInstance() {
>    		try { 
>    			if(instance == null){
>                    synchronized(MySingleton.class) {
>                        if(instance == null) {
>    						instance = new MySingleton();
>                        }
>                    }
>    			}
>    		} catch (InterruptedException e) { 
>    			e.printStackTrace();
>    		}
>    		return instance;
>    	}
>    }
>    ~~~
>
>    
>
> 3. 静态内部类模式：利用虚拟机类初始化机制（什么情况下才会去加载初始化一个类？类的主动引用时）保证延迟初始化且线程安全
>
>    ~~~java
>    public class MySingleton {
>    	
>    	//内部类
>    	private static class MySingletonHandler{
>    		private static MySingleton instance = new MySingleton();
>    	} 
>    	
>    	private MySingleton(){}
>    	 
>    	public static MySingleton getInstance() { 
>    		return MySingletonHandler.instance;
>    	}
>    }
>    ~~~
>
>    
>
> 4. 枚举：枚举在语言层面保证了创建一个enum类型是线程安全的
>
>    ~~~java
>    public enum Singleton {
>        INSTANCE;
>    }
>    ~~~
>
> But, Sping框架的单例模式实现是使用**单例注册表**的方式：
>
> ~~~java
> public class SingletonReg {
>     private final static Map<String, Object> singletonObjects = new ConcurrentHashMap<String, Object>();
> 
>     static {
>         SingletonReg singletonReg = new SingletonReg();
>     }
> 
>     private SingletonReg() {}
> 
>     public static SingletonReg getInstance(String name) {
>         if (name == null) {
>             name = "com.lianggzone.designpattern.singleton.sample.SingletonReg";
>         }
>         if (singletonObjects.get(name) == null) {
>             try {
>                 singletonObjects.put(name, Class.forName(name).newInstance());
>             } catch (Exception ex) {
>                 ex.printStackTrace();
>             }
>         }
>         return (SingletonReg) singletonObjects.get(name);
>     }
> }
> ~~~
>
> 



### Java 引用 

Strong Reference、 SoftReference、WeakReference、PhantomReference、FinalReference

FinalReference：有实现finalize方法的类的对象会被封装成Finalizer，然后被注册到Finalizer链表中，Finalizer类静态初始化时会启动FinalizerThread线程，此线程会在对象被回收前，遍历ReferenceQueue，然后执行相应的finalize方法



DirectByteBuffer 自动内存回收（Cleaner extends PhantomReference）：

DirectByteBuffer在初始化的时候通过Cleaner.create(this, new Deallocator())将DirectByteBuffer加入虚引用的对象，这样在DirectByteBuffer被回收时，相应的虚引用Cleaner会被加入ReferenceQueue，然后静态启动的ReferenceHandler会遍历ReferenceQueue，取出对应的虚引用Cleaner，调用Cleaner的clean方法，clean方法会启动Deallocator线程去释放堆外内存。

But，这种依赖于GC回收DirectByteBuffer来回收堆外内存的方式，会导致堆外内存回收不及时，因为DirectByteBuffer是在堆内内存分配，依赖于JVM的GC，不确定性大。

因此，Netty使用自己的策略（内存池+引用计数）来回收堆外内存。



Netty高性能IO主要特性：

1. 基于Java NIO 封装，NIO基于Linux epoll
2. Reactor线程模型
3. 使用DirectByteBuffer分配堆外内存进行socket读写
4. 使用内存池+引用计数来管理内存（堆外+堆内）的分配和释放，避免堆内内存的频繁GC和堆外内存的回收不及时

### Msql  innodb myisam

myisam: 表级锁，不支持事务，不支持外键，崩溃后无法安全恢复，适合查询比较多的场景

innodb：行级锁，支持事务，支持外键，自动崩溃恢复，适合增删改比较多的场景



### Java Stream parallelStream



### Hibernate & Mybatis



