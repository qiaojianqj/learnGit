package serial;

import java.io.ObjectOutputStream;
import java.io.IOException;
import java.io.FileOutputStream;

public class Producer {
    private Person person;
    
    public Producer(Person person) {
        this.person = person;
    }
    
    public void writeObject() throws IOException {
      FileOutputStream fos = new FileOutputStream("serialized.txt");
      ObjectOutputStream oos = new ObjectOutputStream(fos);
      oos.writeObject(person);
      oos.close();
    }
}