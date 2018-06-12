package  quickStart;

import java.io.File;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

public class Main {
    public static void main(String[] args) throws Exception {

        /*
        int a;
        {
            int a;// redefine
        }
        */

        String str = "♥️ haha";
        char ch = str.charAt ( 1 );
        System.out.println ( "charAt str.1: " + ch + ", length of str: " + str.length () );

        System.out.println ( 1.0 / 0 );

        long valLong = (long)1<<35;
        System.out.println ( valLong );

        int valInt = 1<<35;
        System.out.println ( valInt);

        System.out.println ( new File ( "." ).getAbsolutePath ());

        System.out.println("getResource: " + Main.class.getResource("").getPath ());
        System.out.println("getResource/: " + Main.class.getResource("/").getPath ());

        System.out.println("getClassLoader.getResource: " + Main.class.getClassLoader().getResource(""));
        System.out.println("getClassLoader.getResource/:" + Main.class.getClassLoader().getResource("/"));

        //RandomAccessFile aFile = new RandomAccessFile ( "./target/classes/nio-data.txt","rw" );
        RandomAccessFile aFile = new RandomAccessFile ( Main.class.getResource ( "/nio-data.txt" ).getFile (),"rw" );
        FileChannel inChannel = aFile.getChannel ();
        ByteBuffer buf = ByteBuffer.allocate ( 48 );
        int bytesRead = inChannel.read ( buf );
        System.out.println ( bytesRead + " returned from inChannel" );
        while (bytesRead != -1) {
            System.out.println ( "\nRead " + bytesRead );
            buf.flip ();
            while (buf.hasRemaining ()) {
               System.out.print ( (char) buf.get () );
            }
            buf.clear ();
            bytesRead = inChannel.read ( buf );
        }
        aFile.close ();
    }
}
