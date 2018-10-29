# HashMap源码分析



	网上很多对`HashMap`的源码分析，一上来就是从内部结构开始，让阅读的人对源码整体结构没有全貌。今天我打算从打开源码文件，从第一行代码开始阅读的方式来分析源码。

### 类文件说明

	我们知道java sdk里的注释是最好的doc文档。每个源码文件开始都有一大段注释来说明此文件所描述的内容，在这儿我们可以对源码有个大概的了解。

**一：**

	`HashMap`和`HashTable`类似，不同之处在于`HashMap`是非同步的即不是线程安全的；`HashMap`允许key、value为null

**二：**

	`HashMap`不保证插入元素所存放的顺序，甚至不保证元素的存放顺序会一直保持不变

**三：**

	假定hash函数散列性能比较好，基本的get、put操作都是O(1) 性能。对Map的遍历操作性能则和Map的capacity、size成比例，所以如果对遍历性能要求比较高的话，则不要将`initial capacity`设置太高，也不要将`loadFactor`设置过低

**四：**

	`HashMap`有两个重要的影响性能的参数：`initial capacity`和`loadFactor`。`initial capacity`是哈希表创建时哈希数组的初始大小。`loadFactor`(负载因子)是哈希表自动扩容前所允许哈希数组的已使用容量，当已使用容量超过`loadFactor`时，哈希表自动扩容到两倍之前的capacity，重新构建内部结构。`loadFactor`为0.75时，时间空间度最好。`loadFactor`大于0.75时，空间消耗少，时间消耗增加。`loadFactor`小于0.75时，空间消耗增加，时间消耗少。所以在初始化`HashMap`时要根据`loadFactor`来设置`initial capacity`，以减少扩容(影响性能)的次数。

**五：**

	`HashMap`是通过key的hashcode来确定所对应的存放bucket，所以为了`HashMap`的性能，需要让key的hashcode尽量不重复

**六：**

	`HashMap`不是线程安全的，所以有多个线程同时访问同一个`HashMap`时，如果至少有一个线程修改了`HashMap`的结构(增加或删除元素等操作)，则需要对这个`HashMap`加上Synchronized同步。一个使得`HashMap`成为线程安全的方法如下：

~~~
Map m = Collections.synchronizedMap(new HashMap(...));
~~~

**七：**

	在`HashMap`上取`Iterator`之后，如果不是通过`Iterator`自己的方法来改变`HashMap`的结构（增加或删除元素等操作），`Iterator`将会失效，后续基于`Iterator`的代码将会抛异常：`java.util.ConcurrentModificationException`。

~~~java
public class HashMapTest {
    private static  Map<String, String> employers = new HashMap<> (  );

    public static void main(String[] args) {
        employers.put ( "1", "qiaojian" );
        employers.put ( "2", "leo" );
        employers.put ( "3", "guo" );
        employers.put ( "4", "min" );

        Iterator<Map.Entry<String, String>> iter = employers.entrySet ().iterator ();
        while (iter.hasNext ()) {
            employers.put ( "5", "bab" ); //此行代码导致抛出异常
            Map.Entry<String, String> next = iter.next ();
            if (next.getKey ().equals ( "2" )) {
                iter.remove (); //通过Iterator自己的方法删除元素是正确的
            }
        }
        System.out.println ( employers.size () );
    }
}
~~~



### serialVersionUID 

`serialVersionUID` 用来表明类的不同版本间的兼容性。

对于实现了Serializable接口的类表示此类可以被序列化和反序列化。

`serialVersionUID`是根据类名、接口名、成员方法及属性等来生成一个64位的哈希字段。

Java的反序列化即是通过传过来的`serialVersionUID`和本地定义的类的`serialVersionUID`作比对来确保反序列化的正确性。

显示的定义`serialVersionUID`可以在反序列化时，确保类版本的兼容性。即使某个类在与之对应的对象已经序列化出去后做了修改，该对象依然可以被正确反序列化（当`serialVersionUID`相同时，它就会将不一样的field以type的预设值Deserialize，确保兼容性）。

~~~java
//关于HashMap的序列化
//1. 首先 HashMap 实现了 Serializable 接口，可以序列化

//2. serialVersionUID 用于保证版本的兼容性

//3. static和final属性不会被序列化

//4. transient修饰的属性不会被序列化

//5. HashMap的 table、entrySet、size和modCount属性都被标记为transient，表示不会使用JDK中默认的序列化方法

//6. HashMap实现了自己的序列化方法: writeObject 和反序列化方法 readObject

//7. Java的序列化使用ObjectOutputStream类的各种方法（writeInt、writeBoolean、writeObject等），反序列化使用ObjectInputStream的各种方法（readInt、readBoolean、readObject等），而writeObject和readObject会判断被序列化对象是否重写了对应的方法来调用被序列化对象自己的方法完成自定义的序列化和反序列化

//8. HashMap为什么要自己实现序列化和反序列化方法？ 因为HashMap中，由于Entry的存放位置是根据Key的Hash值来计算，然后存放到数组中的，对于同一个Key，在不同的JVM实现中计算得出的Hash值可能是不同的。而Key的Hash值不同会导致table结构的不同，导致JDK默认序列化出来的数据也不同。而HashMap自定义的序列化方法writeObject中将table里每个Node的key和value分别序列化。在自定义的反序列化方法readObject中将key、value提取出来重新计算hash，重新put形成table

~~~



### tableSizeFor

~~~java
    /**
     * Returns a power of two size for the given target capacity.
     * 此函数的作用是：根据当前传入的cap，计算出table size（为2的幂次方，等于 capacity * loadfactor）
     * 比如：new Hashmap<> (5); 则根据5计算出 table size为8
     */
    static final int tableSizeFor(int cap) {
        int n = cap - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }

	//为什么要保持table size是2的幂次方？
	//因为：在put元素时是根据（hash(key) % capacity）来确定元素要存放的index：
	//而：取余(%)操作中如果除数是2的幂次方则等同于与其除数减一的与(&)操作。
	//所以上式等同于下式
	index = e.hash % newCap
	//等同于
	index = e.hash & (newCap - 1);
	//所以保持table size是2的幂次方是为了根据hash来计算index可以通过&运算完成以提供性能
~~~

### hash(key)

~~~java
    //由下可见，在put元素时，根据key计算hash值
	public V put(K key, V value) {
        return putVal(hash(key), key, value, false, true);
    }
	//hash值的计算规则：取key的hashCode与其自身的高16位进行异或运算
	static final int hash(Object key) {
        int h;
        return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    }

	//为什么hash计算要取key的hashCode与其自身的高16位进行异或运算？
	//因为上面我们提到index的运算规则是e.hash & (newCap - 1)。
	//由于newCap是2的幂次方，那么newCap - 1的高位应该为0。
	//如果e.hash值只用自身的hashcode的话，那么newCap - 1只会和e.hash低位做&操作(e.hash有32位值，而newCap - 1 通常没有那么大)。这样一来，e.hash的值就只有低位参与运算，高位未参与计算，从而会带来哈希冲突的风险。
	//所以在计算key的哈希值的时候，用其自身hashcode值与其高16位做异或操作。这也就让高位参与到index的计算中来了，即降低了哈希冲突的风险又不会带来太大的性能问题。
~~~

### Node\< K ,V >\[\]

`Node<K,V>[] table`是`HashMap`底层存储的数据结构，是一个`Node`数组。`Node`类为元素维护了一个单向链表。这样设计的原因是考虑到遇到哈希冲突的时候，同`index`的`value`值就用单向链表来维护。当单链表的长度超过`TREEIFY_THRESHOLD` (默认8)时，将内部结构单链表转为红黑树存储，红黑树节点由Node的子类TreeNode表示

~~~java
    static class Node<K,V> implements Map.Entry<K,V> {
        final int hash;
        final K key;
        V value;
        Node<K,V> next; //单链表
        ... ...
    }
~~~

### 构造函数

由下可知`HashMap`一共有四个构造函数：均未在构造函数里初始化hash table数组，只是设置属性：

`loadFactor`  和 `threshhold`

~~~java
    public HashMap(int initialCapacity, float loadFactor) {
        if (initialCapacity < 0)
            throw new IllegalArgumentException("Illegal initial capacity: " +
                                               initialCapacity);
        if (initialCapacity > MAXIMUM_CAPACITY)
            initialCapacity = MAXIMUM_CAPACITY;
        if (loadFactor <= 0 || Float.isNaN(loadFactor))
            throw new IllegalArgumentException("Illegal load factor: " +
                                               loadFactor);
        this.loadFactor = loadFactor;
        this.threshold = tableSizeFor(initialCapacity);
    }

    public HashMap(int initialCapacity) {
        this(initialCapacity, DEFAULT_LOAD_FACTOR);
    }

    public HashMap() {
        this.loadFactor = DEFAULT_LOAD_FACTOR; // all other fields defaulted
    }

    public HashMap(Map<? extends K, ? extends V> m) {
        this.loadFactor = DEFAULT_LOAD_FACTOR;
        putMapEntries(m, false);
    }
~~~

### resize()

在put元素时会根据table是否为空来初始化table，或者在put元素后根据table的元素size是否超过`threshold`来扩容。而初始化table和对table进行扩容均是通过resize()实现的

~~~java
扩容：
1. 分配新的Node[]，容量为之前的2倍；
2. 设置新的 threshhold 为新的容量*loadfactor
3. 拷贝旧的table数据到新的table（preserve order）
~~~







