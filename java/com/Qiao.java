class Main {
    public static void main(String[] args) {
        Demo1(); 
    }
    
    public static void Demo1()  
    {  
        Person person = new Person();  
        //try {
        System.out.println("Demo1: Pacage name: " + person.getClass().getPackage().getName() + ";"   
                + "Class name: " + person.getClass().getName());
        //}catch (Exception e) {
        //}
    } 
}

class  Person{  
    private int age;  
    private String name;  
    public Person(){  
          
    }  
    public Person(int age, String name){  
        this.age = age;  
        this.name = name;  
    }  
  
    public int getAge() {  
        return age;  
    }  
    public void setAge(int age) {  
        this.age = age;  
    }  
    public String getName() {  
        return name;  
    }  
    public void setName(String name) {  
        this.name = name;  
    }  
}