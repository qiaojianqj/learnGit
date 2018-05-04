package serial;

import java.io.ObjectInputStream;
import java.io.IOException;
import java.lang.ClassNotFoundException;
import java.io.FileInputStream;

public class Consumer {

    public Person readObject() throws IOException, ClassNotFoundException {
      FileInputStream fis = new FileInputStream("serialized.txt");
      ObjectInputStream ois = new ObjectInputStream(fis);
      Person p = (Person) ois.readObject();
      ois.close();
      return p;
    }
}