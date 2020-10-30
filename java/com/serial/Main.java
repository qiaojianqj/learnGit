package serial;

public class Main {
    public static void main(String[] args) throws Exception {
        Person person = new Person("Qiao Leo");
        Producer producer = new Producer(person);
        Consumer consumer = new Consumer();
        producer.writeObject();
        Person p = consumer.readObject();
        System.out.println(p.getName());
    }
}