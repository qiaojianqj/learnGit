#######################################################################
//java design-patterns learning
site:   https://springframework.guru/gang-of-four-design-patterns/

interpreter pattern: used in env like: sql parsing. Given a language, define a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.
    Client(ExpressionParser) ----> Context(String)
    Abstract Expression (Expression) ----> interpret(Context)
    Terminal Expression(NumberExpression) ----> interpret(Context)
    Nonterminal Expression (AdditionExpression, SubtractionExpression, and MultiplicationExpression) ----> interpret(Context)

    javac com\interpreter\main.java
    java com.interpreter.main

abstract factory pattern: factory of factories, creating families of related or dependent objects.
    Cheese
        ----GoatCheese
        ----GoatCheese
    Sauce
        ----CaliforniaOilSauce
        ----CaliforniaOilSauce
    BaseToppingFactory
        ----SicillianToppingFactory
        ----GourmetToppingFactory
    
    Pizza
        ----CheesePizza
        ----PepperoniPizza
        ----VeggiePizza
    BasePizzaFactory
        ----SicilianPizzaFactory
        ----GourmetPizzaFactory

    javac com\abstractFactory\main.java
    java com.abstractFactory.main

builder pattern: creating an object through a step-by-step construction process and returning the object as the final step.
    House
    HouseBuilder
        ----ConcreteHouseBuilder
        ----PrefabricateHouseBuilder
    ConstructionEngineer

    javac com\builder\main.java
    java com.builder.main

proxy pattern: using a proxy (surrogate) object “in place of” another object. The objective of a proxy object is to control the creation of and access to the real object it represents.
    ReportGenerator
        ----ReportGeneratorImpl
        ----ReportGeneratorImplProxy
    Role

    javac com\proxy\main.java
    java com.proxy.main

composite pattern: Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.
    CatalogComponent
        ----Product
        ----ProductCatalog (Composite)

    javac com\composite\main.java
    java com.composite.main
    
strategy pattern: used in env like: a data encryption class that encrypts data using different encryption algorithms; a number sorting class that supports multiple sorting algorithms; define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.
    EncryptionStrategy
        ----AesEncryptionStrategy
        ----BlowfishEncryptionStrategy
    Encryptor

    javac com\strategy\main.java
    java com.strategy.main
    
template method pattern: Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm’s structure
    PizzaMaker
        ----VegPizzaMaker
        ----NonVegPizzaMaker
        ----InHouseAssortedPizzaMaker
        
    javac com\templateMethod\main.java
    java com.templateMethod.main

prototype pattern: create new object by copying existing object(usually the common property consist of the prototype object)(be careful with shallow copy and deep copy) 
    PrototypeCapableDocument 
        ----TAndC 
        ----NDAgreement
    DocumentPrototypeManager
    
    javac com\prototype\main.java
    java com.prototype.main
    
observer pattern: define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically
    Subject
        ----Product
    Observer
        ----Bidder
        
    javac com\observer\main.java
    java com.observer.main
    
 * 观察者模式典型实现方式：

 * 1、定义2个接口：观察者（通知）接口、被观察者（主题）接口

 * 2、定义2个类，观察者对象实现观察者接口、主题类实现被观者接口

 * 3、主题类注册自己需要通知的观察者

 * 4、主题类某个业务逻辑发生时通知观察者对象，每个观察者执行自己的业务逻辑。
 
adapter pattern: convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn’t otherwise because of incompatible interfaces
    CsvFormattable
        ----CsvFormatter
    TextFormattable
        ----NewLineFormatter
        ----CsvAdatperImpl (adpater CsvFormattable to TextFormattable)

    javac com\adapter\main.java
    java com.adapter.main

    
decorator pattern: allows for an object’s behavior to be extended dynamically at run time
    FlowerBouquet
        ----RoseBouquet
        ----OrchidBouquet
        ----FlowerBouquetDecorator (abstract)
                    ----GlitterDecorator
                    ----PaperWrapperDecorator
                    ----RibbonBowDecorator

    javac com\decorator\main.java
    java com.decorator.main

command pattern: whenever you are writing code that require some invoker to perform different actions on multiple receivers, consider using the Command Pattern
    CommandBase(execute)
        ----xxCommand(xx execute command)
        ----ooCommand(oo execute command)
    Administrator(execute commandBase)

visitor pattern: visitor lets you define a new operation without changing the classes of the elements on which it operates
non visitor:
    MailClient(sendMail, receiveMail, configureForMac, configureForWindows, configureForXX<need to modify every Client class>)
        OperaMailClient
        SquirrelMailClient
        ZimbraMailClient
visitor:
    MailClient(sendMail, receiveMail, accept)
        OperaMailClient
        SquirrelMailClient
        ZimbraMailClient

    MailClientVisitor(visit)
        WindowsMailClientVisitor
        MacMailClientVisitor
        LinuxMailClientVisitor
        XXMailClientVisitor
#############################################################
//c++ learning
1. extern声明放头文件，定义放源文件;extern声明类型要和定义类型一样;static即使修饰的是全局变量，它的作用域也只能是本编译单元,因此，将static全局变量放在源文件;
   static的用法1： 扩展生存期： 用于局部变量
   static的用法2： 限制作用域： 用于全局变量， 普通全局变量的作用域为整个项目，static全局变量的作用域为当前cpp文件
   static的用法3： 数据唯一性： 用于C++类成员变量和成员函数
2. 常量指针与指针常量
   常量指针： 
           指向常量的指针（其实也可以指向变量），不能通过指针修改所指对象（*p = xx; 错）， 可以更改指针的指向（p = &var2; 对）。
           用法： const int *p = &var1;  int const *p = &var1;
   指针常量：
           指针本身是个常量，在声明时必须同时初始化指向一个变量（不能指向常量）， 可以通过指针修改所指对象（*p = xx; 对）， 不能更改指针的指向（p = &var2; 错）。
           用法： int * const p = &var1;
3. 引用的语义在底层是通过 指针常量 实现的， 所以引用在声明时必须初始化，且可以通过引用修改所指对象。 因此引用在底层是占一个指针的内存大小的。
4. 不能建立数组引用是说，数组的元素不能是引用（int& array[num]; 错），因为引用只能在初始化时绑定到一个对象上； 但是可以建立引用数组（int(& refArray)[num]; 对）
5. 数组的降阶： 
            数组作为函数参数时，退化成一个普通指针，size为一个指针的大小:'sizeof' on array function parameter 'array' will return size of 'char*'
            解决办法1： 在参数中增加数组的长度len作为参数
            解决办法2： 使用c++中的引用数组作为参数，例如： void Test( int (&array)[20] )
6. 结构体零大小数组的使用：（参见linux源码），用于变长结构体
    优点： 零大小数组只是一个占位符（因为数组名本身代表一个不可以修改的常量地址，偏移量，指向结构体最后紧邻的空间），不占用空间；
         因此通过一次内存分配即可分配一段连续的内存。释放时也只释放一次即可。
struct pppoe_tag {
    __u16 tag_type;
    __u16 tag_len;
    char *tag_data;
} __attribute ((packed));
创建：
struct pppoe_tag *sample_tag;
__u16 sample_tag_len = 10;
sample_tag = (struct pppoe_tag *)malloc(sizeof(struct pppoe_tag)+sizeof(char)*sample_tag_len);
sample_tag->tag_type = 0xffff;
sample_tag->tag_len = sample_tag_len;
memcpy(sample_tag->tag_data,"datas............", sample_tag_len);
...
释放：
free(sample_tag)

7. 为什么c++拷贝构造函数一定是传引用？为什么不能是传指针的方式？   
   首先不能是传值（会造成递归调用拷贝构造函数，死循环） 然后传指针确实不会造成死循环的问题，但是你得自己实现编译器让它知道发生拷贝操作的时候去调用你写的传指针那个函数。因为传指针在调用处就不是拷贝语义了。
   指针本身就是一个变量，只不过它的值是另一个变量的地址而已，所以说传指针也是值传递。

8. 在使用迭代器的循环体内，不要向迭代器所属容器添加元素，因为这会使迭代器失效

9. 字符数组： char arr[] = "C++"; 自动添加结束符'\0'，因此他的大小是4。

10. 函数重载（同一作用域内的同名形参不同的函数才构成重载）：
    顶层const形参不能构成重载：
        int lookup(int); 与 int lookup(const int); 重复声明
        int lookup(int*); 与 int lookup(int* const); 重复声明
    底层const形参可以构成重载：（通过实参类型的不同来区分）
        int lookup(int &); 与 int lookup(const int&); 根据实参是常量还是非常量进行区分
        int lookup(int*); 与 int lookup(const int*); 根据实参是常量还是非常量进行区分
    类成员函数的const重载（因为只有const 对象可以调用const成员函数，在调用时会有个隐式参数const this指针， 通过这个隐式参数的不同来进行区分）：
    class Screen {
    public:
        Screen& display(ostream &os)
        {
            do_display(os);
            return *this;
        }
        const Screen& display(ostream &os) const
        {
            do_display(os);
            return *this;            
        }
    private:
        void do_display(ostream &os) const
        {
            os<< contents;
        }
        string contents;
    };

11. 类构造函数初始值列表是对const, 引用和类类型进行初始化的地方， 构造函数方法体内是赋值操作而不是初始化。
    class ConstRef{
        public:
            ConstRef(int ii);
        private:
            int i;
            const int ci;
            int &ri;
    };
    ConstRef::ConstRef(int ii)
    {
        i = ii; //内置类型赋值，正确
        ci = ii; //错误，不能给const赋值
        ri = i; //错误，引用必须先初始化
    }
    //使用初始化列表完成初始化，正确。 另外初始化列表里的初始化顺序是由类成员变量的定义顺序决定的。
    ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i)
    {}
12. 只有一个参数的类构造函数又成为转换构造函数，它可以隐式的将其他类型转换成类类型。将此种构造函数声明为explicit，可以阻止这种隐式转换（隐式转换一般在拷贝初始化时发生）。 explicit构造函数只能用于直接初始化。

#############################################################
        
//golang learning
https://nanxiao.gitbooks.io/golang-101-hacks/

go vendor

go iota

go ...

go install -gcflags "-N -l" 关闭内联优化，生成的可执行文件可用于gdb调试或delve调试

go slice 内部结构： 
a) Pointer: Points to the start position of slice in the underlying array;
b) length (type is int): the number of the valid elements of the slice;
b) capacity (type is int): the total number of slots of the slice.

go append (append in slice is tricky, be careful)

go interface ( define a interface Foo, if type A implements the method in Foo, then *A will automaticly implements the method in Foo. But the reverse is not true.)

go types (
    type mySlice1 []int
    type mySlice2 []int
    the type mySlice1 and mySlice2 can't assign value each other.
    but mySlice1, mySlice2 and []int can assign value each other.
)

go check data race

go debug tool - delve, gdb

go goroutine ( main goroutine exit后，它创建的所有goroutine也exit， 所以在main goroutine 里应该等待其他goroutine执行完成)

go defer （defer return语句， 返回值之间的执行顺序： return语句最先执行，将结果写入返回值中； 接着defer执行， 最后函数携带当前返回值退出； https://studygolang.com/articles/4809）

go channel （create channel through make; unbuffered & buffered; block & unblock; close; select）
Operation type	    Nil channel	     Closed channel
    Send	            Block	            Panic
    Receive	            Block	            Not block, return zero value of channel's type
    Close	            Panic	            Panic

go reflect (反射提供了一种机制，允许程序在运行时检查接口变量内部存储的 (value, type) 对,并修改相应的值.)

go context (用来简化在http server中对于处理单个http client请求的多个goroutine之间 与 请求域的数据、取消信号、截止时间等相关操作)
    
go pprof (net/http/pprof package自带的性能监测工具; httprouter & pprof usecase: https://github.com/feixiao/httpprof)

go 可变参数 （https://www.jianshu.com/p/94710d8ab691）

#############################################################
//java learning

1. hashCode & equals 参考 https://blog.csdn.net/javazejian/article/details/51348320

Object类hashCode实现是jni(java native interface)实现，它将对象的内存地址映射到一个hash值
Object类equals实现是比较两个对象的引用，也就是比较的对象的内存地址

比如Map<K,V>是通过把K对象取hash值运用hash算法来存取键值对的， 此时对K对象的比较是通过其equals和hashCode方法，所以在K类中应该同时重写equals和hashCode方法

2. Array, ArrayList, LinkedList

    interface Collection<E>
    interface List<E> extends Collection<E>
    ArrayList<E> implements List<E> /  LinkedList<E> implements List<E>

    Array: 固定大小的数组， 属于java primitive 类型， 可以存放primitive类型或objects 例如： int arr[] = new int[10];
    ArrayList: 动态数组， 默认大小为10， 属于Collection集合， 只能存放objects. 查询(get)，修改(set)性能高（数据量很大时）
    LinkedList： 动态双向链表，属于Collection集合，只能存放objects. 插入(add)，删除(remove)性能高（数据量很大时）
    
    Vector： 是线程安全的ArrayList
    
    数组和链表的性能对比：
    get/set： 数组直接返回index位置上的元素， 链表要通过for循环遍历查找
    add/remove: 在指定位置插入或删除元素时， 数组要移动（copy）后面的所有元素。 链表还是要通过for循环遍历找到对应元素再修改前后元素的指针。
    
3. HashMap实现： 数组+链表+红黑树（JDK1.8： 链表长度大于8时转为红黑树）， 参考 https://tech.meituan.com/java-hashmap.html

    HashMap put,get实现： 对key的hashCode（）再做hash（ (h = key.hashCode()) ^ (h >>> 16) ），然后通过i = (n - 1) & hash;来取数组index， 然后通过key.equals(k)来判定是否插入覆盖或get。
    
    扩容特别耗性能，所以初始化一个HashMap时估算一个大致的大小数值，避免频繁扩容
    HashMap不是线程安全的。并发环境下使用ConcurrentHashMap
    
    LinkedHashMap: 按插入顺序排序的HashMap
    TreeMap: 按Key值的自然序或自定义的Comparator来排序

4. Collections.sort()和Arrays.sort()排序算法， 参考https://blog.csdn.net/timheath/article/details/68930482
   
   Collections.sort() {
        MergeSort(归并排序)
        TimSort
   }
   
   Arrays.sort() {
        DualPivotQuicksort（双轴快速排序）
        insertion sort
        MergeSort(归并排序)
   }

5. 浅拷贝 & 深拷贝， 参考 https://segmentfault.com/a/1190000010648514

    默认clone都是浅拷贝， 拷贝对象的时候，要使用深拷贝
    
6. String s = "abc" 和 String s = new String("abc") 区别， 参考 https://www.jianshu.com/p/2624036c9daa  & https://segmentfault.com/q/1010000008746502

    基础数据类型和引用存放在栈空间， new的对象存放在堆空间， 字符串常量存放在常量池（类似于静态数据段） 
    
    String s = new String("xyz"); 创建两个对象：
    首先在string池（常量池）内找，找到，不创建string对象。 否则创建， 这样就一个string对象。 （String s = "xyz";）
    遇到new运算符号了，在堆内存上创建string对象，并将其返回给s，又一个对象。 （String s = new String("xyz");）
    所以总共是2个对象。

7. JVM GC机制： GCroot（栈中的本地变量引用的对象，方法区中的类静态属性引用的对象或常量引用的对象，native方法引用的对象）可达性分析 + 分代（）收集 
    GCRoot可达性分析： 从GCRoot出发搜索引用链，没被搜索到的对象是不可用的，再通过finalize方法进行标记筛选判定是否进行垃圾回收
    分代收集： 年轻代（Eden区，Survivor0区，Survivor1区）， 年老代，永久代

8.  设计模式6大原则： （https://blog.csdn.net/zhengzhb/article/details/7296944）
    开闭原则： 对扩展开放，对修改关闭
    单一职责原则： 一个类只负责一项职责
    里氏替换原则： 所有引用基类的地方必须能透明地使用其子类的对象（类B继承类A时，除添加新的方法完成新增功能外，尽量不要重写父类A的方法，也尽量不要重载父类A的方法）
    依赖倒置原则： 面向接口编程（高层模块不应该依赖低层模块，二者都应该依赖其抽象；抽象不应该依赖细节；细节应该依赖抽象）
    接口隔离原则： 建立单一接口，不要建立庞大臃肿的接口，尽量细化接口，接口中的方法尽量少
    迪米特法则：  尽量降低类与类之间的耦合（一个类对自己依赖的类知道的越少越好）
    
9. JMM: java内存模型 参考 https://blog.csdn.net/javazejian/article/details/72772461
    原子性： 一个操作是不可中断的
    可见性： 当一个线程修改了某个共享变量的值，其他线程是否能够马上得知这个修改的值
    有序性： 对于单线程的执行代码，我们总是认为代码的执行是按顺序依次执行的
    
    JMM提供以下方式来保证JMM规则
    JVM自身提供的对基本数据类型读写操作的原子性外，对于方法级别或者代码块级别的原子性操作，可以使用synchronized关键字或者重入锁(ReentrantLock)保证程序执行的原子性
    工作内存与主内存同步延迟现象导致的可见性问题，可以使用synchronized关键字或者volatile关键字解决，它们都可以使一个线程修改后的变量立即对其他线程可见
    
    synchronized: 可以保证被修饰变量或代码块的可见性以及原子性
    volatile: 只可以保证变量的可见性

    final 对象： 不可变对象一旦构造完成, 其所有属性就不能更改, 不可变对象显然都是线程安全的
    
10. this逃逸: 是指在构造函数返回之前其他线程就持有该对象的引用。this逃逸经常发生在构造函数中启动线程或注册监听器时
    解决方法： 在构造函数中创建Thread对象是没有问题的, 但是不要启动Thread. 可以提供一个init方法
    
11. java Enum源码实现
 
12. java Unsafe： 提供了可以随意查看及修改JVM中运行时的数据结构； 可以突破单例模式限制，直接创建多个实例； 等...

13. java happen-before规则 参考 http://cmsblogs.com/?p=2102 

14. java 重载：相同方法名，不同参数列表（静态多态， 编译时决定） 
    java 覆写：相同方法名，相同参数列表（子类覆写父类）（动态多态， 运行时决定）
    多态： 接口相同，实现不同
    参考代码：
    
class Base {
    private int i;
    
    public void set(int i) {
        this.i = i;
        System.out.println("set i value in Base: " + i);
    }
}

class Derive extends Base {
    private String j;

    public void set(String j) {
        this.j = j;
        System.out.println("set j value in Derive: " + j);
    }

}

public class xxoo {
    
    public static void main(String args[]) {
        Base obj = new Base();
        obj.set(123);
        
        obj = new Derive();
        obj.set(345);
        //obj.set("str");
        
        Derive d = (Derive)obj;
        d.set(456);
        d.set("str");
        
        /*
        Derive d =  new Derive();
        d.set("str");
        d.set(456);
        */
    }
 
}

15. 死锁： 两个或两个以上的进程在执行过程中，因争夺资源而造成的一种互相等待的现象
    产生条件： 1. 资源的互斥使用（对资源的使用互斥锁） 2. 锁不可抢占（unlock之后才可以重新lock） 3. 请求与保持（Lock A不放，再去Lock B） 4. 循环等待， 即存在一个进程-资源环形链：{p0,p1,p2,...pn},进程p0（或线程）等待p1占用的资源，p1等待p2占用的资源，pn等待p0占用的资源。（最直观的理解是，p0等待p1占用的资源，而p1又在等待p0占用的资源，于是两个进程就相互等待）
    避免死锁： 避免形成循环等待资源(Thread 1...n 使用锁顺序保持一致： Lock A，再Lock B)， 避免无限期等待资源(tryLock())
    
    活锁： 由于某些条件没有满足，导致一直重复尝试，失败，尝试，失败。
    产生条件： 举例： 在a线程里：b.join(); 然后在b线程里：a.join()。两个线程都处于等待状态
    解决方法： 设置最大重试次数， 调整重试机制
    
    饥饿： 一个线程因为CPU时间全部被其他线程抢走而得不到CPU运行时间
    产生条件： 高优先级线程吞噬所有的低优先级线程的CPU时间； 线程被永久堵塞在一个等待进入同步块的状态，因为其他线程总是能在它之前持续地对该同步块进行访问
    解决方法： 公平性 – 即所有线程均能公平地获得运行机会； 提升请求线程的优先级；
    
16. java CAS（CompareAndSwap）， ABA（A-B-A）， 乐观锁， 悲观锁
    参考 http://zl198751.iteye.com/blog/1848575  http://blog.hesey.net/2011/09/resolve-aba-by-atomicstampedreference.html http://www.hollischuang.com/archives/934
    CAS: 比较并交换（CAS有3个操作数，内存值V，旧的预期值A，要修改的新值B。当且仅当预期值A和内存值V相同时，将内存值V修改为B，否则什么都不做。）
    CAS无法避免 ABA问题， ABA问题可通过乐观锁的方式解决
    
    乐观锁： 不使用锁，为数据增加版本标识（或时间戳），更新数据时对比数据值和其版本标识，都相等时才更新
    悲观锁： 先取锁再访问
    
17. java 反射机制与Class类（每个类（型）都有一个Class对象， 当装载类时，Class类型的对象时由JVM自动创建）

18. java 使用 匿名内部类 可以 实例化一个 抽象类 实例， 或者 实现一个 接口

	java 匿名内部类由于不能声明构造方法，可以使用 实例初始化块 完成一些操作
	例如：双括号初始化：
	ArrayList<String> list = new ArrayList<>();
	list.add("first");
	list.add("second");
	parser(list);
	如果在此后不再需要这个ArrayList，则使用匿名内部类+实例初始化块更好
	parser(new ArrayList<String>() {{ add("first"); add("second");}});

    参考 https://www.cnblogs.com/nerxious/archive/2013/01/25/2876489.html
	参考 http://www.cnblogs.com/chenpi/p/5507664.html
#############################################################
//mysql learning
 centos7 安装mysql 参考 https://www.cnblogs.com/starof/p/4680083.html
 
 启动mysql
 service mysqld start
 
 查看mysql 监听端口
 netstat -antp | grep mysql
 
 登陆：
 mysql -uroot -p123456
 
 设置用户密码：
 先登录， 再执行
 set password for 'root'@'localhost' =password('123456');
 
