# 设计模式原则

SOLID

***

Single Responsible Principle:

**保持一个类专注于单一功能点上**

**一个类或者模块应该有且只有一个改变的原因**

***

Open Close Principle:

 **类的设计应该是对扩展开放，对修改封闭**

***

Liskov Substitution Principle:

**Let q(x) be a property provable about objects of x of type T. Then q(y) should be provable for objects y of type S where S is a subtype of T. **

**所有引用基类的地方必须能透明地使用其子类的对象**

**子类可以扩展父类的功能，但不能改变父类原有的功能**



1. 子类可以实现父类的抽象方法，但是不能覆盖父类的非抽象方法。

2. 子类可以增加自己特有的方法。

3. 子类可以重载父类的方法，但是方法的形参要比父类方法的形参更宽松。

4. 子类实现父类的抽象方法时，方法的返回值要比父类方法更严格。

   

里氏替换原则规定了继承时的约束：尽量避免子类覆盖父类的方法。

***

Interface Segregation Principle:

**拆分非常庞大臃肿的接口成为更小的和更具体的接口**

***

Dependence Inversion Principle

**高层模块不应该依赖底层模块，二者都该依赖其抽象；抽象不应该依赖细节；细节应该依赖抽象**

