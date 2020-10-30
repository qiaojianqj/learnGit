
public class xxoo {
    private static class Data {
        private String name;
        public Data() {
            name = "";
        }
        public String getName(){
            return name;
        }
        
        public void setName(String name) {
            this.name = name;
        }
    }
    
    public static void main(String args[])
    {
        int i = 1;
        System.out.println(i);
        checkInt(i);
        System.out.println(i);
        
        Data data = new Data();
        data.setName("first name");
        System.out.println(data.getName());
        checkClass(data);
        System.out.println(data.getName());
        
        char[] abc =new char[]{'A','B','C','D','E','F'};
        int a=abc[0]-'A';
        System.out.println(a);
        
    }
    public static void checkInt(final int i)
    {
        //final parameter i may not be assigned
        //i++;
    }
    
    public static void checkClass(final Data data) 
    {
        //final parameter data may not be assigned
        //data = new Data();
        data.setName("second name");
    }
}